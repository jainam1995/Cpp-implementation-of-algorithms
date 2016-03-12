#include<bits/stdc++.h>
#define repe(i,a,n)  for(int i=(a);i<=(n);i++)
using namespace std;

void solve(string str, int n) {
	
	if(!n) {cout << "Empty String!" << " \n0"; return;}
	int i = 0, s = 0;
	int j = 0, e = 0;
	int len = 1;
	bool marked[256] = {false};
	while(j < n) {
		if(!marked[str[j]]) {
			marked[str[j]] = true;
			if(len < j-i+1) {len = j-i+1; s = i; e = j;};
		}
		else {
			while(str[i] != str[j]) marked[str[i++]] = false;
			i++;
		}
		j++;
	}
	repe(i,s,e) cout << str[i];
	cout << "\n" << len << endl;
}

int main() {
	
	string str = "GEEKSFORGEEKS";
	solve(str, str.length());
  	return 0;
}
