#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct node
{int data;
	struct node* left;
	struct node* right;



};

struct node* newNode(int data)
{struct node* news=(struct node*)malloc(sizeof(node));
	news->left=NULL;
	news->right=NULL;
	news->data=data;

	return news;


}
void printPreorder(struct node* root)
{if(root==NULL)
return;
cout<<root->data<<" ";
printPreorder(root->left);
printPreorder(root->right);

}
void printInorder(struct node* root)
{if(root==NULL)
return;

printInorder(root->left);
cout<<root->data<<" ";
printInorder(root->right);

}
void printPostorder(struct node* root)
{if(root==NULL)
return;

printPostorder(root->left);

printPostorder(root->right);
cout<<root->data<<" ";

}
int main()
{
 struct node *root  = newNode(1);
     root->left             = newNode(2);
     root->right           = newNode(3);
     root->left->left     = newNode(4);
     root->left->right   = newNode(5); 
 
     printf("\n Preorder traversal of binary tree is \n");
     printPreorder(root);
 
     printf("\n Inorder traversal of binary tree is \n");
     printInorder(root);  
 
     printf("\n Postorder traversal of binary tree is \n");
     printPostorder(root);
 
     getchar();
     return 0;








	return 0;
}