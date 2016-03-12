#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node* next;
};
struct node* newNode(int data)
{struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	return temp;	

}
void sortedInsert(struct node** head,int data)
{if(*head==NULL)
	{*head=newNode(data);(*head)->next=*head;return;}
struct node* temp=*head;struct node* root=*head;
if(data<=temp->data)
{while(temp->next!=root)
	temp=temp->next;
	temp->next=newNode(data);
	*head=temp->next;
	temp->next->next=root;

	return;
}
while(temp->next!=root&&data>temp->next->data)
	temp=temp->next;
struct node*g=temp->next;
temp->next=newNode(data);
temp->next->next=g;
return ;

}
void printList(struct node* head)
{struct node* root;
	while(head->next!=root)
	{cout<<head->data<<" ";
	head=head->next; 

	}
	cout<<head->data<<" ";
	cout<<endl;

}
int main()
{

int arr[] = {12, 56, 2, 11, 1, 90};
  
 int i;
  /* start with empty linked list */
  struct node *start = NULL;
 
  /* Create linked list from the array arr[].
    Created linked list will be 1->2->11->56->12 */
  for(i = 0; i< 6; i++)
  {
    
    sortedInsert(&start, arr[i]);
  }
 
  printList(start);

return 0;	
}