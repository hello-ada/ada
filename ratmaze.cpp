#include <iostream>
using namespace std;
int N, maze[10][10],solution[10][10];
void ratMaze(int x,int y)
{
	if(x==N-1 && y==N-1)
	{
		solution[x][y] = 1;
		for(int i=0; i<N;i++)
		{
			cout<<endl;
			for(int j=0; j<N; j++)
				cout<<solution[i][j]<<" ";
		}
		return;
	}
	if(x<0 || x>N-1 || y<0 || y>N-1 || maze[x][y]==0 || solution[x][y]==1) 
		return;
	solution[x][y]=1;
	ratMaze(x,y+1); //right
	ratMaze(x+1,y); //down
	solution[x][y]=0;
}
int main()
{
	cout<<"Enter size of matrix :";
	cin>>N;
	cout<<"Enter maze :\n";
	for(int i=0; i<N; i++)
		for(int j=0;j<N;j++)
			cin>>maze[i][j];
	ratMaze(0,0);
	return 0;
}
