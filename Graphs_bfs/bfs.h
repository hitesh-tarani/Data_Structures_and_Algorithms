#include"graph.h"
#include"queue.h"
#include"stack.h"
#include<ctime>
#include<cstdlib>

void graph::bfs()
{
  std::cout<<"Breadth-First-Search\n\n";
  srand(time(0));
  vertex* s=getVertex(rand()%n+1);
  std::cout<<"Source Vertex : "<<s->pos<<"\n";
  s->distance=0;
  bfs(s);
}

void graph::bfs(vertex* s)
{
  s->color='g';
  queue<vertex*> q;
  q.enqueue(s);
  vertex* x;
  std::cout<<"Inserted Edges\n";
  while(!q.isEmpty())
  {
    q.dequeue(x);
    x->color='b';
    //std::cout<<x->pos<<"\n";
    vertex* a;
    while(getList(*x).traverse(a))
    {
      //std::cout<<a->color<<"\n";
      if(a->color=='w')
      {
	a->color='g';
	a->distance=x->distance+1;
	a->pred=x;
	std::cout<<"("<<x->pos<<","<<a->pos<<")\n";
	q.enqueue(a);
      }
    }
  }
  int i;
  vertex* a;
  std::cout<<"Resulting Sub-graph\n";
  std::cout<<"Pos Dist Pred\n";
  for(i=0;i<n;i++)
  {
    a=getVertex(i+1);
    std::cout<<a->pos<<"    "<<a->distance<<"    ";
    if(a->pred==NULL)
      std::cout<<"--\n";
    else
      std::cout<<a->pred->pos<<"\n";
  }
}


void graph::dfs()
{
  std::cout<<"Depth-First-Search\n\n";
  srand(time(0));
  int i=0,j,time1=0;
  vertex* s=getVertex(rand()%n+1);
  std::cout<<"Source Vertex : "<<s->pos<<"\n";
  vertex* u=s;
  while(i<n)
  {
    i++;
    if(u->color=='w')
      if(i!=1)
      {
	std::cout<<"New Source Vertex : "<<u->pos<<"\n";
	dfs(u,time1);
      }
      else
	dfs(u,time1);
    j=u->getPos();
    if(j!=n)
      u=&v.returnListElement(j+1);
    else
      u=&v.returnListElement(1);
  }
  vertex* a;
  std::cout<<"Resulting Sub-graph\n";
  std::cout<<"Pos Disc Finish Pred\n";
  for(i=0;i<n;i++)
  {
    a=getVertex(i+1);
    std::cout<<a->pos<<"    "<<a->distance<<"    "<<a->distance1<<"       ";
    if(a->pred==NULL)
      std::cout<<"--\n";
    else
      std::cout<<a->pred->pos<<"\n";
  }
}


void graph::dfs(vertex* u,int& time1)
{
  u->color='g';
  time1++;
  u->distance=time1;
  stack<vertex*> s;
  s.push(u);
  std::cout<<"Inserted Edges\n";
  while(!s.isEmpty())
  {
    vertex* x;
    s.pop(x);
    s.push(x);
    //std::cout<<x->pos<<"\n";
    vertex* a;
    if(getList(*x).traverse(a))
    {
      if(a->color=='w')
      {
	a->pred=x;
	a->color='g';
	time1++;
	a->distance=time1;
	std::cout<<"("<<x->pos<<","<<a->pos<<")\n";
	s.push(a);
	//break;
      }
    }
    else
    {
      s.pop(x);
      x->color='b';
      time1++;
      x->distance1=time1;
    }
      //std::cout<<"\n";
  }
}
