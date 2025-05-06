#include<iostream>
using namespace std;
#include<stdio.h>
class node
{
  public:
  node* prev;
  int data;
  node* next;
};
class CDLL
{
  node* start;
  public:
CDLL();
void insertBegin(int item);
void insertLast(int);
};
void CDLL::insertLast(int item)
{
node* NEW=new node();
  NEW->data=item;
  NEW->prev=NULL;
  NEW->next=NULL;
  if(start==NULL)
  {
    start=NEW;
    NEW->next=NEW;
    NEW->prev=NEW;
  }
  else
  {
    NEW->prev=start->prev;
    start->prev->next=NEW;
    NEW->next=start;
    start->prev=NEW;
  }
}
void CDLL::insertBegin(int item)
{
  node* NEW=new node();
  NEW->data=item;
  NEW->prev=NULL;
  NEW->next=NULL;
  if(start==NULL)
  {
    start=NEW;
    NEW->next=NEW;
    NEW->prev=NEW;
  }
  else
  {
    start->prev->next=NEW;
    NEW->prev=start->prev;
    NEW->next=start;
    start->prev=NEW;
    start=NEW;

  }
}
CDLL::CDLL()
{
  start=NULL;
}