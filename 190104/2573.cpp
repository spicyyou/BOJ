#include<iostream>
#include<stdio.h>
#include<utility>
#include<vector>
#include<algorithm>
#include<stack>
#include<string.h>
#include<queue>
using namespace std;

int map[305][305];
int visit[305][305];
int n, m;

int drow[] = { 0,0,-1,1 };
int dcol[] = { -1,1,0,0 };
int component = 0;

void dfs(pair<int,int> k) {
	int row = k.first;
	int col = k.second;
	visit[row][col] = 1;
	for (int i = 0; i < 4; i++) {
		int nrow = row + drow[i];
		int ncol = col + dcol[i];
		if (visit[nrow][ncol] == 0 && map[nrow][ncol] == 0) {
			if (map[row][col] - 1 >= 0) {
				map[row][col]--;
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		int nrow = row + drow[i];
		int ncol = col + dcol[i];
		if (nrow<0 || ncol<0 || nrow>n || ncol>m) continue;
		if (visit[nrow][ncol] == 0&&map[nrow][ncol]!=0) {
			dfs({ nrow,ncol });
		}
	}



}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	int year = 0;
	int flag = 0;
	while (1) {
		for (int i = 1; i <= n-1; i++) {
			for (int j = 1; j <= m-1; j++) {
				if (visit[i][j] == 0&&map[i][j]!=0) {
					flag = 1;
					component++;
					dfs({ i,j });
				}
			}
		}
		if (flag == 0) {
			year = 0;
			break;
		}
		if (component >= 2) {
			break;
		}
		year++;
		flag = 0;
		component = 0;
		memset(visit, 0, sizeof(visit));
	}
	printf("%d\n", year);
}