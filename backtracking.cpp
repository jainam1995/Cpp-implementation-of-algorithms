#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int jai=0;
using namespace std;
void swap(char* a,char* b)
{char c=*a;
	*a=*b;
	*b=c;

}
void permute(char str[],int l,int r)
{if(l==r)
	printf("%s\n",str);
else{
for(int i=l;i<=r;i++)
{swap(&str[l],&str[i]);
	permute(str,l+1,r);
	swap(&str[l],&str[i]);
}

}

}
bool issafe(int sol[][8],int x,int y)
{if(x>=0&&x<8&&y>=0&&y<8&&sol[x][y]==-1)
	return true;
	else return false;

}
bool solveKTutil(int sol[8][8],int xrow[8],int yrow[8],int move,int x,int y)
{jai++;int i,xnew,ynew;
	cout<<move<<" ";
	if(move==64)
	return true;
	//if(issafe(sol,x,y))
		//sol[x][y]=move;
	for( i=0;i<8;i++)
	{
		 xnew=x+xrow[i];
	 ynew=y+yrow[i];
	if(issafe(sol,xnew,ynew))
	{sol[xnew][ynew]=move;
		if(solveKTutil(sol,xrow,yrow,move+1,xnew,ynew))
		return true;
	else sol[xnew][ynew]=-1;
}
	}
	return false;

}
void printans(int sol[][8])
{for(int i=0;i<8;i++)
	{for(int j=0;j<8;j++)
		cout<<sol[i][j]<<" ";
		
	}cout<<"\n";

}
void solveKT()
{int sol[8][8];
	for(int i=0;i<8;i++)
		{for(int j=0;j<8;j++)
			sol[i][j]=-1;
			}
	int xrow[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    int yrow[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
	int move=1;
	int x=0;
	int y=0;
	sol[0][0]=0;
	if(solveKTutil(sol,xrow,yrow,move,x,y)==true)
		printans(sol);
	else cout<<"not possible \n";
cout<<"\n"<<jai<<endl;



}
bool issafemaze(int sol[][4],int maze[][4],int x,int y)
{if(x>=0&&x<4&&y>=0&&y<4&&maze[x][y]&&sol[x][y]==-1)
	return true;
	else return false;


}

void printans(int sol[][4])
{for(int i=0;i<4;i++)
	{for(int j=0;j<4;j++)
		cout<<sol[i][j]<<" ";
		cout<<endl;

	}

}
void solvemazeutil(int maze[][4],int sol[][4],int x,int y,int xrow[],int yrow[])
{
for(int i=0;i<3;i++)
{int nextx=x+xrow[i];
	int nexty=y+yrow[i];
	if(issafemaze(sol,maze,nextx,nexty))
	{sol[nextx][nexty]=1;
		solvemazeutil(maze,sol,nextx,nexty,xrow,yrow);
			




	}


}
//return false;
}





void solveMaze(int maze[4][4])
{int xrow[]={0,1,1};
int yrow[]={1,0,1};
int sol[4][4];
for(int i=0;i<4;i++)
{for(int j=0;j<4;j++)
	sol[i][j]=-1;

}
sol[0][0]=1;
solvemazeutil(maze,sol,0,0,xrow,yrow);
if(sol[3][3]==1)
	printans(sol);
else cout<<"not possible\n";
}
void solveNQ()
{


	
}
int main()
{

	solveNQ();
	return 0;
}