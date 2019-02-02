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

int n[1005];
int dp[10005][1005];
int p[10005];
int main() {
	int t, k;
	cin >> t >> k;
	for (int i = 1; i <= k; i++) {
		scanf("%d %d", p + i, n + i);
	}
	for (int i = 1; i <= k; i++) {
		dp[0][i - 1] = 1;
		for (int j = 1; j <= n[i]; j++) {//사용되는 동전의 갯수
			for (int now = p[i] * j; now <= t; now++) {
				dp[now][i] += dp[now - p[i] * j][i - 1];
			}
		}
		for (int j = 1; j <= t; j++) {
			dp[j][i] += dp[j][i - 1];
		}

	}
	printf("%d\n", dp[t][k]);
}