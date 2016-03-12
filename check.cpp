#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
struct petrolPump{
int fuel;
int dist;

};
int  printTour(int *a,int n)
{int curr=0;int total=0;int start=0;
	for(int i=0;i<n;i++)
	{total+=a[i];
		curr+=a[i];
		if(curr<0)
		{curr=0;
			start=i+1;

		}

	}
	if(total<0)
		return -1;
	else return start;

}

int printTour1(int *a,int n)
{int start=0;int end=1;int curr=a[0];
	while(start!=end||curr<0)
	{while(start!=end&&curr<0)
		{curr-=a[start];
		start=(start+1)%n;
		if(start==0)
			return -1;
	}
	curr=curr+a[end];
	end=(end+1)%n;


	}
	return start;

}

void subArraySum(int *a ,int n,int sum){
int start=0;int curr=a[0];
for(int i=1;i<=n;i++)
{while(curr>sum&&start<i-1)
	{curr-=a[start];
		start++;

	}
	if(curr==sum)
	{cout<<"found between"<<start<<" and "<<i-1;

return;
	}if(i<n)
curr=curr+a[i];
}

}
bool isvalid(int k,int* count)
{int val=0;
	for(int i=0;i<255;i++)
	{if(count[i]>0)
		val++;

	}
	return (k>=val);


}
void kUniques(char* s,int k)
{int start=0;int count[255]={0};
count[s[start]]++;int maxlen=1;int maxstart=start;
for(int i=1;i<=strlen(s);i++)
{while(!isvalid(k,count))
	{count[s[start]]--;
		start++;

	}
	if(i-start>maxlen)
		{maxlen=i-start;
			maxstart=start;}
	if(i<strlen(s))
	count[s[i]]++;


}for(int i=0;i<maxlen;i++)
{cout<<s[i+maxstart];}
cout<<endl;
cout<<maxlen;
}


int main()
{

 char s[] = "abcaeedeeeeeeeeeeefg";
    int k = 3;
    kUniques(s, k);




	return 0;
}