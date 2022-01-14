#include<iostream>

using namespace std;

class TriDiag
{
 int n;
 int *A;

 public:

 TriDiag(int n)
 {
  this->n = n;
  A = new int[3*n -2];
 }

 void set(int i, int j,int x);
 int get(int i,int j);
 void Display();
 int getdimensions(){return n;};
 ~TriDiag();
};

void TriDiag::set(int i, int j, int x)
{
 if(abs(i-j) <= 1)
   {
    if(i-j == 1)
      {
       A[i-1] = x;
      }
    else if(i==j)
      {
       A[n-1 + i-1] = x;
      }
    else if(i-j == -1)
      {
       A[2*n-1 - i-1] = x;
      }
   }
}

int TriDiag::get(int i, int j)
{
 if(abs(i-j) <= 1)
   {
    if(i-j == 1)
      {
       return A[i-1];
      }
    else if(i==j)
      {
       return A[n-1 + i-1];
      }
    else if(i-j == -1)
      {
       return A[2*n-1 - i-1];
      }
   }
 else
   {
    return 0;
   }
}

void TriDiag::Display()
{
 for(int i=1;i<=n;i++)
    {
     for(int j=1;j<=n;j++)
        {
         if(abs(i-j) <= 1)
           {
            if(i-j == 1)
              {
               cout<<A[i-1]<<"\t";
              }
            else if(i==j)
              {
               cout<<A[n-1 + i-1]<<"\t";
              }
            else if(i-j == -1)
              {
               cout<<A[2*n-1 - i-1]<<"\t";
              }
           }
         else
           {
            cout<<"0\t";
           }
        }
     cout<<"\n";
    }
}

TriDiag::~TriDiag()
{
 cout<<"Object deleted.";
 delete []A;
}

int main()
{
 int d,x;
 cout<<"Enter Dimensions : ";
 cin>>d;
 TriDiag lm(d);
 cout<<"Enter all the elements : ";
 for(int i=1;i<=d;i++)
    {
     for(int j=1;j<=d;j++)
        {
         cin>>x;
         lm.set(i,j,x);
        }
    }
 lm.Display();
}


