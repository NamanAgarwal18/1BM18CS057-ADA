#include<iostream>

using namespace std;


void output(int arr[], int n)
{
	for(int i=0; i<n; i++)
	cout<<arr[i]<<"  ";
	cout<<endl;
}

void input(int arr[], int n)
{
	for(int i=0; i<n; i++)
	cin>>arr[i];
}

void quicksort(int arr[], int n)
{
	if(n <= 1)
	return;
	int start = 1;
	int end = n-1;
	int temp;
	while(start<=end)
	{
		if(arr[0]>=arr[start])
		{
			start++;
		}
		else
		{
			if(arr[end]<=arr[0])
			{
				temp = arr[end];
				arr[end] = arr[start];
				arr[start] = temp;
				start++;
			}
			else
				end--;
		}
	}
//	end--;
	temp = arr[end];
	arr[end] = arr[0];
	arr[0] = temp;
	quicksort(arr, end);
	quicksort(arr+end+1, n - end-1);
}


int main()
{
	cout<<"Enter the size: ";
	int n;
	cin>>n;
	int arr[n];
	input(arr,n);
	quicksort(arr,n);
	output(arr,n);
}
