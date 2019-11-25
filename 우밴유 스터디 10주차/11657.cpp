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
struct Edge {
	int start, end, weight;
};
vector<Edge> edges;
int dis[505];
int visit[505];


int pass1, pass2;
vector<int> adj[505];
int isok;
int dfs(int now) {
	visit[now] = 1;
	for (int i = 0; i < adj[now].size(); i++) {
		int next = adj[now][i];
		if (!visit[next]) {
			visit[next] = 1;
			if (next == pass1 || next == pass2) {
				isok = 1;
				return 1;
			}
			dfs(next);
		}
	}
	if (isok == 0) {
		return 0;
	}
	else {
		return 1;
	}
}

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	int flag = 0;
	int flag2 = 0;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		//adj[a].push_back(b);
		Edge tmp;
		tmp.start = a, tmp.end = b, tmp.weight = c;
		edges.push_back(tmp);
		//if (a == 1) {
			//flag = 1;
		//}
	}
	/*if (flag == 0) {
		for (int i = 2; i <= N; i++) {
			printf("-1\n");
		}
		return 0;
	}*/
	for (int i = 1; i <= N; i++) {
		dis[i] = INT_MAX;
	}
	dis[1] = 0;
	for (int iter = 1; iter <= N; iter++) {
		for (int i = 0; i < edges.size(); i++) {
			if (dis[edges[i].end] > dis[edges[i].start] + edges[i].weight && dis[edges[i].start] != INT_MAX) {
				dis[edges[i].end] = dis[edges[i].start] + edges[i].weight;
				if (iter == N) {
					printf("-1\n");
					return 0;
				}
			}
		}
	}
	/*cout << flag2 << endl;
	for (int i = 1; i <= N; i++) {
		cout << visit[i] << " ";
	}cout << endl;*/

	for (int i = 2; i <= N; i++) {
		if (dis[i] == INT_MAX) {
			printf("-1\n");
		}
		else {
			printf("%d\n", dis[i]);
		}
	}
	return 0;
}

/*
5 4
1 3 4
2 4 2
4 2 4
4 5 5*/