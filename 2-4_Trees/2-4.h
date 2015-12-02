#ifndef _2TO4_TREE_INCLUDED_H
#define _2TO4_TREE_INCLUDED_H
#include<cmath>
#include<iostream>
template<class Type>
class Tree234;

template<class Type>
class Node234{
  friend class Tree234<Type>;
 private:
  Node234<Type> *parent;
  Type data[3];
  int keys;
  Node234<Type> *child[4];
 public:
  Node234();
};

template<class Type>
Node234<Type>::Node234()
{
  parent=NULL;
  child[0]=child[1]=child[2]=child[3]=NULL;
  keys=0;
}

template<class Type>
class Tree234{
 protected:
  Node234<Type> *root;
  Node234<Type> *nil;
  int n;
  /*void inorderDisplay(bstNode<Type>* );
  void preorderDisplay(bstNode<Type>* );
  void PrintToFile(bstNode<Type>* , ofstream& );*/
 public:
  Tree234();
  //~Tree234();
  //bool isEmpty();
  //Node<Type>* getRoot();
  int length();
  void insert(Type );
  void insert(Type , int (*function)(char[] , Type ));
  void split(Node234<Type>* , Node234<Type>* , Node234<Type>* , Type );
  void Insert(Node234<Type>* , Type );
  void splitInsert(Node234<Type>* , Node234<Type>* , Node234<Type>* , int );
  void split(Node234<Type>* , Node234<Type>* , Node234<Type>* , Type , int (*function)(char[] , Type ));
  void Insert(Node234<Type>* , Type , int (*function)(char[] , Type ));
  void splitInsert(Node234<Type>* , Node234<Type>* , Node234<Type>* , int , int (*function)(char[] , Type ));
  bool search(Type );
  bool search(char[] , int (*function)(char[] ,Type ));
  //Node<Type>* successor(Node<Type>* );
  bool deleteElement(Type );
  bool deleteElement(char[] , int(*function)(char[] ,Type ));
  Node234<Type>* successor(Node234<Type>* , int );
  bool merge(Node234<Type>* , int );
  bool rotate(Node234<Type>* , int );
  void Delete(Node234<Type>* , Type );
  bool merge(Node234<Type>* , int , int (*function)(char[] , Type ));
  bool rotate(Node234<Type>* , int , int (*function)(char[] , Type ));
  void Delete(Node234<Type>* , char[] , int (*function)(char[] , Type ));
  //void inorderDisplay();
  //void preorderDisplay();
  void levelorderDisplay();
  void levelorderDisplay(Node234<Type>* ,int ,int );
  //void PrintToFile(ofstream& );
};

template<class Type>
Tree234<Type>::Tree234()
{
  root=NULL;
  nil=new Node234<Type>;
  n=0;
}

template<class Type>
int Tree234<Type>::length()
{
  return n;
}

template<class Type>
void Tree234<Type>::insert(Type data)
{
  Node234<Type>* x=root;
  Node234<Type>* a=new Node234<Type>;
  int i,j;
  if(root==NULL)
  {
    root=a;
    a->parent=nil;
    a->data[0]=data;
    a->child[0]=a->child[1]=nil;
    a->keys++;
  }
  else
  {
    while(x->child[0]!=nil)
    {
      for(i=0;i<x->keys;i++)
      {
	if(data<x->data[i])
	  break;
      }
      x=x->child[i];
    }
    if(x->keys<3)
    {
      Insert(x,data);
    }
    else
    {
      Node234<Type>* first=new Node234<Type>;
      Node234<Type>* second=new Node234<Type>;
      split(x,first,second,data);
      for(j=0;j<(x->parent)->keys;j++)
      {
	if((x->parent)->child[j]==x)
	  break;
      }
      first->child[0]=first->child[1]=second->child[0]=second->child[1]=second->child[2]=nil;
      splitInsert(x->parent,first,second,j);
      //delete x;
    }
  }
  n++;
}

