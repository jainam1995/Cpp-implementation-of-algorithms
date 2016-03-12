#define NA -1
#include <bits/stdc++.h>
using namespace std;
int majority(int *a,int n)
{if(n==1)
	return a[0];
	int count=1;
	int max=a[0];
	for(int i=1;i<n;i++)
	{if(count==0)
		{count=1;
			max=a[i];

		}
		else{
			if(a[i]==max)
				count++;
			else count--;
		}

	}
	count=0;
	for(int i=0;i<n;i++)
if(a[i]==max)
	count++;
if(count>n/2)
	return max;
return -1;

}
int oddoccur(int *a,int n)
{int ans=0;
	for(int i=0;i<n;i++)
	{ans=ans^a[i];

	}
	return ans;

}
int maxsumsub(int *a,int n)
{if(n==1)
	return a[0];
	int max=a[0];
	int ans=a[0];
	int start=0;int maxstart=0;
	int end=0;
	for(int i=0;i<n;i++)
	{if(ans<0)
		{start=i;
			ans=a[i];
if(ans>max)
{maxstart=start;
	end=i;

}

		}
		else{
			ans=ans+a[i];
			if(ans>max)
			{max=ans;
				maxstart=start;
				end=i;

			}
		}

	}
cout<<maxstart<<" "<<end<<" "<<max;
}
int abs(int a)
{if(a>=0)
	return a;
	else return -1*a;

}
int getMissingNo(int *a,int n)
{for(int i=0;i<n;i++)
	{if((a[i]-1<n) && a[a[i]-1]>=0)
		a[abs(a[i])-1]=-a[abs(a[i])-1];

	}
	for(int i=0;i<n;i++)
	{if(a[i]>0)
		return i+1;

	}
	return n+1;

}
int findpivot(int *a,int l,int r)
{if(l>r)
	return -1;
	if(l<=r)
	{int mid=l+(r-l)/2;
		if(mid>l&&a[mid-1]>a[mid])
			return mid-1;
		if(mid<r&&a[mid]>a[mid+1])
			return mid;
		if(a[mid]>a[l])
			return findpivot(a,mid+1,r);
		else return findpivot(a,l,mid-1);

	}
	return -1;

}
int findsortpivot(int *a,int n,int k)
{int pivindex=findpivot(a,0,n-1);
	return pivindex;

}
void moveToEnd(int *a,int m)
{int i=0;int j=0;
	for(int i=0;i<m;i++)
	{if(a[i]!=-1)
		a[j++]=a[i];

	}
	while(j<m)
	{a[j]=-1;
		j++;

	}
	for (int i=0;i<m;i++)
		cout<<a[i]<<" ";

}
int max(int a,int b)
{if(a>b)
	return a;
	else return b;


}
int median(int *a,int n)
{if(n&1)
	return a[n/2];
	else return (a[n/2]+a[n/2-1])/2;

}
int min(int a,int b)
{if(a<b)
return a;
else return b;}
int getMedian(int *a,int *b,int n)
{if(n==0)
	return -1;
	if(n==1)
		return (a[0]+b[0])/2;
	if(n==2)
		return (max(a[0],b[0])+min(a[1],b[1]))/2;

int m1=median(a,n);
int m2=median(b,n);
if(m1==m2)
	return m1;
else if(m1<m2)
{if(n%2==0)
	return getMedian(a+n/2-1,b,n/2+1);
	else return getMedian(a+n/2,b,n/2+1);

}
else if(m2<m1)
{if(n%2==0)
	return getMedian(b+n/2-1,a,n/2+1);
	else return getMedian(b+n/2,a,n/2+1);


}


}
int ceilSearch(int *a,int l,int r,int k)
{if(k<=a[l])
return l;
if(k>a[r])
return -1;
if(l>r)
	return -1;
int mid=l+(r-l)/2;
if(a[mid]==k)
return mid;
if(mid>l&&a[mid-1]<k&&a[mid]>=k)
return mid;
if(mid<r&&a[mid]<k&&a[mid+1]>=k)
return mid+1;
if(a[mid]>k)
return ceilSearch(a,l,mid-1,k);
return ceilSearch(a,mid+1,r,k);
}
int FindMaxSum(int *a,int n)
{int ans[n];
	ans[0]=a[0];
	ans[1]=max(a[0],a[1]);
	for(int i=2;i<n;i++)
	{ans[i]=max(a[i]+ans[i-2],ans[i-1]);

	}
	return ans[n-1];


}
int floorSearch(int *a,int l,int r,int k)
{if(l>r)
	return -1;
	if(k>=a[r])
		return r;
	if(k<a[l])
		return -1;
	int mid=l+(r-l)/2;
	if(a[mid]==k)
		return mid;
	if(mid>l&&a[mid-1]<=k&&a[mid]>k)
		return mid-1;
	if(mid<r&&a[mid]<=k&&a[mid+1]>k)
		return mid;
	if(a[mid]>k)
		return floorSearch(a,l,mid-1,k);
	return floorSearch(a,mid+1,r,k);



}
void swap(int *a,int *b)
{int temp=*a;
*a=*b;
*b=temp;

}
void segregateEvenOdd(int *a,int n)
{int l=0;int r=n-1;
	while(l<r)
	{while(a[l]%2==0&&l<r)
		l++;
		while(a[r]&1&&l<r)
			r--;
		swap(a+l,a+r);
		l++;r--;

	}

}
void sort012(int *a,int n)
{int l=0;int mid=0;int r=n-1;
	while(mid<=r)
	{if(a[mid]==1)
		mid++;
		else if(a[mid]==0)
		{swap(a+l,a+mid);
			l++;mid++;

		}
else if(a[mid]==2)
	    {swap(a+mid,a+r);
	    	r--;


	    }
	}

}

