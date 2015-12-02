#include"bfs.h"
using namespace std;
#include<fstream>
#include<cstring>

int numLine(char a[])
{
  char comm[70]="wc -l ";
  strcat(comm,a);
  char endcomm[]=" > temp.txt";
  strcat(comm,endcomm);
  system(comm);
  ifstream infile;
  infile.open("temp.txt");
  int line;
  infile>>line;
  infile.close();
  return line;
}

int main(int argc, char*argv[])
{
  ifstream inFile;
  if(argc!=2)
  {
    cout<<"Enter proper file input\n";
    return 0;
  }
  inFile.open(argv[1]);
  int n=numLine(argv[1]);
  graph g;
  g.setVertices(n);
  int temp,i,j;
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
    {
      inFile>>temp;
      if(temp==1)
	g.insertEdge(i,j);
    }
  }
  g.Display();
  if(g.ifSymmetric())
  {
    cout<<"\nGraph is symmetric\n";
    char temp;
    cout<<"Enter b for BFS search, d for DFS search\n";
    cin>>temp;
    if(temp=='b')
      g.bfs();
    else if(temp=='d')
      g.dfs();
  }
  else
  {
    cout<<"\nGraph is directed\n";
    g.dfs();
  }
  return 0;
}
