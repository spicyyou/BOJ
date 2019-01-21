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

using namespace std;

typedef struct cur {
	int row;
	int col;
	int state;
};

int arr[1005][1005];
int visit[1005][1005][3];
int drow[4] = { 0,0,1,-1 };
int dcol[4] = { -1,1,0,0 };
queue<cur> q;

int main() {

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	//int flag = 0;
	int result = -1;
	cur c;
	c.row = 0, c.col = 0, c.state = 0;
	q.push(c);
	visit[0][0][0] = 1;
	while (!q.empty()) {
		auto now = q.front();
		q.pop();
		if (now.row == n - 1 && now.col == m - 1) {
			//flag = 1;
			result = visit[now.row][now.col][now.state];
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nrow = now.row + drow[i];
			int ncol = now.col + dcol[i];
			if (nrow >= n || ncol >= m || nrow < 0 || ncol < 0) continue;
			cur temp;
			temp.row = nrow, temp.col = ncol;
			int br = now.state;
			if (arr[nrow][ncol] == 1 && now.state == 0) {//벽이 있고 벽을 안뿌셨을때
				br = 1;
				visit[nrow][ncol][br] = visit[now.row][now.col][br - 1] + 1;
				temp.state = br;
				q.push(temp);
			}
			else if (arr[nrow][ncol] == 0 && visit[nrow][ncol][now.state] == 0) {
				visit[nrow][ncol][br]=visit[now.row][now.col][br]+1;
				temp.state = br;
				q.push(temp);
			}

		}
		
	}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", visit[i][j][0]);
		}
		printf("\n");
	}*/
	if (n == 1 && m == 1) {
		printf("1\n");
		return 0;
	}
	printf("%d\n", result);