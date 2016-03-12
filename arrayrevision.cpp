#include <bits/stdc++.h>
using namespace std;

void printPairs(int *a,int n,int k)
{sort(a,a+n);
	int l=0;int r=n-1;
	while(l<r)
	{if(a[l]+a[r]==k)
		{cout<<"Pair eith sum "<<k<<" is "<<a[l]<<" and "<<a[r]<<"\n";
		return;}
		if(a[l]+a[r]<k)
			l++;
		else r--;

	}
cout<<"No pair found.\n";
}
void printMajority(int* a,int n)
{int count=1;
	int poss=a[0];
	for(int i=1;i<n;i++)
	{if(a[i]==a[0])
		count++;
		else count--;
		if(count==0)
			{poss=a[i];
				count=1;}



	}
	int final=0;
	for(int i=0;i<n;i++)
	{if(a[i]==poss)
		final++;

	}
	if(final>n/2)
cout<<"majority is "<<poss<<"\n";
else cout<<"No majority \n";




}
int getOddOccurrence(int *a, int n)
{int ans=a[0];
	for(int i=1;i<n;i++)
	{ans=ans^a[i];

	}
return ans;
}
int maxSubArraySum(int* a,int n)
{int max=a[0];int start=0;int currsum=a[0];
	for(int i=1;i<n;i++)
	{if(currsum<0)
		{currsum=a[i];
			start=i;


		}
		else{
			currsum=currsum+a[i];
		}if(currsum>max)
		max=currsum;

	}
return max;

}
int getMissingNo(int *a,int n)
{int xorn=1;
	for(int i=2;i<=n+1;i++)
		xorn=xorn^i;
	int xora=a[0];
	for(int i=1;i<n;i++)
		xora=xora^a[i];

	return xora^xorn;

}
int bsearch(int*a,int l,int r,int k)
{if(l>r)
	return -1;

	int mid=l+(r-l)/2;
	if(a[mid]==k)
		return mid;
	else if(a[mid]<k)
		bsearch(a,mid+1,r,k);
	else bsearch(a,l,mid-1,k);

}
int findPivot(int arr[], int low, int high)
{
   // base cases
   if (high < low)  return -1;
   if (high == low) {cout<<"hello";return low;}
 
   int mid = (low + high)/2;   /*low + (high - low)/2;*/
   if (mid < high && arr[mid] > arr[mid + 1])
     return mid;
   if (mid > low && arr[mid] < arr[mid - 1])
     return (mid-1);
   if (arr[low] >= arr[mid])
     return findPivot(arr, low, mid-1);
   else
     return findPivot(arr, mid + 1, high);
}

int pivotedBinarySearch(int* a,int n,int k)
{int pivot=findPivot(a,0,n-1);
	if(pivot==-1)
		return bsearch(a,0,n-1,k);
	int ans=bsearch(a,0,pivot,k);
	if(ans!=-1)
		return ans;
	return bsearch(a,pivot+1,n-1,k);


}
void moveToEnd(int *a,int n)
{int j=n-1;
	for(int i=n-1;i>=0;i--)
	{if(a[i]!=-1)
		a[j--]=a[i];

	}
	while(j>=0)
		a[j--]=-1;

}
void merge(int * a,int *b,int m,int n)
{int i=n;
	int j=0;
	int k=0;
	while(i<m&&j<n)
	{if(a[i]<b[j])
		a[k++]=a[i++];
		else if(a[i]>=b[j])
		a[k++]=b[j++];

	}
while(i<m)
	a[k++]=a[i++];
while(j<n)
	a[k++]=b[j++];

}
void printArray(int *a,int n)
{for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	cout<<endl;

}int min(int a,int b)
{if(a<b)
	return a;
	else return b;

}
int max(int a,int b)
{if(a>b)
	return a;
	else return b;

}
int median(int *a,int n)
{if(n<=0)
	return -1;
	if(n&1)
	return a[n/2];
else return((a[n/2]+a[n/2-1])/2);


}
int getMedian(int* a,int* b,int n )
{if(n<=0)
	return -1;
	if(n==1)
	return((a[0]+b[0])/2);
if(n==2)
{return((max(a[0],b[0])+min(a[1],b[1]))/2);


}	
int m1=median(a,n);
int m2=median(b,n);
if(m1==m2)
	return m1;
if(m1<m2)
{
if(n%2==0)
{return getMedian(a+n/2-1,b,n/2+1);


}
else return getMedian(a+n/2,b,n/2+1);

}
else 
{
if(n%2==0)
{return getMedian(b+n/2-1,a,n/2+1);


}
else return getMedian(b+n/2,a,n/2+1);

}
}
int findmaxsum(int *a,int n)
{int ex=0;int ans_inc;int ans_exc=a[0];
	int inc=a[0];
	int maxsum=0;
	for(int i=1;i<n;i++)
	{ ans_inc=a[i]+ex;
		
		maxsum=max(ans_exc,ans_inc);
		ex=max(ex,ans_exc);
		ans_exc=maxsum;



	}
return maxsum;
}

