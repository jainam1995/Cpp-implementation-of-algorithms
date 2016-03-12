#include <bits/stdc++.h>
using namespace std;
struct node{
int data;
struct node* left;
struct node* right;


};
struct node* newNode(int data)
{
struct node* temp=(struct node*)malloc(sizeof(struct node));
temp->data=data;
temp->left=NULL;
temp->right=NULL;
return temp;

}

struct node* insert(struct node* root,int data)
{if(root==NULL)
	{
	root=newNode(data);
	return root;
	}

	if(data<=root->data)
		root->left=insert(root->left,data);
	else if(data>root->data)
		root->right=insert(root->right,data);

	return root;


}
void inorder(struct node* root)
{if(root==NULL)
	return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);



}
bool isleaf(struct node* root){
if(root==NULL)
	return false;
if(root->left==NULL&&root->right==NULL)
	return true;
return false;

}
struct node* deleteNode(struct node* root,int data)
{if(root==NULL)
	return NULL;
	if(data<root->data)
		root->left=deleteNode(root->left,data);
	else if(data>root->data)
		root->right=deleteNode(root->right,data);
	else if(data==root->data){
		if(isleaf(root))
		{free(root);
			root=NULL;
			return NULL;

		}
		else if(root->left==NULL)
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
		else{
			struct node* right=root->right;
			while(right->left!=NULL)
				right=right->left;
			int temp=right->data;
			right->data=root->data;
			root->data=temp;
			root->right=deleteNode(root->right,right->data);


		}





	}

return root;

}
int minValue(struct node* root)
{while(root->left)
	{root=root->left;

	}
	return root->data;

}
void findPreSuc(struct node* root,struct node*& pre,struct node*& suc,int key)
{if(root==NULL)
	return;
	if(root->data<key)
	{pre=root;
		findPreSuc(root->right,pre,suc,key);

	}
else if(root->data>key)
{suc=root;
	findPreSuc(root->left,pre,suc,key);

}	
else if(root->data==key)
{findPreSuc(root->right,pre,suc,key);
	findPreSuc(root->left,pre,suc,key);

}

}
bool isBSTUtil(struct node* root,int min,int max)
{if(root==NULL)
	return true;
if(root->data>max||root->data<min)
	return min;
return(isBSTUtil(root->left,min,root->data)&&isBSTUtil(root->right,root->data,max));

}
bool isBST(struct node* root)
{int min=INT_MIN;
	int max=INT_MAX;
	return isBSTUtil( root,min,max);

}
struct node* lca(struct node* root,int a,int b)
{if(root==NULL)
	return NULL;
	if(root->data==a||root->data==b)
		return root;
	else if(root->data>=a&&root->data<=b)
		return root;
	else if(b<root->data)
		return lca(root->left,a,b);
	else return lca(root->right,a,b);

}
struct node* inordersuccutil(struct node* root,int data,struct node*& succ,struct node*& ans)
{if(root==NULL)
	return NULL;
	inordersuccutil(root->left,data,succ,ans);
	if(succ==NULL)
	{succ=root;

	}
	else if(succ->data==data)
		ans=root;
	succ=root;
	inordersuccutil(root->right,data,succ,ans);


}
struct node* inOrderSuccessor(struct node* root,struct node* temp)
{
	struct node* succ=NULL;struct node* ans=NULL;
	 inordersuccutil(root,temp->data,succ,ans);
	 return ans;
}
void findkthsmallest(struct node* root,int *level,int k,struct node**ref)
{if(root==NULL)
	return;
	findkthsmallest(root->left,level,k,ref);
	if((*level)==k)
	{*ref=root;
		(*level)++;

	}
	else 
		{(*level)=(*level)+1;
			findkthsmallest(root->right,level,k,ref);

}
}
int k_smallest_element_inorder(struct node* root,int k)
{int level=1;struct node* ref=NULL;
	 findkthsmallest(root,&level,k,&ref);
	 return ref->data;

}
struct specialnode{
int data;
struct specialnode* left;
struct specialnode* right;
int k;


};
struct specialnode* newNode2(int data)
{struct specialnode* temp=(struct specialnode*)malloc(sizeof(struct specialnode));
	temp->left=NULL;
	temp->right=NULL;
	temp->data=data;
	temp->k=1;
	return temp;

}
struct specialnode* insert2(struct specialnode* root,int data)
{if(root==NULL)
	{root=newNode2(data);
		

	}
	else if(data<root->data)
	{root->k++;
		root->left=insert2(root->left,data);

	}
	else if(data>root->data)
	{root->right=insert2(root->right,data);

	}
return root;
} 
int k_smallest_element_inorder2(struct specialnode* root,int k)
{if(root==NULL)
	return -1;
	if(k==root->k)
	return root->data;
	else if(k<root->k)
		return k_smallest_element_inorder2(root->left,k);
	else if(root->k<k)return k_smallest_element_inorder2(root->right,k-root->k);


}
void inorder2(struct specialnode* root)
{if(root==NULL)
	return ;
	inorder2(root->left);
	cout<<root->k<<" ";
	inorder2(root->right);

}
void Print(struct node* root,int a,int b)
{if(root==NULL)
	return ;
	if(root->data>a)
		Print(root->left,a,b);
	if(root->data<b)
		Print(root->right,a,b);
	if(root->data>a&&root->data<b)
		cout<<root->data<<" ";


}
void preorder(struct node* root)
{if(root==NULL)
	return ;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);



}
struct node* sortedArrayToBST(int *a,int l,int r)
{if(l>r)
	return NULL;
	if(l==r)
		return newNode(a[l]);
	int mid=l+(r-l)/2;
	struct node* root=newNode(a[mid]);
	root->left=sortedArrayToBST(a,l,mid-1);
	root->right=sortedArrayToBST(a,mid+1,r);

