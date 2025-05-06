#include<iostream>
using namespace std;
#include<stdio.h>
class node
{
  public:
  int data;
  node* next;
};
class CLL
{
   node* last;
   public:
   CLL();
   void insertBegin(int item);
   void insertEnd(int);
   node* search(int);
   void insertafter(int item1,int item2);
   void deleFirst();
   void deleLast();
   void deleSpecific(int);
   void traverse()
   {
    node* temp=last->next;
    /* cout<<last->data;
    cout<<last->next->data;
   } */
  do
  {
    cout<<temp->data<<"<->";
    temp=temp->next;
  }
  while(temp!=last);
  cout<<temp->data<<"<->";
   }
};
void CLL:: deleSpecific(int item)
{
if(last)
{
  node* temp=search(item);
  if(temp)
  {
    if(temp==last)
     deleLast();
     else if(temp==last->next)
     {
      deleFirst();
     }
     else
     {
      node* extra=last;
      do
      {
        extra=extra->next;
      }
      while(extra->next!=temp);
      extra->next=temp->next;
      delete temp;
     }
  }
}
}
void CLL::deleLast()
{
   if(last)
   {
    if(last->next==last)
    {

      delete last;
      last=NULL;
    }
    else
    {
      node* temp=last;
      do
      {
         temp=temp->next;
      }
      while(temp->next!=last);
      temp->next=last->next;
      delete last;
      last=temp;
    }
   }
}
void CLL::deleFirst()
{
   if(last)
   {
    if(last->next==last)
    {

      delete last;
      last=NULL;
    }
    else
    {
      node* temp=last->next;
      last->next=temp->next;
      delete temp;
    }
   }
}
void CLL::insertafter(int item1,int item2)
{
           if(last)
           {
              node* temp=search(item1);


              if(temp)
              {
                if(temp==last)
                {
                  insertEnd(item2);
                }
                else
                {
                 node* NEW=new node();
                 NEW->data=item2;
                 NEW->next=temp->next;
                 temp->next=NEW;
                }
              }
           }
}
node* CLL::search(int item)
{
   if(last)
   {
     node* temp=last;
     do
     {
         if(temp->data==item)
         return temp;
         temp=temp->next;
     }
     while(temp->next!=last);

   }
   return NULL;
}
void CLL::insertEnd(int item)
{
   node* NEW=new node();
    NEW->data=item;
    NEW->next=NULL;
    if(last==NULL)
    {
      last=NEW;
      NEW->next=NEW;
    }
    else
    {
      NEW->next=last->next;
      last->next=NEW;
      last=NEW;

    }
}
void CLL::insertBegin(int item)
{
    node* NEW=new node();
    NEW->data=item;
    NEW->next=NULL;
    if(last==NULL)
    {

      NEW->next=NEW;
      last=NEW;
    }
    else
    {
      NEW->next=last->next;
      last->next=NEW;

    }
}
CLL::CLL()
{
  last=NULL;
}
int main()
{ CLL obj;
//obj.insertBegin(10);
obj.insertBegin(5);
obj.insertEnd(20);
obj.insertEnd(30);
//cout<<obj.search(5)->data<<endl;
obj.insertafter(5,15);
//obj.deleFirst();
//obj.deleLast();

obj.traverse();
  return 0;
}