int findmaxsum2(int *a,int n)
{int res[n-1];
	res[0]=a[0];
	res[1]=max(a[0],a[1]);
	for(int i=2;i<=n-1;i++)
	{res[i]=max(a[i]+res[i-2],res[i-1]);

	}
return res[n-1];
}
void mergearray(int* a,int l,int mid,int r,int *temp,int *count)
{//cout<<"sa";
	int i=l;int j=mid+1;int k=l;
	while(i<=mid&&j<=r)
	{
		if(a[i]<=a[j])
		{temp[k++]=a[i++];

		}
		else{
			*count=*count+mid-i+1;
			temp[k++]=a[j++];
		}

	}
	while(i<=mid)
	{temp[k++]=a[i++];
		


	}
	while(j<=r)
		temp[k++]=a[j++];

	for(int g=l;g<=r;g++)
		a[g]=temp[g];


}
void mergessort(int *a,int l,int r,int *temp,int *count)
{if(l>=r)
	return;
	if(l<r)
	{int mid=l+(r-l)/2;
		mergessort(a,l,mid,temp,count);
		mergessort(a,mid+1,r,temp,count);
		mergearray(a,l,mid,r,temp,count);

	}


}
int firstoccurance(int*a,int l,int r,int k)
{if(l>r)
	return -1;
	if(l==r&&a[l]==k)
		return l;
	else if(l==r)
		return -1;
	int mid=l+(r-l)/2;
	if(mid==l&&a[mid]==k)
		return mid;
	if(a[mid-1]!=k&&a[mid]==k)
		return mid;
	if(a[mid]>=k)
		return firstoccurance(a,l,mid-1,k);
	else return firstoccurance(a,mid+1,r,k);

}
int lastoccurance(int*a,int l,int r,int k)
{if(l>r)
	return -1;
	if(l==r&&a[r]==k)
		return r;
	else if(l==r)
		return -1;
	if(r==l+1&&a[r]==k)
		return r;
	int mid=l+(r-l)/2;
	if(a[mid]==k&&a[mid+1]!=k)
		return mid;
	if(a[mid]<=k)
		return lastoccurance(a,mid+1,r,k);
	else return lastoccurance(a,l,mid-1,k);




}
void segregate0and1(int* a,int n)
{int l=0;int r=n-1;
	while(l<r)
	{while(a[l]==0&&l<r)
		l++;
		while(a[r]==1&&r>l)
			r--;
		int temp=a[r];
		a[r]=a[l];
		a[l]=temp;
		l++;r--;


	}


}
int min(int a,int b,int c)
{int min=c;
	if(a<min)
		min=a;
	if(b<min)
		min=b;
	return min;

}
void printmaxsubsquare(bool a[][5])
{int res[6][5];
	for(int i=0;i<5;i++)
		res[0][i]=a[0][i];
	for(int i=0;i<6;i++)
		res[i][0]=a[i][0];
	for(int i=1;i<6;i++)
	{for(int j=1;j<5;j++)
		{if(a[i][j]==1)
			res[i][j]=min(res[i-1][j],res[i][j-1],res[i-1][j-1])+1;
			else res[i][j]=0;
		}

	}int max=0;
	for(int i=0;i<6;i++)
		{for(int j=0;j<5;j++)
		{if(res[i][j]>max)
			max=res[i][j];

		}	


		}
			for(int i=0;i<max;i++)
			{for(int j=0;j<max;j++)
				cout<<1<<" ";
				cout<<endl;

			}
}

int  prtintmaxdiff(int *a,int n)
{int ans=0;
	int min=a[0];
	for(int i=1;i<n;i++)
	{if(a[i]-min>ans)
		ans=a[i]-min;
		if(a[i]<min)
			min=a[i];

	}
return ans;


}
int floorbsearch(int *a,int l,int r,int k)
{

	return 0;


}
int floor(int *a,int n,int k)
{if(k>=a[n-1])
return a[n-1];
if(k<a[0])
return -1;
if(k==a[0])
return 0;
return floorbsearch(a,0,n-1,k);
}
void sort012(int *a,int n)
{int l=0;int mid=0;int r=n-1;
	while(mid>=l&&mid<=r&&l<r)
	{if(a[mid]==1)
		mid++;
		else if(a[mid]==0)
		{int temp=a[l];
			a[l]=a[mid];
			a[mid]=temp;
			l++;mid++;

		}
		else if(a[mid]==2)
		{int temp=a[mid];
			a[mid]=a[r];
			a[r]=temp;
			r--;

		}

	}


}
void sortposneg(int* a,int n)
{int i=-1;
	int j=0;
	while(j<n)
	{while(a[j]>=0&&j<n)
		j++;
		if(j>=n)
			break;
		if(a[j]<0)
		{i++;
			int temp=a[j];
			a[j]=a[i];
			a[i]=temp;
			j++;

		}

	}

}
void calculateSpan(int *price,int n,int *ans)
{stack<int >s;
	for(int i=0;i<n;i++)
	{while((!s.empty() )&& price[i]>=price[s.top()])
		{
			{s.pop();

			}

		}
		if(s.empty())
			ans[i]=i+1;
		else ans[i]=i-s.top();
		s.push(i);

	}

}

int main()
{
 
   int price[] = {10, 4, 5, 90, 120, 80};
    int n = sizeof(price)/sizeof(price[0]);
    int S[n];

    // Fill the span values in array S[]
    calculateSpan(price, n, S);

    // print the calculated span values
    printArray(S, n);






	return 0;
}