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
int dis[1005];
int res[1005];
int INF = 99999999;
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int T = 0; T < m; T++) {
		int i, j, t;
		scanf("%d%d%d", &i, &j, &t);
		adj[i].push_back({ j,t });
	}
	for (int rr= 1; rr <= n; rr++) {
		for (int temp = 1; temp <= n; temp++) {
			dis[temp] = INF;
		}
		priority_queue<pair<int, int> > pq;// weight,now
		dis[rr] = 0;
		int flag = 0;
		pq.push(make_pair( 0,rr ));
		while (!pq.empty()) {
			int weight = -pq.top().first;
			int now = pq.top().second;
			pq.pop();
			for (int i = 0; i < adj[now].size(); i++) {
				int toGo = adj[now][i].first;
				int toDis = adj[now][i].second+weight;
				if (dis[toGo] > toDis) {
					dis[toGo] = toDis;
					pq.push({ -toDis,toGo });
				}
			}
		}
		res[rr] = dis[k];
		while (!pq.empty())pq.pop();
	}

	for (int temp = 1; temp <= n; temp++) {
		dis[temp] = INF;
	}
	priority_queue<pair<int, int> > pq;// weight,now
	pq.push({ 0,k });
	dis[k] = 0;
	while (!pq.empty()) {
		int weight = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		for (int i = 0; i < adj[now].size(); i++) {
			int toGo = adj[now][i].first;
			int toDis = adj[now][i].second + weight;
			if (dis[toGo] > toDis) {
				dis[toGo] = toDis;
				pq.push({ -toDis,toGo });
			}
		}
	}

	/*for (int i = 1; i <= n; i++) {
		cout << dis[i] << " ";
	}
	cout << endl;
	for (int i = 1; i <= n; i++) {
		cout << res[i] << " ";
	}
	cout << endl;*/
	int max = 0;
	for (int i = 1; i <= n; i++) {
		if (max < dis[i] + res[i]) {
			max = dis[i] + res[i];
		}
	}
	printf("%d\n", max);



}