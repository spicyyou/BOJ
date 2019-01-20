#include<iostream>
#include<stdio.h>
#include<utility>
#include<vector>
#include<algorithm>
#include<stack>
#include<string.h>
#include<queue>
using namespace std;

int coin[105];
int dp[10005];

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		scanf("%d", coin + i);
	}
	for (int i = 1; i <= k; i++) {
		dp[i] = 10001;
	}
	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] = min(dp[j - coin[i]] + 1, dp[j]);
		}
	}
	if (dp[k] == 10001) { printf("-1\n"); }
	else {
		printf("%d\n", dp[k]);
	}
}