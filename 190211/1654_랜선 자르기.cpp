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
#include<climits>

using namespace std;

int lan[10005];
int k, n;

long long int para(long long int left, long long int right) {
	long long int mid = (left + right) / 2;
	long long int cnt = 0;
	if (left <= right) {
		for (int i = 0; i < k; i++) {
			cnt += lan[i] / mid;
		}
		if (cnt >= n) { return para(mid+1, right); }
		else { return para(left, mid - 1); }
	}
	return right;
}

int main() {
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		scanf("%d", lan + i);
	}
	long long int res = para(1, INT_MAX);
	printf("%lld\n", res);
}