void printArray(int *a,int n)
{for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	cout<<endl;

}
int fixedpoint(int *a,int l,int r)
{if(l>r)
	return -1;
	int mid=l+(r-l)/2;
	if(a[mid]==mid)
		return mid;
	if(a[mid]>mid)
		return fixedpoint(a,l,mid-1);
	return fixedpoint(a,mid+1,r);

}
void rearrange(int *a,int n)
{int i=-1;int j=0;
	while(j<n)
	{while(a[j]>0)
		j++;
		if(a[j]<0)
		{i++;
			swap(a+i,a+j);
			j++;

		}

	}
	int pos=i+1;
	int neg=0;
	while(pos<n&&neg<pos&&a[neg]<0)
	{swap(a+neg,a+pos);
		neg=neg+2;
		pos++;

	}

}
struct node{
	int data;
	int index;
	int freq;
};
bool compare(const struct node& a,const struct node& b)
{if(a.freq==b.freq)
	return a.index<b.index;
	return a.freq>b.freq;

}
void sortbyfreq(int *a,int n)
{struct node ans[n];for(int i=0;i<n;i++)ans[i].freq=0;
	sort(a,a+n);int i=1;int j=1;
	ans[0].data=a[0];
	ans[0].freq=1;
	ans[0].index=0;int k=0;
	while(i<n)
	{int count=0;
		while(j<n&&a[j]==a[i])
		{count++;
			j++;

		}
		i=j;
		ans[k].freq+=count;
		k++;
		if(j<n)
		{
		ans[k].index=j;
		ans[k].data=a[j];
		ans[k].freq=1;
		j++;
	}

	}
	sort(ans,ans+k,compare);
	for(int i=0;i<k;i++)
	{for(int j=0;j<ans[i].freq;j++)
		cout<<ans[i].data;

	}

}
void merge(int *a,int l,int mid,int r,int *count,int *temp)
{if(l>=r)
	return;
	int i=l;
	int j=mid+1;
	int k=l;
	while(i<=mid&&j<=r)
	{if(a[i]<=a[j])
		temp[k++]=a[i++];
		else if(a[j]<a[i])
			{temp[k++]=a[j++];
				*count=*count+mid-i+1;
					}

	}
	while(i<=mid)
		temp[k++]=a[i++];
	while(j<=r)
		temp[k++]=a[j++];
for(int g=l;g<k;g++)
	a[g]=temp[g];


}
void mergesortutil(int *a,int l,int r,int *count,int *temp)
{if(l<r)
	{int mid=l+(r-l)/2;
		mergesortutil(a,l,mid,count,temp);
		mergesortutil(a,mid+1,r,count,temp);
		merge(a,l,mid,r,count,temp);

	}

}
int mergeSort(int *a,int n)
{int count=0;int temp[n];
	mergesortutil(a,0,n-1,&count,temp);
return count;

}
int  partition(int *a,int l,int r)
{
	int pivot=a[r];
	int i=l-1;
	int j=l;
while(j<r)
{while(a[j]>=pivot&&j<r)
	j++;
	if(a[j]<pivot)
	{i++;
		swap(a+i,a+j);
		j++;

	}

}
i++;
swap(a+i,a+r);
return i;
}
int kthsmallest(int* a,int l,int r,int k)
{if(l==r)
	return a[l];
	if(l<r)
	{
	int pivot=partition(a,l,r);
	printArray(a,5);
	cout<<endl;
cout<<pivot<<"ASf"<<a[pivot]<<"sdf";
	if(pivot==k)
		return a[pivot];
	if(pivot>k)
		return kthsmallest(a,l,pivot-1,k);
	return kthsmallest(a,pivot+1,r,k);
}


}
int firstoccur(int *a,int l,int r,int k)
{if(l>r)
	return -1;
	int mid=l+(r-l)/2;
	if(a[l]==k)
		return l;
	if(l<mid&&a[mid-1]<k&&a[mid]==k)
		return mid;
	if(a[mid]>=k)
		return firstoccur(a,l,mid-1,k);
	else return firstoccur(a,mid+1,r,k);

}
int lastoccur(int *a,int l,int r,int k)
{if(l>r)
	return -1;
	int mid=l+(r-l)/2;
	if(a[r]==k)
		return r;
	if(mid<r&&a[mid]==k&&a[mid+1]!=k)
		return mid;
	if(a[mid]<=k)
		return lastoccur(a,mid+1,r,k);
	return lastoccur(a,l,mid-1,k);

}
void printUnsorted(int *a,int n)
{int l=0;
	while(l<n-1&&a[l]<=a[l+1])
	l++;//10, 12, 20, 30,  35,25, 50, 60};
if(l==n-1)
	return;
int start=l;
//cout<<start<<"saf";
int r=n-1;
while(r>start&&a[r]>=a[r-1])
	r--;

int end=r;
//cout<<end<<"df";
int min=a[start];int max=a[start];
for(int i=start;i<=end;i++)
{if(a[i]<min)
	min=a[i];
	if(a[i]>max)
		max=a[i];

}
//cout<<start<<"Sdf";
int minindex=start;int maxindex=end;
for(int i=0;i<start;i++)
{if(a[i]>min)
	{minindex=i;
		break;

	}

}
for(int i=n-1;i>end;i--)
{if(a[i]<max)
	{maxindex=i;
	break;}

}

	
cout<<minindex<<" "<<maxindex;
}
bool isMajority(int *a,int n,int k)
{int t=firstoccur(a,0,n-1,k);
	if(t==-1)
		return false;
	//cout<<t<<"sdf\n";
	int p=lastoccur(a,0,n-1,k);
	cout<<p<<"sdf\n";
	if(p-t+1>n/2)
		return true;
	return false;

}