template<class Type>
void Tree234<Type>::split(Node234<Type>* x,Node234<Type>* first,Node234<Type>* second,Type data)
{
  int i;
  for(i=0;i<x->keys;i++)
  {
    if(data<x->data[i])
      break;
  }
  if(i<2)
  {
    first->data[0]=first->data[1]=x->data[0];
    first->data[i]=data;
    second->data[0]=x->data[1];
    second->data[1]=x->data[2];
  }
  else
  {
    first->data[0]=x->data[0];
    first->data[1]=x->data[1];
    second->data[0]=second->data[1]=x->data[2];
    second->data[i-2]=data;
  }
  first->keys=second->keys=2;
}

template<class Type>
void Tree234<Type>::Insert(Node234<Type>* x,Type data)
{
  int i,j;
  for(i=0;i<x->keys;i++)
  {
    if(data<x->data[i])
      break;
  }
  x->child[x->keys+1]=nil;
  j=x->keys;
  while(j>i)
  {
    x->data[j]=x->data[j-1];
    j--;
  }
  x->data[j]=data;
  x->keys++;
}

template<class Type>
void Tree234<Type>::insert(Type data, int (*function)(char a[],Type b))
{
  Node234<Type>* x=root;
  Node234<Type>* a=new Node234<Type>;
  int i,j;
  if(root==NULL)
  {
    root=a;
    a->parent=nil;
    a->data[0]=data;
    a->child[0]=a->child[1]=nil;
    a->keys++;
  }
  else
  {
    while(x->child[0]!=nil)
    {
      for(i=0;i<x->keys;i++)
      {
	if(function(data.getId(),x->data[i])==-1)
	  break;
      }
      x=x->child[i];
    }
    if(x->keys<3)
    {
      Insert(x,data,function);
    }
    else
    {
      Node234<Type>* first=new Node234<Type>;
      Node234<Type>* second=new Node234<Type>;
      split(x,first,second,data,function);
      for(j=0;j<(x->parent)->keys;j++)
      {
	if((x->parent)->child[j]==x)
	  break;
      }
      first->child[0]=first->child[1]=second->child[0]=second->child[1]=second->child[2]=nil;
      splitInsert(x->parent,first,second,j,function);
      //delete x;
    }
  }
  n++;
}

template<class Type>
void Tree234<Type>::split(Node234<Type>* x,Node234<Type>* first,Node234<Type>* second,Type data, int (*function)(char a[],Type b))
{
  int i;
  for(i=0;i<x->keys;i++)
  {
    if(function(data.getId(),x->data[i])==-1)
      break;
  }
  if(i<2)
  {
    first->data[0]=first->data[1]=x->data[0];
    first->data[i]=data;
    second->data[0]=x->data[1];
    second->data[1]=x->data[2];
  }
  else
  {
    first->data[0]=x->data[0];
    first->data[1]=x->data[1];
    second->data[0]=second->data[1]=x->data[2];
    second->data[i-2]=data;
  }
  first->keys=second->keys=2;
}

template<class Type>
void Tree234<Type>::Insert(Node234<Type>* x,Type data, int (*function)(char a[],Type b))
{
  int i,j;
  for(i=0;i<x->keys;i++)
  {
    if(function(data.getId(),x->data[i])==-1)
      break;
  }
  x->child[x->keys+1]=nil;
  j=x->keys;
  while(j>i)
  {
    x->data[j]=x->data[j-1];
    j--;
  }
  x->data[j]=data;
  x->keys++;
}

