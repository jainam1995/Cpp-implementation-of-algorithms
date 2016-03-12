#include<bits/stdc++.h>
using namespace std;


struct tree
{

int data;
struct tree *left;
struct tree *right;
};


typedef struct tree node;

struct mystruct
{
    int Size;
    int Min;
    int Max;
    bool isbst;
};

typedef struct mystruct info;


info largestutil(node *root)
{
    info rootinfo;
    if(root==NULL)
    {
        rootinfo.Size=0;
        rootinfo.Min=INT_MAX;
        rootinfo.Max=INT_MIN;
        rootinfo.isbst=true;
        return rootinfo;
    }

    info leftinfo;
    info rightinfo;
    leftinfo=largestutil(root->left);
    rightinfo=largestutil(root->right);

    if(!leftinfo.isbst||!rightinfo.isbst||root->data<leftinfo.Max||root->data>rightinfo.Min)
    {
        rootinfo.Size=max(leftinfo.Size,rightinfo.Size);
        rootinfo.isbst=false;
        rootinfo.Min=INT_MAX;
        rootinfo.Max=INT_MIN;
        return rootinfo;
    }
    
    rootinfo.isbst=true;
    rootinfo.Size=leftinfo.Size+rightinfo.Size+1;

    if(root->left)
        rootinfo.Min=leftinfo.Min;
    else
        rootinfo.Min=root->data;

    if(root->right)
        rootinfo.Max=rightinfo.Max;
    else
        rootinfo.Max=root->data;

    return rootinfo;

}

int largest(node *root)
{
    info rootinfo=largestutil(root);
    return rootinfo.Size;
}





node* newNode(int num)
{
node *newnode=new node;
newnode->data=num;
newnode->left=NULL;
newnode->right=NULL;

return newnode;
}



node *Insert(node *root,int num)
{
if(root==NULL)
root=newNode(num);

else if(num<root->data)
root->left=Insert(root->left,num);

else if(num>root->data)
root->right=Insert(root->right,num);

return root;
}


int main()
{

node *root=new node;

root=NULL;

root=newNode(50);
root->left	 = newNode(10);
root->right	 = newNode(60);
root->left->left = newNode(5);
root->left->right = newNode(20);
root->right->left = newNode(55);
root->right->left->left = newNode(45);
root->right->right = newNode(70);
root->right->right->left = newNode(65);
root->right->right->right = newNode(80);

/*root=Insert(root,-1);
root=Insert(root,5);
root=Insert(root,4);*/
int ans=largest(root);
cout<<ans;
return 0;
}