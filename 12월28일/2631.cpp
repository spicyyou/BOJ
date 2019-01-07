#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int arr[250];
int dp[250];
int main(){
	int n;
	cin >> n;
	int i = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
		
	}
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j]);
			}
		}
		dp[i]++;
	}
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (max < dp[i]) {
			max = dp[i];
		}
	}

	printf("%d\n", n-max);
}