template<class Type>
void Tree234<Type>::splitInsert(Node234<Type>* x,Node234<Type>* first,Node234<Type>* second,int i)
{
  if(x==nil)
  {
    Node234<Type>* a=new Node234<Type>;
    a->data[0]=first->data[1];
    first->keys=1;
    a->keys=1;
    a->child[0]=first;
    a->child[1]=second;
    root=a;
    a->parent=nil;
    first->parent=second->parent=root;
  }
  else if(x->keys<3)
  {
    Insert(x,first->data[1]);
    first->keys=1;
    first->parent=second->parent=x;
    int j;
    j=x->keys;
    while(j>i+1)
    {
      x->child[j]=x->child[j-1];
      j--;
    }
    x->child[i]=first;
    x->child[i+1]=second;
  }
  else
  {
    int j;
    Node234<Type>* x1=new Node234<Type>;
    Node234<Type>* x2=new Node234<Type>;
    split(x,x1,x2,first->data[1]);
    for(j=0;j<(x->parent)->keys;j++)
    {
      if((x->parent)->child[j]==x)
	break;
    }
    first->keys=1;
    x1->child[0]=x->child[0];
    x1->child[1]=x->child[1];
    x2->child[0]=x->child[1];
    x2->child[1]=x->child[2];
    x2->child[2]=x->child[3];
    x->child[0]->parent=x1;
    x->child[1]->parent=x2;
    x->child[2]->parent=x2;
    x->child[3]->parent=x2;
    if(i==0)
    {
      x1->child[0]=first;
      x1->child[1]=second;
      first->parent=second->parent=x1;
    }
    else if(i==1)
    {
      x1->child[1]=first;
      x2->child[0]=second;
      first->parent=x1;
      second->parent=x2;
    }
    else if(i==2)
    {
      x2->child[0]=first;
      x2->child[1]=second;
      first->parent=second->parent=x2;
    }
    else
    {
      x2->child[1]=first;
      x2->child[2]=second;
      first->parent=second->parent=x2;
      x->child[1]->parent=x1;
      x2->child[0]=x->child[2];
    }
    splitInsert(x->parent,x1,x2,j);
  }
}

template<class Type>
void Tree234<Type>::splitInsert(Node234<Type>* x,Node234<Type>* first,Node234<Type>* second,int i, int (*function)(char a[],Type b))
{
  if(x==nil)
  {
    Node234<Type>* a=new Node234<Type>;
    a->data[0]=first->data[1];
    first->keys=1;
    a->keys=1;
    a->child[0]=first;
    a->child[1]=second;
    root=a;
    a->parent=nil;
    first->parent=second->parent=root;
  }
  else if(x->keys<3)
  {
    Insert(x,first->data[1],function);
    first->keys=1;
    first->parent=second->parent=x;
    int j;
    j=x->keys;
    while(j>i+1)
    {
      x->child[j]=x->child[j-1];
      j--;
    }
    x->child[i]=first;
    x->child[i+1]=second;
  }
  else
  {
    int j;
    Node234<Type>* x1=new Node234<Type>;
    Node234<Type>* x2=new Node234<Type>;
    split(x,x1,x2,first->data[1],function);
    for(j=0;j<(x->parent)->keys;j++)
    {
      if((x->parent)->child[j]==x)
	break;
    }
    first->keys=1;
    x1->child[0]=x->child[0];
    x1->child[1]=x->child[1];
    x2->child[0]=x->child[1];
    x2->child[1]=x->child[2];
    x2->child[2]=x->child[3];
    x->child[0]->parent=x1;
    x->child[1]->parent=x2;
    x->child[2]->parent=x2;
    x->child[3]->parent=x2;
    if(i==0)
    {
      x1->child[0]=first;
      x1->child[1]=second;
      first->parent=second->parent=x1;
    }
    else if(i==1)
    {
      x1->child[1]=first;
      x2->child[0]=second;
      first->parent=x1;
      second->parent=x2;
    }
    else if(i==2)
    {
      x2->child[0]=first;
      x2->child[1]=second;
      first->parent=second->parent=x2;
    }
    else
    {
      x2->child[1]=first;
      x2->child[2]=second;
      first->parent=second->parent=x2;
      x->child[1]->parent=x1;
      x2->child[0]=x->child[2];
    }
    splitInsert(x->parent,x1,x2,j,function);
  }
}

template<class Type>
bool Tree234<Type>::search(Type data)
{
  Node234<Type>* x=root;
  int i;
  while(x!=nil)
  {
    for(i=0;i<x->keys;i++)
    {
      if(data<=x->data[i])
	break;
    }
    if(i<3 && data==x->data[i])
    {
      std::cout<<x->data[i]<<std::endl;
      return true;
    }
    x=x->child[i];
  }
  return false;
}

