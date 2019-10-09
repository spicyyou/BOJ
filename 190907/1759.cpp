#include<stdio.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<iostream>

using namespace std;

char temp[105],combi[105];
int l, c;
void dfs(int start, int depth) {
	if (depth == l) {
		int flag = 0;
		int cnt = 0;
		for (int i = 0; i < l; i++) {
			if (combi[i] == 'a' || combi[i] == 'e' || combi[i] == 'o' || combi[i] == 'i' || combi[i] == 'u') {
				flag = 1;
			}
			else {
				cnt++;
			}
			if (flag&&cnt >= 2)break;
		}
		if (flag == 1&&cnt>=2) {
			for (int i = 0; i < l; i++) {
				cout << combi[i];
			}
			cout << endl;
		}
	}
	for (int i = start; i < c; i++) {
		combi[depth] = temp[i];
		dfs(i + 1, depth + 1);
	}

}
int main() {
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		cin >> temp[i];
	}
	sort(temp, temp + c);
	dfs(0, 0);

	//printf("%c", pq.top().second);
}