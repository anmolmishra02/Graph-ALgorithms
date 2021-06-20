//Bfs for graph having more than 1 connected component 
//A connected component is basically a graph in which there is a path between every two nodes whether its direct or indirect ,but there is a path
//A path is basically set of edges which are used to go from one vertex to another vertex ,can be single or multiple

#include<bits/stdc++.h>
using namespace std;
unordered_set<int> visited;
void bfs(int**graph,int n,int curr)
{
	queue<int> pq;
	pq.push(curr);
	visited.insert(curr);
	while(!pq.empty())
	{
		int top=pq.front();
		pq.pop();
		cout<<top<<"-";
		for(int i=0;i<n;i++)
		{
			if((visited.find(i)==visited.end())and graph[top][i]==1)
			{
				pq.push(i);
				visited.insert(i);
			}
			
		}
	}
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
	for(int i=0;i<n;i++)
	{
		if(visited.find(i)==visited.end())
		{   cout<<"component "<<ct<<endl;
			bfs(graph,n,i);
			cout<<endl;
			ct++;
		}
	}
	
}
