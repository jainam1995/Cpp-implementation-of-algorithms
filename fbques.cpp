#include <bits/stdc++.h>
using namespace std;



int main()
{int n;int m;
	cin>>n>>m;int i;int j;
	int mat[n][m];
	for(i=0;i<n;i++)
	{for( j=0;j<m;j++)
		mat[i][j]=0;

	}
	int dir=0;
	mat[0][0]=1;
	
	int y[]={1,0,-1,0};
	int x[]={0,1,0,-1};
	i=0;j=0;
	int prev=0;
	int count=2;
	int done=0;
	int g;
	while(!done)
	{
		for( g=0;g<4;g++)
		{if(mat[i+x[(4+dir+g)%4]][j+y[(4+dir+g)%4]]==0&&(i+x[(4+dir+g)%4])>=0&&(i+x[(4+dir+g)%4])<n&&(j+y[(4+dir+g)%4])>=0&&(j+y[(4+dir+g)%4])<m)
			{mat[i+x[(dir+g)%4]][j+y[(dir+g)%4]]=count;
				count++;
				i=i+x[(dir+g)%4];
					j=j+y[(dir+g)%4];

					dir=(dir+1)%4;
					cout<<dir<<" "<<i<<" "<<j<<endl	;
					break;
			}
done=1;
		}
		

	}
		cout<<mat[i+x[(dir+g)%4]][j+y[(dir+g)%4]]<<endl<<" "<<i+x[(dir+g)%4]<<" "<<j+y[(dir+g)%4];
cout<<endl;cout<<"sd"<<g;cout<<endl;

	for(i=0;i<n;i++)
	{for(j=0;j<m;j++)
		{cout<<mat[i][j]<<" ";

		}
		cout<<endl;

	}

}