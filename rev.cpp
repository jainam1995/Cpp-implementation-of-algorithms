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
void serializeutil(struct node* root,int *a,int *len)
{if(root==NULL)
	{a[(*len)++]=-1;
		return;


	}
	a[(*len)++]=root->data;
	serializeutil(root->left,a,len);
	serializeutil(root->right,a,len);

}
struct node* deserializeutil(int *a,int &count,int len)
{if(count>=len)
	return NULL;
	if(a[count]==-1)
	{count++;
		return NULL;

	}
	struct node* root=newNode(a[count]);
	count++;
	root->left=deserializeutil(a,count,len);
	root->right=deserializeutil(a,count,len);
	return root;

}
void inorder(struct node* root )
{if(root==NULL)
	return ;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);

}
void serializedeserialize(struct node* root)
{int a[100];
	int len=0;
	serializeutil(root,a,&len);
	int count=0;
	struct node* temp=deserializeutil(a,count,len);
inorder(temp);
}
bool isleaf(struct node* root)
{if(root==NULL)
	return false;
	if(root->left==NULL&&root->right==NULL)
		return true;
	return false;

}
struct node* prune(struct node* root,int k)
{if(root==NULL)
	return NULL;
	root->left=prune(root->left,k-root->data);
	root->right=prune(root->right,k-root->data);
	if(isleaf(root))
	{if(k-root->data>0)
		{free(root);
			return NULL;

		}

	}
	return root;

}
int minimum(int a,int b)
{if(a<b)
	return a;
	return b;

}
int geclosestdown(struct node* root)
{if(root==NULL)
	return INT_MAX;
	if(isleaf(root))
		return 0;
	return 1+minimum(root->left->data,root->right->data);

}
bool fillancestor(struct node* root,int *a,int& len,int k)
{if(root==NULL)
	return false;
if(root->data==k)
{a[len++]=root->data;
	return true;

}
if(fillancestor(root->left,a,len,k)||fillancestor(root->right,a,len,k))
{a[len++]=root->data;
	return true;

}

}
int findClosest(struct node* root,int k)
{int a[100];
	int len=0;
	fillancestor(root,a,len,k);
	
	for(int i=0;i<len;i++)
		cout<<a[i]<<" ";
}
void calculateSpan(int *a,int n,int *b)
{stack<int> s;
	for(int i=0;i<n;i++)//{10, 4, 5, 90, 120, 80};
	{while(!s.empty())
		{if(a[i]>=a[s.top()])
			s.pop();
				else break;
		}
		if(s.empty())
		{
			b[i]=i+1;
		}
		else{
			b[i]=i-s.top();
		}
s.push(i);
	}

}
void printArray(int *a,int n)
{for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	cout<<endl;

}
int maxinincdec(int *a,int l,int r)
{if(l>r)
	return -1;
	if(l==r)
	return a[l];
if(l+1==r)
{if(a[l]>a[r])
	return a[l];
	else return a[r];

}
int mid=l+(r-l)/2;
if(mid>l&&mid<r&&a[mid]>a[mid-1]&&a[mid]>a[mid+1])
return a[mid];
if(a[mid]>a[mid-1])
	return maxinincdec(a,mid+1,r);
else return maxinincdec(a,l,mid-1);


}
int pivot(int *a,int l,int r)
{if(l>r)
	return -1;
	//if(l==r)
		//return l;
	int mid=l+(r-l)/2;
	if(mid>l&&a[mid-1]>a[mid])
		return a[mid-1];
	if(mid<r&&a[mid]>a[mid+1])
		return a[mid];
	if(a[mid]>a[l])
		return pivot(a,mid+1,r);
	else return pivot(a,l,mid-1);



}
int maxs(int a,int b)
{if(a>b)
    return a;
    return b;

}
int maxs(int a,int b,int c)
{int t=a;
    if(b>t)
        t=b;
    if(c>t)
        t=c;
    return t;

}
int diameter(struct node* root,int *h,int *max,struct node** final)
{if(root==NULL)
    {*h=0;
       

        return 0;

    }
    int ld=0;int rd=0;int lh=0;int rh=0;
    ld=diameter(root->left,&lh,max,final);
    rd=diameter(root->right,&rh,max,final);
    if(1+lh+rh>*max)
    {*final=root;*max=1+lh+rh;
//cout<<root->data<<" df "<<1+lh+rh<<"dfs";
    }
    *h=maxs(lh,rh)+1;
    return maxs(ld,rd,1+lh+rh);

}
int ceil(int *a,int l,int r,int k)
{if(l>r)
	return -1;
	if(k<=a[l])
		return a[l];
	if(k>a[r])
		return -1;
	int mid=l+(r-l)/2;
	if(a[mid]==k)
		return k;
	if(mid>l&&a[mid-1]<k&&a[mid]>=k)
		return a[mid];
	if(mid<r&&a[mid]<k&&a[mid+1]>=k)
		return a[mid+1];
	if(a[mid]<k)
		return ceil(a,mid+1,r,k);
	else return ceil(a,l,mid-1,k);




}
int floor(int *a,int l,int r,int k)
{if(l>r)
	return -1;
	if(k<a[l])
		return -1;
	if(k>=a[r])
		return a[r];
	int mid=l+(r-l)/2;
	if(a[mid]==k)
		return a[mid];
	if(mid>l&&a[mid-1]<=k&&a[mid]>k)
		return a[mid-1];
	if(mid<r&&a[mid]<=k&&a[mid+1]>k)
		return a[mid];
	if(a[mid]<k)
		return floor(a,mid+1,r,k);
	else return floor(a,l,mid-1,k);

}
int first(int *a,int l,int r,int k)
{if(l>r)
	return -1;
	if(l==r&&a[l]==k)
		return l;
	if(a[l]==k)
		return l;
	int mid=l+(r-l)/2;
	if(mid>l&&a[mid-1]<k&&a[mid]==k)
		return mid;
	if(mid<r&&a[mid]<k&&a[mid+1]==k)
		return mid+1;
	if(a[mid]<k)
		return first(a,mid+1,r,k);
	return first(a,l,mid-1,k);



}
int last(int *a,int l,int r,int k)
{if(l>r)
	return -1;
	if(a[r]==k)
		return r;
	if(l==r&&a[r]==k)
		return r;
	int mid=l+(r-l)/2;
	if(mid>l&&a[mid-1]==k&&a[mid]>k)
		return mid-1;
	if(mid<r&&a[mid]==k&&a[mid+1]>k)
		return mid;
	if(a[mid]>k)
		return last(a,l,mid-1,k);
	return last(a,mid+1,r,k);

}

