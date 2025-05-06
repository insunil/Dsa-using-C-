#include<iostream>
using namespace std;
class Item
{ private:
  int a,b;
  static int k;
  public:
 static void set_Data(int x)
 {
    k=x;
 }
 static int get_data()
 {
  return k;
 }

};
int Item::k=20;
int main()
{
  //Item i1,i2;
  //i1.a=10;
  //cout<<i2.a<<endl;
  //cout<<i1.k<<endl;
  //cout<<Item::k<<endl;
 Item::set_Data(91);
 cout<<Item::get_data();

  return 0;
}