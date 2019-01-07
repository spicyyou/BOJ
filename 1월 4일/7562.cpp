#include<iostream>
#include<stdio.h>
#include<utility>
#include<vector>
#include<algorithm>
#include<stack>
#include<string.h>
#include<queue>
using namespace std;

int dx[] = {-2,-1,1,2,-2,2,-1,1};//col로 이동
int dy[] = {-1,-2,-2,-1,1,1,2,2};//row로 이동

int adj[305][305];
int visit[305][305];

queue<pair<int  ,int>> q;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int I;
		scanf("%d", &I);
		memset(visit, -1, sizeof(visit));
		int st_row, st_col;
		scanf("%d%d", &st_row, &st_col);
		int dt_row, dt_col;
		scanf("%d%d", &dt_row, &dt_col);
		q.push({ st_row,st_col });
		visit[st_row][st_col] = 0;
		int flag = 0;
		while (!q.empty()) {
			pair<int, int> u;//row,col
			u = q.front();
			q.pop(); 
			if (u.first == dt_row &&u.second == dt_col) {
				flag = 1;
				break;
			}
			for (int i = 0; i < 8; i++) {
				int ncol = u.second + dx[i];//col
				int nrow = u.first + dy[i];
				if (ncol < 0 || nrow<0 || ncol>=I || nrow>=I) continue;
				if (visit[nrow][ncol] == -1) {
					visit[nrow][ncol]=(visit[u.first][u.second] +1);
					q.push({ nrow,ncol });
				}
			}
			if (flag == 1) {
				break;
			}
		}
		printf("%d\n", visit[dt_row][dt_col]);
		while (!q.empty())q.pop();

	}
}