#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

bool validateInput(int F, int N, int L, int M) {

   bool isValid = true;

   printf("Parsing input parameters... %i %i %i %i\n", F, N, L, M);

   if (!(0 <= F and F <= 3)) {

      printf("usage: ./pa1.x i N L M c0 c1 c2\n");
      printf("where: \n");
      printf("    i (0 <= i <= 3) is the index of the property Fi which each segment of S needs to satisfy; \n");
      printf("    N (3 <= N <= 8) is the number of threads; \n");
      printf("    L is the length of each segment of S;\n");
      printf("    M (M divides N) is the number of segments in S to generate, and \n");
      printf("    c0, c1, and c2 are the letters to be used in the property check.\n");

      printf("\n");
      printf("Please check input parameter F\n");
      isValid = false;

   }

   if (!(3 <= N and N <= 8)) {
      printf("usage: ./pa1.x i N L M c0 c1 c2\n");
      printf("where: \n");
      printf("    i (0 <= i <= 3) is the index of the property Fi which each segment of S needs to satisfy; \n");
      printf("    N (3 <= N <= 8) is the number of threads; \n");
      printf("    L is the length of each segment of S;\n");
      printf("    M (M divides N) is the number of segments in S to generate, and \n");
      printf("    c0, c1, and c2 are the letters to be used in the property check.\n");

      printf("\n");
      printf("Please check input parameter N\n");
      isValid = false;
   }



   return isValid;
}