#include<iostream>

using namespace std;

void insertionSort(int arr[], int size)
{
	int temp;
	for(int i=1; i<size; i++)
	{
		temp = arr[i];
		for(int j=i-1; j>=0; j--)
		{
			if(arr[j]>temp)
			{
				arr[j+1] = arr[j];
				arr[j] = temp;  
			}
			else
			{
					arr[j+1] = temp;
					break;
			}
		}
	}
}


int main()
{
	int size;
	cout<<"Enter the size: ";
	cin>>size;
	int arr[size];
	cout<<"Enter then values: ";
	for(int i=0; i<size; i++)
	{
		cin>>arr[i];
	}
	insertionSort(arr,size);
	for(int i=0; i<size; i++)
	{
		cout<<arr[i]<<" ";
	}
}
