 #include<iostream>
using namespace std;
template<typename x>
class Array
{
  int capacity;
  int lastIndex;
  x *ptr;
  public:
    Array(int size)
    {
      capacity=size;
      lastIndex=-1;
      ptr=new x[capacity];
    }
    bool isEmpty();
    void append(x data);
    bool isFull();
    void insert(int index,x data);
    void edit(int ,x);
    void del(int);
    x getItem(int index);
    int count();
    Array(Array&);


};
template <class x>
Array<x>::Array(Array<x>& obj)
{ int i;
  capacity=obj.capacity;
  lastIndex=obj.lastIndex;
  ptr=new int[capacity];
  for(i=0;i<=lastIndex;i++)
  ptr[i]=obj.ptr[i];
}
template <class x>
int Array<x>::count()
{
  return lastIndex+1;
}
template <class x>
x Array<x>::getItem(int index)
{
   if(index<=lastIndex)
   {
        return ptr[index];
   }
   else
   { cout<<"Invalid Index"<<endl;
   return -1;

   }
}
template <class x>
void Array<x>::del(int index)
{  if(index<=lastIndex)
{
     int i;
     for(i=index;i<lastIndex;i++)
     {
      ptr[i]=ptr[i+1];
     }
     lastIndex--;
}
else
{
  cout<<"Invalid index"<<endl;
}

}
template <class x>
void Array<x>::edit(int index,x data)
{
if(index<=lastIndex)
{
   ptr[index]=data;
}
else{
  cout<<"invalid index"<<endl;
}
}
template <class x>
void Array<x>::insert(int index,x data)
{
  if(isFull())
  {
    cout<<"array is full"<<endl;
  }
  else
  {
    if(index==capacity||index>lastIndex+1)
    {
        cout<<"Insertion is not possible"<<endl;
    }
    else if(index==lastIndex+1)
    {
        ptr[++lastIndex]=data;
    }
    else
    {
      int i;
      for(i=lastIndex;i>=index;i--)
      {
        ptr[i+1]=ptr[i];

      }
      ptr[index]=data;
      lastIndex++;
    }
  }
}
template <class x>
bool Array<x>::isEmpty()
{
  return lastIndex==-1;
}
template <class x>
void Array<x>::append(x data)
{
    if(isFull())
    {
      cout<<"array is full"<<endl;
    }
    else
    {
        ptr[++lastIndex]=data;
    }
}
template <class x>
bool Array<x>::isFull()
{
  return lastIndex+1==capacity;
}

int main()
{
  Array<int> obj(5);
int i;


  obj.append(10);
  obj.append(20);
  obj.append(30);
   obj.append(40);
   obj.insert(1,5);
   Array<int> obj2(5);
   obj2=obj;

   for(i=0;i<obj2.count();i++)
      {
        cout<<obj2.getItem(i)<<endl;
      }
  return 0;
}
