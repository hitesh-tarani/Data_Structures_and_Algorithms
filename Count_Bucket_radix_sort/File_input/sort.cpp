#include<sys/time.h>
#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;

class sort{
private:
  int* arr;
  int len;
public:
  void storeElements(char [] , int );
  void CountSort(int , int );
  int* CountSort2(int  ,int );
  void BucketSort();
  void RadixSort(int , int );
  void Display(int );
};

void sort::storeElements(char* fname, int n)
{
  int i=0;
  ifstream inFile;
  inFile.open(fname);
  arr = (int*)malloc(n*sizeof(int));
  for(i=0;i<n;i++)
  {
    inFile >> arr[i];
  }
  len=n;
}

void sort::RadixSort(int k,int n)
{
  int i;

  for(i=1;i<=k;i*=10)
  {
    arr=CountSort2(i,n);
  }

}

int* sort::CountSort2(int index,int n)
{
  int i;
  int* temp;
  int* b = (int*)malloc(n*sizeof(int));
  int* c = new int[10];
  for(i=0;i<10;i++)
  {
    c[i]=0;
  }
  for(i=0;i<n;i++)
    c[(arr[i]/index)%10]++;
  for(i=1;i<10;i++)
    c[i]=c[i]+c[i-1];
  for(i=n-1;i>=0;i--)
  {
    b[c[(arr[i]/index)%10]-1]=arr[i];
    c[(arr[i]/index)%10]--;
  }/*
  temp=arr;
  arr=b;
  b=temp;*/
  return b;
}

void sort::CountSort(int k, int n)
{
  int i;
  int* c = new int[k];
  int* b = new int[n];
  for(i=0;i<k;i++)
  {
    c[i]=0;
  }
  for(i=0;i<n;i++)
    c[arr[i]-1]++;
  for(i=1;i<k;i++)
    c[i]=c[i]+c[i-1];
  for(i=n-1;i>=0;i--)
  {
    b[c[arr[i]-1]-1]=arr[i];
    c[arr[i]-1]--;
    }
  /*for(i=0;i<n;i++)
    cout << b[i] << " ";
    cout << "\n";*/
}

void sort::Display(int n)
{
  int i;
  for(i=0;i<n;i++)
    cout << arr[i] << " ";
  cout << "\n";
}

int main(int argc, char* argv[])
{
  int i,k=1000,n;
  string fname=argv[1];
  /*cout << "Enter the max element\n";
    cin >> k;*/
  system(("wc -l "+fname+"|awk '{print $1}' > tmp.txt").c_str());
  ifstream File;
  File.open("tmp.txt");
  File>>n;
  cout<<n<<"\n";
  sort a;
  a.storeElements(argv[1],n);
  //a.Display(n);
  struct timeval tvalBefore, tvalAfter;
  gettimeofday(&tvalBefore, NULL);
  a.RadixSort(k,n);
  a.Display(n);
  gettimeofday(&tvalAfter, NULL);
  cout<<"Time in microseconds: " << ((tvalAfter.tv_sec - tvalBefore.tv_sec)*(1000000L)+(tvalAfter.tv_usec - tvalBefore.tv_usec)) << "\n";
  return 0;
}
