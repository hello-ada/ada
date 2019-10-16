#include<iostream>
using namespace std;
const int n=5;	//col
const int m=3;	//row
int matrix[m][n]={0};
int visited[m][n]={0};
bool issafe(int r,int c)
{
	if((c>=0)&&(c<n)&&(r>=0)&&(r<m)&&matrix[r][c]&&!visited[r][c])
		return true;
	else
		return false;
}
void dfs(int r,int c)
{
	static int rownbr[]={-1,-1,-1,0,0,1,1,1};
	static int colnbr[]={-1,0,1,-1,1,-1,0,1};
	visited[r][c]=1;
	for(int k=0;k<8;k++) 
		if(issafe(r+rownbr[k],c+colnbr[k]))
			dfs(r+rownbr[k],c+colnbr[k]);
}
int main()
{
	int count=0;
	cout<<"Enter the matrix : \n";
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>matrix[i][j];
	
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if (matrix[i][j]==1 && visited[i][j]==0)
			{
				dfs(i,j);
				++count;
			}
	cout<<"No of Island : "<<count<<endl;
	return 0;
}