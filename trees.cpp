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
void inorder(struct node* root)
{if(root==NULL)
	return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);

}
void preorder(struct node* root)
{if(root==NULL)
	return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);

}
void postorder(struct node* root)
{if(root==NULL)
	return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";


}
bool isleaf(struct node* root)
{if(root==NULL)
	return false;
	if(root->left==NULL&&root->right==NULL)
		return true;
	return false;

}
int max(int a,int b)
{if(a>b)
	return a;
	return b;

}
int max(int a,int b,int c)
{int max=a;
	if(b>max)
		max=b;
	if(c>max)
		max=c;
	return max;

}
int size(struct node* root)
{if(root==NULL)
	return 0;
	return 1+size(root->left)+size(root->right);

}
bool isidentical(struct node* a,struct node* b)
{if(a==NULL&&b==NULL)
	return true;
	if(a==NULL||b==NULL)
		return false;
	if(a->data!=b->data)
		return false;
	return isidentical(a->left,b->left)&&isidentical(a->right,b->right);

}
void deletetree(struct node* root)
{if(root==NULL)
	return;
	deletetree(root->left);
	deletetree(root->right);
	free(root);
	root=NULL;

}
void treetomirror(struct node* root)
{if(root==NULL)
	return;
	struct node* temp=root->left;
	root->left=root->right;
	root->right=temp;
	treetomirror(root->left);
	treetomirror(root->right);


}
void roottopathutil(struct node* root,int *path,int len)
{if(root==NULL)
	return;
	path[len++]=root->data;
	if(isleaf(root))
	{for(int i=0;i<len;i++)
		{cout<<path[i]<<" ";

		}
		cout<<endl;
		return;

	}
	roottopathutil(root->left,path,len);
	roottopathutil(root->right,path,len);

}
void roottopath(struct node* root)
{int path[100];
	int len=0;
	roottopathutil(root,path,len);

}
int maxDepth(struct node* root)
{if(root==NULL)
	return 0;
	return 1+max(maxDepth(root->left),maxDepth(root->right));

}
void levelorder(struct node* root)
{if(root==NULL)
	return;
	struct node* temp;
	queue<struct node*>q;
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
int countleafnodes(struct node* root)
{if(root==NULL)
	return 0;
	if(isleaf(root))
		return 1;
	return countleafnodes(root->left)+countleafnodes(root->right);

}
void spirallevelorder(struct node* root)
{if(root==NULL)
	return;
	stack<struct node*>s1;stack<struct node*>s2;struct node* temp;
	s1.push(root);
	while(!s1.empty()||!s2.empty())
	{while(!s1.empty())
		{temp=s1.top();
			s1.pop();
			cout<<temp->data<<" ";
			if(temp->left)
				s2.push(temp->left);
			if(temp->right)
				s2.push(temp->right);

		}
		while(!s2.empty())
		{temp=s2.top();
			s2.pop();
			cout<<temp->data<<" ";
			if(temp->right)
				s1.push(temp->right);
			if(temp->left)
				s1.push(temp->left);

		}

	}

}
void increment(struct node* root,int data)
{root->data+=data;
	if(root->left)
		increment(root->left,data);
	else if(root->right)
		increment(root->right,data);
}
void converttochildsum(struct node* root)
{if(root==NULL)
	return ;
	if(isleaf(root))
		return;
	converttochildsum(root->left);
	converttochildsum(root->right);
int l=0;int r=0;
if(root->left)
l=root->left->data;
if(root->right)
r=root->right->data;
int diff=l+r-root->data;
if(diff>=0)
root->data+=diff;
else{
diff=-diff;
if(root->left)
{increment(root->left,diff);

}
else if(root->right)
{increment(root->right,diff);}

}


}
bool ischildrensum(struct node* root)
{if(root==NULL)
	return true;
	if(isleaf(root))
		return true;
	int l=0;int r=0;
	if(root->left)
		l=root->left->data;
	if(root->right)
		r=root->right->data;
	if(root->data!=l+r)
		return false;
	return ischildrensum(root->left)&&ischildrensum(root->right);

}
int diameterutil(struct node* root,int *height)
{if(root==NULL)
	{*height=0;
		return 0;

	}
	int lh=0;int rh=0;int ld=0;int rd=0;
	 ld=diameterutil(root->left,&lh);
	 rd=diameterutil(root->right,&rh);

	*height=max(lh,rh)+1;
	return max(ld,rd,lh+rh+1);

}
int diameter(struct node* root)
{int height=0;
	return diameterutil(root,&height);


}
int abs(int a)
{if(a>=0)
return a;
else return -1*a;}
bool isheightbalancedutil(struct node* root,int * height)
{if(root==NULL)
	{*height=0;
		return true;

	}
	int lh=0;int rh=0;
	bool l=isheightbalancedutil(root->left,&lh);
	bool r=isheightbalancedutil(root->right,&rh);
	*height=max(lh,rh)+1;
	if(l==false||r==false)
		return false;
if(abs(lh-rh)<=1)
	return true;
else return false;


}
bool isheightbalanced(struct node* root)
{int height=0;
	return isheightbalancedutil( root,&height);

}
void inorderstack(struct node* root)
{if(root==NULL)
	return ;
	stack<struct node*>s;struct node* temp;
	struct node* curr=root;
	while(curr)
	{while(curr)
		{s.push(curr);
			curr=curr->left;

		}
		cout<<s.top()->data<<" ";
		temp=s.top();
		s.pop();
		while(true)
		{if(s.empty())
			return;
			if(temp->right!=NULL)
			{curr=temp->right;
				break;

			}
			else{
				cout<<s.top()->data<<" ";
		temp=s.top();
		s.pop();


			}

		}
		if(s.empty())
			return;


	}

}
void morris(struct node* root)
{if(root==NULL)
	return;
	struct node* curr=root;
	while(curr)
	{
		if(curr->left==NULL)
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
void rootpathsumequalnumberutil(struct node* root,int *path,int len,int sum)
{if(root==NULL)
	return;
	if(sum<0)
		return;
	path[len++]=root->data;
	sum=sum-root->data;
	if(sum==0&&isleaf(root))
	{for(int i=0;i<len;i++)
		cout<<path[i]<<" ";
		cout<<endl;

	}
	rootpathsumequalnumberutil(root->left,path,len,sum);
	rootpathsumequalnumberutil(root->right,path,len,sum);

}
void rootpathsumequalnumber(struct node* root,int sum)
{
	int path[100];int len=0;
	rootpathsumequalnumberutil(root,path,len,sum);
}
void doubletree(struct node* root)
{if(root==NULL)
	return;
	struct node* temp=root->left;
	root->left=newNode(root->data);
	root->left->left=temp;
	doubletree(root->left->left);
	doubletree(root->right);
	

	


}
void maxwidthutil(struct node* root,int *ans,int level)
{if(root==NULL)
	return;
	ans[level]++;
	maxwidthutil(root->left,ans,level+1);
	maxwidthutil(root->right,ans,level+1);

}
int  maxwidth(struct node* root)
{if(root==NULL)
	return 0;
	int h=maxDepth(root);
	int ans[h+1];
	for(int i=0;i<=h;i++)
		ans[i]=0;
	maxwidthutil(root,ans,1);
int maxs=ans[0];
for(int i=1;i<=h;i++)
{if(ans[i]>maxs)
	maxs=ans[i];

}
return maxs;
}
bool aremirror(struct node* a,struct node* b)
{if(a==NULL&&b==NULL)
return true;
if(a==NULL||b==NULL)
return false;
return aremirror(a->left,b->right)&&aremirror(a->right,b->left);

}
bool isfoldable(struct node* root)
{if(root==NULL)
	return true;
	return aremirror(root->left,root->right);
}
void nodesatk(struct node* root,int k)
{if(root==NULL)
	return;
	if(k<0)
	return;
	if(k==0)
		{cout<<root->data<<" ";
return;}
nodesatk(root->left,k-1);
nodesatk(root->right,k-1);

}
bool isSumTree(struct node* root)
{if(root==NULL)
	return true;
if(isleaf(root))
	return true;
int l;int r;
if(!isSumTree(root->left)||!isSumTree(root->right))
return false;
if(root->left==NULL)
l=0;
else if(isleaf(root->left))
l=root->left->data;
else l=2*root->left->data;
if(root->right==NULL)
r=0;
else if(isleaf(root->right))
r=root->right->data;
else r=2*root->right->data;
if(root->data==l+r)
	return true;
else return false;


}
bool printancestor(struct node* root,int k)
{if(root==NULL)
	return false;
		if(root->data==k)
			return true;
		if(printancestor(root->left,k)||printancestor(root->right,k))
			cout<<root->data<<" ";


}
int toSumTree(struct node* root)
{if(root==NULL)
	return 0;
	int old=root->data;
	root->data=toSumTree(root->left)+toSumTree(root->right);
	return root->data+old;





}
int max(int *a,int l,int r)
{int max=a[l];int maxindex=l;
	for(int i=l+1;i<=r;i++)
	{if(a[i]>max)
		{max=a[i];
			maxindex=i;

		}

	}
	return maxindex;

}
struct node* buildTree(int *inorders,int l,int r)
{if(l>r)
	return NULL;
	int i=max(inorders,l,r);
	struct node* root=newNode(inorders[i]);
	root->left=buildTree(inorders,l,i-1);
	root->right=buildTree(inorders,i+1,r);
	return root;

}
struct node* constructTreeutil(int *pre,char* preLN,int *len,int n)
{if(*len>=n)
	return NULL;
	struct node* root=newNode(pre[*len]);
	if(preLN[(*len)++]=='N')
		{
			root->left=constructTreeutil(pre,preLN,len,n);
		root->right=constructTreeutil(pre,preLN,len,n);
	}
	return root;


}
struct node* constructTree(int *pre,char* preln,int n)
{int len=0;
struct node* root=constructTreeutil(pre,preln,&len,n);

}
int search(int* a,int l,int r,int data)
{for(int i=l;i<=r;i++)
	{if(a[i]==data)
		return i;

	}

}

struct node* constructTreeutil(int *pre,int *post,int *index,int l,int r,int n)
{if(l>r)
	return NULL;
	if(*index>=n)
		return NULL;
	
	struct node* root=newNode(pre[(*index)++]);
	int i=search(post,l,r,pre[*index]);
	root->left=constructTreeutil(pre,post,index,l,i,n);
	root->right=constructTreeutil(pre,post,index,i+1,r,n);
	return root;



}
struct node* constructTree(int *pre,int* post,int n)
{int index=0;
	int l=0;int r=n-1;
	struct node* root=constructTreeutil(pre,post,&index,l,r,n);
return root;
}
void insert(struct node** root,int i,queue<struct node*>& q)
{if(q.empty())
	{*root=newNode(i);
		q.push(*root);
		return;

	}
	struct node* temp=q.front();
	if(temp->left==NULL)
	{temp->left=newNode(i);
		q.push(temp->left);

	}
	else if(temp->right==NULL)
	{temp->right=newNode(i);
		q.push(temp->right);


	}
	else{
		q.pop();
		insert(root,i,q);
	}

}
bool isIsomorphic(struct node*a,struct node* b)
{if(a==NULL&&b==NULL)
	return true;
	if(a==NULL||b==NULL)
		return false;
	if(a->data!=b->data)
		return false;
	return(isIsomorphic(a->left,b->left)&&isIsomorphic(a->right,b->right)||isIsomorphic(a->right,b->left)&&isIsomorphic(a->left,b->right));

}
void test(struct node* root,int data)
{queue<struct node*>q;struct node* temp;struct node* mark=NULL;
	if(root==NULL)
		return;
	q.push(root);
	q.push(mark);
	while(!q.empty())
	{temp=q.front();q.pop();
		if(temp==mark)
		{if(!q.empty())
			{q.push(mark);

			}
		}else{
			 if(temp->data==data)
			{if(q.front()==mark)
				cout<<-1<<" ";
				else cout<<q.front()->data<<" ";
				return;


			}
			
				if(temp->left)
					q.push(temp->left);
				if(temp->right)
					q.push(temp->right);
		
}
		}

	

}
void treePathsSumutil(struct node* root,int ans,int *sum)
{if(root==NULL)
	return;
	ans=ans*10+root->data;
	if(isleaf(root))
	{*sum+=ans;

	}
	treePathsSumutil(root->left,ans,sum);
	treePathsSumutil(root->right,ans,sum);

}
int treePathsSum(struct node* root)
{if(root==NULL)
	return 0;
	int sum=0;
	int ans=0;
	treePathsSumutil(root,ans,	&sum);
	return sum;


}
void convert(struct node* root)
{if(root==NULL)
	return;
	struct node* temp;struct node* mark=NULL;struct node* first=NULL;
	queue<struct node*>q;
	
	q.push(mark);
	first=root;
	if(root->left)
		q.push(root->left);
	if(root->right)
		q.push(root->right);
	root->right=NULL;
	//q.push(mark);
	while(!q.empty())
	{temp=q.front();
		q.pop();
		if(temp==mark)
		{if(!q.empty())
			{first->left=q.front();
				q.push(mark);
				first=q.front();

			}
			else first->left=NULL;

		}
		else{
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
			temp->right=q.front();




		}

	}


}
void downRightTraversal(struct node* root)
{if(root==NULL)return;
cout<<root->data<<" ";
	struct node* temp=root->right;
	while(temp)
	{cout<<temp->data<<" ";
temp=temp->right;

	}
	downRightTraversal(root->left);


}
void btreetodllutil(struct node* root)
{if(root==NULL)
	return ;
	btreetodllutil(root->left);
	btreetodllutil(root->right);
	if(root->left)
	{	struct node* left=root->left;
	while(left->right!=NULL)
		left=left->right;
	left->right=root;
	root->left=left;
}
if(root->right)
{struct node* right=root->right;
	while(right->left!=NULL)
		right=right->left;
	right->left=root;
	root->right=right;

}


}
struct node* btreetodll(struct node* root)
{btreetodllutil(root);
	while(root->left!=NULL)
	{root=root->left;

	}
	return root;

}
void dlltraversal(struct node* root)
{while(root!=NULL)
	{cout<<root->data<<" ";
	root=root->right;

	}
	cout<<endl;

}
void fillprenadsuccutil(struct node* root)
{static struct node* succ=NULL;
	if(root==NULL)
	return;
	
	fillprenadsuccutil(root->right);
	root->right=succ;
	succ=root;
	fillprenadsuccutil(root->left);

}
struct node*fillprenadsucc(struct node* root)
{struct node* r=root;
	while(r->left!=NULL)
		r=r->left;
	//return r;
	fillprenadsuccutil(root);
	//return root;
	
	struct node* prev=NULL;
	struct node* curr=r;struct node* next;
	while(curr)
	{next=curr->right;
		curr->left=prev;
		prev=curr;
		curr=next;

	}
return r;
}void traversal(struct node* root)
{while(root!=NULL)
	{cout<<root->data<<" ";
	root=root->right;
	}
cout<<endl;
}
bool allleavesatsamelevelutil(struct node* root,int& ans,int height)
{if(root==NULL)
	return true;
	if(isleaf(root))
	{if(ans==0)
		{ans=height;

		}
		else if(height>ans)
			return false;

	}
	return (allleavesatsamelevelutil(root->left,ans,height+1) && allleavesatsamelevelutil(root->right,ans,height+1));


}
bool allleavesatsamelevel(struct node* root)
{int level=0;
	return allleavesatsamelevelutil(root,level,1);

}
void printleftview(struct node* root,int height,int *maxheight)
{if(root==NULL)
	return;
	if(height>*maxheight)
	{cout<<root->data<<" ";
	*maxheight=height;


	}
	printleftview(root->left,height+1,maxheight);
	printleftview(root->right,height+1,maxheight);
	

}
int lca(struct node* root,int a,int b)
{if(root==NULL)
	return -1;
	if(root->data==a||root->data==b)
		return root->data;
int l=lca(root->left,a,b);
int r=lca(root->right,a,b);
if(l!=-1&&r!=-1)
	return root->data;
else if(l!=-1)
	return l;
return r;


}
void distkfromleafutil(struct node* root,int level,bool* visited,int k,int* path)
{if(root==NULL)
	return;
	path[level]=root->data;
	visited[level]=false;
	if(isleaf(root))
	{if((level-k)>=0&&visited[level-k]==false)
		{cout<<path[level-k]<<" ";
		visited[level-k]=true;}

	}
	distkfromleafutil(root->left,level+1,visited,k,path);
	distkfromleafutil(root->right,level+1,visited,k,path);

}
void distkfromleaf(struct node* root,int k)
{if(root==NULL)
	return;
	int level=0;
	int path[100];
	bool visited[100];
	memset(visited,100,false);
	distkfromleafutil(root,level,visited,k,path);


}
void reverseAlternateutil(struct node* root,int *a,int *len,int level)
{if(root==NULL)
	return;
	reverseAlternateutil(root->left,a,len,level+1);
	if(level&1)a[(*len)++]=root->data;
	reverseAlternateutil(root->right,a,len,level+1);

}
void reverse(int *a,int len)
{int l=0;int r=len-1;int temp;
	while(l<r)
	{temp=a[l];
		a[l]=a[r];
		a[r]=temp;
		l++;
		r--;

	}

}void reverseAlternateutil2(struct node* root,int *a,int *len,int level)
{if(root==NULL)
	return;
	reverseAlternateutil2(root->left,a,len,level+1);
	if(level&1)root->data=a[(*len)++];
	reverseAlternateutil2(root->right,a,len,level+1);


}
void reverseAlternate(struct node* root)
{int len=0;int arr[100];int level=0;
	reverseAlternateutil(root,arr,&len,level);
	
reverse(arr,len);
cout<<endl;

len=0;
reverseAlternateutil2(root,arr,&len,level);
}
bool aresiblings(struct node* root,int a,int b)
{if(root==NULL)
	return false;
	if(root->left==NULL||root->right==NULL)
		return false;
	if(root->left->data==a&&root->right->data==b||root->left->data==b&&root->right->data==a)
	return true;
	return aresiblings(root->left,a,b)||aresiblings(root->right,a,b);		

}
void firstutil(struct node* root,int *min,int *max,int level)
{if(root==NULL)
	return ;
	if(level<*min)
		{*min=level;}
	if(level>*max)
		*max=level;
	firstutil(root->left,min,max,level-1);
	firstutil(root->right,min,max,level+1);


}
void secondutil(struct node* root,list<int> *a,int level,int min)
{if(root==NULL)
	return;
	secondutil(root->left,a,level-1,min);
	a[level-min].push_back(root->data);
	secondutil(root->right,a,level+1,min);

}
void verticalorder(struct node* root)
{if(root==NULL)
	return ;
	int min=0;int max=0;
	int level=0;
	firstutil(root,&min,&max,level);
	 		
list<int> a[max-min+1];
secondutil(root,a,level,min);
for(int i=0;i<max-min+1;i++)
{cout<<"Level "<<i+1<<" : ";
	list<int>::iterator k;
	for(k=a[i].begin();k!=a[i].end();k++)
		cout<<*k<<" ";
	cout<<endl;
}
}
void serialize(struct node* root,int *a,int *len)
{if(root==NULL)
	a[(*len)++]=-1;
	else{
a[(*len)++]=root->data;
serialize(root->left,a,len);
serialize(root->right,a,len);


	}

}
struct node* deserializeutil(int *a,int *index,int n)
{if(*index>=n)
	return NULL;
	struct node*root;
	if(a[*index]==-1)
		{(*index)++;
			return NULL;
		}
		else{
			 root=newNode(a[(*index)++]);
			root->left=deserializeutil(a,index,n);
			root->right=deserializeutil(a,index,n);
		}
return root;

}
struct node* deserialize(int *a,int l)
{int index=0;
	struct node* root=deserializeutil(a,&index,l);

}
bool isCompleteBT(struct node* root)
{if(root==NULL)
	return true;
	queue<struct node*>q;struct node* temp;
	q.push(root);
	bool done=false;
	while(!q.empty())
	{temp=q.front();q.pop();

		if(temp->left)
		{if(done)
			return false;
			q.push(temp->left);

		}
		else done=1;
		if(temp->right)
		{if(done)
			return false;
			q.push(temp->right);


		}
		else done=1;

	}
	
	return true;

}struct node* removelesskutil(struct node* root,int k,int level)
{if(root==NULL)
	return NULL;
	root->left=removelesskutil(root->left,k,level+1);
	root->right=removelesskutil(root->right,k,level+1);
	if(isleaf(root)&&(level<k))
	{free(root);
		return NULL;

	}
return root;

}
struct node* prune(struct node* root,int k)
{if(root==NULL)
	return NULL;
	root->left=prune(root->left,k-root->data);
	root->right=prune(root->right,k-root->data);
	if(isleaf(root)&&root->data<k)
	{free(root);
		return NULL;


	}

return root;
}
int findrootinsubtree(struct node* root)
{if(root==NULL)
	return INT_MAX;
	if(isleaf(root))
		return 0;
	return 1+min(findrootinsubtree(root->left),findrootinsubtree(root->right));
}
bool findClosestutil(struct node* root,int k,struct node **	a,int *len)
{if(root==NULL)
	return false;

	if(root->data==k)
		{a[(*len)++]=root;
		return true;
	}
	if(findClosestutil(root->left,k,a,len)||findClosestutil(root->right,k,a,len))
	{a[(*len)++]=root;
		return true;

	}
	
	



}
int findClosest(struct node* root,int k)
{//return findrootinsubtree(root->right);
	struct node* a[100];int len=0;
	findClosestutil(root,k,a,&len);
	//for(int i=0;i<len;i++)
		//cout<<a[i]->data<<" ";
	cout<<a[0]->data;
	int min=findrootinsubtree(a[0]);

	for(int i=0;i<len-1;i++)
	{if((len-1-i+findrootinsubtree(a[i]))<min)
		min=len-1-i+findrootinsubtree(a[i]);

	}
	return min;
}
struct node* findcommon(struct node* root)
{if(root==NULL)
	return NULL;
	if(root->left)
	{if(root->left->right==root)
		return root;
	}
	if(root->right)
	{if(root->right->left==root)
		return root;


	}
	struct node* g=findcommon(root->left);
	if(g)
		return g;
	return findcommon(root->right);
		


}
int count(struct node* root)
{int count=0;
	while(root)
	{count++;
		root=root->right;

	}
	return count;

}

struct node*dlltobt(struct node** temp,int n)
{if(temp==NULL)
return NULL;

if(n<=0)
return NULL;
struct node* left=dlltobt(temp,n/2);
struct node* root=*temp;
root->left=left;
*temp=(*temp)->right;
root->right=dlltobt(temp,n-n/2-1);



return root;

}
int main()
{ 
 
    // Let us create binary tree shown in above diagram
    //node *root = newNode(1);
    //root->left = newNode(2);
    //root->right = newNode(3);
    //root->right->left = newNode(4);
    //root->right->right = newNode(5);
    //root->right->left->left = newNode(6);
    //root->right->right->left = newNode(7);
    //root->right->right->right = newNode(8);
    // Let us construct a tree shown in the above figure
    /* Let us construct the following Binary Tree which
      is not a complete Binary Tree
            1
          /   \
         2     3
        / \     \
       4   5     6
    */
 
   /*         1
           /      \
         2          3
      /     \         \
    4         5        6
  /                   /
 7 
                   8 
                   */
  // Let us construct the BST shown in the above figure
    struct node *root        = newNode(1);
    root->left               = newNode(2);
    root->right              = newNode(3);
    root->left->left        = newNode(4);
    root->left->right       = newNode(5);
    root->right->left       = newNode(6);
    root->right->right       = newNode(7);
    struct node* root1=newNode(6);
    root1->left= newNode(2);
    root1->right= newNode(8);
    root1->left->left= root->right->right;
    root1->left->right= newNode(3);
    root1->right->right= newNode(10);
    root1->right->left= newNode(7);




  struct node* temp=btreetodll(root);
  
 //  struct node* temp2=btreetodll(root1);
 //  while(temp!=NULL)
 //{cout<<temp->data<<" ";
//	temp=temp->right;

  // }
  // cout<<endl;
 //  while(temp2!=NULL)
  // {cout<<temp2->data<<" ";
//	temp2=temp2->right;

  // }
//
   struct node* ans=findcommon(root1);
   if(ans)
   {cout<<ans->data;

   }
   else cout<<"NO";
   int n=count(temp);
   root=dlltobt(&temp,n);
   cout<<endl;
   inorder(root);
   cout<<endl;
   inorder(root1);
   
	return 0;
}