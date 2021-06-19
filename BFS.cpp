//bfs traversal is similar to level order traversal in trees , that means we first explore all nodes that are at same distance from the parent node or start node without going 
//further to next level , we need a queue to store current level vertices and a visited set to remember all visited nodes or vertex


#include<bits/stdc++.h>
using namespace std;


//visited set
unordered_set<int> visited;
void bfs(int**graph,int n,int start)
{
	queue<int> pq;
	pq.push(start);
  //first insert the initial or start vertex in queue and mark it as visited
	visited.insert(start);
	while(!pq.empty())
	{
    //keep exploring and popping queue untill all nodes becomes visited
    //take the top element from queue,print it and just push down all its adjacent vertices which are not yet visited and mark them as visited
		int top=pq.front();
		pq.pop();
		cout<<top<<endl;
		for(int i=0;i<n;i++)
		{
			if(i==top)
			  continue;
			  
			if(visited.find(i)==visited.end())
			{
			   if(graph[top][i]==1)
			  {
				visited.insert(i);
				pq.push(i);
			  }
			}
		}
	}
}

int main()
{
	int n,e;
	cin>>n>>e;
  //adjaceny matrix - 2d dynamic array, each index in this array stores another 1 d array pointer
	int**graph=new int*[n];
	for(int i=0;i<n;i++)
	{
		graph[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			graph[i][j]=0;
		}
	}
	for(int i=0;i<e;i++)
	{
		int f,s;
		cin>>f>>s;
		graph[f][s]=1;
		graph[s][f]=1;
	}
	bfs(graph,n,2);
}
