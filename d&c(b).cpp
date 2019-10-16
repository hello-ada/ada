#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;					//no of element
	int a[n];
	int k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];			//input to array
	}
	cin>>k;					//key to be searched
	int beg=0,end=n-1;
	int count=0,i,j;
	while(beg<=end)
	{
		int mid=(beg+end)/2;
		if(a[mid]==k)
		{
			i=mid;
			j=mid;
			while(a[i--]==k)
				count++;
			while(a[j++]==k)
				count++;
			break;
		}
		else if(a[mid]<k)
			beg=mid+1;
		else
			end=mid-1;
	}
	if(count==0)
		cout<<"-1 -1 0"<<endl;
	else
		cout<<i+2<<" "<<j-2<<" "<<count-1<<endl;
	return 0;
}