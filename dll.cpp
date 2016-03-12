#include <bits/stdc++.h>
using namespace std;
struct node
{int data;
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
void push(struct node** head,int data)
{if((*head)==NULL)
	{*head=newNode(data);return;}
	struct node* temp=newNode(data);
	temp->right=*head;
	(*head)->left=temp;
	*head=temp;

}
void printList(struct node* temp)
{while(temp!=NULL)
	{cout<<temp->data<<" ";
	temp=temp->right;

	}

}
int main()
{/* Start with the empty list */
  struct node* head = NULL;
 
  /* Let us create a sorted linked list to test the functions
   Created linked list will be 10->8->4->2 */
  push(&head, 2);
  push(&head, 4);
  push(&head, 8);
  push(&head, 10);
 
  printf("\n Original Linked list ");
  printList(head);
 
  /* Reverse doubly linked list */
 // reverse(&head);
 
  printf("\n Reversed Linked list ");
  printList(head);           

	return 0;
}