#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

bool verifyF(int propertyType, char c0, char c1, char c2, string segment) {

   bool isSatisfied = false;

   size_t occurOfC0 = count(segment.begin(), segment.end(), c0);
   size_t occurOfC1 = count(segment.begin(), segment.end(), c1);
   size_t occurOfC2 = count(segment.begin(), segment.end(), c2);

   printf("F:%i    %c: %zu  %c: %zu   %c: %zu\n", propertyType, c0, occurOfC0, c1, occurOfC1, c2, occurOfC2);

   switch (propertyType) {
      case 0:
         if (occurOfC0 + occurOfC1 == occurOfC2) {
            isSatisfied = true;
            printf("===>YES\n");
         } 
         break;
      case 1:
         if (occurOfC0 + (2 * occurOfC1) == occurOfC2) {
            isSatisfied = true;
            printf("===>YES\n");
         } 
         break;
      case 2:
         if (occurOfC0 * occurOfC1 == occurOfC2) {
            isSatisfied = true;
            printf("===>YES\n");
         } 
         break;
      case 3:
         if (occurOfC0 - occurOfC1 == occurOfC2) {
            isSatisfied = true;
            printf("===>YES\n");
         } 
         break;
   }  

   return isSatisfied;
}