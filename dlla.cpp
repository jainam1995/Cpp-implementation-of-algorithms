#include <bits/stdc++.h>
using namespace std;
struct node{
int data;
struct node* left;
struct node* right;
struct node* parent;

};
struct node* newNode(int data)
{struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;temp->right=NULL;
	temp->parent=NULL;
	return temp;


}
void push(struct node** head,int data)
{if(*head==NULL)
	{*head=newNode(data);
		return;

	}
	struct node* temp=newNode(data);
	temp->right=*head;
	(*head)->left=temp;
	*head=temp;

}
void printList(struct node* head)
{while(head)
	{cout<<head->data<<" ";
	head=head->right;

	}
	cout<<endl;

}
void reverse(struct node**head)
{if((*head)==NULL)
	return;
	struct node* curr=*head;struct node* temp;
	while(curr)
	{temp=curr->left;
		curr->left=curr->right;
		curr->right=temp;
		curr=curr->left;

	}
	struct node* root=*head;
	while(root->left)
		root=root->left;
	*head=root;

}
struct  petrolPump
{int petrol;
	int dist;

};
int printTour(int *a,int n)
{int start=0;int curr=0;int sum=0;
	for(int i=1;i<n;i++)
	{if(curr>0)
		{curr=curr+a[i];

		}
		else{
			curr=a[i];start=i;
		}
		sum=sum+a[i];

	}
if(sum<0)
	return -1;
else return start;

}
int printTour2(int *a,int n)
{int start=0;int end=1;int curr=a[0];
	while(start<end||curr<0)
	{while(start<end&&curr<0)
		{curr=curr-a[start];
			start=(start+1)%n;
			if(start==0)
				return -1;

		}
		curr=curr+a[end];
		end=(end+1)%n;

	}
	return start;

}
void call_below(struct node* root , int k){

	if(root == NULL) return ;


	if(k == 0){

		cout<<" ans-values " << root->data<<"\n" ;
		return;
	}

	call_below(root->right,k-1);
	call_below(root->left,k-1);

	return ;

}


bool get_k_dist_nodes(struct node* root ,struct node* target, int level , int k  ,int *keylevel){

	if(root == NULL) return false;

	

	if(root==target){
		*keylevel = level ;
		call_below(root,k) ;
		return true;
	}

	bool l = get_k_dist_nodes(root->left,target,level+1,k,keylevel) ;
	bool r = get_k_dist_nodes(root->right,target,level+1,k,keylevel) ;
if(l||r)
{
if(k==*keylevel-level)
	cout<<root->data;
}


	if(l and !r){

		call_below(root->right,k-(*keylevel-level+1));
		return true;
	}

	else if(!l and r){
		call_below(root->left,k-(*keylevel-level+1));
		return true;
	}

	else
		return false;


}

void printkdistanceNodeb(struct node* root,struct node* target,int k)
{int keylevel=-1;int level=1;
	bool p=get_k_dist_nodes(root,target,level,k,&keylevel);
	cout<<p;

}
void inorder(struct node* root)
{if(root==NULL)
	return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right); 

}
bool isleaf(struct node*root)
{if(root==NULL)
	return false;
	if(root->left==NULL&&root->right==NULL)
		return true;
	return false;

}
struct node* RemoveHalfNodes(struct node* root)
{if(root==NULL)
	return NULL;
	root->left=RemoveHalfNodes(root->left);
	root->right=RemoveHalfNodes(root->right);
	if(isleaf(root))
		return NULL;
	
