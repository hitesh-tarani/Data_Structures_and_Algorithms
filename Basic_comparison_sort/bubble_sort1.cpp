#include<ctime>
#include<sys/time.h>
#include <fstream>
#include<iostream>
using namespace std;
//#define max 30000

void Bubbsort(int* a,int n)
{
 int i,j=n-1,temp;
 while(j>=1)
 {
  for(i=0;i<j;i++)
  {
   if(a[i]>a[i+1])
   {
    temp=a[i];
    a[i]=a[i+1];
    a[i+1]=temp;
   }
  }
  j=j-1;
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

  //clock_t tStart = clock();
  struct timeval tvalBefore, tvalAfter;
  gettimeofday (&tvalBefore, NULL);
  Bubbsort(array,n);
  gettimeofday (&tvalAfter, NULL);
  cout<<"Time in microseconds: " << ((tvalAfter.tv_sec - tvalBefore.tv_sec)*(1000000L)+(tvalAfter.tv_usec - tvalBefore.tv_usec)) << "\n";
  //clock_t tStop = clock();
  //cout<<"Time taken:"<< (double)(tStop-tStart)/ CLOCKS_PER_SEC << endl;
 }
 return 0;
}
