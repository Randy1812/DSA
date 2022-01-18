#include<bits/stdc++.h>
#include "Queuecpp.h"
#include "Stackcpp.h"

using namespace std;

class BST
{
 public:
    Node *root;
    BST(){root=NULL;}
    int Height(Node *root);
    int Height(){return Height(root);};
    void create_from_preorder(int[], int);
    void Inorder(Node *p);
    void Inorder(){cout<<"\n\nInorder : ";Inorder(root);cout<<"\n";};
    void Levelorder(Node *p);
    void Levelorder(){cout<<"\n\nLevelorder : ";Levelorder(root);cout<<"\n";};
};

void BST::create_from_preorder(int pre[], int n)
{
 Stack *stk;
 Node *t,*p=root;
 int i=0;
 root=new Node;
 root->data=pre[i++];
 root->left=root->right=NULL;
 p=root;
 while(i<n)
      {
       if(pre[i]<p->data)
         {
          t=new Node;
          t->data=pre[i++];
          t->left=t->right=NULL;
          p->left=t;
          push(stk,p);
          p=t;
         }
       else
         {
          if(pre[i]>p->data && pre[i]<stacktop(stk))
            {
             t=new Node;
             t->data=pre[i++];
             t->left->right=NULL;
             p->right=t;
             p=t;
            }
          else
            {
             p=pop(stk);
            }
         }
      }
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
 int A[]={30,20,10,15,25,40,50,60};
 bst.create_from_preorder(A,8);
 bst.Inorder();
}

