#include <bits/stdc++.h>
using namespace std;
void printspiral(int a[3][3])
{cout<<a[0][0];
	int rowbeg=0;
	int colbeg=0;
	int rowend=2;
	int colend=2;int j;int i;int k;
	while(rowbeg<=rowend&&colbeg<=colend)
	{for(i=colbeg,j=rowbeg;i<=colend;i++)
		{cout<<a[j][i]<<" ";
		cout<<endl;
		for(i=rowbeg+1,j=i-1;i<=rowend;i++)
			cout<<a[i][j]<<" ";
		cout<<endl;
		for(j=i-1,k=colend-1;k>=colbeg;k--)
			cout<<a[j][k]<<" ";
		cout<<endl;
		for(i=k+1,j=rowend-1;j>rowbeg;j--)
			cout<<a[i][j]<<" ";
		cout<<endl;
		rowend--;rowbeg++;colend--;colbeg++;}
	}

}
int partition(int *a,int *b,int l,int r)
{int i=l-1;
	int pivot=a[r];
	int j=l;
	while(j<r)
	{while(a[j]>=pivot)
		j++;
		if(a[j]<pivot)
		{i++;
			int temp=a[j];
			a[j]=a[i];
			a[i]=temp;
			j++;

		}

	}
	a[i++]=pivot;
	int ans=i;
	i=l-1;
	j=l;
	while(j<=r)
	{while(b[j]>=pivot)
		j++;
		if(b[j]<=pivot)
		{i++;
		 int temp=b[j];
			b[j]=a[i];
			b[i]=temp;
			j++;

		}


	}
return ans;
}

void nutsbolts(int *a,int *b,int l,int r)
{while(l<r)
	{int pivot=partition(a,b,l,r);cout<<pivot;cout<<" "<<b[5];
	//break;
		nutsbolts(a,b,l,pivot-1);
		nutsbolts(a,b,pivot+1,r);

	}

}


int main()
{
int a[]={5,2,7,4,1,9};
int b[]={9,2,7,1,4,5};
int n=sizeof(a)/sizeof(a[0]);
nutsbolts(a,b,0,n-1);





	return 0;

}