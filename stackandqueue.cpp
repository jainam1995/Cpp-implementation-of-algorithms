#include <bits/stdc++.h>
using namespace std;
struct node{
int data;
struct node* next;

};
struct stackadt{
int capacity;
int top;
struct node* head;




};
struct stackadt* createstack(int capacity)
{struct stackadt* temp=(struct stackadt*)malloc(sizeof(struct stackadt));
	temp->capacity=capacity;
	temp->top=-1;
	temp->head=NULL;
	return temp;

}
bool isfull(struct stackadt* temp)
{if(temp->top==temp->capacity-1)
	return true;
	return false;

}
bool isempty(struct stackadt* temp)
{if(temp->top==-1)
	return true;
	return false;

}
struct node* newnode(int data)
{struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	return temp;

}
void push(struct stackadt* temp,int data)
{if(isfull(temp))
	{cout<<"Stack is full.\n";
	return;


	}
	struct node* root=newnode(data);
	root->next=temp->head;
	temp->head=root;
	temp->top++;

}
int pop(struct stackadt* temp)
{if(isempty(temp))
	{cout<<"Stack is empty\n";
	return -1;

	}
	int data=temp->head->data;
	temp->head=temp->head->next;
	temp->top--;
	return data;

}
struct queueadt{
int capacity;
struct node* front;
struct node* rear;
int size;


};
struct queueadt* createqueue(int capacity)
{struct queueadt* temp=(struct queueadt*)malloc(sizeof(struct queueadt));
	temp->capacity=capacity;
	temp->size=0;
	temp->front=NULL;temp->rear=0;
	return temp;

}
bool isfull(struct queueadt* temp)
{if(temp->size==temp->capacity)
	return true;
	return false;

}
bool isempty(struct queueadt* temp)
{if(temp->front==NULL)
	return true;
	return false;


}
void push(struct queueadt* temp,int data)
{
	if(isfull(temp))
	{cout<<"Queue is full\n";
	return;

	}
	if(temp->front==NULL)
	{struct node* root=newnode(data);
		temp->front=root;
		temp->rear=root;
		temp->size++;
		return;
	}
temp->rear->next=newnode(data);
temp->rear=temp->rear->next;
temp->size++;
}
int pop(struct queueadt* temp)
{if(isempty(temp))
	{cout<<"Queue is empty\n";
	return -1;

	}
if(temp->front==temp->rear)
{int data=temp->front->data;
	temp->front=NULL;
	temp->rear=NULL;
	return data;


}
int data=temp->front->data;
temp->front=temp->front->next;
return data;
}
struct arraystack{
int capacity;
int top;
int *arr;

};
struct arraystack* createarraystack(int capacity)
{struct arraystack* temp=(struct arraystack*)malloc(sizeof(arraystack));
	temp->capacity=capacity;
	temp->top=-1;
	temp->arr=(int *)malloc(sizeof(int)*temp->capacity);
	return temp;

}
bool isempty(struct arraystack* temp)
{if(temp->top==-1)
	return true;
	return false;

}
bool isfull(struct arraystack* temp)
{if(temp->top==temp->capacity-1)
	return true;
	return false;

}
void push(struct arraystack* temp,int data)
{if(isfull(temp))
	{cout<<"Stack is full\n";
	return ;

	}
	temp->arr[++temp->top]=data;


}
int  pop(struct arraystack* temp)
{if(isempty(temp))
	{cout<<"Stack is empty\n";
	return -1;

	}
	return temp->arr[temp->top--];

}
struct arrayqueue{
int capacity;
int front;
int rear;

int *arr;

};
struct arrayqueue* createarrayqueue(int capacity)
{struct arrayqueue* temp=(struct arrayqueue*)malloc(sizeof(struct arrayqueue));
temp->capacity=capacity;
temp->front=-1;
temp->rear=-1;
temp->arr=(int *)malloc(sizeof(int)*temp->capacity);
return temp;	

}
bool isempty(struct arrayqueue* temp)
{if(temp->front==-1)
	return true;
	return false;

}
bool isfull(struct arrayqueue* temp)
{if((temp->rear+1)%temp->capacity==temp->front)
	return true;
	return false;

}
void push(struct arrayqueue* temp,int data)
{if(isfull(temp))
	{cout<<"Queue is full\n";
	return;

	}
	if(temp->front==-1)
	{temp->front=0;
		temp->rear=0;
		temp->arr[temp->rear]=data;
		return;

	}
	temp->rear=(temp->rear+1)%temp->capacity;
	temp->arr[temp->rear]=data;



}
int pop(struct arrayqueue* temp)
{if(isempty(temp))
	{cout<<"Queue is empty\n";
	return -1;

	}
	if(temp->front==temp->rear)
	{int data=temp->arr[temp->front];
		temp->rear=temp->front=-1;
		return data;

	}
	int data=temp->arr[temp->front];
	temp->front=(temp->front+1)%temp->capacity;
	return data;


}
struct heap{
int capacity;
int size;
int *arr;

};
struct heap* createheap(int capacity)
{struct heap* temp=(struct heap*)malloc(sizeof(struct heap));
	temp->capacity=capacity;
	temp->size=0;
	temp->arr=(int *)malloc(sizeof(int)*temp->capacity);
	return temp;

}
int left(struct heap* temp,int i)
{if(2*i+1<temp->size)
	return 2*i+1;
	return -1;

}
int right(struct heap* temp,int i)
{if(2*i+2<temp->size)
	return 2*i+2;
	return -1;

}
int parent(struct heap* temp,int i)
{if((i-1)/2>=0)
	return (i-1)/2;
	return -1;

}

