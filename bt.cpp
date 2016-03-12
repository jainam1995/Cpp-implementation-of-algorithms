#include <bits/stdc++.h>
using namespace std;
struct node{
int data;
struct node* left=NULL;
struct node* right=NULL;

};
struct node* newNode(int data)
{struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;temp->right=NULL;
	return temp;

}
void inorder(struct node* root)
{if(root==NULL)
	return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);

}
int size(struct node* root)
{if(root==NULL)
	return 0;
	return 1+size(root->left)+size(root->right);

}
int max(int a,int b)
{if(a>b)
	return a;
	else return b;

}
int maxdepth(struct node* root)
{if(root==NULL)
	return 0;
	return 1+max(maxdepth(root->left),maxdepth(root->right));


}
bool ismirror(struct node* a,struct node* b)
{if(a==NULL&&b==NULL)
	return true;
	if(a==NULL||b==NULL)
		return false;
	if(a->data!=b->data)
		return false;
	if(ismirror(a->left,b->right)&&ismirror(a->right,b->left))
		return true;

}
void  tomirror(struct node* root)
{if(root==NULL)
	return ;
	struct node* temp=root->left;
	rooot->left=root->right;
	root->right=temp;
	tomirror(root->left);
	tomirror(root->right);


}
bool isleaf(struct node* root)
{if(root==NULL)
	return false;
	if(root->left==NULL&&root->right==NULL)
		return true;
	return false;

}
bool ischildrensum(struct node* root)
{if(root==NULL||isleaf(root))
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
void roottoleafutil(struct node* root,int *a,int len)
{if(root==NULL)
	return false;
	a[len++]=root->data;
	if(isleaf(root))
	{for(int i=0;i<len;i++)
		cout<<a[i]<<" ";
		cout<<endl;return;

	}
	roottoleafutil(root->left,a,len);
	roottoleafutil(root->right,a,len);

}
void roottoleaf(struct node* root)
{int a[100];int len=0;
	roottoleafutil(root,a,len);


}
int max(int a,int b,int c)
{int max=a;
	if(b>max)
		max=b;
	if(c>max)
		max=c;
	return max;

}
int diameter(struct node* root,int *height)
{if(root==NULL)
	{*height=NULL;
		return 0;

	}
	int lh=0;int rh=0;
	int ld=diameter(root->left,&lh);
	int rd=diameter(root->right,&rh);
	*height=max(lh,rh)+1;
	return max(lh+rh+1,ld,rd);

}int abs(a)
{if(a<0)
	return -a;
	return a;

}
bool isheightbalanced(struct node* root,int *height)
{if(root==NULL)
	{*height=0;return true;}
int lh=0;int rh=0;
bool l=isheightbalanced(root->left,&lh);
bool r=isheightbalanced(root->right,&rh);
*height=mac(lh,rh)+1;
if(l==false||r==false)
	return false;
if(abs(lh-rh)>1)
	return false;
return true;

}
void tochildsum(struct node* root)
{if(root==NULL||isleaf(root))
	return;
	int l=0;int r=0;
	if(root->left)
		l=root->left->data;
	if(root->right)
		r=root->right->data;
	root->data=l+r;
	tochildsum(root->left);
	tochildsum(root->right);

}
void morrisinorder(struct node* root)
{while(root!=NULL)
	{if(root->left==NULL)
		{cout<<root->data<<" ";
		root=root->right;

		}
		else{
			struct node* left=root->left;
			while(left->right!=NULL&&left->right!=root)
				left=left->right;
			if(left->right==NULL)
			{left->right=root;
				root=root->left;

			}
			else{
				left->right=NULL;
				cout<<curr->data<<" ";
				curr=curr->right;
			}
		}

	}

}
void roottoleafsumutil(struct node* root,int curr,int sum,struct node** ref)
{if(root==NULL)
	return;
	curr=curr=root->data;
	if(isleaf(root)&&curr==sum)
	{*ref=root;

	}
	roottoleafsumutil(root->left,curr,sum,ref);
	roottoleafsumutil(root->right,curr,sum,ref);

}
void roottoleafsum(struct node* root,int sum)
{int curr=0;
	struct node* ref=NULL;
	roottoleafsumutil(root,curr,sum,&ref);
	cout<<ref->data;

}
void createdouble(struct node* root)
{if(root==NULL)
	return ;
	struct node* temp=root->left;
	root->left=newNode(root->data);
	root->left->left=temp;
	createdouble(root->left->left);
	createdouble(root->right);

}
bool isfoldable(struct node* root)
{if(root==NULL)
	return true;
	return ismirror(root->left,root->right);

}
void kdistfromroot(struct node* root,int k)
{if(root==NULL)
	return ;
	if(k<0)
		return ;
	if(k==0)
		cout<<root->data<<" ";
	kdistfromroot(root->left,k-1);
	kdistfromroot(root->right,k-1);

}
int levelutil(struct node* root,int data,int l)
{if(root==NULL)
	return -1;
	if(root->data==data)
		return l;
	int left=levelutil(root->left,data,l+1);
	if(left!=-1)
		return left;
	else return levelutil(root->right,data,l+1);

}
bool printancestors(struct node* root,int data)
{if(root==NULL)
	return false;
	if(root->data==data)
	{cout<<root->data;
		return true;
	}
if(printancestors(root->left)||printancestors(root->right))
	cout<<root->data<<" ";
}
struct node* lca(struct node* root,int a,int b)
{if(root==NULL)
	return NULL;
	if(root->data==a|||root->data==b)
		return root;
	struct node* left=lca(root->left,a,b);
	struct node* ritght=lca(root->right,a,b);
	if(a&&b)
		return root;
	if(left)
		return left;
	else return right;



}
bool issumtree(struct node* root)
{if(root==NULL||isleaf(root))
	return true;
	int l=0;int r=0;
	if(root->left)
	{if(isleaf(root->left))
		l=root->left->data;
		else l=2*root->left->data;

	}
	if(root->right)
	{if(isleaf(root->right))
		r=root->right->data;
		else r=2*root->right->data;

	}
	if(root->data!=l+r)
		return false;
	return issumtree(root->left)&&issumtree(root->right);

}
int  tosumtree(struct node* root,int sum)
{if(root==NULL)
	return 0;
	int l=tosumtree(root->left);
	int r=tosumtree(root->right);
	int old=root->data;
	root->data=l+r;
	return old;

}
struct nodes{
	int data;
	struct nodes* left;
	struct nodes* right;
	struct nodes*next;
};
struct node* getnextright(struct nodes* root)
{struct nodes* temp=root->next;
	while(temp!=NULL)
	{if(temp->left)
		retun temp->left;
		if(temp->right)
			return temp->right;
		temp=temp->next;

	}
return NULL;
}
void connect(struct nodes* root)
{struct nodes* p=root;
	p->next=NULL;
	while(p!=NULL)
	{struct node* q=p;
		while(q!=NULL)
		{if(q->left)
			{if(q->right)
				q->left->next-q->right;
				else q->left->next=getnextright(q);

			}
			if(q->right)
				q->right->next=getnextright(q);
			q=q->next;

		}
		if(p->left)
			p=p->left;
		else if(p->right)
			p=p->right;
		else p=getnextright(p);


	}



}
void maxroottoleafsumutil(struct node* root,int sum,int *ans)
{if(root==NULL)
	return;
	sum=sum+root->data;
	if(isleaf(root)&&sum>(*ans))
	{*ans=sum;

	}
	maxroottoleafsumutil(root->left,sum,ans);
	maxroottoleafsumutil(root->right,sum,ans);

}
void printleaves(struct node* root)
{if(root==NULL)
	return;
	if(isleaf(root))
		{cout<<root->data<<" ";
			return;}
			printleaves(root->left);
			printleaves(root->right);


}
void printleft(struct node* root)
{if(root==NULL||isleaf(root))
	return ;
	cout<<root->Data<<" ";
	if(root->left)
	{printleft(eoor->left);

	}
	else printleft(root->right);



}
void printright(struct node* root)
{if(root==NULL||isleaf(root))
	return ;
	if(root->right)
		printright(root->right);
	else printright(root->left);
	cout<<root->data<<" ";

}
void reverselevleorder(struct node* root)
{
	if(root==NULL)
		return;
	queue<struct node*>q;struct node* mark=NULL;struct node* temp;
	q.push(root);
	while(!q.empty())
	{temp=q.front();q.pop();
		if(temp==mark)
		{cout<<endl;
			if(!q.empty())
				q.push(mark);

		}
		else{
			cout<<temp->data<<" ";
			if(temp->right)
				q.push(temp->right);
			if(temp->left)
				q.push(temp->left);
		}

	}
}
void boundrytraversal(struct node* root)
{if(root==NULL)
	return ;
	cout<<root->data<<" ";
	if(isleaf(root))
		return;
	printleft(root->left);
	printleft(root);
	printright(root->right);

}
struct node* btreetodll1util(struct node*root)
{if(root==NULL)
	return NULL;struct node* left;struct node* right;
	if(root->left)
	 {left=btreetodll1(root->left);
	while(left->right!=NULL)
		left=left->right;
	left->right=rppt;
	root->left=left;
		

		}
		if(root->right)
		{right=btreetodll1util(root->right);
			while(right->left!=NULL)
				right=right->left;
			right->left=root;
			root->right=right;


		}
		return root;


}
void btreetodll1(struct node* root)
{struct node* root=btreetodll1util(root);
	while(root->left!=NULL)
		root-=root->left;
	return root;

}
void btreetodll2util(struct node* root,struct node** head,struct node** prev)
{if(root==NULL)
	return ;
	btreetodll2util(root->left,head,prev);
	if((*prev)==NULL)
	{root->left=*prev;
		*head=root;
		*prev=root;

	}
	else{
		root->left=*prev;
		(*prev)->right=root;
		*prev=root;
	}
	btreetodll2util(root->right,head,prev);

}
bool allleavessamelevel(struct node* root,int level,int ans)
{if(root==NULL)
	retutn true;
	if(isleaf(root))
	{if(ans==-1)
		{ans=level;
			return true;}
			else {if(ans!=level)
					return false;
					else return true;	}
	return  allleavessamelevel(root->left,level+1,ans)&&allleavessamelevel(root->right,level+1,ans);				


	}


}
void leftview(struct node* root)
{if(root==NULL)
	return ;
	bool isfirst=true;
	queue<struct node*>q;
	struct node* mark=NULL;
	struct node* temp;
	q.push(root);
	q.push(mark);
	while(!q.empty())
	{temp=q.front();
		q.pop();
		if(temp==mark)
		{isfirst=true;
			if(!q.empty())
				q.push(mark);


		}
		else{
			if(isfirst==true)
			{cout<<temp->data<<" ";

			}
			isfirst=false;
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}

	}

}
void getmaxwidth(struct node* root,int *min,int *max,int level)
{if(root==NULL)
	return ;
	if(level>max)
		*max=level;
	if(level<min)
		*min=level;
	getmaxwidth(root->left,min,max,level-1);
	getmaxwidth(root->right,min,max,level+1);


}
struct top{
	int data;
	bool visited;
};
void filltable(struct top a[],struct node* root,int level,int min)
{if(root==NULL)
	return;
	if(a[level-min].visited==false)
		{a[level-min].data=root->data;
			a[level-min].visited=false;}
			filltable(root->left,level-1,min);
			filltable(root->right,level+1,min);

}
void topview(struct node* root)
{if(root==NULL)
	return ;
	int min=0;int max=0;int level=0
	getmaxwidth(root,&min,&max,level);
	int maxwidth=max-min+1;
	struct top a[maxwidth];
	for(int i=0;i<maxwidth;i++)
		a[i].visited=false;
	filltable(a,root,level,min);
	for(int i=0;i<maxwidth;i++)
	{cout<<"Level "<<min+i<<" "<<a[i].data<<"\n";

	}

}
struct node* prune(struct node* root,int sum)
{if(root==NULL)
	return NULL;
	root->left=prune(root->left,sum-root->data);
	root->right=prune(root->right,sum-root->data);
	if(isleaf(root))
	{if(root->data<sum)
		{free(root);
			root=NULL;
			retur NULL;

		}

	}
	return root;
}
int getlevelutil(struct node* root,int a)
{if(root==NULL)
	return -1;
	if(root->data==a)
		return level;
	int l=getlevelutil(root->left,level+1);
	if(l!=-1)
		return l;
	else return getlevelutil(root->right,level+1);

}
int getlevel(struct node* root,int a)
{int level=0;
	return getlevelutil(root,a,level);

}
bool siblings(struct node* root,int a,int b)
{if(root==NULL||root->left==NULL||root->right==NULL)
	return false;
	if((root->left->data==a&&root->right->data==b)||(root->left->data==b&&root->right->data==a))
		return true;
	if(siblings(root->left,a,b)||siblings(root->right,a,b))
		return true;
	return false;

}
void reversealtutil1(struct node* root,int *a,int *len,int level)
{if(root==NULL)
	return;
	if(level%2!=0)
	{a[(*len)++]=root->data;

	}
	reversealtutil1(root->left,a,len,level+1);
	reversealtutil1(root->right,a,len,level+1);

}
void reverse(int* a,int l,int r)
{while(l<r)
	{int temp=a[l];
		a[l]=a[r];
		a[r]=temp;
		l++;
		r--;

	}

}
int min(int a,int b)
{if(a<b)
	return a;
	return b;

}
void reversealtutil2(struct node*root,int *a,int& len,int level)
{it(root==NULL)
	return;
	if(level%2!=0)
	{root->data=a[len++];
	}
	reversealtutil2(root->left,a,len,level+1);
	reversealtutil2(root->right,a,len,level+1);


}
int closestleafdown(struct node* root)
{if(root==NULL)
	return INT_MAX;
	if(isleaf(root))
		return 0;
	return 1+min(closestleafdown(root->left),closestleafdown(root->right))

}
bool fillarray(struct node* root,int *a,int *len)
{if(root==NULL)
	return false;
	if(root->data==k)
		{a[(*len)++]=root;return true;}
	if (fillarray(root->left,a,len)||fillarray(root->right,a,len))
		a[(*len)++]=root;

}
int closestleaf(struct node* root,int k,k)
{struct node a[100];int len=0;
	fillarray(root,a,&len,k);int min=INT_MAX;
	for(int i=0;i<len;i++)
	{if(i+closestleafdown(a[i])<min)
		min=i+closestleafdown(a[i]);

	}
return min;
}
void serialize(struct node* root,int *a,int *len)
{if(rooot==NULL)
	{a[(*len)++]=-1;
		return ;

	}
	a[(*len)++]=root->data;
	serialize(root->left);
	serialize(root->right);

}
struct node* constructtree(int *pre,char* preln,int& i,int n)
{if(i>=n)
	return NULL;
	struct node* temp=newNode(pre[i]);
	
	if(preln[i]=='N')
	{i++;
		temp->left=constructtree(pre,preln,i,n);
		temp->right=constructtree(pre,preln,i,n);

	}
return root;
}
void inorderiter(struct node* root)
{if(root==NULL)
	return;
	stack<struct node*>s;
	bool done=false;
	while(!done)
	{if(root!=NULL)
		{s.push(root);
			root=root->left

		}
		else{
			if(!s.empty())
			{struct node* temp=s.top();
				s.pop();
				cout<<temp->data;
				root=temp->right;

			}
			else done=true;
		}

	}

}
struct node* deserialize(int *a,int& i,int len)
{if(a[i]==-1||i>=len)
	return NULL;
	struct node* root=newNode(a[i++]);
	root->left=deserialize(a,i,len);
	root->right=deserialize(a,i,len);

}
void seializeansdeserialize(struct node* root)
{int a[100];int len=0;
	serialize(root,a,&len);int i=0;
	struct node* temp=deserialize(a,i,len);

}
void reversealt(struct node* root)
{int a[1000];int len=0;int level=0;
reversealtutil1(root,a,&len,level);
reverse(a,0,len-1);
len=0;
reversealtutil2(root,a,len,level);
}
bool ifcousin(struct node*rot,int a,int b )
{if(getlevel(root,a)==-1||getlevel(root,b)==-1)
	return false;
	if(getlevel(root,a)!=getlevel(root,b))
	return false;
	if(siblings(struct node* root,int a,int b))
		return false;
	return true;

}
bool allleavessamelevel(struct node* root)
{int ans=-1;
	int level=0;
	return allleavessamelevel(root,level,ans);


}

struct node* btreetodll2(struct node* root)
{struct node* head=NULL;
	struct node* prev=NULL;
btreetodll2util(struct node* root,&head,&prev);

return head;
}
int  maxroottoleafsum(struct node* root)
{int sum=0;int ans=0;
maxroottoleafsumutil(root,sum,&ans);


return ans;
}
int level(struct node* root,int data)
{int l=0;
	return levelutil(root,data,l)

}
int countleaves(struct node* root)
{if(root==NULL)
	return 0;
	if(isleaf(root))
		return 1;
	return countleaves(root->left)+countleaves(root->right);

}
int main()
{



return 0;	
}