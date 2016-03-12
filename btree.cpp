/*program to print all of its root-to-leaf paths for a tree*/
#include <stdio.h>
#include <stdlib.h>
 #include <iostream>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
 
void printArray(int [], int);
void printPathsRecur(struct node*, int [], int);
struct node* newNode(int );
void printPaths(struct node*);
 
/* Given a binary tree, print out all of its root-to-leaf
   paths, one per line. Uses a recursive helper to do the work.*/  
void printPaths(struct node* node) 
{
  int path[1000];
  printPathsRecur(node, path, 0);
}
 
/* Recursive helper function -- given a node, and an array containing
 the path from the root node up to but not including this node,
 print out all the root-leaf paths. */
void printPathsRecur(struct node* node, int path[], int pathLen) 
{
  if (node==NULL) return;
 
  /* append this node to the path array */
  path[pathLen] = node->data;
  pathLen++;
 
  /* it's a leaf, so print the path that led to here */
  if (node->left==NULL && node->right==NULL) 
  {
    printArray(path, pathLen);
  }
  else
  {
  /* otherwise try both subtrees */
    printPathsRecur(node->left, path, pathLen);
    printPathsRecur(node->right, path, pathLen);
  }
}
 
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}
 
/* Utility that prints out an array on a line */
void printArray(int ints[], int len)
{
  int i;
  for (i=0; i<len; i++) {
    printf("%d ", ints[i]);
  }
  printf("\n");
} 

struct node** createqueue()
{struct node* a[1000];
	return a;


}
void enqueue(struct node*a[],struct node* root,int *front,int *back)
{if(*front==-1)
	{*front=0;*back=0;
		a[*back]=root;}
else {a[++(*back)]=root;}

}
bool empty(struct node* a[],int *front,int* back)
{if(*front==-1&&*back==-1)
	return true;
	else return false;

}
struct node* pops(struct node* a[],int* front,int* back)
{if(*front==*back)
	{struct node* temp=a[*front];
	*front=*back=-1;
	return temp;

}
else return a[(*front)++];
}
 void printLevelOrder(struct node* root)
 {struct node **a=createqueue();
 	int front =-1;int back=-1;
enqueue(a,root,&front,&back);
while(!empty(a,&front,&back))
{struct node* temp=pops(a,&front,&back);
	cout<<temp->data<<" ";
	//cout<<"dfg"<<temp->left->data;
	if(temp->left)
	enqueue(a,temp->left,&front,&back);
	if(temp->right)
	enqueue(a,temp->right,&front,&back);
}


 
 }

/* Driver program to test mirror() */
int main()
{
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(9);
  root->left->left  = newNode(7);
  root->left->right = newNode(5); 
 
  printf("Level Order traversal of binary tree is \n");
  printLevelOrder(root);
 
 // getchar();
  return 0;
}
