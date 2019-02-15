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
#include<math.h>
using namespace std;

int n, m;
vector<int> vec;
int arr[10000];
void dfs(int now, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < cnt; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	for (int i = now; i <= n; i++) {
		arr[cnt] = i;
		dfs(i,cnt+1);
	}

}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		arr[0] = i;
		dfs(i,1);
	}




}