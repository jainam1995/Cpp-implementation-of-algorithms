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

}
struct node* push(struct node* head,int data)
{struct node* temp=newNode(data);
	temp->next=head;
	head=temp;
	return head;

}
void push(struct node** head,int data)
{if(*head==NULL)
	*head=newNode(data);
	else{
		struct node* temp=newNode(data);
		temp->next=*head;
		*head=temp;
	}

}
int getCount(struct node* head)
{int count=0;
	while(head)
	{count++;
		head=head->next;

	}
return count;
}
void printList(struct node*head)
{while(head)
	{cout<<head->data<<" ";
	head=head->next;

	}
	cout<<endl;

}
bool search(struct node* head,int data)
{while(head)
	{if(head->data==data)
		return true;
		head=head->next;
	}
return false;

}
int getnth(struct node* head,int n)
{int count=1;
	while(head!=NULL&&count<n)
	{head=head->next;count++;}
if(head==NULL)
	return -1;
return head->data;

}
int middle(struct node* head)
{if(head==NULL)
	return -1;
	struct node* slow=head;
	struct node* fast=head;
	while(fast!=NULL)
	{if(fast->next==NULL)
		break;
		fast=fast->next;
		if(fast->next==NULL)
			break;
		fast=fast->next;
		slow=slow->next;

	}
	return slow->data;

}
struct node* deletell(struct node* head)
{if(head==NULL)
	return NULL;
	struct node* temp;
	while(head->next!=NULL)
	{temp=head->next;
		free(head);
		head=NULL;
		head=temp;

	}
	return NULL;

}
void printNthFromLast(struct node* head,int n)
{struct node* start=head;
	int count=1;
	while(head!=NULL&&count<n)
		{head=head->next;count++;}
	if(head==NULL)
		return;
	while(head->next!=NULL)
	{start=start->next;
		head=head->next;

	}
	cout<<start->data<<"\n";

}
void detectloop(struct node* head)
{struct node* final=head;
	struct node* start2=head;
	struct node* start=head;
	if(head==NULL)
	{cout<<"No loop\n";return;}
	struct node* slow=head;struct node* fast=head;
	while(true)
	{if(fast==NULL)
		{cout<<"No loop\n";return;}
		if(fast->next==NULL)
		{cout<<"No loop\n";return;}
		fast=fast->next;
		if(fast->next==NULL)
			{cout<<"No loop\n";return;}
		fast=fast->next;
		slow=slow->next;
		if(fast==slow)
			break;


	}
	cout<<"Loop present\n";
	int count=1;
	while(slow->next!=fast)
		{slow=slow->next;count++;}
	cout<<"Length of loop is "<<count<<"\n";

int a=0;
while(a!=count)
{start=start->next;
	a++;

}
while(start!=start2)
{start=start->next;
	start2=start2->next;

}
while(start->next!=start2)
start=start->next;
start->next=NULL;
printList(final);
}
struct node* reverse(struct node* head)
{struct node* prev=NULL;
	struct node* next;
	struct node* curr=head;
	while(curr)
	{next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;

	}
	return prev;

}
bool isPalindrome(struct node* head)
{struct node* start=head;
	if(head==NULL)
	return true;
	struct node* slow=head;
	struct node* fast=head;
	while(fast!=NULL)
	{if(fast->next==NULL)
		break;
		fast=fast->next;
		if(fast->next==NULL)
			break;
			fast=fast->next;
			slow=slow->next;

	}
	slow->next=reverse(slow->next);
	struct node* temp=slow->next;
	while(temp!=NULL)
	{if(start->data!=temp->data)
		{slow->next=reverse(slow->next);
			return false;

		}
		temp=temp->next;
		start=start->next;


	}
	slow->next=reverse(slow->next);
	return true;

}
struct node* sortedinsert(struct node* head,int data)
{struct node* root=head;
	if(head==NULL)
	{head=newNode(data);return head;}
if(data<head->data)
{struct node* temp=newNode(data);
	temp->next=head;
	head=temp;
	return head;
}
while(head->next!=NULL&&head->next->data<data)
{head=head->next;

}
struct node* temp=head->next;
head->next=newNode(data);
head->next->next=temp;
return root;
}
int getIntesectionNode(struct node*a,struct node* b)
{struct node* first;int len1;struct node* second;int diff;
	int len2;
	struct node* s1=a;struct node* s2=b;int count1=0;int count2=0;
	while(s1)
		{count1++;
			s1=s1->next;}
while(s2)
{count2++;
	s2=s2->next;

}
if(count1>count2)
{first=a;
	len1=count1;
	second=b;
	len2=count2;
	diff=count1-count2;

}
else {
	first=b;
	len1=count2;
	second=a;
	len2=count1;
	diff=count2-count1;
}
//first is longer linked list

while(diff--)
{first=first->next;

}
while(first!=second)
{first=first->next;
second=second->next;}
return first->data;
}

