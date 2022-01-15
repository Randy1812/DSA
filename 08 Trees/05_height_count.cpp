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
    int Height(Node *root);
    int Height(){return Height(root);};
    int Count(Node *root);
    int Count(){return Count(root);};
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

int Tree::Height(Node *root)
{
 int x=0,y=0;
 if(root==NULL)
   {
    return 0;
   }
 x=Height(root->left);
 y=Height(root->right);
 if(x>y)
   {
    return x+1;
   }
 else
   {
    return y+1;
   }
}

int Tree::Count(Node *p)
{
 int x=0,y=0;
 if(p!=NULL)
   {
    x=Count(p->left);
    y=Count(p->right);
    return x+y+1;
   }
 return 0;
}

int main()
{
 Tree t;
 t.CreateTree();
 cout<<"Height of the Tree : "<<t.Height()<<"\n\n";
 cout<<"Number of Nodes in the Tree : "<<t.Count();;
 t.Count();
}

