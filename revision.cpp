#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <string.h>
#include <list>
#include <utility>
#include <algorithm>
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

struct node* insertbegin(struct node* head,int data)
{if(head==NULL)
	head=newNode(data);
else{
struct node* temp=newNode(data);
temp->next=head;
head=temp;

}
return head;
}

struct node* insertend(struct node* head,int data)
{if(head==NULL)
	head=newNode(data);
else{
struct node* temp=head;
while(temp->next!=NULL)
temp=temp->next;

struct node* last=newNode(data);
temp->next=last;


}

return head;
}
void printList(struct node* head)
{while(head!=NULL)
	{cout<<head->data<<" ";
	head=head->next;

	}
cout<<endl;
}
void AlternatingSplit(struct node* head,struct node* &a,struct node* &b)
{if(head==NULL)
	return;
	if(head->next==NULL)
	{a=head;
		b=NULL;


	}
	else{

a=head;
b=head->next;
struct node* atemp=a;
struct node* btemp=b;
while(atemp!=NULL&&btemp!=NULL)
{atemp->next=btemp->next;
	atemp=atemp->next;
if(atemp==NULL)
	return;

btemp->next=atemp->next;
btemp=btemp->next;
if(btemp==NULL)
	return;

}



	}


}
void push(struct node**head,int data)
{if(*head==NULL)
	{*head=newNode(data);
	return;}
	struct node* temp=newNode(data);
	temp->next=*head;
	*head=temp;

}
void reverse(struct node** head)
{struct node*temp=*head;
	struct node* prev=NULL;
	struct node* next;
	struct node* curr=temp;
	while(curr!=NULL)
	{next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;

	}
	*head=prev;


}
void detectloop(struct node* head)
{struct node* slow=head;
	struct node* fast=head;
if(head==NULL)
	{cout<<"no";
		return;

	}
while(fast!=NULL)
{slow=slow->next;
	fast=fast->next;
	if(fast==NULL)
	{	cout<<"no";
		return;
	}
	fast=fast->next;
	if(slow==fast)
		{cout<<"yes";
			return;
			}

}
if(fast==NULL)
	cout<<"no";

}
int length(struct node* head)
{int count=0;
	while(head!=NULL)
	{head=head->next;
		count++;

	}
	return count;

}
int  getIntesectionNode(struct node* head1,struct node* head2)
{int len1=length(head1);struct node*start1;struct node* start2;int c;
int len2=length(head2);
if(len1>len2)
{start1=head1;
	start2=head2;
c=len1-len2;
}
else{start1=head2;
	start2=head1;
c=len2-len1;


}
while(c--)
{start1=start1->next;

}
while(start1!=NULL&&start2!=NULL)
{if(start1==start2)
	return start1->data;
	start1=start1->next;
	start2=start2->next;

}
return -1;
}
struct node* intersect(struct node* a,struct node* b)
{struct node* result=NULL;
	if(a==NULL||b==NULL)
		return NULL;
	if(a->data==b->data)
	{	result=a;
	result->next=intersect(a->next,b->next);
	}
	if(a->data<b->data)
		result=intersect(a->next,b);
	else if(a->data>b->data)
		result=intersect(a,b->next);

	return result;
}
struct node* iterintersect(struct node* a,struct node* b)
{struct node* final;
	struct node* curr;
	while(a!=NULL&&b!=NULL&&a->data!=b->data)
	{if(a->data<b->data)
		a=a->next;
	if(b->data<a->data)
		b=b->next;

	}
	if(a==NULL||b==NULL)
		return NULL;
	else{
		final=a;
		curr=final;
		a=a->next;b=b->next;
	}
while(a!=NULL&&b!=NULL)
{if(a->data==b->data)
	{curr->next=a;
	curr=curr->next;
	a=a->next;
	b=b->next;
}
else if(a->data<b->data)
a=a->next;
else if(a->data>b->data)
b=b->next;



}
curr->next=NULL;
return final;

}
struct node* merge(struct node* a,struct node* b)
{if(a==NULL)
	return b;
if(b==NULL)
	return a;
struct node* result=NULL;
if(a->data<b->data)
{result=a;
	result->next=merge(a->next,b);


}
else if(a->data>b->data)
{result=b;
	result->next=merge(a,b->next);

}
else if(a->data==b->data)
{result=a;
	result->next=merge(a->next,b->next);


}
return result;
}
struct node* itermerge(struct node* a,struct node* b)
{struct node* final;
	struct node*curr;
	if(a==NULL)
		{final=b;
			return final;}
if(b==NULL)
{final=a;
	return final;

}
if(a->data<b->data)
{final=a;
	curr=final;
	a=a->next;

}
else if(a->data>b->data)
{final=b;
curr=final;
b=b->next;

}
else if(a->data==b->data)
{final=a;
	curr=final;
a=a->next;
b=b->next;


}
while(a!=NULL&&b!=NULL)
{if(a->data<b->data)
	{curr->next=a;
	curr=curr->next;
	a=a->next;

}
else if(b->data<a->data)
{curr->next=b;
	curr=curr->next;
	b=b->next;

}
else if(a->data==b->data)
{curr->next=a;
	curr=curr->next;
	a=a->next;
	b=b->next;

}
}
if(a==NULL)
curr->next=b;
else if(b==NULL)
curr->next=a;

return final;
}
struct node* reverses(struct node* head,int k)
{if(head==NULL)
	return NULL;
	struct node* prev=NULL;
	struct node* curr=head;
	struct node* next=NULL;
	int count=0;
	while(curr!=NULL&&count<k)
	{next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
count++;

	}int count2=0;
	
