#include"vertex.h"
#include"Linear_lists.h"

//Disjoint Set with rooted tree representation

//template<class Type>
class rooted_tree_node{
  friend class rooted_tree;
 private:
  vertex* data;
  int height;
  rooted_tree_node* parent;
 public:
  rooted_tree_node();
};

rooted_tree_node::rooted_tree_node()
{
  height=0;
  parent=this;
}

class rooted_tree{
 private:
  int n;
  LinearList<rooted_tree_node> disjoint_set;
 public:
  rooted_tree(int );
  void make_set(vertex* );
  rooted_tree_node* find_set(vertex* );
  void Union(vertex* , vertex* );
};

rooted_tree::rooted_tree(int size)
{
  n=size;
  disjoint_set.allocate_size(n);
}

void rooted_tree::make_set(vertex* v)
{
  disjoint_set.returnListElement(v->getPos()).data=v;
}

rooted_tree_node* rooted_tree::find_set(vertex* x)
{
  rooted_tree_node* y=&disjoint_set.returnListElement(x->getPos());
  while(y->parent!=y)
  {
    y=y->parent;
  }
  return y;
}

void rooted_tree::Union(vertex* u, vertex* v)
{
  rooted_tree_node* x=&disjoint_set.returnListElement(u->getPos());
  rooted_tree_node* y=&disjoint_set.returnListElement(v->getPos());
  if(x->height>y->height)
  {
    y->parent=x;
  }
  else if(x->height<y->height)
  {
    x->parent=y;
  }
  else
  {
    x->parent=y;
    y->height++;
  }
}
