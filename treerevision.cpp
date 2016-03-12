#include <bits/stdc++.h>
using namespace std;
struct node{

int data;
struct node* left;
struct node* right;
struct node* next;

};
struct node* newNode(int data)
{
struct node* temp=(struct node*)malloc(sizeof(struct node));
temp->data=data;temp->left=NULL;
temp->right=NULL;
temp->next=NULL;
return temp;


}
int min(int a,int b)
{if(a<b)
	return a;
	return b;

}
int min(int a,int b,int c)
{int min=a;
	if(b<min)
		min=b;
	if(c<min)
		min=c;
	return min;

}
int max(int a,int b)
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
bool isleaf(struct node* temp)
{if(temp==NULL)
	return false;
	if(temp->right==NULL&&temp->left==NULL)
		return true;
	return false;

}
void preorder(struct node* temp)
{if(temp==NULL)
	return;
	cout<<temp->data<<" ";
	preorder(temp->left);
	preorder(temp->right);

}
void inorder(struct node* temp)
{if(temp==NULL)
	return;
	
	inorder(temp->left);
	cout<<temp->data<<" ";
	inorder(temp->right);

}
void postorder(struct node* temp)
{if(temp==NULL)
	return;
	
	postorder(temp->left);
	postorder(temp->right);
	cout<<temp->data<<" ";

}
void levelorder(struct node* temp)
{queue<struct node*>q;struct node* mark;;
if(temp==NULL)
	return;
q.push(temp);
while(!q.empty())
{temp=q.front();
	q.pop();
	cout<<temp->data<<" ";
	if(temp->left)
		q.push(temp->left);
	if(temp->right)
		q.push(temp->right);



}

}
int size(struct node* temp)
{if(temp==NULL)
	return 0;
	else return 1+size(temp->left)+size(temp->right);


}
bool identicalTrees(struct node* a,struct node* b)
{if(a==NULL&&b==NULL)
	return true;
	if(a==NULL||b==NULL)
		return false;
	if(a->data==b->data&&identicalTrees(a->left,b->left)&&identicalTrees(a->right,b->right))
		return true;
	return false;

}
int maxDepth(struct node* temp)
{if(temp==NULL)
	return 0;
	else return 1+max(maxDepth(temp->left),maxDepth(temp->right));

}
void deleteTree(struct node* temp)
{if(temp==NULL)
	return;
	deleteTree(temp->left);
	deleteTree(temp->right);
	free(temp);
	temp=NULL;

}
void mirror(struct node* temp)
{if(temp==NULL)
return;
struct node* root=temp->left;
temp->left=temp->right;
temp->right=root;
mirror(temp->left);
mirror(temp->right);
}
void printarray(int *a,int len){

for(int i=0;i<len;i++)
	{cout<<a[i]<<" ";}
cout<<endl;

}
void printPathsrecur(struct node* root,int *path,int len)
{if(root==NULL)
	return;
	path[len++]=root->data;
	if(isleaf(root))
		printarray(path,len);
	else{
printPathsrecur(root->left,path,len);
printPathsrecur(root->right,path,len);

	}

}
void printPaths(struct node* root)
{int path[100];int len=0;
	printPathsrecur(root,path,len);


}
int getLeafCount(struct node* temp)
{if(temp==NULL)
	return 0;
	if(isleaf(temp))
		return 1;
	else return getLeafCount(temp->left)+getLeafCount(temp->right);

}
void printSpiral(struct node* root)
{
	stack<struct node*>s1;stack<struct node*>s2;struct node* temp;
	if(root==NULL)
		return;
	s1.push(root);
	while(!s1.empty()||!s2.empty())
	{while(!s1.empty())
		{
		temp=s1.top();s1.pop();
		cout<<temp->data<<" ";
		if(temp->right)
			s2.push(temp->right);
		if(temp->left)
			s2.push(temp->left);
	}
	while(!s2.empty())
	{temp=s2.top();
		cout<<temp->data<<" ";
		s2.pop();
		if(temp->left)
			s1.push(temp->left);
		if(temp->right)
			s1.push(temp->right);

	}

	}
}
bool isSumProperty(struct node* root)
{if(root==NULL)
	return true;
	int l=0;int r=0;
	if(isleaf(root))
		return true;
	if(root->left)
		l=root->left->data;
	if(root->right)
		r=root->right->data;
	if((root->data==l+r)&&isSumProperty(root->left)&&isSumProperty(root->right))
		return true;
	return false;


}
void increment(struct node* root,int diff)
{if(root==NULL)
	return;
	root->data+=diff;
	if(root->left)
		increment(root->left,diff);
	else if(root->right)
		increment(root->right,diff);


}
void convertTree(struct node* root)
{if(root==NULL||isleaf(root))
	return;
	convertTree(root->left);
	convertTree(root->right);
	int l=root->left->data;
	int r=root->right->data;
	int diff=l+r-root->data;
	if(diff>0)
		root->data=l+r;
	else{
		diff=-diff;
		if(root->left){
			increment(root->left,diff);
		}
		else if(root->right)
			increment(root->right,diff);


	}



}
int diameter1(struct node* root)
{if(root==NULL)
	return 0;
	int ld=diameter1(root->left);
	int rd=diameter1(root->right);
	int lh=maxDepth(root->left);
	int rh=maxDepth(root->right);
	return max(ld,rd,1+lh+rh);


}
int diameter2(struct node* root,int * height)
{
   int lh=0;int rh=0;
   if(root==NULL)
   {*height=0;
   	return 0;

   }
   int ld=diameter2(root->left,&lh);
   int rd=diameter2(root->right,&rh);
   *height=max(lh,rh)+1;
   return max(ld,rd,lh+rh+1);
}
int abs(int a)
{if(a>=0)
	return a;
	else return -1*a;

}
bool isBalanced(struct node* root,int *height)
{if(root==NULL)
	{	*height=0;
		return true;
	}
	int lh=0;int rh=0;
	bool l=isBalanced(root->left,&lh);
	bool r=isBalanced(root->right,&rh);
	*height=max(lh,rh)+1;
	if(!l||!r)
		return false;
	if(abs(lh-rh)<=1)
		return true;
	else return false;



}
void inorderiterative(struct node* root)
{struct node* temp=root;
	stack<struct node*>s;
	bool done=false;
	while(!done)
	{if(temp!=NULL)
		{s.push(temp);
		temp=temp->left;
	}
	else{
		if(!s.empty())
		{struct node* another=s.top();
			cout<<s.top()->data<<" ";
		s.pop();
		temp=another->right;

		}
		else done=true;

	}



	}


}
void MorrisTraversal(struct node* root)
{if(root==NULL)
	return;
	struct node* curr=root;
	while(curr)
	{if(curr->left==NULL)
		{cout<<curr->data<<" ";
		curr=curr->right;
		}
	else{
		struct node* left=curr->left;
		while(left->right!=NULL&&left->right!=curr)
			left=left->right;
		if(left->right==NULL)
			{left->right=curr;
		curr=curr->left;
	}
		else if(left->right==curr)
		{left->right=NULL;
			cout<<curr->data<<" ";
			curr=curr->right;

		}


	}

	}

}
void MorrisTraversalPreOrder(struct node* root)
{if(root==NULL)
	return;
	struct node* curr=root;
	while(curr)
	{if(curr->left==NULL)
		{cout<<curr->data<<" ";
		curr=curr->right;
		}
	else{
		struct node* left=curr->left;
		while(left->right!=NULL&&left->right!=curr)
			left=left->right;
		if(left->right==NULL)
			{left->right=curr;
				cout<<curr->data<<" ";
		curr=curr->left;

	}
		else if(left->right==curr)
		{left->right=NULL;
			//cout<<curr->data<<" ";
			curr=curr->right;

		}


	}

	}

}
bool hasPathSum(struct node* root,int sum)
{if(root==NULL)
	return false;
	sum=sum-root->data;
	if(sum<0)
		return false;
	if(sum==0&&isleaf(root))
		return true;
	return hasPathSum(root->left,sum)||hasPathSum(root->right,sum);

}
int search(int *a,int data,int l,int r)
{for(int i=l;i<=r;i++)
	{if(a[i]==data)
		return i;

	}

}
struct node* buildTreeutil(int* in,int *pre,int* preindex,int l,int r,int n)
{if(*preindex>=n)
	return NULL;
	if(l>r)
		return NULL;
	int i=search(in,pre[(*preindex)++],l,r);
struct node* root=newNode(in[i]);
root->left=buildTreeutil(in,pre,preindex,l,i-1,n);
root->right=buildTreeutil(in,pre,preindex,i+1,r,n);

return root;
}
struct node* buildTree(int* in,int* pre,int l,int r,int n)
{int preindex=0;
	struct node* root=buildTreeutil(in,pre,&preindex,l,r,n);
	return root;

}
void doubleTree(struct node* root)
{
	if(root==NULL)
		return;
	struct node* temp=root->left;
	root->left=newNode(root->data);
	root->left->left=temp;
	doubleTree(root->left->left);
	doubleTree(root->right);


}
void getmaxutil(struct node* root,int* count,int level)
{if(root==NULL)
	return;
	count[level]++;
	getmaxutil(root->left,count,level+1);
	getmaxutil(root->right,count,level+1);

}
int getMaxWidth(struct node* root)
{int height=maxDepth(root);
	int count[height];
	for(int i=0;i<=height;i++)
		count[i]=0;

	getmaxutil(root,count,1);
	int max=count[0];
for(int i=1;i<=height;i++)
	if(count[i]>max)
		max=count[i];
	return max;

}
bool aremirror(struct node* a,struct node* b)
{if(a==NULL&&b==NULL)
	return true;
	if(a==NULL||b==NULL)
		return false;
	return (aremirror(a->left,b->right)&&aremirror(a->right,b->left));

}
bool isFoldable(struct node* root)
{if(root==NULL)
	return true;
	if(aremirror(root->left,root->right))
		return true;
	return false;

}
void printKDistantUtil(struct node* root,int level,int k)
{if(root==NULL)
	return;
	if(level>k)
	return;
	if(level==k)
	{cout<<root->data<<" ";
		return;
	}
printKDistantUtil(root->left,level+1,k);
printKDistantUtil(root->right,level+1,k);

}
void printKDistant(struct node* root,int k)
{
	int level=0;
	printKDistantUtil(root,level,k);
}
int getlevelutil(struct node* root,int data,int level)
{if(root==NULL)
return -1;
if(root->data==data)
return level;
int l=getlevelutil(root->left,data,level+1);
if(l!=-1)
	return l;
else return getlevelutil(root->right,data,level+1);
}
int getLevel(struct node* root,int data)
{int level=0;
	return getlevelutil(root,data,level);

}
bool printAncestors(struct node* root,int data)
{if(root==NULL)
	return false;
	if(root->data==data)
		return true;
	if(printAncestors(root->left,data)||printAncestors(root->right,data))
		cout<<root->data;

}
bool isSumTree2(struct node* root)
{if(root==NULL||isleaf(root))
	return true;
	if(!isSumTree2(root->left)||!isSumTree2(root->right))
		return false;
	int l=0;int r=0;int ans=0;
	if(root->left)
	{if(isleaf(root->left))
		ans=ans+root->left->data;
		else ans=2*root->left->data;

	}
if(root->right)
{if(isleaf(root->right))
	ans=ans+root->right->data;
	else ans=ans+2*root->right->data;


}
if(root->data==ans)
return true;
else return false;

}
void connect(struct node* root)
{
	if(root==NULL)
		return;
	queue<struct node* >q;struct node* temp;struct node* mark=NULL;
	q.push(root);
	q.push(mark);
	while(!q.empty())
	{temp=q.front();
		q.pop();
		if(temp==mark)
		{if(!q.empty())
			q.push(mark);


		}
		else
		{temp->next=q.front();
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);


		}

	}
}
void populateNext(struct node* root)
{if(root==NULL)
	return;
	static struct node* pre=NULL;
	populateNext(root->right);
	root->next=pre;
	pre=root;
	populateNext(root->left);


}


