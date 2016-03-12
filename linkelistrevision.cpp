#include <bits/stdc++.h>
#define SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

using namespace std;

struct node{

int data;
struct node* next;

};
struct node* newNode(int data)
{struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	return temp;

}
void append(struct node**head,int data)
{if(*head==NULL)
	*head=newNode(data);
	else{
		struct node*temp=*head;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=newNode(data);
	}

}
void push(struct node** head,int data)
{
if(*head==NULL)
	*head=newNode(data);
	else{
		struct node*temp=newNode(data);
		temp->next=*head;
		*head=temp;
	}

}
void printList(struct node* temp)
{
while(temp!=NULL)
	{cout<<temp->data<<" ";
		temp=temp->next;}
		cout<<endl;



}


int getCount(struct node* head)
{int count=0;
	while(head!=NULL)
		{count++;
			head=head->next;}
return count;
}

bool search(struct node* head,int data)
{while(head!=NULL)
	{if(head->data==data)
		return true;
		head=head->next;

	}
	return false;

}
int GetNth(struct node* head,int k)
{if(k<=0)return -1;
	int count=1;
	while(head!=NULL)
	{if(count==k)
		return head->data;
		count++;
		head=head->next;
	}
	return -1;

}


void deleteNode(struct node* head)
{head->data=head->next->data;
	struct node* temp=head->next;
	head->next=head->next->next;
	free(temp);
	temp=NULL;

}

void printMiddle(struct node* head)
{if(head==NULL)
	return;
	struct node* slow=head;struct node* fast=head;
	while(fast!=NULL)
	{
		fast=fast->next;
		if(fast==NULL)
			break;
		fast=fast->next;
		//if(fast==NULL)
		//	break;
		slow=slow->next;
	}
cout<<slow->data<<"\n";

}
void printNthFromLast(struct node* head,int n)
{struct node* temp=head;
	for(int i=1;i<n;i++)
		{head=head->next;
			if(head==NULL)
				break;}

if(head==NULL)
return;
while(head->next!=NULL)
{temp=temp->next;
	head=head->next;

}
//cout<<"sdf";
cout<<temp->data;
}
void deleteList(struct node** head)
{struct node* prev=NULL;
	if(*head==NULL)
		return;
	while(*head!=NULL)
	{prev=*head;
		*head=(*head)->next;
		free(prev);
		prev=NULL;

	}
}
int getcount(struct node* head,int i)
{int count=0;
	while(head!=NULL)
	{if(head->data==i)
		count++;
		head=head->next;
	}

return count;
}
struct node* reverse(struct node* head)
{struct node* prev=NULL;struct node* next;
	struct node* curr=head;
	while(curr)
	{next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;

	}
	return prev;

}
void detectloop(struct node* head)
{if(head==NULL)
	{cout<<"No Loop\n";
	return;

	}
	struct node* slow=head;
	struct node* fast=head;
	while(fast!=NULL)
	{fast=fast->next;
		if(fast==NULL)
		{cout<<"No Loop\n";
		return;

		}
		fast=fast->next;
		if(fast==NULL)
		{cout<<"No Loop\n";
		return;

		}
		slow=slow->next;
		if(slow==fast)
		{cout<<"Loop Exists\n";
			int count=1;
			while(slow->next!=fast)
			{slow=slow->next;
				count++;

			}
			cout<<"Length of the Loop is "<<count<<"\n";
			struct node*temp=head;
			for(int i=1;i<=count;i++)
				temp=temp->next;

			while(head!=temp)
			{head=head->next;
				temp=temp->next;

			}
			if(head==temp)
			{cout<<"Starting point of loop is "<<temp->data<<"\n";

			}
			return;
		}

	}


}
bool ispalindrome(struct node* head)
{if(head==NULL)
	return true;
	if(head->next==NULL)
		return true;
	struct node* slow=head;
	struct node* fast=head;
	while(fast!=NULL)
	{fast=fast->next;
		if(fast==NULL)
			break;
		fast=fast->next;
		if(fast==NULL)break;
		slow=slow->next;

	}
slow->next=reverse(slow->next);
struct node* temp2=slow->next;
while(temp2!=NULL&&head->data==temp2->data)
{head=head->next;
	temp2=temp2->next;

}
if(temp2==NULL)
	return true;
return false;
}
void sortedinsert(struct node** head,struct node* temp)
{if(*head==NULL)
	{*head=temp;
		return;
	}
if(temp->data<(*head)->data)
	{temp->next=*head;
		*head=temp;
	}
	struct node* head2=*head;
while(head2->next!=NULL&&temp->data>head2->next->data)
{head2=head2->next;

}
struct node*temp2=head2->next;
head2->next=temp;
temp->next=temp2;


}
void getintersection(struct node* head1,struct node* head2)
{int d1=getCount(head1);struct node* first;struct node* second;int len;
int d2=getCount(head2);
if(d1>d2)
	{ len=d1-d2;
		 first=head1;
		 second=head2;}
		else { len=d2-d1;
			 first=head1;
			second=head2;
		}
for(int i=0;i<len;i++)
{first=first->next;

}
while(first!=second)
{first=first->next;
	second=second->next;

}
if(first!=NULL)
cout<<first->data<<"\n";

}
void printreverse(struct node* head1)
{if(head1->next!=NULL)
	{printreverse(head1->next);

	}
	cout<<head1->data<<" ";

}
void removeduplicate(struct node* head)
{if(head==NULL)
	return;
	if(head->next==NULL)
		return;
	struct node* temp=NULL;
	while(head->next!=NULL)
	{	if(head->data==head->next->data)
				{temp=head->next;

		head->next=head->next->next;
		free(temp);
		temp=NULL;
	}
	else head=head->next;

	}

}
void swap(int *a,int *b)
{int temp=*a;
	*a=*b;
	*b=temp;

}
void pairwiseswap(struct node* head)
{if(head==NULL||head->next==NULL)
	return;
	swap(&(head->data),&(head->next->data));
	head=head->next->next;
	pairwiseswap(head);

}
void movebacktofront(struct node*& head)
{
	if(head==NULL||head->next==NULL)
	return;
struct node* temp2=head;
	while(temp2->next->next!=NULL)
	{temp2=temp2->next;

	}
	struct node* temp=temp2->next;
	temp->next=head;
	head=temp;
	temp2->next=NULL;

}

