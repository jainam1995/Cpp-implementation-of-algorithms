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
struct node* insert(struct node* root,int data)
{if(root==NULL)
	{root=newNode(data);
		//return root;

	}
	else if(data<=root->data)
	{root->left=insert(root->left,data);

	}
	else  root->right=insert(root->right,data);
	return root;
}
void inorder(struct node* root)
{if(root==NULL)
	return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);

}
struct node* maxinleft(struct node*root)
{if(root==NULL)
	return NULL;
	while(root->right!=NULL)
		root=root->right;
return root;
}struct node* mininright(struct node* root)
{if(root==NULL)
	return NULL;
	while(root->left!=NULL)
		root=root->left;
	return root;

}
void findpreandsucc(struct node* root,struct node** pre,struct node** succ,int k)
{if(root==NULL)
	return;
	if(root->data<k)
	{*pre=root;
		findpreandsucc(root->right,pre,succ,k);

	}
	else if(root->data>k)
	{*succ=root;
		findpreandsucc(root->left,pre,succ,k);

	}
	else{
		struct node*left=maxinleft(root->left);
		if(left)
			*pre=left;
		struct node* right=mininright(root->right);
		if(right)
			*succ=right;


	}

}
int mininrightdata(struct node* root)
{while(root->left!=NULL)
	root=root->left;
return root->data;
}
struct node* deletenode(struct node* root,int k)
{if(root==NULL)
	return NULL;
	if(k<root->data)
		root->left=deletenode(root->left,k);
	else if(k>root->data)
		root->right=deletenode(root->right,k);
	else{
		if(root->left==NULL)
		{struct node* temp=root->right;
			free(root);
			root=NULL;
			return temp;


		}
		else if(root->right==NULL)
		{struct node* temp=root->left;
			free(root);
			root=NULL;
			return temp;

		}else{
			int data=mininrightdata(root->right);
			root->data=data;
			root->right=deletenode(root->right,data);

		}
	}
return root;
}
bool isbstutil(struct node* root,int min,int max)
{if(root==NULL)
	return true;
	if(root->data<min||root->data>max)
		return false;
	return isbstutil(root->left,min,root->data)&&isbstutil(root->right,root->data,max);

}
bool isbst(struct node* root)
{int min=INT_MIN;
	int max=INT_MAX;
	return isbstutil(root,min,max);

}
void  converttogreaterutil(struct node* root,int& sum)
{if(root==NULL)
	return ;
	converttogreaterutil(root->right,sum);
	cout<<"sum "<<sum<<" ";
	root->data=root->data+sum;
	sum=root->data;
	converttogreaterutil(root->left,sum);

}
struct node* converttogreater(struct node* root)
{int sum=0;
	 converttogreaterutil(root,sum);
	 return root;

}
int morris(struct node*&root)
{int ans;
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
			ans=root->data;
			left->right=NULL;
			root=root->right;
			break;

		}



	}

	}
	return ans;

}
void mergemorris(struct node* a,struct node* b)
{struct node*first=a;
	struct node* second=b;
	int ans1;int ans2;
	ans1=morris(first);
	 ans2=morris(second);
	while(first!=NULL&&second!=NULL)
	{ 
		if(ans1<ans2)
		{
			cout<<ans1<<" ";
			ans1=morris(first); 
		}
		else if(ans2<ans1)
		{cout<<ans2<<" ";
	ans2=morris(second);

		}
		else {
			cout<<ans1<<" ";
			ans1=morris(first);
			ans2=morris(second);
		}

	}
	if(first!=NULL)
		cout<<ans1<<" ";
	while(first!=NULL)
		{cout<<morris(first)<<" ";}
	if(second!=NULL)
		cout<<ans2<<" ";
	while(second!=NULL)
		cout<<morris(second)<<" ";

}
int main()
{struct node* root=NULL;
	root=insert(root,5);
	root=insert(root,3);
	root=insert(root,6);
	root=insert(root,45);
	root=insert(root,23);
	root=insert(root,8);
	root=insert(root,9);
	root=insert(root,2);
	
	struct node* root1=NULL;
	root1=insert(root1,45);
	root1=insert(root1,34);
	root1=insert(root1,5);
	root1=insert(root1,4);
	root1=insert(root1,89);
	root1=insert(root1,8);
	mergemorris(root,root1);




return 0;
}