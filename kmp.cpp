#include <bits/stdc++.h>
using namespace std;

void computepls(int * lps,int n,char* pat)
{int j=0;
	int len=0;
	lps[0]=0;
	j=1;
	while(j<n)
	{if(pat[j]==pat[len])
		{len++;
			lps[j]=len;
			j++;

		}
		else{
			if(len!=0)
			{len=lps[len-1];

			}
			else{
				lps[j]=0;
				j++;


			}
		}

	}

}

void KMPSearch(char* pat,char* txt)
{
	int m=strlen(pat);
	int n=strlen(txt);
	int lps[m];
	computepls(lps,m,pat);


	int i=0;int j=0;
	while(i<n)
	{
		if(txt[i]==pat[j])
		{i++;j++;

		}
		if(j==m)
		{cout<<"Pattern found at "<<i-j<<"\n";
		j=lps[j-1];

		}
		else if(i<n&&pat[j]!=txt[i])
		{if(j!=0)
			j=lps[j-1];
			else
				i++;


		}




	}


}



int main()
{
	char *txt = "ABABDABACDABABCABAB";
   char *pat = "A";
   KMPSearch(pat, txt);
   return 0;
}