struct node* findintersection(struct node*a,struct node* b)
{struct node* root=NULL;
	while(a!=NULL||b!=NULL)
	{if(a==NULL)
		return NULL;
		else if(b==NULL)
			return NULL;
		if(a->data==b->data)
		{if(root==NULL)
			root=newNode(a->data);
		else {root->next=newNode(a->data);
			root=root->next;}
			root->next=findintersection(a->next,b->next);
			

		}
		else if(a->data>b->data)
		{if(root==NULL)
			root=findintersection(a,b->next);
			else root->next=findintersection(a,b->next);

		}
		else if(a->data<b->data)
		{if(root==NULL)
			root=findintersection(a->next,b);
			else root->next=findintersection(a->next,b);

		}
		return root;
	}



}
void findintersection2(struct node*&a,struct node*b)
{struct node*head=NULL;struct node*pre=head;struct node* temp=a;
	while(temp!=NULL&&b!=NULL)
	{if(temp->data<b->data)
		temp=temp->next;
		else if(b->data<temp->data)
		b=b->next;
	else if(temp->data=b->data)
	{if(head==NULL)
		{head=temp;
			pre=head;

		}
		else {
			pre->next=temp;
			pre=pre->next;
		}
		temp=temp->next;
		b=b->next;
	}

	}
	if(pre!=NULL)
pre->next=NULL;
a=head;


}
void deletealternate(struct node* head)
{
if(head==NULL||head->next==NULL)
	return;
struct node* temp=head->next;
head->next=head->next->next;
free(temp);
temp=NULL;
deletealternate(head->next);


}
void  alternatesplit(struct node*& a,struct node*& b)
{struct node*temp1=a;
	struct node* temp2=b;
	if(temp1==NULL||temp1->next==NULL)
		return;
temp1=a;temp2=a->next;
struct node*head1=temp1;
struct node* head2=temp2;
while(temp1!=NULL&&temp2!=NULL&&temp1->next!=NULL&&temp2->next!=NULL)
{temp1->next=temp2->next;
	temp1=temp1->next;
	temp2->next=temp1->next;
	temp2=temp2->next;


}
if(temp1!=NULL)
temp1->next=NULL;
if(temp2!=NULL)
temp2->next=NULL;
a=head1;
b=head2;


}
void merge2(struct node*& a,struct node*b)
{
struct node*head=NULL;
struct node* pre=NULL;
while(a!=NULL||b!=NULL)
{if(a==NULL)
	{if(head==NULL)
		head=pre=b;
		else pre->next=b;
		break;
	}
	else if(b==NULL)
	{if(head==NULL)
		head=pre=a;
		else pre->next=a;
		break;

	}
	else if(a->data<b->data)
		{if(head==NULL)
			{head=a;
				pre=head;

			}
			else{
				pre->next=a;
				pre=pre->next;
			}
			a=a->next;
		}
		else if(b->data<a->data)
		{if(head==NULL)
			{head=b;
			pre=b;
			}
			else {pre->next=b;
			pre=pre->next;
		}
		b=b->next;
		}
		else if(a->data==b->data)
		{if(head==NULL)
			{head=a;
				pre=head;

			}
			else {
				pre->next=a;
				pre=pre->next;
			}
			a=a->next;
			b=b->next;

		}

//cout<<pre->data;	
}


a=head;
//cout<<head->data;

}
struct node* merge(struct node* a,struct node* b)
{struct node* root=NULL;
	
