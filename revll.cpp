#include <bits/stdc++.h>
using namespace std;
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
void push(struct node** head,int data)
{struct node* temp=newNode(data);
	temp->next=*head;
	*head=temp;

}
struct node* SortedMerge(struct node* a,struct node* b)
{if(a==NULL)
	return b;
	if(b==NULL)
		return a;
	struct node* res=NULL;
	if(a->data<=b->data)
	{res=a;
		res->next=SortedMerge(a->next,b);

	}
	else if(b->data<a->data)
	{res=b;
		res->next=SortedMerge(a,b->next);

	}
	return res;


}
void printList(struct node* head)
{while(head)
	{cout<<head->data<<" ";
	head=head->next;

	}
	cout<<endl;

}
void printbnotina(struct node*a,struct node* b)
{struct node* first=a;
	struct node* second=b;
	while(first&&second)
	{if(first->data<second->data)
		{first=first->next;

		}
		else if(second->data<first->data)
		{cout<<second->data<<" ";
		second=second->next;

		}
		else {first=first->next;second=second->next;

		}

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
struct node* first=head;
struct node* second=head->next;
while(first&&second)
{first->next=second->next;
	first=first->next;
	if(first==NULL)
		break;
	second->next=first->next;
	second=second->next;

}
}
struct node* kAltReverse(struct node* head,int k)
{struct node* prev=NULL;
	struct node* curr=head;
	struct node* next;
	int count =0;
	while(curr&&count<k)
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
	while(curr&&count<k)
	{curr=curr->next;
		count++;

	}
	if(curr==NULL)
		return prev;
	curr->next=kAltReverse(curr->next,k);
	return prev;

}
struct node* revk(struct node* head,int k)
{struct node* prev=NULL;struct node* curr=head;
	struct node* next;
	int count=0;
	while(curr&&count<k)
	{next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
		count++;

	}
	if(curr==NULL)
		return prev;
	head->next=revk(curr,k);
	return prev;

}
void merge(struct node* p,struct node**q)
{if(p==NULL||*q==NULL)
	return ;
	struct node* firstnext;struct node*secondnext;
	struct node* first=p;struct node* second=*q;
	while(first&&second)
	{firstnext=first->next;
		secondnext=second->next;
		first->next=second;
		second->next=firstnext;
		first=firstnext;
		second=secondnext;

	}
	*q=second;

}
struct node* finalMaxSumList(struct node* a,struct node* b)
{struct node* head=NULL;struct node* sum1=0;struct node* sum2=0;struct node*first=a;
	struct node* second=b;struct node* prefirst=a;struct node* presecond=b;
	struct node*res;
	while(first&&second)
	{if(first->data<second->data)
		{sum1+=first->data;
			first=first->next;

		}
		else if(second->data<first->data)
		{sum2+=second->data;
			second=second->next;

		}	
		else{
			if(sum1>=sum2)
			{if(head==NULL)
				{head=prefirst;
					res=first;
					prefirst=first;
					presecond=second;
					sum1=0;
					sum2=0;
					first=first->next;second=second->next;
				}
				else{
					if(res==presecond)
					{res->next=prefirst->next;
						res=first;
						prefirst=first;
						presecond=second;
						sum1=0;sum2=0;
						first=first->next;second=second->next;

					}
				}

			}else if(sum2>sum1)
			{if(head==NULL)
				{head=presecond;
					res=second;
					prefirst=first;
					presecond=second;
					sum1=0;
					sum2=0;
					first=first->next;second=second->next;
				}
				else{
					if(res==prefirst)
					{res->next=presecond->next;
						res=second;
						prefirst=first;
						presecond=second;
						sum1=0;sum2=0;
						first=first->next;second=second->next;

					}
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
		head=prefirst;
else{
		if(res==presecond)
			res->next=prefirst->next;
	}

	}
	else if(sum2>sum1)
	{if(head==NULL)
		head=presecond;
else{
		if(res==prefirst)
			res->next=presecond->next;
	}

	}
return head;
}
int getMaxArea(int *a,int n)
{stack<int >s;
	int left[n];
	for(int i=0;i<n;i++)
	{while(!s.empty())
		{
			if(a[s.top()]>=a[i])
				s.pop();
			else break;
		}
		if(s.empty())
			left[i]=i;
		else left[i]=i-s.top()-1;
		s.push(i);

	}
	while(!s.empty())
	{s.pop();

	}
	int right[n];
	for(int i=n-1;i>=0;i--)
	{while(!s.empty())
		{if(a[s.top()]>=a[i])
			s.pop();
			else break;

		}//{6, 2, 5, 4, 5, 1, 6};
		if(s.empty())
			right[i]=n-i-1;
		else right[i]=s.top()-i-1;
		s.push(i);

	}
	int max=0;
	for(int i=0;i<n;i++)
	{if(a[i]*(left[i]+right[i]+1)>max)
		max=a[i]*(left[i]+right[i]+1);


	}
	//return max;
	for(int i=0;i<n;i++)
		cout<<left[i]<<" ";
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<right[i]<<" ";
	cout<<endl;
cout<<max;
}
void rearrange(int *a,int n)
{int i=0;int j=1;//i odd on even       j even on odd    
	while(i<n&&j<n)
	{while(i<n&&a[i]%2==0)
		i=i+2;
		if(i>n)
			break;
		while(j<n&&a[j]&1)
			j=j+2;
		if(j>n)
			break;
		int temp=a[i];
		a[i]=a[j];
		a[j]=temp;
		i=i+2;
		j=j+2;

	}

}
int main()
{   int hist[] = {6, 2, 5, 4, 5, 1, 6};
int n=sizeof(hist)/sizeof(hist[0]);
    rearrange(hist,n);
    for(int i=0;i<n;i++)
    	cout<<hist[i]<<" ";




return 0;	
}