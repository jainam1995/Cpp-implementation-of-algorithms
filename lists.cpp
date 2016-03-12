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
int count(struct node* head)
{int count=0;
	while(head)
	{count++;
		head=head->next;

	}
return count;
}
void push(struct node**head,int data)
{
struct node* temp=newNode(data);
temp->next=*head;
*head=temp;

}

void detectloop(struct node* root)
{struct node* ans=root;
	bool flag=false;
	struct node* slow=root;
	struct node* fast=root;
	while(fast->next!=NULL)
	{if(fast->next==NULL)
		break;
		fast=fast->next;
		if(fast->next==NULL)
			break;
		fast=fast->next;
		slow=slow->next;
		if(fast==slow)
		{flag=true;
			break;

		}



		

	}
	if(flag==false)
	 {cout<<"No\n";
		return;}

		int count=1;
		while(slow->next!=fast)
		{slow=slow->next;
			count++;

		}
		struct node* one=root;
		struct node* two=root;
		for(int i=0;i<count;i++)
		{two=two->next;

		}
		while(one !=two)
		{one=one->next;
			two=two->next;


		}
		while(one->next!=two)
		{one=one->next;

		}
		one->next=NULL;


		cout<<"Length of the Loop is "<<count<<endl;
		cout<<"The List is \n";
		while(root!=NULL)
		{cout<<root->data<<" ";
root=root->next;
		}
		cout<<endl;
}
void printList(struct node* root)
{while(root!=NULL)
	{cout<<root->data<<" ";
	root=root->next;

	}

}
struct node* reverse(struct node* head,int k)
{struct node* prev=NULL;int count=0;
	struct node* curr=head;
	if(curr==NULL)
		return prev;
	struct node* next=curr->next;
	while(curr!=NULL&&count<k)
	{next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
		count++;
	}
	count=1;
	head->next=curr;
	while(curr!=NULL&&count<k)
		{curr=curr->next;
			count++;}
			if(curr==NULL)
				return prev;
			curr->next=reverse(curr->next,k);

			return prev;
	

}
int getIntesectionNode(struct node* a,struct node* b)
{int l1=count(a);struct node* first;struct node* second;int diff;
int l2=count(b);
if(l1>=l2)
{first=a;second=b;diff=l1-l2;}
else if(l2>l1)
{first=b;
	second=a;
	diff=l2-l1;

}
for(int i=0;i<diff;i++)
{first=first->next;

}
while(first!=NULL&&first!=second)
{first=first->next;
	second=second->next;

}
if(first==NULL)
return -1;
else return first->data;

}
void removeDuplicates(struct node* head)
{int a[100]={0};struct node* del;
if(head==NULL)
return;
struct node* temp=head;
a[head->data]=1;
while(temp->next!=NULL)
{if(a[temp->next->data]==1)
	{del=temp->next;
		temp->next=temp->next->next;
		free(del);
		del=NULL;

	}
	else{
		a[temp->next->data]=1;
		temp=temp->next;
	}

}


}
struct node* addTwoLists(struct node* a,struct node* b)
{int carry=0;int sum;int ans;int first;int second;struct node* head=NULL;struct node* answer;
	while(a!=NULL||b!=NULL)
	{if(a==NULL)
		first=0;
		else first=a->data;
		if(b==NULL)
			second=0;
		else second=b->data;
		sum=first+second+carry;
		if(sum>=10)
			carry=1;
		else carry=0;
		sum=sum%10;
		if(head==NULL)
			{head=newNode(sum);
				answer=head;}
		else {head->next=newNode(sum);
		head=head->next;
	}
		if(a)
			a=a->next;
		if(b)
			b=b->next;


	}
	return answer;

}
struct node* middle(struct node* head)
{if(head==NULL)
	return NULL;
	struct node* slow=head;
	struct node* fast=head;
	while(fast->next!=NULL){
if(fast->next==NULL)
	return slow;
fast=fast->next;
if(fast->next==NULL)
return slow;
fast=fast->next;
slow=slow->next;

	}
	return slow;

}
struct node* reverse(struct node* head)
{struct node* prev=NULL;struct node*next;struct node* curr=head;
	
