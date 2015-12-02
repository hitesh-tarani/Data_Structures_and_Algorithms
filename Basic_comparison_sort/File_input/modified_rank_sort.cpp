#include<ctime>
#include <fstream>
#include<iostream>
using namespace std;

void Ranksort(int* a,int n)
{
  int i,j,k;
  int *u  = new int[n];
  int *r  = new int[n];
  for(j=0;j<n;j++)
    r[j]=1;
  for(i=1;i<n;i++)
  {
   if(r[i-1]==i && a[i]>=a[i-1])
	r[i]=i+1;
   else
   {
    for(k=0;k<i;k++)
    {
     if(a[i]>=a[k])
      r[i]=r[i]+1;
     else
      r[k]=r[k]+1;
    }
   }
  }
  for(i=0;i<n;i++)
    u[r[i]]=a[i];
  for(i=0;i<n;i++)
    a[i]=u[i+1];
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
