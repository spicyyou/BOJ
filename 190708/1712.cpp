#include<stdio.h>

int main() {
	long long int a, b, c;
	scanf("%lld%lld%lld", &a, &b, &c);
	if (c - b != 0) {
		int res = a / (c - b);
		int mod = a % (c - b);
		int ans = 0;
		//printf("mod : %d\n", mod);
		if (res < 0) {
			ans = 0;
		}
		/*else if (mod == 0) {
			ans = res;
		}*/
		else {
			ans = res + 1;
		}
		if (ans == 0) {
			printf("-1\n");
		}
		else {
			printf("%d\n", ans);
		}
	}
	else {
		printf("-1\n");
	}
}