#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <stack>
using namespace std;
struct node{
int data;
struct node* left;
struct node* right;
struct node*nextRight;

};

struct node* newNode(int data)
{struct node* temps=(struct node*)malloc(sizeof(struct node));
	temps->data=data;
	temps->left=NULL;
	temps->right=NULL;
	temps->nextRight=NULL;
	return temps;	



}
void preorder(struct node* root)
{if(root==NULL)
	return ;

	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);

}
void inorder(struct node* root)
{if(root==NULL)
	return ;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);

}
void postorder(struct node* root)
{if(root==NULL)
	return  ;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";

}
int size(struct node* root)
{if(root==NULL)
	return 0;
	return (1+size(root->left)+size(root->right));

}
bool identicalTrees(struct node* root1,struct node* root2)
{

if(root1==NULL&& root2==NULL)
	return true;
if(root1==NULL|| root2==NULL)
	return false;
return ((root1->data==root2->data)&&identicalTrees(root1->left,root2->left)&&identicalTrees(root1->right,root2->right));

}
int max(int a,int b)
{
	if(a>b)
		return a;
	else return b;
}
int maxDepth(struct node* root)
{if(root==NULL)
	return 0;
	return 1+max(maxDepth(root->left),maxDepth(root->right));



}
void deleteTree(struct node* root)
{if(root==NULL)
	return ;
	deleteTree(root->left);
	deleteTree(root->right);
	free(root);
	root=NULL;

}
void mirror(struct node* root)
{
	if(root==NULL)
		return;
	mirror(root->left);
	mirror(root->right);
	struct node* temp=root->left;
	root->left=root->right;
	root->right=temp;
}
bool isleaf(struct node* root)
{if(root==NULL)
	return false;
	if(root->left==NULL&&root->right==NULL)
		return true;
	return false;

}
void printpathutil(struct node* root,int a[],int len)
{if(root==NULL)
	return;
	a[len]=root->data;
	len++;
	if(isleaf(root))
	{for(int i=0;i<len;i++)
		cout<<a[i]<<" ";
		cout<<endl;
	}
	else{

		printpathutil(root->left,a,len);
		printpathutil(root->right,a,len);
	}

}
void printPaths(struct node* root)
{int a[1000];int len=0;
	printpathutil(root,a,len);


}
void levelorder(struct node* root)
{queue<struct node*> q;
	if(root==NULL)
		return ;
	q.push(root);
	while(!q.empty())
	{struct node* temp=q.front();
		q.pop();
		cout<<temp->data<<" ";
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);

	}


}
int getLeafCount(struct node* root)
{if(root==NULL)
	return 0;
	if(isleaf(root))
		return 1;
	return(getLeafCount(root->left)+getLeafCount(root->right));

}
void spiral(struct node* root)
{stack<struct node*>s1;stack<struct node*>s2;
	if(root==NULL)
		return;
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
bool issumproperty(struct node* root)
{if(root==NULL)
	return true;
	if(isleaf(root))
		return true;
	int l=0;int r=0;
	if(root->left)
		l=root->left->data;
	if(root->right)
		r=root->right->data;
	if((root->data==l+r)&&issumproperty(root->left)&&issumproperty(root->right))
		return true;
	return false;


}
int max3(int a,int b,int c)
{int max=a;
	if(b>max)
		max=b;
	if(c>max)
		max=c;
	return max;

}
int diameterlong(struct node* root)
{if(root==NULL)
	return 0;
	int lh=maxDepth(root->left);
	int rh=maxDepth(root->right);
	int ld=diameterlong(root->left);
	int rd=diameterlong(root->right);

	return max3(1+lh+rh,ld,rd);

}
int diametershort(struct node* root,int* height)
{
if(root==NULL)
	{*height=0;
		return 0;
	}
int lh=0;int rh=0;
int ld=diametershort(root->left,&lh);
int rd=diametershort(root->right,&rh);
*height=max(lh,rh)+1;

return max3((1+lh+rh),ld,rd);


}
int abs(int a)
{
	if(a<0)
		return -1*a;
	else return a;
}
bool isBalanced(struct node* root,int* height)
{
if(root==NULL)
	{*height=0;
		return true;
	}
int lh=0;int rh=0;
bool l=isBalanced(root->left,&lh);
bool r=isBalanced(root->right,&rh);
*height=max(lh,rh)+1;

if((abs(rh-lh)<=1)&&l&&r )
	return true;
return false;


}
void MorrisTraversal(struct node* root)
{if(root==NULL)return;
	struct node* curr=root;
	while(curr!=NULL)
	{if(curr->left==NULL)
		{cout<<curr->data<<" ";
		curr=curr->right;

		}
		else{
		struct node* left=curr->left;
		while(left->right!=NULL&&left->right!=curr)
			left=left->right;
		
		if(left->right==curr)
		{left->right=NULL;
			cout<<curr->data<<" ";
			curr=curr->right;
			
		}
	else if(left->right==NULL)
		{
			left->right=curr;
			curr=curr->left;
		}
	}
	}


}
bool hasPathSum(struct node* root,int sum)
{if(root==NULL&&sum==0)
	return true;
	if(root==NULL&&sum!=0)
		return false;

sum=sum-root->data;
if(sum==0&&isleaf(root))
return true;
if(sum<0)
return false;
if(sum==0&&!(isleaf(root)))
return false;
return(hasPathSum(root->left,sum)||hasPathSum(root->right,sum));

}
struct node* buildTree(int in[],int pre[],int preindex,int start,int end)
{if(start>end)
	return NULL;
	int i;

	struct node* temp=newNode(pre[preindex++]);
	for( i=start;i<=end;i++)
		{if(in[i]==temp->data)
			break;
			}
temp->left=buildTree(in,pre,preindex,start,i-1);
temp->right=buildTree(in,pre,preindex,i+1,end);


return temp;
}
void doubleTree(struct node* root)
{if(root==NULL)
	return ;
	struct node* temp=root->left;
	root->left=newNode(root->data);
	root->left->left=temp;
	doubleTree(root->left->left);
	doubleTree(root->right);
}
int getMaxWidth(struct node* root)
{if(root==NULL)
	return 0;
	struct node* temp;struct node*mark=NULL;
	int max=1;
	int count=0;
	queue<struct node*>q;
	q.push(root);
	
	q.push(mark);
while(!q.empty())
{temp=q.front();
	q.pop();
	if(temp==mark)
	{if(count>max)
		max=count;
		count=0;
		if(!q.empty())
			q.push(mark);
	}
	else{
		count++;
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
	}

}
return max;
}
bool foldableutil(struct node* left,struct node* right)
{
	if(left==NULL&&right==NULL)
		return true;
	if(left==NULL||right==NULL)
		return false;
	return foldableutil(left->left,right->right)&&foldableutil(left->right,right->left);
}
bool isFoldable(struct node* root)
{
	if(root==NULL)
		return true;
	return foldableutil(root->left,root->right);
}
void printKDistant(struct node* root,int k,int level)
{
	if(root==NULL)
		return;
	if(k==level)
		cout<<root->data<<" ";
	else{
		printKDistant(root->left,k,level+1);
		printKDistant(root->right,k,level+1);
	}
}
int getlevelutil(struct node* root,int data,int level)
{if(root==NULL)
	return -1;
	if(root->data==data)
		return level;
	int a=getlevelutil(root->left,data,level+1);
	if(a!=-1)
		return a;
	else return getlevelutil(root->right,data,level+1);




}
int getLevel(struct node* root,int data)
{
	int level=0;
	return getlevelutil(root,data,level);
}
bool printAncestors(struct node* root,int data)
{
	if(root==NULL)
		return false;
	if(root->data==data)
		return true;
	if(printAncestors(root->left,data)||printAncestors(root->right,data))
	{cout<<root->data<<" ";
	return true;
	}
}
bool isSumTree(struct node* root)
{
	if(root==NULL||isleaf(root))
		return true;
	int l;int r;
	if(!isSumTree(root->left)||(!isSumTree( root->right)))
	return false;
if(root->left==NULL)
	l=0;
else if(isleaf(root->left)) l=root->left->data;
else l=2*root->left->data;
if(root->right==NULL)
	r=0;
else if(isleaf(root->right))r=root->right->data;
else r=2*root->right->data;
if(root->data==(l+r))
return true;
return false;
}
void connect(struct node* root)
{if(root==NULL)
	return;
	struct node* temp;
	struct node* mark=NULL;
	queue<struct node*>q;
	q.push(root);
	q.push(mark);
	while(!q.empty())
	{temp=q.front();
		q.pop();

		if(temp==mark)
			{if(!q.empty())
				q.push(mark);}
				else {if(q.front()!=mark)
					temp->nextRight=q.front();
				else temp->nextRight=NULL;
				if(temp->left)
					q.push(temp->left);
				if(temp->right)
					q.push(temp->right);
}

	}


}
void populateNext(struct node* root)
{
static node* next=NULL;
	if(root==NULL)
		return;
populateNext(root->left);
root->nextRight=next;
next=root;
populateNext(root->right);
}
int  toSumTree(struct node* root)
{if(root==NULL)
	return 0;
	int old_data=root->data;
	root->data=toSumTree(root->left)+toSumTree(root->right);
	return old_data+root->data;



}

void maxsumpathutil(struct node* root,int sum,int *max)
{if(root==NULL)
	return;
	sum=sum+root->data;
	if(isleaf(root))
	{if(sum>*max)
		*max=sum;
		return;

	}

maxsumpathutil(root->left,sum,max);
maxsumpathutil(root->right,sum,max);


}


int maxSumPath(struct node* root)
{int sum=0;int max=0;
	maxsumpathutil(root,sum,&max);
return max;

}
struct node* constructTree(int pre[],char preLN[],int* pres,int n)
{if(*pres>n)
	return NULL;
	struct node* temp=newNode(pre[*pres]);
	//*pres++;
	if(preLN[(*pres)++]=='N')
	{	temp->left=constructTree(pre,preLN,pres,n);
		temp->right=constructTree(pre,preLN,pres,n);


	}
	return temp;

}
bool isCompleteBT(struct node* root)
{
	if(root==NULL)
		return true;
	bool hasseenhalf=false;
	queue<struct node*>q;
	q.push(root);
	while(!q.empty())
	{struct node* temp=q.front();
		q.pop();
		
		if(temp->left)
		{if(hasseenhalf)
			return false;
			q.push(temp->left);

		}
		else hasseenhalf=true;
		if(temp->right)
			{
		
				if(hasseenhalf)
			return false;
		q.push(temp->right);
		}else hasseenhalf=true;

	}
	return true;
}
void printleaves(struct node* root)
{if(root==NULL)
	return;
	printleaves(root->left);
	if(isleaf(root))
		cout<<root->data<<" ";
	printleaves(root->right);

}
void printleftmost(struct node* root)
{while(root)
	{if(isleaf(root))
		break;
		cout<<root->data<<" ";
	if(root->left)
		root=root->left;
	else if(root->right)
		root=root->right;
	else break;
	}
}
	void printrightmost(struct node* root)
{while(root)
	{if(isleaf(root))
		break;
		cout<<root->data<<" ";
	if(root->right)
		root=root->right;
	else if(root->left)
		root=root->left;
	else break;
	}

}
void printBoundary(struct node* root)
{
if(root==NULL)
	return ;
cout<<root->data<<" ";
printleftmost(root->left);
printleaves(root);
printrightmost(root->right);


}
void insert(struct node** ref,int data,queue<struct node*>& q)
{if(q.empty())
	{*ref=newNode(data);
		q.push(*ref);
		}
	else{
		struct node* temp=q.front();
if(temp->left && temp->right)
{q.pop();
temp=q.front();
}
if(!temp->left)
	{struct node* in=newNode(data);
		temp->left=in;
		q.push(in);}
		else if(!temp->right)
		{struct node* in=newNode(data);
			temp->right=in;
			q.push(in);

		}


	}
}
void reverseLevelOrder(struct node* root)
{queue<struct node*>q;stack<struct node*>s;
	if(root==NULL)
		return;
	q.push(root);
	while(!q.empty())
	{struct node* temp=q.front();
		q.pop();
		s.push(temp);
		if(temp->right)
			q.push(temp->right);
		if(temp->left)
			q.push(temp->left);
		

	}
	while(!s.empty())
	{cout<<s.top()->data<<" ";
s.pop();

	}


}
struct ListNode{
int data;
struct ListNode* next;


};
struct ListNode* newlistnode(int data)
{struct ListNode* temps=(struct ListNode*)malloc(sizeof(struct ListNode));
	temps->data=data;
	temps->next=NULL;
	return temps;

}
void push(struct ListNode**ref,int data)
{if(*ref==NULL)
*ref=newlistnode(data);
else{


	struct ListNode* temp=newlistnode(data);
	temp->next=*ref;
	*ref=temp;
}

}
struct node* convertList2Binary(struct ListNode* head)
{queue<struct ListNode*>q;
	q.push(head);
	head=head->next;
	while(!q.empty())
	{

	}


}
struct node* bintree2list(struct node* root)
{if(root==NULL)
	return NULL;
	if(root->left)
	{
	struct node* left=bintree2list(root->left);
	while(left->right)
		left=left->right;
	left->right=root;
	root->left=left;
}if(root->right)
{
	struct node* right=bintree2list(root->right);
	while(right->left)
		right=right->left;
	right->left=root;
	root->right=right;

}

return root;
}


void printList(struct node* head)
{while(head)
	{cout<<head->data<<" ";
	head=head->right;

	}

}
bool check(struct node* root)
{queue<struct node*>q;struct node*temp;struct node* mark=NULL;bool first=false; bool second=false;
if(root==NULL)
return true;
q.push(root);
q.push(mark);
while(!q.empty())
{
	temp=q.front();q.pop();
	if(temp==mark)
	{if(first==true)
		second=true;

		if(!q.empty())
			q.push(mark);
	}
	else{
		if(second==true)
			return false;
	if(isleaf(temp))
		first=true;
	if(temp->left)
		q.push(temp->left);
	if(temp->right)
		q.push(temp->right);

}
}
return true;
}
struct node* removeleaves(struct node* root)
{if(root==NULL)
	return NULL;
	if(isleaf(root))
		return NULL;
	removeleaves(root->left);
	removeleaves(root->right);

	return root;

}
struct node* extractLeafListutil(struct node* root,struct node** head)
{static struct node* curr;
if(root==NULL)
	return NULL;
root->left=extractLeafListutil(root->left,head);
if(isleaf(root))
{
if((*head)==NULL)
{*head=root;
curr=*head;
return NULL;
}
else {curr->right=root;
curr=root;
return NULL;
}
}
root->right=extractLeafListutil(root->right,head);
return root;
}
struct node* extractLeafList(struct node* root,struct node** head )
{
	root=extractLeafListutil(root,head);
	//inorder(root);
	//

	//getchar();
	struct node* temp=root;
	//cout<<root->data;
	//getchar();
	while(temp->left!=NULL)
		temp=temp->left;
	
	struct node* prev=NULL;
	struct node* curr=temp;
	while(curr)
	{curr->left=prev;
		prev=curr;
		curr=curr->right;

	}
	//printList()
	
	return root;
}
void deepestLeftLeaf(struct node* root,int level,int *max,bool isleft,struct node** ref)
{if(root==NULL)
	return ;
	if(isleft&&isleaf(root))
	{if(level>(*max))
		{(*max)=level;
			(*ref)=root;}

	}
	deepestLeftLeaf(root->left,level+1,max,true,ref);
	deepestLeftLeaf(root->right,level+1,max,false,ref);

}
void treepathsumutil(struct node* root,int number,int *ans)
{if(root==NULL)
	return;
	number=10*number+root->data;
	if(isleaf(root))
	{*ans=*ans+number;

	}
	treepathsumutil(root->left,number,ans);
	treepathsumutil(root->right,number,ans);


}
int treePathsSum(struct node* root)
{int ans=0;int number=0;
	treepathsumutil(root,number,&ans);
	return ans;

}
int findLCA(struct node* root,int one,int two)
{if(root==NULL)
	return -1;
	if(root->data==one||root->data==two)
		return root->data;
	int first=findLCA(root->left,one,two);
	int second=findLCA(root->right,one,two);
	if(first!=-1&&second!=-1)
		return root->data;
	if(first!=-1)
		return first;
	return second;

}
int findlevelutil(struct node* root,int level,int data)
{if(root==NULL)
	return -1;
	if(root->data==data)
		return level;
	int left=findlevelutil(root->left,level+1,data);
	if(left!=-1)
		return left;
	else return findlevelutil(root->right,level+1,data);

}
int findlevel(struct node* root,int data)
{int level=0;
	return findlevelutil(root,level,data);

}
int findDistance(struct node* root,int one,int two)
{int lca=findLCA(root,one,two);
return findlevel(root,one)+findlevel(root,two)-2*findlevel(root,lca);
}
void printkleafutil(struct node* root,int a[],int len,int k,int visited[])
{if(root==NULL)
	return;
	visited[len]=0;
	a[len++]=root->data;
	if(isleaf(root))
	{if((len-k-1)>=0&&visited[len-k-1]==0)
		cout<<a[len-k-1]<<" ";
		visited[len-k-1]=1;

	}
	printkleafutil(root->left,a,len,k,visited);
	printkleafutil(root->right,a,len,k,visited);

}
void printKDistantfromLeaf(struct node* root,int k)
{int array[1000];int len=0;int visited[1000];
	for(int i=0;i<1000;i++)
		visited[i]=0;
	printkleafutil(root,array,len,k,visited);

}
void reverseAlternate(struct node* root)

{queue<struct node* >q;int g;int h;
	int a[1000];int i=0;
	int count=0;int start;int end;bool rotate=false;
	struct node* temp;struct node* mark=NULL;
	q.push(root);
	q.push(mark);
	while(!q.empty())
	{temp=q.front();
		q.pop();
		if(temp==mark)
		{if((++count)&1)
			{//count=1;
				start=i;

				//rotate=false;
			}
		else 
				{//count=0;
					end=i-1;
					//cout<<"asd";
					//rotate=true;
					for(g=start,h=end;g<h;g++,h--)
			{int temps=a[g];
				a[g]=a[h];
				a[h]=temps;

			}
				}
				if(!q.empty())
					q.push(mark);


		}
		else{

a[i++]=temp->data;
if(temp->left)
	q.push(temp->left);
if(temp->right)
	q.push(temp->right);

		}

	}
cout<<"\narray\n";
for(int k=0;k<i;k++)
	cout<<a[k]<<" ";

}
void serialize(struct node* root,int a[],int& i)
{if(root==NULL)
	{a[i++]=-1;
return;}

a[i++]=root->data;
serialize(root->left,a,i);
serialize(root->right,a,i);

}
void deSerialize(struct node* &root,int a[],int* i,int n)
{
	if(*i>=n||a[*i]==-1)
	return;
	root=newNode(a[(*i)++]);
	//cout<<(*root)->data<<" asd";
	deSerialize(root->left,a,i,n);
	deSerialize(root->right,a,i,n);

}
int main()
{  
   
   // Let us construct a tree shown in the above figure
    struct node *root        = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);
 
    // Let us open a file and serialize the tree into the file
    int a[1000];int i=0;
    serialize(root, a,i);
    //fclose(fp);
 
    // Let us deserialize the storeed tree into root1
    struct node* root2=NULL;
    i=0;
    deSerialize(root2, a,&i,7);
 //cout<<root2->data;
    printf("Inorder Traversal of the tree constructed from file:\n");
    preorder(root2);
 
	return 0;
}