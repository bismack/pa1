#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

void *PrintHello(void *threadid) {
   long tid;
   tid = (long)threadid;
   cout << "Hello World! Thread ID, " << tid << endl;
   pthread_exit(NULL);
}

int main () {
   printf("------------------------\n");
   int num_threads=8;
   pthread_t threads[num_threads];
   int rc;
   int i;
	
   for( i=0; i < num_threads; i++ ){
      cout << "main() : creating thread, " << i << endl;
      rc = pthread_create(&threads[i], NULL, PrintHello, (void *)i);
		
      if (rc){
         cout << "Error:unable to create thread," << rc << endl;
         exit(-1);
      }
   }
	
   pthread_exit(NULL);
}