int toSumTree(struct node* root)
{if(root==NULL)
	return 0;
	int old=root->data;
	root->data=toSumTree(root->left)+toSumTree(root->right);
	return old+root->data;

}
void findminleft(struct node* root,int level,int * min,int *max)
{if(root==NULL)
	return;
	if(level<*min)
		*min=level;
	if(level>*max)
		*max=level;
	findminleft(root->left,level-1,min,max);
	findminleft(root->right,level+1,min,max);

}
void fillaraay(list<int>*& a,struct node* root,int min,int level)
{if(root==NULL)
	return;
	a[level+min].push_back(root->data);
	fillaraay(a,root->left,min,level-1);
	fillaraay(a,root->right,min,level+1);

}
void verticalsum(struct node* root)
{int min=0;int level=0;int max=0;
	findminleft(root,level,&min,&max);
	list<int> *a=new list<int>[max-min+1];
	fillaraay(a,root,-1*min,level);
for(int i=0;i<max-min+1;i++)
{cout<<"the nodes in level "<<i+1<<" are : ";
list<int >::iterator t;
for(t=a[i].begin();t!=a[i].end();t++)
	cout<<*t<<" ";
cout<<endl;

}
}
void findmaxnode(struct node* root,struct node** ref,int& max,int sum)
{if(root==NULL)
	return;
	sum=sum+root->data;
	if(isleaf(root))
	{if(sum>max)
		{max=sum;
			*ref=root;
				
		}
	}
	else{

		findmaxnode(root->left,ref,max,sum);
		findmaxnode(root->right,ref,max,sum);

	}

}
int maxSumPath(struct node* root)
{int max=-10000;int sum=0;struct node* ref=NULL;
	findmaxnode(root,&ref,max,sum);

printAncestors(root,ref->data);
return max;
}
int findmax(int *a,int l,int r)
{int max=a[l];int maxindex=l;
	for(int i=l;i<=r;i++)
	{if(a[i]>max)
		{max=a[i];
			maxindex=i;

		}

	}
	return maxindex;

}
struct node* buildTree2(int *inorder,int l,int r)
{if(l>r)
	return NULL;
	
