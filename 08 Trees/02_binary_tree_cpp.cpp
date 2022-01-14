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
    void Preorder(Node *p);
    void Preorder(){cout<<"\n\nPreorder : ";Preorder(root);cout<<"\n";};
    void Inorder(Node *p);
    void Inorder(){cout<<"\n\nInorder : ";Inorder(root);cout<<"\n";};
    void Postorder(Node *p);
    void Postorder(){cout<<"\n\nPostorder : ";Postorder(root);cout<<"\n";};
    void Levelorder(Node *p);
    void Levelorder(){cout<<"\n\nLevelorder : ";Levelorder(root);cout<<"\n";};
    int Height(Node *root);
    int Height(){return Height(root);};
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

void Tree::Inorder(Node *p)
{
 if(p)
   {
    Inorder(p->left);
    cout<<p->data<<" ";
    Inorder(p->right);
   }
}

void Tree::Preorder(Node *p)
{
  if(p)
   {
    cout<<p->data<<" ";
    Preorder(p->left);
    Preorder(p->right);
   }
}

void Tree::Postorder(Node *p)
{
  if(p)
   {
    Postorder(p->left);
    Postorder(p->right);
    cout<<p->data<<" ";
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

int main()
{
 Tree t;
 t.CreateTree();
 t.Preorder();
 t.Postorder();
 t.Inorder();
 t.Levelorder();
}
