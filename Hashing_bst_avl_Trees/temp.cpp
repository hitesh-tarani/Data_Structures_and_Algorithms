#include<iostream>
#include"avl.h"
#include"hospital-patient.h"
#include<cstring>

using namespace std;


int main()
{
  int i,n;
  record value;
  char temp1[8];
  avlTree<record> a;
  int temp=0;
  while(temp!=5)
  {
    cout<<"Enter: 1 for insertion 2 for search 3 for delete 4 for print 5 for exit\n";
    cin>>temp;
    switch(temp)
    {
    case 1:
      value.storeRecord();
      a.insert(value,recordComp);
      a.balance();
      break;
    case 2:
      cin>>temp1;
      cout<<a.search(temp1,recordComp)<<endl;
      break;
    case 3:
      cin>>temp1;
      cout<<a.deleteElement(temp1,recordComp)<<endl;
      a.balance();
      break;
    case 4:
      a.preorderDisplay();
      break;
    default:
      ;
    }
  }
  /*record r1;
  r1.storeRecord();
  strcpy(r1.Patientid,"Patient1");
  strcpy(r2.Patientid,"Patient2");
  (a.returnListElement(1)).insert(r1);
  (a.returnListElement(1)).insert(r2);
  cout<<((a.returnListElement(1)).length());
  cout<<((a.returnListElement(1)).getElement(1).Patientid)<<endl;
  //cout<<(a.returnListElement(1)).getElement(2)<<endl;
  //value=(a.returnListElement(1)).getElement(2);
  //value="g";
  //a.insert(2,value);
  //cout<<value<<endl;
  //cout<<a.search(value,classCmp)<<endl;
  //(a.returnListElement(1)).Display();*/
  return 0;
}
/*
int main()
{
  int i,n;
  int value;
  cout<<"Insert the no. of elements\n";
  cin>>n;
  LinearList<int> a(n);
  for(i=0;i<n;i++)
  {
      cin>>value;
      a.insert(i+1,value);
  }
  cout<<(a.returnListElement(1));
  //cout<<(a.returnListElement(1)).getElement(2)<<endl;
  //value=(a.returnListElement(1)).getElement(2);
  //value="g";
  //a.insert(2,value);
  //cout<<value<<endl;
  //cout<<a.search(value,classCmp)<<endl;
  //cout<<a.returnListElement(1);
  return 0;
}
*/
/*
int main()
{
  int i,n;
  int value;
  cout<<"Insert the no. of elements\n";
  cin>>n;
  Chain<int> a;
  for(i=0;i<n;i++)
  {
      cin>>value;
      a.insert(i+1,value);
  }
  //value=(a.returnListElement(1)).getElement(2);
  //value="g";
  //a.insert(2,value);
  //cout<<value<<endl;
  //cout<<a.search(value,classCmp)<<endl;
  a.Display();
  return 0;
}
/*
int main()
{
  int i,n;
  int value;
  cout<<"Insert the no. of elements\n";
  cin>>n;
  Chain<int> a[n];
  for(i=0;i<n;i++)
  {
      cin>>value;
      a[1].insert(value);
  }
  value=a[1].getElement(2);
  //value="g";
  //a.insert(2,value);
  //cout<<value<<endl;
  //cout<<a.search(value,classCmp)<<endl;
  a[1].Display();
  return 0;
}*/
