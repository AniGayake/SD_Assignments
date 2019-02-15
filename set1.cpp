#include<iostream>
using namespace std;
int inter(int [],int [],int[],int ,int);
int uni(int [],int[],int[],int,int);
int display(int set);
int compare(int,int [],int);
int difference(int [],int [],int [],int ,int);
int main()
{
	int ch,set1[20], set2[20], set3[20],s1,s2,s;
	cout<<"Enter the size of Set 1 : ";	
	cin>>s1;
	cout<<"Enter the elements of set 1 : \n";
	for(int i=0;i<s1;i++)
	cin>>set1[i];

	cout<<"Enter the size of Set 2 : ";	
	cin>>s2;
	cout<<"Enter the elements of set 2 : \n";
	for(int j=0;j<s2;j++)
	cin>>set2[j];
	cout<<"\t\t\t\nOperations On Set : \n";
	do{
		cout<<"\t\t1.Intersection\n\t\t2.Union\t\t\n\t\t3.Difference\n";
		cout<<"Your choise :  ";
		cin>>ch;
		if(ch>4)
		cout<<"Invalid choise ,Please try again !";
		else
	{		
	switch(ch)
		{
			case 1:

				s = inter(set1,set2,set3,s1,s2);
				if(s==0)
				cout<<"\t\t\nNULL Intersection \n";
				else
				{
				cout<<"\t\t\nIntersection of given sets is : \n";
				//Prints out INTERSECTION
				for(int a=0;a<s;a++)
				cout<<"\t\t\t\t"<<set3[a]<<endl;
				}
			break;
			case 2:
				cout<<"\t\t\nUnion of given sets is : \n";
				s=uni(set1,set2,set3,s1,s2);
				for(int i=0;i<(s+s1);i++)
				cout<<"\t\t\t\t"<<set3[i]<<"\n";
				break;
			case 3:
				cout<<"\t\t\nDifference (A-B) of given sets is : \n";
				 s= difference(set1,set2,set3,s1,s2);
				for(int i=0;i<s;i++)
				cout<<"\t\t\t\t"<<set3[i]<<endl;
				break;
		}
}
	}while(ch<4);
		
}
int inter(int setA[],int setB[],int setC[],int sA,int sB)
{
	int key,k=0;
	for(int i=0;i<sA;i++)
	{
		if(compare(setA[i],setB,sA)==1)
		{
			setC[k] = setA[i];
			k++;
		}
	}
	return k;
}

int uni(int setA[],int setB[],int setC[],int sA,int sB)
{
	int k=0;
		for(int i=0;i<sA;i++)
		setC[i] = setA[i];
		
		for(int i=0;i<sB;i++)
		{
			if(compare(setB[i],setA,sA)==0)
			{
				setC[sA+k] = setB[i];
				k++;
			}
					
		}
return k;
}

int compare(int key,int set[],int s)
{
		int c=0;
	for(int i=0;i<s;i++)
	{
			if(key==set[i])
		{
			c= 1;
			break;
		}	
	}
return c;
		
}
g
int difference(int set1[],int set2[],int set3[],int s1,int s2)
{
	int set[20],k=0;
	int s = inter(set1,set2,set,s1,s2);
	
	for(int i=0;i<s1;i++)
	{
		if(compare(set1[i],set,s)==0)
			{
				set3[k]=set1[i];
				k++;
			}
	}
	return k;
}