	if(a==NULL)
		return b;
		else if(b==NULL)
			return a;
		else if(a->data<b->data)
		{root=a;
			root->next=merge(a->next,b);



		}
		else if(b->data<a->data)
		{root=b;																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																							
			root->next=merge(a,b->next);

		}
		else if(a->data==b->data)
		{root=a;
			
			root->next=merge(a->next,b->next);

		}

	
	return root;

}
struct node* reverseingroup(struct node* root,int k)
{struct node* pre=NULL;struct node* curr=root;struct node* next;
int count=0;
	while(curr!=NULL&&count<k)
	{next=curr->next;
		curr->next=pre;
		pre=curr;
		curr=next;
count++;

	}if(curr!=NULL)
	root->next=reverseingroup(curr,k);
	else root->next=NULL;
return pre;




}
struct node* reversealternategroup(struct node* head,int k)
{struct node* prev=NULL;struct node* curr=head;struct node* next;
	int count=0;
	while(count<k&&curr!=NULL)
	{next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
count++;
	}

head->next=curr;
int count2=1;
while(count2<k&&curr!=NULL)
{curr=curr->next;
count2++;
}
if(curr!=NULL&&curr->next!=NULL)
curr->next=reversealternategroup(curr->next,k);


return prev;
}

struct node* deleterightlarge(struct node* head)
{if(head==NULL||head->next==NULL)
	return head;
	struct node* prev=NULL;
	struct node* curr=head;
	struct node* next;
	while(curr!=NULL)
	{next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;

	}
	head=prev;
	//cout<<prev->data;
	struct node* store=head;
	int max=head->data;
	while(head!=NULL&&head->next!=NULL)
	{if(head->next->data<max)
		{struct node* temp=head->next;
			head->next=head->next->next;
			free(temp);
			temp=NULL;

		}
else if(head->next->data>=max)
{
max=head->next->data;
head=head->next;
	
}
}
prev=NULL;
curr=store;

while(curr!=NULL)
{next=curr->next;
	curr->next=prev;
	prev=curr;
	curr=next;

}
//cout<<prev->data;
return prev;
}
void evenoddsegregate(struct node*& head)
{if(head==NULL||head->next==NULL)
	return;
	struct node* root=head;
	struct node* end=head;
	while(end->next!=NULL)
		end=end->next;
struct node* oriend=end;
while(root->data&1&&root!=oriend)
{struct node* temp=root;
	end->next=root;
	end=end->next;
	root=root->next;
	end->next=NULL;

}
if(root==oriend)
{
	end->next=root;
	end=end->next;
	root=root->next;
	end->next=NULL;
	head=root;
}
else{
head=root;
while(root->next!=oriend)
{if(root->next->data&1)
	{end->next=root->next;
	end=end->next;
	root->next=root->next->next;
	end->next=NULL;
}
else root=root->next;

}
if(root->next->data&1)
{
	end->next=root->next;
	end=end->next;
	root->next=root->next->next;
	end->next=NULL;
}


}
}

