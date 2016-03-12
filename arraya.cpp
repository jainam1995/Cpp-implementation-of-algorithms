#include <bits/stdc++.h>
using namespace std;
void majority(int *a,int n)
{int ans=a[0];int count =1;
	for(int i=1;i<n;i++)
	{if(a[n]==ans)
		{count++;}
		else count--;
		if(count==0)
			{ans=a[i];count=1;}
	}

 count=0;
for(int i=0;i<n;i++)
{if(a[i]==ans)
	count++;

}
if(count>n/2)
cout<<"Majority is "<<ans<<"\n";
else cout<<"No majority exists\n";

}
int maxsubarray(int*a,int n)
{int ans=a[0];int start=0;int maxstart=0;int max=a[0];
	for(int i=1;i<n;i++)
		{if(ans<0)
			{ans=a[i];
				start=i;

			}
			else{
				ans=ans+a[i];
				
			}
			if(ans>max)
					{max=ans;
						maxstart=start;}

		}
		cout<<maxstart<<"\n";
		return max;

}
int oddoccur(int *a,int n)
{int ans=0;
	for(int i=0;i<n;i++)
		ans=ans^a[i];
	return ans;

}
int findpivot(int *a,int l,int r)
{if(l>r)
	return -1;
	if(l==r)
		return l;
	int mid=l+(r-l)/2;
	if(mid<r&&a[mid]>a[mid+1])
		return mid;
	if(mid>l&&a[mid-1]>a[mid])
		return mid-1;
	if(a[l]>a[mid])
		return findpivot(a,l,mid-1);
	return findpivot(a,mid+1,r);



}
int bsearch(int *a,int l,int r,int key)
{if(l>r)
	return -1;
		
	int mid=l+(r-l)/2;
	if(a[mid]==key)
		return mid;
	if(key<a[mid])
		return bsearch(a,l,mid-1,key);
	return bsearch(a,mid+1,r,key);

}
int pivotedBinarySearch(int *a,int n,int data)
{int pivot=findpivot(a,0,n-1);
//if(a[pivot]==data)
	return pivot;
if(data>=a[0])
	return bsearch(a,0,pivot-1,data);
return bsearch(a,pivot+1,n-1,data);


}
int ceil(int *a,int l,int r,int k)
{
	if(k<=a[l])
	return a[l];
if(k>a[r])
	return -1;
int mid=l+(r-l)/2;
if(mid<r&&a[mid]<k&&a[mid+1]>=k)
	return a[mid+1];
if(mid>l&&a[mid-1]<k&&a[mid]>=k)
	return a[mid];
if(a[mid]<k)
	return ceil(a,mid+1,r,k);
return ceil(a,l,mid-1,k);


}
int floor(int *a,int l,int r,int k)
{if(k>=a[r])
	return a[r];
	if(k<a[l])
		return -1;
	int mid=l+(r-l)/2;
	if(mid<r&&a[mid]<=k&&a[mid+1]>k)
		return a[mid];
	if(mid>l&&a[mid]>k&&a[mid-1]<=k)
		return a[mid-1];
	if(a[mid]>k)
		return floor(a,l,mid-1,k);
	return floor(a,mid+1,r,k);

}

int findPeak(int *a,int l,int r)
{if(l>r)
	return -1;
	int mid=l+(r-l)/2;
	if(l+1==r&&a[l]>=a[r])
		return l;
	if(l+1==r&&a[l]<a[r])
		return r;
	if(a[mid]>=a[mid-1]&&a[mid]>=a[mid+1])
		return mid;
	if(a[mid-1]>a[mid])
		return findPeak(a,l,mid-1);
	else return findPeak(a,mid+1,r);

}
void moveToEnd(int *a,int n)
{int j=n-1;
	for(int i=n-1;i>=0;i--)
	{if(a[i]!=-1)
		{a[j--]=a[i];}

	}
	while(j>=0)
		{a[j]=0;
			j--;}

}
void merge(int *a,int *b,int m,int n)
{int h=0;int d=n;
	while(d--)
		h++;
	int i=0;
	int k=0;
	while(i<n&&h<m)
	{if(a[h]<=b[i])
		{a[k++]=a[h];h++;}
	else if(b[i]<a[h])
		{a[k++]=b[i];i++;}

	}
	while(h<m)
	{a[k++]=a[h];h++;

	}
	while(i<n)
	{a[k++]=b[i];i++;

	}


}
void printArray(int *a,int n)
{for(int i=0;i<n;i++)
	cout<<a[i]<<" ";

}
int max(int a,int b)
{if(a>b)
return a;
return b;}
int min(int a,int b)
{if(a<b)
	return a;
	return b;

}
int median(int arr[], int n)
{
    if (n%2 == 0)
        return (arr[n/2] + arr[n/2-1])/2;
    else
        return arr[n/2];
}
int getMedian(int *a,int *b,int n)
{if(n==1)
	return (a[0]+b[0])/2;
	if(n==2)
		return (max(a[0],b[0])+min(a[1],b[1]))/2;
	int m1=median(a, n);
	int m2=median(b, n);
	if (m1==m2)
		return m1;
	if(m1<m2)
	{if(n%2==0)
		{return getMedian(a+n/2-1,b,n/2+1);

		}
	else {
		return getMedian(a+n/2,b,n/2+1);
	}

	}
	if(m1>m2)
	{if(n%2==0)
		{return getMedian(a,b+n/2-1,n/2+1);

		}
	else {
		return getMedian(a,b+n/2,n/2+1);
	}

	}

}
void printUnion(int* a,int *b,int n,int m)
{int i=0;int j=0;
	while(i<n&&j<m)
	{if(a[i]<=b[j])
		cout<<a[i++]<<" ";
		else if(b[j]<a[i])
			cout<<b[j++]<<" ";

	}
	while(i<n)
		cout<<a[i++]<<" ";
	while(j<m)
		cout<<b[j++]<<" ";

}
void printIntersection(int *a,int *b,int n,int m)
{int i=0;int j=0;
	while(i<n&&j<m)
	{if(a[i]<b[j])
		i++;
		else if(b[j]<a[i])
			j++;
		else{
			cout<<a[i]<<" ";i++;j++;
		}


	}

}
void reverse(int *a,int l,int r)
{int temp;
	while(l<r)
	{temp=a[l];
		a[l]=a[r];
		a[r]=temp;
		l++;r--;

	}

}
void leftRotate(int *a,int k,int n)
{reverse(a,0,k-1);
	reverse(a,k,n-1);
	reverse(a,0,n-1);

}
int FindMaxSum(int *a,int n)
{int ans[n];
	ans[0]=a[0];
	ans[1]=max(a[0],a[1]);
	for(int i=2;i<n;i++)
		ans[i]=max(ans[i-1],ans[i-2]+a[i]);
	return ans[n-1];

}

