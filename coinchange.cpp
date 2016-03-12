#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
int max(int a,int b)
{if(a>b)
	return a;
	else return b;

}
int count(int a[],int n,int val)
{int ans[n][val+1];
	for(int i=0;i<n;i++)
		ans[i][0]=1;
	for(int i=0;i<=val;i++)
		ans[0][i]=1;
		
	for(int i=1;i<n;i++)
	{for(int j=1;j<=val;j++)
		{if(a[i]>val)
			ans[i][j]=ans[i-1][j];

		else ans[i][j]=ans[i-1][val-a[i]]+ans[i-1][j];

		}

	}

return ans[n-1][val];

}
int main()
{



int i, j;
    int arr[] = {1, 2, 3};
    int m = sizeof(arr)/sizeof(arr[0]);
    printf("%d ", count(arr, m, 4));
    getchar();
    

	return 0;
}