#include<iostream>
#include<stdio.h>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;
int dp[1005];

pair<int, int> p;
vector<pair<int, int> > vec;
int main() {
	long long int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		p.first = a;
		p.second = b;
		vec.push_back(p);
	}
	dp[0] = 1;
	sort(vec.begin(), vec.end());
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (vec[i].second > vec[j].second) {
				dp[i] = max(dp[i], dp[j]);
			}
		}
		dp[i] += 1;
	}
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (max < dp[i]) {
			max = dp[i];
		}
	}
	printf("%d\n", n-max);
}