#include<iostream>
#include<process.h>

using namespace std;
	
void input(bool matrix[][10], int n, int array[])
{
	for(int i=0; i<n; i++)
	{
		char out = 65+i;
		cout<<"Is "<<out<<" Connected with : \n";
		for(int j=0; j<n; j++)
		{
			char in = 65 +j;
			cout<<in<<": ";
			bool a;
			cin>>a;
			if(a)
			array[j]++;
			matrix[i][j] = a;
		}
	}
}

bool check(bool matrix[][10], int n)
{
	for(int i=0; i<n;i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(matrix[i][j] != matrix[j][i])
			return true;
		}
	}
	return false;
}

bool dfs(bool matrix[][10], int n, int stack[],int *top, short int flag[])
{
	if(*top==-1)
	return false;
//	cout<<"\t3"<<endl;
	bool ans = false;
	for(int i=0; i<n; i++)
	{
		if(matrix[stack[*top]][i])
		{
		//	cout<<i;
			if(flag[i]==0)
			{
			//	cout<<"+";
				return true;
			}
			else if(flag[i]==-1)
			{
			//	cout<<"-";
				flag[i] = 0;
				*top = *top+1;
				stack[*top] = i;
			//	cout<<"Stack";
			//	for(int i=0; i<=*top; i++)
			//	cout<<"\t"<<stack[i];
				ans = ans | dfs(matrix,n,stack,top,flag);
			}
		}
	}
	flag[stack[*top]] = 1;
	*top=*top-1;
	if(*top==-1)
	return false;
	return ans;
	
}

//Check for cycles in a Directed Graph

bool DFS(bool matrix[][10], int n)  
{
//	cout<<"1"<<endl;
	int stack[n];
	short int flag[n];
	int top = 0;
	for(int i=1; i<n; i++)
		flag[i] = -1;
		
	flag[0] = 0;
	stack[0] = 0;
	
//	cout<<"2"<<endl;
	return dfs(matrix,n,stack,&top,flag);
	
}

void topological(bool matrix[][10], int n, int indeg[])
{
	int count;
	char out;
	while(1)
	{
		count=0;
		for(int i=0; i<n; i++)
		{
			if(indeg[i]==-1)
			count++;
			else if(indeg[i]==0)
			{
				out = 65+i;
				cout<<out<<"\t";				
				indeg[i]=-1;
				for(int j=0; j<n; j++)
				{
					if(matrix[i][j])
					{
						indeg[j]--;
					}
				}
				break;
			}
		}
		if(count==n)
		return;
	}
	
}

int main()
{
	while(1) 
	{
		cout<<"\nEnter the size: ";
		int n;
		cin>>n;
		cout<<"Enter the directed graph: \n";
		bool matrix[n][10];
		int indegree[n];
		for(int i=0; i<n; i++)
			indegree[i]=0;
		input(matrix,n,indegree);
		if(!check(matrix,n))
		{
			cout<<"Undirected Graph";
			continue;
		}	
		if(DFS(matrix,n))
		{
			cout<<"Cycles Exist";
			continue;
		}
		cout<<"Topological Ordering: ";
		topological(matrix,n,indegree);		
		break;
	}
}
