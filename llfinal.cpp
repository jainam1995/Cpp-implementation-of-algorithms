#include <bits/stdc++.h>
using namespace std;
struct node{
int data;
struct node* next;

};
struct node* newNode(int data)
{struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	return temp;

}
void push(struct node** head,int data)
{struct node* temp=newNode(data);
	temp->next=*head;
	*head=temp;

}
void printList(struct node* head)
{
	while(head)
	{cout<<head->data<<" ";
head=head->next;

	}
}
struct node* kAltReverse(struct node* head,int k)
{struct node* prev=NULL;struct node* next;struct node* curr=head;
	int count=0;
	while(curr&&count<k)
	{next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
		count++;

	}
	if(curr==NULL)
		return prev;
	head->next=curr;
	count=1;
	while(curr&&count<k)
	{curr=curr->next;
		count++;

	}
	if(curr==NULL)
		return prev;
	curr->next=kAltReverse(curr->next,k);
	return prev;




}
void generate(int *a,int *b,int n,int m)
{int i=0;int j=0;


}
void subArraySum(int *a,int n,int sum)
{int start=0;int end=1;int curr=a[0];
	while(end<=n)
	{while(curr>sum)
		{curr=curr-a[start];
			start++;

		}
if(curr==sum)
	cout<<start<<" "<<end-1<<"\n";

if(end<n)
	curr=curr+a[end];
end++;
	}

}
struct petrolPump{
	int petrol;
	int dist;
};
int printTour(struct petrolPump arr[],int n)
{int a[n];
	for(int i=0;i<n;i++)
		a[i]=arr[i].petrol-arr[i].dist;

	int start=0;
	int end=1;
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

}int printTour2(struct petrolPump* arr,int n)
{int a[n];for(int i=0;i<n;i++)
	a[i]=arr[i].petrol-arr[i].dist;
	int curr=a[0];int sum=a[0];int start=0;
	for(int i=1;i<n;i++)
	{if(curr<0)
		{start=i;
			curr=a[i];

		}
		else{
			curr=curr+a[i];

		}
		sum=sum+a[i];

	}
if(sum<0)
	return -1;
return start;
}
void printCombinationutil(int  *a,int i,int n,int  *ans,int len,int r)
{if(i>n)
	return;
	if(len==r)
	{for(int j=0;j<len;j++)
		{cout<<ans[j]<<" ";


		}
		cout<<endl;
		return;

	}
	if(i==n)
		return;
	ans[len]=a[i];
	printCombinationutil(a,i+1,n,ans,len+1,r);
	while(i<n-1&&a[i]==a[i+1])
		i++;
	printCombinationutil(a,i+1,n,ans,len,r);

}
void printCombination(int *a,int n,int r)
{int  ans[r];int i=0;int len=0;
	printCombinationutil(a,i,n,ans,len,r);

}
int smallestSubWithSum(int *a,int n,int x)
{int start=0;int curr=a[0];int end=1;int ans=INT_MAX;
	while(end<=n)
	{while(curr>x)
		{if(end-start<ans)
			ans=end-start;
			curr=curr-a[start];
			start++;

		}
		if(end<n)
			curr=curr+a[end];
		end++;

	}
return ans;
}
void printSequtil(int *ans,int len,int k,int i,int n)
{if(len==k)
	{for(int j=0;j<len;j++)
		cout<<ans[j]<<" ";
		cout<<endl;
		return;
	}
	if(i>n)
		return;
	ans[len]=i;
	printSequtil(ans,len+1,k,i+1,n);
	printSequtil(ans,len,k,i+1,n);

}
void printSeq(int n,int k)
{int ans[k];int i=1;int len=0;
	printSequtil(ans,len,k,i,n);

}
bool check(int count[] ){
	for(int i=0;i<26;i++)
	{if(count[i]>1)
		return false;

	}
return true;
}
int longestUniqueSubsttr(char* s)
{int count[26];int n=strlen(s);
	for(int i=0;i<26;i++)
		count[i]=0;
	count[s[0]-'A']=1;int start=0;int end=1;int ans=0;
	while(end<=n)
	{while(!check(count))
		{count[s[start]-'A']--;
		start++;

		}
		if(end-start>ans)
			ans=end-start;
		if(end<n)
		{count[s[end]-'A']++;}
	end++;

		

	}
return ans;

}
bool checkunique(int *a,int k)
{int c=0;
	for(int i=0;i<26;i++)
	{if(a[i]>=1)
		c++;


	}
	if(c!=k)
		return false;
	return true;

}
void kUniques(char* s,int k)
{int start=0;int end=1;int n=strlen(s);
	int count[26];
	for(int i=0;i<26;i++)
		count[i]=0;
	count[s[0]-'a']=1;int ans=0;
	while(end<=n)
	{while(!checkunique(count,k))
		{count[s[start]-'a']--;
		start++;

		}
		if(end-start>ans)
			ans=end-start;
		if(end<n)
		{count[s[end]-'a']++;


		}
		end++;

	}
cout<<ans;

}

