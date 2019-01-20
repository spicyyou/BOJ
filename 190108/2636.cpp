	#include<iostream>
	#include<stdio.h>
	#include<utility>
	#include<vector>
	#include<algorithm>
	#include<stack>
	#include<string.h>
	#include<queue>
	using namespace std;

	int adj[105][105];
	int visit[105][105];
	int drow[4] = { 0,0,1,-1 };
	int dcol[4] = { 1,-1,0,0 };

	int n, m;
	int ok;
	void dfs(pair<int,int> k) {
		int row = k.first;
		int col = k.second;
		visit[row][col] = 1;
		for (int i = 0; i < 4; i++) {
			int nrow = row + drow[i];
			int ncol = col + dcol[i];
			if (nrow < 0 || ncol < 0 || nrow >= n || ncol >= m) continue; 
			if (adj[nrow][ncol] == 1 && visit[nrow][ncol]==0) {
				visit[nrow][ncol] = 1;
				adj[nrow][ncol] = 0;
			}
			else if (visit[nrow][ncol]==0&&adj[nrow][ncol]==0) {
				visit[nrow][ncol] = 1;
				dfs({ nrow,ncol });
			}
		}

	}


	int main() {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &adj[i][j]);
			}
		}
		int cnt = 0;
		int prev = 0;
		int time = 0;
		while (1) {
			time++;
			cnt = 0;
			/*for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cout << adj[i][j] << " ";
				}
				cout << endl;
			}*/
			memset(visit, 0, sizeof(visit));
			for (int i = 1; i < n; i++) {
				for (int j = 1; j < m; j++) {
					if (adj[i][j] == 1) {
						cnt++;
					}
				}
			}
			dfs({ 0, 0 });
			if (cnt == 0) {
				printf("%d\n", time-1);
				printf("%d\n", prev);
				break;
			}
			else {
				prev = cnt;
			}
		}
	
	}


