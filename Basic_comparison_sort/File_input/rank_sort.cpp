#include<ctime>
#include <fstream>
#include<iostream>
using namespace std;

void Ranksort(int* array,int n)
{
  int i,j,temp;
  int *a = new int[n];
  int *u  = new int[n];
  int *r  = new int[n];
 for(i=1;i<n;i++)
 {
  temp=array[i];
  for(j=i-1;temp<array[j]&&j>=0;j--)
  {
   array[j+1]=array[j];
  }
  array[j+1]=temp;
 } for(j=0;j<n;j++)
    {
      r[j]=0;
    }
  for(j=1;j<n;j++)
    {
      for(i=0;i<j;i++)
	{
	  if(a[i]<=a[j])
	    r[j]=r[j]+1;
	  else
	    r[i]=r[i]+1;
	}
    }
  for(j=0;j<n;j++)
    {
      u[r[j]]=a[j];
    }
  for(j=0;j<n;j++)
    {
      a[j]=u[j];
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
  Ranksort(array,n);
  clock_t tStop = clock();
  cout<<"Time taken:"<< (double)(tStop-tStart)/ CLOCKS_PER_SEC << endl;
 }
 return 0;
}
