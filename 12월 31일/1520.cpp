#include<iostream>
#include<stdio.h>
#include<utility>
#include<vector>
#include<algorithm>
#include<stack>
#include<string.h>
using namespace std;

int dp[505][505];
int arr[505][505];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int visit[505][505];
int n, m;
int dfs(int row,int col) {

	if (dp[row][col] != -1) return dp[row][col];
	if (col > m || row > n || col < 1 || row < 1) return 0;
	if (row == 1 && col == 1) {
		return 1;
	}
	dp[row][col] = 0;
	for (int i = 0; i < 4; i++) {
		int dxcol = col + dx[i];
		int dyrow = row + dy[i];
		if (arr[row][col] < arr[dyrow][dxcol]) {
			dp[row][col] += dfs(dyrow, dxcol);
		}
	}
	return dp[row][col];
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &arr[i][j]);
			dp[i][j] = -1;
		}
	}
	dfs(n, m);
	printf("%d\n", dp[n][m]);
	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			printf("%d ", dp[i][j]);
		}
		cout << endl;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			printf("%d ", visit[i][j]);
		}
		cout << endl;
	}for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			printf("%d ", dp[i][j]);
		}
		cout << endl;
	}
}*/
}