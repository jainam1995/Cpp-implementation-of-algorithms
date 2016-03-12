#include <bits/stdc++.h>
using namespace std;

void swap(char*a,char*b)
{char s=*a;
	*a=*b;
	*b=s;

}
void permuteutil(char*s,int len,int n)
{if(len==n)
	{for(int i=0;i<n;i++)
		cout<<s[i];
		cout<<endl;
		return;
	}
	bool visited[255]={false};

for(int i=len;i<n;i++)
{if(visited[s[i]]==false)
{	
	swap(s+len,s+i);
permuteutil(s,len+1,n);
swap(s+len,s+i);
visited[s[i]]=true;
}
}
}
void permute(char s[])
{int len=0;int n=strlen(s);
	permuteutil(s,len,n);

}
void combinationutil(char*s,char*a,int len,int n,int j,int p)
{if(len>=n)
	return;
	if(j>=p)
		return;
	
	a[len]=s[j];
	if(len==n-1)
	{for(int i=0;i<=len;i++)
		cout<<a[i];
		cout<<endl;
		

	}
	combinationutil(s,a,len+1,n,j+1,p);
	while(j<=p-1&&s[j]==s[j+1])
		j++;
	combinationutil(s,a,len,n,j+1,p);

}
void combination(char*s,int n)
{char a[n];int len=0;int i=0;int p=strlen(s);
	combinationutil(s,a,len,n,i,p);

}
void printallutil(char* ans,bool visited[3][2],char s[3][2],int len,int i,int j,int n)
{if(len>=n)
	return;
	ans[len++]=s[i][j];
	visited[i][j]=true;
	for(int k=0;k<len;k++)
	{cout<<ans[k];
		

	}
	cout<<endl;
	int q;int p;
	for( p=0;p<3;p++)
	{for( q=0;q<2;q++)
		{if(!visited[p][q])
			printallutil(ans,visited,s,len,p,q,n);
		}
		

	}
	

}
void printall(char s[3][2])
{bool visited[3][2];char ans[4];int len=0;int n=6;
	for(int i=0;i<3;i++)
	{for(int j=0;j<3;j++)
		visited[i][j]=false;

	}
	for(int i=0;i<3;i++)
	{for(int j=0;j<2;j++)
		{
			printallutil(ans,visited,s,len,i,j,n);
			for(int h=0;h<3;h++)
			{for(int g=0;g<2;g++)
				visited[h][g]=false;

			}
		}


	}



}
bool issafe(int x,int y)
{if(x>=0&&x<3&&y>=0&&y<3)
	return true;
	return false;

}
bool presentutil(bool visited[3][3],char s[3][3],char*a,int len,int n,int i,int j,int *xrow,int *yrow)
{visited[i][j]=true;
	if(len==n-1)
	{visited[i][j]=false;
		return true;

	}
	
	int l;int k;
	for( l=0;l<8;l++)
		{for( k=0;k<8;k++)
			{int nextx=i+xrow[l];
			int nexty=j+yrow[k];
			if(issafe(nextx,nexty)&&visited[nextx][nexty]==false&&s[nextx][nexty]==a[len+1])
			{if(presentutil(visited,s,a,len+1,n,nextx,nexty,xrow,yrow))
				{visited[nextx][nexty]=false;
				return true;
			}
				visited[nextx][nexty]=false;
			}
			
		}


		}
return false;

}
bool present(char s[3][3],char a[])
{bool visited[3][3];int len=0;int n=strlen(a);
	int xrow[]={1,1,1,0,0,-1,-1,-1};
	int yrow[]={0,-1,1,1,-1,0,-1,1};
	for(int i=0;i<3;i++)
	{for(int j=0;j<3;j++)
		visited[i][j]=false;

	}
	for(int i=0;i<3;i++)
	{for(int j=0;j<3;j++)
		if(s[i][j]==a[0])
		{visited[i][j]=false;
			if(presentutil(visited,s,a,len,n,i,j,xrow,yrow))
				return true;

		}

	}
return false;
}
void allpossiblepaths(char s[3][3],int i,int j,int x,int y,int len,char* ans)
{ans[len++]=s[i][j];
	if(i==x&&j==y)
	{for(int g=0;g<len;g++)
		{cout<<ans[g];


		}
		cout<<endl;
		return;

	}
	if(i>x||j>y)
		return;
allpossiblepaths(s,i+1,j,x,y,len,ans);
allpossiblepaths(s,i,j+1,x,y,len,ans);
allpossiblepaths(s,i+1,j+1,x,y,len,ans);
}
void allpossiblepathsutil(char s[3][3],bool visited[3][3],int i,int j,int x,int y,char*ans,int len,int *xrow,int *yrow)
{visited[i][j]=true;
	ans[len++]=s[i][j];
	if(i==x-1&&j==y-1)
	{for(int d=0;d<len;d++)
		cout<<ans[d];
		cout<<endl;
		return;

	}
	for(int h=0;h<8;h++)
	{int nextx=i+xrow[h];
		int nexty=j+yrow[h];
		if(issafe(nextx,nexty)&&visited[nextx][nexty]==false)
		{allpossiblepathsutil(s,visited,nextx,nexty,x,y,ans,len,xrow,yrow);
			visited[nextx][nexty]=false;

		}

	}

}
void allpossiblepaths(char s[3][3],int x,int y)
{int i=0;int j=0;int len=0;char ans[100];
	bool visited[3][3];
	for(int g=0;g<3;g++)
	{for(int h=0;h<3;h++)
		visited[g][h]=false;

	}
	int xrow[]={-1,-1,-1,0,0,1,1,1};
	int yrow[]={-1,0,1,1,-1,-1,0,1};
	allpossiblepathsutil(s,visited,i,j,x,y,ans,len,xrow,yrow);

}
void islandsutil(int s[3][3],bool visited[3][3],int i,int j,int *xrow,int *yrow)
{visited[i][j]=true;
	for(int h=0;h<8;h++)
	{int nextx=i+xrow[h];
		int nexty=j+yrow[h];
		if(issafe(nextx,nexty)&&visited[nextx][nexty]==false&&s[nextx][nexty]==1)
		{islandsutil(s,visited,nextx,nexty,xrow,yrow);

		}

	}

}
int islands(int s[3][3])
{bool visited[3][3];
	for(int i=0;i<3;i++)
	{for(int j=0;j<3;j++)
		visited[i][j]=false;

	}
	int count=0;
	int xrow[]={1,1,1,-1,-1,-1,0,0};
	int yrow[]={-1,0,1,-1,0,1,-1,1};
	for(int i=0;i<3;i++)
	{for(int j=0;j<3;j++)
		{if(!visited[i][j]&&s[i][j]==1)
			{islandsutil(s,visited,i,j,xrow,yrow);
			count++;
			}

		}

	}
	return count;

}
int main()
{
int s[3][3]={1,1,1,0,0,0,1,0,1};
//a b c
//d e f
//g h i
cout<<islands(s);


	return 0;
}