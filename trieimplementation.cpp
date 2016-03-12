#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
struct trienode{
int isleaf;
struct trienode* array[26];


};
struct trie{
struct trienode* root;


};
struct trienode* getnode()
{struct trienode* temp=(struct trienode*)malloc(sizeof(struct trienode));
	for(int i=0;i<26;i++)
		temp->array[i]=NULL;
	temp->isleaf=0;

	return temp;

}
void initialize(struct trie* trie1)
{trie1->root=getnode();


}
void insert(char str[],struct trienode* root)
{int level=strlen(str);struct trienode* temp=root;
	for(int i=0;i<level;i++)
	{if(temp->array[str[i]-'a']==NULL)
{//cout<<i<<" ";
	temp->array[str[i]-'a']=getnode();
	temp=temp->array[str[i]-'a'];
}
	else temp=temp->array[str[i]-'a'];

	}
temp->isleaf=1;

}
bool search(char str[],struct trienode* root)
{int level=strlen(str);struct trienode* temp=root;		
	for(int i=0;i<level;i++)
	{if(!temp->array[str[i]-'a'])
		{//cout<<i;
			return false;}
		else temp=temp->array[str[i]-'a'];


	}
if(temp->isleaf)
return true;
return false;

}
void printtrieutil(int i,char* a,struct trienode* temp,int len)
{a[len]=i+'a';
if(temp->isleaf)
{for(int i=0;i<=len;i++)
	cout<<a[i];
	cout<<endl;

}
for(int i=0;i<26;i++)
{if(temp->array[i]!=NULL)
	printtrieutil(i,a,temp->array[i],len+1);

}
}
void printtrie(struct trienode* root)
{char a[1000];int len=0;
	struct trienode*  temp=root;
	for(int i=0;i<26;i++)
	{if(temp->array[i]!=NULL)
		printtrieutil(i,a,temp->array[i],len);

	}


}
void printprefix(char str[],struct trienode* root)
{int level=strlen(str);
	struct trienode* temp=root;
	for(int i=0;i<level;i++)
	{if(temp->array[str[i]-'a']==NULL)
		return;
		temp=temp->array[str[i]-'a'];

	}

	printtrie(temp);

}
int main()
{
struct trie trie1;
initialize(&trie1);
struct trienode* temp=trie1.root;
insert("jainam",temp);
insert("viram",temp);
insert("absd",temp);
insert("jainams",temp);
if(search("jainam",temp))
cout<<"found\n";
else cout<<"not found\n";
printtrie(temp);
cout<<"prefixprint\n";
printprefix("a",temp);
}