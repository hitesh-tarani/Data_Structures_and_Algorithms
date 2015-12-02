#ifndef _DICTIONARY_INCLUDED_H
#define _DICTIONARY_INCLUDED_H
#include<iostream>
#include"hash.h"
#include"bst.h"
#include"avl.h"
#include"2-4.h"

class dictionary{
private:
  char type;
  char collmethod;
  int m;
  openhash data1;
  chain_hash data2;
  bst<record> tree1;
  avlTree<record> tree2;
  Tree234<record> tree3;
public:
  dictionary(char );
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

dictionary::dictionary(char type)
{
  this->type=type;
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
  if(type=='a')
  {
    tree2.insert(a,recordComp);
    tree2.balance();
  }
else if(type=='m')
{
tree3.insert(a,recordComp);
}
  else if(type=='b')
  {
    tree1.insert(a,recordComp);
  }
  else if(type=='h')
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
    rehash();
    Insert(a);
  }
}

bool dictionary::Search(char key[])
{
  if(type=='a')
  {
    return(tree2.search(key,recordComp));
  }
  else if(type=='b')
  {
    return(tree1.search(key,recordComp));
  }
  else if(type=='m')
  {
    return(tree3.search(key,recordComp));
  }

  else if(type=='h')
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
}

void dictionary::Display()
{
  if(type=='a')
  {
    cout<<"Level-order Display\n";
    tree2.levelorderDisplay();
  }
  else if(type=='b')
  {
    cout<<"Level-order Display\n";
    tree1.levelorderDisplay();
  }
  else if(type=='m')
  {
    cout<<"Level-order Display\n";
    tree3.levelorderDisplay();
  }
  else if(type=='h')
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
}

bool dictionary::Delete(char key[])
{
  if(type=='a')
  {
    if(tree2.deleteElement(key,recordComp))
    {
      tree2.balance();
      return true;
    }
    else
      return false;
  }
  else if(type=='b')
  {
    return(tree1.deleteElement(key,recordComp));
  }
  else if(type=='m')
  {
    return(tree3.deleteElement(key,recordComp));
  }
  else if(type=='h')
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
  ofstream outfile;
  outfile.open("input.txt",ofstream::out);
  if(type=='a')
  {
    tree2.PrintToFile(outfile);
  }
  else if(type=='b')
  {
    tree1.PrintToFile(outfile);
  }
  else if(type=='h')
  {
    if(collmethod=='c')
      data2.PrintToFile();
    else
      data1.PrintToFile();
  }
  outfile.close();
}

#endif
