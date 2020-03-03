#include<iostream>

using namespace std;

void insertionSort(int arr[][2], int size)
{
	int Si,Fi;
	for(int i=1; i<size; i++)
	{
		Si = arr[i][0];
		Fi = arr[i][1];
		for(int j=i-1; j>=0; j--)
		{
			if(arr[j][1]>Fi)
			{
				arr[j+1][0] = arr[j][0];
				arr[j+1][1] = arr[j][1];
				arr[j][0] = Si; 
				arr[j][1] = Fi; 
			}
			else
			{
					arr[j+1][0] = Si;
					arr[j+1][1] = Fi;
					break;
			}
		}
	}
}

int main()
{
    int n,i,value;
	cout<<"Enter the size: ";
    cin>>n;
    int arr[n][2];
    for(i=0;i<n;i++)
    {
        cout<<"Si : ";
	cin>>arr[i][0];
	cout<<"Fi : ";
	cin>>arr[i][1];
	if(arr[i][1]<arr[i][0])
	{
		cout<<"Invalid Input";
		i--;
	}
    }
    

    insertionSort(arr,n);
//	cout<<"Sorted: \n";

//	for(i=0; i<n; i++)
//	{
//		cout<<arr[i][0]<<" "<<arr[i][1]<<endl;
//	}

  

    i=0;

    while(i<n)
    {
        cout<<"Meeting no: "<<i+1<<endl;
        cout<<"Pair "<<arr[i][0]<<", "<<arr[i][1]<<endl;
        value = arr[i][1];
        while(arr[i][0]<value && i<n)
        {
            i++;
        }
    }


    return 0;
}
