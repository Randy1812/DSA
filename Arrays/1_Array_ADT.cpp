#include<iostream>

using namespace std;

struct Array {
 int A[20];
 int size;
 int length;
};

void Display(Array arr) {
 int i;
 cout<<"The elements are : \n";
 for(i=0;i<arr.length;i++) {
    cout<<arr.A[i]<<" ";
 }
}

int main()
{
 Array arr = {{2,3,4,5,6}, 20, 5};
 Display(arr);
}
