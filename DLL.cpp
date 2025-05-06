#include<iostream>
#include<stdio.h>
using namespace std;
class node
{ public:
 node* prev;
 int data;
 node* next;

};
class DLL
{
   node* start;
   public:
   DLL()
   {
    start=NULL;
   }
   void insertBegin(int item)
   {
    node* NEW=new node();
    NEW->data=item;
    NEW->prev=NULL;
    if(start==NULL)
    {
      start=NEW;
      NEW->next=NULL;
    }
    else
    {
      NEW->next=start;
      start->prev=NEW;
      start=NEW;

    }
   }
   void insetEnd(int item);
   node* search(int);
   void insertSpecific(int,int);
   void deletFirst();

   
   void traverse()
   {
     node* temp=start;
     while(temp)
     {
      cout<<temp->data<<"->";
      temp=temp->next;
     }
   }
};
void DLL::deletFirst()
{
   if(start)
   {
      if(start->next==NULL)
      { delete start;
        start=NULL;

      }
      else{
             node* temp=start;
             start=start->next;
             start->prev=NULL;
             delete temp;
      }
   }
}
void DLL::insertSpecific(int item1,int item2)
{
  if(search(item1)!=NULL)
  {
    node* temp=search(item1);
   node* NEW=new node();
    NEW->data=item2;
    if(temp->next==NULL)
    {
      NEW->prev=temp;
      NEW->next=NULL;
      temp->next=NEW;
    }
    else
    {
      NEW->prev=temp;
      NEW->next=temp->next;
      temp->next->prev=NEW;
      temp->next=NEW;
    }
  }

}
node* DLL::search(int item)
{
if(start)
{
  node* temp=start;
  while(temp)
  {
    if(temp->data==item)
    {
      return temp;
    }
    temp=temp->next;
  }

}
return NULL;
}
void DLL::insetEnd(int item)
{
    node* NEW=new node();
    NEW->data=item;
    NEW->next=NULL;
    if(start==NULL)
    {
       start=NEW;
      NEW->next=NULL;
    }
    else
    {
      node *temp=start;
       while(temp->next!=NULL)
       {
        temp=temp->next;
       }
       temp->next=NEW;
       NEW->prev=temp;
    }
}
int main()
{ DLL obj;
   obj.insetEnd(10);
   obj.insetEnd(20);
   obj.insertBegin(50);
   obj.insertSpecific(100,5);
    obj.traverse();
  return 0;
}
