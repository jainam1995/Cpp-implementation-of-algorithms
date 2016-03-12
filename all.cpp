#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <queue>
using namespace std;
int i=0;
int a[10];


struct node{
int data;
struct node* left;
struct node* right;
struct node*nextRight;



};
struct nodes{
	char data;
	struct nodes* left;
	struct nodes* right;
};
int max(int a,int b)
{if(a>b)
	return a;
	else return b;


}
struct node* newNode(int data)
{struct node* news=(struct node*)malloc(sizeof(node));
	news->left=NULL;
	news->right=NULL;
	news->data=data;
	news->nextRight=NULL;
	return news;


}
int size(struct node* root)
{if(root==NULL)return 0;
	else return 1+size(root->left)+size(root->right);


}
bool identicalTrees(struct node* root1,struct node* root2)
{if(root1==NULL&&root2==NULL)
	return true;
	if(root1==NULL)
		return false;
	if(root2==NULL)
	return false;
	if(root1->data==root2->data&&identicalTrees(root1->left,root2->left)&&identicalTrees(root1->right,root2->right))
return true;

return false;
}
int maxDepth(struct node* root)
{if(root==NULL)
	return 0;
int lheight=maxDepth(root->left);
int rheight=maxDepth(root->right);

return 1+max(lheight,rheight);





}
void printInorders(struct nodes* node) 
{
  if (node == NULL) 
    return;
   
  printInorders(node->left);
  printf("%c ", node->data);
 
  printInorders(node->right);
}  
void printInorder(struct node* node) 
{
  if (node == NULL) 
    return;
   
  printInorder(node->left);
  printf("%d ", node->data);
 
  printInorder(node->right);
}  
void mirror(struct node* root)
{if(root==NULL)
	return;
	struct node* temp=root->left;
root->left=root->right;
root->right=temp;
mirror(root->left);
mirror(root->right);




}

int leaves(struct node* root)
{if(root==NULL)
	return 0;
	else if(root->left==NULL&&root->right==NULL)
		return 1+leaves(root->left)+leaves(root->right);
	else return leaves(root->left)+leaves(root->right);


}
void deleteTree(struct node*root)
{if(root==NULL)
	return;
	deleteTree(root->left);
	deleteTree(root->right);
	free(root);

}
void printPaths(struct node* root)
{
	if(root==NULL)
		return;
	else{ a[i++]=root->data;

}
	if(root->left==NULL&&root->right==NULL)
		{for(int j=0;j<i;j++)
			cout<<a[j]<<" ";
		cout<<"\n";
}

printPaths(root->left);
printPaths(root->right);
}
void printSpiral(struct node* root)
{stack<struct node*> s1;
	stack<struct node*>s2;
	s1.push(root);
	while(!s1.empty()||!s2.empty())
	{while(!s1.empty())
		{struct node* temp=s1.top();
			s1.pop();
			cout<<temp->data<<" ";
			if(temp->right)
				s2.push(temp->right);
			if(temp->left)
				s2.push(temp->left);
		}
		while(!s2.empty())
		{struct node* temp=s2.top();
			s2.pop();
			cout<<temp->data<<" ";
			if(temp->left)
				s1.push(temp->left);
			if(temp->right)
				s1.push(temp->right);
		}
	}



}
bool isSumProperty(struct node* root)
{
if(root==NULL||(root->left==NULL&&root->right==NULL ))
return true;
int l=0;int r=0;
if(root->left)
	l=root->left->data;
if(root->right)
	r=root->right->data;
if(root->data==l+r && isSumProperty(root->left)&&isSumProperty(root->right))
	return true;
return false;


}
void increment(struct node* node,int diff)
{if(node->left)
	{node->left->data+=diff;
		increment(node->left,diff);

	}
	else if(node->right)
	{node->right->data+=diff;
		increment(node->right,diff);


	}


}
void convertTree(struct node* root)
{if(root==NULL||(root->left==NULL&&root->right==NULL))
	return;
convertTree(root->left);
convertTree(root->right);
int left=0;
int right=0;
if(root->left)
	left=root->left->data;
if(root->right)
	right=root->right->data;
int diff=left+right-root->data;
if(diff>=0)
root->data+=diff;
else increment(root,-diff);




}
int max2(int a,int b)
{if(a>b)
	return a;
	else return b;

}
int max(int a,int b,int c)
{int max=a;
if(b>max)
	max=b;
if(c>max)
	max=c;

return max;

}