		head->next=curr;
	struct node* temp=curr;
	while(temp!=NULL&&count2<k-1)
	{temp=temp->next;
count2++;
	}
	if(temp!=NULL&&temp->next!=NULL)
		temp->next=reverses(temp->next,k);
	return prev;

}
struct node* getend(struct node* head)
{if(head==NULL)return NULL;
	while(head->next!=NULL)
		head=head->next;
	return head;

}
void delLesserNodes(struct node**head)
{if(*head==NULL)
	return ;
	if((*head)->next==NULL)
		return;
	struct node* temphead=*head;
	reverse(&temphead);
	int max=temphead->data;
	struct node*temp=temphead;
	while(temp!=NULL&&temp->next!=NULL)
	{if(temp->next->data<max)
		{struct node* del=temp->next;
			temp->next=temp->next->next;
			free(del);

		}
		else if(temp->next->data>max)
		{max=temp->next->data;
			temp=temp->next;

		}


	}
reverse(&temphead);
(*head)=temphead;

}
void segregateEvenOdd(struct node** head)
{struct node*temp=*head;struct node* head1;
	if(head==NULL)
		return;
	struct node* end=getend(temp);
	struct node* oldend=end;
	while(temp!=NULL&&((temp->data)&1)&&temp!=oldend)
	{head1=temp->next;
		end->next=temp;
		temp->next=NULL;
		temp=head1;
		end=end->next;
		//cout<<"Sdf";

	}
	//cout<<"hello";
*head=temp;
	if(temp==oldend)
return;
struct node*firsteven=temp;
while(firsteven!=NULL&&firsteven->next!=NULL&&firsteven->next!=oldend)
{if((firsteven->next->data)&1)
	{head1=firsteven->next;
		firsteven->next=firsteven->next->next;
		end->next=head1;
		head1->next=NULL;
		end=end->next;


	}
else firsteven=firsteven->next;

}
struct node* ends=getend(*head);
if(ends==NULL)
return;
struct node* reorder=*head;
while(reorder!=NULL&&reorder->next!=oldend)
reorder=reorder->next;
if(reorder==NULL)
	return;
if(reorder->next->data&1)
{ends->next=reorder->next;
	reorder->next=reorder->next->next;
	ends->next->next=NULL;
	ends=ends->next;

}
}

void rotate(struct node** head,int k)
{struct node* temp=*head;k--;
	struct node* end=getend(temp);
	while(k--)
	{temp=temp->next;

	}

end->next=*head;
*head=temp->next;
temp->next=NULL;
}
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																		
 struct node* addTwoLists(struct node* one,struct node* two)
 {struct node* res=NULL;struct node* temp;
 	int carry=0;
 	int ans;int first;int second;
 	while(one !=NULL||two!=NULL)
 	{if(one)
 		first=one->data;
 	else first=0;
 	if(two)
 		second=two->data;
 	else second=0;
 	ans=second+first+carry;
 	if(ans>=10)
 		carry=1;
 	else carry=0;
 	ans=ans%10;
 	if(res==NULL)
 		{res=newNode(ans);																																																																																																																								
 		temp=res;
}
else {
	temp->next=newNode(ans);
	temp=temp->next;
}
if(one)
	one=one->next;
if(two)
	two=two->next;

 	}
if(carry>0)
	{temp->next=newNode(carry);
		temp=temp->next;
	}
temp->next=NULL;

reverse(&res);
return res;
 }
 struct Node{
int data;
struct Node* next;
struct Node* down;

 };
 void sortList(struct node* head)
 {int one=0;struct node* temp=head;
 	int two=0;
 	int three=0;
 	while(head!=NULL)
 	{if(head->data==0)
 		one++;
 		else if(head->data==1)
 			two++;
 	else	if(head->data==2)
 			three++;
 		head=head->next;
 	}
 	while(temp!=NULL)
 	{while(one--)
 		{temp->data=0;
temp=temp->next;

 		}
 		while(two--)
 		{temp->data=1;
temp=temp->next;

 		}
 		while(three--)
 		{temp->data=2;
temp=temp->next;

 		}

 	}


 }
 //First Linked List:
