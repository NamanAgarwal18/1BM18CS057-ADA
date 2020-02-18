#include<iostream>

using namespace std;

int binary(int front, int end, int arr[],int key)
{
	if(front>end)
	return-1;
	int	mid = (front + end)/2;
	
	if(arr[mid] > key )
	{
		return binary(front,(mid-1),arr,key);
	}
	else if(arr[mid] < key)
		return binary((mid+1),end,arr,key);
	else 
		return mid;
}


int linear(int size,int arr[],int key)
{
	for(int i =0; i<size; i++)
	{
		if(key == arr[i])
		return i;
	}
	return -1;
}


int main()
{
	int size;
	cout<<"Enter the size: ";
	cin>>size;
	int *arr = new int[size];
	cout<<"Enter the key: ";
	int key;
	cin>>key;
	for(int i =0; i<size; i++)
	cin>>arr[i];
	cout<<"Binary: "<<(1+binary(0,(size-1),arr,key));
	cout<<"\nLinear: "<<(1+linear(size,arr,key));
}

