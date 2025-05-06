#include<iostream>
using namespace std;
#include<stdio.h>
class node
{
  public:
  node* left;
  int data;
  node* right;
};
class BST
{
   node* root;
   protected:
   void pretraverse(node* temp);
   public:
   BST();
   void insert(int item);
   void inorder();
};
void BST::pretraverse(node* temp)
{
  if(temp)
  {

    pretraverse(temp->left);
    cout<<temp->data<<" ";
    pretraverse(temp->right);
  }
}
void BST::inorder()
{
  pretraverse(root);

}
void BST::insert(int item)
{
  node* NEW=new node();
  NEW->data=item;
  NEW->left=NULL;
  NEW->right=NULL;
  if(root==NULL)
  {
    root=NEW;
  }
  else
  {
    node* temp=root;
    while(temp)
    {
      if(temp->data>NEW->data)
      {
        if(temp->left)
        {
          temp=temp->left;
        }
        else
        break;
      }
      else if(temp->data<NEW->data)
      {
        if(temp->right)
        {
          temp=temp->right;
        }
        else {break;}
      }
    }
    if(temp->data>NEW->data)
    {
      temp->left=NEW;
    }
    else
    {
      temp->right=NEW;
    }
  }
}
BST::BST()
{
  root=NULL;
}
int main()
{ BST obj;
obj.insert(50);
obj.insert(40);
obj.insert(45);
obj.insert(42);
obj.inorder();
  return 0;
}