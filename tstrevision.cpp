#include <bits/stdc++.h>
using namespace std;

struct node{
char data;
struct node*left;
struct node*eq;
struct node* right;
bool isleaf;


};
struct node* newnode(char data)
{struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;temp->eq=NULL;
	temp->right=NULL;
	temp->isleaf=false;
	return temp;

} 

void insert(char* s,struct node*& root)
{if(root==NULL)
	{root=newnode(s[0]);
//cout<<"asd";
		if(s[1])
		{
			insert(s+1,root->eq);

		}
		else {root->isleaf=true;
			return;}

	}else if(*s<root->data)
	insert(s,root->left);
	else if(*s>root->data)
		insert(s,root->right);
	else if(root->data==*s)
	{if(s+1)
		insert(s+1,root->eq);
		else {root->isleaf=true;
			return;}

	}

}
void search(char*s,struct node* temp)
{if(temp==NULL)
	{cout<<"Not Found\n";
return ;}
	if(*s<temp->data)
		search(s,temp->left);
	else if(*s>temp->data)
		search(s,temp->right);
	else if(*s==temp->data)
	{if(s[1])
		search(s+1,temp->eq);
	else if(temp->isleaf)
		cout<<"Found\n";
	else cout<<"Not Found\n";

	}


}
void printtstutil(struct node* temp,char* path,int len)
{if(temp==NULL)
	return;
	printtstutil(temp->left,path,len);
	path[len]=temp->data;
	if(temp->isleaf)
	{
		path[len+1]='\0';
		cout<<path<<"\n";
	}
	printtstutil(temp->eq,path,len+1);
	printtstutil(temp->right,path,len);

}
void printst(struct node* temp)
{char path[100];int len=0;
	printtstutil(temp,path,len);


}
void prefixprint(char* s,struct node* temp)
{
		

}
int main()
{
//struct node* root=NULL;
//insert("jasdi",root);
//insert("jais",root);

//search("jais",root);
//printst(root);
	char ch=' ';char a='s';
	string s="jainam";
	s=s+ch+a;
	cout<<s;


	return 0;
}