void printRepeating(int *a,int n)
{for(int i=0;i<n;i++)
	{if(a[abs(a[i])]>0&&a[i]!=0)
		a[abs(a[i])]=-a[abs(a[i])];
		else if(a[i]!=0)cout<<abs(a[i])<<" ";
	}
	int count=0;
	for(int i=0;i<n;i++)
	{if(a[i]==0)
		count++;

	}
	if(count>1)
		cout<<0<<"\n";
	

}
int findFirstMissing(int *a,int l,int r)
{if(l>r)
	return r+1;
	int mid=l+(r-l)/2;
	if(a[l]!=l)
		return l;
	if(a[mid]>mid)
		return findFirstMissing(a,l,mid-1);
	return findFirstMissing(a,mid+1,r);

}
int findFirstMissing2(int *a,int l,int r)
{for(int i=l;i<=r;i++)
	{if(a[abs(a[i])]>0)
		a[abs(a[i])]=-a[abs(a[i])];

	}

}
int maxi(int a,int b)
{if(a>b)
	return a;
	return b;

}
int mini(int a,int b)
{if(a<b)
	return a;
	return b;

}
int maxIndexDiff(int *a,int n)
{int max[n];int min[n];
	min[0]=a[0];max[n-1]=a[n-1];
	for(int i=1;i<n;i++)
	{min[i]=mini(a[i],min[i-1]);

	}
	for(int i=n-2;i>=0;i--)
		max[i]=maxi(a[i],max[i+1]);
	int maxdiff=0;
	int i=0;int j=0;
	while(i<n&&j<n)
	{
		if(max[j]>min[i])
		{if(j-i>maxdiff);
		maxdiff=j-i;
			j++;
		}
		else i++;

	}
	for(int i=0;i<n;i++)
		cout<<max[i]<<" ";
return maxdiff;
}
int minDist(int *a,int n,int x,int y)
{int i=0;
while(a[i]!=x&&a[i]!=y)
	i++;
int ans=a[i];
int index=i;
i++;
int min=INT_MAX;
while(i<n)
{while(a[i]!=x&&a[i]!=y)
	i++;
	if(a[i]!=ans)
	{if(i-index<min)
		{min=i-index;
			

		}


	}
	index=i;
			ans=a[i];
i++;
}
return min;
}
void printTwoElements(int *a,int n)
{cout<<"Repeating :\n";
	for(int i=0;i<n;i++)
	{if(a[abs(a[i])-1]>0)
		a[abs(a[i])-1]=-a[abs(a[i])-1];
		else cout<<abs(a[i])<<" ";

	}
	cout<<endl;
	cout<<"Missing :\n";
	for(int i=0;i<n;i++)
	{if(a[i]>0)
		cout<<i+1<<" ";

	}
	cout<<endl;

}
void printTwoElementsxor(int *a,int n)
{int one=0;
	for(int i=1;i<=n;i++)
		one=one^i;
	for(int i=0;i<n;i++)
		one=one^a[i];
	int k;
	for(k=1;;k=k<<1)
	{if(one&k)
		break;

	}
	int first=0;int second=0;
	for(int i=0;i<n;i++)
	{if(a[i]&k)
		first=first^a[i];
		else second=second^a[i];

	}

cout<<first<<" "<<second;
}
int bitonic(int *a,int n)
{int min[n];int max[n];
	min[0]=1;
	for(int i=1;i<n;i++)
	{if(a[i]>=a[i-1])
		min[i]=1+min[i-1];
		else min[i]=1;

	}
	max[n-1]=1;
	for(int i=n-2;i>=0;i--)
		if(a[i]>=a[i+1])
			max[i]=1+max[i+1];
		else max[i]=1;
int maxans=0;
		for(int i=0;i<n;i++)
		{if(max[i]+min[i]-1>maxans)
			maxans=max[i]+min[i]-1;
		}
return maxans;
}
int findMaximum(int *a,int l,int r)
{if(l<=r){
	if(l+1==r)
		if(a[l]>=a[r])
			return a[l];
		if(l+1==r)
			if(a[r]>=a[l])
				return a[r];
			int mid=l+(r-l)/2;
			if(a[mid]>a[mid-1]&&a[mid]>a[mid+1])
				return a[mid];
			if(a[mid-1]>=a[mid]&&a[mid]>=a[mid+1])
				return findMaximum(a,l,mid-1);
			return findMaximum(a,mid+1,r);



}

}
int minJumps(int *a,int n)
{if(a[0]==0||n==0)
	return INT_MAX;
	int ans[n];
	for(int i=0;i<n;i++)
		ans[i]=INT_MAX;
	ans[0]=0;
	for(int i=1;i<n;i++)
	{for(int j=0;j<i;j++)
		{if((a[j]!=INT_MAX)&&a[j]+j>=i)
			{ans[i]=ans[j]+1;
				break;}

		}

	}
return ans[n-1];
}
int partitions(int *a,int l,int r)
{int i=l-1;
	int j=l;
	while(j<=r)
	{while(j<=r&&a[j]>-1)
		j++;
		if(j>r)
			break;
		if(a[j]<=-1)
		{i++;
			swap(a+i,a+j);
			j++;

		}


	}
	return i+1;


}
int findmissingutil(int *a,int n)
{for(int i=0;i<n;i++)
	{if(abs(a[i])<n&&a[abs(a[i])]>=0)
		a[abs(a[i])]=-a[abs(a[i])];


	}
	int i;
	for( i=0;i<n;i++)
	{if(a[i]>0)
		return i;

	}
	if(i==n)
		return n;


}
int findPeak(int *a,int l,int r)
{if(l<=r)
	{if(l==r)
		return a[l];
		if(l+1==r)
		{if(a[l]>=a[r])
			return a[l];}
		if(l+1==r&&a[r]>=a[l])
			return a[r];
		int mid=l+(r-l)/2;
		if(mid>l&&mid<r&&a[mid]>a[mid-1]&&a[mid]>a[mid+1])
			return a[mid];
		if(a[mid]>a[mid+1])
			return findPeak(a,l,mid-1);
		return findPeak(a,mid+1,r);


	}

}
int findMissing(int *a,int n)
{int pivot=partitions(a,0,n-1);
return findmissingutil(a+2,n-pivot)-pivot;
}
// Functions to run test cases
struct Interval{
int start;int end;


};
bool compares(const Interval& a,const Interval& b)
{return a.start<b.start;

}
void mergeIntervals(Interval* a,int n)
{sort(a,a+n,compares);
	//for(int i=0;i<n;i++)
	//	cout<<a[i].start<<" ";
	stack<Interval>s;
	s.push(a[0]);int count=1;
	for(int i=1;i<n;i++)
	{if(a[i].start<=s.top().end)
		{if(s.top().end<a[i].end)
			s.top().end=a[i].end;

		}
		else {s.push(a[i]);count++;}

	}
//cout<<s.top().end;cout<<count;
for(int i=count-1;i>=0;i--)
{a[i]=s.top();s.pop();

}
for(int i=0;i<count;i++)
cout<<a[i].start<<" "<<a[i].end<<"\n";
}
void TestCase1()
{
    // Create a set of intervals
    Interval intervals[] = { {6,8}, {1,2}, {2,4}, {4,5} };
    
    // Merge overlapping inervals and print result
    mergeIntervals(intervals,4);
}