void sortbyfreq(int *a,int n)
{map<int,int> hash;
	for(int i=0;i<n;i++)
	{if(hash.find(a[i])==hash.end())
		hash[a[i]]=1;
		else hash[a[i]]++;

	}
	cout<<hash[2];
int b[n];int j=0;
for(int i=0;i<n;i++)
{if(hash.find(a[i])!=hash.end())
	{int p=hash[a[i]];
		while(p--)
			b[j++]=a[i];
		hash.erase(a[i]);

	}

}
a=b;

}
void merge(int *a,int l,int mid,int r,int *ans,int *count)
{int i=l;
	int j=mid+1;
	int k=l;
	while(i<=mid&&j<=r)
	{if(a[i]<=a[j])
		ans[k++]=a[i++];
	else{
		*count+=mid-i+1;
		ans[k++]=a[j++];
	}
	}
	while(i<=mid)
		ans[k++]=a[i++];
	while(j<=r)
		ans[k++]=a[j++];
	for(int h=l;h<=r;h++)
		a[h]=ans[h];


}
void mergeSortutil(int *a,int l,int r,int *count,int *ans)
{if(l>=r)
	return;
	int mid=l+(r-l)/2;
	mergeSortutil(a,l,mid,count,ans);
	mergeSortutil(a,mid+1,r,count,ans);
	merge(a,l,mid,r,ans,count);

}
int  mergeSort(int *a,int n)
{int count=0;int ans[n];
	int l=0;int r=n-1;
	mergeSortutil(a,l,r,&count,ans);
	return count;

}
int abs(int a)
{if(a>=0)
	return a;
	return -a;

}
void minAbsSumPair(int *a,int n)
{sort(a,a+n);
	int first=0;int last=n-1;
	int ans=abs(a[first]+a[last]);
int l=0;int r=n-1;
while(l<r)
{if(abs(a[l]+a[r])<ans)
	{ans=abs(a[l]+a[r]);
		first=l;
		last=r;

	}
	if(a[l]+a[r]<0)
		l++;
	else r--;

}
cout<<ans<<" "<<a[first]<<" "<<a[last]<<"\n" ;
}
void print2Smallest(int *a,int n)
{int smallest;int ssmallest;
	if(a[0]<a[1])
		{smallest=a[0];ssmallest=a[1];}
	else{smallest=a[1];ssmallest=a[0];}
	for(int i=2;i<n;i++)
	{if(a[i]<smallest)
		{ssmallest=smallest;
			smallest=a[i];}

	
	else if(a[i<ssmallest])
		ssmallest=a[i];
	}
cout<<smallest<<" "<<ssmallest;
}
struct pairs
{int min;
	int max;

};
struct pairs getMinMax(int *a,int n)
{struct pairs mm;int k;
	if(n%2!=0)
		{mm.min=a[0];
	mm.max=a[0];
	k=1;}
	else {
		mm.min=min(a[0],a[1]);
		k=2;
		mm.max=max(a[0],a[1]);
	}
	for(int i=k;i<n;i=i+2)
	{int g=a[i];int h=a[i+1];
		if(a[i]<=a[i+1])
		{if(a[i]<mm.min)
			mm.min=a[i];
			if(a[i+1]>mm.max)
				mm.max=a[i+1];

		}
		else {
			if(a[i+1]<mm.min)
				mm.min=a[i+1];
			if(a[i]>mm.max)
				mm.max=a[i];
		}

	}


return mm;

}

