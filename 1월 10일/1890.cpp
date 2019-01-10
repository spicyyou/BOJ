#include<iostream>
#include<stdio.h>
#include<utility>
#include<vector>
#include<algorithm>
#include<stack>
#include<string.h>
#include<queue>
using namespace std;

int arr[105][105];
int visit[105][105];
int drow[3] = { 0,1 };
int dcol[3] = { 1,0 };
long long int dp[105][105];
int n;
int cnt;
int ddfs(int row, int col) {
	visit[row][col] = 1;
	if (row == n&&col == n) {
		cnt++; 
		return 0;
	}
	for (int i = 0; i < 2; i++) {
		int nrow = row + (drow[i] * arr[row][col]);
		int ncol = col + (dcol[i] * arr[row][col]);
		if (nrow > n || ncol > n || nrow <= 0 || ncol <= 0)continue;
		if (!visit[nrow][ncol]) {
			ddfs(nrow, ncol);
		}
	}
	return 0;
}

long long int dfs(int row, int col) {
	if (dp[row][col] != -1) return dp[row][col];
	if (row > n || col > n || row <= 0 || col <= 0) return 0;
	if (row == n && col == n) return 1;
	dp[row][col] = 0;
	for (int i = 0; i < 2; i++) {
		int nrow = row + drow[i] * arr[row][col];
		int ncol = col + dcol[i] * arr[row][col];
		dp[row][col] += dfs(nrow, ncol);
	}
	return dp[row][col];
}



int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &arr[i][j]);
			dp[i][j] = -1;
		}
	}
	long long int ans = dfs(1, 1);
	cout << ans << endl;
}