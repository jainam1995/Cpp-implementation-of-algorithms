#include <bits/stdc++.h>
using namespace std;
struct node{
int data;
struct node* left;struct node* right;
int count;int rank;
};
struct node* newnode(int data)
{struct node* temp=(struct node*)malloc(sizeof(struct node));
temp->data=data;
temp->left=NULL;temp->right=NULL;
temp->count=1;
temp->rank=1;
return temp;
}
struct node* insert(struct node* root,int data)
{if(root==NULL)
	return newnode(data);
	if(data==root->data)
		root->count++;
		else if(data<root->data)
	root->left=insert(root->left,data);
	else{
		root->right=insert(root->right,data);
	}
	return root;

}
struct node* insertiter(struct node* root,int data)
{if(root==NULL)
	return newnode(data);
	struct node*temp=root;
	int count=0;
	while(true)
	{if(temp->data==data)
		{temp->count++;
			temp->rank++;
			break;}
			else if(data<temp->data)
			{temp->rank++;
				if(temp->left==NULL)
				{temp->left=newnode(data);
					temp->left->rank+=count;
					break;}
				temp=temp->left;

			}
			else if(data>temp->data)
			{count=temp->rank;
				if(temp->right==NULL)
				{temp->right=newnode(data);
					temp->right->rank+=count;
					break;}
				temp=temp->right;
			}


	}

return root;

}
void inorder(struct node* root)
{if(root==NULL)
	return;
	inorder(root->left);
	cout<<root->data<<" "<<root->rank<<"\n";
	inorder(root->right);

}
bool search(struct node* root,int data)
{if(root==NULL)
return false;
if(root->data==data)
return true;
if(data<root->data)
return search(root->left,data);
else return search(root->right,data);


}
int findmin(struct node* root)
{while(root->left!=NULL)
	root=root->left;
	return root->data;

}
struct node* deletes(struct node* root,int data)
{if(root==NULL)
	return NULL;
	if(data<root->data)
	root->left=deletes(root->left,data);
	else if(data>root->data)
	root->right=deletes(root->right,data);
	else{
		if(root->left==NULL)
		return root->right;
		else if(root->right==NULL)
		return root->left;
		int value=findmin(root->right);
		root->data=value;
		root->right=deletes(root->right,value);
	}



return root;

}
struct node* findmaxnode(struct node* root)
{while(root->right!=NULL)
	root=root->right;
	return root;

}
struct node* findminnode(struct node* root)
{while(root->left!=NULL)
	root=root->left;
	return root;

}
void findPreSuc(struct node* root,struct node*&pre,struct node*&succ,int data)
{if(root==NULL)
	return;
	if(root->data==data)
	{if(root->left)
		pre=findmaxnode(root->left);
		if(root->right)
		succ=findminnode(root->right);
		

	}
	if(root->data<data)
	{pre=root;
		findPreSuc(root->right,pre,succ,data);


	}
	if(root->data>data)
	{succ=root;
		findPreSuc(root->left,pre,succ,data);

	}




}
bool isbst(struct node* root,int min,int max)
{if(root==NULL)
	return true;
	if(root->data>max||root->data<min)
	return false;
	return isbst(root->left,min,root->data)&&isbst(root->right,root->data,max);

}
struct node* lca(struct node* root,int a,int b)
{if(root==NULL)
	return NULL;
	if(root->data==a||root->data==b)
	return root;
	if(root->data>a&&root->data<b)
	return root;
	if(b<root->data)
	return lca(root->left,a,b);
	 lca(root->right,a,b);
}
void  kthsmallest(struct node* root,int k,int *count,struct node**ref)
{if(root==NULL)
	return ;
	kthsmallest(root->left,k,count,ref);
	if(*count==k)
	{*ref=root;
	}
	(*count)+=1;
	kthsmallest(root->right,k,count,ref	);

}
void printinrange(struct node* root,int a,int b)
{if(root==NULL)
	return;
	if(root->data>=a&&root->data<=b)
	cout<<root->data<<" ";
	if(root->data>=a)
	printinrange(root->left,a,b);
	if(root->data<=b)printinrange(root->right,a,b);

}
struct node* arraytobt(int *a,int l,int r)
{if(l>r)
	return NULL;
	if(l==r)
	return newnode(a[l]);
	int mid=l+(r-l)/2;
	struct node* root=newnode(a[mid]);
	root->left=arraytobt(a,l,mid-1);
	root->right=arraytobt(a,mid+1,r);
	return root;

}
void addgreater(struct node* root,int *sum)
{if(root==NULL)
	return;
	addgreater(root->right,sum);
	root->data=root->data+*sum;
	*sum=root->data;
	addgreater(root->left,sum);

}
struct node* removerange(struct node* root,int a,int b)
{if(root==NULL)
	return NULL;
	root->left=removerange(root->left,a,b);
	root->right=removerange(root->right,a,b);
	if(root->data<a)
	{struct node* t=root->right;
		
	return t;
}
	else if(root->data>b)
	{struct node* t=root->left;
		

	
	return t;}