	int i=findmax(inorder,l,r);
	struct node* root=newNode(inorder[i]);
	root->left=buildTree2(inorder,l,i-1);
	root->right=buildTree2(inorder,i+1,r);
	return root;

}
struct node* constructTreeUtil(int *pre,char* ln,int n,int& index)
{if(index>=n)
	return NULL;
	struct node* root=newNode(pre[index]);
	if(ln[index++]=='N')
	{root->left=constructTreeUtil(pre,ln,n,index);
		root->right=constructTreeUtil(pre,ln,n,index);

	}
	return root;


}
struct node* constructTree(int *pre,char*ln,int n)
{int index=0;
	struct node* root = constructTreeUtil(pre,ln,n,index);
	return root;


}
bool isCompleteBT(struct node* root)
{if(root==NULL)
	return true;
	queue<struct node*>q;
	bool halfseen=false;
	q.push(root);
	while(!q.empty())
	{
			struct node* temp=q.front();
			q.pop();
			if(temp->left)
			{if(halfseen)
				return false;
				q.push(temp->left);

			}
			else halfseen=true;
			if(temp->right)
				{if(halfseen)
					return false;
					q.push(temp->right);
				}
			else halfseen=true;





	}

return true;

}
void printleaves(struct node* root)
{if(root==NULL)
	return;
	if(isleaf(root))
		cout<<root->data<<" ";
	else{
		printleaves(root->left);
		printleaves(root->right);


	}
	}
