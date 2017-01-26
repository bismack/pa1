#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int numOfSegmentsSatisfied = 0;

bool verifyF(int propertyType, char c0, char c1, char c2, string segment) {

   bool isSatisfied = false;
   cout << "Validating Property F" << propertyType << ": " << endl;

   size_t occurOfC0 = count(segment.begin(), segment.end(), c0);
   size_t occurOfC1 = count(segment.begin(), segment.end(), c1);
   size_t occurOfC2 = count(segment.begin(), segment.end(), c2);

   cout << "Occurences of c0: " << occurOfC0 << endl;
   cout << "Occurences of c1: " << occurOfC1 << endl;
   cout << "Occurences of c2: " << occurOfC2 << endl;

   switch (propertyType) {
      case 0:
         if (occurOfC0 + occurOfC1 == occurOfC2) {
            isSatisfied = true;
            cout << "YES" << endl;
         } 
         cout << "Property 0 Hit" << endl;
         break;
      case 1:
         if (occurOfC0 + (2 * occurOfC1) == occurOfC2) {
            isSatisfied = true;
            cout << "YES" << endl;
         } 
         cout << "Property 1 Hit" << endl;
         break;
      case 2:
         if (occurOfC0 * occurOfC1 == occurOfC2) {
            isSatisfied = true;
            cout << "YES" << endl;
         } 
         cout << "Property 2 Hit" << endl;
         break;
      case 3:
         if (occurOfC0 - occurOfC1 == occurOfC2) {
            isSatisfied = true;
            cout << "YES" << endl;
         } 
         cout << "Property 3 Hit" << endl;
         break;
      default:
         cout << "Property DEFAULT Hit" << endl;
   }  

   return isSatisfied;
}


int main () {

   ofstream textFile;
   textFile.open("out.txt");


   if (verifyF(1, 'a', 'b', 'c', "bccabcaccc") == true) {
      numOfSegmentsSatisfied++;
      cout << "numOfSegmentsSatisfied: " << numOfSegmentsSatisfied << endl;
   }
   
   textFile << numOfSegmentsSatisfied;
   textFile.close();

}