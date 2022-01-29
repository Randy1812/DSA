
#include<iostream>

using namespace std;


void merge(int a[], int l, int mid, int h)
{
 int i=l,j=mid+1,k=l;
 int b[100];
 while(i<=mid&&j<=h)
      {
       if(a[i]<a[j])
         {
          b[k++]=a[i++];
         }
       else
         {
          b[k++]=a[j++];
         }
      }
 while(i<=mid)
      {
       b[k++]=a[i++];
      }
 while(j<=h)
      {
       b[k++]=a[j++];
      }
 for(int i=l;i<=h;i++)
    {
     a[i]=b[i];
    }
}

void iter_merge(int a[], int n)
{
 int p,i,l,mid,h;
 for(p=2;p<=n;p*=2)
    {
     for(i=0;i+p-1<n;i+=p)
        {
         l=i;
         h=i+p-1;
         mid=(l+h)/2;
         merge(a,l,mid,h);
        }
    }
 if(p/2<n)
   {
    merge(a,0,p/2-1,n-1);
   }
}

void recursive_merge(int a[], int l, int h)
{
 if(l<h)
   {
    int mid=(l+h)/2;
    recursive_merge(a,l,mid);
    recursive_merge(a,mid+1,h);
    merge(a,l,mid,h);
   }
}


void disp(int ar[], int n)
{
 for(int i=0;i<n;i++)
    {
     cout<<ar[i]<<" ";
    }
 cout<<"\n";
}

int main()
{
 int ar[]={8,3,7,4,9,2,6,5};
// iter_merge(ar,8);
 recursive_merge(ar,0,8);
 disp(ar,8);
}


