#include<iostream>
using namespace std;
#include<stdio.h>
class node
{
    public:
    node* left;
    int data;
    int h;
    node* right;
};
class BST
{
 node* root;
 protected:
 node* insertrec(node* ptr,int item);
 void inorderrec(node* ptr);
 node* delerec(node* ptr,int item);
 node* minValuerec(node* ptr);

 public:
 BST();
 void insert(int item);
 void inorder();
 void dele(int);
 int minValue();
};
node* BST::minValuerec(node* ptr)
{
   if(ptr==NULL)
   return ptr;
   else
   {
    while(ptr->left!=NULL)
    {
      ptr=ptr->left;
    }
    return ptr;
   }
}
int BST::minValue()
{ node* t=minValuerec(root);
 if(t)
   return t->data;
   else
   return INT_MAX;
}
node* BST:: delerec(node* ptr,int item)
{
  if(ptr==NULL)
  {
    return ptr;
  }
  else if(item<ptr->data)
  {
    ptr->left=delerec(ptr->left,item);
  }
  else if(item>ptr->data)
  {
    ptr->right=delerec(ptr->right,item);
  }
  else
  {
    if(ptr->left==NULL&& ptr->right==NULL)
    { delete ptr;
      ptr=NULL;
    }
    else if(ptr->left||ptr->right)
    {
      node* temp=ptr->left?ptr->left:ptr->right;
      delete ptr;
      ptr=temp;
    }
    else
    {
      node* succ=minValuerec(ptr->right);
      ptr->data=succ->data;
      ptr->right=delerec(ptr->right,succ->data);
    }
  }
  return ptr;
}
void BST::dele(int item)
{
  root=delerec(root,item);
}
void BST::inorderrec(node* ptr)
{
  if(ptr)
  {
    inorderrec(ptr->left);
    cout<<ptr->data<<" ";
    inorderrec(ptr->right);
  }
}
void BST::inorder()
{
inorderrec(root);
}
node* BST::insertrec(node* ptr,int item)
{
  if(ptr==NULL)
  {
    node* NEW=new node();
    NEW->data=item;
    NEW->left=NULL;
    NEW->right=NULL;
    NEW->h=1;
    ptr=NEW;
    return ptr;
  }
  else if(item<ptr->data)
  {
    ptr->left=insertrec(ptr->left,item);
  }
  else if(item>ptr->data)
  {
  ptr->right=insertrec(ptr->right,item);
  }
  else
  return ptr;

  return ptr;

}
void BST::insert(int item)
{
 root=insertrec(root,item);
}
BST::BST()
{
  root=NULL;
}
int main()
{ BST obj;
 obj.insert(50);
 obj.insert(30);
 obj.insert(70);
 obj.insert(20);
 

 obj.inorder();
  return 0;
}
