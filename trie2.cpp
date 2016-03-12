#include <bits/stdc++.h>
using namespace std;
struct node{
bool isleaf;
struct node* arr[26];

};
struct node* newNode()
{struct node* temp=(struct node*)malloc(sizeof(struct node));
temp->isleaf=false;
for(int i=0;i<26;i++)
temp->arr[i]=NULL;

}
void insert(struct node* root,char*s)
{int level=strlen(s);
	for(int i=0;i<level;i++)
	{if(root->arr[s[i]-'a']==NULL)
		root->arr[s[i]-'a']=newNode();
		root=root->arr[s[i]-'a'];


	}
	root->isleaf=true;

}
bool search(struct node* root,char*s)
{if(root==NULL)
	return false;
int level=strlen(s);
	for(int i=0;i<level;i++)
	{if(root==NULL)
		return false;
		root=root->arr[s[i]-'a'];

	}
	return root->isleaf;

}
void printtrieutil(struct node* t,string s,int i)
{char ch='a'+i;
s=s+ch;

if(t->isleaf)
{cout<<s;
	cout<<"\n";

}
for(int g=0;g<26;g++)
{if(t->arr[g]!=NULL)
printtrieutil(t->arr[g],s,g);

}
s.erase(s.size()-1);
}
void printtrie(struct node* t)
{string s="";
	for(int i=0;i<26;i++)
	{if(t->arr[i]!=NULL)
		printtrieutil(t->arr[i],s,i);

	}


}
void printprefixutil(struct node* root,string s,int i,char *t)
{char ch='a'+i;s=s+ch;
if(root->isleaf)
cout<<t<<s<<"\n";
for(int g=0;g<26;g++)
{if(root->arr[g]!=NULL)
	printprefixutil(root->arr[g],s,g,t);

}s.erase(s.size()-1);

}
void printprefix(struct node* root, char* t)
{int level=strlen(t);
	for(int i=0;i<level;i++)
		{if(root->arr[t[i]-'a']==NULL)
			return;
			root=root->arr[t[i]-'a'];
		}
		if(root->isleaf)
			cout<<t<<"\n";
		string s="";
		for(int i=0;i<26;i++)
		{if(root->arr[i]!=NULL)
			printprefixutil(root->arr[i],s,i,t);

		}

}
int main()
{struct node* t=newNode();
	insert(t,"jainam");
	insert(t,"jaina");
	insert(t,"na");
	if(search(t,"jaina"))
		cout<<"Yes\n";
		else cout<<"No\n";
	printprefix(t,"naxn");

}