template<class Type>
bool Tree234<Type>::search(char data[], int (*function)(char b[] ,Type a))
{
  Node234<Type>* x=root;
  int i;
  while(x!=nil)
  {
    for(i=0;i<x->keys;i++)
    {
      if(function(data,x->data[i])==0||function(data,x->data[i])==-1)
	break;
    }
    if(i<3 && function(data,x->data[i])==0)
    {
      x->data[i].Display();
      return true;
    }
    x=x->child[i];
  }
  return false;
}

template<class Type>
bool Tree234<Type>::deleteElement(Type data)
{
  Node234<Type>* x=root;
  int i,j;
  while(x!=nil)
  {
    for(i=0;i<x->keys;i++)
    {
      if(data<=x->data[i])
	break;
    }
    if(i<3 && data==x->data[i])
    {
      if(x->child[0]==nil)
      {
	if(x->keys>1)
	{
	  Delete(x,data);
	  return true;
	}
	else
	{
	  Node234<Type>* y;
	  y=x->parent;
	  for(j=0;j<y->keys;j++)
	  {
	    if(y->child[j]==x)
	      break;
	  }
	  if(rotate(x,j))
	    return true;
	  if(merge(x,j))
	    return true;
	}
      }
      else
      {
	//not leaf
	Node234<Type>* y;
	y=successor(x,i);
	//std::cout<<i;
	Type temp;
	temp=x->data[i];
	x->data[i]=y->data[0];
	y->data[0]=temp;
	Delete(y,temp);
	if(y->keys==0)
	{
	  Node234<Type>* z;
	  z=y->parent;
	  for(j=0;j<z->keys;j++)
	  {
	    if(z->child[j]==y)
	      break;
	  }
	  merge(y,j);
	}
      }
      return true;
    }
    x=x->child[i];
  }
  return false;
}

template<class Type>
Node234<Type>* Tree234<Type>::successor(Node234<Type>* x, int i)
{
  Node234<Type>* y;
  y=x->child[i+1];
  while(y->child[0]!=nil)
    y=y->child[0];
  return y;
}

template<class Type>
bool Tree234<Type>::merge(Node234<Type>* x, int i)
{
  int j;
  Node234<Type>* y=x->parent;
    if(i==0)
    {
      Node234<Type>* a=new Node234<Type>;
      a->data[0]=y->data[0];
      a->child[0]=x->child[0];
      a->data[1]=y->child[1]->data[0];
      a->child[1]=y->child[1]->child[0];
      a->child[2]=y->child[1]->child[1];
      j=0;
      while(j<y->keys-1)
      {
	y->data[j]=y->data[j+1];
	y->child[j+1]=y->child[j+2];
	j++;
      }
      y->child[0]=a;
      y->keys--;
      a->keys=2;
      a->parent=y;
      //delete x;
      //delete y->child[1];
    }
    else
    {
      Node234<Type>* a=new Node234<Type>;
      a->data[0]=y->child[i-1]->data[y->child[i-1]->keys-1];
      a->child[0]=y->child[i-1]->child[0];
      a->child[1]=y->child[i-1]->child[1];
      a->data[1]=y->data[i-1];
      a->child[2]=x->child[0];
      j=i-1;
      while(j<y->keys-1)
      {
	y->data[j]=y->data[j+1];
	y->child[j+1]=y->child[j+2];
	j++;
      }
      y->child[i-1]=a;
      y->keys--;
      a->keys=2;
      a->parent=y;
      //delete x;
      //delete y->child[i-1];
    }
    if(y->keys==0)
    {
      Node234<Type>* z;
      z=y->parent;
      if(z==nil)
      {
        root=y->child[0];
      }
      else
      {
	if(z==nil)
	{
	  root=y->child[0];
	  return true;
	}
	else
	{
	  for(j=0;j<z->keys;j++)
	  {
	    if(z->child[j]==y)
	      break;
	  }
	  if(rotate(y,j))
	    return true;
	  merge(y,j);
	}
      }
    }
    else
      return true;

}

