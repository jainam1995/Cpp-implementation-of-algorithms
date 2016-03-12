#include <bits/stdc++.h>
using namespace std;
struct node{
	char data;
	bool isleaf;
	struct node* left;
	struct node* right;
	struct node* middle;
};
struct node* newNode(char data)
{struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
temp->left=NULL;
temp->right=NULL;
temp->middle=NULL;temp->isleaf=false;
return temp;

}
struct node* insert(struct node* root,char *data)
{int level=strlen(data);
	for(int i=0;i<level;i++)
	{if(root==NULL)
		{root=newNode(data[i]);
		if(data[i+1]=='\0')
			{root->isleaf=true;
				return root;}
		else root->middle=insert(root->middle,data+1);
		}
		else if(root->data==data[i])
		{if(data[i+1]=='\0')
			{root->isleaf=true;
				return root;}
				else root->middle=insert(root->middle,data+1);


		}
		else if(data[i]<root->data)
			root->left=insert(root->left,data);
		else root->right=insert(root->right,data);
		return root;



	}

}
bool search(struct node* root,char *s)
{
	if(root==NULL)
		return false;
		if(s[0]<root->data)
			return search(root->left,s);
		else if(s[0]>root->data)
			return search(root->right,s);
		else if(s[0]==root->data){
			if(s[1]=='\0')
				return root->isleaf;
			else return search(root->middle,s+1);

		}

	

}
void printstutil(struct node* root,string s)
{if(root==NULL)
	return;
	printstutil(root->left,s);
	s=s+root->data;
	if(root->isleaf)
		cout<<s<<"\n";
	printstutil(root->middle,s);
	s.erase(s.size()-1);
	printstutil(root->right,s);


}
bool searchprefix(struct node* root,char*s,struct node** ref)
{if(root==NULL)
	return false;
	if(s[0]<root->data)
		return searchprefix(root->left,s,ref);
	else if(s[0]>root->data)
		return searchprefix(root->right,s,ref);
	else if(s[0]==root->data)
	{if(s[1]=='\0')
{*ref=root;
	return true;
}
	else return searchprefix(root->middle,s+1,ref)	;

	}

}
void printprefixutil(struct node* root,string t,char* s)
{if(root==NULL)
	return;
	printprefixutil(root->left,t,s);
	t=t+root->data;
	if(root->isleaf)
		cout<<s;
		cout<<t<<"\n";
		printprefixutil(root->middle,t,s);
		t.erase(t.size()-1);
		printprefixutil(root->right,t,s);



}
void printprefix(struct node* root,char* s)
{struct node* ref=NULL;
	bool p=searchprefix(root,s,&ref);

	if(p==false)
		return;

	if(root->isleaf)
		cout<<s<<"\n";
	string t="";
	//cout<<ref->data;
	if(ref->isleaf)
		cout<<s<<"\n";
	printprefixutil(ref->left,t,s);
	printprefixutil(ref->middle,t,s);
	printprefixutil(ref->right,t,s);
}
void printtst(struct node* root)
{string s="";
printstutil(root,s);

}
int main()
{struct node* root=NULL;
	root=insert(root,"jainam");
	root=insert(root,"jaina");
	root=insert(root,"sdf");
	root=insert(root,"jai");
	if(search(root,"sdf"))
		cout<<"Yes\n";
	else cout<<"No\n";
	printprefix(root,"j");






return 0;
}