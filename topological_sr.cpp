#include<iostream>
using namespace std;
const int n=4;
int indegree[n];
int a[n][n]={0};
void T_O()
{
	for(int i=0;i<n;i++)
	{
		indegree[i]=0;
		for(int j=0;j<n;j++)
			indegree[i] += a[j][i];
	}
	for(int j=0;j<n;j++)
		if(indegree[j]==0)
		{
			indegree[j]=-1;
			cout<<j+1;
			for(int k=0;k<n;k++)
			{
				if(a[j][k]==1)
				indegree[k]=indegree[k]-1;
			}
		}
}
int main()
{
	cout<<"\nEnter the adjacency matrix : \n";
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	T_O();
	return 0;
}
