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

int main()
{
 int i,n;
 cout << "Enter the number of elements\n";
 cin >> n;
 int array[n];
 cout << "Enter the numbers\n";
 for(i=0;i<n;i++)
  cin >> array[i];

 Bubbsort(array,n);
 cout << "Sorted Numbers\n";
 for(i=0;i<n;i++)
  cout << array[i] << " ";
 cout << "\n";
 return 0;
}

