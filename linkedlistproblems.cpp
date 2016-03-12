#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <queue>
using namespace std;
struct node{
int data;
struct node* next;


};
struct node* newnode(int data)
{struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	return temp;


}
void push(struct node** head_ref,int data)
{if(*head_ref==NULL)
	*head_ref=newnode(data);
else{

struct node* temp=newnode(data);
temp->next=*head_ref;
*head_ref=temp;

}

}
int getCount(struct node* head)
{int count=0;
	while(head!=NULL)
	{head=head->next;
		count++;

	}
return count;
}

bool search(struct node* head,int data){
	if(head==NULL)
		return false;
	if(head->data==data)
		return true;
	return search(head->next,data);
}
int GetNth(struct node* head,int index)
{index--;
	while(index--)
{if(head==NULL)
	return -1;
	head=head->next;




}
return head->data;
}
void printList(struct node* head)
{while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
cout<<"\n";
}
struct node* deleteNode(struct node* head,struct node* pointer)
{if(pointer==NULL)
	return head;
	if(pointer==head)
	{struct node* temp=head;
	head=head->next;
	free(temp);
	return head;
}
else{struct node* temp=head;
	while(temp->next!=pointer)
		{temp=temp->next;}
	struct node* del=temp->next;
	temp->next=temp->next->next;
free(del);
return head;
}

}
struct node* printMiddle1(struct node* head)
{if(head==NULL)
	return NULL;
	struct node*slow=head;
	struct node* fast=head;
	while(true)
	{if(fast->next!=NULL)
		{slow=slow->next;
			fast=fast->next;

		}
		else if(fast->next==NULL)
			{//cout<<slow->data<<"\n";
			return slow;
				}
		if(fast->next!=NULL)
			fast=fast->next;
		else if(fast->next==NULL)
			{//cout<<slow->data<<"\n";


		return slow;
	}
	}



}
void printMiddle2(struct node* head)
{if(head==NULL)
return;
struct node* slow=head;
struct node* fast=head;
while (true)
{if(fast->next&&fast->next->next)
	{slow=slow->next;
		fast=fast->next->next;
	}
else{
	cout<<slow->data<<"\n";
	break;
}

}
}
void printNthFromLast(struct node* head,int count)
{
	int n=getCount(head);

	if(count>n)
	{	cout<<"not as many nodes in the linked list\n";
	return;
}
	struct node* first=head;
	struct node* second=head;
	for(int i=0;i<count-1;i++)
		{first=first->next;}
	while(first->next!=NULL)
		{first=first->next;
			second=second->next;}
			cout<<second->data<<"\n";
}
void deleteList(struct node** head)
{
	if(*head==NULL)
		return;
	struct node** temp=head;
	*head=(*head)->next;
	free(*temp);
	*temp=NULL;
	deleteList(head);
}
int count(struct node* head,int data)
{if(head==NULL)
	return 0;
	int count=0;
while(head!=NULL)
{if(head->data==data)
	count++;
	head=head->next;

}
return count;

}
struct node* reverse(struct node** head_ref)
{
struct node* head=*head_ref;
if(head==NULL)
return NULL;
struct node* prev=NULL;
struct node* curr=head;
struct node* next;
while(curr)
{next=curr->next;
	curr->next=prev;
	prev=curr;
	curr=next;



}
*head_ref=prev;
return prev;
}
void recursivereverse(struct node** head_ref)
{struct node* first;
	struct node* rest;
	if(*head_ref==NULL)
		return;
	first=*(head_ref);
	rest=(*(head_ref))->next;
	if(rest==NULL)
		return;
	recursivereverse(&rest);
	first->next->next=first;
	first->next=NULL;

	*head_ref=rest;




}
bool detectloop(struct node* head)
{if(head==NULL)
	return false;
	struct node* slow=head;
	struct node* fast=head;
while(fast->next!=NULL&&fast->next->next!=NULL)
{
	{slow=slow->next;
		fast=fast->next->next;

	}if(slow==fast)
	return true;

}
return false;
}
bool isPalindrome(struct node* head)
{
struct node* middle=printMiddle1(head);
struct node* temp=head;
if(getCount(head)==1)
return true;
if(getCount(head)&1)
middle=middle->next;
while(temp->next!=middle)
	temp=temp->next;
temp->next=reverse(&middle);
middle=temp->next;

while(middle!=NULL)
{if(head->data!=middle->data)
	return false;
head=head->next;
middle=middle->next;

}
return true;
}
void sortedInsert(struct node** head_ref,struct node* nodes)
{if(*head_ref==NULL)
	{*head_ref=nodes;
	return;}
	if(nodes->data<(*head_ref)->data)
		{nodes->next=*head_ref;
	*head_ref=nodes;
return;}
	else{
struct node*temp=*head_ref;
while(temp!=NULL)
{
	if(temp->next==NULL)
		{temp->next=nodes;
			return;

		}

if(temp->next->data<=nodes->data)
	temp=temp->next;
else{ struct node* another=temp->next;
temp->next=nodes;
nodes->next=another;
return;

}

}


	}
	
}
int getIntesectionNode(struct node* head1,struct node* head2)
{int l1=getCount(head1);int max;int min;
	int l2=getCount(head2);
	struct node* longs;struct node* shorts;
	if(l1==0||l2==0)return -1;
	if(l1>l2)
		{max=l1;
			min=l2;
			longs=head1;
			 shorts=head2;}
else{max=l2;
min=l1;
longs=head2;
			 shorts=head1;}
int common=max-min;
for(int i=0;i<common;i++)
{longs=longs->next;


}
while(shorts!=NULL&&longs!=NULL)
{if(shorts==longs)
	return shorts->data;
	else{
longs=longs->next;
shorts=shorts->next;

	}

}

}
struct node* removeduplicateutil(struct node* head)
{
	if(head==NULL)
		return NULL;
	if(head->next==NULL)
		return head;
	if(head->next->data==head->data)
	{
		struct node*temp=head->next;
		head->next=head->next->next;
		free(temp);
		removeduplicateutil(head);
	}
	else removeduplicateutil(head->next);