int height(struct node* root)
{if(root==NULL)return 0;
	else return max2(height(root->left),height(root->right))+1;

}
int diameter(struct node* root,int* height)
{	
	int lh=0;
	int rh=0;
	int ld=0;int rd=0;
	if(root==NULL)
		{*height=0;
return 0;
}
ld=diameter(root->left,&lh);
rd=diameter(root->right,&rh);

*height=max2(lh,rh)+1;

return max(1+lh+rh,ld,rd);

}int abs(int a)
{if(a>=0)
	return a;
	else return -1*a;

}
bool isBalanced(struct node* root,int * height)
{int lh=0;int rh=0;bool a=false;bool b=false;	
	if(root==NULL)
	{*height=0;
		return true;

	}

 a=isBalanced(root->left,&lh);
 b=isBalanced(root->right,&rh);
*height=max2(lh,rh)+1;
if(abs(lh-rh)<=1&&a&&b)
	return true;
else return false;


}
 void stackinorder(struct node* root)
 {stack<struct node*>s;
 	struct node* current=root;
 	int done=0;
 	while(!done)
 	{while(current)
 		{s.push(current);
 			current=current->left;

 		}
 		if(!s.empty())
 		{current=s.top();
 		s.pop();
 		cout<<current->data<<" ";
 		current=current->right;
 	}
 	else done=1;





 	}




 }
 struct node* rightmost(struct node*a,struct node* b)
 {while(a->right!=NULL&&a->right!=b)
 	{a=a->right;

 	}
return a;
 }
 void MorrisTraversal(struct node* root)
 {struct node* current=root;
 	if(current==NULL)
 		return;
 	while(current)
 	{if(current->left==NULL)
 		{cout<<current->data<<" ";
 		current=current->right;
 		}
 		else{
 			struct node* right=rightmost(current->left,current);
 				if(right->right==NULL)
 				{right->right=current;
 					current=current->left;

 				}
 				else{right->right=NULL;
 					cout<<current->data<<" ";
 					current=current->right;}


 		}

 	}


 }
bool hasPathSum(struct node* root,int k)
{

	if(root==NULL)
		return false;
	if(k<0)
		return false;
	if(root->data>k)
		return false;
	if(root->left==NULL&&root->right==NULL&&root->data==k)
		return true;
	if(hasPathSum(root->left,k-root->data)||hasPathSum(root->right,k-root->data))
		return true;
	return false;
}
void print(struct node* root,int a[],int len)
{

if(root==NULL)
	return;
a[len++]=root->data;
if(root->left==NULL&&root->right==NULL)
{for(int i=0;i<len;i++)
cout<<a[i]<<" ";
cout<<"\n";}
print(root->left,a,len);
print(root->right,a,len);
}
void printallPaths(struct node* root)
{int paths[1000];
int len=0;

print(root,paths,len);



}
void doubleTree(struct node* root)
{if(root==NULL)
	return;
	struct node* temp=root->left;
	root->left=newNode(root->data);
	root->left->left=temp;
	doubleTree(root->left->left);
	doubleTree(root->right);


}
int getMaxWidth(struct node* root)
{if(root==NULL)
	return 0;
	struct node* temp;
	queue<struct node*>q;int max=1;int curr=0;
	struct node* mark=NULL;
	q.push(root);
	q.push(mark);
	while(!q.empty())
	{temp=q.front();
		q.pop();
		if(temp==mark)
		{if(curr>max)
			max=curr;
			curr=0;
			if(!q.empty())
				q.push(mark);
		}		
		else{curr++;
			if(temp->left)
			q.push(temp->left);
			if(temp->right)
				q.push(temp->right);}
	}
return max;


}
bool isFoldable(struct node* left,struct node* right)
{
if(left==NULL&&right==NULL)
	return true;
if(left==NULL)
	return false;
if(right==NULL)
	return false;
if(isFoldable(left->left,right-right)&&isFoldable(left->right,right->left))
	return true;
return false;


}
void printKDistant(struct node* root,int k)
{if(root==NULL)
	return;
	if(k<0)
		return;
	if(k==0)
		cout<<root->data<<" ";
	printKDistant(root->left,k-1);
	printKDistant(root->right,k-1);


}
int util(struct node* root,int x,int level)
{if(root==NULL)
	return 0;
	if(root->data==x)
		return level;
	int a=util(root->left,x,level+1);
	if(a!=0)
		return a;
	else return util(root->right,x,level+1);

}
int getLevel(struct node* root,int x)
{int level=1;
return util(root,x,level);



}
bool printAncestors(struct node* root,int k)
{if(root==NULL)
	return false;
	if(root->data==k)
		return true;
	if(printAncestors(root->left,k)||printAncestors(root->right,k))
		{cout<<root->data<<" ";
//return true;
}
}
bool isleaf(struct node * root)
{if(root==NULL)
return false;
else if(root->left==NULL&&root->right==NULL)
return true;
else return false;
}
bool isSumTrees(struct node* root)
{if(root==NULL||(root->left==NULL&& root->right==NULL))
	return true;
	int ls;int rs;
	if(isleaf(root->left))
		ls=root->left->data;
	else if(!root->left)                                                       

		ls=0;
	else ls=2*root->left->data;
	if(isleaf(root->right))
		rs=root->right->data;
	else if(!root->right)
		rs=0;
	else rs=2*root->right->data;
	if(isSumTrees(root->left)&&isSumTrees(root->right)&&root->data==ls+rs)
		return true;
	else return false;



}
void connect(struct node* root)
{queue<struct node*>q;
	struct node* temp;
	struct node* mark=NULL;
	q.push(root);
	q.push(mark);
	while(!q.empty())
	{temp=q.front();
		q.pop();
		if(temp==mark)
		{if(!q.empty())
			q.push(mark);

		}
		else if(q.front()==mark)
			{temp->nextRight=NULL;
				if(temp->left)
					q.push(temp->left);
				if(temp->right)
				q.push(temp->right);}
		else
			{temp->nextRight=q.front();
			if(temp->left)
					q.push(temp->left);
				if(temp->right)
				q.push(temp->right);}



	}


}
void func(struct node*root,queue<struct node*> &q)
	{if(root==NULL)
		return;
		func(root->left,q);
		q.push(root);
		func(root->right, q);
		
 
	}