int lastindexutil(int *a,int l,int r,int k)
{if(l>r)
	return -1;
	if(l==r&&a[r]==k)
		return r;
	int mid=l+(r-l)/2;
	if(mid>l&&a[mid-1]==k&&a[mid]!=k)
		return mid-1;
	if(mid<r&&a[mid]==k&&a[mid+1]!=k)
		return mid;
	if(a[mid]<=k)
		return lastindexutil(a,mid+1,r,k);
	return lastindexutil(a,l,mid-1,k);

}
int lastindex(int *a,int n,int k)
{return lastindexutil(a,0,n-1,k);

}
int firstindexutil(int *a,int l,int r,int k)
{if(l>r)
	return -1;
	if(a[l]==k)
		return l;
	if(l==r&&a[l]==k)
		return l;
	if((l+1==r)&&a[l]!=k&&a[r]==k)
		return r;
	int mid=l+(r-l)/2;
	if(mid>l&&a[mid-1]!=k&&a[mid]==k)
		return mid;
	if(mid<r&&a[mid]!=k&&a[mid+1]==k)
		return mid+1;
	if(a[mid]>=k)
		return firstindexutil(a,l,mid-1,k);
	return firstindexutil(a,mid+1,r,k);



}
int firstindex(int *a,int n,int k)
{return firstindexutil(a,0,n-1,k);

}
int ceil(int *a,int l,int r,int k)
{
	if(l>r)
		return -1;
	if(k<=a[l])
		return a[l];
	if((l+1==r)&&a[l]<k&&a[r]>=k)
		return a[r];
	int mid=l+(r-l)/2;
	if(a[mid]==k)
		return k;
	if(mid<r&&a[mid]<k&&a[mid+1]>=k)
		return a[mid+1];
	if(mid>l&&a[mid-1]<k&&a[mid]>=k)
		return a[mid];
	if(a[mid]<k)
		return ceil(a,mid+1,r,k);
	return ceil(a,mid-1,r,k);
}
int findpivot(int *a,int l,int r)
{if(l>r)
	return -1;
	if(l==r)
		return l;
	int mid=l+(r-l)/2;
	if(mid>l&&a[mid-1]>a[mid])
		return mid-1;
	if(mid<r&&a[mid]>a[mid+1])
		return mid;
	if(a[mid]>a[l])
		return findpivot(a,mid+1,r);
	return findpivot(a,l,mid-1);

}
int findmax(int *a,int l,int r)
{if(l>r)
	return -1;
	if(l==r)
		return a[l];
	if(l+1==r)
	{if(a[l]>a[r])
		return a[l];
		return a[r];

	}
	int mid=l+(r-l)/2;
	if(mid>l&&mid<r&&a[mid]>a[mid-1]&&a[mid]>a[mid+1])
		return a[mid];
	if(a[mid-1]>a[mid])
		return findmax(a,l,mid-1);
	return findmax(a,mid+1,r);
}
void reversewords(char *a)
{int n=strlen(a);
	int start=0;int j=0;int end=0;
	while(a[start]==' '&&start<n)
		start++;
	if(start==n)
		return;
	while(true)
	{if(end==n)
		break;
		while(a[end]!=' '&&end<n)
		end++;
	int l=start;int r=end-1;
	while(l<=r)
	{char temp=a[l];
		a[l]=a[r];
		a[r]=temp;
		l++;r--;

	}
	for(int i=start;i<=end-1;i++)
		a[j++]=a[i];
	
	if(end==n)
		break;
	a[j++]=' ';
	while(a[end]==' '&&end<n)
		end++;
	if(end==n)
		break;
	start=end;
	}

	a[j]='\0';
	
	int l=0;int r=j-1;
	while(l<=r)
	{char temp=a[l];
		a[l]=a[r];
		a[r]=temp;
		l++;r--;

	}
//cout<<a;
}
void reversewordsori(char *a)
{int n=strlen(a);
	int start=0;
	while(a[start]==' '&&start<n)
		start++;
	if(start==n)
		return;
	int end=start;
	while(true)
	{while(a[end]!=' '&&end<n)
		end++;
		int l=start;int r=end-1;
		while(l<=r)
		{char temp=a[l];
			a[l]=a[r];
			a[r]=temp;
			l++;r--;

		}
		if(end==n)
			break;
		while(a[end]==' '&&end<n)
			end++;
		if(end==n)
			break;
		start=end;
	}
	int l=0;int r=n-1;
	while(l<r)
	{char temp=a[l];
		a[l]=a[r];
		a[r]=temp;
		l++;r--;

	}

}
int findpivots(int *a,int l,int r)
{int j=l-1;
	int i=l;
	int pivot=a[r];
	while(i<r)
	{
	while(i<r&&a[i]>=pivot)
	i++;
		if(a[i]<pivot&&i<r)
		{	j++;
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
void quicksort(int *a,int l,int r)
{if(l<r)
	{int pivot=findpivots	(a,l,r);
		quicksort(a,l,pivot-1);
		quicksort(a,pivot+1,r);

	}

}
bool findPartiionutil(int *a,int len,int n,int s,int sum)
{if(s==sum)
	return true;
	if(len==n)
		return false;
	s+=a[len];
	return findPartiionutil(a,len+1,n,s,sum)||findPartiionutil(a,len+1,n,s-a[len],sum);


}
bool findPartiion(int *a,int n)
{int sum=0;
	for(int i=0;i<n;i++)
		sum=sum+a[i];
	if(sum%2!=0)
		return false;
	int ans=sum/2;
	int s=0;int len=0;
	return findPartiionutil(a,len,n,s,ans);
}
void printArray(int *a,int n)
{for(int i=0;i<n;i++)
	cout<<a[i]<<" ";

}
void rearrangeutil(int *a,int i,int n)
{int val=-(i+1);
	 i=a[i]-1;
	while(a[i]>0)
	{int newi=a[i]-1;
		a[i]=val;
		val=-(i+1);
		i=newi;

	}

}
void rearrange(int *a,int n)
{for(int i=0;i<n;i++)
	a[i]=a[i]+1;
for(int i=0;i<n;i++)
{if(a[i]>0)
	{rearrangeutil(a,i,n);

	}

}
for(int i=0;i<n;i++)
a[i]=-(a[i])-1;

}
//bool boggleutil(char a[3][3],bool visited[3][3],char *s,int x,int y,int* xrow,int* yrow)
//{

//}
/*bool boggle(char*s,char a[3][3])
{bool visited[3][3];
	for(int i=0;i<3;i++)
	{for(int j=0;j<3;j++)
		visited[i][j]=false;

	}
	for(int i=0;i<3;i++)
	{for(int j=0;j<3;j++)
		{if(a[i][j]==s[0])
			if(boggleutil(a,visited,s,i,j)==true)
				return true;
			visited[i][j]=false;

		}

	}
return false;
}*/struct jai{
	int data;
	int index;
};
bool compare(jai i,jai j)
{if(i.data<j.data)
	return 1;
	return 0;

}
int main()
{

 /** char a[3][3]={{'j','a','i'},
				{'n','a','m'},
			     {'f','g','k'}};

char s[]="jna";
if(boggle(s,a))
	cout<<"There.\n";
else cout<<"Not There.\n";
**/
struct jai s[]={{2,1},{1,8}};
sort(s,s+2,compare);
for(int i=0;i<2;i++)
	cout<<s[i].data<<" "<<s[i].index<<"\n";

return 0;	
}