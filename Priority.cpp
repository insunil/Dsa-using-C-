#include<iostream>
using namespace std;
#include<stdio.h>
class node
{ public:
   int data;
   node* next;
   int priority;
};
class Pqueue
{
    node* start=NULL;
    public:
    void insert(int item,int p)
    {
     node* NEW=new node();
     NEW->data=item;
     NEW->priority=p;
     NEW->next=NULL;
     if(start==NULL)
     {
      start=NEW;
     }
     else
     {
      node* temp=start;
      node* prev=NULL;
      while(temp)
      {
        if(temp->priority>=p)
        {
          prev=temp;
          temp=temp->next;
        }
        else
        {
          break;
        }
      }
      if(prev==NULL)
      {
        NEW->next=start;
        start=NEW;
      }
      else
      {
        NEW->next=prev->next;
        prev->next=NEW;
      }
     }
    }
    void dele()
    {
      if(start==NULL)
        cout<<"Empty\n";
      else
      {
        node* temp=start;
        start=start->next;
        delete temp;
      }
    }
    int getElement()
    {
      if(start==NULL)
         return INT_MAX;
      else
      return start->data;
    }
    void traverse()
    {
      if(start)
      {
        node* temp=start;
        while(temp)
        {
          cout<<temp->data<<"= "<<temp->priority<<"\n";
          temp=temp->next;
        }
      }
    }
};

int main()
{Pqueue obj;
obj.insert(10,5);
obj.insert(20,3);
obj.insert(5,7);
obj.dele();
obj.traverse();
  return 0;
}
