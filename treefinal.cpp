#include <bits/stdc++.h>
using namespace std;
struct node{
int data;
struct node* left;
struct node* right;


};
struct node* newNode(int data)
{struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;

}
struct node* bintree2listutil(struct node* root)
{
	if(root==NULL)
		return NULL;
	root->left=bintree2listutil(root->left);
	if(root->left)
	{struct node* left=root->left;
		while(left->right)
			left=left->right;
		left->right=root;
		root->left=left;



	}
	root->right=bintree2listutil(root->right);
	if(root->right)
	{struct node* right=root->right;
		while(right->left)
		right=right->left;
	right->left=root;
	root->right=right;

		

	}
	return root;
}
void printList(struct node* head)
{while(head)
	{cout<<head->data<<" ";
	head=head->right;

	}

}
struct node* bintree2list(struct node* root)
{struct node* temp=bintree2listutil(root);
	while(temp->left)
		temp=temp->left;
	return temp;

}
void inorder(struct node* root)
{
	if(root==NULL)
		return ;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}void push (struct node** head,int data)
{struct node* temp=newNode(data);
	temp->right=*head;
	*head=temp;


}
int count(struct node* head)
{int count=0;
	while(head)
	{count++;
		head=head->right;

	}

}
struct node* sortedListToBSTutil(struct node** head,int n)
{if(n<=0)
	return NULL;
	struct node* left=sortedListToBSTutil(head,n/2);
	struct node* root=*head;
	root->left=left;
	*head=(*head)->right;
	root->right=sortedListToBSTutil(head,n-n/2-1);
return root;
}
struct node* sortedListToBST(struct node* head)
{int n=count(head);
	return sortedListToBSTutil(  &head, n);

}
struct pairs{
	int s;int e;


};
int main()
{

 
 char s[]="jaianm   sf kh  kl     klklk";
 int n=strlen(s);
 stack<struct pairs >a;
struct pairs arr[strlen(s)];
for(int i=0;i<n;i++)
{

}



return true;	
}