	return root;

}
void modifybstutil(struct node* root,int *sum)
{if(root==NULL)
	return ;
	modifybstutil(root->right,sum);
	*sum=*sum+root->data;
	root->data=*sum;
	modifybstutil(root->left,sum);

}
void modifyBST(struct node* root)
{int sum=0;
	modifybstutil(root,&sum);


}
struct node* removeOutsideRange(struct node* root,int a,int b)
{if(root==NULL)
	return NULL;
	root->left=removeOutsideRange(root->left,a,b);
	root->right=removeOutsideRange(root->right,a,b);
	if(root->data<a)
	{
		struct node* temp=root->right;
		free(root);root=NULL;
		return temp;
	}
	else if(root->data>b)
	{struct node* temp=root->left;
		free(root);
		root=NULL;
		return temp;

	}
return root;

}
bool hasOnlyOneChild(int *a,int n)
{int max=a[n-1];int min=a[n-1];
	for(int i=n-2;i>=0;i--)
	{if(a[i]<min)min=a[i];
		else if(a[i]>max)max=a[i];
			else return false;

	}
return true;
}
void inarr(struct node* root,int *a,int *l)
{if(root==NULL)
	return;
	inarr(root->left,a,l);
	a[(*l)++]=root->data;
	inarr(root->right,a,l);


}
bool isTripletPresent(struct node* root)
{int a[1000];int len=0;
inarr(root,a,&len);
for(int i=0;i<len;i++)
{int r=len-1;
	for(int j=i+1;j<r;)
	{if(a[i]+a[j]+a[r]==0)
		return true;
		if(a[i]+a[j]+a[r]>0)
			r--;
		else j++;
	}

}
return false;


}
void correctBST(struct node*& root)
{int a[1000];int len=0;int temp;
inarr(root,a,&len);int first=-1;int second=-1;
//cout<<endl;
//for(int i=0;i<len;i++)
//cout<<a[i]<<"s ";
//cout<<endl;
for(int i=0;i<len-1;i++)
{if(a[i]>a[i+1])
	{if(first==-1)
		first=i;
		else second=i;}
	}
		//cout<<first<<endl<<second;
		if(second==-1)
		{int temp=a[first];
			a[first]=a[first+1];
			a[first+1]=temp;

		}
		else {
			temp=a[first];
			a[first]=a[second+1];
			a[second+1]=temp;




		}
		cout<<endl;
		
		 root=sortedArrayToBST(a,0,len-1);



}
struct node* constructTreeutil(int* pre,int* preindex,int min,int max,int size,int key)
{if(*preindex>=size)
	return NULL;
	struct node* root=NULL;
	if(key<=max&&key>=min)
	{root=newNode(key);
		*preindex=*preindex+1;
		if(*preindex<size)
		{root->left=constructTreeutil(pre,preindex,min,key,size,pre[*preindex]);
			root->right=constructTreeutil(pre,preindex,key,max,size,pre[*preindex]);

		}

	}
return root;	

}
struct node* constructTree(int* pre,int n)
{int key=pre[0];
	int min=INT_MIN;int max=INT_MAX;int size=n;int preindex=0;
	return constructTreeutil(pre,&preindex,min,max,size,key);
}
int Ceil(struct node* root,int data)
{if(root==NULL)
	return -1;
	if(root->data==data)
		return root->data;
	if(root->data<data)
		return Ceil(root->right,data);
	if(root->data>data)
	{int ans=Ceil(root->left,data);
		if(ans==-1)
			return root->data;
		else if(ans<root->data)
			return ans;
		else return root->data;

	}

}
struct nodel{
int data;
struct nodel* next;

};
struct nodel* newNode3(int data)
{struct nodel* temp=(struct nodel*)malloc(sizeof(struct nodel));
	temp->data=data;
	temp->next=NULL;
return temp;
}
void push(struct nodel**root,int data)
{if(*root==NULL)
	{*root=newNode3(data);
		return;}

	struct nodel* temp=newNode3(data);
	temp->next=*root;
	*root=temp;

}
void printList(struct nodel* root)
{while(root!=NULL)
	{cout<<root->data<<" ";
	root=root->next;

	}

}
int countnode(struct nodel* root)
{int count=0;
	while(root!=NULL)
	{root=root->next;
		count++;

	}
return count;
}
struct node* sortedListToBSTutil(struct nodel*& head,int n)
{if(n<=0)
	return NULL;
	
