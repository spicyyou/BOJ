#include<iostream>
#include<stdio.h>
#include<utility>
#include<vector>
#include<algorithm>
#include<stack>
#include<string.h>
#include<queue>
using namespace std;
vector<int> p;
vector<int> res;
int main() {

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		p.push_back(i);
	}
	cout << "<";
	int i = m - 1;
	while (1) {
		if (p.size() != 1) {
			cout << p[i] << ", ";
		}
		else {
			cout << p[i] << ">"<<endl;
			break;
		}
		p.erase(p.begin() + i);
		if (p.size() == 0) break;
		i += (m - 1);
		if (i >= p.size()) {
			i %= p.size();
		}
	}
}