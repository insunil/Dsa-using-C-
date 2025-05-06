#include<iostream>
#include<fstream>
using namespace std;
class Book
{
    int id;
    char name[20];
    float price;
    public:
    void input()
    {
      cout<<"Enter book id,title and price\n";
      cin>>id;
      cin.ignore();
      cin.getline(name,20);
      cin>>price;
    }
    void display()
    {
      cout<<id<<" "<<name<<" "<<price<<endl;
    }
    void store()
    {
      ofstream fout;
      fout.open("filedata.dat",ios::app|ios::binary);
      fout.write((char*)(this),sizeof(*this));
      fout.close();

    }
    void displayallbook()
    {
     ifstream fin;
     fin.open("filedata.dat",ios::in|ios::binary);
     if(!fin)
     {
      cout<<"not exit\n";
     }
     else{
      fin.read((char*)(this),sizeof(*this));
      while(!fin.eof())
      {
        display();
        fin.read((char*)(this),sizeof(*this));
      }
     }

    }
};
int main()
{ Book b;
  int choice;
  while(1)
{
  cout<<"please select your choice\n";
  cout<<"1.add new record\n";
  cout<<"2.display all record\n";
  cout<<"3.exit\n";
  cin>>choice;
  switch(choice)
  {
    case 1:b.input();
           b.store();
           break;
    case 2:b.displayallbook();
          break;
    case 3:exit(0);
           break;
    default:cout<<"please choose right option\n";


  }
}


  return 0;
}
