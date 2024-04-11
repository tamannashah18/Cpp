#include<iostream>
using namespace std;
void input(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"enter element";
		cin>>a[i];
	}
}
void output(int a[],int n)
{
	cout<<"\n THE ARRAY \n";
	for(int i=0;i<n;i++)
		{
			cout<<a[i]<<"\t";
		}
}
void bubble_sort(int a[],int n)
{
	int temp,i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	cout<<"\n THE SORTED ARRAY \n";

	for(i=0;i<n;i++)
		{
			cout<<a[i]<<"\t";
		}
}
int main()
{
	int ch=0,n;
	cout<<"ENTER NUMBER OF ARRAY ELEMENTS";
	cin>>n;
	int a[n];
	while(ch!=6)
	{
		cout<<"\nENTER 1 to input values"<<endl;
		cout<<"ENTER 2 to display values"<<endl;
		cout<<"ENTER 3 to sort values by bubble sort"<<endl;
		cout<<"ENTER 4 to exit"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				input(a,n);
				break;
			case 2:
				output(a,n);
				break;
			case 3:
				bubble_sort(a,n);
				break;
			case 4:
				exit(0);
				break;
			default:
				cout<<"invalid input"<<endl;
		}
	}
}
