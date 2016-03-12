#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node* left;
	struct node* right;
	int  rank;
};
struct node* newNode(int data)
{struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	temp->rank=1;
	return temp;

}
struct node* insert(struct node* root,int data)
{if(root==NULL)
	{root=newNode(data);}
	else{struct node* temp=root;int count=0;
		while(temp)
		{if(data<=temp->data)
			{temp->rank++;
				if(temp->left==NULL)
					{temp->left=newNode(data);temp->left->rank+=count;break;}
				else
					temp=temp->left;

			}
			else if(data>temp->data)
			{count=temp->rank;
				if(temp->right==NULL)
				{temp->right=newNode(data);temp->right->rank+=count;break;}
				else
				temp=temp->right;


			}

		}





	}
	return root;


}
void inorder(struct node* root)
{if(root==NULL)
	return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);


}
void inorderrank(struct node *root)
{if(root==NULL)
	return;
	inorderrank(root->left);
	cout<<root->rank<<" ";
	inorderrank(root->right);


}
int main()
{
struct node* root=NULL;
	root=insert(root,5);
	root=insert(root,3);
	root=insert(root,6);
	root=insert(root,45);
	root=insert(root,23);
	root=insert(root,8);
	root=insert(root,9);
	root=insert(root,2);

inorder(root);
cout<<endl;
inorderrank(root);

return 0;
}