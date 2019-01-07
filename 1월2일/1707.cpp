#include<iostream>
#include<stdio.h>
#include<utility>
#include<vector>
#include<algorithm>
#include<stack>
#include<string.h>
using namespace std;

vector<int> adj[20005];

char color[3] = { 'A','B' };
int visit[20005];
int comp[20005];
int cnt = 0;
int isokay = 0;

void dfs(int k, int c) {
	comp[k] = 1;
	/*int j = cnt % 2;
	cnt++;
	c++;*/
	visit[k] = c;
	for (int n = 0; n < adj[k].size(); n++) {
		int new_v = adj[k][n];
		if (visit[new_v] == 0) {
			dfs(new_v, 3-c);
		}
	}
	/*else {
	if (visit[new_v] == visit[k]) {
	isokay = -1;
	return;
	}
	}
	if (isokay == -1) {
	return;
	}
	}if (isokay == -1) {
	return;
	}*/
}


int main() {
	int k;
	cin >> k;
	while (k--) {
		int V, E;
		scanf("%d%d", &V, &E);
		for (int i = 0; i < E; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		for (int i = 1; i <= V; i++) {
			if (comp[i] == 0) {
				dfs(i, 0);
			}

		}
		for (int i = 1; i <= V; i++) {
			for (int j = 0; j < adj[i].size(); j++) {
				int k = adj[i][j];
				if (visit[i] == visit[k]) {
					isokay = -1;
					break;
				}
			}
		}
		if (isokay != 0) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
		}
		int cnt = 0;
		isokay = 0;
		memset(visit, 0, sizeof(visit));
		memset(comp, 0, sizeof(comp));
		for (int i = 1; i <= V; i++) {
			adj[i].clear();
		}
	}
}