void btodllutil(struct node**head,struct node**pre,struct node* root)
{if(root==NULL)
	return ;
	btodllutil(head,pre,root->left);
	if((*head)==NULL)
	{*head=root;
		*pre=root;

	}
	else{
		root->left=*pre;
		(*pre)->right=root;
		*pre=root;
	}
btodllutil(head,pre,root->right);
}
struct node* btodll(struct node* root)
{struct node* head=NULL;struct node* pre=NULL;
	btodllutil(&head,&pre,root);
	return head;

}
void printlist(struct node* head)
{while(head)
	{cout<<head->data<<" ";
	head=head->right;

	}
cout<<endl;
}
struct node* btodll2util(struct node* root)
{if(root==NULL)
	return NULL;
	root->left=btodll2util(root->left);
	if(root->left)
	{struct node* temp=root->left;
		while(temp->right!=NULL)
			temp=temp->right;
		temp->right=root;
		root->left=temp;

	}
root->right=btodll2util(root->right);
if(root->right)
{struct node* temp=root->right;
	while(temp->left)
	temp=temp->left;
temp->left=root;
root->right=temp;

}
return root;

}
struct node* btodll2(struct node* root)
{struct node* head=btodll2util(root);
while(head->left)
	head=head->left;
return head;
}
int main()
{ 
// Let us create the tree shown in above diagram
    struct node *root        = newNode(10);
    root->left        = newNode(12);
    root->right       = newNode(15);
    root->left->left  = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36); 
    inorder(root);
    struct node* head=btodll2(root);
    
    cout<<endl;
    printlist(head);
}