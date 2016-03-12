#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node* next;
};
struct stack{
int capacity;
struct node* head;
int size;

};
struct node* newNode(int data)
{struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;

}
struct stack* newStack(int n)
{struct stack* temp=(struct stack*)malloc(sizeof(struct stack));
	temp->capacity=capacity;
	temp->head=NULL;
	temp->size=size;
	return temp;

}
void push(struct stack* s,int data)
{if(isfull(s))
	{cout<<"Stack is already full\n";return;}
	struct node* temp=newNode(data);
	temp->next=s->head;
	(s->size)++;
	s->head=temp;


}
bool isfull(struct stack* s)
{if(s->size==s->capacity)
	return true;
	return false;

}
bool isempty(struct stack* s)
{if(s->head==NULL)
	return true;
	return false;

}struct node* pop(struct stack*s)
{if(isempty(s))
	{cout<<"Stack is empty.\n";return;}
	struct node* temp=(s->head)->next;
	free(s->head);
	s->head=NULL;
	s->head=temp;
	(s->size)--;

}
void print(struct stack* s)
{struct node* temp=s->head;
	while(temp!=NULL)
	{cout<<temp->data<<" ";
temp=temp->next;

	}

}
struct stackarr
{int capacity;
	int *a;
	int size;
	int top;

};
struct stackarr* newStackarr(int n)
{struct stackarr* temp=(struct stackarr*)malloc(sizeof(struct stackarr));
	temp->capacity=n;
	temp->a=(int *)malloc(sizeof(int )*n);
	s->size=0;
	s->top=0;
	return temp;

}
bool isfull(struct stackarr*s)
{if(s->size==s->capacity)
	return true;
	return false;

}
bool isempty(struct stackarr* s)
{if(s->size==0)
	return true;
	return false;

}
void insert(struct stackarr*s,int data)
{if(isfull(s))
	return;
	s->a[s->top++]=data;
	(s->size)++;




}
int main()
{struct stack* s=newStack(10);
	for(int i=1;i<=10;i++)
	{push(s,i);

	}
	print(s);




return 0;	
}