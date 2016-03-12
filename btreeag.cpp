#include <bits/stdc++.h>
using namespace std;

struct node{
int data;
struct node* left;
struct node* right;
struct node* nextRight;


};
struct node* newNode(int data)
{struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	temp->nextRight=NULL;
	return temp;

}
int max(int a,int b)
{if(a>b)
	return a;
	else return b;

}
int max(int a,int b,int c)
{int maxs=a;
	if(b>maxs)
		maxs=b;
	if(c>maxs)
		maxs=c;
	return maxs;

}
int min(int a,int b)
{if(a<b)
	return a;
	return b;

}
int min(int a,int b,int c)
{int ans=a;
	if(b<ans)
		ans=b;
	if(c<ans)
		ans=c;
	return ans;


}
int depth(struct node* root)
{if(root==NULL)
	return 0;
	int l=depth(root->left);
	int r=depth(root->right);
	return 1+max(l,r);

}
int size(struct node* root)
{if(root==NULL)
	return 0;
	return 1+size(root->left)+size(root->right);

}
void preOrder(struct node* root)
{if(root==NULL)
	return;
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);

}
void inOrder(struct node* root)
{if(root==NULL)
	return;
	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);

}
void postOrder(struct node* root)
{if(root==NULL)
	return;
	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<" ";

}
struct node* deletetree(struct node* root)
{if(root==NULL)
return NULL;
root->left=deletetree(root->left);
root->right=deletetree(root->right);
free(root);
root=NULL;
return NULL;
}
void tomirror(struct node* root)
{if(root==NULL)
	return ;
	struct node* temp=root->left;
	root->left=root->right;
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
void roottoleafpathsutil(struct node* root,int *a,int count)
{if(root==NULL)
	return;
	a[count++]=root->data;
	if(isleaf(root))
	{for(int i=0;i<count;i++)
		cout<<a[i]<<" ";
		cout<<endl;
		return;


	}
	roottoleafpathsutil(root->left,a,count);
	roottoleafpathsutil(root->right,a,count);

}
void roottoleafpaths(struct node* root)
{int a[100];
	int count=0;
	roottoleafpathsutil(root,a,count);

}
void levelOrder(struct node* root)
{if(root==NULL)
	return;
	struct node* mark=NULL;
	struct node* temp;
	queue<struct node*>q;
	q.push(root);
	q.push(mark);
	while(!q.empty())
	{temp=q.front();
		q.pop();
		if(temp==mark)
		{if(!q.empty())
			q.push(mark);
			cout<<endl;

		}
		else{cout<<temp->data<<" ";
				if(temp->left)
					q.push(temp->left);
				if(temp->right)
					q.push(temp->right);
				}

	}

}
int countleafnodes(struct node* root)
{if(root==NULL)
	return 0;
	if(isleaf(root))
		return 1;
	else return (countleafnodes(root->left)+countleafnodes(root->right));

}
bool areidentical(struct node* a,struct node* b)
{if(a==NULL&&b==NULL)
	return true;
	if(a==NULL||b==NULL)
		return false;
	if(a->data!=b->data)
		return false;
	return areidentical(a->left,b->left)&&areidentical(a->right,b->right);

}
void levelOrderSpiral(struct node* root)
{if(root==NULL)
	return;
	struct node* temp;
	stack<struct node* >s1;stack<struct node*>s2;
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
bool childrensumproperty(struct node* root)
{if(root==NULL||isleaf(root))
	return true;
	int l=0;int r=0;
	if(root->left)
		l=root->left->data;
	if(root->right)
		r=root->right->data;
	if(root->data!=l+r)
		return false;
	return childrensumproperty(root->left)&&childrensumproperty(root->right);

}
void increment(struct node* root,int data)
{if(root==NULL)
	return;
	root->data+=data;
	if(root->left)
		increment(root->left,data);
	else if(root->right)
		increment(root->right,data);

}
void tochildrensumtree(struct node* root)
{if(root==NULL)
	return ;
	if(isleaf(root))
		return;
	tochildrensumtree(root->left);
	tochildrensumtree(root->right);
	int l=0;int r=0;
	if(root->left)
	{
		l=root->left->data;
		


	}
	if(root->right)
	{
		r=root->right->data;
		
	}
	int diff=l+r-root->data;
	if(diff>=0)
		root->data=l+r;
	else if(root->left)
		increment(root->left,-diff);
	else increment(root->right,-diff);



}
int diameter(struct node* root,int *height)
{if(root==NULL)
	{*height=0;
		return 0;

	}
	else{
		int l=0;int r=0;
		int ld=diameter(root->left,&l);
		int rd=diameter(root->right,&r);
		*height=1+max(l,r);
		return max(ld,rd,1	+l+r);




	}

}
int abs(int a)
{if(a>=0)
	return a;
	return -a;

}
bool isheightbalanced(struct node* root,int *height)
{if(root==NULL)
	{*height=0;
		return true;
	}
	else{
		int l=0;int r=0;
		bool isl=isheightbalanced(root->left,&l);
		bool isr=isheightbalanced(root->right,&r);
		*height=1+max(l,r);
		if((!isl)||(!isr))
			return false;
		if(abs(l-r)>1)
			return false;
		return true;





	}


}
void morriss(struct node* root)
{
	while(root)
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
				cout<<root->data<<" ";
				root=root->left;

			}
			else{
				left->right=NULL;
				
				root=root->right;
			}
		}

	}

}
bool roottoleafsum(struct node* root,int sum)
{if(root==NULL)
	return false;
	sum=sum-root->data;
	if(sum<0)
		return false;
	if(sum==0&&isleaf(root))
		return true;
	return roottoleafsum(root->left,sum)||roottoleafsum(root->right,sum);

}
void doubletree(struct node* root)
{if(root==NULL)
	return ;
	struct node* temp=root->left;
	root->left=newNode(root->data);
	root->left->left=temp;
	doubletree(root->left->left);
	doubletree(root->right);


}
int getMaxWidth(struct node* root)
{if(root==NULL)
	return 0;int count=0;
	int max=0;struct node* temp;struct node* mark=NULL;
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
bool aremirror(struct node*a,struct node*b)
{if(a==NULL&&b==NULL)
	return true;
	if(a==NULL||b==NULL)
		return false;
	return aremirror(a->left,b->right)&&aremirror(a->right,b->left);

}
bool isFoldable(struct node* root)
{if(root==NULL)return true;
	return aremirror(root->left,root->right);

}
void printKDistant(struct node* root,int k)
{if(root==NULL)
	return;
	if(k==0)
	{cout<<root->data<<" ";
	return;

	}
	printKDistant(root->left,k-1);
	printKDistant(root->right,k-1);

}
bool printAncestors(struct node* root,int k)
{if(root==NULL)
	{return false;}
	if(root->data==k)
		return true;
	if(printAncestors(root->left,k)||printAncestors(root->right,k))
	{cout<<root->data<<" ";
		return true;
	}


}bool isSumTree(struct node* root)
{if(root==NULL)
	return true;
	if(isleaf(root))
		return true;
	if(!isSumTree(root->left)||!isSumTree(root->right))
		return false;
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
	return true;


}
struct node* getnextright(struct node* root)
{if(root==NULL)
	return NULL;
	struct node* temp=root->nextRight;
	while(temp)
	{if(temp->left)
		return temp->left;
		if(temp->right)
			return temp->right;
		temp=temp->nextRight;

	}
	return NULL;

}
void connect(struct node* root)
{if(root==NULL)
	return ;
	root->nextRight=NULL;
	struct node* q=root;
	while(q)
	{struct node*p=q;
		while(p)
		{if(p->left)
			{if(p->right)
				p->left->nextRight=p->right;
				else p->left->nextRight=getnextright(p);
			}
			if(p->right)
				p->right->nextRight=getnextright(p);
			p=p->nextRight;


		}
		if(q->left)
			q=q->left;
		else if(q->right)
			q=q->right;
		else q=getnextright(q);

	}

}
void populateNextutil(struct node* root,struct node** suc)
{if(root==NULL)
	return;
	populateNextutil(root->right,suc);
	
		root->nextRight=*suc;
		*suc=root;
		populateNextutil(root->left,suc);

}
void populateNext(struct node* root)
{
	struct node *suc=NULL;
	populateNextutil(root,&suc);
}
int toSumTree(struct node* root)
{if(root==NULL)
	return 0;
	int l=toSumTree(root->left);
	int r=toSumTree(root->right);
	int old=root->data;
	root->data=l+r;
	return old+l+r;

}
bool printAncestors2(struct node* root,struct node* ans)
{if(root==NULL)
	return false;
	if(root==ans)
		{cout<<root->data<<" ";
		return true;}
	if(printAncestors2(root->left,ans)||printAncestors2(root->right,ans))
	{cout<<root->data<<" ";
return true;

	}

}
void maxSumPathutil(struct node *root,int curr,int *max,struct node**ref)
{if(root==NULL)
	return;
	curr=curr+root->data;
	if(isleaf(root))
	{if(curr>*max)
		{*max=curr;
			*ref=root;
			return;

		}

	}
	maxSumPathutil(root->left,curr,max,ref);
	maxSumPathutil(root->right,curr,max,ref);

}
int maxSumPath(struct node* root)
{int max=INT_MIN;struct node* ref=NULL;
	int curr=0;
	maxSumPathutil(root,curr,&max,&ref);
	printAncestors2(root,ref);
	return max;

}
void insert(struct node**root,int data,queue<struct node*>&q)
{if(q.empty())
	{(*root)=newNode(data);
		q.push(*root);
		return;

	}
	struct node* temp=q.front();
	if(temp->left==NULL)
		{temp->left=newNode(data);
			q.push(temp->left);}
	else if(temp->right==NULL)
		{temp->right=newNode(data);
			q.push(temp->right);}
	else{q.pop();
		insert(root,data,q);

	}

}
int morris(struct node*&root)
{int ans;
	while(root)
	{if(root->left==NULL)
		{ans=root->data;
			root=root->right;
			return ans;
		}
		else {
			struct node* left=root->left;
			while(left->right!=NULL&&left->right!=root)
				left=left->right;
			if(left->right==NULL)
			{left->right=root;
				root=root->left;

			}
			else{
				left->right=NULL;
				ans=root->data;
				root=root->right;
				return ans;

			}
		}


	}

}
void mergemorris(struct node*a,struct node* b)
{int first=morris(a);
	int second=morris(b);
	while(a||b)
	{if((b==NULL)||(a!=NULL&&b!=NULL&&first<=second))
		{cout<<first<<" ";
		first=morris(a);

		}
		else if((a==NULL)||(a!=NULL&&b!=NULL&&second<first))
		{cout<<second<<" ";
	second=morris(b);

		}

	}
if(first<second)
	cout<<first<<" "<<second;
else cout<<second<<" "<<first;
}
int main()
{


   /* Create following tree as first balanced BST
           100
          /  \
        50    300
       / \
      20  70
    */
    struct node *root1  = newNode(100);
    root1->left         = newNode(50);
    root1->right        = newNode(300);
    root1->left->left   = newNode(20);
    root1->left->right  = newNode(70);

    /* Create following tree as second balanced BST
            80
           /  \
         40   120
    */
    struct node *root2  = newNode(80);
    
mergemorris(root1,root2);
 
	return 0;
}