void percolatedown(struct heap* temp,int i)
{while(i<temp->size)
	{int ans=temp->arr[i];int minindex=i;
		if(left(temp,i)!=-1)
		{if(temp->arr[left(temp,i)]<ans)
			{ans=temp->arr[left(temp,i)];
				minindex=left(temp,i);
			}
		}
		if(right(temp,i)!=-1)
		{if(temp->arr[right(temp,i)]<ans)
			{ans=temp->arr[right(temp,i)];
				minindex=right(temp,i);
			}
		}
		if(minindex!=i)
		{int inter=temp->arr[i];
			temp->arr[i]=temp->arr[minindex];
			temp->arr[minindex]=inter;
			i=minindex;
			

		}
		else if(minindex==i)
		return;


	}

}
bool isfull(struct heap* temp)
{if(temp->size==temp->capacity)
	return true;
	return false;

}
void push(struct heap* temp,int data)
{if(isfull(temp))
	{cout<<"Heap is full.\n";
	return;

	}
	temp->arr[temp->size++]=data;
	int i=temp->size-1;
	while(i>0)
	{if(temp->arr[i]<temp->arr[parent(temp,i)])
		{int inter=temp->arr[parent(temp,i)];
			temp->arr[parent(temp,i)]=temp->arr[i];
			temp->arr[i]=inter;
			i=parent(temp,i);


		}

	}

}
void display(struct heap* temp)
{for(int i=0;i<temp->size;i++)
	cout<<temp->arr[i]<<" ";
	cout<<endl;

}
int bsearch(struct node* a[],int l,int r,struct node* k)
{if(l<=r)
	{int mid=l+(r-l)/2;
		if(a[mid]==k)
			return k->data;
			if(a[mid]<k)
			return bsearch(a,mid+1,r,k);
			return bsearch(a,l,mid-1,k);

	}
	return -1;

}
int greaters(char* s)
{int count=0;
	for(int i=0;i<strlen(s);i++)
	{if(s[i]<s[0])
		count++;

	}
	return count;

}
int factorial(int n)
{int a[n+1];
	a[1]=1;a[0]=1;
	for(int i=1;i<=n;i++)
	a[i]=i*a[i-1];


return a[n];
}

int main()
{
	//lexicographic rank of a string
	char s="dcba";
	int rank=1;
	int len=strlen(s);
	int fact=factorial(strlen(s));
for(int i=0;i<len;i++)
{rank=rank+greaters(s+i)*(fact/(len-i));
	fact=fact/(len-i);

}
cout<<rank;
return 0;
}