#include <bits/stdc++.h>
using namespace std;
struct node
{int data;struct node* left;struct node* right;int l;

};
struct node* newNode(int data)
{struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->left=NULL;
	temp->right=NULL;
	temp->data=data;
	temp->l=1;
	return temp;

}
void printList(struct node* head)
{while(head)
	{cout<<head->data<<" ";head=head->right;}
	cout<<endl;

}
void inorder(struct node* root)
{if(root==NULL)
	return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);

}
void push(struct node**head,int data)
{if(*head==NULL)
	{*head=newNode(data);
		return;
	}
struct node* temp=newNode(data);
temp->right=*head;
(*head)->left=temp;
*head=temp;


}
int count(struct node* root)
{int count=0;
	while(root)
	{if(root!=NULL)
		count++;
		root=root->right;

	}
	return count;

}
struct node*sortedListToBSTutil(struct node**head,int n)
{if(n==0)
	return NULL;
	struct node* left=sortedListToBSTutil(head,n/2);
	struct node* root=*head;
	*head=(*head)->right;
	root->left=left;
	root->right=sortedListToBSTutil(head,n-n/2-1);
	return root; 

}
struct node* sortedListToBST(struct node* root)
{int n=count(root);
	return sortedListToBSTutil(&root,n);

}
struct node* insert(struct node* root,int data)
{if(root==NULL)
	return newNode(data);
	if(data<=root->data)
		root->left=insert(root->left,data);
	else root->right=insert(root->right,data);
	return root;

}
bool search(struct node* root,int data)
{if(root==NULL)
	return false;
	if(data==root->data)
		return true;
	if(data<root->data)
		return search(root->left,data);
	if(data>root->data)
		return search(root->right,data);

}
struct node* minintree(struct node* root)
{if(root==NULL)
	return NULL;
	while(root->left)
	{root=root->left;

	}
	return root;

}
struct node* deletes(struct node* root,int data)
{if(root==NULL)
	return NULL;
	if(data<root->data)
		root->left=deletes(root->left,data);
	else if(data>root->data)
		root->right=deletes(root->right,data);
	else{
		if(root->left==NULL)
		{struct node* temp=root->right;
			free(root);
			root=NULL;
			return temp;

		}
		else if(root->right==NULL)
		{struct node* temp=root->left;
			free(root);
			root=NULL;
			return temp;

		}
		else{struct node* temp=minintree(root->right);
			root->data=temp->data;
			root->right=deletes(root->right,temp->data);



		}
	}
return root;
}
struct node* maxintree(struct node* root)
{if(root==NULL)
	return NULL;
	while(root->right)
		root=root->right;
	return root;

}
void findPreSuc(struct node* root,struct node*&pre,struct node*&suc,int key)
{if(root==NULL)
	return;
	if(root->data<key)
		{pre=root;
			findPreSuc(root->right,pre,suc,key);}
		else if(root->data>key)
		{suc=root;
			findPreSuc(root->left,pre,suc,key);

		}
		else if(root->data==key)
		{struct node* temp=minintree(root->right);
			if(temp)
				suc=temp;
		temp=maxintree(root->left);
		if(temp)
			pre=temp;

		}

}
bool isbst(struct node* root,int min,int max)
{if(root==NULL)
	return true;
	if(root->data<min||root->data>max)
		return false;
	return isbst(root->left,min,root->data)&&isbst(root->right,root->data,max);


}
void bsttodllutil(struct node* root,struct node** pre,struct node**head)
{if(root==NULL)
	return;
	bsttodllutil(root->left,pre,head);
	if((*pre)==NULL)
	{*head=root;
		root->left=*pre;
		*pre=root;

	}
else{
	root->left=*pre;
	(*pre)->right=root;
	*pre=root;
}

bsttodllutil(root->right,pre,head);
}
struct node* bsttodll(struct node* root)
{struct node* pre=NULL;
	struct node* head=NULL;
	bsttodllutil(root,&pre,&head);


