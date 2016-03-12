#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
int max(int a,int b)
{if(a>b)
return a;
else return b;}
int compare(const void* a,const void* b)
{
	return (*(int*)a > *(int*)b);
}

bool hasArrayTwoCandidates(int a[],int size,int n)
{qsort(a,size,sizeof(int ),compare);
	for(int i=0,j=size-1;i<j;)
{if(a[i]+a[j]==n)
	return true;
	else if(a[i]+a[j]<n)
		i++;
	else j--;
}
return false;



}
void printMajority(int a[],int n)
{int ans=a[0];int count=1;int i;
	for( i=1;i<n;i++)
	{if(a[i]==ans)
		count++;
		else count--;
		if(count==0)
		{ans=a[i];
			count=1;

		}
		

	}

if(count>1)
		cout<<"The majority element is "<<ans;
		else cout<<"NONE";

}
int getOddOccurrence(int a[],int n)
{int ans=a[0];
	for(int i=1;i<n;i++)
		ans=ans^a[i];

	return ans;

}
int maxSubArraySum(int a[],int  n)
{int sum;int max;int here;
	max=a[0];sum=a[0];here=0;
	for(int i=1;i<n;i++)
	{if(sum<0)
			sum=0;
		sum=sum+a[i];
		if(sum>max)
			max=sum;
		



	}

return max;

}
void moveToEnd(int a[],int size)
{int j=size-1;int i=size-1;int count=5;
	while(count)
	{if(a[i]!=-1)
		{a[j]=a[i];
			count--;j--;

		}
		i--;


	}

for( i=0;i<4;i++)
{a[i]=-1;}


}
void merge(int a[],int b[],int size1,int size2)
{int start1=size2;
int start2=0;
int cursor=0;
while(start1<size1&&start2<size2)
{if(a[start1]<b[start2])
	{a[cursor++]=a[start1++];}
else a[cursor++]=b[start2++];
}
while(start1<size1)
	a[cursor++]=a[start1++];
while(start2<size2)
	a[cursor++]=b[start2++];

}
void printArray(int a[],int size)
{for(int i=0;i<size;i++)
	{
		cout<<a[i]<<" ";
	}
cout<<"\n";
}

int FindMaxSum(int a[],int size)

{int inc=a[0];
	int ex=0;int sum;
	for(int i=1;i<size;i++)
	{sum=max(ex+a[i],inc);
		int temp=ex;
		ex=inc;
		inc=temp+a[i];



	}

return sum;

	
}
void printLeaders(int a[],int size)
{int max=-1;
	for(int i=size-1;i>=0;i--)
	{if(a[i]>max)
		{max=a[i];
		cout<<max<<" ";
}
	}



}
int getInvCount(int [],int size)
{													



}
int maxDiff(int a[],int size)
{int min=a[0];
	int diff=0;
	for(int i=1;i<size;i++)
	{if(a[i]-min>diff)
		diff=a[i]-min;
		if(a[i]<min)
			min=a[i];

	}

return diff;

}
int bsearch(int a[],int l,int r,int x)
{if(r>=l)
	{int mid=(l+r)/2;
		if((mid==r&&a[mid]>=x)||a[mid]==x||(a[mid]>x&&a[mid-1]<x))
			return mid;
		else if(a[mid]<x)
			return bsearch(a,mid+1,r,x);
		else return bsearch(a,l,mid-1,x);

	}
return -1;
}
int ceilSearch(int a[],int l,int h,int x)
{if(a[l]>x)
	return l;
	if(a[h]<x)
	return -1;
	return bsearch(a,l,h,x);



}
void printNGE(int a[],int n)
{stack<int >s;s.push(a[0]);
	int i=1;
	while(i<n)
	{
	
	while(!s.empty()&&i<n)
	{if(a[i]>s.top())
		{cout<<s.top()<<"---"<<a[i]<<"\n";
		s.pop();
	}
	else 
		break;
	}
	
	s.push(a[i]);
if(i==n-1)
	break;
	i++;
}
//cout<<"sdf";
while(!s.empty())
{
	cout<<s.top()<<"-- -1\n";
	s.pop();
}

}
int bfloor(int a[],int l,int r,int x)
{if(l<=r)
	{int mid=(l+r)/2;
		if((mid==l&&a[mid]==x) ||(a[mid]==x) &&a[mid-1]!=x)
			return mid;
		else if(a[mid]>=x)
			return bfloor(a,l,mid-1,x);
		else return bfloor(a,mid+1,r,x);


	}
	return -1;

}
int bceil(int a[],int l,int r,int x)
{if(l<=r)
	{int mid=(l+r)/2;
		if((mid==r&&a[mid]==x) ||(a[mid]==x) &&a[mid+1]!=x)
			return mid;
		else if(a[mid]<=x)
			return bceil(a,mid+1,r,x);
		else return bceil(a,l,mid-1,x);


	}
return -1;
}
int count(int a[],int x,int size)
{int l=0;int r=size-1;
	int as=bfloor(a,l,r,x);
	int bs=bceil(a,l,r,x);
	if(bs==-1)
		return 0;
	return bs-as+1;

}
int mins(int a,int b)
{
	if(a<b)
		return a;
	else return b;
}int maxs(int a,int b)
{if(a>b)
return a;
else return b;}
int maxIndexDiff(int a[],int n)
{int max[n];
	int min[n];min[0]=a[0];
	for(int i=1;i<n;i++)
	{min[i]=mins(a[i],min[i-1]);

	}
	max[n-1]=a[n-1];
	for(int i=n-2;i>=0;i--)
	{max[i]=maxs(a[i],max[i+1]);


	}
int diff=0;
	int one=0;int two=0;
	while(one <n&&two <n)
	{if(max[one]>min[two])
		{if(one-two>diff)
			diff=one-two;
			one++;

		}
		else two++;

	}
return diff;
}
int findMaximum(int a[],int l,int r)
{
if(l<=r)
{
	int mid=(l+r)/2;
	cout<<l<<" "<<r<<" "<<mid<<"\n";
	if(mid==r)
		return a[mid];
	if(mid==l&&a[mid]>a[mid+1])
		return a[mid];
	if(a[mid]>a[mid+1]&&a[mid]>a[mid-1])
		return a[mid];
	if(a[mid]>a[mid+1])
		return findMaximum(a,l,mid-1);
	else return findMaximum(a,mid+1,r);


}


}
int main()
{

  int arr[] = {1, 30, 40, 50,100,100, 60, 50, 40 };
   int n = sizeof(arr)/sizeof(arr[0]);
   printf("The maximum element is %d", findMaximum(arr, 0, n-1));
	return 0;
}