	return root;

}
bool isleaf(struct node* root)
{if(root==NULL)
	return false;
	if(root->left==NULL&&root->right==NULL)
	return true;
	return false;

}
bool internalsingle(struct node* root)
{
if(root==NULL)

return true;
if(isleaf(root))
return true;
if(root->left&&root->right)
return false;
return internalsingle(root->left)&&internalsingle(root->right);

}
void bttodllutil(struct node** head,struct node* root,struct node** prev)
{if(root==NULL)
	return ;
	bttodllutil(head,root->left,prev);
	if(*prev==NULL)
	{*head=root;
		root->left=*prev;
		*prev=root;


	}
	else{
		(*prev)->right=root;
		root->left=*prev;
		*prev=root;
	}
bttodllutil(head,root->right,prev);

}
struct node* bttodll(struct node* root)
{struct node* head=NULL;
	struct node* prev=NULL;
	bttodllutil(&head,root,&prev);
	return head;


}
bool istriplet(struct node* head,int k)
{struct node*temp=head;
	while(head->right!=NULL)
	head=head->right;
	struct node* end=head;struct node* next=NULL;struct node* back=end;
	while(temp)
	{
		if(temp->right==NULL||temp->right->right==NULL)
		break;
		next=temp->right;back=end;
		cout<<next->data<<" "<<end->data<<"\n";
		while(back!=next&&back->right!=next)
		{cout<<temp->data+next->data+back->data<<" ";
			if(temp->data+next->data+back->data==k)
			return true;
			else if(temp->data+next->data+back->data<k)
			next=next->right;
			else back=back->left;

		}
		temp=temp->right;

	}return false;

}
int morris(struct node*& root)
{int ans=0;
	while(root!=NULL)
	{if(root->left==NULL)
		{ans=root->data;
			root=root->right;
			break;

		}
		else{
			struct node* left=root->left;
			while(left->right!=NULL&&left->right!=root)
				left=left->right;


				if(left->right==NULL)
				{left->right=root;
					root=root->left;
				}
				else{
					left->right=NULL;
					ans=root->data;
					root=root->right;
					break;
				}
		}

	}
	return ans;


}
void correctbstutil(struct node* root,struct node**prev,struct node**first,struct node**firstprev,struct node** second,struct node** secondprev)
{if(root==NULL)
	return;
	correctbstutil(root->left,prev,first,firstprev,second,secondprev);
	if(*prev==NULL)
	{*prev=root;

	}
	else if((*prev)->data>root->data)
		{if((*firstprev)==NULL)
			{(*firstprev)=*prev;
				(*first)=root;
			}
			else{
				(*secondprev)=*prev;
				(*second)=root;
			}
			*prev=root;

		}
		else *prev=root;
	
correctbstutil(root->right,prev,first,firstprev,second,secondprev);

}
void correctBST(struct node* root)
{struct node* prev=NULL;struct node* first=NULL;struct node*firstprev=NULL;struct node*second=NULL;struct node* secondprev=NULL;
correctbstutil(root,&prev,&first,&firstprev,&second,&secondprev);
if(second==NULL)
{int  temp=first->data;
	first->data=firstprev->data;
	firstprev->data=temp;


}
else{
int temp=second->data;
second->data=firstprev->data;
firstprev->data=temp;

}
}
int main()
{

  /*     6
        /  \
       2    10
      / \   / \
     1   3 7  12
     10 and 2 are swapped
    */
 
    struct node *root = newnode(6);
    root->left        = newnode(2);
    root->right       = newnode(12);
    root->left->left  = newnode(1);
    root->left->right = newnode(3);
    root->right->right = newnode(10);
    root->right->left = newnode(7);
 
    printf("Inorder Traversal of the original tree \n");
    inorder(root);
 
    correctBST(root);
 
    printf("\nInorder Traversal of the fixed tree \n");
    inorder(root);
	return 0;
}