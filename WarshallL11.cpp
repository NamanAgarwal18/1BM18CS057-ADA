#include<iostream>
#include<process.h>

using namespace std;
	
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


void warshall(bool matrix[][10], int n)
{
	for(int k=0; k<n; k++)
	{
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				matrix[i][j] = matrix[i][j] | (matrix[i][k] & matrix[k][j]);
			}
		}
	}
}

void display(bool matrix[][10], int n)
{
	system("cls");
	char out;
	for(int j=0; j<n; j++)
	{
			out = 65+j;
			cout<<"    "<<out<<"    ";
	}
	cout<<endl<<"\t ";
	for(int j=0; j<n; j++)
	{
		cout<<"---------";
	}
	cout<<endl;
	for(int i =0; i<n; i++)
	{
		out = 65+i;
		cout<<"    "<<out<<"    ";
		for(int j=0; j<n; j++)
		{
			cout<<"|  ";
				cout<<" "<<matrix[i][j]<<" ";
			cout<<"  |";
		}
		cout<<endl<<"\t ";
		for(int j=0; j<n;j++)
		{
			cout<<"---------";
		}
		cout<<endl;
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
	warshall(matrix,n);
	display(matrix,n);

}