//1 2 3
//Second Linked List:
//4 5 6 7 8
//Modified First Linked List:
//1 4 2 5 3 6
//Modified Second Linked List:
//7 8 
 void merge(struct node* first,struct node** second)
 {struct node* head2=*second;struct node* onenext;struct node* twonext;
 	struct node* one=first;
 	struct node* two=*second;
 	if(*second==NULL)
 		return;
 	onenext=one->next;
 	twonext=two->next;
while(two!=NULL)
{one->next=two;
	two->next=onenext;
	two=twonext;
	if(onenext==NULL)
		break;
	one=onenext;
twonext=two->next;
onenext=one->next;

}
if(onenext==NULL)
*second=two->next;
else *second=two;


 }
 struct node* revutil(struct node*one,struct node* two)
 {struct node* temp1;struct node* temp2;
 	if(one!=NULL&&two!=NULL)
 	{temp2=two;
 		temp1=two->next;
 		two->next=one;
 		if(temp1!=NULL)
 			one->next=revutil(temp1,temp1->next);
 		else 
 			one->next=NULL;

return temp2;
 	}


 }

 void pairWiseSwap(struct node** start)
 {struct node* temp=*start;struct node*end;struct node* newhead;
 	if(temp!=NULL&&temp->next!=NULL)
 	{newhead=temp->next;
 		end=temp->next->next;
 		temp->next->next=temp;
 		temp->next=end;
 		*start=newhead;


if(end!=NULL&&end->next!=NULL)

newhead->next->next=revutil(end,end->next);
 	}
 	

 }
 void finalMaxSumList(struct node* a,struct node* b)
 {struct node* result=NULL;
 	struct node* curr1=a;struct node* curr2=b;struct node* curr;
 	int sum1=0;int sum2=0;
 	while(a!=NULL&&b!=NULL)
 	{if(a->data<b->data)
 		{sum1=sum1+a->data;
 		a=a->next;

		}
		else if(b->data<a->data)
		{sum2=sum2+b->data;
			b=b->next;


		}
		else if(a->data==b->data)
		{if(sum1>=sum2)
			{if(result==NULL)
				{result=curr1;
					curr=a;
					curr1=a->next;
					curr2=b->next;
					a=a->next;b=b->next;
				

			}
			else{
				curr->next=curr1;
				curr=a;
				curr1=a->next;
				curr2=b->next;
				a=a->next;b=b->next;


			}

			}

				else if(sum2>sum1)
			{if(result==NULL)
				{result=curr2;
					curr=b;
					curr2=b->next;
									curr1=a->next;

					a=a->next;b=b->next;
				

			}
			else{
				curr->next=curr2;
				curr=b;
				curr2=b->next;
								curr1=a->next;

				a=a->next;b=b->next;


			}

			}

			sum1=0;sum2=0;
		}
 	}

 if(a==NULL)
 {while(b)
 	{sum2=sum2+b->data;
 		b=b->next;

 	}
 	if(sum1>=sum2)
 	{curr->next=curr1;

 	}
 	else curr->next=curr2;

 }	
 if(b==NULL)
 {while(a)
 	{sum1=sum1+a->data;
 		a=a->next;

 	}
 	if(sum1>=sum2)
 	{curr->next=curr1;

 	}
 	else curr->next=curr2;

 }	
while(result!=NULL)
 	{cout<<result->data<<" ";
result=result->next;}
 }
 
