#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;

char A[150];
char B[150];
char C[150];
int dp[150][150][150];
int dp2[150][150];
int main() {
	cin >> A >> B >> C;
	int alen = strlen(A);
	int blen = strlen(B);
	int clen = strlen(C);
	for (int i = 1; i <= alen; i++) {
		for (int j = 1; j <= blen; j++) {
			for (int k = 1; k <= clen; k++)
			{
				if (A[i-1]==B[j-1]&&B[j-1]==C[k-1]){
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				}
				else {
					dp[i][j][k] = max(dp[i - 1][j][k], dp[i][j - 1][k]);
					dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1]);
				}
			}
		}
	}
	printf("%d\n", dp[alen][blen][clen]);
}	