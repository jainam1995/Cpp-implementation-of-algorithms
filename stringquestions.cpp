#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;
bool check[256];

void swap(char* a,char* b)
{char temp;
	temp=*a;
	*a=*b;
	*b=temp;

}
void permute(char* a,int l,int r)
{int  was[256];
int j;

 for(j = 0; j <= 255; j++)
    was[j] = 0;
 
if(l==r)
	cout<<a<<endl;
// bzero(was, 256);
 for (j = l; j <= r; j++)
 {
    if (!was[*(a+j)]) {
      swap((a+l), (a+j));
      permute(a, l+1, r);
      swap((a+l), (a+j)); //backtrack
      was[*(a+j)] = 1;
    }
 }


}
void countSort(char* str)
{int hash[255]={0};
for(int i=0;i<strlen(str);i++)
hash[str[i]]++;
for(int i=1;i<255;i++)
{hash[i]=hash[i]+hash[i-1];

}
char output[strlen(str)+1];
for(int i=strlen(str)-1;i>=0;i--)
{output[hash[str[i]]-1]=str[i];
	hash[str[i]]--;

}

for(int i=0;i<strlen(output);i++)
	str[i]=output[i];



}
void countsortutil(int *a,int n,int p)
{int hash[10]={0};
int output[n];
for(int i=0;i<n;i++)
{hash[(a[i]/p)%10]++;

}
for(int i=1;i<10;i++)
hash[i]=hash[i-1]+hash[i];
for(int i=n-1;i>=0;i--)
{output[hash[(a[i]/p)%10]-1]=a[i];
	hash[(a[i]/p)%10]--;

}
for(int i=0;i<n;i++)
a[i]=output[i];

}
void radixsort(int *arr,int n)
{int max=arr[0];
	for(int i=1;i<n;i++)
	{	if(arr[i]>max)
			max=arr	[i];
	}
	for(int i=1;max/i>0;i=i*10)
	{
		countsortutil(arr,n,i);
	}
}
void print(int *a,int n)
{for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	cout<<endl;

}
int main()
{
int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr)/sizeof(arr[0]);
    radixsort(arr, n);
    print(arr, n);






	return 0;
}