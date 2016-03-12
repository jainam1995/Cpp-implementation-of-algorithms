#include <bits/stdc++.h>
using namespace std;
void printarray(int *a,int n)
{for(int i=0;i<n;i++)
    {cout<<a[i]<<" ";

    }
    cout<<endl;

}
void swap(int *a,int *b)
{int temp=*a;
    *a=*b;
    *b=temp;

}
int  partitionmodify(int* a,int n)
{int i=-1;int j=0;
while(j<n)
{while(j<n&&a[j]>0)
    {j++;

    }
    if(a[j]<=0)
    {i++;
        swap(a+j,a+i);
        j++;

    }

}
return i;
}
void zeroend(int *a,int l,int r)
{int j=0;
for(int i=0;i<=r;i++)
{if(a[i]!=0)
    {a[j++]=a[i];

    }

}
while(j<=r)
{a[j]=0;
j++;

}

}
void swap(char* a,char* b)
{char temp=*a;
    *a=*b;
    *b=temp;

}
void printarray(char* a,int n)
{for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;

}
int partitionnuts(char* nuts,int l,int r)
{int i=l-1;int j=l;
    char ans=nuts[r];// cout<<" ans"<<ans<<" " ;
    while(j<r)
    {while(j<r&&nuts[j]>ans)
        j++;
        if(j>=r)
            break;
        if(nuts[j]<=ans)
        {i++;
            swap(nuts+i,nuts+j);
            j++;

        }

    }
i++;
//cout<<"sadasd"<<nuts[i]<<" "<<nuts[r]<<" "  ;
swap(nuts+i,nuts+r);
return i;
}
void partitionbolts(char* bolts,char ans,int l,int r)
{int i=l-1;int j=l;
    while(j<=r)
    {while(j<=r&&bolts[j]>ans)
        j++;
        if(j>r)
            break;
        if(bolts[j]<=ans)
        {i++;
            swap(bolts+i,bolts+j);
            j++;

        }

    }
for(int k=l;k<=i;k++)
{if(bolts[k]==ans)
    {
        swap(bolts+k,bolts+i);
        break;
    }

}
}
void nutsandbolts(char*nuts,char* bolts,int l,int r)
{if(l<r)
    {int pivot=partitionnuts(nuts,l,r);
       cout<<nuts[pivot]<<endl;
       
        partitionbolts(bolts,nuts[pivot],l,r);
        printarray(nuts,6);
       printarray(bolts,6);
        nutsandbolts(nuts,bolts,l,pivot-1);
        nutsandbolts(nuts,bolts,pivot+1,r);

    }


}
void printPatternutil(char*s,char*res,int i,int index,int len,int size)
{if(i==len)
    {for(int k=0;k<index;k++)
        {cout<<res[k];


        }
        cout<<endl;
        return;

    }
    if(i>len)
        return;
    if(i==0||res[index-1]==' ')
    {res[index]=s[i];
        printPatternutil(s,res,i+1,index+1,len,size);

    }
    else{
    res[index]=s[i];
       // cout<<"we";
        printPatternutil(s,res,i+1,index+1,len,size);
        res[index]=' ';
        printPatternutil(s,res,i,index+1,len,size);
    }
        

    

}
void printspaces(char*s,char* res,int i,int index,int len,int size)
{if(i==len-1)
    {for(int k=0;k<=index;k++)
        {cout<<res[k];


        }
        cout<<endl;
        return;

    }
    if(i>=len)
        return;
    res[index]=s[i];
    printspaces(s,res,i+1,index+1,len,size);
    res[index+1]=' ';
    printspaces(s,res,i+1,index+2,len,size);


}
void printPattern(char* s)
{int len=strlen(s);
    int size=2*len-1;
    char res[size];
    int i=0;int index=0;
    printPatternutil(s,res,i,index,len,size);

}
void printcombinationutil(char*s,char*res,int len,int k,int i,int index)
{if(index==k)
    {for(int g=0;g<index;g++)
        cout<<res[g];
        cout<<endl;
        return;
    }
    if(i>=len)
        return;
    res[index]=s[i];
    printcombinationutil(s,res,len,k,i+1,index+1);
    while(i<len-1&&s[i]==s[i+1])
        i++;
    printcombinationutil(s,res,len,k,i+1,index);


}
void printcombination(char*s,int k)
{char res[k];int len=strlen(s);
    int i=0;int index=0;
    printcombinationutil(s,res,len,k,i,index);

}
void printpermutationuutil(char* s,int l,int r)
{if(l==r)
    {
        cout<<s;
        cout<<endl;
        return;


    }else{cout<<"Ad";
       // bool visited[255]={false};
        for(int i=l;i<=r;i++)
        {
            swap(s+l,s+i);
                printpermutationuutil(s,l+1,r);
                swap(s+l,s+i);
              


            

        }


    }

}
void printpermutation(char* s)
{int n=strlen(s);
    int i=0;
    printpermutationuutil(s,0,n-1);

}

int main() 
{ char *str = "ABC";
    printpermutation(str);
return 0;
}