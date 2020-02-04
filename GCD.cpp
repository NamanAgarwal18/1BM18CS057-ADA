#include<iostream.h>
#include<stdio.h>
#include<algorithm.h>

using namespace std;

int euclid(int m, int n)
{
	int rem;
	while(n!=0)
	{
		rem = m%n;
		m = n;
		n = rem;
	}
	return m;
}


int rep(int m, int n)
{
	while(m!=n)
	{
		if(m>n)
			m = m-n;
		else
			n = n-m;
	}
	return n;
}

int consicutive(int m, int n)
{
	int small = std::min(m,n);
	while(n%small!=0 && m%small!=0)
		small = small-1;
	return small;
}

int main()
{
	cout<<"Enter the two numbers";
	int a,b;
	cin>>a>>b;
	cout<<euclid(a,b)<<endl;
	cout<<euclid(b,a)<<endl;
	cout<<rep(a,b)<<endl;
	cout<<rep(b,a)<<endl;
	cout<<consicutive(a,b)<<endl;
	cout<<consicutive(b,a)<<endl;
}
