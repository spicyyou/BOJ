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
#include<climits>
#include<stdlib.h>

using namespace std;

int arr[100005];
int dp[100005];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	dp[0] = arr[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i-1], 0)+arr[i];
	}
	/*for (int i = 0; i < n; i++) {
		cout << dp[i] << " ";
	}
	cout << endl;*/
	int maximum = -1005;
	for (int i = 0; i < n; i++) {
		if (maximum < dp[i]) {
			maximum = dp[i];
		}
	}
	printf("%d\n", maximum);
}