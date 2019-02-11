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

int region[10005];
long long int n, m;
int max = 0;
long long int para(long long int left, long long int right) {
	long long int mid = (left + right) / 2;
	long long int res = 0;
	if (left <= right) {
		for (int i = 0; i < n; i++) {
			if (region[i] - mid < 0) res += region[i];
			else {
				res += mid;
			}
		}
		if (res <= m) { return para(mid + 1, right); }
		else { return para(left, mid - 1); }
	}
	return right;
}

int main() {
	cin >> n;
	int max = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", region + i);
		sum += region[i];
		if (max < region[i])max = region[i];
	}
	cin >> m;
	//cout << sum << " " << m << endl;
	if (sum <= m) {
		printf("%d\n", max);
		return 0;
	}
	long long int res = para(1,1000000000);
	printf("%lld\n", res);
}