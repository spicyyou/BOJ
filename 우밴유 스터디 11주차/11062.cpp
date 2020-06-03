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
int input[1005];
int DP[2][1005][1005];

int func(int turn, int left, int right) {
	if (left == right) {
		if (turn == 0) {
			return input[left];
		}
		else {
			return 0;
		}
	}
	if (DP[turn][left][right]!=-1) {
		return DP[turn][left][right];
	}

	if (turn == 0) {
		DP[turn][left][right] = max(func(1, left + 1, right)+input[left], func(1, left, right - 1)+input[right]);
	}
	else {
		DP[turn][left][right] = min(func(0, left + 1, right), func(0, left, right - 1));
	}
	return DP[turn][left][right];

}


int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int N;
		scanf("%d", &N);
		memset(DP, -1, sizeof(DP));
		for (int i = 0; i < N; i++) {
			scanf("%d", &input[i]);
		}

		int ans = func(0, 0, N - 1);
		printf("%d\n", ans);
		memset(input, 0, sizeof(input));
	}
}