void populateNext(struct node* root)
{queue<struct node*>q;
	//struct node* temp;
	//struct node* mark=NULL;

func(root, q);
struct node* temp;
while(!q.empty())
{temp=q.front();
	q.pop();
	temp->nextRight=q.front();

}
struct node *ptr = root->left->left;
    while(ptr)
    {
        // -1 is printed if there is no successor
        printf("Next of %d is %d \n", ptr->data, ptr->nextRight? ptr->nextRight->data: -1);
        ptr = ptr->nextRight;
    }
}
int  toSumTree(struct node* root)
{if(root==NULL)
	return 0;
	int old=root->data;
	root->data=toSumTree(root->left)+toSumTree(root->right);

	return old+root->data;
}
struct node* constructTreeUtil (int pre[], int post[], int* preIndex,
                                int l, int h, int size)
{
    // Base case
    if (*preIndex >= size || l > h)
        return NULL;
 
    // The first node in preorder traversal is root. So take the node at
    // preIndex from preorder and make it root, and increment preIndex
    struct node* root = newNode ( pre[*preIndex] );
    ++*preIndex;
 
    // If the current subarry has only one element, no need to recur
    if (l == h)
        return root;
 
    // Search the next element of pre[] in post[]
    int i;
    for (i = l; i <= h; ++i)
       { if (pre[*preIndex] == post[i])
            break;
 }
    // Use the index of element found in postorder to divide postorder array in
    // two parts. Left subtree and right subtree
    if (i <= h)
    {
        root->left = constructTreeUtil (pre, post, preIndex, l, i-1, size);
        root->right = constructTreeUtil (pre, post, preIndex, i + 1, h, size);
    }
 
    return root;
}
 
// The main function to construct Full Binary Tree from given preorder and 
// postorder traversals. This function mainly uses constructTreeUtil()
struct node *constructTree (int pre[], int post[], int size)
{
    int preIndex = 0;
    return constructTreeUtil (pre, post, &preIndex, 0, size - 1, size);
}


