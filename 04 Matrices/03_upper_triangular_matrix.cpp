#include<iostream>

using namespace std;

class UpperTri
{
 int n;
 int *A;

 public:

 UpperTri(int n)
 {
  this->n = n;
  A = new int[n*(n+1)/2];
 }

 void set(int i, int j,int x);
 int get(int i,int j);
 void Display();
 int getdimensions(){return n;};
 ~UpperTri();
};

void UpperTri::set(int i, int j, int x)
{
// Row Major
// if(i>=j)
//   {
//    A[n*(i-1) - (i-2)*(i-1)/2 + j-1] = x;
//   }
// Column Major
 if(i>=j)
   {
    A[j*(j-1)/2 + i-1] = x;
   }
}

int UpperTri::get(int i, int j)
{
// Row Major
// if(i>=j)
//   {
//    return A[n*(i-1) - (i-2)*(i-1)/2 + j-1];
//   }
// Column Major
 if(i>=j)
   {
    return A[j*(j-1)/2 + i-1];
   }
 else
   {
    return 0;
   }
}

void UpperTri::Display()
{
 for(int i=1;i<=n;i++)
    {
     for(int j=1;j<=n;j++)
        {
         if(i>=j)
           {
//            Row Major
//            cout<<A[n*(i-1) - (i-2)*(i-1)/2 + j-1]<<"\t";
//            Column Major
            cout<<A[j*(j-1)/2 + i-1]<<"\t";
           }
         else
           {
            cout<<"0\t";
           }
        }
     cout<<"\n";
    }
}

UpperTri::~UpperTri()
{
 cout<<"Object deleted.";
 delete []A;
}

int main()
{
 int d,x;
 cout<<"Enter Dimensions : ";
 cin>>d;
 UpperTri lm(d);
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


