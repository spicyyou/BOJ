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
#include<climits>
#include<stdlib.h>

using namespace std;

int main() {
	int n, h;
	scanf("%d%d", &n, &h);
	vector<int> seok;
	vector<int> jong;
	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		if (i % 2 == 0) {

			jong.push_back(a);
		}
		else {
			seok.push_back(a);
		}
	}
	sort(jong.begin(), jong.end());
	sort(seok.begin(), seok.end());
	int section = 1;
	int mini = INT_MAX;
	for (int i = 1; i <= h; i++) {
		int ans1 = seok.size() -( lower_bound(seok.begin(), seok.end(), i)-seok.begin());
		int ans2 = jong.size() - (upper_bound(jong.begin(), jong.end(), h - i) - jong.begin());
		//cout << ans1 << " " << ans2 << endl;
		if (mini > ans1 + ans2) {
			mini = ans1 + ans2;
			section = 1;
		}
		else if (mini==ans1+ans2) {
			section++;
		}
	}
	printf("%d %d\n", mini, section);

}