struct nodes* newNodes(char ch)
{struct nodes* temp=(struct nodes*)malloc(sizeof(struct nodes));
	temp->data=ch;
	temp->left==NULL;
	temp->right==NULL;

}
struct nodes* buildTreeutil(char a[],char b[],int * pre,int l,int r,int size)
{if(*pre>size)
	return NULL;
	struct nodes* root=newNodes(a[*pre]);
	//cout<<root->data<<" ";
	++(*pre);
	if(l==r)
		return root;
	int i;
	for(i=l;i<=r;i++)
		{if(b[i]==root->data)

			break;}
			if(i<=r)
	{root->left=buildTreeutil(a,b,pre,l,i-1,size);
	root->right=buildTreeutil(a,b,pre,i+1,r,size);
}
return root;


}
struct nodes* buildTree(char a[],char b[],int l,int r)
{int pre=0;
	return buildTreeutil(b,a,&pre,l,r,r+1);


}
void maxsumutil(struct node* root,int currsum,int * maxsum,struct node** ref)
{if(root==NULL)
	return;
	currsum=currsum+root->data;
	if(root->left==NULL&&root->right==NULL)
	{if(currsum>*maxsum)
		{*maxsum=currsum;
			*ref=root;

		}

	}
	maxsumutil(root->left,currsum,maxsum,ref);
	maxsumutil(root->right,currsum,maxsum,ref);

}
bool printpath(struct node* root,struct node* target)
{if(root==NULL)
	return false;
	if(root==target)
		{cout<<root->data<<" ";
		return true;
	}
if(printpath(root->left,target)||printpath(root->right,target))
	{cout<<root->data<<" ";
return true;
}
}
int maxSumPath(struct node* root)
{int maxsum=0;int currsum=0;struct node* ref=root;
	maxsumutil(root,currsum,&maxsum,&ref);
printpath(root,ref);
return maxsum;


}
struct node* buildTrees(int a[],int start,int end)
{if(start>end)return NULL;
	int mid=(start+end)/2;
	struct node* temp=newNode(a[mid]);
	if(start==end)
		return temp;
temp->left=buildTrees(a,start,mid-1);
temp->right=buildTrees(a,mid+1,end);

return temp;

}
struct node* constructtreeutil(int pre[],char preLN[],int * pres,int size)
{if((*pres)>=size)
	return NULL;
	struct node* temp=newNode(pre[*pres]);
	if(preLN[*pres]=='N')
	{
	(*pres)++;
	temp->left=constructtreeutil(pre,preLN,pres,size);
	temp->right=constructtreeutil(pre,preLN,pres,size);
return temp;
}else
{

	(*pres)++;
return temp;
}


}
struct node* constructTrees(int pre[],char preLN[],int size)
{int pres=0;
	return constructtreeutil(pre,preLN,&pres,size);

}
bool isCompleteBT(struct node* root)
{bool partial=false;struct node* temp;
	queue<struct node* >q;
	if(root==NULL)
		return true;
	q.push(root);
	while(!q.empty())
	{temp=q.front();
		q.pop();
		if(temp->left)
		{if(partial==true)
			return false;
		q.push(temp->left);

		}
		else partial=true;
		if(temp->right)
		{if(partial==true)
			return false;
			q.push(temp->right);

		}
		else partial=true;

	}
return true;



}void printleft(struct node* root)
{if(root==NULL)
	return;
	if(root->left)
	{cout<<root->data<<" ";
	printleft(root->left);

	}
else if(root->right)
{	cout<<root->data<<" ";
	printleft(root->right);
}

}
void printleaves(struct node* root)
{if(root==NULL)
	return;
	printleaves(root->left);
	if(root->left==NULL&&root->right==NULL)
		cout<<root->data<<" ";
	printleaves(root->right);

}
void printright(struct node* root)
{
	if(root==NULL)
	return;
	if(root->right)
	{cout<<root->data<<" ";
	printright(root->right);

	}
else if(root->left)
{	cout<<root->data<<" ";
	printright(root->left);
}
}
void printBoundary(struct node* root)
{printleft(root->left);
	printleaves(root);
	printright(root->right);

}


