#include<iostream>
using namespace std;
#include<stdio.h>
class Stack
{
  int capacity;
  int *ptr;
  int top;
  public:
  Stack(int size);
  Stack(Stack&);
  void push(int);
  bool isFull();
  bool isEmpty();
  void pop();
  int peek();
};
Stack::Stack(Stack& obj)
{ int i;
   capacity=obj.capacity;
   top=obj.top;
   ptr=new int[capacity];
for(i=0;i<=top;i++)
{
  ptr[i]=obj.ptr[i];
}
}
int Stack::peek()
{
  if(!isEmpty())
  {
  return ptr[top];
  }
  return INT_MAX;
}
void Stack::pop()
{
  if(!isEmpty())
  {
    top--;
  }
}
bool Stack::isEmpty()
{
  return top==-1;
}
bool Stack::isFull()
{
  return top+1==capacity;
}
void Stack::push(int item)
{
 if(!isFull())
 {
   ptr[++top]=item;
 }
}
Stack::Stack(int size)
{
  capacity=size;
  ptr=new int[size];
  top=-1;
}
int main()
{ Stack obj(5);
obj.push(10);
obj.push(20);
obj.push(20);
obj.push(30);
while(!obj.isEmpty())
{
  cout<<obj.peek()<<endl;
  obj.pop();
}

  return 0;
}