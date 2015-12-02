#include<iostream>
#include"Dictionary.h"

int main()
{
  char coll;
  cout<<"Enter the collision method: l for linear probing, d for double hashing, c for chain hashing\n";
  cin>>coll;
  int m=2*numLine();
  dictionary a;
  if(coll=='l'||coll=='c')
  {
    a.Assign(coll,m);
  }
  else if(coll=='d')
  {
    int size,offlen;
    cout<<"Enter Size of Table(Prime number) greater than "<<m<<"\n";
    cin>>size;
    cout<<"Enter a prime num offset for double hash\n";
    cin>>offlen;
    a.Assign(coll,size,offlen);
  }

  int temp=0;
  record h;
  char key[8];
  while(temp!=5)
    {
      cout<<"Enter: 1 for insertion 2 for search 3 for delete 4 for print 5 for exit\n";
      cin>>temp;
      switch(temp)
      {
      case 1:
	cout<<"Input as :\nPatient_Id Patient_Name Patient_Address Phone_No Disease Doctor_Name\n";
	h.storeRecord();
	if(!a.Insert(h))
	  {
      	    a.rehash();
	    a.Insert(h);
	    a.Modify_file();
	  }
	else
	  a.Modify_file();
	break;
      case 2:
	cout<<"Enter Key\n";
	cin>>key;
	if(a.Search(key))
	  cout<<"Found!!\n";
	else
	  cout<<"Not Found!!\n";
	break;
      case 3:
	cout<<"Enter Key\n";
	cin>>key;
	if(a.Delete(key))
	{
	  a.Modify_file();
	  cout<<"Deleted Successfully!!\n";
	}
	else
	  cout<<"Not Found!!\n";
	break;
      case 4:
	a.Display();
	break;
      default:
	break;
      }
    }
  return 0;
}
