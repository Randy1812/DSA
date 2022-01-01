#include<iostream>

using namespace std;

class Toeplitz
{
 int n;
 int *A;

 public:

 Toeplitz(int n)
 {
  this->n = n;
  A = new int[2*n - 1];
 }

 void set(int i, int j,int x);
 int get(int i,int j);
 void Display();
 int getdimensions(){return n;};
 ~Toeplitz();
};

void Toeplitz::set(int i, int j, int x)
{
 if(i<=j)
   {
    A[j-1] = x;
   }
 else
   {
    A[n+i-j-1] = x;
   }
}

int Toeplitz::get(int i, int j)
{
 if(i<=j)
   {
    return A[j-1];
   }
 else
   {
    return A[n+i-j-1];
   }
}

void Toeplitz::Display()
{
 for(int i=1;i<=n;i++)
    {
     for(int j=1;j<=n;j++)
        {
         if(i<=j)
           {
            cout<<A[j-1]<<"\t";
           }
         else
           {
            cout<<A[n+i-j-1]<<"\t";
           }
        }
     cout<<"\n";
    }
}

Toeplitz::~Toeplitz()
{
 cout<<"Object deleted.";
 delete []A;
}

int main()
{
 int d,x;
 cout<<"Enter Dimensions : ";
 cin>>d;
 Toeplitz lm(d);
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