void printleft(struct node*root)

{

while(root)
{	if(!isleaf(root))
	cout<<root->data<<" ";
if(root->left)
root=root->left;
else root=root->right;

}
}
void printright(struct node* root)
{if(root==NULL)
	return;
	if(root->right)
		printright(root->right);
	else printright(root->left);
		if(!isleaf(root))
		cout<<root->data<<" ";

}

void printBoundary(struct node* root)
{if(root==NULL)
	return;
	cout<<root->data<<" ";
	printleft(root->left);
	printleaves(root);
	printright(root->right);

}
int searchinpost(int *a,int data,int l,int r)
{for(int i=l;i<=r;i++)
if(a[i]==data)
	return i;
}
struct node* constructTree3(int* pre,int* post,int n,int *preindex,int l,int r)
{if(l>r||*preindex>=n)
	return NULL;
	struct node* root=newNode(pre[*preindex]);
	(*preindex)++;
	int i=searchinpost(post,pre[*preindex],l,r);
	root->left=constructTree3(pre,post,n,preindex,l,i);
	root->right=constructTree3(pre,post,n,preindex,i+1,r);

return root;

}
void iterativePreorder(struct node* root)
{if(root==NULL)
	return;
	stack<struct node*>s;
	struct node* curr=root;bool done=false;
	while(!done)
	{cout<<curr->data<<" ";
	s.push(curr);
	if(curr->left)
		curr=curr->left;
	else if(curr->right)curr=curr->right;
else {if(!s.empty())
	{curr=s.top();
	s.pop();
}
else done=true;
	}
	}

}
void insert(struct node**root,int data,queue<struct node*>& q)
{if((*root)==NULL)
	{*root=newNode(data);
	q.push(*root);
}
	
	else 
	{cout<<q.front()->data<<" jai ";
		struct node* temp;
		temp=q.front();
		if(temp->left==NULL)
			{temp->left=newNode(data);
				q.push(temp->left);}
		else if(temp->right==NULL)
		{temp->right=newNode(data);
			q.push(temp->right);

		}
		else{
			q.pop();
			cout<<"asd";
			insert(root,data,q);

		}

	}

}
void reverseLevelOrder(struct node* root)
{if(root==NULL)
	return;
	stack<struct node*>s;
	queue<struct node*>q;q.push(root);
while(!q.empty())
{struct node* temp=q.front();
	q.pop();
	s.push(temp);
	if(temp->right)
		q.push(temp->right);
	if(temp->left)q.push(temp->left);

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
struct ListNode* newlistnode(data)
{struct ListNode* temp=(struct ListNode*)malloc(sizeof(ListNode));
	temp->data=data;
	temp->next=NULL;
	return temp;


}
void push(struct ListNode** head,int data)
{if(*head==NULL)
	*head=newlistnode(data);
	else{
		struct node* temp=newlistnode(data);
		temp->next=*head;
		*head=temp;

	}

}void convertList2Binary(struct ListNode* head ,struct node* root)
{
	
}
int main()
{ // create a linked list shown in above diagram
    struct ListNode* head = NULL;
    push(&head, 36);  /* Last node of Linked List */
    push(&head, 30);
    push(&head, 25);
    push(&head, 15);
    push(&head, 12);
    push(&head, 10); /* First node of Linked List */
 
    struct node *root;
    convertList2Binary(head, root);
 
    cout << "Inorder Traversal of the constructed Binary Tree is: \n";
    inorderTraversal(root);
 
  
    
	return 0;
}