void printPairs(int a[],int n,int sum)
{sort(a,a+n);
	int l=0;
	int r=n-1;
while(l<r)
{if(a[l]+a[r]==sum)
	{cout<<a[l]<<" "<<a[r];
		return;}


	if(a[l]+a[r]<sum)
		l++;
	else if(a[l]+a[r]>sum)
	r--;
}


}
void printMajority(int* a,int n)
{int count=1;
	int ans=a[0];
	for(int i=1;i<n;i++)
	{if(a[i]==ans)
		count++;
		else count--;
		if(count==0)
		{ans=a[i];
			count=1;

		}

	}
	int check=0;
	for(int i=0;i<n;i++)
	{if(a[i]==ans)
		check++;

	}
	if(check>n/2)
		cout<<ans;
	else cout<<"-1";


}
int maxSubArraySum(int* a,int n)
{int ans=a[0];
	int max=ans;
	int starting=0;int ending=0;
for(int i=1;i<n;i++)
{if(ans<0)
	{ans=a[i];
		starting=i;
		}
		else ans=ans+a[i];
if(max<ans)
	{max=ans;
	ending=i;
}
}
cout<<starting<<" "<<ending<<" ";

return max;
}
int bsearchutil(int * a,int l,int r,int k)
{if(l<=r)
	{int mid=(l+r)/2;
		if(mid==l||mid==r)
			return -1;
		if(a[mid]<a[mid-1])
			return mid-1;
		if(a[mid]>a[mid+1])
			return mid;
		if(a[mid]>a[l])
			return bsearchutil(a,mid+1,r,k);
		else return bsearchutil(a,l,mid-1,k);





	}

}
int binarysearch(int * a,int l,int r,int k)
{if(l<=r)
	{int mid=(l+r)/2;
		if(a[mid]==k)
			return mid;
		else if(a[mid]<k)
			return binarysearch(a,mid+1,r,k);
		else return binarysearch(a,l,mid-1,k);

	}
return -1;
}
int pivotedBinarySearch(int* a,int size,int k)
{int pivot= bsearchutil(a,0,size-1,k);
	cout<<"pivot: "<<pivot;
int left=binarysearch(a,0,pivot,k);
if(left!=-1)
	return left;
return binarysearch(a,pivot+1,size-1,k);


}
void moveToEnd(int a[],int size,int n)
{int j=size-1;
	for(int i=size-1;i>=0;i--)
{if(a[i]!=-1)
	a[j--]=a[i];

}


}
void merge(int a[],int b[],int m,int n)
{int i=n;
	int j=0;int k=0;
while(i<m&&k<n)
{if(a[i]<b[k])
	a[j++]=a[i++];
else if(a[i]>b[k])
	a[j++]=b[k++];
else {a[j++]=b[k++];
		a[i++];}
}	
while(i<m)
a[j++]=a[i++];
while(k<n)
a[j++]=b[k++];


}
int median(int a[],int n)
{if(n&1)

	return a[n/2];
	else return (a[n/2-1]+a[n/2])/2;


}
int getMedian(int a[],int b[],int n)
{if(n==1)
	return(a[0]+b[0])/2;
if(n==2)
	return(max(a[0],a[1])+min(b[0],b[1]))/2;

int m1=median(a,n);
int m2=median(b,n);
if(m1==m2)
	return m1;
else if(m1>m2)
{if((!n&1))
	{
		return getMedian(b+n-n/2-1,a,n-n/2+1);

	}
	else return getMedian(b+n/2,a,n-n/2);

}
else if(m2>m1)
{
if((!n&1))
	{
		return getMedian(a+n-n/2-1,b,n-n/2+1);

	}
	else return getMedian(a+n/2,b,n-n/2);



}
}
void printArray(int a[],int size)
{for(int i=0;i<size;i++)
	cout<<a[i]<<" ";

}
int findNumberOfTriangles(int *a ,int n)
{int count=0;int i;
	for(i=0;i<n-2;i++)
	{int k=i+2;
		for(int j=i+1;j<n-1;j++)
		{while(a[i]+a[j]>a[k]&&k<n)
			k++;
			count=count+k-j-1;

		}



	}
	return count;
}
bool issafe(int x,int y)
{if(x>=0&&x<5&&y>=0&&y<5)
	return true;
	return false;

}
void countutil(int a[][5],bool visited[][5],int x,int y,int xrow[],int yrow[])
{visited[x][y]=true;
	for(int i=0;i<7;i++)
	{int xnew=x+xrow[i];
	int ynew=y+yrow[i];
	if(a[xnew][ynew]==1&&!visited[xnew][ynew]&&issafe(xnew,ynew))
		countutil(a,visited,xnew,ynew,xrow,yrow);

	}

}
int countIslands(int a[][5])
{bool visited[5][5];int count=0;
	for(int i=0;i<5;i++)
	{for(int j=0;j<5;j++)
		visited[i][j]=false;
	}
		int xrow[]={0,0,1,1,-1,-1,1,-1};
		int yrow[]={-1,1,1,-1,1,-1,0,0};
		for(int i=0;i<5;i++)
		{for(int j=0;j<5;j++)
			{if(a[i][j]==1&&!visited[i][j])
				{countutil(a,visited,i,j,xrow,yrow);
					count++;
					}

			}

		}
	

return count;
}
int FindMaxSum(int a[],int n)
{int sum;
int	inc=a[0];
int exc=0;
for(int i=1;i<n;i++)
{sum=max((a[i]+exc),inc);
int temp=inc;
	inc=a[i]+exc;
	exc=max(temp,exc);
	


}return sum;
}
void merge(int a[],int temp[],int l,int mid,int r,int * count)
{int size1=mid-l+1;
	int size2=r-mid;
	int i=l;
	int j=mid+1;
	int k=l;
	while(i<=mid&&j<=r)
	{if(a[i]<a[j])
		temp[k++]=a[i++];
	else if(a[j]<a[i])
	{*count=*count+mid-i+1;
		temp[k++]=a[j++];

	}	
	else{
		temp[k++]=a[i++];
		a[j++];
	}
	}
	while(i<=mid)
		temp[k++]=a[i++];
	while(j<=r)
		temp[k++]=a[j++];

	for(int i=l;i<=r;i++)
		{a[i]=temp[i];}



}
void countinversions(int a[],int temp[],int l,int r,int* count)
{if(l<r)
	{int mid=(l+r)/2;
		countinversions(a,temp,l,mid,count);
		countinversions(a,temp,mid+1,r,count);
		merge(a,temp,l,mid,r,count);

	}


}
int mergesort(int a[],int size)
{int temp[size];
	int count=0;
	 countinversions(a,temp,0,size-1,&count);
return count;

}
int abs(int a)
{if(a<0)
	return -1*a;
	else return a;

}
void minAbsSumPair(int *a ,int size)
{sort(a,a+size);int ansi;int ansj;
	int i=0;int j=size-1;
	int min=10000;
	while(i<j)
	{if(abs(a[i]+a[j])<min)
		{min=abs(a[i]+a[j]);
			ansi=i;ansj=j;}
	if(a[i]+a[j]>0)
		j--;
	else if(a[i]+a[j]<0)
		i++;

	}
cout<<ansi<<" "<<ansj;

}
void print2Smallest(int *a,int n)
{int smallest;int secondsmallest;
	if(a[0]<a[1])
	{smallest=a[0];
	 secondsmallest=a[1];
	}
	else{
		smallest=a[1];
		secondsmallest=a[0];
	}
	for(int i=1;i<n;i++)
	{
		if(a[i]<smallest)
			{secondsmallest=smallest;

		smallest=a[i];}
		else if(a[i]<secondsmallest)
			secondsmallest=a[i];
	}

cout<<smallest<<" "<<secondsmallest;
}
void segregate0and1(int *a,int n)
{int i=0;int j=n-1;
	while(i<n&&a[i]==0)
		i++;
	while(j>=0&&a[j]==1)
		j--;
	while(i<j)
	{if(a[i]==1&&a[j]==0&&i<j)
		{int temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}else {if(a[i]==0&&i<j)
		i++;
			if(a[j]==1&&i<j)
			j--;}

	}

}
int maxDiff(int * a,int n)
{int max=0;
	int min=a[0];
	for(int i=1;i<n;i++)
	{if(a[i]-min>max)
		max=a[i]-min;
		if(a[i]<min)
			min=a[i];


	}
	return max;

}
void printIntersection(int *a,int *b,int m,int n)
{
int i=0;int j=0;
while(i<m&&j<n)
{if(a[i]<b[j])
	i++;
	else if(b[j]<a[i])
		j++;
else{cout<<a[i]<<" ";i++;j++;}

}
}
void printunion(int *a,int *b,int m,int n)
{int i=0;int j=0;
	while(i<m&&j<n)
	{if(a[i]<b[j])
		{cout<<a[i]<<" ";
			i++;
		}
		else if(b[j]<a[i])
		{cout<<b[j]<<" ";
			j++;

		}
		else {
			cout<<a[i]<<" ";
			i++;j++;
		}
	}
while(i<m)
	cout<<a[i++]<<" ";
while(j<n)
	cout<<b[j++]<<" ";
}
struct pairs
{
int min;
int max;

};
struct pairs getMinMax(int *a,int size)
{struct pairs node;int i;
	if(size%2==0)
	{if(a[0]<a[1])
		{node.min=a[0];
			node.max=a[1];

		}
		else{
			node.min=a[1];
			node.max=a[0];

		}
i=2;
	}
	if(size&1)
{node.min=a[0];
	node.max=a[1];
i=1;
}
 
while(i<size-1)
{if(a[i]<a[i+1])
	{if(a[i]<node.min)
		node.min=a[i];
	if(a[i+1]>node.max)
		node.max=a[i+1];

	}
	else
	{if(a[i+1]<node.min)
		node.min=a[i+1];
	if(a[i]>node.max)
		node.max=a[i];

	}
i=i+2;
}

return node;
}
int bsearchceil(int *a ,int l,int r,int x)
{if(l<=r)
	{int mid=(l+r)/2;
		if((mid==l)&&a[mid]>=x)
			return l;
		if((mid==r)&&a[mid]>=x)
			return mid;
		if(a[mid]>=x&&a[mid-1]<x)
			return mid;
		if(a[mid]<x&&a[mid+1]>=x)
			return mid+1;
		if(a[mid]>x)
			return bsearchceil(a,l,mid-1,x);
		else return bsearchceil(a,mid+1,r,x);

	}

}
int ceilSearch(int *a,int l,int r,int x)
{if(x>a[r])
	return -1;
	if(x<=a[l])
		return 0;
	if(x==a[r])
		return r;
	return bsearchceil(a,l,r,x);

}
void productArray(int *a,int n)
{
int left[n];int right[n];
left[0]=1;
right[n-1]=1;
for(int i=1;i<n;i++)
left[i]=left[i-1]*a[i-1];
for(int i=n-2;i>=0;i--)
right[i]=right[i+1]*a[i+1];

for(int i=0;i<n;i++)
cout<<left[i]*right[i]<<" ";


}
void sort012(int *a,int n)
{int left=0;int right=n-1;int size;int middle=0;
	while(left<=right&a[left]==0)
		left++;
	while(left<=right&&a[right]==2)
		right--;
	middle=left;
	while(left<=middle&&middle<=right)
	{if(a[middle]==1)
		middle++;
		else if(a[middle]==0)
		{int temp=a[middle];
			a[middle]=a[left];
			a[left]=temp;
			left++;middle++;

		}
		else if(a[middle]==2)
		{int temp=a[middle];
			a[middle]=a[right];
			a[right]=temp;
			right--;


		}

	}

}
void printRepeating(int a[],int size)
{//cout<<a[1]<<"sdf";
	for(int i=1;i<size;i++)
	{
		a[abs(a[i])]=-1*a[abs(a[i])];


	}
	for(int i=1;i<size;i++)
		{if(a[abs(a[i])]>0)
			cout<<abs(a[i])<<" ";}

}
void printUnsorted(int *a,int size)
{int left;int right;int i;
	for( i=1;i<size;i++)
		{if(a[i]<a[i-1])
			{left=i-1;
			break;
		}

		}
		
		for(int i=size-2;i>=0;i--)
		{if(a[i]>a[i+1])
			{right=i+1;break;

			}
			}	

int min=a[left];int max=a[right];
for(int i=left;i<=right;i++ )
{if(a[i]>max)
	max=a[i];
	if(a[i]<min)
		min=a[i];

}
for(int i=0;i<left;i++)
{if(a[i]>min)
	{left=i;
		break;

	}
}
for(int i=size-1;i>right;i--)
{if(a[i]<max)
	{right=i;
		break;

	}

}
			
cout<<left<<" "<<right<<" ";
}
void printNGE(int *a ,int n)
{
stack<int >s;
s.push(a[0]);
for(int i=1;i<n;i++)
{while(!s.empty()&&(a[i]>s.top()))
	{
		cout<<s.top()<<"--"<<a[i]<<"\n";
		s.pop();

		

	}
	s.push(a[i]);


}
while(!s.empty())
{cout<<s.top()<<"-- "<<"-1"<<"\n";
s.pop();
}

}
int findFirstMissing(int *a,int l,int r)
{if(l<=r)
	{int mid=(l+r)/2;
		if(mid==l&&a[mid]!=mid)
		return l;
		//if(a[mid]==mid&&mid==l)
			//return -2;
		if(mid==r&&mid==a[mid])
			return -1;
		if(mid==r&&a[mid]!=mid)
			return mid;
		
		if(a[mid]==mid)
			return findFirstMissing(a,mid+1,r);
		if(a[mid]!=mid)
			return findFirstMissing(a,l,mid-1);
	}

//return -1;
}
int blowsearch(int *a,int l,int r,int k)
{if(l<=r)
	{int mid=(l+r)/2;
		if(mid==l&&a[mid]==k)
			return mid;
		if(a[mid]==k&&a[mid-1]!=k)
			return mid;
		if(a[mid]>=k)
			return blowsearch(a,l,mid-1,k);
		if(mid==r&&a[mid]!=k)
			return -1;
		if(a[mid]<k)
			return blowsearch(a,mid+1,r,k);

	}
return -1;
}
int bhighsearch(int *a,int l,int r,int k)
{if(l<=r)
	{int mid=(l+r)/2;
		if(mid==r&&a[mid]==k)
		return mid;
	if(mid==r&&a[mid]!=k)
		return -1;
	if(a[mid]==k&&a[mid+1]!=k)
		return mid;
	if(a[mid]<=k)return bhighsearch(a,mid+1,r,k);
		if(a[mid]>k)
			return bhighsearch(a,l,mid-1,k);

	}
return -1;
}
int count(int *a,int k,int size)
{if(k<a[0]||k>a[size-1])
	return 0;
int low=blowsearch(a,0,size-1,k);
if(low==-1)return 0;
int high=bhighsearch(a,0,size-1,k);
return high-low+1;	


}
int maxIndexDiff(int*a ,int n)
{int left[n];
	int min=a[0];
	for(int i=0;i<n;i++)
	{if(a[i]<min)
		min=a[i];
		left[i]=min;

	}
	int right[n];int max=a[n-1];
	for(int i=n-1;i>=0;i--)
	{if(a[i]>max)
		max=a[i];
		right[i]=max;

	}
	int ans=-1;
	int i=0;int j=0;
	while(i<n&&j<n)
	{if(right[i]>=left[j])
	{if((i-j)>ans)
		ans=i-j;
		i++;



	}	
	else j++;
	}
return ans;
}
int maximum(int a,int b)
{if(a>b)
	return a;
	else return b;

}
void printKMax(int *a,int n,int k)
{int left[n];int right[n];
	int min=a[0];
	left[0]=a[0];
	for(int i=1;i<n;i++)
	{if(i%k==0)
		{left[i]=a[i];
			

		}
		else 
		{
			left[i]=maximum(a[i],left[i-1]);

		}

	}int i;
	//int max=a[n-1];
	for( i=0;i+k-1<n;i=i+k)
	{right[i+k-1]=a[i+k-1];
	int j=i+k-2;
	while(j>=i)
	{right[j]=maximum(a[j],right[j+1]);
		j--;
	}
	


	}
	right[n-1]=a[n-1];
	int j=n-2;
	while(j>=i)
		{right[j]=maximum(a[j],right[j+1]);
			j--;}
	int ans[n-k+1];
	for(int i=0;i<n;i++)
		cout<<left[i]<<" ";
	cout<<"\n";
	for(int i=0;i<n;i++)
		cout<<right[i]<<" ";
	cout<<"\n";
for(int i=0;i<n-k+1;i++)
{ans[i]=maximum(right[i],left[i+k-1]);

}
for(int i=0;i<n-k+1;i++)
	cout<<ans[i]<<" ";
}
int minDist(int *a,int n,int x,int y)
{
	int i=0;
	while(i<n&&(a[i]!=x&&a[i]!=y))
		i++;
	if(i==n)
		return 0;
	cout<<i;
	int first=i;
	i++;int second;
	int max=n;
	while(i<n)
	{if(a[i]==a[first])
		first=i;
		else if((a[i]==x||a[i]==y)&&a[i]!=a[first])
		{if((i-first)<max)
			max=i-first;
			first=i;

		}
		i++;
	}
	return max;
}
int findMaximum(int *a,int l,int r)
{if(l<=r)
	{int mid=l+(r-l)/2;
		if((mid==r))
			return a[mid];
		if(a[mid]>a[mid-1]&&a[mid]>a[mid+1])
			return a[mid];
		if(a[mid]>a[mid-1])
			return findMaximum(a,mid+1,r);
		return findMaximum(a,l,mid-1);

	}

}
void printcombinationutil(int a[],int n,int ans[],int r,int i,int index)
{
	
	if(index==r)
	{for(int k=0;k<r;k++)
		cout<<ans[k];
		cout<<"\n";
	}
	if(index>=r)
		return;
	if(i>=n)
		return;
	ans[index]=a[i];
	printcombinationutil(a,n,ans,r,i+1,index+1);
printcombinationutil(a,n,ans,r,i+1,index);
}
void printCombination(int *a,int n,int r)
{
int ans[r];
printcombinationutil(a,n,ans,r,0,0);

}
void printPattern(char* s)
{


}
int maxOnesIndex(bool *a,int n)
{int previndex=-1;int prevprevindex=-1;int maxindex;int ans=0;int curr;
	for(int i=0;i<n;i++)
	{if(a[i]==0)
		{curr=i;
			if(curr-prevprevindex>ans)
			{maxindex=previndex;

				ans=curr-prevprevindex;
				prevprevindex=previndex;
				previndex=curr;

			}

		}



	}
if(n-prevprevindex>ans)
{maxindex=previndex;
	ans=n-prevprevindex;

}
return previndex;

}

