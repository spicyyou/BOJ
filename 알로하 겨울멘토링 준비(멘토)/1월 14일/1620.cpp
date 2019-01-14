#include<iostream>
#include<stdio.h>
#include<utility>
#include<vector>
#include<algorithm>
#include<stack>
#include<string.h>
#include<queue>
#include<set>
#include<ostream>
#include<map>
#include<string>

using namespace std;

map <string, string> is;
map<string, string> si;
char temp[30];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%s", temp);
		is.insert({ to_string(i),temp });
		si.insert({ temp,to_string(i) });
	}
	for (int i = 0; i < m; i++) {
		scanf("%s", temp);
		if (isdigit(temp[0])) {
			printf("%s\n", is[temp].c_str());
		}
		else {
			printf("%s\n", si[temp].c_str());
		}
	}

}