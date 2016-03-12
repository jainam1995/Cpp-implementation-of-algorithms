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
void push(struct node** head;int data)
{if(*head==NULL)
	{*head=newNode(data);
		return;}
struct node* temp=newNode(data);
temp->right=*head;
*head->left=temp;
*head=temp;

}
void quicksort(struct node* root)
{
	
}
int main()
{struct node* root=NULL;
	push(&root,4);

	push(&root,2);

	push(&root,-5);
	push(&root,1);
	push(&root,9);

	push(&root,0);
	push(&root,-2);
	push(&root,5);
	quicksort(root);
	while(root!=NULL)
	{cout<<root->data<<" ";
	root=root->right;
	}
cout<<endl;





	return 0;
}