int maxProfit(int *a,int n)
{int ans[n];
	for(int i=0;i<n;i++)
		ans[i]=0;
	int high=a[n-1];
	for(int i=n-2;i>=0;i--)
	{if(a[i]>high)
		high=a[i];
		ans[i]=max(ans[i+1],high-a[i]);

	}
	int low=a[0];
	for(int i=1;i<n;i++)
	{if(a[i]<low)
		low=a[i];
		ans[i]=max(ans[i-1],ans[i]+a[i]-low);


	}

return ans[n-1];
}
int findSmallest(int *a,int n)
{int res=1;int i=0;
	while(i<n&&a[i]<=res)
	{res=res+a[i];
		i++;

	}
	return res;

}
int smallestSubWithSum(int *a,int n,int k)
{int curr=a[0];int start=0;int end=1;int min=n;
	while(end<=n)
	{while(curr>k&&start<end)
		{if(end-start<min)
			min=end-start;
			curr=curr-a[start];start++;

		}if(end<n)
		curr=curr+a[end];end++;

	}

return min;
}
int maxRepeating(int *a,int n,int k)
{for(int i=0;i<n;i++)
	a[a[i]%k]=a[a[i]%k]+k;
	int max=0;int maxindex=0;
	for(int i=0;i<n;i++)
	{if(a[i]>max)
		{max=a[i];maxindex=i;}

	}
return maxindex;
}
struct petrolPump{
	int petrol;
	int dist;
};
int printTour(int*a,int n)
{int start=0;int curr=a[0];int ans=0;int sum=a[0];
	for(int i=1;i<n;i++)
		{sum=sum+a[i];
			if(curr<0)
			{start=i;
				curr=a[i];
				ans=i;
			}
			else{
				curr=a[i];
			}

		}
if(sum<0)
	return -1;
else return ans;

}
int printTour2(int *a,int n)
{int start=0;int curr=a[0];int end=1;
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

}
void subArraySum(int *a,int n,int sum)
{int start=0;int end=1;int curr=a[0];
	while(end<=n)
	{while(start<end&&curr>sum)
		{curr=curr-a[start];
				start++;
		}
		if(curr==sum)
		{cout<<start<<" "<<end-1<<endl;
	return;

		}
		if(end<n)
			curr=curr+a[end];
		end++;

	}
	cout<<"None\n";

}
struct nodes{
int data;int freq;

};
void moreThanNdK(int *a,int n,int k)
{struct nodes temp[k-1];
	for(int i=0;i<k-1;i++)
	{temp[i].data=-1;
		temp[i].freq=0;

	}
	int flag;
for(int i=0;i<n;i++)
{flag=0;int p=-1;
	for(int j=0;j<k-1;j++)
	{if(temp[j].data==a[i])
		{temp[j].freq++;flag=1;break;}
		if(temp[j].freq==0)
			p=j;


	}
	if(flag==1)
		continue;
	if(p!=-1)
	{temp[p].data=a[i];
		temp[p].freq++;
continue;

	}
	for(int g=0;g<k-1;g++)
		{temp[g].freq--;
			if(temp[g].freq==0)
				temp[g].data=-1;
		}


}
for(int i=0;i<k-1;i++)
{if(temp[i].data!=-1)
	{int count=0;
		for(int j=0;j<n;j++)
		{if(a[j]==temp[i].data)
			count++;

		}
		if(count>n/k)
		{cout<<temp[i].data<<" "<<count<<"\n";

		}
	}


}


}
bool comp(const char* a,const char* b)
{
	
	return strcmp(a,b)<0;
}
void printAnagramsTogether( char* a[],int n)
{char* b[n];
	for(int i=0;i<n;i++)
		{b[i]=(char*)malloc(sizeof(char)*strlen(a[i])+1);
			strcpy(b[i],a[i]);}
	for(int i=0;i<n;i++)
	sort(b[i],b[i]+strlen(b[i]));
	sort(b,b+n,comp);
	for(int i=0;i<n;i++)
		cout<<b[i]<<"\n";
}
void printKMax(int *a,int n,int k)
{int left[n];int right[n];
	left[0]=a[0];
	for(int i=1;i<n;i++)
	{if(i%k==0)
		left[i]=a[i];
		else left[i]=max(a[i],left[i-1]);

	}
	right[n-1]=a[n-1];
	for(int i=n-2;i>=0;i--)
	{
		if((i%k)==k-1)
			right[i]=a[i];
		else right[i]=max(a[i],right[i+1]);
	}
	for(int i=0;i<n;i++)
		cout<<left[i]<<" ";
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<right[i]<<" ";
cout<<endl;
for(int i=0;i<=n-k;i++)
{cout<<max(right[i],left[i+k-1])<<" ";

}
}
int josephus(int n, int k)
{
  if (n == 1)
    return 1;
  else
    /* The position returned by josephus(n - 1, k) is adjusted because the
       recursive call josephus(n - 1, k) considers the original position 
       k%n + 1 as position 1 */
    return (josephus(n - 1, k) + k-1) % n + 1;
}
bool notunique(bool*a,char ch)
{if(a[ch-'A']==true)
return true;
return false;

}
int longestUniqueSubsttr(char*s)
{int start=0;int end=1;int n=strlen(s);bool a[26]={false};
	int max=1;int maxstart=0;a[0]=true;
	while(end<n)
	{
		if(notunique(a,s[end]))
		{while(s[start]!=s[end])
			{start++;

			}
			start++;
		}
			if(end-start+1>max)
				{max=end-start+1;
					maxstart=start;}

			a[s[end]-'A']=true;
			end=end+1;

		cout<<max<<" \n";

	}
	cout<<maxstart<<"dsf";
return max;

}
// Driver Program to test above function
int main()
{
   char str[] = "GEEKSFORGEEKS";
    printf("The input string is %s \n", str);
    int len =  longestUniqueSubsttr(str);
    printf("The length of the longest non-repeating character substring is %d", len);

  return 0;
}