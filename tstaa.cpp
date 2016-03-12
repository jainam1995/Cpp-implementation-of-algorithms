#include <bits/stdc++.h>
using namespace std;
struct node{
int data;
struct node* left;
struct node* middle;
struct node* right;
bool isleaf;



};
struct node* newNode(char data)
{struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	temp->middle=NULL;
	return temp;

}
struct node*  insert(struct node* temp,char* s)
{
	if(temp==NULL)
		{temp=newNode(s[0]);
			if(s[1]=='\0')
				{temp->isleaf=true;
				return temp;}
				else  temp->middle= insert(temp->middle,s+1);			
	
				}

	else if(temp->data==s[0])
	{if(s[1]=='\0')
			{temp->isleaf=true;
			return temp;}
			else 
				temp->middle=insert(temp->middle,s+1);

	}
	else if(s[0]<temp->data)
		temp->left=insert(temp->left,s);
	else temp->right=insert(temp->right,s);

return temp;

}
bool search(struct node* temp,char* s)
{if(temp==NULL)
	return false;
	if(s[0]<temp->data)
		return search(temp->left,s);
	else if(s[0]>temp->data)
		return search(temp->right,s);
	else{
		if(s[1]=='\0')
			return temp->isleaf;
		else return search(temp->middle,s+1);
	}

}
void printallutil(struct node* temp,char* s,int len)
{
	if(temp==NULL)
		return;
	printallutil(temp->left,s,len);
	s[len++]=temp->data;
	if(temp->isleaf)
	{for(int i=0;i<len;i++)
		cout<<s[i];
		cout<<endl;

	}
	printallutil(temp->middle,s,len);
	printallutil(temp->right,s,len-1);
}
void printall(struct node* temp)
{char s[100];int len=0;
	printallutil(temp,s,len);
	

}
struct node* findnode(struct node* temp,char*s)
{if(temp==NULL)
	return NULL;
	if(temp->data==s[0])
	{if(s[1]=='\0')
return temp;
else return findnode(temp->middle,s+1);
	}
	else if(s[0]<temp->data)
		return findnode(temp->left,s);
	else return findnode(temp->right,s);

}
void printprefixutil(struct node* temp,char *s,char *a,int len)
{if(temp==NULL)
	return;
	printprefixutil(temp->left,s,a,len);
	a[len++]=temp->data;
	if(temp->isleaf)
	{cout<<s;
		for(int i=0;i<len;i++)
			cout<<a[i];
		cout<<endl;

	}
	printprefixutil(temp->middle,s,a,len);
	printprefixutil(temp->right,s,a,len-1);

}
void printprefix(struct node* temp,char*s)
{struct node* start=findnode(temp,s);
	if(start==NULL)
		return ;
	if(start->isleaf)
		cout<<s<<endl;
	char a[100];int len=0;
	printprefixutil(start->middle,s,a,len);




}
int main()
{struct node* temp=NULL;
	temp=insert(temp,"jai");
		temp=insert(temp,"kushal");

	
	temp=insert(temp,"jainam");
	temp=insert(temp,"ajinkya");

	
	if(search(temp,"jainam"))
		cout<<"Yes\n";
	else cout<<"No\n";
	printprefix(temp,"jainam");







return 0;	
}