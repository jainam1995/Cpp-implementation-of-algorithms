#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
struct node{
char data;
bool isleaf;
struct node* less;
struct node* eq;
struct node* more;

};

struct node* newnode(char data)
{struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->isleaf=false;
	temp->less=NULL;
	temp->eq=NULL;
	temp->more=NULL;

}
void insert(struct node*& temp,char* data)
{
	if(temp==NULL)
	{temp=newnode(*data);
		if(*(data+1))
	insert(temp->eq,data+1);
else temp->isleaf=true;
	}
	else if(temp->data==*data){

if(*(data+1))
insert(temp->eq,data+1);
else temp->isleaf=true;


	}
else if(*data<temp->data)
insert(temp->less,data);
	else if(*data>temp->data)
		insert(temp->more,data);



}

bool search(struct node* temp,char* data)
{if(temp==NULL)
	return false;
	else if(temp->data==*data)
	{if(!*(data+1))
		return(temp->isleaf);
	else return search(temp->eq,data+1);

	}
	else if(*data<temp->data)
		return search(temp->less,data);
	else return search(temp->more,data);

}

void printtst(struct node* temp,char data[],int depth)
{if(temp==NULL)
	return;
	printtst(temp->less,data,depth);
	data[depth]=temp->data;
	if(temp->isleaf)
	{data[depth+1]='\0';
	cout<<data<<endl;

	}
	printtst(temp->eq,data,depth+1);
	printtst(temp->more,data,depth);


}



int main()
{struct node* temp=NULL;
	insert(temp,"jainam");
	insert(temp,"jainams");
		insert(temp,"ainams");

if(search(temp,"jainaasdm"))
	cout<<"found\n";
else cout<<"not found\n";
char buff[100];
printtst(temp,buff,0);
	return 0;
}