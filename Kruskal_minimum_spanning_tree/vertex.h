#ifndef _VERTEX_INCLUDED_H
#define _VERTEX_INCLUDED_H

#include"linked_lists.h"
class weighted_node;

class vertex{
  friend class graph;
  private:
  int pos;
  Chain<weighted_node>* list;
 public:
  vertex();
  vertex(int );
  int getPos();
};

vertex::vertex()
{
  ;
}

vertex::vertex(int data)
{
  pos=data;
}

int vertex::getPos()
{
  return pos;
}

class weighted_node{
  friend class graph;
 private:
  vertex* next;
  int weight;

 public:
  weighted_node();
  weighted_node(vertex* , int );
  vertex* getNext();
};

weighted_node::weighted_node()
{
  ;
}

weighted_node::weighted_node(vertex* v, int w)
{
  next=v;
  weight=w;
}

vertex* weighted_node::getNext()
{
  return next;
}

#endif
