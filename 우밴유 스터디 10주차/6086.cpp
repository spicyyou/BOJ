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

int cap[705][705];
int flow[705][705];
vector<int> adj[705];
int main() {
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char a, b;
		int c;
		cin >> a >> b >> c;
		int from = a - 'A';
		int to = b - 'A';
		cap[a - 'A'][b - 'A'] += c;
		cap[b - 'A'][a - 'A'] += c;
		adj[from].push_back(to);
		adj[to].push_back(from);
	}
	int ans = 0;
	int start = 0;
	int sink = 'Z' - 'A';
	while (1) {
		int prev[705];
		memset(prev, -1, sizeof(prev));

		queue<int> q;
		q.push(start);


		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			for (int i = 0; i < adj[cur].size(); i++) {
				int next = adj[cur][i];

				if (prev[next] != -1) continue;

				if (cap[cur][next] - flow[cur][next] > 0) {
					q.push(next);
					prev[next] = cur;

					if (next == sink) { break; }
				}
			}
		}


		if (prev[sink] == -1) {
			break;
		}

		int f = INT_MAX;
		for (int i = sink; i != start; i = prev[i]) {
			f = min(f, cap[prev[i]][i] - flow[prev[i]][i]);
		}

		for (int i = sink; i != start; i = prev[i]) {
			flow[prev[i]][i] += f;
			flow[i][prev[i]] -= f;
		}
		ans += f;
	}
	printf("%d\n", ans);
}