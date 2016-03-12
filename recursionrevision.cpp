#include <bits/stdc++.h>
using namespace std;

void printrcombinationutil(char* str,char* res,int i,int index,int n,int r)
{	if(index==r)
	{for(int j=0;j<index;j++)
		cout<<res[j];
		cout<<endl;
		return;

	}
else{if(i>=n)
	return;
	else{

		res[index]=str[i];
		printrcombinationutil(str,res,i+1,index+1,n,r);
		while(i+1<n&&str[i+1]==str[i])i++;
		printrcombinationutil(str,res,i+1,index,n,r);



	}



}
}
void swap(char* a,char *b)
{char temp=*a;
	*a=*b;
	*b=temp;

}
void printrcombination(char* str,int r)
{
int n =strlen(str);
int index=0;
int i=0;
char res[r];
printrcombinationutil(str,res,i,index,n,r);

}
void printpermutationutil(char* str,int i,int n)
{bool visited[256];
	for(int h=0;h<256;h++)
	visited[h]=false;
	if(i==n)
	{cout<<str;
		cout<<endl;
		return;

	}
	else{
		for(int j=i;j<n;j++)
		{if(visited[str[j]]==false)
			{
			swap(str+i,str+j);
			printpermutationutil(str,i+1,n);
			swap(str+i,str+j);
				visited[str[j]]=true;
				}
		}




	}

}
void printpermutation(char* str)
{int n=strlen(str);int i=0;
	printpermutationutil(str,i,n);



}
void addtonutil(int k,int n,int *res,int index,int final)
{
	if(k>final-1)
	return;
	if(n==0)
	{for(int i=0;i<index;i++)
		cout<<res[i]<<" ";
		cout<<endl;
		return;
	}
	if(n<0)
	return;

	
	
		addtonutil(k+1,n,res,index,final);

		res[index]=k;
		addtonutil(k,n-k,res,index+1,final);
		

	

}
void addton(int n)
{int res[1000];int index=0;
	addtonutil(1,n,res,index,n);

}
void printrcombinationutil(int *a,int *res,int i,int index,int n,int r)
{if(index==r)
	{for(int g=0;g<index;g++)
		cout<<res[g]<<" ";
		cout<<endl;
		return;
	}
	if(i>=n)
		return;
	res[index]=a[i];
	printrcombinationutil(a,res,i+1,index+1,n,r);
	while(a[i]==a[i+1]&&i<n-1)
		i++;
	printrcombinationutil(a,res,i+1,index,n,r);

}
void printcombination(int *a,int n,int r)
{int res[r];int index=0;int i;
	printrcombinationutil(a,res,i,index,n,r);

}
void powerset(int *a,int n)
{cout<<"NULL";
cout<<endl;
for(int i=1;i<=n;i++)
{printcombination(a,n,i);

}

}

void subsum0util(int *a,int *res,int i,int index,int n,int ans)
{if(ans==0)
	{	if(index!=0)
		{
		for(int i=0;i<index;i++)
			cout<<res[i]<<" ";
		cout<<endl;
	}

	}
	if(i>=n)
		return;
	if(index>=n)
		return;

res[index]=a[i];
ans=ans+a[i];
subsum0util(a,res,i+1,index+1,n,ans);
ans=ans-a[i];
while(i<n-1&&a[i]==a[i+1])
	i++;
subsum0util(a,res,i+1,index,n,ans);


}
void subsequencesum0(int *a,int n)
{int res[n];int i=0;int index=0;int ans=0;
	subsum0util(a,res,i,index,n,ans);

}
void printkincutil(int n,int k,int res[],int i,int index)
{if(index==k)
	{for(int g=0;g<index;g++)
		cout<<res[g]<<" ";
		cout<<endl;
		return;

	}
if(i>n)
	return;
res[index]=i;
printkincutil(n,k,res,i+1,index+1);
printkincutil(n,k,res,i+1,index);
}
void printkinc(int n,int k)
{int res[k];int i=1;int index=0;
	printkincutil( n, k, res,i, index);

}
bool isSubSequence(char* a,char* b,int m,int n)
{if(m>n)
	return false;
int i;int j;
	for( i=0,j=0;i<m&&j<n;j++)
	{if(a[i]==b[j])
		i++;

	}
	if(j==m)
		return true;
	return false;

}
void generate(int zeros,int ones,char* res,int n,int i)
{if(i==n)
	{for(int k=0;k<n;k++)
	cout<<res[k];
		cout<<endl;
		return;

	}
	if(ones==zeros)
	{res[i]='1';
		generate(zeros,ones+1,res,n,i+1);

	}
	else if(ones>zeros)
	{res[i]='1';
		generate(zeros,ones+1,res,n,i+1);
	res[i]='0';
		generate(zeros+1,ones,res,n,i+1);
	}

}
int maxOnesIndex(bool *a,int n)
{int previndex=-1;int maxlen=-1;int maxindex=-1;int currindex=-1;
	int prevprevindex=-1;int i=0;
	while(i<n)
	{while(a[i]==1)
		i++;
		currindex=i;
		if(currindex - prevprevindex>maxlen)
			{maxlen=currindex - prevprevindex;
			maxindex=previndex;}
			prevprevindex=previndex;
			previndex=currindex;
			i++;

	}
	
if(n-prevprevindex>maxlen)
	maxindex=previndex;

return maxindex;

}
int  issetbit(int a,int l)
{int b=1<<l;
	if(a&b)
		return 1;
	return 0;

}
int  replace05(int n)
{if(n==0)
	return 0;
	int a=n%10;
	if(a==0)
		a=5;
	return (10*(replace05(n/10))+a);

}
#define MAX_CHAR 26

