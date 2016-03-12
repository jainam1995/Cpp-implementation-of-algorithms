#include <bits/stdc++.h>
using namespace std;
struct stackarr
{int capacity;
	int *a;
	int top;

};
struct stackarr* newstackarr(int capacity)
{struct stackarr* temp=(struct stackarr*)malloc(sizeof(struct stackarr));
	temp->capacity=capacity;
	temp->top=-1;
	temp->a=(int *)malloc(sizeof(int)*capacity);
	return temp;

}
bool isfull(struct stackarr* temp)
{if(temp->top==temp->capacity-1)
	return true;
	return false;

}
bool isempty(struct stackarr* temp)
{if(temp->top==-1)
	return true;
	return false;

}
void push(struct stackarr* temp, int data)
{if(isfull(temp))
	{cout<<"The stack is full\n";return;}
	temp->a[++(temp->top)]=data;

}
void pop(struct stackarr* temp)
{if(isempty(temp))
	{cout<<"The stack is empty\n";
	return ;

	}
cout<<temp->a[temp->top]<<"\n";
(temp->top)--;

}
struct node{
	int data;
	struct node* next;
};
struct stacknode{
	int capacity;
	struct node* head;
	int size;


};
struct node* newNode(int data)
{struct node* temp=(struct node*)malloc(sizeof(struct node));
temp->data=data;
temp->next=NULL;
}
struct stacknode* newstacknode(int capacity)
{struct stacknode* temp=(struct stacknode*)malloc(sizeof(stacknode));
	temp->capacity=capacity;
	temp->size=0;
	temp->head=NULL;
	return temp;

}

void push(struct stacknode* temp,int data)
{if(temp->size==temp->capacity)
	{cout<<"Stack is full\n";return;}
	struct node* root=newNode(data);
	root->next=temp->head;
	temp->head=root;
	temp->size++;

}
void pop(struct stacknode* temp)
{if(temp->size==0)
	{cout<<"Stack is empty\n";return;}
	cout<<(temp->head)->data<<"\n";
	struct node* root=temp->head;
	temp->head=(temp->head)->next;
	free(root);
	root=NULL;
	(temp->size)--;


}
struct queuearr{
int front;
int rear;
int capacity;
int *a;

};
struct queuearr* newqueuearr(int capacity)
{struct queuearr* temp=(struct queuearr*)malloc(sizeof(struct queuearr));
	temp->capacity=capacity;
	temp->front=-1;
	temp->rear=-1;
	temp->a=(int *)malloc(sizeof(int)*capacity);
	return temp;

}
bool isfull(struct queuearr* temp)
{
	if((temp->rear+1)%temp->capacity==temp->front)
		return true;
	return false;
}
bool isempty(struct queuearr* temp)
{
	if(temp->front==-1)
		return true;
	return false;
}
void push(struct queuearr* temp,int data)
{if(isfull(temp))
	{cout<<"Queue is full\n";return;


	}
	if(temp->front==-1)
		{(temp->front)++;
			temp->rear=temp->front;
			temp->a[temp->front]=data;//cout<<"s\n";
		}
		else 
		{temp->rear=(temp->rear+1)%temp->capacity;
			temp->a[temp->rear]=data;
			//cout<<data<<"d\n";

		}

}
void pop(struct queuearr* temp)
{if(isempty(temp))
	{cout<<"Queue is empty\n";return;}
	if(temp->front==temp->rear)
		{cout<<temp->a[temp->front]<<"\n";
			temp->front=-1;temp->rear=-1;}
	else{cout<<temp->a[temp->front]<<"\n";
		temp->front=(temp->front+1)%temp->capacity;
	}

}
struct queuenode{
	int capacity;
	struct node* front;
	struct node* rear;
	int size;
};
struct queuenode* newqueuenode(int capacity)
{struct queuenode* temp=(struct queuenode*)malloc(sizeof(struct queuenode));
	temp->capacity=capacity;
	temp->front=NULL;temp->rear=NULL;
	temp->size=0;
	return temp;

}
void push(struct queuenode* temp,int data)
{if(temp->size==temp->capacity)
	{cout<<"Queue is full\n";return;}
	if(temp->front==NULL)
	{temp->front=newNode(data);
		temp->rear=temp->front;
		temp->size++;


	}
	else{
		temp->rear->next=newNode(data);
		temp->rear=temp->rear->next;
		temp->size++;
	}

}
void pop(struct queuenode* temp)
{if(temp->front==NULL)
	{cout<<"Queue is empty\n";return;}
	else{
if(temp->front==temp->rear)
{cout<<(temp->front)->data<<"\n";
temp->size--;
}
else{
	cout<<(temp->front)->data<<"\n";
	struct node* h=temp->front;
	temp->front=(temp->front)->next;
	free(h);
	temp->size--;
}

	}

}
struct heap{
int capacity;
int size;
int *arr;

};
struct heap* newHeap(int capacity)
{struct heap* temp=(struct heap*)malloc(sizeof(struct heap));
	temp->capacity=capacity;
	temp->size=0;
	temp->arr=(int*)malloc(sizeof(int)*capacity);
	return temp;

}
int left(struct heap* temp,int i)
{if(2*i+1>=temp->size)
	return -1;
	return 2*i+1;

}
int right(struct heap* temp,int i)
{if(2*i+2>=temp->size)
	return -1;
	return 2*i+2;


}
int parent(struct heap* temp,int i)
{if((i-1)/2<0)
	return -1;
	return (i-1)/2;

}
void percolatedown(struct heap* temp,int i)
{int max;
	while(true)
	{max=i;
		if(left(temp,i)!=-1)
		{int a=temp->arr[left(temp,i)];
			if(a>temp->arr[max])
				max=left(temp,i);

		}
		if(right(temp,i)!=-1)
		{int a=temp->arr[right(temp,i)];
			if(a>temp->arr[max])
				max=right(temp,i);

		}
		if(max==i)
			break;
		else{
			int c=temp->arr[i];
			temp->arr[i]=temp->arr[max];
			temp->arr[max]=c;
			i=max;
		}

	}

}
void heapify(struct heap* temp,int i)
{while(parent(temp,i)>=0)
	{if(temp->arr[parent(temp,i)<temp->arr[i]])
		{int c=temp->arr[i];
			temp->arr[i]=temp->arr[parent(temp,i)];
			temp->arr[parent(temp,i)]=c;
			i=parent(temp,i);

		}
		else break;

	}

}
void buildheap(struct heap* temp)
{for(int i=(temp->size-2)/2;i>=0;i--)
	percolatedown(temp,i);

}
bool isfull(struct heap* temp)
{if(temp->size==temp->capacity-1)
	return true;
	return false;

}
bool isempty(struct heap* temp)
{if(temp->size==0)
	return true;
	return false;

}
void insertheap(struct heap* temp,int data)
{if(isfull(temp))
	{cout<<"Heap is full\n";return;}
	(temp->size)++;
	temp->arr[temp->size]=data;
	heapify(temp,temp->size);

}
int deletemin(struct heap* temp)
{if(isempty(temp))
	{cout<<"Heap is empty\n";
	return -1;

	}
	int ans=temp->arr[0];
	temp->arr[0]=temp->arr[temp->size];
	temp->size--;
	percolatedown(temp,0);
	return ans;

}
int main()
{struct heap* temp=newHeap(10);

for(int i=0;i<37;i++)
temp->arr[i]=i;
temp->size=7;
buildheap(temp);
for(int i=0;i<7;i++)
cout<<temp->arr[i]<<" ";



	return 0;
}//6
//4 5
//3102