	return head;

}
void transformTreeutil(struct node* root,int *sum)
{if(root==NULL)
	return;
	transformTreeutil(root->right,sum);
	int old=root->data;
	root->data=*sum;
	*sum=old+*sum;
	transformTreeutil(root->left,sum);

}
void transformTree(struct node* root)
{int sum=0;
	transformTreeutil(root,&sum);

}
void  kthLargestutil(struct node* root,int *curr,int k,struct node**ref)
{if(root==NULL)
	return ;
	kthLargestutil(root->left,curr,k,ref);
	if(*curr==k)
	{if(*ref==NULL)
		{*ref=root;}	
		return;

	}
	else{
	(*curr)++;
	kthLargestutil(root->right,curr,k,ref);
}

}
void kthLargest(struct node* root,int k)
{int curr=1;struct node* ref=NULL;
	kthLargestutil(root,&curr,k,&ref);
	cout<<ref->data<<" ";

}
struct ListNode{
	int data;
	struct ListNode* next;
};
struct ListNode* newnode(int data)
{struct ListNode* temp=(struct ListNode*)malloc(sizeof(struct ListNode));
	temp->data=data;
	temp->next=NULL;
	return temp;

}
void push(struct ListNode**head,int data)
{struct ListNode* temp=newnode(data);
	temp->next=*head;
	*head=temp;

}
struct node* convertList2Binary(struct ListNode*& head)
{if(head==NULL)
	return NULL;


}
int Ceil(struct node* root,int i)
{if(root==NULL)
	return -1;
	if(root->data<i)
		return Ceil(root->right,i);
	if(root->data>i)
	{int ans=root->data;
		int second=Ceil(root->left,i);
		if(second!=-1&&second<ans)
			return second;
		else return ans;

	}

}
void correctBSTutil1(struct node* root,struct node** pre,struct node** oo,struct node**os,struct node** so,struct node**ss)
{if(root==NULL)
	return;
	correctBSTutil1(root->left,pre,oo,os,so,ss);
	if(*pre==NULL)
	{*pre=root;

	}
	else{
		if(root->data<(*pre)->data)
		{if((*oo)==NULL)
			{*oo=*pre;
				*os=root;

			}
			else if((*so)==NULL){
				*so=*pre;
				*ss=root;
				cout<<"sdf "<<root->data<<" sdf";
			}

		}
		*pre=root;
	}
	correctBSTutil1(root->right,pre,oo,os,so,ss);

}
void correctBSTutil21(struct node* root,struct node* oo,struct node* os,int ans)
{if(root==NULL)
	return;
	correctBSTutil21(root->left,oo,os,ans);
	if(root==oo)
		root->data=os->data;
	if(root==os)
		root->data=ans;
	correctBSTutil21(root->right,oo,os,ans);

}
void correctBSTutil22(struct node* root,struct node*& oo,struct node*& ss,int ans)
{if(root==NULL)
	return ;
	correctBSTutil22(root->left,oo,ss,ans);
	if(root==oo)
		root->data=ss->data;
	if(root==ss)
		{root->data=ans;
			}
	correctBSTutil22(root->right,oo,ss,ans);

}
void correctBST(struct node* root)
{struct node* pre=NULL;struct node* firstfirst=NULL;struct node* firstsecond=NULL;struct node* secondfirst=NULL;struct node* secondsecond=NULL;
correctBSTutil1(root,&pre,&firstfirst,&firstsecond,&secondfirst,&secondsecond);
//cout<<firstfirst->data<<"dd "<<secondsecond->data;
if((secondsecond)==NULL)	
{
	correctBSTutil21(root,firstfirst,firstsecond,firstfirst->data);
}
else correctBSTutil22(root,firstfirst,secondsecond,firstfirst->data);
}
struct node* removeOutsideRange(struct node* root,int l,int r)
{if(root==NULL)
	return NULL;
	root->left=removeOutsideRange(root->left,l,r);
	root->right=removeOutsideRange(root->right,l,r);
	if(root->data<l)
	{struct node * temp=root->right;
		free(root);
		root=NULL;
		return temp;

	}
	else if(root->data>r)
	{struct node*temp=root->left;
		free(root);
		root=NULL;
		return temp;

	}
return root;

}
struct node* sortedArrayToBST(int *a,int l,int r)
{if(l>r)
	return NULL;
	int mid=l+(r-l)/2;
	struct node* root=newNode(a[mid]);
	root->left=sortedArrayToBST(a,l,mid-1);
	root->right=sortedArrayToBST(a,mid+1,r);
	return root;

}
void Print(struct node* root,int a,int b)
{if(root==NULL)
	return;
	if(root->data>=a)
		Print(root->left,a,b);
	if(root->data<=b)
		Print(root->right,a,b);
	if(root->data>=a&&root->data<=b)
		cout<<root->data<<" ";

}
struct node* lca(struct node* root,int a,int b)
{if(root==NULL)
	return NULL;
	if(root->data==a||root->data==b)
		return root;
	struct node* l=lca(root->left,a,b);
	struct node* r=lca(root->right,a,b);
	if(l&&r)
		return root;
	if(l)
		return l;
	else return r;

}
struct node* lcabst(struct node* root,int a,int b)
{if(root==NULL)
	return NULL;
	if(root->data==a||root->data==b)
		return root;
	if(root->data>a&&root->data<b)
		return root;
	if(root->data>b)
		return lcabst(root->left,a,b);
	else return lcabst(root->right,a,b);


}
bool isleaf(struct node* root)
{if(root==NULL)
	return false;
	if(root->left==NULL&&root->right==NULL)
		return true;
	return false;

}
struct node* removeShortPathNodes(struct node* root ,int k)
{if(root==NULL)
	return NULL;
	root->left=removeShortPathNodes(root->left,k-1);
	root->right=removeShortPathNodes(root->right,k-1);
	if(isleaf(root))
	{if(k>1)
		{free(root);
		root=NULL;
		return NULL;
	}
	}
return root;
}
struct node* constructTreeutil(int *pre,char *preLN,int *count,int n)
{if(*count>=n)
	return NULL;
	struct node* root=newNode(pre[*count]);
	if(preLN[*count]=='N')
	{(*count)++;
		root->left=constructTreeutil(pre,preLN,count,n);
		root->right=constructTreeutil(pre,preLN,count,n);
	}
	else{
		(*count)++;
	}
	return root;
}
struct node* constructTree(int * pre,char *preLN,int n)
{int count=0;
	return constructTreeutil(pre,preLN,&count,n);

}
void printLeft(struct node* root)
{if(root==NULL)
return ;
if(isleaf(root))
return ;
cout<<root->data<<" ";
if(root->left)
	printLeft(root->left);
else printLeft(root->right);
}
void printLeaves(struct node* root)
{if(root==NULL)
	return;
	printLeaves(root->left);
	if(isleaf(root))
		cout<<root->data<<" ";
	printLeaves(root->right);

}
void printRight(struct node* root)
{if(root==NULL)
return ;
if(isleaf(root))
return ;
if(root->right)
printRight(root->right);
else printRight(root->left);
cout<<root->data<<" ";   
}
void printBoundary(struct node* root)
{if(root==NULL)
	return ;
	cout<<root->data<<" ";
	printLeft(root->left);
	printLeaves(root);
	printRight(root->right);

}
struct node* inserts(struct node* root,int data)
{if(root==NULL)
	{root=newNode(data);
		return root;

	}
	struct node* temp=root;
while(true)
{if(data<=root->data)
	{(root->l)++;
		if(root->left==NULL)
			{root->left=newNode(data);return temp;}
		else root=root->left;

	}
	else {
		if(root->right==NULL)
			{root->right=newNode(data);return temp;}
		else root=root->right;
	}

}
return root;
}
int kthsmallest(struct node* root,int k)
{if(root==NULL)
	return -1;
	if(root->l==k)
		return root->data;
	if(k<root->l)
		return kthsmallest(root->left,k);
	else if(root->l<k)
		return kthsmallest(root->right,k-root->l);


}
void inorders(struct node* root)
{if(root==NULL)
	return ;
	inorders(root->left);
	cout<<root->l<<" ";
	inorders(root->right);

}
struct node* btreetodllutil(struct node* root)
{if(root==NULL)
	return NULL;
	root->left=btreetodllutil(root->left);
	root->right=btreetodllutil(root->right);
	if(root->left)
	{struct node* left=root->left;
		while(left->right)
			left=left->right;
		left->right=root;
		root->left=left;

	}
	if(root->right)
	{struct node* right=root->right;
		while(right->left)
			right=right->left;
		right->left=root;
		root->right=right;

	}
	return root;

}
struct node* btreetodll(struct node* root)
{struct node* temp=btreetodllutil(root);
	while(temp->left)
		temp=temp->left;
	return temp;

}
bool isIsomorphic(struct node* a,struct node* b)
{if(a==NULL&&b==NULL)
	return true;
	if(a==NULL||b==NULL)
		return false;
	if(a->data!=b->data)
		return false;
	return isIsomorphic(a->left,b->left)&&isIsomorphic(a->right,b->right)||isIsomorphic(a->left,b->right)&&isIsomorphic(a->right,b->left);

}
void bottomviewutil1(struct node* root,int *min,int *max,int level)
{if(root==NULL)
	return ;
	if(level<*min)
		*min=level;
	if(level>*max)
		*max=level;
	bottomviewutil1(root->left,min,max,level-1);
	bottomviewutil1(root->right,min,max,level+1);

}
struct top
{int data;
	int  levels;

};
void bottomviewutil2(struct node* root,int level,int min,struct top a[],int height)
{if(root==NULL)
	return ;
	
	if(a[level-min].levels>=height)
	{a[level-min].data=root->data;
		a[level-min].levels=height;}
	bottomviewutil2(root->left,level-1,min,a,height+1);
	bottomviewutil2(root->right,level+1,min,a,height+1);

}
void bottomview(struct node* root)
{int min=INT_MAX;int max=INT_MIN;int level=0;int height=0;
	bottomviewutil1(root,&min,&max,level);
	struct top a[max-min+1];
	for(int i=0;i<max-min+1;i++)
		a[i].levels=INT_MAX;
	bottomviewutil2(root,level,min,a,height);
	for(int i=0;i<max-min+1;i++)
	{cout<<"Level "<<min+i<<" - "<<a[i].data<<"\n";

	}
	cout<<a[0].levels<<"sdf";


}
int min(int a,int b)
{if(a<b)
	return a;
	else return b;

}

