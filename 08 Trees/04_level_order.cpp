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
    void Levelorder(Node *p);
    void Levelorder(){cout<<"\n\nLevelorder : ";Levelorder(root);cout<<"\n";};
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

void Tree::Levelorder(Node *root)
{
 Queue q(100);
 cout<<root->data<<" ";
 q.enqueue(root);
 while(!q.isempty())
      {
       root=q.dequeue();
       if(root->left)
         {
          cout<<root->left->data<<" ";
          q.enqueue(root->left);
         }
       if(root->right)
         {
          cout<<root->right->data<<" ";
          q.enqueue(root->right);
         }
      }
}


int main()
{
 Tree t;
 t.CreateTree();
 t.Levelorder();
}
