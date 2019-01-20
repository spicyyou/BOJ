#include<iostream>
#include<stdio.h>
#include<utility>
#include<vector>
#include<algorithm>
#include<stack>
#include<string.h>
using namespace std;

vector<int> out[100];
vector<int> in[100];

int visit[100];
int visit_in[100];
int dfs1(int k) {
	int res = 1;
	for (int i = 0; i < out[k].size(); i++) {
		if (!visit[out[k][i]]) {
			visit[out[k][i]] = 1;
			res += dfs1(out[k][i]);
		}
	}
	return res;
}


int dfs2(int k) {
	int res = 1;
	for (int i = 0; i < in[k].size(); i++) {
		if (!visit_in[in[k][i]]) {
			visit_in[in[k][i]] = 1;
			res += dfs2(in[k][i]);
		}
	}
	return res;
}
int res[100];
int main() {
	int n,m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		out[a].push_back(b);
		in[b].push_back(a);
	}
	int mid = (n + 1) / 2;
	for (int i = 1; i <= n; i++) {
		visit[i] = 1;
		visit_in[i] = 1;
		if (dfs1(i) > mid || dfs2(i) > mid) {
			res[i] = 1;
		}
		memset(visit, 0, sizeof(visit));
		memset(visit_in, 0, sizeof(visit_in));
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (res[i] == 1) {
			ans++;
		}
	}
	printf("%d\n", ans);
}