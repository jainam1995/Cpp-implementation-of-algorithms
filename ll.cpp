#include <bits/stdc++.h>
using namespace std;
struct node
{int data;
	struct node* next;

};
struct node* newNode(int data)
{struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	return temp;

}
void push(struct node**head,int data)
{struct node* temp=newNode(data);
	temp->next=*head;
	*head=temp;

}
struct node* reverse(struct node* head)
{struct node* prev=NULL;

	struct node* curr;
	struct node* next;
	curr=head;
	while(curr!=NULL)
	{next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;

	}
	return prev;

}
int count(struct node* head)
{int count=0;
	while(head!=NULL)
	{count++;
		head=head->next;

	}
	return count;

}
void printList(struct node* head)
{while(head!=NULL)
	{cout<<head->data<<" ";
		head=head->next;
		}

}
int getNth(struct node* head,int n)
{int count=1;
	while(head!=NULL&&count!=n)
		{head=head->next;count++;}
	if(head!=NULL)
		return head->data;

}
int getNthfromend(struct node* head,int n)
{int count=1;struct node* curr=head;
	while(head!=NULL&&count!=n)
		{head=head->next;count++;}
	if(head!=NULL)
	{
		while(head->next!=NULL)
		{head=head->next;curr=curr->next;}
		return curr->data;

	}
}
bool search(struct node* head,int data)
{while(head!=NULL)
	{if(head->data==data)
		return true;
		head=head->next;

	}
	return false;

}
struct node* getmiddle(struct node* head)
{
	struct node*slow=head;
	struct node*fast=head;
	while(fast->next!=NULL)
	{fast=fast->next;
		if(fast->next==NULL)
			break;
		fast=fast->next;
		slow=slow->next;


	}
	return slow;

}

