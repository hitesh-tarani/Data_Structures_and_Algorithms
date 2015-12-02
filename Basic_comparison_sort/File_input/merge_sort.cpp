#include<ctime>
#include <fstream>
#include<iostream>
using namespace std;
#define max 30000

void Merge(int* array,int p,int q,int r)
{
 int no1,no2,i,j,k;
 no1=q-p+1;
 no2=r-q;
 int *a1=new int[no1+1];
 int *a2=new int[no2+1];
 for(i=0;i<no1;i++)
 {
  a1[i]=array[i+p];
 }
 for(i=0;i<no2;i++)
 {
  a2[i]=array[i+q+1];
 }
 a1[no1]=a2[no2]=max;
 i=j=0;
 for(k=p;k<r+1;k++)
 {
  if(a1[i]<=a2[j])
  {
   array[k]=a1[i];
   i++;
  }
  else
  {
   array[k]=a2[j];
   j++;
  }
 }
}

void Mergesort(int* array,int p,int r)
{
 int q;
 if(p<r)
 {
  q=(p+r)/2;
  Mergesort(array,p,q);
  Mergesort(array,q+1,r);
  Merge(array,p,q,r);
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
  int *array=new int[n];
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
  Mergesort(array,0,n-1);
  clock_t tStop = clock();
  cout<<"Time taken:"<< (double)(tStop-tStart)/ CLOCKS_PER_SEC << endl;
 }
 return 0;
}
