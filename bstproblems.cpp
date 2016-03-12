#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <queue>
#include <limits.h>
using namespace std;
struct node
{int data;
	struct node* left;
	struct node* right;
	int isleft;

};

struct node* newNode(int data)
{
struct node* temps=(struct node*)malloc(sizeof(struct node));
temps->data=data;
temps->left=NULL;
temps->right=NULL;
temps->isleft=0;
return temps;


}
struct node* insert(struct node* root,int data)
{if(root==NULL)
	{root=newNode(data);
	return root;
	}if(data<root->data)
		{root->isleft++;
			root->left=insert(root->left,data);

		}
	else root->right=insert(root->right,data);
return root;
}

void inorder(struct node* root)
{if(root==NULL)
	return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);

}
bool search(struct node* root,int data)
{if(root==NULL)
	return false;

	if(root->data==data)
		return true;
	if(data<root->data)
		return search(root->left,data);
		if(data>root->data)
			return search(root->right,data);


}
bool isleaf(struct node* root)
{if(root->left==NULL&&root->right==NULL)
	return true;
	else return false;

}
struct node* findmax(struct node* root)
{while(root->right!=NULL)
	root=root->right;
return root;


}
struct node* deleteNode(struct node* root,int data)
{
	if(root==NULL)
		return NULL;
	if(data<root->data)
		root->left=deleteNode(root->left,data);
	if(root->data<data)
		root->right=deleteNode(root->right,data);
	if(root->data==data)
		{if(isleaf(root))
		return NULL;
	if(root->left==NULL)
		return root->right;
	if(root->right==NULL)
		return root->left;
	struct node* temp=findmax(root->left);
	root->data=temp->data;
	root->left=deleteNode(root->left,temp->data);
}

	return root;
}
void findPreSuc(struct node* root,struct node* &pre,struct node* &succ,int data)
{if(root==NULL)
	return;
	if(root->data<data)
	{pre=root;
		findPreSuc(root->right,pre,succ,data);
	}
	else if(root->data>data)
	{succ=root;
		findPreSuc(root->left,pre,succ,data);

	}
	if(root->data==data)
	{findPreSuc(root->left,pre,succ,data);
		findPreSuc(root->right,pre,succ,data);
		
	}


}
bool isBST(struct node* root,int min,int max)
{if(root==NULL)
	return true;
	if(root->data<=max&& root->data>=min)
	{if(isBST(root->left,min,root->data)&&isBST(root->right,root->data,max))
		return true;

	}
	return false;

}
struct node* LCA(struct node* root,int data1,int data2)
{
	if(root==NULL)
		return NULL;
	if(root->data==data1 || root->data==data2)
		return root;
	if(data1<root->data&&data2>root->data)
		return root;
	if(data2<root->data)
		return LCA(root->left,data1,data2);
	else return LCA(root->right,data1,data2);
}
void kthsmallest(struct node* root,int& i,int k,struct node* &root2)
{if(root!=NULL)
	{
	kthsmallest(root->left,i,k,root2);
	i++;
	if(i==k)
		root2=root;
	//cout<<"asd"<<i<<" ";
	kthsmallest(root->right,i,k,root2);
}
}
int kthsmallest2(struct node* root,int k)
{if(root==NULL)
	return -1;
	if(k==root->isleft)
		return root->data;
	if(k<root->isleft)
		return kthsmallest2(root->left,k);
	else if(k>root->isleft)
		return kthsmallest2(root->right,k-root->isleft-1);


}
void Print(struct node* root,int k1,int k2)
{if(root==NULL)
	return;
	
	if(root->data>k1)
		Print(root->left,k1,k2);
	if(root->data<k2)
		Print(root->right,k1,k2);
if(root->data<=k2&&root->data>=k1)
		cout<<root->data<<" ";

}
void preorder(struct node* root){
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
struct node* sortedArrayToBST(int a[],int l,int r)
{if(l>r)
	return NULL;
int mid=l+(r-l)/2;
struct node* temp=newNode(a[mid]);
temp->left=sortedArrayToBST(a,l,mid-1);
temp->right=sortedArrayToBST(a,mid+1,r);

return temp;


}
void reverseinorder(struct node* root)
{if(root==NULL)
	return;
reverseinorder(root->right);
cout<<root->data<<" ";
reverseinorder(root->left);

}
void modifyBST(struct node* root,int *curr)
{if(root==NULL)
	return;
	modifyBST(root->right,curr);
	*curr=*curr+root->data;
	root->data=*curr;
	modifyBST(root->left,curr);


}
struct node* removeOutsideRange(struct node* root,int l,int r)
{
if(root==NULL)
	return NULL;
root->left=removeOutsideRange(root->left,l,r);
root->right=removeOutsideRange(root->right,l,r);
if(root->data<l)
	return root->right;
if(root->data>r)
	return root->left;
return root;


}
bool hasOnlyOneChild(int a[],int n)
{int max=a[n-1];int min=a[n-1];
	for(int i=n-2;i>=0;i--)
	{if(a[i]>max)
		max=a[i];
		else if(a[i]<min)
			min=a[i];
		else return false;



	}
	return true;

}
void correctBST(struct node* root,int a[],int& i)
{if(root==NULL)
	return;
	correctBST(root->left,a,i);
	a[i++]=root->data;
	correctBST(root->right,a,i);


}
struct node* constructTree(int start,int a[],int size,int l,int r)
{if(start>=size||l>r)
	return NULL;
	struct node* temp=newNode(a[start++]);
	if(l==r)
		return temp;
	int i;
	for(i=l;i<=r;i++)
		{if(a[i]>a[start])
			break;
}
temp->left=constructTree(start,a,size,start,i-1);
temp->right=constructTree(start,a,size,i,r);

return temp;
}
void Ceil(struct node* root,int data,int& ceil)
{
	if(root==NULL)
		return ;
	if(root->data==data)
		{ceil=data;

		}
	if(root->data<data)
		 Ceil(root->right,data,ceil);
	if(root->data>data)
	{ceil=root->data;
	Ceil(root->left,data,ceil);

	}
	
}
int printTour(int a[],int n)
{int start=0;int end=1;
	int curr=a[start];
	while(start!=end||curr<0)
	{

		while(start!=end&&curr<0)
		{curr=curr-a[start];
			start=(start+1)%n;
			if(start==0)
				return -1;


		}
		curr=curr+a[end];
		end=(end+1)%n;

	}

return start;
}
int main()
{ //struct petrolPump arr[] = {{6, 4}, {3, 6}, {7, 3}};
 int petrol[]={6,3,7};
 int distance[]={4,6,3};
 int n = sizeof(petrol)/sizeof(petrol[0]);
 int a[n];
 for(int i=0;i<n;i++)
 	a[i]=petrol[i]-distance[i];
    
    int start = printTour(a, n);
 
    (start == -1)? printf("No solution"): printf("Start = %d", start);
 
	return 0;
}