struct node* pairwiseswap(struct node* head)
{if(head==NULL||head->next==NULL)
	return head;
	struct node* ans=head->next;
	struct node* prev=head->next->next;
	head->next->next=head;
	head->next=pairwiseswap(prev);
	return ans;

}
struct node* lasttofront(struct node* head)
{if(head==NULL)
	return NULL;
	if(head->next==NULL)
		return head;
	struct node* root=head;
	while(head->next->next!=NULL)
	{
		head=head->next;
	}
	struct node* ans=head->next;
ans->next=root;
root=ans;
head->next=NULL;
return root;


}struct node* deletealt(struct node* head)
{if(head==NULL||head->next==NULL)
	return head;struct node* temp;
	while(head!=NULL&&head->next!=NULL)
	{temp=head->next;
		head->next=head->next->next;
		free(temp);
		temp=NULL;
head=head->next;
	}

}
struct node* altsplit(struct node*a,struct node* b)
{if(a==NULL||b==NULL)
return b;
struct node* first=a;struct node* second=b;
struct node* firstnext=first->next;struct node* secondnext=second->next;
while(first!=NULL&&second!=NULL)
{firstnext=first->next;
	secondnext=second->next;
	first->next=second;
	second->next=firstnext;
	first=firstnext;
	second=secondnext;

}
return second;
}
struct node* splitalt(struct node* head)
{if(head==NULL)
	return NULL;
	if(head->next==NULL)
		return NULL;
	struct node* first=head;
	struct node* second=head->next;
	struct node* ans=second;
	while(first!=NULL&&second!=NULL)
	{first->next=second->next;
		first=first->next;
		if(first==NULL)
			break;
		second->next=first->next;
		second=second->next;

	}
return ans;

}
struct node* merge(struct node* a,struct node* b)
{if(a==NULL)
	return b;
	if(b==NULL)
		return a;
	struct node* res;
	if(a->data<b->data)
	{res=a;
		res->next=merge(a->next,b);


	}
	else if(b->data<a->data)
	{res=b;
		res->next=merge(a,b->next);

	}
	else if(a->data==b->data)
	{res=a;
		res->next=merge(a->next,b->next);

	}
return res;
}
struct node* mergeiter(struct node* a,struct node* b)
{if(a==NULL)
	return b;
	if(b==NULL)
		return a;
	struct node* head=NULL;
	struct node*res=head;
	while(a!=NULL&&b!=NULL)
	{if(a->data<b->data)
		{if(head==NULL)
			{head=a;res=head;}
			else {
				res->next=a;
				res=res->next;
			}
			a=a->next;

		}
		else if(b->data<a->data)
		{if(head==NULL)
			{head=b;res=head;}
			else{
				res->next=b;
				res=res->next;
			}
			b=b->next;

		}
		else{if(head==NULL)
			{head=a;res=head;}
			else{res->next=a;
				res=res->next;}
				a=a->next;
				b=b->next;


		}

	}
	if(a!=NULL)
		res->next=a;
	else if(b!=NULL)
		res->next=b;
	return head;
}
struct node* reverseingroups(struct node* head,int k)
{struct node* prev=NULL;struct node* next;struct node* curr=head;int count=0;
	while(curr!=NULL&&count<k)
	{next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
		count++;

	}
	if(curr!=NULL)
		head->next=reverseingroups(curr,k);
	return prev;

}
struct node* altkreverse(struct node*head,int k)
{struct node* prev=NULL;
	struct node*curr=head;struct node*next;int count=0;
	while(curr!=NULL&&count<k)
	{next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
		count++;


	}
	head->next=curr;count=1;
	while(curr!=NULL&&count<k)
		{curr=curr->next;count++;}
	if(curr!=NULL&&curr->next!=NULL)
	{curr->next=altkreverse(curr->next,k);


	}
	return prev;

}
struct node* segevenodd(struct node* head)
{if(head==NULL||head->next==NULL)
	return head;
	struct node*evenbodd;
	struct node* root=head;struct node* temp=head;
	if(head->data%2!=0)
	{while(head->next!=NULL&&head->next->data%2!=0)
		head=head->next;
		if(head->next==NULL)
			return root;
		struct node* ans=head->next;
		head->next=head->next->next;
		ans->next=root;
		root=ans;
		evenbodd=root;

	}
	else{
		while(temp->next!=NULL&&temp->next->data%2==0)
			temp=temp->next;
		if(temp->next==NULL)
			return root;
		else evenbodd=temp;

	}struct node* t;
	struct node* temp2=evenbodd;
	while(temp2->next!=NULL)
	{if(temp2->next->data%2==0)
		{t=temp2->next->next;
			temp2->next->next=evenbodd->next;
			evenbodd->next=temp2->next;
			temp2->next=t;
			evenbodd=evenbodd->next;

		}
		else{
			temp2=temp2->next;
		}

	}

return root;
}
struct node* addlinkedlist(struct node* a,struct node* b)
{struct node* head=NULL;struct node* res=head;int carry=0;int sum;int rem;
	while(a!=NULL||b!=NULL)
	{int one=0;int two=0;
		if(a)
			one=a->data;
		if(b)
			two=b->data;
		sum=one+two+carry;
		rem=sum%10;
		if(sum>=10)
			carry=1;
		else carry=0;
		if(head==NULL)
			{head=newNode(rem);
		res=head;}
		else {res->next=newNode(rem);
		res=res->next;}
		if(a)
			a=a->next;
		if(b)
			b=b->next;

	}
	if(carry)
		res->next=newNode(carry);
return head;
}
struct node* intersect(struct node*a,struct node*b)
{if(a==NULL||b==NULL)
	return NULL;
	struct node* res;
	if(a->data<b->data)
		{res=a;
			res->next=intersect(a->next,b);}
			else if(b->data<a->data)
			{res=b;
				res->next=intersect(a,b->next);

			}
			else{
				res=a;
				res->next=intersect(a->next,b->next);
			}

}
struct node* rotate(struct node* head,int k)
{int count=1;
	struct node* root=head;
	while(head!=NULL&&count<k)
	{head=head->next;count++;

	}
	if(head==NULL||head->next==NULL)
		return reverse(root);
struct node* head2=head->next;
head->next=NULL;
struct node* f=head2;
while(f->next!=NULL)
f=f->next;
f->next=root;
root=head2;



}
int main()
{ struct node* res = NULL;
    struct node* first = NULL;
    struct node* second = NULL;

    // create first list 7->5->9->4->6
    push(&first, 6);
    push(&first, 4);
    push(&first, 9);
    push(&first, 5);
    push(&first, 7);
    printf("First List is ");
    printList(first);

   
    res = rotate(first, 5);
    printf("Resultant list is ");
    printList(res);

return 0;	
}