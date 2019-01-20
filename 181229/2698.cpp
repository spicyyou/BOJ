#include<iostream>
#include<stdio.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {

		int n, k;
		cin >> n >> k;

		int dp[205][205][2] = { 0 };
		dp[1][0][1] = 1; // 1
		dp[1][0][0] = 1;
		for (int k = 0; k < 100; k++) {
			for (int n = 2; n <= 100; n++) {
				if (k == 0) {
					dp[n][k][1] += dp[n - 1][k][0];
				}
				else {
					dp[n][k][1] += dp[n - 1][k][0] + dp[n - 1][k - 1][1];
				}
				dp[n][k][0] += dp[n - 1][k][0] + dp[n - 1][k][1];
			}
		}
		printf("%d\n", dp[n][k][1] + dp[n][k][0]);
	}
}