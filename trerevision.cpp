#include <bits/stdc++.h>
using namespace std;
struct trie{
struct trienode* root;
};
struct trienode{
int isleaf;
struct trienode* array[26]; 


};
struct trienode* newnode()
{struct trienode* temp=(struct trienode*)malloc(sizeof(struct trienode));
	temp->isleaf=0;
	for(int i=0;i<26;i++)
		temp->array[i]=NULL;
	return temp;

}
void insert(char* s,struct trienode* root)
{if(root==NULL)
	root=newnode();
	struct trienode* temp=root;
	int level=strlen(s);
	for(int i=0;i<level;i++)
	{
	if(temp->array[s[i]-'a']==NULL)
		{temp->array[s[i]-'a']=newnode();
		//cout<<"asd";
}
	temp=temp->array[s[i]-'a'];
}
temp->isleaf=1;
}

void search(char* s,struct trienode* root)
{if(root==NULL)
	{cout<<"Not Found\n";
	return;

	}
	struct trienode* temp=root;
	int level=strlen(s);
	for(int i=0;i<level;i++)
	{if(temp->array[s[i]-'a']==NULL)
	{cout<<"Not Found\n";
	return;

	}
	temp=temp->array[s[i]-'a'];
	}
	if(temp->isleaf)
		cout<<"Found\n";
	else cout<<"Not Found\n";

}
void printtrieutil(int a,struct trienode* temp,int len,char* path)
{path[len++]=a+'a';//int flag=0;

if(temp->isleaf)
	{for(int i=0;i<len;i++)
		cout<<path[i];
		cout<<endl;}
		for(int i=0;i<26;i++)
		{if(temp->array[i]!=NULL)
			printtrieutil(i,temp->array[i],len,path);

		}




}
void printtrie(struct trienode* root)
{if(root==NULL)
	return;
	struct trienode* temp=root;
	int len=0;
	char path[100];
	for(int i=0;i<26;i++)
	{if(temp->array[i]!=NULL)
	printtrieutil(i,temp->array[i],len,path);
	}



}

int main()
{
struct trie trie1;
trie1.root=newnode();
insert("example",trie1.root);

insert("examples",trie1.root);
insert("examplesd",trie1.root);

search("examplesds",trie1.root);
printtrie(trie1.root);



	return 0;
}