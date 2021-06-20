//check if two vertices of graph has a path between them ,this is very usefull
//let us we design a road system where we have a set of nodes as cities and edges as roads connecting these cities ,we can check whether we can gp from A city to B city 
//by road or not

#include<bits/stdc++.h>
using namespace std;
unordered_set<int> visited;

bool haspath(int**graph,int n,int src,int dest)
{   visited.insert(src);
    //first marking the current node as visited so we dont visit it again  
    if(src==dest)
    {
    	return true;
    }
    // if current node or src has an edge connecting to destination just return true 
	if(graph[src][dest]==1)
	  {
	  	return true;
	  }
       //if at above check no direct edge found just check on the adjacent vertices of source whether they are connected to destination or not
	 for(int i=0;i<n;i++)
	 {
	 	if(visited.find(i)==visited.end() and graph[src][i]==1)
	 	{
			//calling on child vertices or adjacent vertices
	 		return haspath(graph,n,i,dest);
	 	}
	 	
	 }
       //atlast return false means we dont have any path between the given src and dest,so we need to return false
	 return false;
}


int main()
{
	int n;
	cin>>n;
	int e;
	cin>>e;
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
	int ct=0;
     
    int source,dest;
    cin>>source>>dest;
    
    if(haspath(graph,n,source,dest))
    {
    	cout<<"path Exists";
    }
    else
    {
    	cout<<"no path exists b/w these";
    }
	
}
