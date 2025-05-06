 #include<iostream>
using namespace std;
class Array
{
  int capacity;
  int lastIndex;
  int *ptr;
  protected:
 void doublearray();
 void halfarray();
  public:
    Array(int size)
    {
      capacity=size;
      lastIndex=-1;
      ptr=new int[capacity];
    }
    bool isEmpty();
    void append(int data);
    bool isFull();
    void insert(int index,int data);
    void edit(int ,int);
    void del(int);
    int getItem(int index);
    int count();
    Array(Array&);
    int capacityy();




};
int Array::capacityy()
{
 return capacity;
}
void Array::doublearray()
{
  int *temp=new int[capacity*2];
  int i;
  capacity*=2;
  for(i=0;i<=lastIndex;i++)
  {
    temp[i]=ptr[i];
  }
  delete []ptr;
  ptr=temp;
}
void Array::halfarray()
{
  int *temp=new int[capacity/2];
  int i;
  capacity/=2;
  for(i=0;i<=lastIndex;i++)
  {
     temp[i]=ptr[i];
  }
  delete []ptr;
  ptr=temp;
}

Array::Array(Array& obj)
{ int i;
  capacity=obj.capacity;
  lastIndex=obj.lastIndex;
  ptr=new int[capacity];
  for(i=0;i<=lastIndex;i++)
  ptr[i]=obj.ptr[i];
}
int Array::count()
{
  return lastIndex+1;
}
int Array::getItem(int index)
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
void Array::del(int index)
{  if(index<=lastIndex)
  {
     int i;
     for(i=index;i<lastIndex;i++)
     {
      ptr[i]=ptr[i+1];
     }
     lastIndex--;
     if(lastIndex+1==capacity/2 &&capacity!=1)
     {
      halfarray();
     }
   }
else
{
  cout<<"Invalid index"<<endl;
}

}
void Array::edit(int index,int data)
{
if(index<=lastIndex)
{
   ptr[index]=data;
}
else{
  cout<<"invalid index"<<endl;
}
}
void Array::insert(int index,int data)
{
  if(isFull())
  {doublearray();

  }


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
bool Array::isEmpty()
{
  return lastIndex==-1;
}
void Array::append(int data)
{
    if(isFull())
    {
      doublearray();
    }


        ptr[++lastIndex]=data;

}
bool Array::isFull()
{
  return lastIndex+1==capacity;
}

int main()
{
  Array obj(5);
int i;


  obj.append(10);
  obj.append(20);
  obj.append(30);
   obj.append(40);
   obj.insert(1,5);
   cout<<obj.capacityy()<<endl;
   obj.append(60);
 cout<<obj.capacityy()<<"\n";
   for(i=0;i<obj.count();i++)
      {
        cout<<obj.getItem(i)<<endl;
      }
  return 0;
}