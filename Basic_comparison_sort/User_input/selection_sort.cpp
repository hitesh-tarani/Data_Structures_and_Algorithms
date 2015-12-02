#include<iostream>
using namespace std;
#define Max 25

class array{
 int a[Max];
public:
 int n;
 void Add(int no);
 void Display();
 void Selsort();
};


void array::Add(int no)
{
 if(n<Max)
 {
  a[n]=no;
  n++;
 }
 else
  cout << "Max size of array is "<< Max <<"\n";
}

void array::Display()
{
 int i;
 for(i=0;i<n;i++)
  cout << a[i] << " ";
 cout << "\n";
}

void array::Selsort()
{
 int i,j,pos,temp,sorted=false;
 i=n-1;
 while(i>0&&sorted==false)
 {
  pos=0;
  sorted=true;
  for(j=1;j<=i;j++)
  {
   if(a[pos]<=a[j])
   {
    pos=j;
   }
   else
    sorted=false;
  }
  temp=a[pos];
  a[pos]=a[i];
  a[i]=temp;
  i--;
 }
}

int main()
{
 array b;
 b.n=0;
 int i,temp;
 cout << "Enter the numbers\n";
 cin >> temp;
 while(temp>=0)
 {
  b.Add(temp);
  cin >> temp;
 }
 b.Selsort();
 cout << "Sorted Numbers\n";
 b.Display();
 return 0;
}
