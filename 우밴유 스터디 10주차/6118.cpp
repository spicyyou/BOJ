#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
#include<queue>
#include<climits>
#include<stdlib.h>

using namespace std;

vector<int> adj[20005];

int dis[20005];
int visit[20005];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	queue<pair<int, int > > q;
	q.push({ 1,0 });
	dis[1] = 0;
	int max = 0;
	visit[1] = 1;
	while (!q.empty()) {
		auto now = q.front();
		q.pop();
		for (int i = 0; i < adj[now.first].size(); i++) {
			int next = adj[now.first][i];
			if (!visit[next]) {
				if (now.second + 1 > max) {
					max = now.second + 1;
				}
				dis[next] = now.second+1;
				visit[next] = 1;
				q.push({ next, dis[next] });
			}
		}
	}
	int cnt = 0;
	int ans1 = 0;
	for (int i = 1; i <= n; i++) {
		if (max == dis[i]) {
			if (ans1 == 0) {
				ans1 = i;
			}
			cnt++;
		}
	}
	printf("%d %d %d", ans1, max, cnt);

}