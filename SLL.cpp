#include<iostream>
using namespace std;
class node
{  public:
   int data;
   node* next;

};
class SLL
{
   node *start;
   public:
   SLL();
   SLL(SLL&);
   void insertBegin(int data);
   void insertEnd(int);
   node* search(int item);
   void inserafter(int item1,int item2);
   void deleBegin();
   void deleSpecific(int);
   void delLast();
   ~SLL();
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
SLL::~SLL()
{
   while(start)
   {
    deleBegin();
   }
}
SLL::SLL(SLL& obj)
{
  start=new node();
  node* temp=obj.start;
  while(temp)
  {
    insertEnd(temp->data);
    temp=temp->next;
  }
}
void SLL:: delLast()
{
  if(start==NULL)
  {
    cout<<"empty\n";
  }
  else if(start->next==NULL)
  {
    delete start;
    start=NULL;
  }
  else{
      node *extra=start;
        while(extra->next->next!=NULL)
        {
          extra=extra->next;
        }
        delete extra->next;
        extra->next=NULL;
  }

}
void SLL::deleSpecific(int item)
{ node* temp;
  if(start==NULL)
  {
    cout<<"Empty\n";
  }
  else if(search(item)==NULL)
  {
     cout<<"Not exist"<<endl;
  }
  else
  { temp=search(item);
     if(temp==start && start->next==NULL)
     {
       delete temp;
       start=NULL;
     }
     else if(temp==start && start->next!=NULL)
     {
         start=start->next;
         delete temp;
     }
     else if(temp->next==NULL)
     {
        node *extra=start;
        while(extra->next->next!=NULL)
        {
          extra=extra->next;
        }
        extra->next=NULL;
        delete temp;
     }
     else
     {
       node *extra=start;
       while(extra->next!=temp)
       {
        extra=extra->next;
       }
       extra->next=temp->next;

     }

  }
}
void SLL::deleBegin()
{
  if(start==NULL)
  {
    cout<<"List is empty\n";
  }
else if(start->next==NULL)
{
   delete start;
   start=NULL;
}
else
{
  node *temp=start;
  start=start->next;
  delete temp;
}
}


void SLL::inserafter(int item,int item2)
{
  node* temp=search(item);
 try
 {
   if(temp==NULL)
  {
     throw 1;
  }
  node* NEW=new node();
  NEW->data=item2;
  NEW->next=NULL;
  NEW->next=temp->next;
  temp->next=NEW;

 }
 catch(int e)
 {
   cout<<"item is not available\n";
 }



}
node* SLL::search(int item)
{
    if(start==NULL)
    {
      return NULL;
    }
    else
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
      return NULL;
    }
}
void SLL::insertEnd(int item)
{
  node* NEW=new node();
  NEW->data=item;
  NEW->next=NULL;
  if(start==NULL)
  {
    start=NEW;
  }
  else
  {
     node* temp=start;
     while(temp->next!=NULL)
     {
      temp=temp->next;
     }
     temp->next=NEW;
  }
}
void SLL::insertBegin(int item)
{
  node* NEW=new node();
  NEW->data=item;
  NEW->next=NULL;
  if(start==NULL)
  {
    start=NEW;
  }
  else{
    NEW->next=start;
    start=NEW;
  }

}
SLL::SLL()
{
  start=NULL;
}
int main()
{ SLL obj;

obj.insertEnd(10);
obj.insertEnd(20);
obj.insertBegin(30);
cout<<obj.search(30)->data<<"\n";
obj.deleSpecific(300);
obj.inserafter(100,5);
obj.traverse();
  return 0;
}
