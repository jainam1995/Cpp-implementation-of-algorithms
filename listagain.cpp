#include <bits/stdc++.h>
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
void printList(struct node* head)
{while(head!=NULL)
	{cout<<head->data<<" ";
	head=head->next;


	}
	cout<<endl;

}
void finalMaxSumList(struct node* head1,struct node* head2)
{struct node* a;struct node* b;struct node* preva;struct node* prevb;struct node* head=NULL;struct node* res;
int sum1=0;int sum2=0;a=head1;
b=head2;
preva=a;prevb=a;
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
		{if(head==NULL)
			{head=preva;
				res=head;
				preva=a;
				prevb=b;



			}
			else{
				if(res==preva)
				{res=a;

				}
				else{
					res->next=preva->next;
					res=a;
				}
				preva=a;
				prevb=b;


			}

		}
		else if(sum2>sum1)
		{if(head==NULL)
			{head=prevb;
				res=head;
				preva=a;
				prevb=b;



			}
			else{
				if(res==prevb)
				{res=b;

				}
				else{
					res->next=prevb->next;
					res=b;
				}
				preva=a;
				prevb=b;


			}




		}
		//cout<<" sum1 "<<sum1<<" sum2"<<sum2 <<" res->"<<res->data<<" ";
		sum1=0;sum2=0;
		a=a->next;b=b->next;
	}

}
while(a!=NULL)
{sum1=sum1+a->data;
	a=a->next;

}
while(b!=NULL)
{sum2=sum2+b->data;
	b=b->next;

}
if(sum1>=sum2)
{if(head==NULL)
	{head=preva;
		res=head;


	}
	else{if(res==prevb)
		{res->next=preva->next;

		}



	}

}
else if(sum2>sum1)
{if(head==NULL)
	{head=prevb;
		res=head;


	}
	else{if(res==preva)
		{res->next=prevb->next;

		}



	}

}

printList(head);
}
void push(struct node** head,int data)
{struct node* temp=newNode(data);
	temp->next=*head;
	*head=temp;

}
struct btree{
	int data;
	struct btree* left;
	struct btree* right;
};
struct btree* newnode(int data)
{struct btree* temp=(struct btree*)malloc(sizeof(struct btree));
	temp->data=data;
	temp->left=NULL;temp->right=NULL;
	return temp;

}
int count(struct node* head)
{int c=0;
	while(head!=NULL)
		{c++;head=head->next;}
return c;
}struct btree* lltobtreeutil(struct node** head,int n)
{if(n==0)
	return NULL;struct btree* left=NULL;
	left=lltobtreeutil(head,n/2);
	struct btree* temp=newnode((*head)->data);
	temp->left=left;
	
	*head=(*head)->next;
temp->right=lltobtreeutil(head,n-n/2-1);
return temp;

}
struct btree* lltobtree(struct node** head)
{int n=count(*head);
	return lltobtreeutil(head,n);

}
void inorder(struct btree* root)
{if(root==NULL)
	return ;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);

}
int main()
{//Linked List 1 : 1->3->30->90->110->120->NULL
    //Linked List 2 : 0->3->12->32->90->100->120->130->NULL
    struct node *head1 = NULL;struct node *head2 = NULL;
   struct btree* root=NULL;

    push(&head2, 130);
    push(&head2, 120);
    push(&head2, 100);
    push(&head2, 90);
    push(&head2, 32);
    push(&head2, 12);
    push(&head2, 3);
    push(&head2, 0);

   root=lltobtree(&head2);
   inorder(root);




return 0;
}