bool findpartitionutil(int *a,int n,int sum)
{if(sum==0)
	return true;
if(n==0)
	return false;
if(a[n-1]>sum)
	return findpartitionutil(a,n-1,sum);
return findpartitionutil(a,n-1,sum)||findpartitionutil(a,n-1,sum-a[n-1]);

}
bool findPartiion(int *a,int n)
{int sum=0;
	for(int i=0;i<n;i++)
	{sum=sum+a[i];

	}
if(sum&1)
	return  false;
else return findpartitionutil(a,n,sum/2);
}
void printarrayr(int *a,int r)
{for(int i=0;i<r;i++)
	cout<<a[i]<<" ";
	cout<<endl;

}
void printcomb(int *a,int *ans,int i,int index,int n,int r)
{
	if(index==r)
	printarrayr(ans,r);
else{
	if(i>=n)
		return;
	if(index>r)
		return;
	ans[index]=a[i];
	printcomb(a,ans,i+1,index+1,n,r);
	while(i<n&&a[i]==a[i+1])
		i++;
	printcomb(a,ans,i+1,index,n,r);




}
}
void printCombinations(int *a,int n,int r)
{if(r==0)
	return;
	int ans[r];
	int i=0;
	int index=0;
	printcomb(a,ans,i,index,n,r);

}

