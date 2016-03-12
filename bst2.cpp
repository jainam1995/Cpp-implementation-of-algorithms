#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node* left;
	struct node* right;
};
struct node* newNode(int data)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;temp->right=NULL;
	return temp;
}
struct node* insert(struct node*root,int data)
{if(root==NULL)
	return newNode(data);
	if(root->data<=data)
	{root->left=insert(root->left,data);


	}
	else root->right=insert(root->right,data);

}
bool isleaf(struct node* root)
{if(root==NULL)
	return false;
	if(root->left==NULL&&root->right==NULL)
		return true;
	return false;

}
bool isbst(struct node* root,int min,int max,struct node** ref)
{if(root==NULL)
	return true;
	if(root->data<min||root->data>max)
	{*ref=root;
		return false;
	}
	if(isbst(root->left,min,root->data,ref)==false||isbst(root->right,root->data,max,ref)==false)
		return false;
	return true;

}
struct node* minnode(struct node* root)
{if(root==NULL)
	return NULL;
	while(root->left)
	{root=root->left;

	}
	return root;

}
struct node* deletes(struct node* root,int data)
{if(root==NULL)
	return NULL;
	if(data<root->data)
		root->left=deletes(root->left,data);
	else if(data>root->data)
		root->right=deletes(root->right,data);
	else {

		if(isleaf(root))
		{free(root);
			root=NULL;
			return NULL;

		}
		struct node* temp;
		if(root->left==NULL)
		{temp=root->right;
			free(root);
			root==NULL;
			return temp;

		}
		else if(root->right=NULL)
		{temp=root->left;
			free(root);
			root=NULL;
			return temp;

		}
		else{
			struct node* min=minnode(root->right);
			root->data=min->data;
			root->right=deletes(root->right,min->data);



		}

	}

}
struct node* lca(struct node* root,int a,int b)
{if(root==NULL)
	return NULL;
	if(root->data==a||root->data==b||(root->data>a&&root->data<b))
		return root;
	if(root->data<a)
	return lca(root->right,a,b);
else return lca(root->left,a,b);

}
struct node* maxnode(struct node* root)
{if(root==NULL)
	return NULL;
	while(root->right)
		root=root->right;
	return root;

}
void presucc(struct node* root,int data,struct node** pre,struct node** succ)
{if(root==NULL)
	return ;
	if(root->data==data)
	{*pre=maxnode(root->left);
		*succ=minnode(root->right);
		return;

	}
	else if(root->data<data)
	{*pre=root;
		presucc(root->right,data,pre,succ);

	}
	else if(root->data>data)
	{*succ=root;
		presucc(root->left,data,pre,succ);

	}

}
void bstnodesinrange(struct node* root,int a,int b)
{if(root==NULL)
	return;
	if(root->data>=a)
		bstnodesinrange(root->left,a,b);
	if(root->data<=b)
		bstnodesinrange(root->right,a,b);
	if(root->data>=a&&root->data<=b)
		cout<<root->data<<" ";

}
struct node* arraytobst(int *a,int l,int r)
{if(l>r)
	return NULL;
	int mid=l+(r-l)/2;
	struct node* root=newNode(a[mid]);
	root->left=arraytobst(a,l,mid-1);
	root->right=arraytobst(a,mid+1,r);
	return root;

}
void  kthsmallestutil(struct node* root,int *count,int k,struct node**ref)
{if(root==NULL)
	return NULL;
	kthsmallestutil(root->left,count,k);
	if(*count==k)
	{*ref=root;
		return;

	}
	(*count)++;
	kthsmallest(root->right,count,k,ref);

}
struct node* kthsmallest(struct node*root,int k)
{int count=1;struct node* ref=NULL
	 kthsmallestutil(root,&count,k,&ref);
	 if(ref!=NULL)
	 	return ;


}
void addgretervalues(struct node* root,int *sum)
{if(root==NULL)
	return;
	addgretervalues(root->right,sum);
	root->data=root->data+*sum;
	*sum=root->data;
	addgretervalues(root->left,*sum);

}
struct node* removeoutsiderange(struct node* root,int a,int b)
{if(root==NULL)
	return NULL;
	root->left=removeoutsiderange(root->left,a,b);
	root->right=removeoutsiderange(root->right,a,b);
	if(root->data<a)
	{struct node* temp=root->right;
		free(root);
		root=NULL;
		return temp;

	}
	else if(root->data>b)
	{struct node* temp=root->left;
		free(root);
		root=NULL;
		return temp;

	}
return root;
}
bool eachonechild(struct node* root)
{if(root==NULL||isleaf(root))
	return true;
	if(root->left&&root->right)
		return false;
	return eachonechild(root->left)&&eachonechild(root->right);

}
int  morrismerge(struct node*& root)
{if(root==NULL)
	return -1;
	int temp;
	while(root!=NULL)
	{if(root->left==NULL)
		{temp=root->data;
			root=root->right;
			return temp;

		}
		else{
			struct node* left=root->left;
			while(left->right!=NULL&&left->right!=root)
				left=left->right
			if(left->right==NULL)
			{left->right=root;
				root=root->left;

			}
			else{
				left->right=NULL;
				temp=root->data;
				root=root->right;
				return temp;
			}


		}

	}

}
void mergeconstantspace(struct node* first,struct node*second)
{int a=morrismerge(first);
	int b=morrismerge(second);
	while(first!=NULL||second!=NULL)
	{if(a<b)
		{cout<<a<<" ";
		if(first==NULL)
			a=INT_MAX;
		else
		a=morrismerge(first);}
		else if(b<a)
		{cout<<b<<" ";
	if(second==NULL)
		b=INT_MAX;
			else
			b=morrismerge(second)

		}
		else {cout<<a<<" ";
		if(first==NULL)
			a=INT_MAX;
		else
		a=morrismerge(first);
		if(second==NULL)
			b=INT_MAX;
		else
		b=morrismerge(second);}

	}
if(a!=INT_MAX)
	cout<<a;
else if(b==INT_MAX)
	cout<<b;
}
int getcount(struct node* head)
{int count=1;
	while(head!=NULL)
	{count++;
		head=head->next;

	}
	return count;

}
struct node* dlltobst(struct node**head,int count)
{if(count==0)
	return NULL;
	struct node* left=dlltobst(head,n/2);
	struct node* root=newNode(head->data);
	*head=(*head)->right;
	root->left=left;
	root->right=dlltobst(head,count-count/2-1);
	return root;

}
struct nodes{
	int data;
	struct nodes* left;
	struct nodes* right;
	int rank;
};
struct nodes* newnode(int data)
{struct nodes* temp=(struct nodes*)mallloc(sizeof(struct nodes));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	temp->rank=1;

}
struct nodes* inserts(struct node* root,int data)
{if(root==NULL)
	return newnode(data);
	struct node*ans=root;
	while(true)
	{if(data<=root->data)
		{root->rank++;
			if(root->left=NULL)
			{root->left=newnode(data);
				break;

			}
			else root=root->left;

		}
		else if(data>root->data)
		{if(root->right==NULL)
			{root->right=newnode(data);
				break;

			}
			else root=root->right;

		}

	}
	return ans;

}
struct node* root(struct node* head)
{int count=getcount(head);
struct node* root=dlltobst(struct node**head,int count);
}

int main()
{

 





return 0;
}