#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
int min(int a,int b,int c)
{int min=a;
	if(b<min)
		min=b;
	if(c<min)
		min=c;
	return min;

}
int mincost(int a[][3],int m,int n)
{int ans[3][3];ans[0][0]=a[0][0];
	for(int i=1;i<3;i++)
	{ans[0][i]=a[0][i]+ans[0][i-1];

	}
for(int i=1;i<3;i++)
	{ans[i][0]=a[i][0]+ans[i-1][0];

	}
for(int i=1;i<3;i++)
{
	for(int j=1;j<3;j++)
	{
		ans[i][j]=a[i][j]+min(ans[i-1][j-1],ans[i][j-1],ans[i-1][j]);

	}
}
return ans[m][n];
}



int main()
{int cost[3][3] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };

int ans=mincost(cost,2,2);
cout<<ans;

}