	struct node* left=sortedListToBSTutil(head,n/2);
	struct node* root=newNode(head->data);
	head=head->next;
	root->left=left;
	root->right=sortedListToBSTutil(head,n-n/2-1);

	return root;



}
struct node* sortedListToBST(struct nodel* head)
{int n=countnode(head);
	//cout<<n<<"Sdf";
	return sortedListToBSTutil(head,n);


}
int morristraversal(struct node*& curr)
{int retval=-1;
	int ans=retval;
	//struct node* curr=root;
	while(curr)
	{if(curr->left==NULL)
		{ans=curr->data;
			curr=curr->right;
			break;

		}
		else{
				struct node* left=curr->left;
				while(left->right!=NULL&&left->right!=curr)
					left=left->right;
				if(left->right==curr)
				{ans=curr->data;
					left->right=NULL;
					curr=curr->right;
					break;

				}
				else if(left->right==NULL)
				{left->right=curr;
					curr=curr->left;

				}
				


		}

	}
	return ans;

}
void merge(struct node* a,struct node* b)
{int first=morristraversal(a);
	//cout<<first;
	int second=morristraversal(b);
	while(first!=-1&&second!=-1)
	{if(first<second)
		{cout<<first<<" ";
			first=morristraversal(a);}
			else if(second<first)
			{cout<<second<<" ";
				second=morristraversal(b);
				}
				else if(first==second)
				{cout<<first<<" ";
					first=morristraversal(a);
					second=morristraversal(b);


				}

			


	}
	if(first==-1&&second!=-1)
		cout<<second<<" ";
	if(second==-1&&first!=-1)
		cout<<first<<" ";
while(true)
{//cout<<"asd";
	first=morristraversal(a);
	if(first!=-1)
	cout<<first<<" ";
else break;

}
while(true)
{//cout<<"sad";
	second=morristraversal(b);
	if(second!=-1)
	cout<<second<<" ";
else break;

}





}
int main()
{
    struct node  *root1 = NULL, *root2 = NULL;
 
    /* Let us create the following tree as first tree
            3
          /  \
         1    5
     */
    root1 = newNode(3);
    root1->left = newNode(1);
    root1->right = newNode(5);
 
    /* Let us create the following tree as second tree
            4
          /  \
         2    6
     */
    root2 = newNode(45);
    root2->left = newNode(23);
    root2->right = newNode(644);
 
    // Print sorted nodes of both trees
    merge(root2, root1);
	return 0;
}