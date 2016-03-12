#include <bits/stdc++.h>
using namespace std;
void swap(char*a,char*b)
{char c=*a;
	*a=*b;
	*b=c;


}
void permute(char* s,int i,int n)
{if(i==n)
	{cout<<s<<" \n";
	return;}
	else{bool a[255]={false};
	for(int j=i;j<n;j++)
	{
		if(a[s[j]]==false)
		{swap(s+i,s+j);
		permute(s,i+1,n);
		swap(s+i,s+j);
			a[s[j]]=true;}

	}


}

}
int min(int a,int b)
{if(a<b)
	return a;
	return b;

}
int binomial(int n,int k)
{k=min(k,n-k);


}
void printSequtil(int *res,int index,int k,int n,int start)
{if(index==k)
	{for(int i=0;i<k;i++)
		cout<<res[i]<<" ";
		cout<<endl;
		return;

	}
	if(start>n)
		return;
	res[index]=start;
	printSequtil(res,index+1,k,n,start+1);
	printSequtil(res,index,k,n,start+1);

}
void printSeq(int n,int k)
{int res[k];int index=0;int start=1;
	printSequtil(res,index,k,n,start);

}
void printPatternutil(char* str,char* res,int i,int len,int index,int k)
{if(index==k)
	{for(int g=0;g<k;g++)
		cout<<res[g];
		cout<<endl;
		return;

	}
	if(i>=len)
		return;
	if(index==0||res[index-1]==' ')
	{res[index]=str[i];//cout<<"dsfsdf\n";
		printPatternutil(str,res,i+1,len,index+1,k);

	}
	else{res[index]=' ';
		printPatternutil(str,res,i,len,index+1,k);
		res[index]=str[i];
		printPatternutil(str,res,i+1,len,index+1,k);
//cout<<"Asd\n";
		
		

	}

}
void printPattern(char* str)
{int len=strlen(str);int k=2*len-1;

	char res[k];
	int index=0;
	int i=0;
	printPatternutil( str, res, i, len, index, k);


}


int main()
{ char str[] = "ABC";
//cout<<str[strlen(str)];
    printPattern(str);

	return 0;
}