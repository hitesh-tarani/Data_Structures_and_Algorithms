#ifndef _HEAP_INCLUDED_H
#define _HEAP_INCLUDED_H

#include"graph.h"
#include"Linear_lists.h"

template<class Type>
class heap{
  friend class graph;
 private:
  LinearList<Type> data;
  int size;
  LinearList<int> v;

 public:
  heap();
  heap(int );
  void allocate_size(int );
  bool isEmpty();
  int parent(int );
  int left(int );
  int right(int );
  Type heap_minimum();
  int  search(int );
  void insert(Type );
  void insert(Type , int(*function)(Type a, Type b));
  void decrease_key(Type , int );
  void decrease_key(Type , int , int(*function)(Type a, Type b));
  void heapify(int );
  void heapify(int, int(*function)(Type a, Type b));
  Type delete_min();
  Type delete_min(int(*function)(Type a, Type b));

};

template<class Type>
heap<Type>::heap()
{
  size=0;
}

template<class Type>
heap<Type>::heap(int n)
{
  size=0;
  data.allocate_size(n+1);
  v.allocate_size(n+1);
}

template<class Type>
void heap<Type>::allocate_size(int n)
{
  data.allocate_size(n+1);
  v.allocate_size(n+1);
}

template<class Type>
int  heap<Type>::search(int  x)
{
  return v.returnListElement(x+1);
}

template<class Type>
bool heap<Type>::isEmpty()
{
  return (size==0);
}

template<class Type>
int heap<Type>::parent(int x)
{
  return x/2;
}

template<class Type>
int heap<Type>::left(int x)
{
  return 2*x;
}

template<class Type>
int heap<Type>::right(int x)
{
  return (2*x+1);
}

template<class Type>
Type heap<Type>::heap_minimum()
{
  return data.returnListElement(2);
}

template<class Type>
void heap<Type>::insert(Type value)
{
  size++;
  decrease_key(value,size);
}

template<class Type>
void heap<Type>::insert(Type value, int(*function)(Type a, Type b))
{
  size++;
  v.insert(value.v->getPos()+1,size+1);
  decrease_key(value,size,function);
}

template<class Type>
void heap<Type>::decrease_key(Type value, int i)
{
  data.insert(i+1,value);
  while(i>1 && data.returnListElement(parent(i)+1)>data.returnListElement(i+1))
  {
    Type temp;
    temp=data.returnListElement(i+1);
    data.returnListElement(i+1)=data.returnListElement(parent(i)+1);
    data.returnListElement(parent(i)+1)=temp;
    i=parent(i);
  }
}


template<class Type>
void heap<Type>::decrease_key(Type value, int i, int(*function)(Type a, Type b))
{
  data.insert(i+1,value);
  while(i>1 && function(data.returnListElement(parent(i)+1),data.returnListElement(i+1))>0)
  {
    Type temp;
    v.returnListElement(data.returnListElement(i+1).v->getPos()+1)=parent(i)+1;
    v.returnListElement(data.returnListElement(parent(i)+1).v->getPos()+1)=i+1;
    temp=data.returnListElement(i+1);
    data.returnListElement(i+1)=data.returnListElement(parent(i)+1);
    data.returnListElement(parent(i)+1)=temp;
    i=parent(i);
  }
}

template<class Type>
void heap<Type>::heapify(int i)
{
  int l,r,least=i;
  l=left(i);
  r=right(i);
  if(l<=size && data.returnListElement(l+1)<data.returnListElement(i+1))
  {
    least=l;
  }
  if(r<=size && data.returnListElement(r+1)<data.returnListElement(least+1))
  {
    least=r;
  }
  if(least!=i)
  {
    Type temp;
    temp=data.returnListElement(i+1);
    data.returnListElement(i+1)=data.returnListElement(least+1);
    data.returnListElement(least+1)=temp;
    heapify(least);
  }
}

template<class Type>
void heap<Type>::heapify(int i, int(*function)(Type a, Type b))
{
  int l,r,least=i;
  l=left(i);
  r=right(i);
  if(l<=size && function(data.returnListElement(l+1),data.returnListElement(i+1))<0)
  {
    least=l;
  }
  if(r<=size && function(data.returnListElement(r+1),data.returnListElement(least+1))<0)
  {
    least=r;
  }
  if(least!=i)
  {
    Type temp;    
    v.returnListElement(data.returnListElement(i+1).v->getPos()+1)=least+1;
    v.returnListElement(data.returnListElement(least+1).v->getPos()+1)=i+1;
    temp=data.returnListElement(i+1);
    data.returnListElement(i+1)=data.returnListElement(least+1);
    data.returnListElement(least+1)=temp;
    heapify(least,function);
  }
}

template<class Type>
Type heap<Type>::delete_min()
{
  Type min=data.returnListElement(2);
  data.returnListElement(2)=data.returnListElement(size+1);
  size--;
  heapify(1);
  return min;
}

template<class Type>
Type heap<Type>::delete_min(int(*function)(Type a, Type b))
{
  Type min=data.returnListElement(2);
  data.returnListElement(2)=data.returnListElement(size+1);
  v.returnListElement(data.returnListElement(2).v->getPos()+1)=2;
  size--;
  heapify(1,function);
  return min;
}

#endif
