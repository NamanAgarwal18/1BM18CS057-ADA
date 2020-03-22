#include<iostream>
#include<string.h>

using namespace std;

int edits(string s1, string s2)
{
	int a = s1.length();
	int b = s2.length();
	int arr[a+1][b+1];
	int min;
	for(int i=0; i<a+1; i++)
	{
		for(int j=0; j<b+1; j++)
		{
			if(i==0)
			arr[0][j] = j;
			else if(j==0)
			arr[i][0] = i;
			else if(s1[i-1] == s2[j-1])
			arr[i][j] = arr[i-1][j-1];
			else
			{
				min = arr[i][j-1];
				if(arr[i-1][j-1]<min)
				min = arr[i-1][j-1];
				if(arr[i-1][j]<min)
				min = arr[i-1][j];
				arr[i][j] = 1 + min;
			}
			
		}
	}
	return arr[a][b];	
}

int main()
{
	cout<<"Enter the two strings: ";
	string s1,s2;
	cin>>s1>>s2;
	cout<<"Min edits: "<<edits(s1,s2);
}
