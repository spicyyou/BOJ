#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>
#include<string>
#include<climits>
#include<string.h>

using namespace std; 

int arr[1005][1005];
int dp[1005][1005];
int dr[] = { -1,-1,0 };
int dc[] = { 0,-1,-1 };
int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	dp[0][0] = arr[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 && j == 0) continue;
			for (int k = 0; k < 3; k++) {
				int ni = i + dr[k];
				int nj = j + dc[k];
				if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
				dp[i][j] = max(dp[ni][nj], dp[i][j]);
			}
			dp[i][j] += arr[i][j];
		}
	}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", dp[i][j]);
		}cout << endl;
	}*/
	printf("%d\n", dp[n - 1][m - 1]);

}