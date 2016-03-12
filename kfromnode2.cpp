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
void countdown(struct node* root,int *ans,int k)
{if(root==NULL)
	return;
	if(k<0)
		return;
	if(k==0)
		{*ans=*ans+root->data;
			return;}
			countdown(root->left,ans,k-1);
			countdown(root->right,ans,k-1);


}
bool kthnodeutil(struct node* root,int *keylevel,int key,int level,int k,int *ans)
{if(root==NULL)
	return false;
	if(root->data==key)
	{*keylevel=level;
		countdown(root,ans,k);
		return true;

	}
	bool l=kthnodeutil(root->left,keylevel,key,level+1,k,ans);
	bool r=kthnodeutil(root->right,keylevel,key,level+1,k,ans);
	if(l&&!r)
	{countdown(root->right,ans,k-(*keylevel-level+1));
		return true;

	}
	if(!l&&r)
	{countdown(root->left,ans,k-(*keylevel-level+1));
		return true;

	}
return false;
}
struct node* insert(struct node* root,int data)
{if(root==NULL)
	return newNode(data);
	else if(data<=root->data)
		{root->left=insert(root->left,data);}
	else root->right=insert(root->right,data);
return root;
}
int maxfunc(int a ,int b)
{if(a>=b)
	return a;
return b;

}
int maxleafsumutil(struct node* root,int *max)
{if(root==NULL)
	return 0;
	int l=maxleafsumutil(root->left,max);
	int r=maxleafsumutil(root->right,max);
	if(l+r+root->data>*max)
		*max=l+r+root->data;
	return maxfunc(l,r)+root->data;

}
int maxleafsum(struct node* root)
{int max=0;

maxleafsumutil( root, &max);
return max;
}
struct bstinbt{
	bool isbst;
	int size;
	int mins;int maxs;
};
struct bstinbt largestBST(struct node* root)
{if(root==NULL)
	{struct bstinbt final;
		final.size=0;
		final.isbst=true;
		final.mins=INT_MAX;
		final.maxs=INT_MIN;
return final;
	}
	struct bstinbt left=largestBST(root->left);
	struct bstinbt right=largestBST(root->right);
	if(!left.isbst||!right.isbst||left.maxs>root->data||right.mins<root->data)
	{struct bstinbt final;
		final.isbst=false;
		final.size=0;
		final.mins=INT_MAX;
		final.maxs=INT_MIN;

return final;
	}
struct bstinbt final;
final.isbst=true;
final.size=left.size+right.size;
if(root->left)
final.mins=left.mins;
else final.mins=root->data;
if(root->data)
	final.maxs=right.maxs;
else final.maxs=root->data;

return final;
}
bool isleaf(struct node* root)
{if(root==NULL)
	return false;
	if(root->left==NULL&&root->right==NULL)
		return true;
	return false;

}
struct node* extractleaves(struct node* root,struct node** head,struct node**res)
{if(root==NULL)
	return NULL;
	
	
	if(isleaf(root))
	{
	if((*head)==NULL)
	{*head=root;*res=*head;
		return NULL;

	}
	else{(*res)->right=root;
		root->left=*res;
		*res=root;
		return NULL;

	}
}	root->left=extractleaves(root->left,head,res);
	root->right=extractleaves(root->right,head,res);
	return root;

	return root;

}

void inorder(struct node* root)
{if(root==NULL)
	return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);

}
int main()
{     struct node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
 struct node* head=NULL;struct node* res=NULL;
  //  cout << "Nodes at distance 2 are: ";
  root=  extractleaves(root,&head,&res);
    while(head)
    {cout<<head->data<<" ";
head=head->right;

    }

    cout<<endl;
  inorder(root);
    return 0;
}