	return root;

}
struct node* removeShortPathNodes(struct node* root,int k)
{if(root==NULL)
	return NULL;
	root->left=removeShortPathNodes(root->left,k-1);
	root->right=removeShortPathNodes(root->right,k-1);
	if(isleaf(root))
	{if(k>1)
		{free(root);
		return NULL;}

	}
	return root;

}
int count(struct node* head)
{int count=0;
	while(head)
	{count++;
		head=head->right;

	}
	return count;

}
struct node* sortedListToBSTutil(struct node** head,int n)
{if(n==0)
	return NULL;
	struct node* left=sortedListToBSTutil(head,n/2);
	struct node* root=*head;
	root->left=left;
	*head=(*head)->right;
	root->right=sortedListToBSTutil(head,n-n/2-1);
	return root;

}
struct node* sortedArrayToBST(int* a,int l,int r)
{if(l>r)
	return NULL;
	int mid=l+(r-l)/2;
	struct node*root=newNode(a[mid]);
	root->left=sortedArrayToBST(a,l,mid-1);
	root->right=sortedArrayToBST(a,mid+1,r);
	return root;

}
struct node* sortedListToBST(struct node* head)
{int n=count(head);
	struct node* root=sortedListToBSTutil(&head,n);
return root;
}
int smallestSubWithSum(int *a,int n,int x)
{int min=INT_MAX;
	int start=0;int end=1;
	int sum=a[0];
	for(int i=1;i<=n;i++)
	{while(sum>x)
		{if(end-start<min)
			min=end-start;
			sum=sum-a[start];
			start++;

		}
		if(end<n)
			sum=sum+a[end];
		end++;

	}
return min;
}
void printCombinationutil(int *a,int n,int r,int *ans,int len,int start)
{if(len>r||start>n)
	return;
	if(len==r)
	{for(int i=0;i<r;i++)
		{cout<<ans[i]<<" ";}
		cout<<endl;
		return;

	}
	ans[len]=a[start];
	printCombinationutil(a,n,r,ans,len+1,start+1);
	printCombinationutil(a,n,r,ans,len,start+1);

}
void printCombination(int *a,int n,int r)
{int ans[r];int len=0;int start=0;
	printCombinationutil(a,n,r,ans,len,start);

}
int findPeak(int *a,int l,int r)
{if(l>r)
	return -1;
	if(r==l+1)
	{if(a[l]>=r)
		return a[l];
		else return a[r];

	}
	if(l==r)
		return a[l];
	int mid=l+(r-l)/2;
	if(mid<r&&mid>l&&a[mid]>=a[mid-1]&&a[mid]>=a[mid+1])
		return a[mid];
	if(a[mid-1]>=a[mid])
		return findPeak(a,l,mid-1);
	else return findPeak(a,mid+1,r);
	

	

}
int abs(int n)
{if(n>=0)
	return n;
	return -n;

}
int maxRepeating(int *a,int n,int k)
{for(int i=0;i<n;i++)
	{a[a[i]%n]+=n;

	}
	int max=0;
	for(int i=0;i<n;i++)
	{	if(a[i]/n>max)
			max=a[i]/n;}
return max;
}bool issafe(int x,int y)
{if(x>=0&&x<5&&y>=0&&y<5)
	return true;return false;

}
void dfs(int a[5][5],int x,int y,int *xrow,int *yrow,bool visited[5][5])
{visited[x][y]=true;
	for(int i=0;i<8;i++)
	{int nextx=x+xrow[i];
		int nexty=y+yrow[i];
		if(issafe(nextx,nexty)&&a[nextx][nexty]==1&&visited[nextx][nexty]==false)
		{dfs(a,nextx,nexty,xrow,yrow,visited);

		}

	}

}
int countIslands(int a[5][5])
{bool visited[5][5];
	for(int i=0;i<5;i++)
	{for(int j=0;j<5;j++)
		visited[i][j]=false;

	}
	int count=0;
	int xrow[]={1,1,1,-1,-1,-1,0,0};
	int yrow[]={1,0,-1,1,0,-1,1,-1};
	for(int i=0;i<5;i++)
	{for(int j=0;j<5;j++)
		{if(a[i][j]==1&&visited[i][j]==false)
			{dfs(a,i,j,xrow,yrow,visited);count++;}

		}

	}
return count;
}
int min(int a,int b,int c)
{int ans=a;
	if(b<ans)
		ans=b;
	if(c<ans)
		ans=c;
	return ans;

}
int max(int a,int b,int c)
{int ans=a;
	if(b>ans)
		ans=b;
	if(c>ans)
		ans=c;
return ans;
}
int maxSubarrayProduct(int *a,int n)
{int ans=-1;int start=0;int maxnow=a[0];int minnow=a[0];int premin=a[0];int premax=a[0];
	for(int i=1;i<n;i++)
	{minnow=min(a[i]*premin,a[i]*premax,a[i]);
		maxnow=max(a[i]*premin,a[i]*premax,a[i]);
		if(maxnow>ans)
		{ans=maxnow;

		}
		premin=minnow;
		premax=maxnow;
	}
return ans;
}
int linearSearch(int *a,int l,int r)
{if(l>r)
	return -1;
	int mid =l+(r-l)/2;
	if(a[mid]==mid)
		return mid;
	if(a[mid]<mid)
		return linearSearch(a,mid+1,r);
	return linearSearch(a,l,mid-1);

}
void printTwoElements(int *a,int n)
{for(int i=0;i<n;i++)
	{if(a[abs(a[i])-1]>0)
		a[abs(a[i])-1]=-a[abs(a[i])-1];
		else cout<<abs(a[i])<<"\n";



	}cout<<"Non repeating\n";
	for(int i=0;i<n;i++)
		{if(a[i]>0)
			cout<<i+1<<"\n";}


}

