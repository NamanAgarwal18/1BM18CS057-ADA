#include<iostream>

using namespace std;

void mergesort(int arr[], int temp[], int start, int end)
{
	if(start>=end)
	{
		return;
	}
		int mid = (start + end )/2;
		mergesort(arr,temp,start,mid);
		mergesort(arr,temp,mid+1,end);
	int i=start, j=mid+1;	
	int index = start;
	while(i<=mid && j <=end)
	{
		if(arr[i] <= arr[j])
		{
			temp[index] = arr[i];
			i++;
		}
		else
		{
			temp[index] = arr[j];
			j++;
		}
		index++;
	}
	if(i<=mid)
	{
		while(i<=mid)
		{
			temp[index] = arr[i];
			i++;
			index++;	
		}
	}
	else 
	{
		while(j<=end)
		{
			temp[index] = arr[j];
			j++;
			index++;
		}
	}
	for(i = start; i<=end; i++)
	{
		arr[i] = temp[i];
	}
}

void merge(int arr[], int n)
{
	int temp[n];
	mergesort(arr,temp,0,n-1);
}



int main()
{
	int n;
	cout<<"Enter the size: ";
	cin>>n;
	int arr[n];
	cout<<"Enter the elements: ";
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	merge(arr,n);
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<"   ";
	}
}
