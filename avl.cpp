#include <bits/stdc++.h>
using namespace std;
struct node{
int data;
struct node* left;
struct node* right;
int height;	

};
struct node* newNode(int data)
{struct node* root=(struct node*)malloc(sizeof(struct node));
	root->data=data;
	root->left=NULL;
	root->right=NULL;
	root->height=1;
	return root;

}
void preorder(struct node* root)
{if(root==NULL)
	return ;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);

}int maxs(int a,int b)
{if(a>b)
	return a;
	else return b;

}
int getheight(struct node* root)
{if(root==NULL)
	return 0;
	return root->height;

}
int balance(struct node* root)
{if(root==NULL)
	return 0;
	return getheight(root->left)-getheight(root->right);

}
struct node* leftrotate(struct node* x)
{struct node* y=x->right;
	struct node* t=y->left;
	y->left=x;
	x->right=t;
	x->height=maxs(getheight(x->left),getheight(x->right))+1;
	y->height=maxs(getheight(y->left),getheight(y->right))+1;
return y;
}
struct node*rightrotate(struct node* y)
{
	struct node* x=y->left;
	struct node* t=x->right;
	x->right=y;
	y->left=t;
	y->height=maxs(getheight(y->left),getheight(y->right))+1;
	x->height=maxs(getheight(x->left),getheight(x->right))+1;
	return x;
}
int minvalue(struct node*root){
	while(root->left)
		root=root->left;
	return root->data;
}
struct node* insert(struct node* root,int data)
{if(root==NULL)
	return newNode(data);
	else if(data<root->data)
		root->left=insert(root->left,data);
	else if(data>root->data)
		root->right=insert(root->right,data);
	root->height=maxs(getheight(root->left),getheight(root->right))+1;
	int bal=balance(root);
	if(bal>1&&data<root->left->data)
	{return rightrotate(root);

	}else if (bal<-1&&data>root->right->data){

		return leftrotate(root);

	}
	 else if(bal>1&&data>root->left->data)
	{root->left=leftrotate(root->left);
		return rightrotate(root);


	}
	 else if(bal <-1&&data<root->right->data)
	{root->right=rightrotate(root->right);
		return leftrotate(root);

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
	else{if(root->left==NULL&&root->right==NULL)
		{free(root);
			root=NULL;



		}
		else{
			if(root->left==NULL)
			{

			}
			else if(root->left==NULL)
				return root->right;
			else{
				int mindata=minvalue(root->right);
				root->data=mindata;
				root->right=deletes(root->right,mindata);

			}


		}


	}
	if(root==NULL)
		return NULL;
	root->height=max(root->left->height,root->right->height)+1;
	int bal=balance(root);
	if(bal>1&&data<root->left->data)
		return rightrotate(root);
	else if(bal<-1&&data>root->right->data)
		return leftrotate(root);
	else if(bal>1&&data>root->left->data)
	{root->right=leftrotate(root->right);
		return rightrotate(root);
	}
		else if(bal <-1&&data<root->right->data)
		{root->left=rightrotate(root->left);
			return leftrotate(root);

		}
return root;
	



}
int main()
{
	struct node *root = NULL;

  /* Constructing tree given in the above figure */
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);
root=deletes(root,50);
  /* The constructed AVL Tree would be
            30
           /  \
         20   40
        /  \     \
       10  25    50
  */

  printf("Pre order traversal of the constructed AVL tree is \n");
  preorder(root);
}