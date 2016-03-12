#include <bits/stdc++.h>
using namespace std;
struct node{
char data;
struct node* left;
struct node* middle;
struct node* right;
bool isleaf;


};
struct node* newnode(char data)
{struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	temp->middle=NULL;
	temp->isleaf=false;
	return temp;

}
void insert(struct node*& root,char* s)
{if(root==NULL)
	{root=newnode(*s);
		if(*(s+1))
		{insert(root->middle,(s+1));

		}
		else {root->isleaf=true;return;}



	}
	else if(*s<root->data)
		insert(root->left,s);
	else if(*s>root->data)
		insert(root->right,s);
	else if(*s==root->data)
	{if(*(s+1))
		insert(root->middle,(s+1));
		else {root->isleaf=true;return;}


	}


	




}

bool search(struct node* root,char* s)
{
if(root==NULL)
	return false;
if(*s<root->data)
	search(root->left,s);
else if(*s>root->data)
	search(root->right,s);
else if(*s==root->data)
{if(*(s+1))
	search(root->middle,s+1);
	else return root->isleaf;

}
}
void printtstutil(struct node* root,string s)
{if(root==NULL)
	return;
	printtstutil(root->left,s);
	s=s+root->data;
	if(root->isleaf)
		cout<<s<<endl;
	printtstutil(root->middle,s);
	s.erase(s.size()-1,1);
	printtstutil(root->right,s);

}
void printtst(struct node* root)
{string s="";
printtstutil(root,s);




}
struct node* searchprefix(struct node* root,string s)
{if(root==NULL)
	return NULL;
	if(s[0]<root->data)
		return searchprefix(root->left,s);
	else if(s[0]>root->data)
		return searchprefix(root->right,s);
	else if(root->data==s[0])
	{if(s[1]=='\0')
		{
		
		return root;
	}
		else {int i;
			for(i=0;i<s.size()-1;i++)
				s[i]=s[i+1];
				s[i]='\0';
				
				
			return searchprefix(root->middle,s);}

	}


}
void printprefix(struct node* temp,string ans,string s)
{if(temp==NULL)
	return;
	printprefix(temp->left,ans,s);
	ans=ans+temp->data;
	if(temp->isleaf)
		cout<<s<<ans<<endl;
	printprefix(temp->middle,ans,s);
	ans.erase(ans.size()-1,1);
	printprefix(temp->right,ans,s);


}
void prefixprint(struct node* root,string s)
{struct node* temp=searchprefix(root,s);

if(temp==NULL)cout<<"Not possible\n";
else{
	string ans="";
printprefix(temp->middle,ans,s);





}

}

int main()
{
char ch[4]][4]={{},{},{},{}};

return 0;
}