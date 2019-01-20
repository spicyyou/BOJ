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

int dp[305];
int main() {
	int n;
	cin >> n;
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + 2;
	}
	printf("%d", dp[n]);
}