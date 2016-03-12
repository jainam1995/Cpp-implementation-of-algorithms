#include <bits/stdc++.h>
using namespace std;
struct node{
int data;int rank;
struct node* left;struct node* right;

};
struct node* newNode(int data)
{struct node*temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	temp->rank=1;
	return temp;
}
void inorder(struct node* root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
int searchmax(int *a,int l,int r)
{int max=a[l];
	int maxindex=l;
	for(int i=l+1;i<=r;i++)
	{if(a[i]>max)
		{max=a[i];
			maxindex=i;

		}

	}
return maxindex;

}
struct node* buildTree(int *a,int l,int r)
{if(l>r)
	return NULL;
	if(l==r)
		return newNode(a[l]);
	int i=searchmax(a,l,r);
	struct node* root=newNode(a[i]);
	root->left=buildTree(a,l,i-1);
	root->right=buildTree(a,i+1,r);
	return root;


}
struct node* constructTreeutil(int *pre,char* preln,int n,int* index)
{if(*index>=n)
	return NULL;
	struct node* root=newNode(pre[*index]);
	if(preln[(*index)++]=='N')
	{
		root->left=constructTreeutil(pre,preln,n,index);
		root->right=constructTreeutil(pre,preln,n,index);

	}
	return root;

}
struct node* constructTree(int *pre,char*preln,int n)
{int index=0;
	struct node* root=constructTreeutil(pre,preln,n,&index);
return root;
}
struct ListNode{
	int data;
	struct ListNode* next;
};
struct ListNode* newListNode(int data)
{struct ListNode* temp=(struct ListNode*)malloc(sizeof(struct ListNode));
	temp->data=data;
	temp->next=NULL;
	return temp;

}
void push(struct ListNode** temp,int data)
{struct ListNode* root=newListNode(data);
	root->next=*temp;
	*temp=root;


}
void convertList2Binary(struct ListNode* head,struct node* &root)
{
	queue<struct node*>q;
	root=newNode(head->data);
	head=head->next;
	q.push(root);
	while(!q.empty())
	{struct node*temp=q.front();q.pop();
		if(temp==NULL)
			continue;
		if(head==NULL){
			temp->left=NULL;
		}
		else {temp->left=newNode(head->data);
			head=head->next;

	}q.push(temp->left);
	if(head==NULL)
		temp->right=NULL;
	else{
		temp->right=newNode(head->data);
		head=head->next;
	}
	q.push(temp->right);

}

}bool isleaf(struct node* root)
{if(root==NULL)
	return false;
	if(root->left==NULL&&root->right==NULL)
		return true;
	return false;

}
struct node* prune(struct node* root,int k)
{if(root==NULL)
	return NULL;
	root->left=prune(root->left,k-root->data);
	root->right=prune(root->right,k-root->data);
	if(isleaf(root))
	{if(k-root->data>0)
		{free(root);
			root=NULL;
			return NULL;
		}

	}
	return root;

}
int search(int *a,int l,int r,int data)
{for(int i=l;i<=r;i++)
	{if(a[i]==data)
		return i;

	}

}
struct node* constructutil(int *pre,int *index,int n,int *post,int l,int h)
{if(l>h)
	return NULL;
	if((*index)>=n)
		return NULL;
	
	struct node* root=newNode(pre[*index]);
	(*index)++;
	if(l==h)
		return root;
	int i=search(post, l, h,pre[*index]);
	if(i<=h){
	root->left=constructutil(pre,index,n,post,l,i);
	root->right=constructutil(pre,index,n,post,i+1,h);
}
return root;

}
struct node* constructTree(int * pre,int *post,int n)
{int l=0;int h=n-1;int index=0;
	return constructutil(pre,&index,n,post,l,h);

}
int main()
{

 int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
    int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
    int size = sizeof( pre ) / sizeof( pre[0] );

    struct node *root = constructTree(pre, post, size);

    printf("Inorder traversal of the constructed tree: \n");
    inorder(root);

	return 0;
}