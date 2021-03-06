/*#include"graph.h"
#include"Linear_lists.h"
#include<algorithm>
#include"disjoint_set.h"
#include"edge.h"

int partition(LinearList<edge>* a,int p,int r)
{
  int i,j;
  edge temp,pivot;
  pivot=a->returnListElement(r+1);
  i=p-1;
  j=r+1;
  while(1)
  {
    do
    {
      j--;
    }while(edgeComp(pivot,a->returnListElement(j+1)));
    do
    {
      i++;
    }while(edgeComp(a->returnListElement(i+1),pivot));
    
    if(i<j)
    {
      temp=a->returnListElement(i+1);
      a->returnListElement(i+1)=a->returnListElement(j+1);
      a->returnListElement(j+1)=temp;
    }
    else
      return (i-1);
  }
}

void Partsort(LinearList<edge>* a,int p,int r)
{
  int i,q;
  if(p<r)
  {
    q=partition(a,p,r);
    Partsort(a,p,q);
    Partsort(a,q+1,r);
  }
}

void graph::mst_kruskal()
{
  LinearList<edge> edge_list(m);
  int i,j;
  for(i=0;i<n;i++)
  {
    vertex a=v.returnListElement(i+1);
    weighted_node b;
    while(getList(a).traverse(b))
    {
      if(b.next->pos<a.pos)
      {
	edge temp(&a,b.next,b.weight);
	std::cout<<a.pos<<" "<<b->pos<<" "<<weight<<"\n";
	edge_list.insert(edge_list.length()+1,temp);
      }
    }
  }/*
  //sort edges
  //Partsort(&edge_list,0,n-1);
  rooted_tree set(n);
  for(i=0;i<n;i++)
  {
    set.make_set(&v.returnListElement(i+1));
  }
  for(i=0;i<m;i++)
  {
    edge* temp=&edge_list.returnListElement(i+1);
    if(set.find_set(temp->vertex1)!=set.find_set(temp->vertex2))
    {
      std::cout<<temp->vertex1->pos<<" "<<temp->vertex2->pos<<"\n";
      set.Union(temp->vertex1,temp->vertex2);
    }
    }
  //make-set 


}*/
#include"graph.h"
#include"Linear_lists.h"
#include<algorithm>
#include"disjoint_set.h"
#include"edge.h"
  /*
int partition(int *a,int p,int r)
{
 int i,j,temp,pivot;
 pivot=a[r];
 i=p-1;
 j=r+1;
 while(1)
 {
  do
  {
   j--;
  }while(a[j]>pivot);
  do
  {
   i++;
  }while(a[i]<pivot);
  
  if(i<j)
  {
   temp=a[i];
   a[i]=a[j];
   a[j]=temp;
  }
  else
   return (i-1);
 }
}

void Partsort(int* a,int p,int r)
{
 int i,q;
 if(p<r)
 {
  q=partition(a,p,r);
  Partsort(a,p,q);
  Partsort(a,q+1,r);
 }
}*/
void graph::mst_kruskal()
{
  edge edge_list[m];
  int i,j,k=0;
  for(i=0;i<n;i++)
  {
    vertex* a=&v.returnListElement(i+1);
    weighted_node b;
    while(getList(*a).traverse(b))
    {
      if(b.next->pos<a->pos)
      {
       	edge temp(a,b.next,b.weight);
	//std::cout<<a.pos<<" "<<b.next->pos<<"\n";
       	edge_list[k]=temp;
	std::cout<<"("<<edge_list[k].vertex1->pos<<","<<edge_list[k].vertex2->pos<<","<<edge_list[k].weight<<")"<<"\n";
	k++;
	//std::cout<<k<<"\n";
      }
    }
    //std::cout<<edge_list[0].vertex1->pos<<" "<<edge_list[0].vertex2->pos<<"\n";
  }
  //std::cout<<(edge_list[0].vertex1)->pos;
  std::sort(edge_list,edge_list+k,edgeComp);
  rooted_tree set(n);
  for(i=0;i<n;i++)
  {
    set.make_set(&v.returnListElement(i+1));
  }
  std::cout<<"Kruskal Minimum Spanning Tree\n";
  for(j=0;j<k;j++)
  {
    edge temp=edge_list[j];
    //std::cout<<edge_list[j].vertex1->pos<<" "<<edge_list[j].vertex2->pos<<"\n";
    
    if(set.find_set(edge_list[j].vertex1)!=set.find_set(edge_list[j].vertex2))
    {
      std::cout<<"("<<temp.vertex1->pos<<","<<temp.vertex2->pos<<","<<temp.weight<<")"<<"\n";
      set.Union(temp.vertex1,temp.vertex2);
    }
  }

  /*
  */
  //make-set //sort(edge_list,edge_list+m,edgeComp);
  //*/

}
