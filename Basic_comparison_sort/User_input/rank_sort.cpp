#include<iostream>
using namespace std;

void Ranksort(int* array,int n)
{
  int i,j,temp,a[n],r[n],u[n];
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

int main()
{
 int i,n;
 cout << "Enter the number of elements\n";
 cin >> n;
 int array[n];
 cout << "Enter the numbers\n";
 for(i=0;i<n;i++)
  cin >> array[i];

 Ranksort(array,n);
 cout << "Sorted Numbers\n";
 for(i=0;i<n;i++)
  cout << array[i] << " ";
 cout << "\n";
 return 0;
}
