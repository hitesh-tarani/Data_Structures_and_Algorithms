#ifndef _STACK_INCLUDED_H
#define _STACK_INCLUDED_H

#include<iostream>
#include"linked_lists.h"

template<class Type>
class stack{
 private:
  Chain<Type> s;
 public:
  bool isEmpty();
  int length();
  void push(Type );
  void pop(Type& );
};

template <class Type>
bool stack<Type>::isEmpty()
{
  return s.isEmpty();
}

template <class Type>
int stack<Type>::length()
{
  return s.length();
}

template<class Type>
void stack<Type>::push(Type a)
{
  s.insert(1,a);
}

template<class Type>
void stack<Type>::pop(Type& a)
{
  s.deleteElement(1,a);
}


#endif
