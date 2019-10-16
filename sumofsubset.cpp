#include <iostream>
using namespace std;
void  FindSubsets(int *arr, int d, int *x, int currsum, int k, int rtotal){
	x[k] = 1; //include the kth element, this is left child in state space tree
	if(currsum + arr[k] == d)
	{	//subset found
		for(int i=0;i<=k;i++)
			if(x[i]==1) cout<<arr[i]<<" ";
		cout<<endl;
		return;
	}
	else if(currsum+arr[k]+arr[k+1]<=d)
		 FindSubsets(arr,d,x,currsum+arr[k],k+1,rtotal-arr[k]);
	
	if((currsum+rtotal-arr[k]>=d)&&(currsum+arr[k+1]<=d)){
		//don't include kth element, this is right child in state space tree
		x[k]=0;
		FindSubsets(arr,d,x,currsum,k+1,rtotal-arr[k]);
	}
}
int main(){
	int n, *arr, *x, d, total;
	cout<<"Enter the no of elements :";
	cin>>n;
	arr = new int[n];
	x = new int[n];
	cout<<"Enter the elements :\n";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		total+=arr[i];
	}
	cout<<"Enter the required sum :";
	cin>>d;
	FindSubsets(arr,d,x, 0, 0, sum);
	return 0;
}
