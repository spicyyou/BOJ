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

long long int find5num(long long int n) {
	long long int cnt = 0;
	for (long long int i = 5; n / i >= 1; i *= 5) {
		cnt += n / i;
	}
	return cnt;
}

long long int find2num(long long int n) {
	long long int cnt = 0;
	for (long long int i = 2; n / i >= 1; i *= 2) {
		cnt += n / i;
	}
	return cnt;
}

int main() {
	long long int n, m;
	scanf("%lld%lld", &n, &m);
	long long int ans5 = find5num(n) - find5num(m) - find5num(n - m);
	long long int ans2 = find2num(n) - find2num(m) - find2num(n - m);
	printf("%lld\n", min(ans5, ans2));
}