int closestdown(struct node* root)
{if(root==NULL)
 return INT_MAX;
 if(isleaf(root))
 	return 0;
 return 1+min(closestdown(root->left),closestdown(root->right));


}
bool fillarray(struct node* root,struct node* a[],int k,int *count)
{if(root==NULL)
	return false;
	if(root->data==k)
	{a[(*count)++]=root;
		return true;

	}
	if(fillarray(root->left,a,k,count)||fillarray(root->right,a,k,count))
	{a[(*count)++]=root;
		return true;

	}

}
int findClosest(struct node* root,int k)
{struct node* a[100];int count=0;
	fillarray(root,a,k,&count);
	int min=INT_MAX;
	for(int i=0;i<count;i++)
	{if(i+closestdown(a[i])<min)
		min=i+closestdown(a[i]);

	}
	return min;
}
void serializeutil(struct node* root,int *a,int* count)
{if(root==NULL)
	{a[(*count)++]=-1;
		return;

	}a[(*count)++]=root->data;
	serializeutil(root->left,a,count);
	
	serializeutil(root->right,a,count);

}
struct node* deserialize(int *a,int* start,int count)
{if(*start>=count||a[*start]==-1)
	{(*start)++;
		return NULL;}
	
	struct node* root=newNode(a[*start]);
	(*start)++;
	root->left=deserialize(a,start,count);
	root->right=deserialize(a,start,count);
return root;

}
void serialize(struct node* root)
{int a[100];
	int count=0;
	serializeutil(root,a,&count);

	int start=0;
	struct node* temp=deserialize(a,&start,count);
inorder(temp);
}
int getlevel(struct node* root,int a,int level)
{if(root==NULL)
	return -1;
	if(root->data==a)
		return level;
	int l=getlevel(root->left,a,level+1);
	if(l!=-1)
		return l;
	return getlevel(root->right,a,level+1);

}
int findDistance(struct node* root,int a,int b)
{struct node* temp=lca(root,a,b);
	int level=0;
	int l=getlevel(root,a,level);
	int r=getlevel(root,b,level);
	return l+r-2*getlevel(root,temp->data,level);


}
void treePathsSumutil(struct node* root,int temp,int *count)
{if(root==NULL)
	return;
	temp=10*temp+root->data;
	if(isleaf(root))
		*count=*count+temp;
	treePathsSumutil(root->left,temp,count);
	treePathsSumutil(root->right,temp,count);


}
int treePathsSum(struct node* root)
{int temp=0;
	int count=0;
treePathsSumutil(root,temp,&count);
return count;
}
int search(int *a,int l,int h,int data)
{for(int i=l;i<=h;i++)
	{if(a[i]==data)
		return i;

	}
	return -1;

}
struct node* constructTreeutil(int *pre,int *post,int *count,int l,int h,int n)
{if(*count>=n||l>h)
	return NULL;
	struct node* root=newNode(pre[*count]);
 (*count)++;
 if(l==h)
 	return root;
 int index=search(post ,l,h,pre[*count]);
 if(index!=-1)
 {root->left=constructTreeutil(pre,post,count,l,index,n);
 root->right=constructTreeutil(pre,post,count,index+1,h,n);
}
 return root;

}
struct node* constructTree(int *pre,int *post,int n)
{int count=0;int l=0;int h=n-1;
	return constructTreeutil(pre,post,&count,l,h,n);

}
void levelorder(struct node* root)
{if(root==NULL)
	return ;
	struct node* mark=NULL;
	struct node* temp;
	queue<struct node* >q;
	q.push(root);
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
struct node* deserializelevel(int *a,int i,int count)
{queue<struct node*>q;struct node* temp;
	struct node* root=newNode(a[i]);
	q.push(root);
	i++;
	while(!q.empty())
	{temp=q.front();
	
		if(i>=count||a[i]==-1)
			temp->left=NULL;
			else {temp->left=newNode(a[i]);q.push(temp->left);}
			i++;
		if(i>=count||a[i]==-1)
			temp->right=NULL;
		else {temp->right=newNode(a[i]);q.push(temp->right);}
		i++;
		q.pop();

		

	}
	return root;
}
void serializelevel(struct node* root)
{queue<struct node*> q;
	if(root==NULL)
		return;
	int count=0;int a[100];
	struct node* temp;
	q.push(root);
	while(!q.empty())
	{temp=q.front();
		q.pop();
		a[count++]=temp->data;
		if(temp->left==NULL)
			a[count++]=-1;
		if(temp->right==NULL)
			a[count++]=-1;
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);

	}
	int i=0;
struct node* tem=deserializelevel(a,i,count);
levelorder(tem);
}
int main()
{  // Let us construct a tree shown in the above figure
    struct node *root        = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);
    levelorder( root);
    cout<<endl;
    serializelevel( root);
	return 0;
}