void removeDuplicates(struct node* head)
{if(head==NULL||head->next==NULL)
	return;
	struct node* temp;
	map<int ,bool>hash;
	hash[head->data]=true;
	while(head->next!=NULL)
	{if(hash.find(head->next->data)==hash.end())
		{hash[head->next->data]=true;
			head=head->next;

		}
		else
		{temp=head->next;
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
	struct node* next=prev->next;
	head->next->next=head;
	head->next=pairWiseSwap(next);
	return prev;



}
void moveToFront(struct node**head)
{if(*head==NULL||(*head)->next==NULL)
	return;
	struct node*temp=*head;
	while(temp->next->next!=NULL)
		temp=temp->next;
	struct node* ans=temp->next;
	ans->next=*head;
	*head=ans;
	temp->next=NULL;


}
void deleteAlt(struct node* head)
{if(head==NULL||head->next==NULL)
	return;
	struct node* temp;
	while(head!=NULL&&head->next!=NULL)
	{temp=head->next;
		head->next=temp->next;
		free(temp);
		temp=NULL;
		head=head->next;


	}

}
void AlternatingSplit(struct node* head,struct node**a,struct node**b)
{if(head==NULL)
	return;
	*a=head;
	*b=head->next;
	if(head->next==NULL)
		return;
	struct node*one=head;struct node*two=head->next;
	while(one&&two)
	{one->next=two->next;
		one=one->next;
		if(one==NULL)
			break;
		two->next=one->next;
		two=two->next;


	}
	if(one)
		one->next=NULL;
	if(two)
		two->next=NULL;

}struct node* SortedMerge(struct node* a,struct node*b)
{if(a==NULL)
	return b;
	if(b==NULL)
		return a;
	struct node* res;
	if(a->data<b->data)
	{ res=a;
		a->next=SortedMerge(a->next,b);

	}
	else if(b->data<a->data)
	{ res=b;
		res->next=SortedMerge(a,b->next);
		
	}
	else {
			 res=a;
			res->next=SortedMerge(a->next,b->next);
		}

	return res;

}
struct node* SortedMergeiter(struct node*a,struct node* b)
{if(a==NULL)
	return b;
	if(b==NULL)
		return a;
	struct node* head=NULL;
	struct node* res=head;
	while(a!=NULL&&b!=NULL)
	{if(a->data<=b->data)
		{if(head==NULL)
			{head=a;
				res=head;
				head=head->next;

			}
			else{
				res->next=a;
				res=res->next;
				a=a->next;
			}

		}
		else if(a->data>b->data)
		{if(head==NULL)
			{head=b;
				res=head;
				b=b->next;

			}
			else{
				res->next=b;
				res=res->next;
				b=b->next;


			}

		}

	}
	if(a)
		res->next=a;
	else if(b)
		res->next=b;
	return head;
}
struct node* reverse(struct node* head,int k)
{struct node* prev=NULL;
	struct node* curr=head;
	struct node* next;
	int count=0;
	while(curr&&count<k)
	{next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;count++;

	}
	if(curr==NULL)
		return prev;
	head->next=reverse(curr,k);
	return prev;

}
struct node* kAltReverse(struct node* head,int k)
{struct node* prev=NULL;
	struct node* curr=head;
	struct node* next;
	int count=0;
	while(curr&&count<k)
	{next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
		count++;

	}head->next=curr;
	if(curr==NULL)
		return prev;
	count=1;
	while(curr!=NULL&&count<k)
	{curr=curr->next;count++;

	}
	if(curr==NULL)
		return prev;
	curr->next=kAltReverse(curr->next,k);
	return prev;

}
struct node* delLesserNodes(struct node* head)
{if(head==NULL||head->next==NULL)
	return head;
	struct node* temp=reverse(head);
	struct node* g=temp;
	int max=temp->data;
	struct node* a;
	while(temp->next!=NULL)
	{if(temp->next->data<max)
		{a=temp->next;temp->next=a->next;
			free(a);
			a=NULL;

		}
		else{
			max=temp->next->data;
			temp=temp->next;
		}

	}
	return reverse(g);


}
void segregateEvenOdd(struct node** head)
{struct node* root=*head;struct node* firsteven;
	if(root->data%2!=0)
		{struct node* temp=root;
			while(temp->next&&temp->next->data%2!=0)
			{temp=temp->next;

			}
			if(temp->next==NULL)
				return;
			struct node* p=temp->next;
			temp->next=p->next;
			p->next=root;
			firsteven=p;
			*head=p;

		}
	else{struct node* temp=root;
		while(temp->next&&temp->next->data%2==0)
			temp=temp->next;
		if(temp->next==NULL)
			return;
		firsteven=temp;



	}
	struct node* g=firsteven;
	while(g->next)
	{if(g->next->data%2==0)
		{struct node* p=g->next;
			g->next=p->next;
			p->next=firsteven->next;
			firsteven->next=p;
			firsteven=p;

		}
		else g=g->next;

	}


}
struct node* addTwoLists(struct node*a,struct node* b)
{struct node* head=NULL;
	struct node*res=head;
	int a1;int b1;int ans;int carry=0;int sum;
	while(a||b)
	{if(a)
		a1=a->data;
	else a1=0;
	if(b)
		b1=b->data;
	else b1=0;
	 sum=a1+b1+carry;
	cout<<"sum"<<sum;
	 ans=sum%10;
	 carry=sum/10;
	cout<<"carry"<<carry;
	if(head==NULL)
	{head=newNode(ans);
		res=head;

	}
	else {res->next=newNode(ans);res=res->next;}

	if(a)
		a=a->next;
	if(b)
		b=b->next;


	}
	if(carry)
	{if(head==NULL)
		head=newNode(carry);
		else res->next=newNode(carry);

	}
return head;

}
void merge(struct node* p,struct node**q)
{if(p==NULL||(*q)==NULL)
	return;
	struct node* firstsecond;
	struct node* secondsecond;
	struct node* first=p;
	struct node* second=*q;
	while(first&&second)
	{firstsecond=first->next;
		secondsecond=second->next;
		first->next=second;
		second->next=firstsecond;
		first=firstsecond;
		second=secondsecond;

	}
	*q=second;

}
struct node* finalMaxSumList(struct node*a,struct node* b)
{if(a==NULL)
	return b;
	if(b==NULL)
		return a;
	int sum1=0;int sum2=0;struct node* head=NULL;struct node* res=head;
	struct node* first=a;struct node* second=b;struct node* prevfirst=a;struct node*prevsecond=b;
	while(first&&second)
	{if(first->data<second->data)
		{sum1=sum1+first->data;
			first=first->next;

		}
	else if(second->data<first->data)
	{sum2=sum2+second->data;
		second=second->next;

	}
	else{
		if(sum1>=sum2)
		{if(head==NULL)
			{head=a;
				res=first;
				sum1=0;
				sum2=0;
				prevfirst=first;
				prevsecond=second;
				first=first->next;
				second=second->next;

			}
			else{
				if(res==prevsecond)
				res->next=prevfirst->next;
					res=first;
					prevfirst=first;
					prevsecond=second;
					first=first->next;
					second=second->next;
					sum1=0;sum2=0;


				


			}

		}
		else if(sum2>sum1)
		{if(head==NULL)
			{head=b;
				res=second;
				sum1=0;
				sum2=0;
				prevfirst=first;
				prevsecond=second;
				first=first->next;
				second=second->next;

			}
			else{
				if(res==prevfirst)
				res->next=prevsecond->next;
					res=second;
					prevfirst=first;
					prevsecond=second;
					first=first->next;
					second=second->next;sum1=0;sum2=0;


				


			}

		}


	}

	}
while(first)
{sum1+=first->data;
	first=first->next;

}
while(second)
{sum2+=second->data;
	second=second->next;

}
if(sum1>=sum2)
{if(head==NULL)
	head=prevfirst;
	else{if(res==prevsecond)
				res->next=prevfirst->next;


	}

}
else if(sum2>sum1)
{if(head==NULL)
	head=prevsecond;
	else{if(res==prevfirst)
				res->next=prevsecond->next;


	}

}


return head;
}
bool isleaf(struct node* root)
{if(root==NULL)
	return false;
	if(root->left==NULL&&root->right==NULL)
		return true;
	return false;

}
struct node* extractleaves(struct node* root,struct node** head,struct node**res)
{if(root==NULL)
	return NULL;
	
	root->left=extractleaves(root->left,head,res);
	if(!isleeaf(root))
		return root;
	if((*head)==NULL)
	{*head=root;*res=*head;
		return NULL;

	}
	else{(*res)->right=root;
		root->left=*res;
		*res=root;
		return NULL;

	}
	root->right=extractleaves(root->right,head,res);

	

}
void serializeutil(struct node* root,int *a,int *len)
{if(root==NULL)
	{a[(*len)++]=-1;
		return;


	}
	a[(*len)++]=root->data;
	serializeutil(root->left,a,len);
	serializeutil(root->right,a,len);

}
struct node* deserializeutil(int *a,int &count,int len)
{if(count>=len)
	return NULL;
	if(a[count]=-1)
	{count++;
		return NULL;

	}
	struct node* root=newNode(a[count]);
	count++;
	root->left=deserializeutil(a,count,len);
	root->right=deserializeutil(a,count,len);
	return root;

}
void inorder(struct node* root )
{if(root==NULL)
	return ;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);

}
void serializedeserialize(struct node* root)
{int a[100];
	int len=0;
	serializeutil(root,a,&len);
	int count=0;
	struct node* temp=deserializeutil(a,count,len);
inorder(temp);
}
int main()
{     //Linked List 1 : 1->3->30->90->110->120->NULL
    //Linked List 2 : 0->3->12->32->90->100->120->130->NULL
    struct node *head1 = NULL, struct node*head2 = NULL;
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
 printList(head1);
 //   finalMaxSumList(head1, head2);
    return 0;
}


