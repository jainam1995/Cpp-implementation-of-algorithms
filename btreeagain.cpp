#include <bits/stdc++.h>
using namespace std;
struct node
{int data;
struct node* left;
struct node* right;
};
struct lists{
	int data;
	struct lists* next;
};
struct lists* newnode(int data)
{struct lists* temp=(struct lists*)malloc(sizeof(struct lists));
	temp->data=data;
	temp->next=NULL;
	return temp;

}
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
void levelorder(struct node* root)
{queue<struct node*>q;struct node* temp;struct node* mark=NULL;
	if(root==NULL)
		return;
	q.push(root);
	q.push(mark);
	while(!q.empty())
	{temp=q.front();q.pop();
		if(temp==mark)
		{cout<<endl;
			if(!q.empty())
			q.push(mark);


		}
		else{cout<<temp->data<<" ";
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}

	}

}
struct node* btreetodll1util(struct node* root)
{if(root==NULL)
	return NULL;
	if(root->left)
	{struct node* left=btreetodll1util(root->left);
		while(left->right!=NULL)
			left=left->right;
		left->right=root;
		root->left=left;

	}
	if(root->right)
	{struct node* right=btreetodll1util(root->right);
		while(right->left!=NULL)
			right=right->left;
		right->left=root;
		root->right=right;


	}
	return root;


}
void printLists(struct node* root)
{while(root!=NULL)
	{cout<<root->data<<" ";
root=root->right;}

}
struct node* btreetodll1(struct node* root)
{struct node* temp=btreetodll1util(root);
	while(root->left)
		root=root->left;
	return root;

}
void btreetodll2util(struct node** head,struct node** prev,struct node* root)
{if(root==NULL)
	return;
	btreetodll2util(head,prev,root->left);
	if(*prev==NULL)
	{root->left=*prev;
		*head=root;
		*prev=root;

	}
	else{
		root->left=*prev;
		(*prev)->right=root;
		*prev=root;

	}
	btreetodll2util(head,prev,root->right);

}
int count(struct lists* head)
{int c=0;
	while(head!=NULL)
	{c++;
		head=head->next;

	}
return c;
}
struct node* btreetodll2(struct node* root)
{if(root==NULL)
	return NULL;
	struct node* prev=NULL;
	struct node* head=NULL;
	btreetodll2util(&head,&prev,root);
	return head;
}
struct node* dlltobtreeutil(struct lists**head,int n)
{if(n==0)
	return NULL;
	struct node* left=dlltobtreeutil(head,n/2);
	struct node* root=newNode((*head)->data);
	root->left=left;
	*head=(*head)->next;;
	root->right=dlltobtreeutil(head,n-n/2-1);
	return root;

}
struct node* dlltobtree(struct lists** head)
{int n=count(*head);
	return dlltobtreeutil(head,n);

}
void push(struct lists** head,int data)
{struct lists*temp=newnode(data);
	temp->next=*head;
	*head=temp;

}
void morris(struct node* head)
{if(head==NULL)
	return;
	struct node* curr=head;
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
			else{
				left->right=NULL;
				
				curr=curr->right;
			}



		}

	}

}
int size(struct node* root)
{if(root==NULL)
	return 0;
	return 1+size(root->left)+size(root->right);

}
int max(int a,int b,int c)
{int max=a;
	if(b>max)
		max=b;
	if(c>max)
		max=c;
	return max;
}
int max(int a,int b)
{if(a>b)
	return a;
	return b;

}
int maxdepth(struct node* root)
{if(root==NULL)
	return 0;
	int l=maxdepth(root->left);
	int r=maxdepth(root->right);
	return 1+max(l,r);

}
int diameter(struct node* root,int *height)
{if(root==NULL)
	{*height=0;
		return 0;

	}int lh=0;int rh=0;
	int ld=diameter(root->left,&lh);
	int rd=diameter(root->right,&rh);
	*height=max(lh,rh)+1;
	return max(ld,rd,lh+rh+1);

}
void tomirror(struct node* root)
{if(root==NULL)
	return;
	
	tomirror(root->left);
	tomirror(root->right);
	struct node* temp=root->left;
	root->left=root->right;
	root->right=temp;

}
void serializeinorderutil(struct node* root,int *a,int *index)
{if(root==NULL)
	{a[(*index)++]=-1;
		return;

	}a[(*index)++]=root->data;
	serializeinorderutil(root->left,a,index);
	
	serializeinorderutil(root->right,a,index);

}
struct node* deserialize(int *a,int *i,int len)
{if(*i>=len||a[*i]==-1)
	{(*i)++;
		return NULL;
	}
	struct node* root=newNode(a[*i]);
	(*i)++;
	root->left=deserialize(a,i,len);
	root->right=deserialize(a,i,len);
	return root;

}
void reverse(int *a,int n)
{int l=0;int r=n-1;
	while(l<r)
	{int temp=a[l];
		a[l]=a[r];
		a[r]=temp;
		l++;r--;
	}

}
struct node* serializeinorder(struct node* root,int *a)
{int index=0;
	serializeinorderutil(root,a,&index);
	//reverse(a,index);
	int i=0;
	return deserialize(a,&i,index);


}
struct node* deserializelevelorder(int *a,int i,int index)
{if(a[i]==-1||i>=index)
	return NULL;
	struct node* root=newNode(a[i]);
	root->left=deserializelevelorder(a,2*i+1,index);
	root->right=deserializelevelorder(a,2*i+2,index);
	return root;

}
struct node* serializelevelorder(struct node* root,int *a)
{queue<struct node* >q;struct node* temp;int index=0;
	a[index++]=root->data;
	q.push(root);
	while(!q.empty())
	{temp=q.front();q.pop();

if(temp->left==NULL)
	a[index++]=-1;
else{
	a[index++]=temp->left->data;
	q.push(temp->left);
}
if(temp->right==NULL)
a[index++]=-1;
else{
	a[index++]=temp->right->data;
	q.push(temp->right);
}

	}int i=0;
	return deserializelevelorder(a,i,index);
	for(int i=0;i<index;i++)
		cout<<a[i]<<" ";

}
bool isleaf(struct node* root)
{if(root==NULL)
	return false;
	if(root->left==NULL&&root->right==NULL)
		return true;
	return false;

}
void pathsutil(struct node* root,int *a,int level)
{if(root==NULL)
	return;
	a[level++]=root->data;
	if(isleaf(root))
	{for(int i=0;i<level;i++)
		cout<<a[i]<<" ";
		cout<<endl;
		return; 

	}
	pathsutil(root->left,a,level);
	pathsutil(root->right,a,level);

}
void roottoleafpaths(struct node* root)
{if(root==NULL)
	return;
	int a[10];int level=0;
	pathsutil(root,a,level);


}
int abs(int a)
{if(a<0)
	return -a;
	return a;

}
bool isheightbalanced(struct node* root,int *height)
{if(root==NULL)
	{*height=0;
		return true;

	}
	int lh=0;int rh=0;
	bool l=isheightbalanced(root->left,&lh);
	bool r=isheightbalanced(root->right,&rh);
	*height=max(lh,rh)+1;
	if(!l||!r)
		return false;
else return abs(lh-rh)<=1;
}
void spirallevelorder(struct node* root)
{if(root==NULL)
	return ;
	stack<struct node* >s1;stack<struct node* >s2;struct node* temp;struct node* mark=NULL;
	s1.push(root);
	while(!s1.empty()||!s2.empty())
	{while(!s1.empty())
		{temp=s1.top();s1.pop();
			
		
			cout<<temp->data<<" ";
			if(temp->left)
				s2.push(temp->left);
			if(temp->right)
				s2.push(temp->right);
		

		}cout<<endl;
		while(!s2.empty())
		{
			temp=s2.top();s2.pop();
			cout<<temp->data<<" ";
			if(temp->right)
				s1.push(temp->right);
			if(temp->left)
				s1.push(temp->left);

		}
cout<<endl;
	}

}
bool printancestors(struct node* root,struct node* key)
{if(root==NULL)
	return false;
	if(root==key)
	{cout<<root->data<<" ";
		return true;}
		if(printancestors(root->left,key)||printancestors(root->right,key))
			cout<<root->data<<" ";
	

}
bool roottopathsumequalsanumberutil(struct node* root,int k,struct node** ref)
{if(root==NULL)
return false;
if(k-root->data<0)
return false;
if(k-root->data==0&&isleaf(root))
{*ref=root;
	return true;

}
return roottopathsumequalsanumberutil(root->left,k-root->data,ref)||roottopathsumequalsanumberutil(root->right,k-root->data,ref);

}
void roottopathsumequalsanumber(struct node* root,int k)
{struct node* ref=NULL;
	if(roottopathsumequalsanumberutil(root,k,&ref))
	printancestors(root,ref);
else cout<<"No such sum possible\n";

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
 struct node *root        = newNode(1);
    root->left               = newNode(2);
    root->right              = newNode(3);
    root->left->left        = newNode(4);
    root->left->right       = newNode(5);
    root->right->left       = newNode(6);
    root->right->right       = newNode(7);
    cout<<maxwidth(root);
	return 0;
}