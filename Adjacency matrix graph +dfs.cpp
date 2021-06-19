//dfs means go and just keep exploring current path untill its a dead end or you cant go further 
//if that happens just come back and explore other path which is yet unexplored


#include<bits/stdc++.h>
using namespace std;
//maintaining a visited set so as if any vertex is visited we do not traverse it another time
unordered_set<int> visited;

//dfs print function
void print(int**graph,int n,int start)
{
	cout<<start<<endl;
  //first printing the current node  and then checking all other nodes which are adjacent to it 
	visited.insert(start);
  //pushing it into visited set as soon as it is traversed
	for(int i=0;i<n;i++)
	{
		if(start==i)
		   continue;
		if(graph[start][i]==1)
		{
		if(visited.find(i)!=visited.end())
		{
    //means we already traversed this vertex before
			continue;
		}
    //havent traversed yet so need to go further and explore this vertex
			print(graph,n,i);
		}
	}
	
}
int main()
{
	int n;
  //no of vertices
	cin>>n;
	int e;
  //no of edges
	cin>>e;
  //adjacency matrix 
	int**graph=new int*[n];
	for(int i=0;i<n;i++)
	{
		graph[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			graph[i][j]=0;
		}
	}
  //taking input of edges
	for(int i=0;i<e;i++)
	{
		int f,s;
		cin>>f>>s;
		graph[f][s]=1;
		graph[s][f]=1;
	}
	print(graph,n,2);
	
}