void inserts(struct node* root,int data,queue<struct node*>& q)
{cout<<"ewr";
struct node* temp;struct node* temp2;
	
	 if(!q.empty())
	{temp=q.front();//q.pop();
		if(temp->left==NULL)
		{	temp2=newNode(data);
			temp->left=temp2;
			q.push(temp2);
			}
		else if(temp->right==NULL)
		{temp2=newNode(data);
			temp->right=temp2;
			q.push(temp2);

		}
		else {
			q.pop();
			inserts(root,data,q);
		}

	}
}
void levelOrder(struct node* root)
{if(root==NULL)
	return;
	struct node* temp;
	queue<struct node*>q;
	q.push(root);
	while(!q.empty())
	{temp=q.front();
		cout<<temp->data<<" ";
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
		q.pop();

	}

}
struct node* bintree2list(struct node* root)
{if(root==NULL)
	return NULL;
	if(root->left!=NULL)
	{struct node* left=bintree2list(root->left);
		while(left->right!=NULL)
			{left=left->right;}
		left->right=root;
		root->left=left;
	}
	if(root->right!=NULL)
	{struct node* right=bintree2list(root->right);
		while(right->left!=NULL)
			{right=right->left;}
		right->left=root;
		root->right=right;
	}
return root;

}
void printList(struct node* root)
{if(root==NULL)
	return ;
	cout <<root->data<<" ";
	printList(root->right);

}
void reverseLevelOrder(struct node* root)
{queue<struct node*>q;struct node* temp;
	stack<struct node*>s;
	if(root==NULL)
		return;
	q.push(root);
	while(!q.empty())
	{temp=q.front();
		s.push(temp);
		if(temp->right)
			q.push(temp->right);
		if(temp->left)
			q.push(temp->left);
		q.pop();


	}
while(!s.empty())
{cout<<s.top()->data<<" ";
s.pop();

}
}
bool isIsomorphic(struct node* one,struct node* two)
{if(one==NULL && two==NULL)
	return true;
if(one==NULL||two==NULL)
	return false;
if(one->data!=two->data)
	return false;
if(isIsomorphic(one->left,two->left)&&isIsomorphic(one->right,two->right)||isIsomorphic(one->left,two->right)&&isIsomorphic(one->right,two->left))
return true;
return false;
}
bool check(struct node* root)
{if(root==NULL)
	return true;
	struct node* temp;
	struct node* mark=NULL;
	bool hasseen=false;
	queue<struct node*>q;
q.push(root);
q.push(mark);
while(!q.empty())
{temp=q.front();
q.pop();
	if(!q.empty())
	{if(temp==mark)
		{if(hasseen)
			return false;
			q.push(mark);

		}
		else if(isleaf(temp))
		hasseen=true;
	else{if(temp->left)
		q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
		}
	}

	


}
return true;
}

struct node* pruneutil(struct node* root,int k,int *sum)
{if(root==NULL)
	return NULL;
	int lh=*sum+root->data;
	int rh=*sum+root->data;
	root->left=pruneutil(root->left,k,&lh);
	root->right=pruneutil(root->right,k,&rh);
	*sum=max(lh,rh);
	if(*sum<k)
		{free(root);
			root=NULL;}
return root;


}
struct node* prune(struct node* root,int k)
{int sum=0;
	struct node* roots=pruneutil(root,k,&sum);
return roots;
}
struct linked
{int data;
	struct linked* next;

};
struct linked* headw=NULL;
//head->next=NULL;head->data=0;

