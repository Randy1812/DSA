#include<stdio.h>

using namespace std;

int main()
{
 int A[5];
 int *p;
// For C++
 p = new int[5];
 delete []p;
// for C
 p = (int*)malloc(5*sizeof(int));
 free(p);
}
