#include <bits/stdc++.h>
using namespace std;
struct Interval
{
    int start;
    int end;
};
bool compare(Interval a,Interval b)
{if(a.start<=b.start)
	return 1;
	return 0;

}
void mergeintervals(struct Interval a[],int n)
{sort(a,a+4,compare);struct Interval temp;
	for(int i=0;i<4;i++)
		cout<<a[i].start<<" "<<a[i].end<<" ";
	stack<Interval> s;
	s.push(a[0]);
	for(int i=1;i<4;i++)
	{temp=s.top();
		if(a[i].start>temp.end)
			s.push(a[i]);
		else{
			if(a[i].end>temp.end)
				{temp.end=a[i].end;}
			cout<<temp.start<<" "<<temp.end;
		}

	}
	cout<<"asd"<<s.top().end;
while(!s.empty())
{temp=s.top();
	s.pop();
		cout<<temp.start<<" "<<temp.end<<"\n";

}
}
void printKMax(int *a,int n,int k)
{
	
}

int main()
{  int arr[] = {12, 1, 78, 90, 57, 89, 56};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    printKMax(arr, n, k);
}