void subArraySum(int *a,int n,int sum)
{int start=0;
	int currsum=a[0];int i;
	for( i=1;i<=n;i++)
	{while(currsum>sum&&start<i-1)
		{currsum-=a[start];
			start++;

		}
		if(currsum==sum)
		{	cout<<"found at "<<start<<" and "<<i-1;
			return;}
		
		if(i<n)
			currsum+=a[i];

	}
if(i==n+1)
	cout<<"not found";
}
bool isvalid(int *count,int k)
{int value=0;
	for(int i=0;i<26;i++)
	{if(count[i]>0)
		value++;

	}
	return (k>=value);

}
void kUniques(char a[],int k)
{int count[26]={0};

	int start=0;int maxstart=0;int end=0;int max=1;
	count[a[0]-'a']++;

	int i;
	for(i=1;i<strlen(a);i++)
	{count[a[i]-'a']++;
		end++;
		while(!isvalid(count,k))
		{count[a[start]-'a']--;
			start++;

		}
		if(end-start+1>max)
		{max=end-start+1;
			maxstart=start;

		}



	}
	//for(int j=0;j<26;j++)
		cout<<max<<" ";
		cout<<a[maxstart];

}
class Graph
{
public:
	Graph(int v)
	{vertices=v;
		adj=new list<int>[v];

	}
	void addEdge(int src,int dest)
	{adj[src].push_back(dest);

	}
	void printAllPathsutil(int x,int d,bool visited[],int path[],int len)
	{visited[x]=true;
		path[len++]=x;
		if(x==d)
		{for(int i=0;i<len;i++)
			cout<<path[i]<<" ";
			cout<<endl;
			visited[x]=false;
			return;
		}
		
		list<int>::iterator t;
		for(t=adj[x].begin();t!=adj[x].end();t++)
		{if(!visited[*t])
			{printAllPathsutil(*t,d,visited,path,len);

			}

		}
		visited[x]=false;


	}
	void printAllPaths(int s,int d)
	{bool visited[this->vertices];
		for(int i=0;i<this->vertices;i++)
			visited[i]=false;
	int path[this->vertices];int len=0;
	
	printAllPathsutil(s,d,visited,path,len);

	for(int i=0;i<vertices;i++)
		cout<<visited[i]<<" ";

	}
	
private:
	int vertices;
	list<int>* adj;
	
};
bool issafet(int x,int y,int r,int c,int * visited)
{if(x<r&&y<c&&(*((visited+x*c)+y)==false))
	return true;
	return false;

}
void printAllpossiblePathsutil(int *visited,int x,int y,int *mat,int  *xrow,int *yrow,int m,int n,int *path,int len)
{*((visited+x*(n+1))+y)=true;
	cout<<*((mat+x*(n+1))+y)<<" ";
	path[len++]=*((mat+x*(n+1))+y);
	if(x==m&&y==n)
	{for(int i=0;i<len;i++)
		cout<<path[i]<<" ";
		cout<<endl;
		*((visited+x*(n+1))+y)=false;
		return;

	}
	//cout<<"dg";
	for(int k=0;k<3;k++)
	{int nextx=x+xrow[k];
		int nexty=y+yrow[k];
		
		if(issafet(nextx,nexty,m+1,n+1,visited))
		{	//cout<<"sdf";
			printAllpossiblePathsutil(visited,nextx,nexty,mat,xrow,yrow,m,n,path,len);

		}
		//else 	cout<<"jainam";

	}
	*((visited+x*(n+1))+y)=false;

}
void printAllpossiblePaths(int *mat,int r,int c)
{int path[r+c];
	int len=0;
	int xrow[]={0,1,1};
	int yrow[]={1,0,1};
	int x=0;int y=0;
	bool visited[r][c];
	for(int i=0;i<r;i++)
	{for(int j=0;j<c;j++)
		visited[i][j]=false;
	}
		
	printAllpossiblePathsutil((int *)visited,x,y,mat,xrow,yrow,r-1,c-1,path,len);
	

}
bool issafes(int x,int y,bool visited[][4])
{if(x<4&&x>=0&&y<4&&y>=0&&visited[x][y]==false)
	return true;
else return false;

}
bool findutil(char* s,int x,int y,char mat[][4],bool visited[][4],int level,int levelfinal,int *xrow,int *yrow)
{visited[x][y]=true;
	if(level==levelfinal)
		return true;
	for(int k=0;k<8;k++)
	{int nextx=x+xrow[k];
		int nexty=y+yrow[k];
		if(issafes(nextx,nexty,visited)&&mat[nextx][nexty]==s[level+1])
		{if(findutil(s,nextx,nexty,mat,visited,level+1,levelfinal,xrow,yrow)==true)
			return true;
		}

	}
visited[x][y]=false;
return false;

}
bool issafed(int i,int j,bool visited[][2])
{if(visited[i][j]==false)
	return true;
	else return false;

}
void printall(char mat[][2],int k,int level,bool visited[][2],char path[],int x,int y)
{visited[x][y]=true;
	path[level]=mat[x][y];
	if(level==k)
	{for(int p=0;p<=level;p++)
		cout<<path[p]<<" ";
		cout<<endl;
		visited[x][y]=false;
		return;
	}
	for(int i=0;i<2;i++)
	{for(int j=0;j<2;j++)
		{if(issafed(i,j,visited))
			{printall(mat,k,level+1,visited,path,i,j);

			}

		}

	}
visited[x][y]=false;
}
int main(void)
{ char mat[2][2]{{'c','a'},{'e','n'}};
bool visited[2][2];
for(int i=0;i<2;i++)
{for(int j=0;j<2;j++)
	visited[i][j]=false;

}
int level=0;
int k=2;
char path[k];

for(int i=0;i<2;i++)
{for(int j=0;j<2;j++)
	{printall(mat,k-1,level,visited,path,i,j);


	}


}


	return 0;
}