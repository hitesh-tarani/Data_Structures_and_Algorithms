#include<iostream>
#include"linked_lists.h"
#include"Linear_lists.h"
#include"hospital-patient.h"
#include<cstring>

using namespace std;



int main()
{
  int i,n;
  int value;
  LinearList < Chain<record> > a(2);
  record r1,r2;
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
  //(a.returnListElement(1)).Display();
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