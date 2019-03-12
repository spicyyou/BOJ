#include<stdio.h>
#include<iostream>
#include<queue>
#include<string.h>
#include<string>
#include<stdlib.h>
#include<vector>
#include<algorithm>

using namespace std;
int arr[55][55];
int visit[55][55];
int drow[4] = { 0,0,-1,1 };
int dcol[4] = { -1,1,0,0 };
queue<pair<int,int> > q;
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m, k;//m : col, n : row
		scanf("%d%d%d", &m, &n, &k);
		for (int i = 0; i < k; i++) {
			int x, y;
			scanf("%d%d", &x, &y); //x : col, y: row;
			arr[y][x] = 1;
		}
		int cnt = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 1&&visit[i][j]==0) {
					q.push({ i,j });
					visit[i][j] = 1;
					while (!q.empty()) {
						auto now = q.front();
						q.pop();
						for (int i = 0; i < 4; i++) {
							int nrow = now.first + drow[i]; //n
							int ncol = now.second + dcol[i]; //m
							if (nrow >= n || ncol >= m || nrow < 0 || ncol < 0) continue;
							if (!visit[nrow][ncol] && arr[nrow][ncol]==1) {
								visit[nrow][ncol] = 1;
								q.push({ nrow,ncol });
							}
						}
					}
					cnt++;
				}
			}
		}
		printf("%d\n", cnt-1);
		memset(visit, 0, sizeof(visit));
		memset(arr, 0, sizeof(arr));
	}
}