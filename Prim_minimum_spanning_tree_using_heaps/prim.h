#ifndef _PRIM_INCLUDED_H
#define _PRIM_INCLUDED_H

#include"graph.h"
#include"heap.h"

#define inf 50000

class heap_node{
  friend class graph;
  friend class heap<heap_node>;
 private:
  vertex* v;
  int key;
  vertex* parent;
 public:
  int getKey();
  void setKey(int );
};

int heap_node::getKey()
{
  return key;
}

int heap_nodeComp(heap_node a, heap_node b)
{
  if(a.getKey()>b.getKey())
    return 1;
  else if(a.getKey()<b.getKey())
    return -1;
  else
    return 0;
}


void graph::mst_prim()
{
  int i=0;
  int s[n];
  heap<heap_node> h(n);
  heap_node x;
  heap_node* hp[n];
  /*for(i=0;i<n;i++)
  {
    vertex* a=&v.returnListElement(i+1);
    heap_node* b=new heap_node[1];
    s[i]=0;
    x.v=a;
    x.key=inf;
    x.parent=NULL;
    //hp[i]=b;
    h.insert(x,heap_nodeComp);
  }*/
  for(i=0;i<n;i++)
  {
    vertex* a=&v.returnListElement(i+1);
    heap_node* b=new heap_node[1];
    s[i]=0;
    b->v=a;
    b->key=inf;
    b->parent=NULL;
    hp[i]=b;
    h.insert(*b,heap_nodeComp);
  }
  vertex* r=&v.returnListElement(1);
  x.v=r;
  h.decrease_key(x,0,heap_nodeComp);
  heap_node b;
  while(!h.isEmpty())
  {
    b=h.delete_min(heap_nodeComp);
    if(b.parent!=NULL)
    {
      cout<<b.parent->pos<<" "<<b.v->pos<<" ";
      cout<<b.key<<"\n";
    }
    //cout<<b.v->pos<<" "<<b.key<<"\n";
    s[b.v->pos]=1;
    weighted_node c;
    while(getList(*(b.v)).traverse(c))
    {
      //if(c.next->pos==9)
      //cout<<b.v->pos;
      if(s[c.next->pos]==0)
      {
	int j=h.search(c.next->pos);
	
	//cout<<c.next->pos<<" "<<j<<" "<<h.data.returnListElement(j).v->pos<<" ";

	if(h.data.returnListElement(j).key>c.weight)
	{
	  h.data.returnListElement(j).key=c.weight;
	  h.data.returnListElement(j).parent=b.v;
	  //cout<<h.data.returnListElement(j).v->pos<<h.data.returnListElement(j).key<<" ";
	  h.decrease_key(h.data.returnListElement(j),j-1,heap_nodeComp);
	}
	//cout<<"\n";
      }
    }
  }
}

#endif
