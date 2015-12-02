#include<iostream>
using namespace std;
//#define max 30000

int partition(int *a,int p,int r)
{
 int i,j,temp,pivot;
 pivot=a[r];
 i=p-1;
 j=r+1;
 while(1)
 {
  do
  {
   j--;
  }while(a[j]>pivot);
  do
  {
   i++;
  }while(a[i]<pivot);
  
  if(i<j)
  {
   temp=a[i];
   a[i]=a[j];
   a[j]=temp;
  }
  else
   return (i-1);
 }
}

void Partsort(int* a,int p,int r)
{
 int i,q;
 if(p<r)
 {
  q=partition(a,p,r);
  Partsort(a,p,q);
  Partsort(a,q+1,r);
 }
}

int main()
{
 int i,n;
 cout << "Enter the number of elements\n";
 cin >> n;
 int array[n];
 cout << "Enter the numbers\n";
 for(i=0;i<n;i++)
  cin >> array[i];

 Partsort(array,0,n-1);
 cout << "Sorted Numbers\n";
 for(i=0;i<n;i++)
  cout << array[i] << " ";
 cout << "\n";
 return 0;
}

