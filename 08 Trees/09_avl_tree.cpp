#include<iostream>

using namespace std;

struct Node
{
 Node *left,*right;
 int data,height;
}*root=NULL;

int NodeHeight(Node *p)
{
 int hl,hr;
 hl=p&&p->left?p->left->height:0;
 hr=p&&p->right?p->right->height:0;
 return max(hl,hr)+1;
}

int Balancefactor(Node *p)
{
 int hl,hr;
 hl=p&&p->left?p->left->height:0;
 hr=p&&p->right?p->right->height:0;
 return hl-hr;
}

Node* LLRotation(Node *p)
{
 Node *pl=p->left;
 Node *plr=pl->right;
 pl->right=p;
 p->left=plr;
 p->height=NodeHeight(p);
 pl->height=NodeHeight(pl);
 if(root==p)
   {
    root=pl;
   }
 return pl;
}

Node* LRRotation(Node *p)
{
 Node *pl=p->left;
 Node *plr=pl->right;
 pl->right=plr->left;
 p->left=plr->right;
 plr->left=pl;
 plr->right=p;
 p->height=NodeHeight(p);
 pl->height=NodeHeight(pl);
 plr->height=NodeHeight(plr);

 if(root==p)
   root=plr;

 return plr;
}

Node* RRRotation(Node *p)
{
 Node *pr=p->right;
 Node *prl=pr->left;
 pr->left=p;
 p->right=prl;
 p->height=NodeHeight(p);
 pr->height=NodeHeight(pr);
 if(root==p)
   {
    root=pr;
   }
 return pr;
}

Node *RLRotation(Node *p)
{
 Node *pr=p->right;
 Node *prl=pr->left;
 p->right=prl->left;
 pr->left=prl->right;
 prl->left=p;
 prl->right=pr;
 p->height=NodeHeight(p);
 pr->height=NodeHeight(pr);
 prl->height=NodeHeight(prl);
 if(root==p)
   {
    root=prl;
   }
 return prl;
}

Node* insert(Node *p, int key)
{
 Node *t=NULL;
 if(p==NULL)
   {
    t=new Node;
    t->data=key;
    t->height=1;
    t->left=t->right=NULL;
    return t;
   }
 if(key<p->data)
   {
    p->left=insert(p->left,key);
   }
 else if(key>p->data)
   {
    p->right=insert(p->right,key);
   }
 p->height=NodeHeight(p);
 if(Balancefactor(p)==2 && Balancefactor(p->left)==1)
    return LLRotation(p);
 else if(Balancefactor(p)==2 && Balancefactor(p->left)==-1)
    return LRRotation(p);
 else if(Balancefactor(p)==-2 && Balancefactor(p->right)==-1)
    return RRRotation(p);
 else if(Balancefactor(p)==-2 && Balancefactor(p->right)==1)
    return RLRotation(p);
 return p;
}

Node* inorder_successor(Node *p)
{
 while(p && p->left!=NULL)
      {
       p=p->left;
      }
 return p;
}

Node *inorder_predeccesor(Node *p)
{
 while(p && p->right!=NULL)
      {
       p=p->right;
      }
 return p;
}

void del(Node *p, int key)
{
 if(p==NULL)
   {
    return p;
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
 if(key<p->data)
   {
    p->left=del(p->left,key);
   }
 else if(key>p->data)
   {
    p->right=del(p->right,key);
   }
 else
   {
    Node *q;
    if(NodeHeight(p->left) > NodeHeight(p->right))
      {
       q=inorder_predeccesor(p->left);
       p->data=q->data;
       p->left=del(p->left,q->data);
      }
    else
      {
       q=inorder_successor(p->right);
       p->data=q->data;
       p->right=del(p->right,q->data);
      }
   }
 p->height=NodeHeight(p);
 if(Balancefactor(p)==2 && Balancefactor(p->left)==1)
   {
    return LLRotation(p);
   }
 else if(Balancefactor(p)==2 && Balancefactor(p->left)==-1)
   {
    return LRRotation(p);
   }
 else if(Balancefactor(p)==-2 && Balancefactor(p->right)==-1)
   {
    return RRRotation(p);
   }
 else if(Balancefactor(p)==-2 && Balancefactor(p->right)==1)
   {
    return RLRotation(p);
   }
 else if(Balancefactor(p)==2 && Balancefactor(p->left)==0)
   {
    return LLRotation(p);
   }
else if(Balancefactor(p)==2 && Balancefactor(p->right)==0)
   {
    return RRRotation(p);
   }
 return p;
}

int main()
{
 root=insert(root,50);
 insert(root,30);
 insert(root,20);
 cout<<root->data;
}
