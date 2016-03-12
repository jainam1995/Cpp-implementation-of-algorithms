# include <bits/stdc++.h>
using namespace std;
int countWays(int n)
{int fib[n+1];
	fib[0]=1;
	fib[1]=1;
	for(int i=2;i<=n;i++)
		fib[i]=fib[i-1]+fib[i-2];
	return fib[n];

}

int countWaysm(int n,int m)
{int fib[n+1];int j;int count;
	for(int k=0;k<=n;k++)
		fib[k]=0;
	fib[0]=1;
	fib[1]=1;
	for(int i=2;i<=n;i++)
	{for( j=i-1,count=0;j>=0&&count<m;j--,count++)
		{//if(j<0)
			//break;

			fib[i]+=fib[j];

		}

	}
return fib[n];


}
bool isusmpresent(int *set,int sum,int n)
{if(sum==0)
	return true;
	if(n<=0&&sum!=0)
		return false;
	if(sum<0)
		return false;
	if(set[n-1]>sum)
		return isusmpresent(set,sum,n-1);
	else return isusmpresent(set,sum,n-1)||isusmpresent(set,sum-set[n-1],n-1);




}
struct node{
	int data;
	struct node* left;
	struct node* right;
};
struct node* newNode(int data)
{struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;

}
int lpsubstring(char* s)
{int n=strlen(s);int ans=1;
	int lps[n][n];
	for(int i=0;i<n;i++)
	{for(int j=i;j<n;j++)
		{if(i==j)
			lps[i][j]=1;
		if(j-i==1)
			{lps[i][j]=(s[i]==s[j]?1:0);
				ans=2;}

		}

	}

int lens;
for( lens=3;lens<=n;lens++)
{for(int i=0;i<n-lens+1;i++)
	{int j=i+lens-1;
		if(lps[i+1][j-1]&&s[i]==s[j])
		{ans=lens;
			lps[i][j]=1;

		}
		else lps[i][j]=0;

	}

}
return ans;

}
int minjumps(int *a,int n)
{if(a[0]==0||n==0)
	return -1;
	int ans[n];
ans[0]=0;
	for(int i=1;i<n;i++)
	{ans[i]=INT_MAX;

		for(int j=0;j<i;j++)
		{cout<<ans[j]<<" ";
			if(ans[j]!=INT_MAX && ((a[j]+j)>=i))
			{
				ans[i]=ans[j]+1;
				break;
			}

		}

	}
if(ans[n-1]==INT_MAX)
	return -1;
return ans[n-1];
}
void fib(int n)
{int a=1;
	int b=1;
int c;
	if(n==1||n==2)
		cout<<1;
	else for(int i=3;i<=n;i++)
	{c=a+b;
		a=b;
		b=c;

	}
	cout<<c;
}
int minPalPartion(char* s)
{int n=strlen(s);
	int p[n][n];
	for(int i=0;i<n;i++)
		p[i][i]=1;
	for(int len=2;len<=n;len++)
	{for(int i=0;i<n-len+1;i++)
		{int j=i+len-1;
			if(len==2)
				p[i][j]=(s[i]==s[j]);
			else{
				p[i][j]=((s[i]==s[j])&&p[i+1][j-1]);
			}

		}

	}

	int c[n];
	c[0]=0;
	for(int i=0;i<n;i++)
	{if(p[0][i])
		c[i]=0;
		continue;
		c[i]=INT_MAX;
		for(int j=0;j<i;j++)
		{if(c[j]!=INT_MAX&&p[j+1][i]&&c[i]>c[j]+1)
			c[i]=c[j]+1;

		}

	}
return c[n-1];
}
int cutrods(int *a,int n)
{int ans[n];
	ans[0]=a[0];
	for(int i=1;i<n;i++)
	{ans[i]=a[i];
		for(int j=0;j<i;j++)
		{if( ans[j]+a[i-j-1]>ans[i])
			ans[i]= ans[j]+a[i-j-1];


		}


	}


return ans[n-1];

}
int  partition(int *a,int l,int r)
{int pivot=a[r];
	int i=l-1;
	int j=l;
	while(j<r)
	{if(a[j]>=pivot)
		j++;
		else{
			i++;
			int temp=a[j];
			a[j]=a[i];
			a[i]=temp;
			j++;
		}

	}
	i++;
	a[r]=a[i];
	a[i]=pivot;
	return i;

}

void quicksort(int *a,int l,int r)
{if(l<r)
	{int pivot=partition(a,l,r);
		quicksort(a,l,pivot-1);
		quicksort(a,pivot+1,r);


	}

}
void printarray(int *a,int n)
{for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	cout<<endl;

}
int kthsmallest(int *a,int l,int r,int k)
{if(k>r)
	return -1;
	int pivot=partition(a, l,r);
	if(pivot==k)
		return a[k];
	else if(k<pivot)
		return kthsmallest(a,l,pivot-1,k);
	else return kthsmallest(a,pivot+1,r,k);

}
void printPatternutil(char* str,char* res,int i,int index,int n)
{if(i==n)
	{for(int j=0;j<index;j++)
		cout<<res[j];
		cout<<endl;
		return;

	}
	else{
		if(i==0||index==0||res[index-1]==' ')
			{res[index]=str[i];
		printPatternutil(str,res,i+1,index+1,n);}
		else{

			res[index]=' ';
			printPatternutil(str,res,i,index+1,n);
			res[index]=str[i];
			printPatternutil(str,res,i+1,index+1,n);

		}

	}

}
void printPattern(char * str)
{int n=strlen(str);
	char res[2*n-1];
int index=0;int i=0;
printPatternutil(str,res,i,index,n);

}
int searchmaxutil(int *a,int l,int r)
{if(l>r)
	return -1;
	if(l==r)
	return a[l];
	int mid=l+(r-l)/2;
	if(mid==r)
		return a[mid];
	if(mid==l)
		{if(a[mid]>a[mid+1])
			return a[mid];
			return a[mid+1];
		}

	if(a[mid]>a[mid+1]&&a[mid]>a[mid-1])
		return a[mid];
	if(a[mid]>=a[mid+1])
		return searchmaxutil(a,l,mid-1);
	else return searchmaxutil(a,mid+1,r);
}
int searchmax(int * a,int n)
{return searchmaxutil(a,0,n-1);

}
int main()
{

int a[]={1,2,3,4,5,6,6,4,3,2,1};
int size=sizeof(a)/sizeof(a[0]);
cout<<searchmax(a,size);










	return 0;
}