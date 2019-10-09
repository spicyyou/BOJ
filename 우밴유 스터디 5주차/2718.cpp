#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>
#include<string>
#include<climits>
#include<string.h>

using namespace std; 
int dp[501][15];
//0000,1100,0011,1001
int tile(int n, char bit) {
	if (n ==-1 ) return 0;
	if (n ==0) return !bit;
	//dp[n][bit];
	if (dp[n][bit] != -1) return dp[n][bit];
	dp[n][bit] = 0;
	switch (bit)
	{
		case 0:
			dp[n][bit] = tile(n - 1, 0) + tile(n - 1, 3) + tile(n - 1, 9) + tile(n - 1, 12) + tile(n - 2, 0);
			break;	
		case 3:
			dp[n][bit] = tile(n - 1, 0) + tile(n - 1, 12);
			break;
		case 6:
			dp[n][bit] = tile(n - 1, 9);
			break;
		case 9:
			dp[n][bit] = tile(n - 1, 0) + tile(n - 1, 6);
			break;
		case 12:
			dp[n][bit] = tile(n - 1, 0) + tile(n - 1, 3);
			break;
	}
	return dp[n][bit];
}

int main() {
	int t, n;
	scanf("%d", &t);
	memset(dp, -1, sizeof(dp));
	while (t--) {
		scanf("%d", &n);
		printf("%d\n", tile(n, 0));
	}
	return 0;
}
/*int res = 0;
// 0000,1100,0011,1001
int tile(int n, int bit) {
	if (n == 0) {	}
	
	switch (bit) {
	case 0:
		res = tile(n - 1, 0) + tile(n - 1, 3) + tile(n - 1, 9) + tile(n - 1, 12) + tile(n - 2, 0);
	case 3:
		res = tile
	}
}


int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		res = 0;
	}
}*/