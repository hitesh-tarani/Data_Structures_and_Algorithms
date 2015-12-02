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
  void storeElements(char [], int );
  void BucketSort(int ,int );
  void Display(int );
};

class Node{
  friend class Chain;
private:
  int data;
  Node* next;
};

class Chain{
private:
  Node* first;
  Node* last;
public:
  Chain();
  void addNode(int );
  void addChain(Chain& );
  void Display();
};

Chain::Chain()
{
  first=last=NULL;
}

void Chain::addNode(int value)
{
  if(first!=NULL)
  {
    Node* a;
    a=(Node*)malloc(sizeof(Node));
    a->data=value;
    last->next=a;
    a->next=NULL;
    last=a;
  }
  else
  {
    Node* a;
    a=(Node*)malloc(sizeof(Node));
    a->data=value;
    first=a;
    last=a;
    a->next=NULL;
  }
}

void Chain::addChain(Chain& a)
{
  if(first!=NULL)
  {
    if(a.first!=NULL)
    {
      last->next=a.first;
      last=a.last;
    }
  }
  else
  {
    first=a.first;
    last=a.last;
  }
}

void Chain::Display()
{
  Node* a;
  for(a=first;a!=NULL;a=a->next)
  {
    cout<<a->data<<" ";
  }
  cout<<"\n";
}

void sort::BucketSort(int k, int n)
{
  int i=0;
  Chain b[k];
  for(i=0;i<n;i++)
  {
    b[arr[i]-1].addNode(arr[i]);
  }/*
  for(i=0;i<k;i++)
  {
    if(b[i].first!=NULL)
      cout<<"1 ";
      }*/  
  //cout<<&b[5]<<"\n";
  for(i=1;i<k;i++)
  {
    b[0].addChain(b[i]);
  }
  //b[0].Display();
}

void sort::storeElements(char* fname, int n)
{
  int i=0;
  ifstream inFile;
  inFile.open(fname);
  arr = new int[n];
  for(i=0;i<n;i++)
  {
    inFile >> arr[i];
  }
  len=n;
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
  a.BucketSort(k,n);
  //a.Display(n);
  gettimeofday(&tvalAfter, NULL);
  cout<<"Time in microseconds: " << ((tvalAfter.tv_sec - tvalBefore.tv_sec)*(1000000L)+(tvalAfter.tv_usec - tvalBefore.tv_usec)) << "\n";
  return 0;
}