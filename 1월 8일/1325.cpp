#include<iostream>
#include<stdio.h>
#include<utility>
#include<vector>
#include<algorithm>
#include<stack>
#include<string.h>
#include<queue>
using namespace std;

vector<int> adj[10005];
int visit[10005];

int dfs(int k) {
	visit[k] = 1;
	int res = 1;
	for (int i = 0; i < adj[k].size(); i++) {
		int next = adj[k][i];
		if (visit[next] == 0) {
			visit[next] = 1;
			res += dfs(next);
		}
	}
	return res;
}
vector<int> ans;
vector<int> arr;
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		int temp = dfs(i);
		memset(visit, 0, sizeof(visit));
		ans.push_back(temp);
	}
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (max < ans[i]) {
			max = ans[i];
		}
	}

	for (int i = 0; i < n; i++) {
		if (ans[i] == max) {
			arr.push_back(i + 1);
		}
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++) {
		printf("%d ", arr[i]);
	}
}