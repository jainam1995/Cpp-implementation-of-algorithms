#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <climits>
#include <cassert>
#include <stack>
 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
 
#define pb push_back
#define mp make_pair
#define sz size()
#define ln length()
#define forr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) forr(i,0,n)
#define all(v) v.begin(),v.end()
#define uniq(v) sort(all(v));v.erase(unique(all(v)),v.end())
#define clr(a) memset(a,0,sizeof a)
#define debug if(1)
#define debugoff if(0)
 
#define printt(x) cerr << x << " ";
#define pn() cerr << endl;
#define trace1(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
 
#define MAX 1000010
#define MOD 1000000007
#define endl '\n'

int flag = 0;

struct BstNode {
    int data;
    struct BstNode* right;
    struct BstNode *left;
};
map<struct BstNode*,bool> hash;

struct BstNode* getNewNode(int data) {
    struct BstNode* newNode = (struct BstNode*) malloc(sizeof(struct BstNode));
    newNode->data = data;
    newNode->right = newNode->left = NULL;

    return newNode;
}

struct BstNode* insert(struct BstNode *root, int data) {
    if(root == NULL) {
        root = getNewNode(data);
    }
    else if(data <= root->data) {
        root->left = insert(root->left, data);
    }
    else if(data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}


void print(struct BstNode* root) {
    if(root == NULL) {
        return;
    }

    print(root->left);
    printf("%d\n", root->data);
    print(root->right);

}

void call_below(BstNode * root , int k){

	if(root == NULL) return ;
if(k<0)
    return;

	if(k == 0&&(hash.find(root)==hash.end())){

		cout<<" ans-values " << root->data<<"\n" ;
        hash[root]=true;
		return;
	}

	call_below(root->right,k-1);
	call_below(root->left,k-1);

	return ;

}


bool get_k_dist_nodes(BstNode * root , int level , int k , int key ,int *keylevel){

	if(root == NULL) return false;

	

	if(root->data == key&&(hash.find(root)==hash.end())&&*keylevel==-1){
		*keylevel = level ;
        
		call_below(root,k) ;
        hash[root]=true;
		return true;
	}

	bool l = get_k_dist_nodes(root->left,level+1,k,key,keylevel) ;
	bool r = get_k_dist_nodes(root->right,level+1,k,key,keylevel) ;


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
int max(int a,int b)
{if(a>b)
    return a;
    return b;

}
int max(int a,int b,int c)
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
        if(*h>*max)
            *final=root;

        return 0;

    }
    int ld=0;int rd=0;int lh=0;int rh=0;
    ld=diameter(root->left,&lh,max,final);
    rd=diameter(root->right,&rh,max,final);
    if(1+lh+rh>*max)
    {*final=root;*max=1+lh+rh;

    }
    *h=max(lh,rh);
    return max(ld,rd,1+lh+rh);

}
int main()
{
   /* Constructed binary tree is 
            1
          /   \
        2      3
      /  \
    4     5
  */
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
 int h=0;int max=0;struct node* final=NULL;
  printf("Diameter of the given binary tree is %d\n", diameter(root,&h,&max,&final));
   cout<<final->data<<"sdf";
   return 0;

}