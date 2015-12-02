#include<ctime>
#include <fstream>
#include<iostream>
using namespace std;

void Insort(int* array,int n)
{
 int i,j,temp;
 for(i=1;i<n;i++)
 {
  temp=array[i];
  for(j=i-1;temp<array[j]&&j>=0;j--)
  {
   array[j+1]=array[j];
  }
  array[j+1]=temp;
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
  Insort(array,n);
  clock_t tStop = clock();
  cout<<"Time taken:"<< (double)(tStop-tStart)/ CLOCKS_PER_SEC << endl;
 }
 return 0;
}
