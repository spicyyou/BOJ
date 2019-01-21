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

int dp[1005];
int arr[1005];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
		dp[i] = arr[i];
	}
	dp[0] = arr[0];
	for (int i = 1; i < n; i++) {
		for (int j = i-1; j >= 0; j--) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i],dp[j]+arr[i]);
			}
		}
	}
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (max < dp[i]) {
			max = dp[i];
		}
	}
	printf("%d\n", max);

}