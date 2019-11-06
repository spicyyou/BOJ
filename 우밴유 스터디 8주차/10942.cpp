#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
#include<queue>


using namespace std;

int arr[2005];
int dp[2005][2005];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	int m;
	scanf("%d", &m);
	for (int i = 0; i < n; i++) {
		dp[i][i] = 1;
	}
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] == arr[i + 1]) {
			dp[i][i + 1] = 1;
		}
	}
	for (int len = 2; len <= n - 1; len++) {
		for (int k = 0; k <= n - len; k++) {
			int j = len + k;
			if (arr[j] == arr[k] && dp[k + 1][j - 1] == 1) {
				dp[k][j] = 1;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", dp[a - 1][b - 1]);
	}
}