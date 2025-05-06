#include<iostream>
using namespace std;
#include<stdio.h>
class Deque
{
  int capacity;
  int front;
  int rear;
  int *ptr;
    public:
    Deque(int size);
    void insertFront(int item);
    bool isFull();
    bool isEmpty();
    void inserRear(int item);
    void traverse();
    void deleFront();
    void deleRear()
    {

    }
};

void Deque::deleFront()
{
  if(front==-1)
    cout<<"empty\n";
    else if(front==rear)
     {front=rear=-1;
     }
     else if(front==capacity-1)
     {
      front=0;
     }
     else
     {
      front++;
     }


}
void Deque::traverse()
{ if(!isEmpty())
  {
    int i=front;
   while(i!=rear)
   {
      cout<<ptr[i]<<endl;
      i=i%(capacity-1);
   }
   cout<<ptr[rear];
  }

}
void Deque::inserRear(int item)
{
   if(isFull())
     {
        cout<<"full\n";
     }
     else if(rear==capacity-1)
     {
             rear=0;
             ptr[rear]=item;
     }
     else
     {
      rear++;
      ptr[rear]=item;
     }
}
bool Deque::isEmpty()
{
  return front==-1;
}
bool Deque::isFull()
{  if((front==0&& rear==capacity-1)||(front-1==rear))
   {return true;
   }
   else
   {
   return false;
   }
}
void Deque::insertFront(int item)
{
     if(isFull())
     {
        cout<<"full\n";
     }
     else if(front==0) //because deque is not full
     {                 // then we come here.not need extra condition
        front=capacity-1;
        ptr[front]=item;
     }
     else
     {
      front--;
      ptr[front]=item;
     }
}
Deque::Deque(int size)
{
  capacity=size;
  front=-1;
  rear=-1;
  ptr=new int[capacity];
}
int main()
{
  return 0;
}