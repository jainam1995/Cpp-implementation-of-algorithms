#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct node
{int data;
	struct node* left;
	struct node* right;
	bool rightthread;

};
struct node* leftmost(struct node*root)
{if(root==NULL)
	return NULL;
	else{while(root->left)
		root=root->left;}
return root;
}


void inorder(struct node* root)
{if(root=NULL)
	return;
	struct node* curr=leftmost(root)
	while(curr)
	{cout<<curr<<" ";
if(curr->rightthread)
	curr=curr->right;
else curr=leftmost(curr->right);


	}


}
int main()
{






	return 0;
}