// n is number of computers in cafe.
// 'seq' is given sequence of customer entry, exit events
int runCustomerSimulation(int n, const char *seq)
{
    // seen[i] = 0, indicates that customer 'i' is not in cafe
    // seen[1] = 1, indicates that customer 'i' is in cafe but
    //              computer is not assigned yet.
    // seen[2] = 2, indicates that customer 'i' is in cafe and
    //              has occupied a computer.
    char seen[MAX_CHAR] = {0};

    // Initialize result which is number of customers who could
    // not get any computer.
    int res = 0;

    int occupied = 0;  // To keep track of occupied computers

    // Travers the input sequence
    for (int i=0; seq[i]; i++)
    {
        // Find index of current character in seen[0...25]
        int ind = seq[i] - 'A';

        // If First occurrence of 'seq[i]'
        if (seen[ind] == 0)
        {
            // set the current character as seen
            seen[ind] = 1;

            // If number of occupied computers is less than
            // n, then assign a computer to new customer
            if (occupied < n)
            {
                occupied++;

                // Set the current character as occupying a computer
                seen[ind] = 2;
            }

            // Else this customer cannot get a computer,
            // increment result
            else
                res++;
        }

        // If this is second occurrence of 'seq[i]'
        else
        {
           // Decrement occupied only if this customer
           // was using a computer
           if (seen[ind] == 2)
               occupied--;
           seen[ind] = 0;
        }
    }
    return res;
}
void generateutil(int *a,int *b,int * res,int n,int m,int i,int j,int len,bool flag)
{if(len>=m+n-1)
	return;

	

	if(flag==false)
	{res[len]=a[i];
		for(int g=j;g<m;g++)
		{if(b[g]>res[len])
			{//cout<<"ddd"<<b[g]<<endl;
			generateutil(a,b,res,n,m,i+1,g,len+1,!flag);
			}

		}
	}
		else if(flag==true)
		{res[len]=b[j];

	{for(int h=0;h<=len;h++)
	{cout<<res[h]<<" ";
	

	}
	cout<<endl;
}
		for(int d=i;d<n;d++)
		{if(a[d]>res[len])
			{//cout<<"asf"<<a[d]<<endl;
			generateutil(a,b,res,n,m,d,j+1,len+1,!flag);
			}

		}

		

	}



}
void generate(int *a,int *b,int n,int m)
{bool flag=false;
	int res[m+n-1];
	int len;
	int i=0;int j=0;
	for(int k=0;k<n;k++)
	 {generateutil(a,b,res,n,m,k,j,len,flag);
	}
}
int *p;
void fun(int *a)
{
    a = (int*)malloc(sizeof(int));
    p=a;
    *p = 6;
    printf("%d\n",*p);
}

int main()
{
    
  char arr[] = "geeksforgeeks";
    char *ptr1 = arr;
    char *ptr2 = ptr1 + 3;
    printf ("ptr2 - ptr1 = %d\n", ptr2 - ptr1);
    printf ("(int*)ptr2 - (int*) ptr1 = %d",  (int*)ptr2 - (int*)ptr1);
    getchar();
    return 0;
}