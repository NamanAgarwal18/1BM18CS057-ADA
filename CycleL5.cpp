#include<iostream>

using namespace std;

bool cycles = false;
//Undirected graph cycle

void dfs(bool matrix[][10], int n, int i, bool arr[])
	{
		char out = (65+i);
		cout<<out<<"\t";
   
		arr[i] = true;
		for(int j =0; j<n; j++)
		{
			if(matrix[i][j])
			{
				if(!arr[j])
				{
					dfs(matrix,n,j,arr); 
				}
				else
				{
					cycles = true;
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
	cout<<"Enter the directed graph: ";
	bool matrix[n][10];
	input(matrix,n);
	DFS(matrix,n);
	cout<<endl;
	if(cycles)
	cout<<"Cycles exist\n";

}