struct linked* curr=headw;
struct node* removeleaf(struct node* root)
{if(root==NULL)
	return NULL;
	if(isleaf(root))
		{
			if(headw==NULL)
				{headw=(struct linked*)malloc(sizeof(struct linked));
					headw->data=root->data;
					headw->next==NULL;
					curr=headw;
		}
		else{struct linked* temp=(struct linked*)malloc(sizeof(struct linked));
			temp->data=root->data;
			temp->next=NULL;
			curr->next=temp;
			curr=curr->next;


		}
		return NULL;
	}
	root->left=removeleaf(root->left);
	root->right=removeleaf(root->right);
return root;
}
void deeputil(struct node* root,int level,int *max,int isleft,struct node** ref)
{if(root==NULL)
	return ;
	if(isleft)
	{
		if(level>*max)
			{*max=level;
				*ref=root;}

	}
	deeputil(root->left,level+1,max,1,ref);
	deeputil(root->right,level+1,max,0,ref);

}
struct node* deepestleftleaf(struct node* root)
{int level=1;int max_level=1;struct node* temp=root;
	 deeputil(root,level,&max_level,0,&temp);
if(temp==root)
	return NULL;
return temp;
}
void test(struct node* root,int k)
{queue<struct node*>q;struct node* temp;struct node*mark=NULL;
	
	q.push(root);
	q.push(mark);
	while(!q.empty())
	{temp=q.front();
		q.pop();
		if(temp==mark)
			{if(!q.empty())
				q.push(mark);}
else{
if(temp->data==k)
{
	if(q.front()!=mark)
		cout<<"Next right to "<<temp->data<<" is "<<q.front()->data<<"\n";
	else cout<<"No next right found for "<<temp->data<<"\n";

	return;
}

if(temp->left)
	q.push(temp->left);
if(temp->right)
	q.push(temp->right);



}
}
}
void pathsumutil(struct node* root,int i,int *final)
{if(root==NULL)
	return;
	i=10*i+root->data;
	if(isleaf(root))
	{*final=*final+i;}
pathsumutil(root->left,i,final);
pathsumutil(root->right,i,final);


}
int treePathsSum(struct node* root)
{
int final=0;
int initial=0;
pathsumutil(root,initial,&final);

return final;

}
int findLCA(struct node* root,int a,int b)
{if(root==NULL)
	return -1;
	if(root->data==a||root->data==b)
		return root->data;
	int l=findLCA(root->left,a,b);
	int r=findLCA(root->right,a,b);
	if(l!=-1 && r!=-1)
		return root->data;
	if(l!=-1)
		return l;
	if(r!=-1)
		return r;

}
int levelutil(struct node* root,int a, int level)
{if(root==NULL)
	return -1;
	if(root->data==a)
	return level;
	int l=levelutil(root->left,a,level+1);
	if(l!=-1)
		return l;
	else return(levelutil(root->right,a,level+1));

}
int level (struct node* root,int a)
{return levelutil(root,a,1);



}
int findDistance(struct node* root,int a,int b)	
{int c=findLCA(root,a,b);
	//cout<<"c"<<c;
	return(level(root,a)+level(root,b)-2*level(root,c));

}
void kutil(struct node* root,int a[],int visited[],int len,int k)
{if(root==NULL)
	return;

	a[len++]=root->data;
	
	if(isleaf(root)&&(len-k-1>=0)&&visited[len-k-1]==0)
		{cout<<a[len-k-1]<<" ";
			visited[len-k-1]=1;
			return ;}
			kutil(root->left,a,visited,len,k);
			kutil(root->right,a,visited,len,k);


	

}
bool kfromleaf(struct node* root,int dist)
{int a[1000];int len=0;int visited[1000];
	for(int i=0;i<1000;i++)
		visited[i]=0;
	kutil(root,a,visited,len,dist);
	
	

}
struct node* insert(struct node* root,int data)
{if(root==NULL)
	{struct node* temp=newNode(data);
	return temp;
}
else{

if(data<=root->data)
	root->left=insert(root->left,data);
else root->right=insert(root->right,data);
return root;
}

}
struct node* deleteNode(struct node* root,int data)
{if(root==NULL)
	return NULL;
	if(data<root->data)
	root->left=deleteNode(root->left,data);
	else if(data>root->data)
		root->right=deleteNode(root->right,data);
	
else{
if(root->right==NULL)
	{struct node*temp=root->left;
		free(root);
		return temp;
	}
else if(root->left==NULL)
	{struct node*temp=root->right;
		free(root);
		return temp;
	}
else{struct node* temp=root->right;
	while(temp->left!=NULL)
		temp=temp->left;
root->data=temp->data;
root->right=deleteNode(root->right,temp->data);

}





	}return root;


}
int minValue(struct node* root)
{if(root==NULL)
	return -1;
	struct node* temp=root;
	while(temp->left!=NULL)
		temp=temp->left;
	return temp->data;

}
void findPreSuc(struct node* root,struct node*& pre,struct node*& suc,int data)
{if(root->left)
	root=root->left;
	pre=root;
	suc=root;



}
bool bstutil(struct node* root,int min,int max)
{if(root==NULL)
	return true;
	if(root->data<min||root->data>max)
		return false;
	return bstutil(root->left,min,root->data)&&bstutil(root->right,root->data,max);

}
bool isBST(struct node* root)
{int min=-9999999;int max=9999999;
	return bstutil(root,min,max);

}
struct node* lca(struct node* root,int a,int b)
{if(root==NULL)
	return NULL;
	if(root->data==a||root->data==b)
		return root;
	if(root->data>a&&root->data<b)
		return root;
	if(root->data>b)
		return lca(root->left,a,b);
	else return lca(root->right,a,b);

}
void Print(struct node* root,int l,int r)
{if(root==NULL)
	return;
	Print(root->left,l,r);
	if(root->data<r&&root->data>l)
		cout<<root->data<<" ";

	
	Print(root->right,l,r);
	

}
int main()
{ 
struct node *root = new struct node;
  int k1 = 10, k2 = 25;
 
  /* Constructing tree given in the above figure */
  root = newNode(20);
  root->left = newNode(8);
  root->right = newNode(22);
  root->left->left = newNode(4);
  root->left->right = newNode(12);
 
  Print(root, k1, k2);
     
    return 0;
  
}