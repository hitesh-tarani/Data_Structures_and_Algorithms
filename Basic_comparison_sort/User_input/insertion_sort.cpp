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
int main()
{
 int i,n;
 cout << "Enter the number of elements\n";
 cin >> n;
 int array[n];
 cout << "Enter the numbers\n";
 for(i=0;i<n;i++)
  cin >> array[i];
 
 Insort(array,n);
 cout << "Sorted Numbers\n";
 for(i=0;i<n;i++)
  cout << array[i] << " ";
 cout << "\n";
 return 0;
}