void detectandremoveloop(struct node* root)
{struct node* head=root;
	if(root==NULL)
	return;
struct node* slow=root;
struct node* fast=root;
while(fast!=NULL)
{fast=fast->next;
	if(fast==NULL)
		return;
	fast=fast->next;
	if(fast==NULL)
		return;
	slow=slow->next;
	if(slow==fast)
		break;

}
int count=1;
while(slow->next!=fast)
{slow=slow->next;
	count++;

}
cout<<count<<"sdf";
struct node* temp=head;
while(count--)
{temp=temp->next;

}
struct node* start=head;
while(start!=temp)
{start=start->next;
	temp=temp->next;


}
while(start->next!=temp)
	start=start->next;
start->next=NULL;


}
struct node* addnumbers(struct node* a,struct node* b)
{int carry=0;struct node*root=NULL;struct node* pre=NULL;
	while(a!=NULL||b!=NULL)
	{int first=0;int second=0;
		if(a!=NULL)
			first=a->data;
		if(b!=NULL)
			second=b->data;
		int sum=(first+second+carry);
		if(sum>=10)
			carry=1;
		else carry=0;
		sum=sum%10;
		if(root==NULL)
			{root=newNode(sum);
				pre=root;}
		else {pre->next=newNode(sum);
			pre=pre->next;}
			if(a)
				a=a->next;
			if(b)
				b=b->next;

	}
if(carry>0)
	pre->next=newNode(carry);
struct node* root2=reverse(root);
return root2;
}
void rotatelist(struct node*& a,int k)
{if(a==NULL)
	return;
	struct node* head=a;struct node* end=a;
	for(int i=1;i<k;i++)
	{if(head==NULL)
		return;
		head=head->next;


	}
	while(end->next!=NULL)
		end=end->next;
	end->next=a;
	a=head->next;
	head->next=NULL;

}
struct Node{
	int data;
	struct Node* right;
	struct Node* down;
};
struct Node* newnode(int data)
{struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=data;
	temp->right=NULL;
	temp->down=NULL;
	return temp;

}
void pushs(struct Node** head,int data)
{struct Node* temp=newnode(data);
	temp->down=*head;
	*head=temp;




}
void printLists(struct Node* root)
{while(root!=NULL)
	{cout<<root->data<<" ";
	root=root->down;
}
cout<<endl;

}
struct Node* merges(struct Node* a,struct Node* b)
{struct Node* root=NULL;
	if(a==NULL)
		return b;
	if(b==NULL)
		return a;
	if(a->data<b->data)
	{root=a;
		a->down=merges(a->down,b);

	}
	if(b->data<a->data)
	{root=b;
		root->down=merges(a,b->down);


	}
	else if(a->data==b->data)
	{root=a;
		root->down=merges(a->down,b->down);

	}
return root;

}

struct Node* flatten(struct Node* root)
{if(root==NULL||root->right==NULL)
	return root;
	return merges(root,flatten(root->right));

}
void merge3(struct node* p,struct node*& q)
{struct node*first=p;
struct node* second=q;struct node* firstnext;struct node* secondnext;
while(first!=NULL&&second!=NULL)
{firstnext=first->next;secondnext=second->next;
	first->next=second;

	second->next=firstnext;
	//cout<<p->next->next->data<<"sdf";
	first=firstnext;
	second=secondnext;



}
	
if(second==NULL)
	q=second;
if(first==NULL)
	q=second;

}
struct node* reversealternate(struct node* root)
{if(root==NULL||root->next==NULL)
	return root;
	struct node* prev=NULL;
	struct node* curr=root;
	struct node* next;
	prev=root->next;
	next=prev->next;
	prev->next=root;
	if(next!=NULL)
		root->next=reversealternate(next);
	else root->next=NULL;
	return prev;



}
void pushc(struct node** head,int data)
{if((*head)==NULL)
	{*head=newNode(data);
	(*head)->next=(*head);
	return ;}
else{

struct node* temp=*head;
while(temp->next!=*head)
temp=temp->next;
struct node* temp2=newNode(data);
temp->next=temp2;
temp2->next=*head;
*head=temp2;

}
}
void printListc(struct node* root)
{if(root==NULL)
	return;
	struct node* temp=root;
	while(temp->next!=root)
	{cout<<temp->data<<" ";
	temp=temp->next;
	}
	cout<<temp->data<<" ";
	cout<<endl;

}
struct node* splitcircular(struct node* root)
{struct node* slow=root;
	struct node* fast=root;
	if(root==NULL)
		return NULL;
	if(root->next==root)
		return NULL;
	while(fast->next!=root)
	{fast=fast->next;
		if(fast->next==root)
			break;
		fast=fast->next;
				slow=slow->next;

		if(fast->next==root)
			break;


	}
		struct node* g=slow->next;
	struct node* newroot=slow->next;

