#ifndef _GRAPH_INCLUDED_H
#define _GRAPH_INCLUDED_H

#include<iostream>
#include"Linear_lists.h"
#include"vertex.h"

//template<class Type>

class graph{
 private:
  LinearList<vertex> v;
  LinearList< Chain<weighted_node> > chain;
  int n;
  int m;

 public:
  graph();
  graph(int );
  void setVertices(int );
  bool insertEdge(int , int );
  bool insertEdge(int , int , int );
  vertex* getVertex(int );
  Chain<weighted_node>& getList(vertex& a);
  void Display();
  void bfs();
  void bfs(vertex* );
  void dfs();
  void dfs(vertex* , int& );
  bool ifSymmetric();
  void mst_kruskal();
};

graph::graph()
{

}

graph::graph(int vertices)
{
  int i;
  n=vertices;
  m=0;
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
  m=0;
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
  weighted_node temp(x,1);
  chain.returnListElement(a).insert(temp);
  //chain.returnListElement(b).insert(y);
  m++;
  return true;
}

bool graph::insertEdge(int a, int b, int weight)
{
  if(a>n||b>n)
    return false;
  vertex* x=&v.returnListElement(b);
  weighted_node temp(x,weight);
  //vertex* y=&v.returnListElement(a);
  chain.returnListElement(a).insert(temp);
  //chain.returnListElement(b).insert(y);
  m++;
  return true;
}

vertex* graph::getVertex(int a)
{
  return &v.returnListElement(a);
}

Chain<weighted_node>& graph::getList(vertex& a)
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
    weighted_node b;
    std::cout<<a.pos<<" -> ";
    while(getList(a).traverse(b))
    {
      std::cout<<b.next->pos<<" ";
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

bool graphComp(weighted_node a,weighted_node b)
{
  if(a.getNext()->getPos()==b.getNext()->getPos())
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
    weighted_node x(&a,1);
    weighted_node b;
    while(getList(a).traverse(b))
    {
      if(a.pos==b.next->pos)
	return false;
      if(!getList(*b.next).search(x,graphComp))
	return false;
    }
  }
  return true;
}

#endif
