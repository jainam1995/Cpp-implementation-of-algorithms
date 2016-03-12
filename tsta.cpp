#include <bits/stdc++.h>
using namespace std;
struct node{
char data;
struct node* left;
struct node* middle;struct node* right;
bool isleaf;


};
struct node* newNode(char data)
{struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->isleaf=NULL;
	temp->left=temp->middle=temp->right=NULL;

};
struct node* insert(struct node* temp,char* s)
{if(temp==NULL)
	{temp=newNode(s[0]);
		if(s[1]=='\0')
			{temp->isleaf=true;return temp;}
		else temp->middle=insert(temp->middle,s+1);

	}
	else if(temp->data==s[0])
	{if(s[1]=='\0')
		{temp->isleaf=true;
			
			return temp;

		}
		else temp->middle=insert(temp->middle,s+1);

	}
	else if(s[0]<temp->data)
		temp->left=insert(temp->left,s);
	else if(s[0]>temp->data)
		temp->right=insert(temp->right,s);
	return temp;

}
bool search(struct node* temp,char* s)
{if(temp==NULL)
	return false;
	if(temp->data==s[0])
	{if(s[1]=='\0')
	return temp->isleaf;

else return search(temp->middle,s+1);
	}
	else if(s[0]<temp->data)
		return search(temp->left,s);
	else return search(temp->right,s);
	


}
void printtstutil(struct node* temp,char a[],int len)
{if(temp==NULL)
	return;
	printtstutil(temp->left,a,len);
	a[len]=temp->data;
	if(temp->isleaf)
	{for(int j=0;j<=len;j++)
		cout<<a[j];
		cout<<endl;

	}
	printtstutil(temp->middle,a,len+1);
	printtstutil(temp->right,a,len);


}
void printtst(struct node* temp)
{char a[100];int len=0;
	printtstutil(temp,a,len);

}
void printprefixutil1(struct node*temp,char *s,struct node** ref)
{if(temp==NULL)
	return;
	if(temp->data==s[0])
	{if((s[1])=='\0')
		{if(*ref==NULL)
			*ref=temp;
			return;}
		else printprefixutil1(temp->middle,s+1,ref);

	}
	else if(s[0]<temp->data)
		printprefixutil1(temp->left,s,ref);
	else printprefixutil1(temp->right,s,ref);

}
void printprefixutil2(struct node* temp,char *s,char *a,int len)
{if(temp==NULL)
	return;
	printprefixutil2(temp->left,s,a,len);
	a[len]=temp->data;
	if(temp->isleaf)
	{cout<<s;
		for(int j=0;j<=len;j++)
			cout<<a[j];
		cout<<endl;

	}
	printprefixutil2(temp->middle,s,a,len+1);
	printprefixutil2(temp->right,s,a,len);

}
void printprefix(struct node* temp,char *s)
{struct node* ref=NULL;
	printprefixutil1(temp,s,&ref);
	if(ref==NULL)
		return;
	if(ref->isleaf)
		cout<<s<<"\n";
	char a[100];int len=0;
	printprefixutil2(ref->middle,s,a,len);

}

int main()
{struct node* temp=NULL;

	temp=insert(temp,"jainam");
	temp=insert(temp,"jain");
	temp=insert(temp,"jainamshah");
	temp=insert(temp,"sdgh");
	//cout<<temp->middle->middle->middle->middle->middle->data;
	if(search(temp,"jai"))
		cout<<"Yes\n";
	else cout<<"No\n";
	if(search(temp,"sdgh"))
		cout<<"Yes\n";
	else cout<<"No\n";
	printprefix(temp,"jainad");




	return 0;
}