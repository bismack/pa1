#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <pthread.h>
#include <string>
#include <unistd.h>
#include <time.h>
#include <fstream>
#include <random>

#include "verify.h"

using namespace std;

pthread_mutex_t mutex;
string alphabet = {"abcdefgh"};
string S;
int numOfSegmentsSatisfied = 0;
int counter = 0;
int stringLength = 0;

struct INPUT {
   int F;
   int N;
   int L;
   char c0, c1, c2;
};    
INPUT inSt;


void writeOutputFile() {
   ofstream textFile;
   textFile.open("out.txt");
   textFile << S << endl;
   textFile << numOfSegmentsSatisfied << endl;
   textFile.close();
}

void *checkSegmentProp(void *rank) {
   int tid = (intptr_t)rank;
   int start = tid * inSt.L + counter * inSt.L * inSt.N;
   
   string strSeg = S.substr(start, inSt.L);
   
   // printf("THREAD %i VERIFYING SEGMENT: %s\n", tid, strSeg.c_str());
   if (verifyF(inSt.F, inSt.c0, inSt.c1, inSt.c2, strSeg) == true) {
      pthread_mutex_lock(&mutex);
      numOfSegmentsSatisfied++;
      pthread_mutex_unlock(&mutex);
      // printf("THREAD %i CONFIRMED SEGMENT %s SATISFIED PROPERTY %i\n", tid, strSeg.c_str(), inSt.F);
   }
   printf("-----THREAD: %i Substr: %s   Satisfied: %i\n", tid, strSeg.c_str(), numOfSegmentsSatisfied); 

   return NULL;
}

void *constructS(void *rank){
   int tid = (intptr_t)rank;
   const char letter = alphabet[tid];

   random_device rd;
   mt19937 eng(rd());
   uniform_int_distribution<> distr(100, 500);
   unsigned int microsleep = distr(eng);

   //printf("Thread %i - SLEEPING FOR: %ims\n", tid, microsleep);
   usleep(microsleep);

   pthread_mutex_lock(&mutex);
   // printf("MUTEX ACQUIRED BY THREAD: %i\n", tid);
   S += letter;
   stringLength++;
   printf("THREAD %i APPENDED LETTER: %c - SEGMENT S: %s %i \n", tid, letter, S.c_str(), stringLength);
   pthread_mutex_unlock(&mutex);

   return NULL;
}

int main(int argc, char* argv[]) {
   printf("\n");
   printf("PROGRAM START: \n");

   inSt.F = atoi(argv[1]);
   int N = atoi(argv[2]);
   int L = atoi(argv[3]);
   int M = atoi(argv[4]);
   inSt.c0 = argv[5][0];
   inSt.c1 = argv[6][0]; 
   inSt.c2 = argv[7][0];

   pthread_t threads[N];

   int segment = 1;

   while (segment <= M) {
      // printf("STRING LENGTH: %i\n", stringLength);
      for (int i=0; i < N; i++) {
         if (counter < L) {   
            pthread_create(&threads[i], NULL, constructS, (void *)(intptr_t)i);
            counter++;
            if (i == (N-1)) {
               i = 0;
            }
         }
      }
      segment++;
      counter = 0;
	}
   counter = 0;

   for (int i=0; i < N; i++) {
      pthread_join(threads[i], NULL);
   }

   printf("\n");
   printf("---------------String S CREATED: %s\n", S.c_str());
   inSt.L = L;
   inSt.N = N;


   while (counter < M/N) {
      // printf("======== Counter: %i  M/N: %i  M%N: %i \n", counter, M/N, M%N);

      for (int i=0; i < N; i++){
         pthread_create(&threads[i], NULL, checkSegmentProp, (void *)(intptr_t)i);
      }
      for (int i=0; i < N; i++) {
         pthread_join(threads[i], NULL);
      }

      counter++;
      if ((counter==M/N) && (M%N!=0)) {
         for (int i=0; i < M%N; i++){
            pthread_create(&threads[i], NULL, checkSegmentProp, (void *)(intptr_t)i);
         }
         for (int i=0; i < N; i++) {
            pthread_join(threads[i], NULL);
         }
      }
   }
   counter = 0;

   writeOutputFile();
   pthread_exit(NULL);
}