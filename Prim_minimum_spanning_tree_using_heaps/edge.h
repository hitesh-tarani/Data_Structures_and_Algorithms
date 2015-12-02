#ifndef _EDGE_INCLUDED_H
#define _EDGE_INCLUDED_H

class edge{
  friend class graph;
 private:
  vertex* vertex1;
  vertex* vertex2;
  int weight;
 public:
  edge();
  edge(vertex* ,vertex* , int );
  int getWeight();
};

edge::edge()
{
  ;
}

edge::edge(vertex* a, vertex* b, int weight)
{
  vertex1=a;
  vertex2=b;
  this->weight=weight;
}

int edge::getWeight()
{
  return weight;
}

bool edgeComp(edge a, edge b)
{
  return(a.getWeight()<b.getWeight());
}

#endif
