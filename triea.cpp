#include <bits/stdc++.h>
using namespace std;

struct trienode{
	struct trienode* arr[26];
	bool isleaf;
};
struct trienode* newNode()
{
	struct trienode* temp=(struct trienode*)malloc(sizeof(struct trienode));
	for(int i=0;i<26;i++)
		temp->arr[i]=NULL;
	temp->isleaf=false;
	return temp;
};
void insert(struct trienode* temp,char* s)
{
	int level=strlen(s);
	for(int i=0;i<level;i++)
	{if(temp->arr[s[i]-'a']==NULL)
		temp->arr[s[i]-'a']=newNode();
		temp=temp->arr[s[i]-'a'];

	}
	temp->isleaf=true;

}
bool search(struct trienode* temp,char* s)
{int level=strlen(s);
	for(int i=0;i<level;i++)
	{if(temp->arr[s[i]-'a']==NULL)
	return false;
	temp=temp->arr[s[i]-'a'];

	}
	return temp->isleaf;

}
void printtrieutil(struct trienode*temp,char a[],int len,int i)
{a[len++]=i+'a';
if(temp->isleaf)
{for(int k=0;k<len;k++)
	cout<<a[k];
	cout<<endl;

}
for(int j=0;j<26;j++)
{if(temp->arr[j])
printtrieutil(temp->arr[j],a,len,j);}

}
void printtrie(struct trienode* temp)
{char a[100];
	int len=0;
	for(int i=0;i<25;i++)
	{if(temp->arr[i]!=NULL)	
	printtrieutil(temp->arr[i],a,len,i);
}
}
void printprefixutil(struct trienode* temp,int i,int len,char a[],char* pre)
{a[len++]=i+'a';
if(temp->isleaf)
{cout<<pre;
for(int k=0;k<len;k++)
cout<<a[k];
cout<<endl;
}
for(int j=0;j<26;j++)
	{if(temp->arr[j]!=NULL)
	 printprefixutil(temp->arr[j],j,len,a,pre);}

}
void printprefix(struct trienode* temp,char* pre)
{int level=strlen(pre);
	for(int i=0;i<level;i++)
	{if(temp->arr[pre[i]-'a']==NULL)
	return;
	temp=temp->arr[pre[i]-'a'];


	}
	if(temp->isleaf)
		cout<<pre<<"\n";
	char ans[100];int len=0;
	for(int i=0;i<26;i++)
		{if(temp->arr[i]!=NULL)
		printprefixutil(temp->arr[i],i,len,ans,pre);

	}
}
int main()
{struct trienode* temp=newNode();
	insert(temp,"jainam");
	insert(temp,"jain");
	insert(temp,"jainamshah");
	insert(temp,"sdgh");
	if(search(temp,"jainam"))
		cout<<"Yes\n";
	else cout<<"No\n";
	if(search(temp,"sdgh"))
		cout<<"Yes\n";
	else cout<<"No\n";
printprefix(temp,"sdghs");


}