template<class Type>
bool Tree234<Type>::rotate(Node234<Type>* x, int j)
{
  Node234<Type>* y=x->parent;
  if(j==0)
    {
      if(y->child[1]->keys>1)
	{
	  x->data[0]=y->data[0];
	  y->data[0]=y->child[1]->data[0];
	  Delete(y->child[1],y->child[1]->data[0]);
	  return true;
	}
    }
  else if(j==3)
    {
      if(y->child[2]->keys>1)
	{
	  x->data[0]=y->data[2];
	  y->data[2]=y->child[2]->data[y->child[2]->keys-1];
	  Delete(y->child[2],y->child[2]->data[y->child[2]->keys-1]);
	  return true;
	}
    }
  else
    {
      if(y->child[j-1]->keys>1)
	{
	  x->data[0]=y->data[j-1];
	  y->data[j-1]=y->child[j-1]->data[y->child[j-1]->keys-1];
	  Delete(y->child[j-1],y->child[j-1]->data[y->child[j-1]->keys-1]);
	  return true;
	}
      else if(y->child[j+1]->keys>1)
	{
	  x->data[0]=y->data[j];
	  y->data[j]=y->child[j+1]->data[0];
	  Delete(y->child[j+1],y->child[j+1]->data[0]);
	  return true;
	}
    }
}

template<class Type>
void Tree234<Type>::Delete(Node234<Type>* x, Type data)
{
  int i,j;
  for(i=0;i<x->keys;i++)
  {
    if(data==x->data[i])
      break;
  }
  x->child[x->keys]=NULL;
  j=i;
  while(j<x->keys-1)
  {
    x->data[j]=x->data[j+1];
    j++;
  }
  x->keys--;
}

template<class Type>
bool Tree234<Type>::deleteElement(char data[], int (*function)(char b[] ,Type a))
{
  Node234<Type>* x=root;
  int i,j;
  while(x!=nil)
  {
    for(i=0;i<x->keys;i++)
    {
      if(function(data,x->data[i])==0||function(data,x->data[i])==-1)
	break;
    }
    if(i<3 && function(data,x->data[i])==0)
    {
      if(x->child[0]==nil)
      {
	if(x->keys>1)
	{
	  Delete(x,data,function);
	  return true;
	}
	else
	{
	  Node234<Type>* y;
	  y=x->parent;
	  for(j=0;j<y->keys;j++)
	  {
	    if(y->child[j]==x)
	      break;
	  }
	  if(rotate(x,j,function))
	    return true;
	  if(merge(x,j,function))
	    return true;
	}
      }
      else
      {
	//not leaf
	Node234<Type>* y;
	y=successor(x,i);
	//std::cout<<i;
	Type temp;
	temp=x->data[i];
	x->data[i]=y->data[0];
	y->data[0]=temp;
	Delete(y,data,function);
	if(y->keys==0)
	{
	  Node234<Type>* z;
	  z=y->parent;
	  if(z==nil)
	  {
	    root=y->child[0];
	    y->child[0]->parent=nil;
	    return true;
	  }
	  else
	  {
	    for(j=0;j<z->keys;j++)
	    {
	      if(z->child[j]==y)
		break;
	    }
	    merge(y,j,function);
	  }
	}
      }
      return true;
    }
    x=x->child[i];
  }
  return false;
}

