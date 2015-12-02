#ifndef _GRAPH_INCLUDED_H
#define _GRAPH_INCLUDED_H

#include<iostream>
#include"Linear_lists.h"
#include"linked_lists.h"

//template<class Type>

class vertex{
  friend class graph;
  private:
  vertex* pred;
  int pos;
  char color;
  int distance;
  int distance1;
  Chain<vertex*>* list;
 public:
  vertex();
  vertex(int );
  int getPos();
  void setColor(char );
  void setDistance(int );
  void setPred(vertex );
};

vertex::vertex()
{
  color='w';
  distance=-1;
  distance1=-1;
  pred=NULL;
}

vertex::vertex(int data)
{
  pos=data;
  color='w';
  distance=-1;
  pred=NULL;
}

int vertex::getPos()
{
  return pos;
}

void vertex::setColor(char colour)
{
  color=colour;
}

void vertex::setDistance(int d)
{
  distance=d;
}

void vertex::setPred(vertex a)
{
  pred=&a;
}

class graph{
 private:
  LinearList<vertex> v;
  LinearList< Chain<vertex*> > chain;
  int n;

 public:
  graph();
  graph(int );
  void setVertices(int );
  bool insertEdge(int , int );
  vertex* getVertex(int );
  //void Display();
  Chain<vertex*>& getList(vertex& a);
  void Display();
  void bfs();
  void bfs(vertex* );
  void dfs();
  void dfs(vertex* , int& );
  bool ifSymmetric();
};

graph::graph()
{

}

graph::graph(int vertices)
{
  int i;
  n=vertices;
  v.allocate_size(n);
  chain.allocate_size(n);
  for(i=0;i<n;i++)
  {
    v.returnListElement(i+1).pos=i+1;
    v.returnListElement(i+1).list=&chain.returnListElement(i+1);
  }
}

void graph::setVertices(int vertices)
{
  int i;
  n=vertices;
  v.allocate_size(n);
  chain.allocate_size(n);
  for(i=0;i<n;i++)
  {
    v.returnListElement(i+1).pos=i+1;
    v.returnListElement(i+1).list=&chain.returnListElement(i+1);
  }
}

bool graph::insertEdge(int a, int b)
{
  if(a>n||b>n)
    return false;
  vertex* x=&v.returnListElement(b);
  chain.returnListElement(a).insert(x);
  //v.returnListElement(b).insert(y);
  return true;
}

vertex* graph::getVertex(int a)
{
  return &v.returnListElement(a);
}

Chain<vertex*>& graph::getList(vertex& a)
{
  return chain.returnListElement(a.getPos());
}

void graph::Display()
{
  int i,j;
  std::cout<<"Adjacency List Representation\n";
  for(i=0;i<n;i++)
  {
    vertex a=v.returnListElement(i+1);
    vertex* b;
    std::cout<<a.pos<<" -> ";
    while(getList(a).traverse(b))
    {
      std::cout<<b->pos<<" ";
    }
    std::cout<<"\n";
  }
}

bool graphComp(vertex* a,vertex* b)
{
  if(a->getPos()==b->getPos())
    return 1;
  else
    return 0;
}

bool graph::ifSymmetric()
{
  int i,j;
  for(i=0;i<n;i++)
  {
    vertex a=v.returnListElement(i+1);
    vertex* b;
    while(getList(a).traverse(b))
    {
      if(a.pos==b->pos)
	return false;
      if(!getList(*b).search(&a,graphComp))
	return false;
    }
  }
  return true;
}

#endif
