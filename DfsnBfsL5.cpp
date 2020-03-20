#include<iostream>

using namespace std;

int count =0;
bool cycles = false;

void dfs(bool matrix[][10], int n, int i, bool arr[])
	{
		char out = (65+i);
		cout<<out<<"\t";
    	count++;
		arr[i] = true;
		for(int j =0; j<n; j++)
		{
			if(matrix[i][j])
			{
				if(!arr[j])
				{
					dfs(matrix,n,j,arr); 
				}
			}
			
		}
	}

void DFS(bool matrix[][10], int n)
{
	bool arr[n];
	for(int i=0; i<n; i++)
		arr[i]= false;
	cout<<"Enter the start node for DFS: ";
	int start;
	cin>>start;
	
	dfs(matrix,n,start,arr);
	if(count!=n)
	{
		cout<<"\nNon Connected";
	}
	else 
	cout<<"\nConnected";
}

void BFS(bool matrix[][10], int n)
{
	int queue[n];
	int start, end = 0;
	cout<<"Enter the start node for BFS: ";
	cin>>start;
	queue[0]=start;
	start= 0;
	while(start<=end)
	{
		for(int j=0; j<n; j++)
		{
			if(matrix[queue[start]][j])
			{
				bool counter = false;
				for(int k=0; k<=end ; k++)
				{
					if(queue[k] == j)
					{
						counter = true;
						break;
					}
				}
				if(!counter)
				{
					end++;
					queue[end] = j;
				}
			}
		}
		char out = (65 + queue[start]);
		start++;
		cout<<out<<"\t";
	}
	char out;
	for(int j=start; j<=end; j++)
	{
		out =65 +queue[j];
		cout<<out<<"\t";
	}
}

void input(bool matrix[][10], int n)
{
	for(int i=0; i<n; i++)
	{
		char out = 65+i;
		cout<<"Is "<<out<<" Connected with : \n";
		for(int j=0; j<n; j++)
		{
			char in = 65 +j;
			cout<<in<<": ";
			int a;
			cin>>a;
			matrix[i][j] = a;
		}
	}
}

int main()
{
	cout<<"Enter the size: ";
	int n;
	cin>>n;
	cout<<"Enter the array: ";
	bool matrix[n][10];
	input(matrix,n);
	DFS(matrix,n);
	cout<<endl;
	if(cycles)
	cout<<"Cycles exist\n";
	BFS(matrix,n);
}
