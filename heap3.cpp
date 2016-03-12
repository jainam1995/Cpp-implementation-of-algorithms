#include <bits/stdc++.h>
using namespace std;
struct heap{
int capacity;
int *a;


};
struct heap* newHeap(int n)
{struct heap* temp=(struct heap*)malloc(sizeof(struct heap));
	temp->capacity=n;
	temp->a=(int *)malloc(sizeof(heap)*n);
	return temp;

}
int left(struct heap* temp,int i)
{if(2*i+1>=temp->capacity)
return -1;
return 2*i+1;
}
int right(struct heap* temp,int i)
{if(2*i+2>=temp->capacity)
	return -1;
	return 2*i+2;

}
int parent(struct heap* temp,int i)
{if((i-1)/2)<0
	return -1;
	return (i-1)/2;

}
void percolatedown(struct heap*temp,int i)
{int l;int r;int max;int maxindex;
	while(i<temp->capacity)
	{max=temp->a[i];
		if(left(temp,i)!=-1)
		{l=left(temp,i);
			
			if(temp->a[l]>max)
				{maxindex=i;
					max=temp->a[i];}
					}
			r=right(temp,i);
			if(r!=-1)
			{if(temp->a[i]>max)
				{maxindex=r;
					max=temp->a[i];}

			}	

			if(maxindex!=i)
			{int t=temp->a[i];
				temp->a[i]=temp->a[maxindex];
				temp->a[maxindex]=t;


			}
		
			i=maxindex;

	}

}
void heapify(struct stack*s,int i)
{

}
int main()
{






return 0;	
}