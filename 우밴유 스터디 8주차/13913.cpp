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

int dp[200005];
int dx[4] = { 0,1,-1,2 };
queue<pair<int, pair<int, int>> > q;
int vec[200005];
vector<int> v;
int main() {
	int n, k;
	scanf("%d%d", &n,&k);

	q.push({ n,{0,-1} });
	vec[0] = n;
	dp[n] = 1;
	int ans;
	while (!q.empty()) {
		int first = q.front().first;
		int second = q.front().second.first;
		//vec[second] = first;	
		dp[first] = 1;
		q.pop();
		if (first == k) {
			ans = second;
			break;
		}
		for (int i = 1; i <= 3; i++) {
			int next;
			if (dx[i] == 2) {
				next = dx[i] *first;
			}
			else {
				next = dx[i] + first;
			}
			if (next < 0||next>=200000||dp[next]!=0||next==n) continue;
			dp[next] = 1;
			vec[next] = first;
			q.push({ next,{second + 1,first} });
		}
	}
	
	printf("%d\n", ans);
	vec[n] = -1;
	int idx = k;
	v.push_back(k);
	while (1) {
		idx= vec[idx];
		if (idx == -1) break;
		v.push_back(idx);
	}
	for (int i = v.size()-1; i >= 0; i--) {
		printf("%d ", v[i]);
	}
}