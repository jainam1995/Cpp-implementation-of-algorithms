#include <bits/stdc++.h>
using namespace std;
struct node{
	bool isleaf;
	struct node* a[26];
};
struct node* newNode()
{struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->isleaf=false;
	for(int i=0;i<26;i++)
		temp->a[i]=NULL;
	return temp;

}
void insert(struct node* temp,char*s)
{int level=strlen(s);
	for(int i=0;i<level;i++)
	{if(temp->a[s[i]-'a']==NULL)
		temp->a[s[i]-'a']=newNode();
		temp=temp->a[s[i]-'a'];

	}
	temp->isleaf=true;

}
bool search(struct node* temp,char*s)
{int level=strlen(s);
	for(int i=0;i<level;i++)
	{if(temp->a[s[i]-'a']==NULL)
		return false;
		temp=temp->a[s[i]-'a'];

	}
	return temp->isleaf;

}
void printallutil(struct node* temp,int k,char s[],int level)
{s[level++]='a'+k;
if(temp->isleaf)
{for(int i=0;i<level;i++)
	cout<<s[i];
	cout<<endl;

}
for(int i=0;i<26;i++)
{if(temp->a[i])
	printallutil(temp->a[i],i,s,level);

}

}
void printall(struct node* temp)
{char s[100];
	int level=0;
	for(int i=0;i<26;i++)
	{if(temp->a[i]!=NULL)
		printallutil(temp->a[i],i,s,level);

	}

}
void printprefixutil(struct node* temp,int l,int level,char*s,char*d)
{d[level++]='a'+l;
if(temp->isleaf)
{cout<<s;
	for(int i=0;i<level;i++)
		cout<<d[i];
	cout<<endl;

}
for(int i=0;i<26;i++)
{if(temp->a[i])
	printprefixutil(temp->a[i],i,level,s,d);

}

}
void printprefix(struct node* temp,char* s)
{int level=strlen(s);
	for(int i=0;i<level;i++)
	{if(temp->a[s[i]-'a']==NULL)
		return;
		temp=temp->a[s[i]-'a'];

	}
	if(temp->isleaf)
	{cout<<s<<endl;

	}
	char d[100]; level=0;
	for(int i=0;i<26;i++)
	{if(temp->a[i])
		printprefixutil(temp->a[i],i,level,s,d);

	}

}
int main()
{struct node* temp=newNode();
char s[]="jainam";
insert(temp,s);
insert(temp,"jai");
insert(temp,"h");
if(search(temp,"jai"))
cout<<"Yes\n";
else cout<<"No\n";
printprefix(temp,"jai");




}