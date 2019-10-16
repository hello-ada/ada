#include<iostream>
using namespace std;
int partition(int a[],int low,int high)
{
	int pivot=a[low];
	int i=low+1;
	int j=high;
	while(1)
	{
		while(i<=high && a[i]<=pivot){i=i+1;}
		while(j>=low && a[j]>pivot){j=j-1;}
		if(i<j)
			swap(a[i],a[j]);
		else
		{
			swap(a[j],a[low]);
			return j;
		}
	}
}
void quicksort(int a[],int low,int high)
{
	if(high<low)
		return;
	int pivot_pos = partition(a,low,high);
	quicksort(a,low,pivot_pos-1);
	quicksort(a,pivot_pos+1,high);
}
int main()
{
	int n,s,e,k;
	cout<<"Enter the no of element : ";
	cin>>n;
	int a[n]; 
	cout<<"\nEnter the elements of the array\n";
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<endl;
	cout<<"Enter the starting point : ";
	cin>>s;
	cout<<"Enter the end point : ";
	cin>>e;
	cout<<"Enter the value of k : ";
	cin>>k;
	quicksort(a,s-1,e-1);
	cout<<"\nKth smallest element : "<<a[s+k-2];
	return 0;
}
