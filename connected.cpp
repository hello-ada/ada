#include<iostream>
using namespace std;
const int n=5;
int visited[n]={0};
int adjacent[n][n];
void dfs(int v)
{
	cout<<v+1;
	visited[v]=1;
	for(int i=0;i<n;i++)
	{
		if((adjacent[v][i]==1)&&(visited[i]==0))
			dfs(i);
	}
}
int main()
{
	cout<<"Enter the adjacency matrix : (n=5)\n";
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>adjacent[i][j];

	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			dfs(i);
			cout<<"\n";
		}
	}
	return 0;
}