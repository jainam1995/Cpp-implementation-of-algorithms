#include <bits/stdc++.h>
using namespace std;
void swap(char*a,char* b)
{char temp=*a;
    *a=*b;
    *b=temp;

}
void printpermutationuutil(char* s,int l,int r)
{if(l==r)
    {
        cout<<s;
        cout<<endl;
        return;


    }else{//cout<<"Ad";
        bool visited[255]={false};
        for(int i=l;i<=r;i++)
        {if(visited[s[i]]==false)
            {
            swap(s+l,s+i);
                printpermutationuutil(s,l+1,r);
                swap(s+l,s+i);
                visited[s[i]]=true;
            }
              


            

        }


    }

}
void printpermutation(char* s)
{int n=strlen(s);
    
    printpermutationuutil(s,0,n-1);

}
void findcandidatesutil(int *a,int res[],int i,int n,int index,int sum)
{if(sum==0)
    {//cout<<"sd";
        for(int k=0;k<index;k++)
        cout<<res[k]<<" ";
        cout<<endl;
        return;


    }
    if(sum<0||i>=n||index>=n)
        return;
    //  cout<<"sd";
    res[index]=a[i];
    findcandidatesutil(a,res,i+1,n,index+1,sum-a[i]);
    while(i<n-1&&a[i]==a[i+1])
        i++;
    findcandidatesutil(a,res,i+1,n,index,sum);


}
void printarray(int *a,int n)
{for(int i=0;i<n;i++)
    cout<<a[i];
    cout<<endl;

}
void findcandidates(int *a,int n,int sum)
{sort(a,a+n);
    int res[n];
    int i=0;int index=0;
    findcandidatesutil(a,res,i,n,index,sum);


}
void multiply(int *a,int na,int *b,int nb)
{int c[na+nb];int s=na+nb-1;
    for(int h=0;h<na+nb;h++)
        c[h]=0;
    for(int i=na-1;i>=0;i--)
    {int carry=0;
        int shift=s;
        for(int j=nb-1;j>=0;j--)
        {int m=a[i]*b[j];
            int sum=c[shift]+carry+m;
            c[shift]=sum%10;
            carry=sum/10;
            shift--;

        }
        c[shift]=c[shift]+carry;
        s--;



    }
    printarray(c,na+nb);

}   
bool dictionaryContains(string word)
{
    string dictionary[] = {"mobile","samsung","sam","sung","man","mango",
                           "icecream","and","go","iii","i","like","ice","cream"};
    int size = sizeof(dictionary)/sizeof(dictionary[0]);
    for (int i = 0; i < size; i++)
        if (dictionary[i].compare(word) == 0)
           return true;
    return false;
}
bool wordBreak(string s)
{int len=s.size();
    if(len==0)
        return true;
    bool ans[len];
    for(int i=0;i<len;i++)
        ans[i]=false;
    for(int i=1;i<len;i++)
    {for(int j=0;j<i;j++)
        {if(ans[j]&&dictionaryContains(s.substr(j+1,i-j)))
            ans[i]=true;
            else if(dictionaryContains(s.substr(0,j+1)))
            {ans[j]=true;
                if(dictionaryContains(s.substr(j+1,i-j)))
                    ans[i]=true;

            }

        }

    }
    return ans[len-1];

}
void printSequtil(int *res,int index,int k,int i,int n)
{if(index==k)
    {for(int j=0;j<index;j++)
        cout<<res[j];
        cout<<endl;
        return;

    }
    if(i>n)
        return;
    res[index]=i;
    printSequtil(res,index+1,k,i+1,n);
    printSequtil(res,index,k,i+1,n);

}
string dictionary[] = {"GEEK", "FOR", "QUIZ", "GO"};
int n = sizeof(dictionary)/sizeof(dictionary[0]);
void printSeq(int n,int k)
{int res[k];
    int i=1;int index=0;
    printSequtil(res,index,k,i,n);

}bool issafe(int x,int y,int r,int c)
{if(x>=0&&y>=0&&x<r&&y<c)
    return true;
    return false;

}
bool ispresentutil(int i,int j,int* xrow,int* yrow,string s,int level,int len,bool visited[3][3],int r,int c,char boggle[3][3])
{visited[i][j]=true;
if(level==len-1)
    return true;
if(level>=len-1)
    return false;
level++;
for(int k=0;k<8;k++)
{int newx=i+xrow[k];
    int newy=j+yrow[k];
    if(boggle[newx][newy]==s[level]&&visited[newx][newy]==false&&issafe(newx,newy,r,c))
    {return ispresentutil(newx,newy,xrow,yrow,s,level,len,visited,r,c,boggle);

    }


}
visited[i][j]=false;
return false;
}
void findallutil(char boggle[2][2],bool visited[2][2],int x,int y,char* ans,int level,int r,int c,int len)
{visited[x][y]=true;
    ans[level++]=boggle[x][y];
    if(level==len)
   { for(int i=0;i<level;i++)
        cout<<ans[i];
    cout<<endl;
    visited[x][y]=false;
return;}
    if(level>=len)
        {visited[x][y]=false;
            return;}
int i;int j;
    for( i=0;i<r;i++)
    {for( j=0;j<c;j++)
        {if(visited[i][j]==false)
            {findallutil(boggle,visited,i,j,ans,level,r,c,len);

            }

        }

    }
    visited[x][y]=false;

}
void findall(char boggle[2][2],int r,int c)
{char ans[r*c];
    bool visited[2][2];int level=0;int len=3;

    for(int h=0;h<r;h++)
    {for(int g=0;g<c;g++)
        visited[h][g]=false;
    }
    for(int i=0;i<r;i++)
    {for(int j=0;j<c;j++)
        {findallutil(boggle,visited,i,j,ans,level,r,c,len);
           
        }

    }



}

int main() 
{  char boggle[2][2] = {{'G','I'},
                         {'U','E'}};

    cout << "Following words  are present\n";
    findall(boggle,2,2);
}