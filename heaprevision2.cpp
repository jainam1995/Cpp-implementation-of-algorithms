#include <bits/stdc++.h>
using namespace std;
struct heap{
int size;
int capacity;
int *arr;

};
int parent(struct heap* temp,int i)
{if(i<1||i>=temp->size)
	return -1;
	return (i-1)/2;

}
int left(struct heap* temp,int i )
{if(i<0||(2*i+1)>=temp->size)
	return -1;
	return 2*i+1;

}
int right(struct heap* temp,int i)
{if(i<0||(2*i+2)>=temp->size)
	return -1;
	return 2*i+2;

}
int getmin(struct heap* temp)
{if(temp->size==0)
	return -1;
	return temp->arr[0];

}
void percolatedown(struct heap* temp,int i)
{while(i<temp->capacity)
	{int min=temp->arr[i];int minindex=i;
		if(2*i+1<temp->size&&temp->arr[2*i+1]<min)
			{min=temp->arr[2*i+1];minindex=2*i+1;}
		if(2*i+2<temp->size&&temp->arr[2*i+2]<min)
			{min=temp->arr[2*i+2];minindex=2*i+2;}
		if(minindex!=i)
		{int data=temp->arr[i];
			temp->arr[i]=temp->arr[minindex];
			temp->arr[minindex]=data;
			i=minindex;
		}
		else break;


	}

}
int deletemin(struct heap* temp)
{if(temp->size==0)
	return -1;
	int ans=temp->arr[0];
	temp->arr[0]=temp->arr[temp->size-1];
	temp->size--;
	percolatedown(temp,0);
	return ans;



}
void insert(struct heap* temp,int data)
{if(temp->size==temp->capacity)
	return;
	temp->size++;
	int i=temp->size-1;
	while(i>0 && data<temp->arr[(i-1)/2])
	{temp->arr[i]=temp->arr[(i-1)/2];
		i=(i-1)/2;
	}
	temp->arr[i]=data;

} 
void heapify(struct heap* temp)
{int n=(temp->size-2)/2;
for(int i=n;i>=0;i--)
{percolatedown(temp,i);

}

}
struct heap* createHeap(int capacity)
{struct heap* temp=(struct heap*)malloc(sizeof(struct heap));
	temp->capacity=capacity;
	temp->size=0;
	temp->arr=(int*)malloc(sizeof(int)*capacity);
	return temp;

}
void heapsort(struct heap* temp)
{int oldsize=temp->size;
	for(int i=0;i<oldsize;i++)
	cout<<deletemin(temp)<<" ";
	cout<<endl;

}



int main()
{struct heap* temp=createHeap(10);
	temp->arr[0]=7;
	temp->size++;
	temp->arr[1]=3;
	temp->size++;
	temp->arr[2]=5;
	temp->size++;
	temp->arr[3]=6;
	temp->size++;
	temp->arr[4]=1;
	temp->size++;
	temp->arr[5]=2;
	temp->size++;
	temp->arr[6]=4;
	temp->size++;
heapify(temp);
heapsort(temp);
//for(int i=0;i<temp->size;i++)
// /cout<<temp->arr[i]<<" ";








	return 0;
}