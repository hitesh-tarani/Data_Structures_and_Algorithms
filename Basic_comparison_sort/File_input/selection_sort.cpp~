#include<iostream>
#include<ctime>
#include <fstream>
using namespace std;

void Selsort(int* a,int n)
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

int main(int argc, char* argv[])
{
 if(argc==2)
 {
  ifstream inFile;
  inFile.open(argv[1]);
  string temp;
  int i=0,n=-1;
  while(!inFile.eof())
  {
   getline(inFile,temp);
   n++;
  }
  inFile.close();
  inFile.open(argv[1]);
  int array[n];
  for(i=0;i<n;i++)
  {
   inFile >> array[i];
  }
  //cout << "Enter the number of elements\n";
  //cin >> n;
  //cout << "Enter the numbers\n";
  //for(i=0;i<n;i++)
   //cin >> array[i];

  clock_t tStart = clock();
  Selsort(array,n);
  clock_t tStop = clock();
  cout<<"Time taken:"<< (double)(tStop-tStart)/ CLOCKS_PER_SEC << endl;
 }
 return 0;
}