	slow->next=root;
	while(g->next!=root)g=g->next;
	g->next=newroot;
	return newroot;


}
void sortedinsertc(struct node**head,int data)
{if(*head==NULL)
	{*head=newNode(data);
		(*head)->next=*head;
		return;
	}
if(data<(*head)->data)
{struct node* temp=newNode(data);
	struct node* g=*head;
	while(g->next!=*head)
		g=g->next;
	g->next=temp;
	temp->next=*head;
	*head=temp;
	return;
}
struct node* g=*head;
while(g->next->data<data&&g->next!=*head)
{g=g->next;

}
if(g->next==*head)
{struct node* temp=newNode(data);
	 g->next=temp;
	temp->next=*head;
return;
}else{
struct node* another=newNode(data);
struct node* temp=g->next;
 g->next=another;
another->next=temp;
}
}
struct dllnode{
	int data;
	struct dllnode* left;
	struct dllnode* right;
};
struct dllnode* newnodedll(int data)
{struct dllnode* temp=(struct dllnode*)malloc(sizeof(struct dllnode));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;

}
void pushd(struct dllnode** root,int data)
{if(*root==NULL)
	{*root=newnodedll(data);
	return;
}
else {


struct dllnode* temp=newnodedll(data);
temp->right=*root;
(*root)->left=temp;
*root=temp;

}
}
void printListd(struct dllnode* root)
{while(root!=NULL)
{cout<<root->data<<" ";
root=root->right;

}
cout<<endl;
}
void deletedll(struct dllnode** root,int data)
{if((*root)->data==data)
	{struct dllnode* temp=*root;
	*root=(*root)->right;
	free(temp);
	temp=NULL;
}
else{

struct dllnode* temp=*root;
while(temp->right!=NULL&&temp->data!=data)
	temp=temp->right;


if(temp->data==data)
	{temp->left->right=temp->right;
		free(temp);

	}


}

}
struct dllnode* reversedll(struct dllnode* root)
{if(root==NULL||root->right==NULL)
	return root;
	struct dllnode* prev=root;
	struct dllnode* next=root->right;


}
struct node* finalMaxSumList(struct node* a,struct node* b)
{struct node* head=NULL;struct node* prev=head;struct node*endfirst=NULL;struct node* endsecond=NULL;
	struct node* first=a;int sum1=0;int sum2=0;
	struct node* second=b;
	while(first!=NULL&&second!=NULL)
	{if(first->data<second->data)
		{sum1=sum1+first->data;
			first=first->next;

		}
		else if(second->data<first->data)
		{sum2=sum2+second->data;
			second=second->next;

		}
		else if(first->data==second->data)
		{
			if(sum1>=sum2)
			{if(head==NULL)
				{head=a;
					prev=first;

				}
				else {prev->next=endfirst->next;prev=first;}
				endfirst=first;endsecond=second;

				first=first->next;second=second->next;
				sum1=0;sum2=0;
			}
			else if(sum2>sum1)
			{if(head==NULL)
				{head=b;
				prev=second;}
else{prev->next=endsecond->next;prev=second;}
	endfirst=first;endsecond=second;

	first=first->next;second=second->next;
	sum1=0;sum2=0;
			}
			
		}

	}
if(first==NULL&&second==NULL)
	return head;
	while(first)
	{sum1=sum1+first->data;
		first=first->next;

	}
	while(second)
	{sum2=sum2+second->data;
		second=second->next;

	}
	if(sum1>=sum2)
	{if(head==NULL)
		{head=a;
			prev=head;


		}
		else{if(prev!=endfirst)
			prev->next=endfirst->next;
		}

	}
	else if(sum2>sum1)
	{
if(head==NULL)
		{head=b;
			prev=head;


		}
		else{if(prev!=endsecond)
			prev->next=endsecond->next;
		}		
	}



	return head;
} 
int main()

{

	 //Linked List 1 : 1->3->30->90->110->120->136->30->NULL
    //Linked List 2 : 0->3->12->32->90->100->120->130->NULL
    struct node *head1 = NULL;struct node *head2 = NULL;
    //push(&head2, 30);
    push(&head2, 136);
    push(&head1, 120);
    push(&head1, 110);
    push(&head1, 90);
    push(&head1, 30);
    push(&head1, 3);
    push(&head1, 1);
 
    push(&head2, 130);
    push(&head2, 120);
    push(&head2, 100);
    push(&head2, 90);
    push(&head2, 32);
    push(&head2, 12);
    push(&head2, 3);
    push(&head2, 0);
 
    struct node*root=finalMaxSumList(head1, head2);
		
 printList(root);

return 0;
}