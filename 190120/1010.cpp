#include<iostream>
#include<stdio.h>
#include<utility>
#include<vector>
#include<algorithm>
#include<stack>
#include<string.h>
#include<queue>
#include<set>
#include<ostream>
#include<map>
#include<string>
#include<deque>

using namespace std;

long long int dp[1005][1005];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= m; i++) {
			dp[1][i] = i;
		}
		for (int i = 2; i <= n; i++) {
			for (int j = i; j <= m; j++) {
				for (int k = j; k >= i; k--) {
					dp[i][j] += dp[i - 1][k-1];
				}
			}
		}
		printf("%lld\n", dp[n][m]);
		memset(dp, 0, sizeof(dp));
	}


}