template<class Type>
bool Tree234<Type>::merge(Node234<Type>* x, int i, int (*function)(char[] , Type ))
{
  int j;
  Node234<Type>* y=x->parent;
    if(i==0)
    {
      Node234<Type>* a=new Node234<Type>;
      a->data[0]=y->data[0];
      a->child[0]=x->child[0];
      a->data[1]=y->child[1]->data[0];
      a->child[1]=y->child[1]->child[0];
      a->child[2]=y->child[1]->child[1];
      j=0;
      while(j<y->keys-1)
      {
	y->data[j]=y->data[j+1];
	y->child[j+1]=y->child[j+2];
	j++;
      }
      y->child[0]=a;
      y->keys--;
      a->keys=2;
      a->parent=y;
      //delete x;
      //delete y->child[1];
    }
    else
    {
      Node234<Type>* a=new Node234<Type>;
      a->data[0]=y->child[i-1]->data[y->child[i-1]->keys-1];
      a->child[0]=y->child[i-1]->child[0];
      a->child[1]=y->child[i-1]->child[1];
      a->data[1]=y->data[i-1];
      a->child[2]=x->child[0];
      j=i-1;
      while(j<y->keys-1)
      {
	y->data[j]=y->data[j+1];
	y->child[j+1]=y->child[j+2];
	j++;
      }
      y->child[i-1]=a;
      y->keys--;
      a->keys=2;
      a->parent=y;
      //delete x;
      //delete y->child[i-1];
    }
    if(y->keys==0)
    {
      Node234<Type>* z;
      z=y->parent;
      if(z==nil)
      {
	root=y->child[0];
	y->child[0]->parent=nil;
	return true;
      }
      else
      {
	for(j=0;j<z->keys;j++)
	{
	  if(z->child[j]==y)
	    break;
	}
	if(rotate(y,j,function))
	  return true;
	if(merge(y,j,function))
	  return true;
      }
    }
    else
      return true;

}

template<class Type>
bool Tree234<Type>::rotate(Node234<Type>* x, int j, int (*function)(char[] , Type ))
{
  Node234<Type>* y=x->parent;
  if(j==0)
    {
      if(y->child[1]->keys>1)
	{
	  x->data[0]=y->data[0];
	  y->data[0]=y->child[1]->data[0];
	  Delete(y->child[1],y->child[1]->data[0].getId(),function);
	  return true;
	}
    }
  else if(j==3)
    {
      if(y->child[2]->keys>1)
	{
	  x->data[0]=y->data[2];
	  y->data[2]=y->child[2]->data[y->child[2]->keys-1];
	  Delete(y->child[2],y->child[2]->data[y->child[2]->keys-1].getId(),function);
	  return true;
	}
    }
  else
    {
      if(y->child[j-1]->keys>1)
	{
	  x->data[0]=y->data[j-1];
	  y->data[j-1]=y->child[j-1]->data[y->child[j-1]->keys-1];
	  Delete(y->child[j-1],y->child[j-1]->data[y->child[j-1]->keys-1].getId(),function);
	  return true;
	}
      else if(y->child[j+1]->keys>1)
	{
	  x->data[0]=y->data[j];
	  y->data[j]=y->child[j+1]->data[0];
	  Delete(y->child[j+1],y->child[j+1]->data[0].getId(),function);
	  return true;
	}
    }
  return false;
}

template<class Type>
void Tree234<Type>::Delete(Node234<Type>* x, char data[], int (*function)(char[] , Type ))
{
  int i,j;
  for(i=0;i<x->keys;i++)
  {
    if(function(data,x->data[i])==0)
      break;
  }
  x->child[x->keys]=NULL;
  j=i;
  while(j<x->keys-1)
  {
    x->data[j]=x->data[j+1];
    j++;
  }
  x->keys--;
}

template<class Type>
void Tree234<Type>::levelorderDisplay()
{
  int i,j,level=0;
  Node234<Type>* x=root;
  while(x->child[0]!=nil)
  {
    level++;
    x=x->child[0];
  }
  for(i=0;i<=level;i++)
  {
    for(j=0;j<pow(2,(level-i));j++)
     {
       std::cout<<"       ";
     }
    levelorderDisplay(root,i,level-i);
    std::cout<<"\n";
  }
}

template<class Type>
void Tree234<Type>::levelorderDisplay(Node234<Type>* x,int level,int z)
{
  if(x==nil)
  {
    int y=pow(2,z+1),j;
    for(j=0;j<y;j++)
      std::cout<<"       ";
    return ;
  }
  if(level==0)
  {
    int i=0;
    while(i<x->keys)
    {
      std::cout<<x->data[i].getId()<<"  ";
      i++;
    }
    int y=pow(2,z+1),j;
    for(j=0;j<y-1;j++)
      std::cout<<"       ";
    return ;
  }
  int j;
  for(j=0;j<=x->keys;j++)
  {
    levelorderDisplay(x->child[j],level-1,z);
  }
}
#endif
