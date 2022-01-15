#include<iostream>
#include "Queuecpp.h"

using namespace std;

class Tree
{
 private:
    Node *root;
 public:
    Tree(){root=NULL;};
    void CreateTree();
    int Countdeg0(Node *root);
    int Countdeg0(){return Countdeg0(root);};
    int Countdeg1(Node *root);
    int Countdeg1(){return Countdeg1(root);};
    int Countnonleaf(Node *root);
    int Countnonleaf(){return Countnonleaf(root);};
    int Countdeg2(Node *root);
    int Countdeg2(){return Countdeg2(root);};
};

void Tree::CreateTree()
{
 Node *p,*t;
 int x;
 Queue q(100);

  cout<<"Enter root : ";
  cin>>x;
  root = new Node;
  root->data=x;
  root->left=root->right=NULL;
  q.enqueue(root);

  while(!q.isempty())
       {
        p=q.dequeue();
        cout<<"Enter the left child of "<< p->data <<": ";
        cin>>x;
        if(x!=-1)
          {
           t = new Node;
           t->data=x;
           t->left=t->right=NULL;
           p->left=t;
           q.enqueue(t);
          }
        cout<<"Enter the right child of "<< p->data <<": ";
        cin>>x;
        if(x!=-1)
          {
           t = new Node;
           t->data=x;
           t->left=t->right=NULL;
           p->right=t;
           q.enqueue(t);
          }
       }
}


int Tree::Countdeg0(Node *p)
{
 int x=0,y=0;
 if(p!=NULL)
   {
    x=Countdeg0(p->left);
    y=Countdeg0(p->right);
    if(p->left==NULL && p->right==NULL)
      {
       return x+y+1;
      }
    else
      {
       return x+y;
      }
   }
 return 0;
}

int Tree::Countdeg1(Node *p)
{
 int x=0,y=0;
 if(p!=NULL)
   {
    x=Countdeg1(p->left);
    y=Countdeg1(p->right);
    if(p->left!=NULL ^ p->right!=NULL)
      {
       return x+y+1;
      }
    else
      {
       return x+y;
      }
   }
 return 0;
}

int Tree::Countdeg2(Node *p)
{
 int x=0,y=0;
 if(p!=NULL)
   {
    x=Countdeg2(p->left);
    y=Countdeg2(p->right);
    if(p->left!=NULL && p->right!=NULL)
      {
       return x+y+1;
      }
    else
      {
       return x+y;
      }
   }
 return 0;
}

int Tree::Countnonleaf(Node *p)
{
 int x=0,y=0;
 if(p!=NULL)
   {
    x=Countnonleaf(p->left);
    y=Countnonleaf(p->right);
    if(p->left!=NULL || p->right!=NULL)
      {
       return x+y+1;
      }
    else
      {
       return x+y;
      }
   }
 return 0;
}

int main()
{
 Tree t;
 t.CreateTree();
 cout<<"\nLeaf Nodes : "<<t.Countdeg0();
 cout<<"\nNon-Leaf Nodes : "<<t.Countnonleaf();
 cout<<"\nNodes Of Degree 1 : "<<t.Countdeg1();
 cout<<"\nNodes Of Degree 2 : "<<t.Countdeg2();
}

