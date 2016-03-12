#include <bits/stdc++.h>
using namespace std;
struct node
{int dist;
	int petrol;

};
int findstart1(int *a,int l,int r)
{int start=0;int sum=a[l];int curr=a[l];
	for(int i=l+1;i<r;i++)
	{sum=sum+a[i];
		if(curr<0)
		{curr=a[i];
			start=i;

		}
		else {
			curr=curr+a[i];
		}

	}
	if(sum<0)
		return -1;
	return start;

}
int findstart2(int *a,int n)
{int start=0;
	int end=1;int curr=a[0];
	while(start<end||curr<0)
	{while(start<end&&curr<0)
		{curr=curr-a[start];
			start=(start+1)%n;
			if(start==0)
			return -1;
		}
		curr=curr+a[end];
		end=(end+1)%n;
		


	}


return start;


}bool check(int *temp)
{for(int i=0;i<26;i++)
	{if(temp[i]>=2)
		return true;}
		return false;

	

}

int longestUniqueSubsttr(char* s)
{int len=strlen(s);int   temp[26]={0};
	int start=0;int end=1;int curr=1;int max=1;temp[s[start]-'A']=1;
	while(end<=len)
	{while(check(temp))
		{temp[s[start]-'A']=temp[s[start]-'A']-1;start++;}
			if(end-start>max)
				max=end-start;
		if(end<len)
		{temp[s[end]-'A']++;
			

		}
		end++;
		
cout<<max	<<" "<<end<<" "<<s[start]<<temp[s[start]-'A']<<" | ";

	}
//ABDAAAAAAGHJFURYDLKD



return max;
}
int binarySearch(int *a,int l,int r)
{if(l<=r)
	{if(l==r)
		{if(a[l]==l)
			return l;
			else return -1;

		}
		int mid=l+(r-l)/2;
		if(a[mid]==mid)
			return mid;
		if(a[mid]<mid)
			return binarySearch(a,mid+1,r);
		return binarySearch(a,l,mid-1);

	}
return -1;
}
int findMaximum(int *a,int l,int r)
{if(l>r)
	return -1;
	if(l==r)
		return a[l];
	int mid=l+(r-l)/2;
	if(mid>=l+1)
		{if(a[mid-1]<a[mid]&&a[mid]>a[mid+1])
			return a[mid];
		}
		if(a[mid]>a[mid-1])
			return findMaximum(a,mid+1,r);
		return findMaximum(a,l,mid-1);


}
void subArraySum(int *a,int n,int sum)
{int start=0;int end=1;int curr=a[0];
	while(end<=n)
	{while(curr>sum)
		{curr-=a[start];
			start++;
		}
			if(curr==sum)
			{cout<<start<<" "<<end-1<<"\n";
			return;

			}
			if(end<n)
			{curr=curr+a[end];end++;

			}

		

	}

}
void printArray(int *a,int n)
{for(int i=0;i<n;i++)
	cout<<a[i]<<" ";

}
void partition(int *a,int l,int r)
{while(l<r)
	{while(a[l]<0&&l<r)
		l++;
		while(a[r]>0&&l<r)
			r--;
		if(l<r)
		{int temp=a[l];
			a[l]=a[r];
			a[r]=temp;
			l++;
			r--;

		}

	}

}
void rearrange(int *a,int n)
{partition(a,0,n-1);

int pos=0;int neg=0;
while(a[pos]<0&&pos<n)
pos++;
if(pos>=n)
return;
while(neg<pos&&a[neg]<0&&a[pos]<n)
{int temp=a[neg];
a[neg]=a[pos];
a[pos]=temp; 
neg+=2;
pos++;
}






}
int findPeak(int *a,int l,int r)
{if(l<=r)
	{int mid=l+(r-l)/2;
		if()

	}

}
int smallestSubWithSum(inr *a,int n,int x)
{int start=0;int curr=a[0],int min=1;int end=1;
	while(end<=n)
	{while(curr)

	}


}
int main()
{ int arr1[] = {1, 4, 45, 6, 10, 19};
    int x = 51;
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    cout << smallestSubWithSum(arr1, n1, x) << endl;

    int arr2[] = {1, 10, 5, 2, 7};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    x  = 9;
    cout << smallestSubWithSum(arr2, n2, x) << endl;

    int arr3[] = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    x  = 280;
    cout << smallestSubWithSum(arr3, n3, x) << endl;
return 0;
}