int findFirstMissing(int *a,int n)
{for(int i=0;i<n;i++)
	{if(a[abs(a[i])]<n&&a[abs(a[i])]>0)
		a[abs(a[i])]=-a[abs(a[i])];

	}
	for(int i=0;i<n;i++)
		{if(a[i]>0)
			return i;}
			return n;


}
void printParenthesisutil(char*ans,int len,int start,int end,int n)
{if(len==2*n)
	{for(int i=0;i<len;i++)
		cout<<ans[i];
		cout<<endl;return;
	}
if(start<n)
{ans[len]='{';
printParenthesisutil(ans,len+1,start+1,end,n);

}
if(end<n&&end<start)
{ans[len]='}';
printParenthesisutil(ans,len+1,start,end+1,n);

}
}
void printParenthesis(int n)
{char ans[100];
	int start=0;int end=0;int len=0;
	printParenthesisutil(ans,len,start,end,n);

}
void printPatternutil(char*ans,int len,char*s,int start,int n)
{if(len>2*n)
	return;
	if(start>n)
		return;
	if(start==n)
	{for(int i=0;i<len;i++)
		cout<<ans[i];
		cout<<endl;
		return;

	}
	if(len==0||ans[len-1]==' ')
		{ans[len]=s[start];printPatternutil(ans,len+1,s,start+1,n);}
	else{
		ans[len]=' ';
		printPatternutil(ans,len+1,s,start,n);
		ans[len]=s[start];
		printPatternutil(ans,len+1,s,start+1,n);
	}

}
void printPattern(char*s)
{int n=strlen(s);
	char ans[2*n];
	int len=0;int start=0;
	printPatternutil(ans,len,s,start,n);

}
bool issafe2(int x,int y)
{if(x>=0&&x<3&&y>=0&&y<3)
	return true;
	return false;
}
bool findWordsutil(char boggle[3][3],bool visited[3][3],int i,int j,char*s,int *xrow,int *yrow)
{visited[i][j]=true;
	//cout<<s[0]<<" ";
	if(s[1]=='\0')
	{
		visited[i][j]=false;
		return true;

	}
for(int k=0;k<8;k++)
{int nextx=i+xrow[k];
	int nexty=j+yrow[k];
	if(issafe2(nextx,nexty)&&boggle[nextx][nexty]==s[1]&&visited[nextx][nexty]==false)
	{//cout<<boggle[nextx][nexty]<<" ";
		if(findWordsutil(boggle,visited,nextx,nexty,s+1,xrow,yrow)==true)
		return true;

	}

}
visited[i][j]=false;
return false;

}
bool findWords(char boggle[3][3],char*s)
{bool visited[3][3];

	for(int i=0;i<3;i++)
	{for(int j=0;j<3;j++)
		visited[i][j]=false;

	}
	int xrow[]={1,1,1,-1,-1,-1,0,0};
	int yrow[]={1,-1,0,1,-1,0,1,-1};

	for(int i=0;i<3;i++)
	{for(int j=0;j<3;j++)
		{if(boggle[i][j]==s[0])
			{if(findWordsutil(boggle,visited,i,j,s,xrow,yrow)==true)
				return true;
				visited[i][j]=false;
			}

		}

	}

return false;
}
int maxi(int a,int b)
{if(a>=b)
	return a;
	return b;

}
int  maxPathSumutil(struct node* root,int *max)
{if(root==NULL)
	return 0;



int l=maxPathSumutil(root->left,max);
int r=maxPathSumutil(root->right,max);
if(root->data+l+r>*max)
*max=l+r+root->data;

return maxi(l,r)+root->data;
}
int maxPathSum(struct node* root)
{int max=0;int ans=0;
	maxPathSumutil(root,&max);
	return max;

}
int count(int *a,int size,int n)
{int ans[n+1][size];
	for(int i=0;i<size;i++)
		ans[0][i]=1;
	for(int i=1;i<=n;i++)
	{for(int j=0;j<size;j++)
		{if(a[j]>i&&j>0)
			ans[i][j]=ans[i][j-1];
			else if(a[j]>i&&j==0)
				ans[i][j]=0;
			else if(a[j]<=i)
			{ans[i][j]=0;
				if(j>0)
				ans[i][j]=ans[i][j-1];
				ans[i][j]+=ans[i-a[j]][j];

			}

		}

	}
	return ans[n][size-1];

}
bool isInterleaved(char*a,char*b,char*c)
{int n=strlen(a);
	int m=strlen(b);
	int nm=strlen(c);
	if(nm!=n+m)
		return false;
	int ans[n+1][m+1];
	for(int i=0;i<n;i++)
	{for(int j=0;j<m;j++)
		ans[i][j]=0;

	}
	for(int i=0;i<=n;i++)
	{for(int j=0;j<=m;j++)
		{if(i==0&&j==0)
			ans[i][j]=1;

		
		else if(i==0&&b[j-1]==c[j-1])
			ans[i][j]=1;
		else if(j==0&&c[i-1]==b[i-1])
			ans[i][j]=1;
		else if(a[i-1]==c[i+j-1]&&b[j-1]!=c[i+j-1])
			ans[i][j]=ans[i-1][j];
		else if(b[j-1]==c[i+j-1]&&a[i-1]!=c[i+j-1])
			ans[i][j]=ans[i][j-1];
		else if(a[i-1]==c[i+j-1]&&b[j-1]==c[i+j-1])
			ans[i][j]=ans[i-1][j]||ans[i][j-1];



	}

	}
return ans[n][m];
}
// A function to run test cases
void test(char *A, char *B, char *C)
{
    if (isInterleaved(A, B, C))
        cout << C <<" is interleaved of " << A <<" and " << B << endl;
    else
        cout << C <<" is not interleaved of " << A <<" and " << B << endl;
}
void printarray(int *a,int n)
{for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	cout<<endl;

}
 void printKMax(int *a,int n,int k)
 {int left[n];int right[n];
 	for(int i=0;i<n;i++)
 	{if(i%k==0)
 		left[i]=a[i];
 		else left[i]=maxi(left[i-1],a[i]);

 	}
 	right[n-1]=a[n-1];
 	for(int i=n-2;i>=0;i--)
 	{if((i+1)%k==0)
 		right[i]=a[i];
 		else right[i]=maxi(right[i+1],a[i]);

 	}
 	int ans[n-k+1];
 	for(int i=0;i<=n-k;i++)
 	{ans[i]=maxi(right[i],left[i+k-1]);

 	}
printarray(ans,n-k+1);
 }
 bool issafe3(int x,int y)
 {if(x>=0&&x<8&&y>=0&&y<8)
 	return true;
 	return false;

 }
 bool solveKTutil(int ans[8][8],bool visited[8][8],int* xrow,int *yrow,int x,int y,int count)
 {visited[x][y]=true;
 	ans[x][y]=count;
 	if(count==63)
 	{for(int i=0;i<8;i++)
 		{for(int j=0;j<8;j++)
 			cout<<ans[i][j]<<" ";
			cout<<endl;
 		}
 		return true;
 		

 	}
 	for(int i=0;i<8;i++)
 	{int nextx=x+xrow[i];
 		int nexty=y+yrow[i];
 		if(issafe3(nextx,nexty)&&visited[nextx][nexty]==false)
 		{if(solveKTutil(ans,visited,xrow,yrow,nextx,nexty,count+1))
 			return true;

 		}

 	}
 	visited[x][y]=false;
 	return false;


 }
 void solveKT()
 {int ans[8][8];
 	 int xrow[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    int yrow[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
    bool visited[8][8];
    for(int i=0;i<8;i++)
    {for(int j=0;j<8;j++)
    	visited[i][j]=false;

    }
    int count=0;
    solveKTutil(ans,visited,xrow,yrow,0,0,count);
 }
 bool issafe4(int x,int y)
 {if(x>=0&&x<4&&y>=0&&y<4)
 	return true;
 	return false;

 }
 bool solveMazeutil(int maze[4][4],int ans[4][4],int x,int y)
 {ans[x][y]=1;
 	if(x==3&&y==3)
 	{for(int i=0;i<4;i++)
 		{for(int j=0;j<4;j++)
 			cout<<ans[i][j]<<" ";
 			cout<<endl;
 		}
 		return true;

 	}
if(issafe4(x+1,y)&&maze[x+1][y]==1&&solveMazeutil(maze,ans,x+1,y))
return true;
 if(issafe4(x,y+1)&&maze[x][y+1]==1&&solveMazeutil(maze,ans,x,y+1))
	return true;

ans[x][y]=0;
return false;

 }
 void solveMaze(int a[4][4])
 {int ans[4][4];
 	for(int i=0;i<4;i++)
 	{for(int j=0;j<4;j++)
 		ans[i][j]=0;

 	}
 	solveMazeutil(a,ans,0,0);

 }
 bool issumutil(int a[],int len,int sum,int size,int target )
 {if(len>size)
 	return false;
 	if(sum==target)
 		return true;
 	if(len==size)
 		return false;
 	sum=sum+a[len];
 	if(issumutil(a,len+1,sum,size,target))
 		return true;
 	sum=sum-a[len];
 	if(issumutil(a,len+1,sum,size,target))
 		return true;
 	else return false;


 }
 bool issum(int *weights,int size,int target)
 {int sum=0;
 	int len=0;
 	if(issumutil(weights,len,sum,size,target))
 		return true;
 	return false;

 }
 int power(int x,int y)
 {if(y==0)
 	return 1;
 	if(y==1)
 		return x;
 	int temp=power(x,y/2);
 	if(y%2==0)
 		return temp*temp;
 	else return x*temp*temp;

 }
 void converttobinary(int n)
 {string s="";int rem;string temp;
 while(n)
 {rem=n%2;
temp='0'+rem;
s=s+temp;
n=n/2;

 }

int l=0;int r=s.size()-1;
while(l<r)
{char t=s[l];
	s[l]=s[r];
	s[r]=t;
	l++;r--;

 }
 cout<<s;
}
int getFirstSetBitPos(int n)
{int a=n;int count=0;
while(a)
{count++;
	a=a/2;

}
int i;
for( i=0;i<=count;i++)
{if(n&(1<<i))
	break;


}
return i;
}

class Graph{
private:int vertices;
			list<int>* adj;
		public:Graph(int v){
			this->vertices=v;
			adj=new list<int>[v];
		}
		void addEdge(int u,int v)
		{adj[u].push_back(v);

		}
		void dfsutil(int p,bool visited[],stack<int>& s)
		{visited[p]=true;
			list<int>::iterator i;
			for(i=adj[p].begin();i!=adj[p].end();i++)
			{int v=*i;
				if(visited[v]==false)
				{dfsutil(v,visited,s);

				}

			}
			s.push(p);

		}
		Graph transpose(int v)
		{Graph gr=Graph(v);list<int>::iterator j;
			for(int i=0;i<v;i++)
			{for(j=adj[i].begin();j!=adj[i].end();j++)
				{int g=*j;
					gr.adj[g].push_back(i);

				}

			}
			return gr;
		}
		void dfsshow(int v,bool visited[])
		{visited[v]=true;
			cout<<v<<" ";
			list<int>::iterator k;
			for(k=adj[v].begin();k!=adj[v].end();k++)
			{int d=*k;
				if(visited[d]==false)
					dfsshow(d,visited);

			}

		}
		void topologicalsort(int src)
		{stack<int >s;
			bool visited[this->vertices];
			for(int i=0;i<this->vertices;i++)
				visited[i]=false;
				dfsutil(src,visited,s);
				Graph g=transpose(this->vertices);
				for(int i=0;i<this->vertices;i++)
				visited[i]=false;
			while(!s.empty())
			{int h=s.top();
				s.pop();
				if(visited[h]==false)
				{g.dfsshow(h,visited);

				}
				cout<<endl;

			}


		}
		


};
struct node* nextright(struct node* given)
{if(given->parent==NULL)
	return given;
	int ans=0;int level;
	while(given->parent)
	{if(given->parent->right==given)
		{ans++;given=given->parent;

		}
		else{if(given->parent->left==given)
			{ ans++;level=1;int temp=ans;struct node* f=given->parent;
				if(f->right==NULL)
					{given=given->parent;continue;}
				f=f->right;
				while(true)
				{if(level==ans)
					return f;
					if(f->left)
					{f=f->left;
						level++;//cout<<"le"<<level-1;

					}
					else{
						if(f->right)
						{f=f->right;level++;

						}
						else break;
					}

				}

			}

		}

	}
return NULL;
}
// Same as "void print(int **arr, int m, int n)"
void print(int **arr, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
      for (j = 0; j < n; j++)
        printf("%d ", *(*(arr+0) + 0));
}
void countDistinct(int *a,int n,int k)
{map<int,int > hash;int count=0;
	for(int i=0;i<k;i++)
	{if(hash.find(a[i])==hash.end())
		{count++;hash[a[i]]=1;}
		else{
			if(hash[a[i]]==1)
				count--;
			int temp=hash[a[i]];
			hash[a[i]]=temp+1;
		}

	}
	cout<<count<<"\n";
	for(int i=k;i<n;i++)
	{if(hash[a[i-k]]==1)
			{count--;
				hash.erase(a[i-k]);
				
			}
			else{
				if(hash[a[i-k]]==2)
					count++;
				int temp=hash[a[i-k]];
				hash[a[i-k]]=temp-1;
			}


		if(hash.find(a[i])==hash.end())
		{count++;
			hash[a[i]]=1;

		}
		else{
			if(hash[a[i]]==1)
				count--;
		}
			int temp=hash[a[i]];
			hash[a[i]]=temp+1;

cout<<count<<"\n";
	}


}
void rearrange(int *a,int n)
{int i=0;int j=1;//i odd on even       j even on odd    
	while(i<n&&j<n)
	{while(i<n&&a[i]%2==0)
		i=i+2;
		if(i>n)
			break;
		while(j<n&&a[j]&1)
			j=j+2;
		if(j>n)
			break;
		int temp=a[i];
		a[i]=a[j];
		a[j]=temp;
		i=i+2;
		j=j+2;

	}

}
void rearrange2(int *a,int n)
{int l=0;int r=n-1;
	while(l<r)
	{while(l<r&&a[l]%2!=0)
		l++;
		while(l<r&&a[r]%2==0)
			r--;
		if(l<r)
		{int temp=a[l];
			a[l]=a[r];
			a[r]=temp;
			l++;r--;
		}

	}
	int i;
	for( i=0;i<n;i++)
		{if(a[i]%2==0)
			break;}
int odd=0;int even=i;
while(odd<even&&even<n&&a[odd]%2==1)
{int temp=a[even];
	a[even]=a[odd];
	a[odd]=temp;
	odd=odd+2;
	even++;

}


}
void printspiral(int a[4][3],int m,int n)
{int firstrow=0;int lastrow=m-1;int firstcol=0;int lastcol=n-1;int i;int j;
	while(firstrow<=lastrow&&firstcol<=lastcol)
	{for(i=firstcol;i<=lastcol;i++)
		cout<<a[firstrow][i]<<" ";
		i--;
		for(j=firstrow+1;j<=lastrow;j++)
			cout<<a[j][i]<<" ";
		j--;
		for(i=lastcol-1;i>=firstcol;i--)
			cout<<a[j][i]<<" ";
		i++;
		for(j=lastrow-1;j>firstrow;j--)
			cout<<a[j][i]<<" ";
		firstrow++;
		lastrow--;
		firstcol++;
		lastcol--;





	}

}
void countdown(struct node* root,int k,int *ans)
{if(root==NULL)
	return ;
	if(k<0)
		return ;
	if(k==0)
	{*ans=*ans+root->data;
		cout<<root->data<<" ";
		return;

	}
	countdown(root->left,k-1,ans);
	countdown(root->right,k-1,ans);

}
bool ispresent(struct node* root,struct node* target,int level,int *keylevel,int *ans,int k)
{if(root==NULL)
	return false;
	if(root==target)
	{*keylevel=level;
		countdown(root,k,ans);
		return true;

	}
	bool l=ispresent(root->left,target,level+1,keylevel,ans,k);
	bool r=ispresent(root->right,target,level+1,keylevel,ans,k);
	if((l||r)&&*keylevel-level==k)
		{*ans=*ans+root->data;cout<<root->data<<" ";return true;}
	if(l&&!r)
	{countdown(root->right,k-(*keylevel-level+1),ans);
		return true;

	}
	else if(r&&!l)
	{
		countdown(root->left,k-(*keylevel-level+1),ans);
		return true;
	}
else return false;
}
int printkdistanceNode(struct node* root,struct node* target,int k)
{int ans=0;int level=1;int keylevel=-1;
	ispresent(root,target,level,&keylevel,&ans,k);
	return ans;

}
int maxSubArraySum(int *a,int n)
{int max=a[0];
	int start=0;
	int sum=a[0];
	for(int i=1;i<n;i++)
	{if(sum<0)
		{
			sum=a[i];
			if(sum>max)
				max=sum;

		}
		else {sum=sum+a[i];
			if(sum>max)max=sum;}

	}
return max;
}
// Driver program to test above functions
bool compares(char* a,char* b)
{if(strcmp(a,b)<=0)
	return true;
	return false;

}
bool comparef(const char& a,const char& b)
{if(a<=b)
	return true;
	return false;

}
char* func()
{char *a=(char*)malloc(10);
a="sdf";
return a;	


}
int main()
{  /*struct node* root=newNode(10);root->parent=NULL;
	root->left=newNode(5);root->left->parent=root;
	root->left->left=newNode(8);root->left->left->parent=root->left;
	root->left->right=newNode(120);root->left->right->parent=root->left;
	root->right=newNode(15);root->right->parent=root;
	root->right->right=newNode(100);root->right->right->parent=root->right;
	root->right->left=newNode(18);root->right->left->parent=root->right;
	struct node* temp=nextright(root->left->right);
	if(temp)
	cout<<temp->data;
    return 0;*/
 /* Let us construct the tree shown in above diagram */
//char *s="jai";

 char*s=func();
 cout<<s;
}