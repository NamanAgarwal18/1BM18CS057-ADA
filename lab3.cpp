#include<iostream>

using namespace std;

int search(int size, int arr[], int key)
{
	int front = 0, end = size-1, mid;
	while(front<=end)
	{
		mid = (front+end)/2;
		
		if(arr[mid]==key)
			return mid;
		else if(arr[mid]>key)
		{
				if(key < arr[front])
			{
				front = mid  +1;
			}
			else if(key > arr[front])
			{
				end = mid -1;
			}
			else 
				return front;
		}	
		else
		{
			if(key > arr[end])
			{
				end  = mid-1;
			}
			else if(key < arr[end])
			{
				front = mid +1;
			}
			else
				return end;
		
		}
	}
	return -1;
}

int main()
{
	int n;
	cout<<"Enter the size of array: ";
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++)
	cin>>arr[i];
	cout<<"Enter the element to be searched: ";
	int key;
	cin>>key;
	cout<<"The Answer is : "<<(search(n,arr,key)+1);
}
