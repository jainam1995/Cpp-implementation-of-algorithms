#include <bits/stdc++.h>
using namespace std;
struct node{
struct node*a[26];
bool isleaf;


};
struct node* newnode()
{struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->isleaf=false;
	for(int i=0;i<26;i++)
	{temp->a[i]=NULL;

	}
	return temp;
}
struct trie{
struct node* root;

};
void insert(struct node* root,char*s)
{int level=strlen(s);
if(root==NULL)
	root=newnode();
	for(int i=0;i<level;i++)
	{if(root->a[s[i]-'a']==NULL)
		{root->a[s[i]-'a']=newnode();

		}
		root=root->a[s[i]-'a'];

	}
	root->isleaf=true;

}
bool search(struct node* root,char* s)
{
	if(root==NULL)
		return false;
	int level=strlen(s);
	for(int i=0;i<level;i++)
	{if(root->a[s[i]-'a']==NULL)
return false;
	root=root->a[s[i]-'a'];
	}
	return (root->isleaf==true);
}
void dfs(struct node* root,char ch,char* res,int len,char* pre)
{res[len++]=ch;
	if(root->isleaf)
	{cout<<pre;
		for(int i=0;i<len;i++)
			cout<<res[i];
		cout<<endl;
	}
	for(int i=0;i<26;i++)
	{if(root->a[i]!=NULL)
		dfs(root->a[i],'a'+i,res,len,pre);

	}


}
void dfsutil(struct node* root,char* pre)
{int len=0;char res[200];
	for(int i=0;i<26;i++)
	{if(root->a[i]!=NULL)
		{dfs(root->a[i],'a'+i,res,len,pre);

		}

	}

}
void prefixprint(struct node* root,char* pre)
{if(root==NULL)
	return;
	int level=strlen(pre);
	for(int i=0;i<level;i++)
	{if(root->a[pre[i]-'a']==NULL)
		return;
		root=root->a[pre[i]-'a'];

	}
	if(root->isleaf)
		cout<<pre<<endl;
	dfsutil(root, pre);


}


int main()
{
struct  trie first;
struct node* root=newnode();
first.root=root;
insert(root,"jainam");
insert(root,"jai");
insert(root,"jau");
if(search(root,"ja")==true)
cout<<"Yes\n";
else cout<<"No\n";
prefixprint(root,"a");



	return 0;
}