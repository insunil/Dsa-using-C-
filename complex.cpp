#include<iostream>
using namespace std;
class Complex
{int a,b;

 public:
  Complex():a(0),b(0)
  {}
Complex(int a,int b):a(a),b(b)
 {

 }
 Complex(Complex &c)
{
  a=c.a; b=c.b;

 }

  void setData(int x,int y)
  {
    a=x;
    b=y;
  }
 void showData()
 {
  cout<<"a="<<a<<"b= "<<b<<endl;
 }
 Complex operator+(Complex c)
 {
  Complex temp;
  temp.a=a+c.a;
  temp.b=b+c.b;
  return temp;
 }
 Complex operator-()
 {
  Complex temp;
  temp.a=-a;
  temp.b=-b;
  return temp;
 }

};
int main()
{ Complex c1(3,6),c2(4,8),c3,c4;
///destructor 3,4,5,6
Complex c5=c1;//destructor 7
cout<<"c5 "<<endl;
 c1.setData(3,5);
 c2.setData(4,6);
 //c3=c1.operator+(c2);
 c3=-c1;
 c3.showData();


  return 0;
}