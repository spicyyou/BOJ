#include<stdio.h>
#include<algorithm>

using namespace std;
int dp[5005];

int main() {
	int n;
	scanf("%d", &n);
	if (n % 5 == 0) {
		printf("%d\n", n / 5);
		return 0;
	}
	int res = 0;
	for (int i = 0; i <= (n / 5); i++) {
		if ((n - 5 * i) % 3 == 0) {
			res = i + (n - 5 * i) / 3;
		}
	}
	if (res != 0) {
		printf("%d\n", res);
		return 0;
	}
	printf("-1\n");
}