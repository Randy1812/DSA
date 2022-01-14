// Logic: 0 if i<j else non zero
// Row Major Mapping A[i][j] = i(i-1)/2 + j-1
// Column Major Mapping A[i][j] = i( i-1)/2 + j-1

#include<iostream>

using namespace std;

class LowerTri
{
 int n;
 int *A;

 public:

 LowerTri(int n)
 {
  this->n = n;
  A = new int[n*(n+1)/2];
 }

 void set(int i, int j,int x);
 int get(int i,int j);
 void Display();
 int getdimensions(){return n;};
 ~LowerTri();
};

void LowerTri::set(int i, int j, int x)
{
// Row Major
// if(i>=j)
//   {
//    A[i*(i-1)/2 + j-1] = x;
//   }
// Column Major
 if(i>=j)
   {
    A[n*(j-1) - (j-2)*(j-1)/2 + i-j] = x;
   }
}

int LowerTri::get(int i, int j)
{
// Row Major
// if(i>=j)
//   {
//    return A[i*(i-1)/2 + j-1];
//   }
// Column Major
 if(i>=j)
   {
    return A[n*(j-1) - (j-2)*(j-1)/2 + i-j];
   }
 else
   {
    return 0;
   }
}

void LowerTri::Display()
{
 for(int i=1;i<=n;i++)
    {
     for(int j=1;j<=n;j++)
        {
         if(i>=j)
           {
//            Row Major
//            cout<<A[i*(i-1)/2 + j-1]<<"\t";
//            Column Major
            cout<<A[n*(j-1) - (j-2)*(j-1)/2 + i-j]<<"\t";
           }
         else
           {
            cout<<"0\t";
           }
        }
     cout<<"\n";
    }
}

LowerTri::~LowerTri()
{
 cout<<"Object deleted.";
 delete []A;
}

int main()
{
 int d,x;
 cout<<"Enter Dimensions : ";
 cin>>d;
 LowerTri lm(d);
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

