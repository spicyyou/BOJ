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

using namespace std;

set<string> s;
char temp[30];
char temp2[30];
vector<string> vec;
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		scanf("%s", temp);
		s.insert(temp);
	}
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		scanf("%s", temp2);
		auto it = s.find(temp2);
		if(it!=s.end()){
			vec.push_back(temp2);
			cnt++;
		}
	}
	printf("%d\n", cnt);
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++) {
		printf("%s\n", vec[i].c_str());
	}
}