	while(curr!=NULL)
	{next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;

	}
	return prev;

}
bool ispalindrome(struct node* head)
{struct node* middles=middle(head);
	middles->next=reverse(middles->next);
	struct node* one=head;
	struct node* two=middles->next;
	while(two!=NULL)
	{if(one->data!=two->data)
		return false;
		one=one->next;
		two=two->next;

	}
	return true;


}
struct node* sortedinsert(struct node* head,int k)
{
	if(head==NULL)
		{head=newNode(k);
			return head;}
			if(k<=head->data)
			{struct node* temp=newNode(k);
				temp->next=head;
				head=temp;
				return head;

			}
			struct node* temp=head;
			while(temp->next!=NULL)
			{if(k>=temp->data&&k<=temp->next->data)
				{struct node* a=temp->next;
					temp->next=newNode(k);
					temp->next->next=a;
					return head;

				}
				temp=temp->next;

			}
			temp->next=newNode(k);
			return head;

}struct node* pairwiseswap(struct node* head)
{if(head==NULL||head->next==NULL)
	return head;
	struct node* prev;
	prev=head->next;
	struct node* next=prev->next;
	prev->next=head;
head->next=pairwiseswap(next);
return prev;


}
struct node* movelasttofirst(struct node* head)
{if(head==NULL||head->next==NULL)
	return head;
struct node* temp=head;
while(temp->next->next!=NULL)
temp=temp->next;
struct node* a=temp->next;
a->next=head;
head=a;
temp->next=NULL;
return head;


}
struct node* sortedIntersectiter(struct node*a,struct node* b)
{struct node* head=NULL;struct node* res=head;
	while(a!=NULL&&b!=NULL)
	{if(a->data<b->data)
		a=a->next;
		else if(b->data<a->data)
			b=b->next;
		else if(a->data==b->data)
		{if(head==NULL)
			{head=newNode(a->data);
				res=head;

			}
			else {
				res->next=newNode(a->data);
				res=res->next;
			}
			a=a->next;
			b=b->next;

		}

	}
return head;
}
struct node* sortedIntersect(struct node*a,struct node* b)
{struct node* res=NULL;
	if(a==NULL||b==NULL)
		return NULL;
	if(a->data<b->data)
	{res=sortedIntersect(a->next,b);

	}
	else if(a->data>b->data)
		res=sortedIntersect(a,b->next);
	else {
		res=newNode(a->data);
		res->next=sortedIntersect(a->next,b->next);


}

return res;


}
void delalternate(struct node* head)
{if(head==NULL||head->next==NULL)
	return ;
	while(head&&head->next)
	{struct node* root=head->next;
		head->next=head->next->next;
		free(root);
		root=NULL;
		head=head->next;
	}


}
struct node* splitalternate(struct node*a)
{struct node* head=NULL;struct node* res=head;
	if(a==NULL||a->next==NULL)
		return head;
	head=a->next;
	res=head;
	a->next=head->next;
	a=a->next;
	while(a&&res)
	{res->next=a->next;
		res=res->next;
		if(res==NULL)
			return head;
		a->next=res->next;
		a=a->next;

	}
return head;
}
struct node* merge(struct node* a,struct node* b)
{struct node* head=NULL;
if(a==NULL)
	return b;
if(b==NULL)
	return a;
if(a->data<b->data)
{head=newNode(a->data);
	head->next=merge(a->next,b);


}
else if(b->data<a->data)
{head=newNode(b->data);
	head->next=merge(a,b->next);

}
else {
	head=newNode(a->data);
	head->next=merge(a->next,b->next);
}

return head;
}
struct node* mergeiter(struct node*a,struct node* b)
{if(a==NULL)
	return b;
	else if(b==NULL)
		return a;
	struct node* head=NULL;struct node* res=head;
	while(a!=NULL&&b!=NULL)
	{if(a->data<b->data)
		{if(head==NULL)
			{head=newNode(a->data);
				res=head;
					
		}
		else{res->next=newNode(a->data);
			res=res->next;



			}
			a=a->next;
		}
		else if(b->data<a->data)
		{if(head==NULL)
			{head=newNode(b->data);
				res=head;

			}
			else{
				res->next=newNode(b->data);
				res=res->next;
			}
			b=b->next;
		}
		else{
			if(head==NULL)
			{head=newNode(a->data);
				res=head;

			}
			else{
				res->next=newNode(a->data);
				res=res->next;
			}
a=a->next;
b=b->next;
		}

	}
if(a==NULL)
{if(head==NULL)
	head=b;
	else {
		res->next=b;
	}

}
if(b==NULL)
{if(head==NULL)
	head=a;
	else {
		res->next=a;
	}

}

return head;
}
struct node* delgreatright(struct node* head)
{struct node* temp=reverse(head);struct node* root=temp;
	int max=temp->data;
	while(temp->next!=NULL)
	{if(temp->next->data>=max)
		{max=temp->next->data;
			temp=temp->next;

		}
		else{
			struct node* a=temp->next;
			temp->next=a->next;
			free(a);
			a=NULL;

		}
	}
root=reverse(root);
return root;
}void segregateEvenOdd(struct node** head)
{struct node* temp=*head;struct node* curr=*head;
	
	if((*head)->data%2!=0)
	{while(curr->next!=NULL&&curr->next->data&1)
		curr=curr->next;
		if(curr->next==NULL)
			return;

		struct node* temp=curr->next;
		curr->next=temp->next;
		temp->next=*head;
		*head=temp;

	}
	struct node*evenlast=*head;struct node* temp3;
	while(evenlast->next!=NULL&&evenlast->next->data%2==0)
		evenlast=evenlast->next;
	if(evenlast->next==NULL)
		return;
	struct node* temp2=evenlast->next;
	while(temp2->next!=NULL)
	{if(temp2->next->data%2==0)
		{ temp3=temp2->next;
			temp2->next=temp3->next;
			temp3->next=evenlast->next;
			evenlast->next=temp3;
			evenlast=temp3;

		}
		else 
		temp2=temp2->next;

	}


}
void isSumSorted(struct node*a,struct node* b,struct node*c,int k)
{int i;int j;struct node*p;struct node*q;
	//c=reverse(c);
	while(a!=NULL&&b!=NULL&&c!=NULL)
	{while(a!=NULL)
		{i=a->data;
			p=b;q=c;
			while(p!=NULL&&q!=NULL)
			{if(i+p->data+q->data==k)
				{cout<<i<<" "<<p->data<<" "<<q->data<<" "<<endl;
				p=p->next;
				q=q->next;}
				else if(i+p->data+q->data<k)
					p=p->next;
				else q=q->next;

			}
			a=a->next;
		}

	}

}
void merge (struct node* a,struct node** b)
{if(a==NULL||b==NULL)
	return;
	struct node*first=a;struct node*second=*b;
	struct node* firstsecond;struct node*secondsecond;
	while(first&&second)
	{firstsecond=first->next;secondsecond=second->next;
		first->next=second;
		second->next=firstsecond;
		first=firstsecond;
		second=secondsecond;


	}
	*b=secondsecond;
}
struct node* finalMaxSumList(struct node*a,struct node* b)
{int sum1=0;int sum2=0;struct node* head=NULL;struct node* res=head;
	struct node*first=a;struct node*aans=a;struct node* bans=b;struct node* temp;
	struct node* second=b;
	while(first!=NULL&&second!=NULL)
	{if(first->data<second->data)
		{sum1+=first->data;first=first->next;

		}
		else if(second->data<first->data)
		{sum2+=second->data;
			second=second->next;


		}
		else{
			if(sum1>=sum2)
			{if(head==NULL)
				{head=aans;
					res=head;
					aans=first;
					bans=second;
					first=first->next;
					second=second->next;}
					else{if(res==bans)
						{temp=second->next;
							second->next=first;

						}
						res=first;
						aans=first;
						bans=second;
						first=first->next;
					second=temp;
						

					}
					

			}
			else if(sum2>sum1)
			{if(head==NULL)
				{head=bans;
					res=head;
				aans=first;
					bans=second;
					first=first->next;
					second=second->next;}
					else{if(res==aans)
					{
						temp=first->next;
							first->next=second;
					}	
						res=second;
						aans=first;
						bans=second;
						first=temp;
						second=second->next;
						
					}

			}
			
			sum1=0;sum2=0;
		}

	}
	return head;
while(first!=NULL)
{sum1+=first->data;
	first=first->next;

}
while(second!=NULL)
{sum2+=second->data;
second=second->next;}
if(sum1>=sum2)
{if(head==NULL)
				{head=aans;
					res=head;
					aans=first;
					bans=second;
					}
					else{if(res==bans)
						{temp=second->next;
							second->next=first;

						}
						res=first;
						aans=first;
						bans=second;
						

					}

}
else if(sum2>sum1)
{if(head==NULL)
				{head=bans;
					res=head;
				aans=first;
					bans=second;
					}
					else{if(res==aans)
					{
						temp=first->next;
							first->next=second;
					}	
						res=second;
						aans=first;
						bans=second;
						
						
					}


}
return head;
}
int main()
{
  //Linked List 1 : 1->3->30->90->110->120->NULL
    //Linked List 2 : 0->3->12->32->90->100->120->130->NULL
    struct node *head1 = NULL;struct node*head2 = NULL;
    push(&head1, 120);
    push(&head1, 110);
    push(&head1, 90);
    push(&head1, 30);
    push(&head1, 3);
    push(&head1, 1);

   
    push(&head2, 32);
    push(&head2, 12);
    push(&head2, 3);
    push(&head2, 0);
head2->next->next->next->next=head1->next->next->next;
   map<struct node*,bool> hash;
   struct node* temp=head1;
   while(temp)
   {hash[temp]=true;
   	temp=temp->next;

   }
   struct node* temp2=head2;
   while(temp2)
   {if(hash.count(temp2))
   	{cout<<temp2->data;
   		break;

   	}
   	temp2=temp2->next;

   }
   cout<<endl;
   cout<<hash.size();
   cout<<endl;
   map<struct node*,bool>::iterator i;
   for(i=hash.begin();i!=hash.end();i++)
   {cout<<i->first->data<<" "<<i->second;
	cout<<endl;

   }
  cout<<hash.count(head2->next->next->next->next);
  cout<<endl;
   if(i->first)
   	cout<<i->first;
   else cout<<"No\n";

	return 0;
}