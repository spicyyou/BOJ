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
#include<deque>

using namespace std;
vector<pair<int, int > > adj[1005];
vector<pair<int, int > > res;
int dis[1005];
int track[1005];
int INF = 99999999;
int visit[1005];
int cnt = 0;
void dfs(int now) {
	visit[now] = 1;
	for (int i = 0; i < adj[now].size(); i++) {
		int next = adj[now][i].first;
		int nww = adj[now][i].second;
		if (dis[next] == dis[now] + nww && !visit[next]) {
			cnt++;
			res.push_back({ now,next });
			visit[next] = 1;
			dfs(next);

		}
	}
}

int main() {
	int test = 1;
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}
	priority_queue<pair<int, int> > pq;
	for (int i = 1; i <= n; i++) {
		dis[i] = INF;
	}
	pq.push({ -0,1 });
	dis[1] = 0;
	while (!pq.empty()) {
		int w = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		for (int i = 0; i < adj[now].size(); i++) {
			int next = adj[now][i].first;
			int nw = adj[now][i].second + w;
			if (dis[next] > nw) {
				dis[next] = nw;
				//track[next] = now;
				pq.push({ -nw,next });
			}
		}
	}
	dfs(1);
	printf("%d\n", cnt);
	for (int i = 0; i < res.size(); i++) {
		printf("%d %d\n", res[i].first, res[i].second);
	}


}