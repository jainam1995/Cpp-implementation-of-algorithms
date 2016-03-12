#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node* left;
	struct node* right;
	int count;
	int less;
};
struct node* newnode(int data)
{struct node* temp=(struct node*)malloc(sizeof(struct node));
temp->data=data;
temp->left=NULL;temp->right=NULL;
temp->count=1;
temp->less=0;
return temp;
	
}
struct node* insert(struct node* root,int data)
{if(root==NULL)
	{root=newnode(data);
	return root;

}
struct node* temp=root;
int count=0;
while(true)
{if(data==temp->data)
	{temp->count++;
		return root;

	}
	else if(data<temp->data)
	{temp->less++;
		if(temp->left==NULL)
		{temp->left=newnode(data);
		return root;
		}
		else temp=temp->left;

	}
	else if(data>temp->data)
	{count=count+temp->less;
		if(temp->right==NULL)
		{temp->right=newnode(data);
			temp->right->less=count;
			return root;

		}
		else temp=temp->right;

	}

}
}
int search(struct node* root,int data)
{if(root==NULL)
	return -1;
	if(root->data==data)
	return root->less;
	if(data<root->data)
	return search(root->left,data);
	else return search(root->right,data);



}
void constructLowerArray(int *a,int* l,int n)
{struct node* root=NULL;
	for(int i=0;i<n;i++)
	root=insert(root,a[i]);
	
for(int i=0;i<n;i++)
{l[i]=search(root,a[i]);

}


}
void printArray(int *a,int n)
{for(int i=0;i<n;i++)
	cout<<a[i]<<" ";

}
int main()
{
int arr[] = {12, 10, 5, 4, 2, 20, 6, 1, 0, 2};
  int n = sizeof(arr)/sizeof(arr[0]);
  int *low = (int *)malloc(sizeof(int)*n);
  constructLowerArray(arr, low, n);
  printArray(low, n);
  }