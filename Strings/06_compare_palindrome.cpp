#include<iostream>

using namespace std;

int main()
{
// Comparison
// char A[] = "Painter";
// char B[] = "Painting";
 int i,j;
// for(i=0,j=0;A[i]!='\0'&& B[j]!='\0';i++,j++)
//    {
//     if(A[i] != A[j])
//       {
//        break;
//       }
//    }
//  if(A[i] == B[j])
//    {
//     cout<<"Equal";
//    }
//  else if(A[i] < B[j])
//    {
//     cout<<"A is smaller.";
//    }
// else
//   {
//    cout<<"A is greater.";
//   }

// Palindrome
 char C[] = "malayalam";
 i=0;
 for(j=0;C[j]!='\0';j++);
 j--;
 bool pal = true;
 while(i<=j)
      {
       if(C[i++] != C[j--])
         {
          pal = false;
         }
      }
 if(pal)
   {
    cout<<"Palindrome";
   }
 else
   {
    cout<<"Not a Palindrome.";
   }
}