void segregate012(int *a,int n)
{int l=0;int mid=0;int r=n-1;
	while(mid<=r)
	{if(a[mid]==1)
		mid++;
		else if(a[mid]==0)
		{int temp=a[l];
			a[l]=a[mid];
			a[mid]=temp;
			l++;
			mid++;

		}else {
			int temp=a[r];
			a[r]=a[mid];
			a[mid]=temp;
			r--;
		}

	}

}
void printRepeating(int *a,int n)
{for(int i=0;i<n;i++)
	{if(a[abs(a[i])]>0)
		a[abs(a[i])]=-a[abs(a[i])];
		else cout<<abs(a[i])<<" ";

	}


}
void printNGE(int* a,int n)
{stack<int> s;
	s.push(a[0]);
	for(int i=1;i<n;i++)
		{while(!s.empty()&&a[i]>s.top())
			{int t=s.top();
				s.pop();
				cout<<t<<" --- "<<a[i]<<endl;

			}

			s.push(a[i]);
		}

while(!s.empty())
{int t=s.top();
	s.pop();
	cout<<t<<" --- "<<-1<<endl;

}
}
bool areConsecutive(int *a,int n)
{map<int,bool>hash;int min=INT_MAX;int max=INT_MIN;
	for(int i=0;i<n;i++)
	{if(a[i]<min)
		min=a[i];
		if(a[i]>max)
			max=a[i];
		if(hash.find(a[i])!=hash.end())
		return false;
		hash[a[i]]=true;

	}
if(max-min+1==n)
	return true;
return false;

}
int firstoccur(int *a,int x,int l,int r)
{if(l>r)
	return -1;
	if(l==r&&a[l]==x)
		return l;
	if(a[l]==x)
		return l;
	int mid=l+(r-l)/2;
	if(mid>l&&a[mid-1]!=x&&a[mid]==x)
		return mid;
	if(mid<r&&a[mid]!=x&&a[mid+1]==x)
		return mid+1;
 if(a[mid]>=x)
 	return firstoccur(a,x,l,mid-1);
 else return firstoccur(a,x,mid+1,r);

}
int lastoccur(int *a,int x,int l,int r)
{if(l>r)
	return -1;
	if(a[r]==x)
		return r;
	if(l==r&&a[l]==x)
		return l;
	int mid=l+(r-l)/2;
	//cout<<mid<<" ";
	if(mid>l&&a[mid-1]==x&&a[mid]!=x)
		return mid-1;
	if(mid<r&&a[mid]==x&&a[mid+1]!=x)
		return mid;
	if(a[mid]<=x)
		return lastoccur(a,x,mid+1,r);
	return lastoccur(a,x,l,mid-1);

}
int count(int *a,int x,int n)
{int first=firstoccur(a,x,0,n-1);
	int second=lastoccur(a,x,0,n-1);
	if(first==-1)
		return 0;
	cout<<first<<" "<<second<<"\n"; 
	return second-first+1;

}
int mins(int a,int b)
{if(a<b)
	return a;
	return b;


}
int maxs(int a,int b)
{if(a>b)
	return a;
	return b;

}
int maxIndexDiff(int *a,int n)
{int min[n];
	int max[n];
	min[0]=a[0];
	for(int i=1;i<n;i++)
		min[i]=mins(min[i-1],a[i]);
	
	max[n-1]=a[n-1];
	for(int i=n-2;i>=0;i--)
		max[i]=maxs(max[i+1],a[i]);

	int ans=-1;
	int i=0;int j=0;
	while(i<n&&j<n)
	{if(max[j]>min[i])
		{if(j-i>ans)
			ans=j-i;
			cout<<ans<<" ";
			j++;

		}
		else i++;

	}
return ans;
}
int minDist(int *a,int n,int x,int y)
{int i;
	for( i=0;i<n;i++)
	{if(a[i]==x||a[i]==y)
		break;

	}
	int min=INT_MAX;
	int prev=i;
int first=a[i];
for(;i<n;i++)
{if(a[i]==x||a[i]==y)
	{if(a[i]!=first)
		{if(i-prev<min)
			min=i-prev;
		}
		first=a[i];
		prev=i;


	}

}
return min;
}
void printTwoElements(int *a,int n)
{for(int i=0;i<n;i++)
	{if(a[abs(a[i])-1]>0)
		a[abs(a[i])-1]=-a[abs(a[i])-1];
		else cout<<"repaeating "<<abs(a[i])<<"\n";

	}
	for(int i=0;i<n;i++)
	{if(a[i]>0)
		cout<<"Missing "<<i+1<<"\n";

	}

}
int binarySearch(int *a,int l,int r)
{if(l>r)
	return -1;
	int mid=l+(r-l)/2;cout<<mid<<" ";
	if(a[mid]==mid)
		return mid;
	if(a[mid]>mid)
		return binarySearch(a,l,mid-1);
	return binarySearch(a,mid+1,r);

}
int findMaximum(int *a,int l,int r)
{if(l>r)
	return -1;
	int mid=l+(r-l)/2;
	
	if(l+1==r&&a[l]>a[r])
		return a[l];
	if(l+1==r&&a[r]>a[l])
		return a[r];
	if(a[mid]>a[mid-1]&&a[mid]>a[mid+1])
		return a[mid];
	
	if(a[mid]<a[mid+1])
		return findMaximum(a,mid+1,r);
	return findMaximum(a,l,mid-1);

}
int minJumps(int *a,int l,int r)
{if(a[0]==0)
	return INT_MAX;
	int n=r+1;
	int ans[r+1];
	for(int i=0;i<n;i++)
		ans[i]=INT_MAX;
	ans[0]=0;
	for(int i=0;i<n;i++)
	{for(int j=0;j<i;j++)
		{if(ans[j]!=INT_MAX&&(a[j]+j>=i)&&(ans[j]+1<ans[i]))
			ans[i]=ans[j]+1;

		}

	}
return ans[r];
}
int bitonic(int *a,int n)
{int ans[n];
	ans[0]=1;
	for(int i=1;i<n;i++)
	{if(a[i]>a[i-1])
		ans[i]=ans[i-1]+1;
		else ans[i]=1;

	}
	for(int i=n-2;i>=0;i--)
	{if(a[i]>a[i+1])
		a[i]+=1;


	}
	int max=ans[0];
for(int i=1;i<n;i++)
{if(ans[i]>max)
	max=ans[i];

}
return max;
}
void subArraySum(int *a,int n,int k)
{int start=0;int sum=a[0];int end=1;
	while(end<=n)
	{while(sum>k)
		{sum=sum-a[start];
			start++;

		}
		if(sum==k)
		{cout<<start<<" "<<end-1<<" ";

		}
		if(end<n)
			sum=sum+a[end];
		end++;


	}

}
void find3Numbers(int *a,int n,int sum)
{sort(a,a+n);
	for(int i=0;i<n;i++)
	{int l=i+1;int r=n-1;
		while(l<r)
		{if(a[i]+a[l]+a[r]==sum)
			{cout<<a[i]<<" "<<a[l]<<" "<<a[r]<<"\n";l++;r--;}
			else if(a[i]+a[l]+a[r]<sum)
				l++;
			else r--;

		}

	}

}
void printTwoOdd(int *a,int n)
{int ans=0;
	for(int i=0;i<n;i++)
		ans=ans^a[i];
	int k ;
	for( k=0;k<31;k++)
		{if(ans^(1<<k))
			break;}
			int setbit=1<<k;
			int one=0;int two=0;
			for(int i=0;i<n;i++)
			{if(a[i]^setbit)
				one=one^a[i];
				else two=two^a[i];

			}
cout<<one<<" "<<two;
}
void findSubArray(int *a,int n)
{int sum[n];
	for(int i=0;i<n;i++)
	{if(a[i]==0)
		a[i]=-1;

	}
	int start;int end;
sum[0]=a[0];
for(int i=1;i<n;i++)
sum[i]=sum[i-1]+a[i];
for(int i=0;i<n;i++)
cout<<sum[i]<<" d";
int max=0;
for(int i=n-1;i>=0;i--)
{if(sum[i]==0)
	{max=i+1;start=0;end=i;cout<<max<<"\n";break;}

}
map<int ,int > hash;
for(int i=0;i<n;i++)
{
	if(hash.find(sum[i])==hash.end())
	hash[sum[i]]=i;
else {
	if(i-hash[sum[i]]+1>max)
		{max=i-hash[sum[i]]+1;start=hash[sum[i]];end=i;
			cout<<max<<"\n";}
}
}
cout<<max<<" "<<start<<" "<<end;
}
struct petrolPump{
	int petrol;
	int dist;
};
int printTour(int *a,int n)
{int start=0;int curr=a[0];int sum=a[0];
	for(int i=1;i<n;i++)
	{if(curr<0)
		{start=i;curr=a[i];

		}
		else curr=curr+a[i];
		sum=sum+a[i];

	}
	if(sum<0)
		return -1;
	return start;

}
int printTour2(int *a,int n)
{int start=0;int end=1;
	int curr=a[0];
	while(curr<0||start<end)
	{while(curr<0&&start<end)
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
bool compare(const string& s1,const string& s2)
{string s3=s1+s2;
	string s4=s1+s2;
	if(s3>=s4)
		return 1;
	return 0;

}
void printLargest(vector<string>&a)
{sort(a.begin(),a.end(),compare);
	vector<string>::iterator i;
	for(i=a.begin();i!=a.end();i++)
		cout<<*i;


}
bool issumutil(int *a,int n,int ans,int sum,int i)
{if(ans==sum)
	return true;
	if(i>=n)
		return false;
	ans=ans+a[i];
	if(ans==sum)
		return true;
	return issumutil(a,n,ans,sum,i+1)||issumutil(a,n,ans-a[i],sum,i+1);


}
bool issum(int *a,int n,int sum)
{int ans=0;int i=0;
	return issumutil(a,n,ans,sum,i);

}
bool tugOfWar(int *a,int n)
{int sum=0;
	for(int i=0;i<n;i++)
		sum=sum+a[i];
	cout<<sum<<"\n";
	if(sum&1)
		return false;
	if(issum(a,n,sum/2))
		return true;
	return false;
}
 
int maxRepeating(int *a,int n,int k)
{for(int i=0;i<n;i++)
	{a[a[i]%k]+=k;

	}
	int max=INT_MIN;
	int maxindex=0;
	for(int i=0;i<n;i++)
	{if(a[i]/k>max)
		{max=a[i]/k;
			maxindex=i;

		}

	}
cout<<max<<" ";
return maxindex;
}
void stockBuySell(int *a,int n)
{int min=a[0];int ans=0;
	for(int i=1;i<n;i++)
	{if(a[i]>min)
		{ans=ans+a[i]-min;min=a[i];}
		else if(a[i]<min)
			min=a[i];

	}
if(ans==0)
	cout<<"Not possible\n";
else cout<<ans<<"\n";
}
void rearrange(int *a,int n)
{int l=0;int r=n-1;
	while(l<r)
	{while(a[l]<0&&l<r)
		l++;
		while(a[r]>0&&r>l)
			r--;
		if(l<r)
		{int temp=a[l];
			a[l]=a[r];
			a[r]=temp;
			l++;r--;
		}


	}
	int i;
for( i=0;i<n;i++)
{if(a[i]>0)
	break;

}
int neg=0;int pos=i;
while(neg<pos&&a[neg]<0&&pos<n)
{int temp=a[pos];
	a[pos]=a[neg];
	a[neg]=temp;
	neg=neg+2;pos++;

}
}
void pushZerosToEnd(int *a,int n)
{
int j=0;
for(int i=0;i<n;i++)	
{if(a[i]!=0)
	a[j++]=a[i];

}
for(;j<n;j++)
a[j]=0;

}
int smallestSubWithSum(int *a,int n,int x)
{int curr=a[0];int start=0;int end=1;int min=INT_MAX;
	while(end<=n)
	{while(curr>x)
		{if(end-start<min)
			{min=end-start;
			}

			curr-=a[start];
			start++;

		}
		if(end<n)
			curr=curr+a[end];
		end++;


	}
return min;
}
int partirion(int *a,int l,int r)
{int j=l-1;
int i=l;
int pivot=a[r];
while(i<r)
{while(a[i]>pivot&&i<r)
	i++;
	if(a[i]<=pivot&&i<r)
	{j++;
		int temp=a[i];
		a[i]=a[j];
		a[j]=temp;
		i++;

	}
	

}
j++;
	int temp=a[r];
	a[r]=a[j];
	a[j]=temp;
	return j;

}
void kthSmallest(int *a,int l,int r)
{if(l>=r)
	return;
	int pivot=partirion(a,l,r);
	
		kthSmallest(a,pivot+1,r);
	 kthSmallest(a,l,pivot-1);

}
int maxOnesIndex(int *a,int n)
{int previndex=-1;int prevprevindex=-1;int curr=0;int max=INT_MIN;int maxindex=0;
	while(curr<n)
	{if(a[curr]==0)
		{if(curr-prevprevindex>max)
			{max=curr-prevprevindex;
				maxindex=previndex;

			}
			prevprevindex=previndex;
			previndex=curr;

		}curr++;

	}
if(curr-prevprevindex>max)
	maxindex=previndex;
return previndex;

}
void printClosest(int *a,int *b,int m,int n,int x)
{reverse(b,0,m-1);
	int i=0;int j=0;int min=INT_MAX;int first=0;int second=0;
	while(i<n&&j<m)
		{if(abs(a[i]+b[j]-x)<min)
			{first=a[i];second=b[j];min=abs(a[i]+b[j]-x);

			}
			if(a[i]+b[j]>x)
				j++;
			else i++;

		}
cout<<first<<" "<<second;
}
void sortAccording(int *a,int *b,int m,int n)
{int temp[m];
	int first;
	int last;
for(int i=0;i<m;i++)
temp[i]=a[i];
sort(temp,temp+m);

bool visited[m];
for(int i=0;i<m;i++)
	visited[i]=false;
int count=0;
for(int i=0;i<n;i++)
{first=firstoccur(temp,b[i],0,m-1);
	if(first!=-1)
	{last=lastoccur(temp,b[i],0,m-1);


	}
	if(first!=-1&&visited[first]==false)
	{for(int j=first;j<=last;j++)
		visited[j]=true;
		int num=last-first+1;
		while(num--)
		{a[count++]=temp[first];
			//cout<<a[count-1]<<" ";

		}

	}
	for(int k=0;k<m;i++)
	{if(visited[k]==false)
		a[count++]=temp[k];

	}

}


}
int maxi(int a,int b)
{if(a>b)
	return a;
	return b;

}
int maxProfit(int *a,int n)
{int ans[n];int max=a[n-1];ans[n-1]=0;
	for(int i=n-2;i>=0;i--)
	{ans[i]=maxi(ans[i+1],max-a[i]);
		if(a[i]>max)
			max=a[i];

	}
	cout<<ans[0];
	int min=a[0];
	for(int i=1;i<n;i++)
	{ans[i]=maxi(ans[i-1],ans[i]+a[i]-min);
		if(a[i]<min)
			min=a[i];

	}
return ans[n-1];
}
int maxPathSum(int *a,int *b,int m,int n)
{int sum1=0;int sum2=0;int i=0;int j=0;int sum=0;
	while(i<n&&j<m)
	{if(a[i]<b[j])
		{sum1=sum1+a[i];
			i++;

		}
		else if(b[j]<a[i])
		{sum2=sum2+b[j];
			j++;

		}
		else{
			if(sum1>=sum2)
				sum=sum+sum1;
			else sum=sum+sum2;
			
			sum1=a[i];sum2=b[j];
			i++;j++;
		}

	}
	while(i<n)
	{sum1=sum1+a[i];
		i++;

	}
	while(j<m)
		{sum2=sum2+b[j];}
	if(sum1>=sum2)
		sum=sum+sum1;
	else sum=sum+sum2;

	return sum;

}
bool checkDuplicatesWithinK(int *a,int k,int n)
{map<int ,bool> hash;
	for(int i=0;i<n;i++)
	{if(hash.find(a[i])!=hash.end())
		{cout<<a[i];return true;}
		hash[a[i]]=true;
		if(i>=k-1)
		{hash.erase(hash.find(a[i-(k-1)]));

		}

	}
return false;
}
int rowWithMax1s(int a[4][4])
{int max=3;int maxans=0;
	for(int i=0;i<4;i++)
	{while(max>=0 && a[i][max]==1)
		{max--;
			maxans=i;}

	}

return maxans;
}
void rev(string& s,int l,int r)
{while(l<r)
	{char ch=s[l];
		s[l]=s[r];
		s[r]=ch;
		l++;r--;

	}

}
void reverse(string& s)
{int l=0;int r=s.size()-1;
	stack<int>ss;
	//ss.push(0);
	while(l<s.size()-1)
	{ss.push(l);
		while(s[l+1]!=' '&&s[l+1]!='\0')
	l++;
	ss.push(l);
	l++;
	if(s[l]=='\0')
		break;
	while(s[l]==' ')
		l++;

	}int first;int second;
	while(!ss.empty())
	{first=ss.top();ss.pop();second=ss.top();ss.pop();
		for(int i=second;i<=first;i++)
			cout<<s[i];
		cout<<" ";

	}

}
bool compares(string a,string b)
{if(a<b)
	return 0;
	return 1;

}
void calculateSpan(int *a,int n,int* s)
{stack<int >h;
	for(int i=0;i<n;i++)
	{
	while(!h.empty())
	{int p= h.top();
		if(a[i]>=a[p])
			h.pop();
		else{ break;}

	}

	if(h.empty())
		s[i]=i+1;
else s[i]=i-h.top();
h.push(i);
}

}
struct pla{
	int data;
	int  aod;
};
int findPlatform(int *a,int *d,int n)
{struct pla ans[2*n];int i=0;int j=0;int k=0;
	while(i<n&&j<n)
	{if(a[i]<=d[j])
		{ans[k].data=a[i];ans[k].aod=0;k++;i++;}
		else {
			ans[k].data=d[j];ans[k].aod=1;k++;j++;
		}

	}
while(i<n)
{ans[k].data=a[i];
	ans[k].aod=0;
	i++;k++;

}
while(j<n)
{ans[k].data=d[j];
	ans[k].aod=1;
	j++;k++;

}
int max=0;int curr=0;
for(int i=0;i<2*n;i++)
{if(ans[i].aod==0)
	{curr++;
		if(curr>max)
			max=curr;

	}
	else curr--;

}
return max;
}
bool issafe(int x,int y)
{if(x>=0&&x<8&&y>=0&&y<8)
	return true;
	return false;	

}
void floodFillutil(int a[8][8],int x,int y,int old,int news)
{a[x][y]=news;
	if(issafe(x-1,y)&&a[x-1][y]==old)
		floodFillutil(a,x-1,y,old,news);
	if(issafe(x,y-1)&&a[x][y-1]==old)
		floodFillutil(a,x,y-1,old,news);
	if(issafe(x+1,y)&&a[x+1][y]==old)
		floodFillutil(a,x+1,y,old,news);
	if(issafe(x,y+1)&&a[x][y+1]==old)
		floodFillutil(a,x,y+1,old,news);


}

void floodFill(int a[8][8],int x,int y,int news)
{int old=a[x][y];
	floodFillutil(a,x,y,old,news);

}
void printSequtil(int n,int *ans,int k,int len,int i)
{if(len==k)
	{for(int j=0;j<k;j++)
		cout<<ans[j]<<" ";
		cout<<endl;
		return;
	}
	if(i>n)
		return;
ans[len]=i;
printSequtil(n,ans,k,len+1,i+1);
printSequtil(n,ans,k,len,i+1);
}
void printSeq(int n,int k)
{int ans[k];int len=0;int i=1;
	printSequtil(n,ans,k,len,i);


}
bool isSubSequence(char*a,char*b,int m,int n)
{int i=0;int j=0;
	while(i<m&&j<n)
	{if(a[i]==b[j])
		{i++;j++;

		}
		else j++;

	}
if(i<m)
	return false;
return true;
}
void generatebper(int *ans,int zeros,int ones,int len,int n)
{if(len==n)
	{for(int i=0;i<n;i++)
		cout<<ans[i]<<" ";
		cout<<endl;
		return;

	}
	if(zeros==ones)
		{ans[len]=1;generatebper(ans,zeros,ones+1,len+1,n);}
	else{
		ans[len]=1;generatebper(ans,zeros,ones+1,len+1,n);
		ans[len]=0;
		generatebper(ans,zeros+1,ones,len+1,n);

	}

}
void generatebper(int n)
{int ans[n];
	int ones=0;int zeros=0;int len=0;
	generatebper(ans,zeros,ones,len,n);


}
int partition(char a[],int l,int r,int pivot)
{int j=l-1;
	int i=l;
	while(i<=r)
	{while(a[i]>pivot&&i<=r)
		i++;
		if(i<=r&&a[i]<=pivot)
		{j++;
			char temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			i++;

		}

	}
	int k;
	for(k=l;k<=j;k++)
	{if(a[k]==pivot)
		break;

	}
	char temp=a[k];
	a[k]=a[j];
	a[j]=temp;
return j;
}
void nutsbolts(char a[],char b[],int l,int r)
{if(l>=r)
	return;
	int pivot=partition(a,l,r,b[r]);
	partition(b,l,r,a[pivot]);
	nutsbolts(a,b,l,pivot-1);
	nutsbolts(a,b,pivot+1,r);

}
void printCompositionsutil(int *a,int len,int n,int sum)
{if(sum==0)
	{for(int i=0;i<len;i++)
		cout<<a[i]<<" ";
		cout<<endl;
		return;

	}
	if(sum<0)
		return;
	if(sum>=1)
	{a[len]=1;
		printCompositionsutil(a,len+1,n,sum-1);

	}
	if(sum>=2)
	{a[len]=2;
		printCompositionsutil(a,len+1,n,sum-2);


	}
	if(sum>=3)
	{a[len]=3;
		printCompositionsutil(a,len+1,n,sum-3);

	}

}
void printCompositions(int n)
{int a[5];int len=0;int sum=5;
	printCompositionsutil(a,len,n,sum);

}
int countWays(int s,int m)
{int ans[s+1];
	//for(int i=0;i<=s;i++)
		
	ans[0]=1;
	ans[1]=1;
	for(int i=2;i<=s;i++)
	{ans[i]=0; 	
		for(int j=1;j<=m;j++)
		{if((i-j)>=0){ans[i]+=ans[i-j];}


		}

	}
	return ans[s];

}
int countDecoding(char* a,int n)
{int ans[n];
	ans[0]=1;
	//ans[1]=1;
	for(int i=1;i<n;i++)
	{ans[i]=0;
		if(a[i]>='0'&&a[i]<='9')
		{ans[i]+=ans[i-1];
			if((a[i-1]<='1'||(a[i-1]=='2'&&a[i]<='7'))&&(i-2>=0))
			ans[i]+=ans[i-2];

		}

	}
return ans[n-1];
}
int maxim(int a,int b)
{if(a>b)
	return a;
	return b;

}
void printKMax(int *a,int n,int k)
{int max[n];int min[n];
	for(int i=0;i<n;i++)
	{if((i%k)==0)
		min[i]=a[i];
		else min[i]=maxim(min[i-1],a[i]);

	}
	max[n-1]=a[n-1];
for(int i=n-2;i>=0;i--)
{if(i%k==k-1)
	max[i]=a[i];
	else max[i]=maxim(a[i],max[i+1]);

}
int ans[n-k+1];
for(int i=0;i<=n-k;i++)
{ans[i]=maxim(max[i],min[i-1+k]);
cout<<ans[i]<<" ";
}

}
struct node{
int capacity;
int top;
int *a;

};
struct node*newStack(int capacity)
{struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->capacity=capacity;
	temp->top=-1;
	temp->a=(int *)malloc(sizeof(int )*capacity);
	return temp;

}
void push(struct node* temp,int data)
{if(temp->top==temp->capacity-1)
	return;
	(temp->top)++;
	temp->a[temp->top]=data;

}bool isempty(struct node* temp)
{if((temp->top)==-1)
	return true;
	return false;

}
int pop(struct node* temp)
{if(temp->top==-1)
	return -1;
	int t=temp->a[temp->top];
	(temp->top)--;
	return t;

}
void sortedinsert(struct node*& temp,int x)
{if(isempty(temp)||x>temp->a[temp->top])
	{push(temp,x);
		return;
	}
	else{
		int data=pop(temp);
		sortedinsert(temp,x);
		push(temp,data);


	}

}
void revstack(struct node*& temp)
{if(isempty(temp))
	return;
	int x=pop(temp);
	revstack(temp);
	sortedinsert(temp,x);

	
}
void pushatbottom(struct node*& temp,int x)
{if(isempty(temp))
	{push(temp,x);
		return;


	}
	int data=pop(temp);
	pushatbottom(temp,x);
	push(temp,data);

}
void rev(struct node*& temp)
{if(isempty(temp))
	return;
	int x=pop(temp);
	rev(temp);
	pushatbottom(temp,x);

}int catalan(int n)
{if(n==0||n==1	)
	return 1;
	int ans[n+1];
	for(int i=0;i<=n;i++)
		ans[i]=0;

	ans[0]=1;
	ans[1]=1;

	for(int i=2;i<=n;i++)
	{for(int j=0;j<i;j++)
		ans[i]+=ans[j]*ans[i-j-1];

	}
return ans[n];
}
int lis(int *a,int n)
{
	int ans[n];
	for(int i=0;i<n;i++)
		ans[i]=1;
	for(int i=0;i<n;i++)
	{for(int j=0;j<i;j++)
		{if(a[i]>a[j]&&ans[j]+1>ans[i])
			ans[i]=ans[j]+1;

		}

	}int max=ans[0];
	for(int i=0;i<n;i++)
	{if(ans[i]>max)
		max=ans[i];

	}
	return max;
}
int lcs(char a[],char b[],int m,int n)
{int ans[m+1][n+1];
	for(int i=0;i<=m;i++)
	{ans[i][0]=0;

	}
	for(int i=0;i<=n;i++)
	{ans[0][i]=0;

	}
	for(int i=1;i<=m;i++)
	{for(int j=1;j<=n;j++)
		{if(a[i-1]==b[j-1])
			ans[i][j]=1+ans[i-1][j-1];
			else ans[i][j]=maxim(ans[i-1][j],ans[i][j-1]);
		}

	}
int i=m;int j=n;
string s="";
while(i>=1&&j>=1)
{if(a[i-1]==b[j-1])
	{s=s+a[i-1];
		i--;j--;

	}
	else if(ans[i-1][j]>=ans[i][j-1])
		i--;
	else j--;

}
int l=0;int r=s.size()-1;
while(l<r)
{char c=s[l];
	s[l]=s[r];
	s[r]=c;
	l++;r--;


}
cout<<s<<" ";
return ans[m][n];
}
int max3(int a,int b,int c)
{int max=a;
	if(b>max)
		max=b;
	if(c>max)
		max=c;
	return max;

}
int EditDistanceDP(char* a,char*b)
{int m=strlen(a);
int n=strlen(b);
int ans[m+1][n+1];
for(int i=0;i<=m;i++)
{ans[i][0]=0;

}
for(int i=0;i<=n;i++)
{ans[0][i]=0;

}
for(int i=1;i<=m;i++)
{for(int j=1;j<=n;j++)
	{if(a[i-1]==b[j-1])
		ans[i][j]=ans[i-1][j-1];

	
	else {
		ans[i][j]=max3(ans[i-1][j],ans[i][j-1],ans[i-1][j-1]+1);
	}
	}

}
return ans[m][n];
}
int min3(int a,int b,int c)
{int min=b;
	if(a<min)
		min=a;
	if(c<min)
		min=c;
return min;
}
int minCost(int a[3][3],int m,int n)
{int ans[3][3];ans[0][0]=a[0][0];
	for(int i=1;i<=n;i++)
	{ans[0][i]=a[0][i]+ans[0][i-1];

	}
	for(int i=1;i<=m;i++)
	{ans[i][0]=a[i][0]+ans[i-1][0];

	}
	for(int i=1;i<=m;i++)
	{for(int j=1;j<=n;j++)
		{ans[i][j]=min3(ans[i-1][j],ans[i-1][j-1],ans[i][j-1])+a[i][j];

		}

	}
return ans[m][n];

}
int counts(int *a,int m,int n )
{int ans[n+1][m];
	for(int i=0;i<m;i++)
	{ans[0][i]=1;

	}
	for(int i=1;i<=n;i++)
	{for(int j=0;j<m;j++)
		{	ans[i][j]=0;	
			if(j>=1)
			ans[i][j]+=ans[i][j-1];
			if(a[j]<=i)
			{
				ans[i][j]+=ans[i-a[j]][j];
				

			}

		}

	}

return ans[n][m-1];
}
int binomialCoeff(int n,int k)
{int ans[n+1][k+1];
	
	
	for(int i=0;i<=n;i++)
	{for(int j=0;j<=min(k,i);j++)
		{if(i==j||j==0)
			ans[i][j]=1;
			else 
		ans[i][j]=(ans[i-1][j]+ans[i-1][j-1]);}
	}
return ans[n][k];
}

int lps(char *s)
{int n=strlen(s);
	int ans[n][n];
	for(int i=0;i<n;i++)
		ans[i][i]=1;
	for(int len=2;len<=n;len++)
	{for(int i=0;i<=n-len;i++)
		{int j=i+len-1;
			if(s[i]==s[j]&&len==2)
				ans[i][j]=2;
			else if(s[i]==s[j])
				ans[i][j]=2+ans[i+1][j-1];
			else ans[i][j]=maxi(ans[i][j-1],ans[i+1][j]);
		}

	}
return ans[0][n-1];
}
int cutRod(int *a,int n)
{int ans[n];
	for(int i=0;i<n;i++)
		ans[i]=a[i];
	for(int i=1;i<n;i++)
	{for(int j=0;j<i;j++)
		{if(ans[j]+a[i-j-1]>ans[i])
			ans[i]=ans[j]+a[i-j-1];

		}

	}
return ans[n-1];
}
int maxSumIS(int *a,int n)
{int ans[n];
	for(int i=0;i<n;i++)
		ans[i]=a[i];
	int max=INT_MIN;
	for(int i=1;i<n;i++)
	{for(int j=0;j<i;j++)
		{if(a[j]<a[i]&&ans[j]+a[i]>ans[i])
			{ans[i]=ans[j]+a[i];
			 if(ans[i]>max)
			 	max=ans[i];}

		}

	}
return max;
}
int lbs(int *a,int n)
{int first[n];int second[n];
for(int i=0;i<n;i++)
	{first[i]=1;second[i]=1;}
for(int i=1;i<n;i++)
{for(int j=0;j<i;j++)
	if(a[j]<a[i]&&first[j]+1>first[i])
		first[i]=first[j]+1;

}
for(int i=n-2;i>=0;i--)
{for(int j=n-1;j>i;j--)
	{if(a[i]>a[j]&&second[j]+1>second[i])
		second[i]=second[j]+1;

	}

}
int max=INT_MIN;
for(int i=0;i<n;i++)
{if(first[i]+second[i]-1>max)
	max=first[i]+second[i]-1;

}
return max;
}

int minJumpss(int *a,int l,int r)
{if(r==0)
	return 0;
	int n=r+1;
	if(a[0]==0)
		return INT_MAX;
	int ans[n];
	ans[0]=0;
	for(int i=1;i<n;i++)
		ans[i]=INT_MAX;
	for(int i=1;i<n;i++)
	{for(int j=0;j<i;j++)
		{if(ans[j]!=INT_MAX&&j+a[j]>=i)
			{ans[i]=ans[j]+1;
				break;

			}

		}

	}
return ans[n-1];

}
struct pairss{
	int a;int b;
};
int maxChainLength(struct pairss a[],int n)
{int ans[n];ans[0]=1;int max=-1;
	for(int i=1;i<n;i++)
	{ans[i]=1;
		for(int j=0;j<i;j++)
		{if(a[i].a>a[j].b&&ans[j]+1>ans[i])
			{ans[i]=ans[j]+1;
				if(ans[i]>max)
					max=ans[i];}

		}

	}
return max;
}
int longestPalSubstr(char *s)
{int n=strlen(s);
	int ans[n][n];
	for(int i=0;i<n;i++)
	{for(int j=0;j<n;j++)
		ans[i][j]=1;

	}
	int max=1;

	for(int len=2;len<=n;len++)
	{for(int i=0;i<=n-len;i++)
		{int j=i+len-1;
			if(len==2&&s[i]==s[j])
			{ans[i][j]=1;
				max=len;

			}else if(s[i]!=s[j])
				ans[i][j]=0;
				else if(s[i]==s[j])
				{ans[i][j]=ans[i+1][j-1];if(ans[i][j]==1)max=len;}			

		}

	}
return max;
}
int countWayss(int s,int m)
{bool ans[s+1];
	ans[0]=1;ans[1]=1;
	for(int i=2;i<=s;i++)
	{ans[i]=0;
		for(int j=1;j<=m;j++)
		{if(i-j>=0)
			ans[i]+=ans[i-j];

		}

	}
return ans[s];
}
int minPalPartion(char s[])
{int n=strlen(s);
	int ans[n][n];
	for(int i=0;i<n;i++)
	{for(int j=0;j<n;j++)
		ans[i][j]=0;

	}
	for(int i=0;i<n;i++)
	ans[i][i]=1;
	for(int len=2;len<=n;len++)
	{for(int i=0;i<=n-len;i++)
		{int j=i+len-1;
			if(len==1)
			{ans[i][j]=1;


			}
			else if(len==2)
			{ans[i][j]=(s[i]==s[j]);

			}
			else {
				if(s[i]!=s[j])
					ans[i][j]=0;
				else ans[i][j]=ans[i-1][j+1];
			}

		}

	}
for(int i=0;i<n;i++)
	cout<<ans[0][i]<<" ";
int c[n];
for(int i=0;i<n;i++)
{if(ans[0][i]==1)
	c[i]=0;
	else{
		c[i]=INT_MAX;
		for(int j=0;j<i;j++)
		{if(ans[j+1][i]&&c[j]+1<c[i])
			c[i]=c[j]+1;

		}
	}

}

return c[n-1];

}
int knapSack(int weight,int *wt,int *val,int n)
{int a[n+1][weight+1];
	for(int i=0;i<=n;i++)
	{for(int j=0;j<=weight;j++)
		{if(i==0||j==0)
			a[i][j]=0;
			else if(wt[i-1]>j)
			{a[i][j]=a[i-1][j];

			}
			else a[i][j]=maxi(val[i-1]+a[i-1][j-wt[i-1]],a[i-1][j]);

		}

	}
return a[n][weight];
}
void printPatternutil(char a[],int len,char s[],int i,int n)
{
	if(i>n)
	return;
	if(i==n)
	{for(int j=0;j<len;j++)
		cout<<a[j];
		cout<<endl;
		return;

	}
	if(len==0||a[len-1]==' ')
	{a[len]=s[i];
		printPatternutil(a,len+1,s,i+1,n);

	}
	else {
		a[len]=' ';
		printPatternutil(a,len+1,s,i,n);
		a[len]=s[i];
		printPatternutil(a,len+1,s,i+1,n);
	}

}
void printPattern(char s[])
{int n=strlen(s);
	char a[2*n];
	int i=0;int len=0;
	printPatternutil(a,len,s,i,n);

}
bool issame(int fortxt[],int forpat[])
{for(int i=0;i<255;i++)
	{if(forpat[i]!=fortxt[i])
		return false;

	}
	return true;

}
void search(char pat[],char txt[])
{int n=strlen(txt);
	int m=strlen(pat);
	int forpat[255]={0};
	int fortxt[255]={0};
	for(int i=0;i<m;i++)
		{forpat[pat[i]]++;
			fortxt[txt[i]]++;}
			if(issame(fortxt,forpat))
				cout<<"index "<<0<<"\n";
	for(int i=m;i<=n;i++)
	{fortxt[txt[i]]++;fortxt[txt[i-m]]--;
		if(issame(fortxt,forpat))
			cout<<"index "<<i-m+1<<"\n";

	}


}
void printIlsutil(char *ans,int len,int tot,char*a,int n,int i,char*b,int m,int j)
{if(len==4)
	{//cout<<"sfd";
		for(int k=0;k<len;k++)
		cout<<ans[k];
		cout<<endl;
		return;

	}
	
	if(i<=n-1)
	{ans[len]=a[i];
	printIlsutil(ans,len+1,tot,a,n,i+1,b,m,j);}
if(j<=m-1)
	{ans[len]=b[j];
	
	printIlsutil(ans,len+1,tot,a,n,i,b,m,j+1);}

}


void printIls(char* a,char *b,int n,int m)
{char ans[m+n];int len=0;int tot=m+n+1;int i=0;int j=0;
	printIlsutil(ans,len,tot,a,n,i,b,m,j);

}
int piv(int *a,int l,int r)
{if(l>r)
	return -1;
	if(l==r)
		return l;
	int mid=l+(r-l)/2;
	if(l+1==r&&a[l]>a[r])
		return l;
	if(l+1==r&&a[r]>a[l])
		return r;
	if(a[mid]>a[mid-1]&&a[mid]>a[mid+1])
		return mid;
	if(a[mid]>a[mid-1])
		return piv(a,mid+1,r);
	return piv(a,l,mid-1);

}
void printMatrix(bool a[4][5])
{for(int i=0;i<4;i++)
	{for(int j=0;j<5;j++)
		cout<<a[i][j]<<" ";
cout<<endl;
	}

}
void modifyMatrix(bool a[4][5])
{bool isrow=0;bool iscol=0;
	for(int i=0;i<5;i++)
	{if(a[0][i])
		isrow=1;

	}
	for(int i=0;i<4;i++)
	{if(a[i][0])
		iscol=1;

	}
	for(int i=1;i<4;i++)
	{for(int j=1;j<5;j++)
		{if(a[i][j]==1)
			{a[i][0]=1;
				a[0][j]=1;

			}

		}

	}
	for(int i=1;i<4;i++)
	{for(int j=1;j<5;j++)
		{if(a[i][0]==1||a[0][j]==1)
			a[i][j]=1;
			else a[i][j]=0;

		}

	}
	if(isrow)
	{for(int i=0;i<5;i++)
		a[0][i]=1;


	}
	if(iscol)
	{for(int i=0;i<4;i++)
		a[i][0]=1;
}
}
struct orange{
	int i;int j;int time;
};
int rottenoranges(vector<vector<int> >& a)
{int n=a.size();
	int m=a[0].size();
	queue<struct orange>q;
	for(int i=0;i<n;i++)
	{for(int j=0;j<n;j++)
		{if(a[i][j]==2)
			{struct orange temp;
				temp.i=i;temp.j=j;temp.time=0;

			}

		}

	}
	int ans=-1;
	struct orange temp;struct orange temp2;int i;int j;
	while(!q.empty())
	{temp=q.front();
		q.pop();i=temp.i;j=temp.j;
		ans=maxi(ans,temp.time);
		if(i<m-1&&a[i+1][j]==1)
		{temp2.i=i+1;temp2.j=j;temp2.time=temp.time+1;
			q.push(temp2);
			a[i+1][j]=2;

		}
		if(i>0&&a[i-1][j]==1)
		{temp2.i=i-1;temp2.j=j;temp2.time=temp.time+1;
			q.push(temp2);
			a[i-1][j]=2;

		}
		if(j<n-1&&a[i][j+1]==1)
		{temp2.i=i;temp2.j=j+1;temp2.time=temp.time+1;
			q.push(temp2);
			a[i][j+1]=2;

		}
		if(j>0&&a[i][j-1]==1)
		{temp2.i=i;temp2.j=j-1;temp2.time=temp.time+1;
			q.push(temp2);
			a[i][j-1]=2;

		}

	}
	for(int i=0;i<n;i++)
	{for(int j=0;j<m;j++)
		{if(a[i][j]==1)
			return -1;

		}

	}
return ans;
}
int main()
{	vector<vector<int> > oranges = {{1,0,0,1},
									{2,0,0,2},
									{1,1,1,0},
									{0,2,2,2}};
	cout<<"minimum time needed is : "<<rottenoranges(oranges)<<endl;
 
  return 0;

}																																		