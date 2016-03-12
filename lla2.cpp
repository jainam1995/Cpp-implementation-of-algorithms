#include <bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node* next;


};
struct node* newNode(int data)
{struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	return temp;

}
struct node* insert(struct node* head,int data)
{struct node* temp=newNode(data);
	temp->next=head;
	head=head;
return head;

}
void push(struct node** head,int data)
{struct node* temp=newNode(data);
	temp->next=(*head);
	*head=temp;



}
void printList(struct node* head)
{while(head)
	{cout<<head->data<<" ";
	head=head->next;

	}cout<<endl;

}
void printMiddle(struct node* head)
{if(head==NULL)
	return;
 struct node* slow=head;
 struct node* fast=head;
 while(fast)
 {if(fast->next==NULL)
 	break;
 	fast=fast->next;
 	if(fast->next==NULL)
 		break;
 	slow=slow->next;
 	fast=fast->next;

 }
cout<<slow->data<<" ";
}
void printNthFromLast(struct node* head,int k)
{int count=1;struct node* temp=head;
	while(count<k&&temp!=NULL)
	{temp=temp->next;count++;

	}
	if(temp==NULL)
		return;
	while(temp->next!=NULL)
	{head=head->next;
		temp=temp->next;

	}
cout<<head->data<<" ";
}
struct node* reverse(struct node* head)
{struct node* prev=NULL;struct node* curr=head;struct node* next;
	while(curr)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;


	}
	return prev;

}
void reverse(struct node** head)
{if(*head==NULL)
	return;
	struct node* temp=(*head)->next;
	if(temp==NULL)
		return;
	reverse(&temp);
	(*head)->next->next=*	head;
	(*head)->next=NULL;
	*head=temp;


}
void detectloop(struct node* head)
{if(head==NULL)
	return;
	struct node* slow=head;
	struct node* fast=head;
	while(fast!=NULL)
	{if(fast->next==NULL)
		return;
		fast=fast->next;
		if(fast->next==NULL)
			return;
		slow=slow->next;fast=fast->next;
		if(slow==fast)
			break;

	}

int count=1;
while(slow->next!=fast)
{slow=slow->next;
	count++;

}
//cout<<count;
int i=0;struct node* temp2=head;
while(i<count)
{temp2=temp2->next;
i++;
}
while(head!=temp2)
{temp2=temp2->next;
	head=head->next;

}
while(head->next!=temp2)
	head=head->next;
head->next=NULL;


}
int count(struct node* head)
{int count=0;
	while(head)
	{count++;
		head=head->next;

	}
return count;
}
int getIntesectionNode(struct node* a,struct node* b)
{struct node* first;int len1;struct node* second;int len2;
int count1=count(a);
int count2=count(b);
if(count1<=count2)
{first=b;
	len1=count2;
	second=a;
	len2=count1;


}
else{
first=a;second=b;
len1=count1;len2=count2;

}

int diff=len1-len2;
int count=0;
while(count<diff)
{first=first->next;count++;}
while(first!=second)
{first=first->next;second=second->next;

}
return first->data;	
}
void removeDuplicates2(struct node* head)
{if(head==NULL||head->next==NULL)
	return;
	while(head->next!=NULL)
	{if(head->next->data==head->data)
		{struct node* temp=head->next;
			head->next=temp->next;
			free(temp);
			temp=NULL;

		}
		else {head=head->next;}

	}

}void removeDuplicates(struct node* head)
{map<int ,bool> hash;
	if(head==NULL)
	return;
	hash[head->data]=true;
	while(head->next!=NULL)
	{if(hash.find(head->next->data)==hash.end()){
		hash[head->next->data]=true;
		head=head->next;
	}
	else{
		struct node* temp=head->next;
		head->next=temp->next;
		free(temp);
		temp=NULL;
	}

	}

}
struct node* pairWiseSwap(struct node* head)
{if(head==NULL||head->next==NULL)
	return head;
	struct node* prev=head->next;
	struct node* final=prev->next;
	head->next->next=head;
	head->next=pairWiseSwap(final);
	return prev;



}
struct node* sortedIntersect(struct node* a,struct node* b)
{struct node* res=NULL;
	if(a==NULL)
		return b;
	if(b==NULL)
		return a;
	if(a->data<=b->data)
	{res=a;
		res->next=sortedIntersect(a->next,b);

	}
	else{
		res=b;
		res->next=sortedIntersect(a,b->next);
	}
return res;

}
struct node* sortedIntersect2(struct node* a,struct node* b)
{struct node* res=NULL;
	if(a==NULL||b==NULL)
		return NULL;
	if(a->data<b->data)
	{res=sortedIntersect2(a->next,b);


	}
	else if(b->data<a->data)
	{res=sortedIntersect2(a,b->next);

	}
else{
	res=a;
	res->next=sortedIntersect2(a->next,b->next);
}
return res;	
}
void deleteAlt(struct node* head)
{if(head==NULL||head->next==NULL)
	return;
	while(head!=NULL&&head->next!=NULL)
	{struct node* temp=head->next;
		head->next=temp->next;head=head->next;
		free(temp);
		temp=NULL;

	}

	

}
void AlternatingSplit(struct node* head,struct node**a,struct node**b)
{if(head==NULL)
	return;
	if(head->next==NULL)
	{*a=head;
		return;

	}
	*a=head;
	*b=head->next;
	struct node* first=*a;
	struct node*second=*b;
	head=head->next;
	while(first&&second)
	{first->next=second->next;
		first=first->next;
		if(first==NULL)
			break;
		second->next=first->next;
		second=second->next;

	}

}
struct node* reverse(struct node* head,int k)
{struct node* prev=NULL;
	struct node* next;
	struct node* curr=head;int count=0;
	while(curr!=NULL&&count<k)
	{next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
		count++;

	}
	if(curr==NULL)
		return prev;
	head->next=reverse(curr,k);
	return prev;

}
struct node* altreverse(struct node* head,int k)
{struct node* curr=head;struct node* prev=NULL;struct node* next;
int count=0;
	while(curr!=NULL&&count<k)
	{next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
		count++;

	}
	if(curr==NULL)
		return prev;
	head->next=curr;
	count=1;
	while(count<k&&curr!=NULL)
	{curr=curr->next;
		count++;

	}
if(curr==NULL)
	return prev;
curr->next=altreverse(curr->next,k);
return prev;


}
void segregateEvenOdd(struct node**head)
{

}
void printLisst	(struct node* head)
{while(head!=NULL)
	{cout<<head->data<<" ";
	head=head->next;

	}

}
struct node* addTwoLists(struct node* a,struct node* b)
{struct node* res=NULL;int sum=0;int carry=0;int first=0;int second=0;struct node* temp;
while(a||b)
{if(a)
	first=a->data;
	else first=0;
	if(b)
		second=b->data;
	else second=0;
	 sum=carry+first+second;
	 if(sum>=10)
	 	carry=1;
	 else carry=0;
	 sum=sum%10;
	 if(res==NULL)
	 	{res=newNode(sum);temp=res;}
	 else {temp->next=newNode(sum);temp=temp->next;}
	 if(a)
	 	a=a->next;
	 if(b)
	 	b=b->next;



}
if(carry)
{temp->next=newNode(1);


}
return res;

}
int main()
{      struct node* res = NULL;
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
 
    // create second list 8->4
    push(&second, 4);
    push(&second, 8);
    printf("Second List is ");
    printList(second);
 
    // Add the two lists and see result
    res = addTwoLists(first, second);
    printf("Resultant list is ");
    printLisst(res);
    return 0;
}
