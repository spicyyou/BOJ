//2017030519_홍유진_A
#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<queue>
#include<algorithm>
#include<stack>
#include<map>
#include<functional>

using namespace std;

vector<pair<int, int> > adj[1005];
priority_queue<int> dis[1005];
//int dis[1005][105];
int INF = 9999999;
int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		adj[a].push_back({ b,c });
	}
	priority_queue < pair<int, int >> pq;

	pq.push({ -0,1 });//0가중치의 1번 노드 시작
	dis[1].push( 0 );
	while (!pq.empty())
	{
		int now = pq.top().second;
		int weight = -pq.top().first;
		pq.pop();
		for (int i = 0; i < adj[now].size(); i++) {
			int next = adj[now][i].first;
			int nw = weight + adj[now][i].second;
			if (dis[next].size() < k) {
				dis[next].push(nw);
				pq.push({ -nw,next });
			}
			else {
				if (dis[next].top() > nw) {
					dis[next].pop();
					dis[next].push({ nw });
					pq.push({ -nw,next });
				}
			}

		}
	}
	for (int i = 1; i <= n; i++) {
		if (dis[i].size() != k) {
			printf("-1\n");
		}
		else {
			printf("%d\n", dis[i].top());
		}
	}
}