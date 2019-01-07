#include<iostream>
#include<stdio.h>

using namespace std;
int dp[1000005];
int main() {
	int mod = 9901;
	int n;
	cin >> n;
	dp[1] = 3;
	dp[2] = 7;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 2] + dp[i - 1] * 2)%mod;
	}
	printf("%d\n", dp[n]%mod);
}