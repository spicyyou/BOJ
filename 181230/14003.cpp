#include<iostream>
#include<stdio.h>
#include<utility>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;


long long int dp[1000005];
long long int arr[1000005];
vector<long long int> vec;
pair<long long int, long long int> tracking[1000005];
int INF = 999999;

int main() {
	long long int n;
	scanf("%lld", &n);
	for (long long int i = 0; i < n; i++) {
		scanf("%lld", arr + i);
	}
	long long int num = 0;
	vec.push_back(arr[0]);
	tracking[0].first = 0;
	tracking[0].second = arr[0];
	for (long long int i = 1; i < n; i++) {
		if (vec.back() < arr[i]) {
			vec.push_back(arr[i]);
			num++;
			tracking[i].first = num;
			tracking[i].second = arr[i];
		}
		else {
			auto lb = lower_bound(vec.begin(), vec.end(), arr[i]);//iterator¿©¾ßÇÔ
			*lb = arr[i];
			int temp = distance(vec.begin(), lb);
			tracking[i].first = temp;
			tracking[i].second = arr[i];
		}
	}
	
	int temp = num;
	stack<long long int> st;
	for (int i = n-1; i >= 0; i--) {
		if (temp == tracking[i].first) {
			st.push(tracking[i].second);
			temp--;
		}
	}
	printf("%d\n", num + 1);
	while (!st.empty())
	{
		printf("%d ", st.top());
		st.pop();
	}
}