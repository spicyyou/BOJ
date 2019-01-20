#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;

int dp[305][305];
int main() {
	int n,m;
	cin >> n>>m;
	dp[1][1] = 0;
	for (int i = 2; i <= m; i++) {
		dp[1][i] = (i - 1);
	}
	for (int i = 2; i <= m; i++) {
		dp[i][1] = (i - 1);
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			dp[i][j] = dp[i][j - 1] + dp[i][1] + 1;
		}
	}
	printf("%d", dp[n][m]);
}