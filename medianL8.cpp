#include<iostream>

using namespace std;

void output(int arr[], int n)
{
	for(int i=0; i<n; i++)
	cout<<arr[i]<<"  ";
	cout<<endl;
}


float median(int arr[], int n )
{
	return ((arr[n/2] + arr[(n-1)/2])/2 );
}

float medianrecur(int arr1[], int arr2[], int n)
{
	output(arr1,n);
	output(arr2,n);
	if(n==1)
	return (arr1[0] + arr2[0])/2;
	else if(n==2)
	{
		return ((max(arr1[0],arr2[0]) + min(arr1[1],arr2[1])) / 2);
	}
	
	int med1 = median(arr1,n), med2=median(arr2,n);
	
	if(med1==med2)
		return med1;
	else if(med1<med2)
	{
		return medianrecur((arr1 + (n-1)/2),arr2, (n+1)/2 );
	}
	else
	return medianrecur((arr2 + (n-1)/2),arr1,(n+1)/2);
}

void input(int arr[], int n)
{
	for(int i=0; i<n; i++)
	cin>>arr[i];
}


void bubble(int arr[], int n)
{
	bool tag  = false;
	for(int i=0; i<n; i++)
	{
		for(int j=1; j<n-i; j++)
		{
			if(arr[j-1] > arr[j])
			{
				tag = true;
				arr[j] = arr[j] + arr[j-1];
				arr[j-1] = arr[j] - arr[j-1];
				arr[j] = arr[j] - arr[j-1];
			}
		}
		if(!tag)
		return;
		tag = false;
	}
}
int main()
{
	cout<<"Enter the size: ";
	int n;
	cin>>n;
	int arr1[n], arr2[n];
	cout<<"Enter the first array: ";
	input(arr1,n);
	bubble(arr1,n);
	
	cout<<endl;
	cout<<"Enter the second array: ";
	input(arr2,n);
	
	bubble(arr2,n);
	
	cout<<endl;
	cout<<"Answer is: "<<medianrecur(arr1,arr2,n);
}