	return head;
}
void removeDuplicates(struct node* head)
{head=removeduplicateutil(head);

}
void moveToFront(struct node** head)
{if(*head==NULL||(*head)->next==NULL)
	return;
	struct node* temp=*head;

	while(temp->next->next!=NULL)
	{temp=temp->next;
		//cout<<"SDf"<<temp->data<<" ";
	}
temp->next->next=*head;
		*head=temp->next;
		temp->next=NULL;

}
struct node* sortedIntersect(struct node* a,struct node* b)
{struct node* head=NULL;
	struct node* curr=NULL;
	while(a!=NULL&&b!=NULL)
	{if(a->data<b->data)
		{push(&head,a->data);
			
			a=a->next;
}
else if(b->data<a->data)
{push(&head,b->data);
	b=b->next;
			//cout<<head->data<<"sd";

	}
	else
		{push(&head,a->data);
			a=a->next;
			b=b->next;
					//cout<<head->data<<"sd";
}

}
while(a!=NULL)
	{push(&head,a->data);
			a=a->next;
					//cout<<head->data<<"sd";

	}
	while(b!=NULL)
	{push(&head,b->data);
			b=b->next;
					//cout<<head->data<<"sd";

	}
			

			//while(head!=NULL)
				//cout<<head->data<<" ";
	return head;
}
void deleteAlt(struct node* head)
{
	while(head!=NULL&&head->next!=NULL)
	{struct node* temp=head->next;
		head->next=temp->next;
		free(temp);
		head=head->next;

	}
}
void AlternatingSplit(struct node* head,struct node**a,struct node**b)
{
	if(head==NULL)
		return;
	struct node* first;
	struct node*second;
	first=head;
	second=head->next;
	*a=first;
	*b=second;
	while(first!=NULL && first->next!=NULL && second!=NULL && second->next!=NULL )
	{first->next=first->next->next;
		first=first->next;
		second->next=second->next->next;
		second=second->next;

	}
	while(second!=NULL && second->next!=NULL)
	{second->next=second->next->next;
		second=second->next;

	}
	while(first!=NULL && first->next!=NULL  )
	{first->next=first->next->next;
		first=first->next;
		

}
}
struct node* SortedMerge(struct node* a,struct node*b)
{

	struct node*head=NULL;struct node* temp;
	if(a==NULL)
		return b;
	if(b==NULL)return a;
	if(a->data<b->data)
		{head=a;
			temp=head;
			a=a->next;
		}
		else if(b->data<a->data){head=b;temp=head;
			b=b->next;}
			else{head=a;
				temp=head;
				a=a->next;
				b=b->next;
			}
	while(a!=NULL&&b!=NULL)
	{if(a->data<b->data)
		{temp->next=a;
			temp=temp->next;
			a=a->next;

		}
		else if(b->data<a->data)
		{temp->next=b;
			temp=temp->next;
			b=b->next;

		}
		else{
			temp->next=a;
			temp=temp->next;
			a=a->next;
			b=b->next;
		}

}
if(a!=NULL)
	{temp->next=a;
	}
else temp->next=b;

return head;
}
void segregateEvenOdd(struct node** heads)
{struct node* head=*heads;struct node* another2=head;
struct node* temp=head;
while(temp->next !=NULL)
temp=temp->next;

while(another2->next !=NULL)
{if(another2->data%2==0)
	break;
another2=another2->next;
}
struct node* end=temp;

while(head!=end)
	{if(head->data%2!=0){
struct node* g=head;

temp->next=g;
head=head->next;
g->next=NULL;
temp=g;
cout<<temp->data<<" ";
	}
else head=head->next;
}


*heads=another2;
}
int main()
{
  struct node *p = NULL, *q = NULL;
     push(&p, 3);
     push(&p, 2);
     push(&p, 1);
     printf("First Linked List:\n");
     printList(p);
 
     push(&q, 8);
     push(&q, 7);
     push(&q, 6);
     push(&q, 5);
     push(&q, 4);
     printf("Second Linked List:\n");
     printList(q);
 
     merge(p, &q);
 
     printf("Modified First Linked List:\n");
     printList(p);
 
     printf("Modified Second Linked List:\n");
     printList(q);

	return 0;
}