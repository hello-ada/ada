include <iostream>
#include <queue> 
using namespace std; 
char grid[10][10];
int visited[10][10];
int r,c; 
class QItem
{ 
	public: 
		int row; 
		int col; 
		int dist; 
	QItem(int x, int y, int w) : row(x), col(y), dist(w)
}; 
int minDistance(int r, int c) 
{ 
	QItem source(0, 0, 0);
	for (int i=0; i<r; i++)
		for (int j=0; j<c; j++) 
		{ 
			if (grid[i][j] == '0') 
				visited[i][j]=1; 
			else
				visited[i][j]=0; 
			// Finding source 
			if (grid[i][j] == 's') 
			{ 
				source.row = i; 
				source.col = j; 
			} 
		}  

	// applying BFS on matrix cells starting from source 
	queue<QItem> q; 
	q.push(source); 
	visited[source.row][source.col] = true; 
	while (!q.empty())
	{ 
		QItem p = q.front(); 
		q.pop()
		if (grid[p.row][p.col] == 'd') 
			return p.dist; 

		// moving up 
		if (p.row-1>=0 && visited[p.row-1][p.col]==0)
		{ 
			q.push(QItem(p.row-1, p.col, p.dist+1)); 
			visited[p.row-1][p.col] = true; 
		} 

		// moving down 
		if (p.row+1<r && visited[p.row+1][p.col]==0)
		{ 
			q.push(QItem(p.row+1, p.col, p.dist+1)); 
			visited[p.row+1][p.col] = true; 
		} 

		// moving left 
		if (p.col-1>=0 && visited[p.row][p.col-1]==0)
		{ 
			q.push(QItem(p.row, p.col-1, p.dist+1)); 
			visited[p.row][p.col-1] = true; 
		} 

		// moving right 
		if (p.col+1<c && visited[p.row][p.col+1]==0)
		{ 
			q.push(QItem(p.row, p.col+1, p.dist+1)); 
			visited[p.row][p.col+1] = true; 
		} 
	} 
	return -1; 
} 
int main() 
{ 
	cout<<"Enter number of rows :";
	cin>>r;
	cout<<"Enter number of columns :";
	cin>>c;
	cout<<"Enter grid :\n";
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			cin>>grid[i][j];
	cout << "Min distance : "<<minDis(r,c)<<endl; 
	return 0; 
}