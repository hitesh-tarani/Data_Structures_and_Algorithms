#ifndef _DICTIONARY_INCLUDED_H
#define _DICTIONARY_INCLUDED_H
#include<iostream>
#include"hash.h"

class dictionary{
private:
  char collmethod;
  int m;
  openhash data1;
  chain_hash data2;
public:
  dictionary();
  dictionary(char ,int );
  bool Assign(char ,int );
  bool Assign(char ,int ,int );
  void rehash();
  bool Insert(record );
  bool Delete(char key[]);
  bool Search(char key[]);
  void Display();
  void Modify_file();
};

dictionary::dictionary()
{
  ;
}

int numLine()
{
  system("wc -l input.txt > temp.txt");
  ifstream infile;
  infile.open("temp.txt");
  int line;
  infile>>line;
  infile.close();
  return line;
}

dictionary::dictionary(char coll,int size)
{
  collmethod=coll;
  m=size;
  int line=numLine();
  if(coll=='l'||coll=='d')
  {
    data1.allocate_size(coll,size);
    data1.storeElements(line);
  }
  else if(coll=='c')
  {
    data2.allocate_size(size);
    data2.storeElements(line);
  }
}

bool dictionary::Assign(char coll,int size)
{
  collmethod=coll;
  m=size;
  int line=numLine();
  if(coll=='l'||coll=='d')
  {
    data1.allocate_size(coll,size);
    return(data1.storeElements(line));
  }
  else if(coll=='c')
  {
    data2.allocate_size(size);
    return(data2.storeElements(line));
  }
}

bool dictionary::Assign(char coll,int size,int offlen)
{
  collmethod=coll;
  m=size;
  int line=numLine();
  if(coll=='l'||coll=='d')
  {
    data1.allocate_size(coll,size,offlen);
    data1.storeElements(line);
  }
  else if(coll=='c')
  {
    data2.allocate_size(size);
    data2.storeElements(line);
  }
}

bool dictionary::Insert(record a)
{
  if(collmethod!='c')
  {
    if(data1.insert(a))
      return true;
  }
  else
  {
    if(data2.insert(a))
      return true;
  }
  cout<<"Rehashing hash table\n";
  return false;
}

bool dictionary::Search(char key[])
{
  if(collmethod!='c')
  {
    return(data1.search(key));
  }
  else
  {
    return(data2.search(key));
  }
}

void dictionary::Display()
{
  if(collmethod!='c')
  {
    return(data1.Display());
  }
  else
  {
    return(data2.Display());
  }
}

bool dictionary::Delete(char key[])
{
  if(collmethod!='c')
  {
    return(data1.Delete(key));
  }
  else
  {
    return(data2.Delete(key));
  }
}

void dictionary::rehash()
{
  int line=numLine();
  if(collmethod=='c'||collmethod=='l')
    Assign(collmethod,2*line);
  else
    {
      int size,offlen;
      cout<<"Enter Size of Table(Prime number) greater than "<<2*line<<"\n";
      cin>>size;
      cout<<"Enter a prime num offset for double hash\n";
      cin>>offlen;
      Assign(collmethod,size,offlen);
    }
}

void dictionary::Modify_file()
{
  if(collmethod=='c')
    data2.PrintToFile();
  else
    data1.PrintToFile();
}

#endif