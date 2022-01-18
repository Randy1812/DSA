#include<iostream>
#include "Queuecpp.h"

using namespace std;

class BST
{
 public:
    Node *root;
    BST(){root=NULL;}
    int Height(Node *root);
    int Height(){return Height(root);};
    Node* recursive_insert(Node *p, int x);
    void iterative_insert(int x);
    Node* recursive_search(Node *p, int x);
    Node* iterative_search(Node *p, int x);
    Node* recursive_remove(Node *p, int x);
    Node* inorder_predecessor(Node *p);
    Node* inorder_successor(Node *p);
    void Inorder(Node *p);
    void Inorder(){cout<<"\n\nInorder : ";Inorder(root);cout<<"\n";};
    void Levelorder(Node *p);
    void Levelorder(){cout<<"\n\nLevelorder : ";Levelorder(root);cout<<"\n";};
};

Node* BST::inorder_predecessor(Node *p)
{
 while(p&&p->right!=NULL)
       p=p->right;
 return p;
}

Node *BST::inorder_successor(Node *p)
{
 while(p&&p->left!=NULL)
       p=p->left;
 return p;
}

int BST::Height(Node *root)
{
 int x=0,y=0;
 if(root==NULL)
   {
    return 0;
   }
 x=Height(root->left);
 y=Height(root->left);
 if(x>y)
   {
    return x+1;
   }
 else
   {
    return y+1;
   }
}

Node* BST::recursive_remove(Node *p, int x)
{

 Node *q;
 if(p==NULL)
   {
    return NULL;
   }
 if(p->left==NULL && p->right==NULL)
   {
    if(p==root)
      {
       root=NULL;
      }
    delete p;
    return NULL;
   }
 if(x<p->data)
   {
    p->left=recursive_remove(p->left,x);
   }
 else if(x>p->data)
   {
    p->right=recursive_remove(p->right,x);
   }
 else
   {
    if(Height(p->left)>Height(p->right))
      {
       q=inorder_predecessor(p->left);
       p->data=q->data;
       p->left=recursive_remove(p->left,q->data);
      }
    else
      {
       q=inorder_successor(p->right);
       p->data=q->data;
       p->right=recursive_remove(p->right,q->data);
      }
   }
 return p;
}

Node* BST::recursive_insert(Node *p, int x)
{
 Node *t;
 if(p==NULL)
   {
    t=new Node;
    t->data=x;
    t->left=t->right=NULL;
    return t;
   }
 if(x<p->data)
   {
    p->left=recursive_insert(p->left,x);
   }
 else if(x>p->data)
   {
    p->right=recursive_insert(p->right,x);
   }
 return p;
}

void BST::iterative_insert(int x)
{
 Node *p=root,*q=NULL;
 if(p==NULL)
   {
    Node *t = new Node;
    t->data=x;
    t->left=t->right=NULL;
    root=t;
    return;
   }
 else
   {
    while(p!=NULL)
      {
       q=p;
       if(p->data==x)
         {
          cout<<"Element already exists in the BST.\n";
          return;
         }
       else if(p->data>x)
         {
          p=p->left;
         }
       else
         {
          p=p->right;
         }
      }
    Node *t = new Node;
    t->data=x;
    t->left=t->right=NULL;
    if(t->data<q->data)
      {
       q->left=t;
      }
    else
      {
       q->right=t;
      }
   }
}

Node* BST::recursive_search(Node *p, int x)
{
 if(p==NULL)
   {
    return NULL;
   }
 else
   {
    if(x==p->data)
      {
       return p;
      }
    else if(x<p->data)
      {
       return recursive_search(p->left,x);
      }
    else
      {
       return recursive_search(p->right,x);
      }
   }
}

Node* BST::iterative_search(Node *p, int x)
{
 while(p)
      {
       if(x==p->data)
         {
          return p;
         }
       else if(p->data>x)
         {
          p=p->left;
         }
       else
         {
          p=p->right;
         }
      }
 return NULL;
}

void BST::Inorder(Node *p)
{
 if(p)
   {
    Inorder(p->left);
    cout<<p->data<<" ";
    Inorder(p->right);
   }
}

void BST::Levelorder(Node *root)
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
 BST bst;
 bst.root = bst.recursive_insert(bst.root,22);
 bst.recursive_insert(bst.root,1);
 bst.recursive_insert(bst.root,45);
 bst.recursive_insert(bst.root,233);
 bst.recursive_insert(bst.root,4);
 bst.recursive_insert(bst.root,89);
 bst.Inorder();
 bst.recursive_remove(bst.root,45);
 bst.Inorder();


// bst.iterative_insert(20);
// bst.iterative_insert(1);
// bst.iterative_insert(45);
// bst.iterative_insert(233);
// bst.iterative_insert(4);
// bst.iterative_insert(89);
// bst.Inorder();
}
