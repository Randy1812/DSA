//#include<iostream>
//
//using namespace std;
//
//struct Matrix
//{
// int A[10];
// int n;
//};
//
//void set(Matrix &m, int i, int j, int x)
//{
// if(i==j)
//   {
//    m.A[i-1] = x;
//   }
//}
//
//int get(Matrix &m, int i, int j)
//{
// if(i==j)
//   return m.A[i-1];
// else
//   return 0;
//}
//
//void Display(Matrix m)
//{
// for(int i=0;i<m.n;i++)
//    {
//     for(int j=0;j<m.n;j++)
//        {
//         if(i==j)
//           {
//            cout<<m.A[i]<<"\t";
//           }
//         else
//           {
//            cout<<"0\t";
//           }
//        }
//     cout<<"\n";
//    }
//}
//
//int main()
//{
// Matrix m ;
// m.n = 4;
// set(m,1,1,5);
// set(m,2,2,8);
// set(m,3,3,9);
// set(m,4,4,12);
// Display(m);
//}

//CPP Implementation

#include<iostream>

using namespace std;

class Diagonal
{
 int n;
 int *A;

 public:

 Diagonal(int n)
 {
  this->n = n;
  A = new int[n];
 }

 void set(int i, int j,int x);
 int get(int i,int j);
 void Display();
 ~Diagonal();
};

void Diagonal::set(int i, int j, int x)
{
 if(i==j)
   {
    A[i-1] = x;
   }
}

int Diagonal::get(int i, int j)
{
 if(i==j)
   {
    return A[i-1];
   }
 else
   {
    return 0;
   }
}

void Diagonal::Display()
{
 for(int i=0;i<n;i++)
    {
     for(int j=0;j<n;j++)
        {
         if(i==j)
           {
            cout<<A[i]<<"\t";
           }
         else
           {
            cout<<"0\t";
           }
        }
     cout<<"\n";
    }
}

Diagonal::~Diagonal()
{
 cout<<"Object deleted.";
 delete []A;
}

int main()
{
 Diagonal d(4);
 d.set(1,1,5);
 d.set(2,2,8);
 d.set(3,3,9);
 d.set(4,4,12);
 d.Display();
}
