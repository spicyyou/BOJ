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
typedef struct dij {
	int w;
};
int adj[105][105];
int dis[105][105];
int drow[] = { 0,0,-1,1 };
int dcol[] = { 1,-1,0,0 };
//vector<pair<int, int > > adj[1005];
int INF = 99999999;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &adj[i][j]);
		}
	}
	priority_queue<pair<int, pair<int, int> >> pq;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			dis[i][j] = INF;
		}
	}
	pq.push({ adj[0][0],{0,0} });
	dis[0][0] = 0; 
	while (!pq.empty()) {
		int r = pq.top().second.first; //row
		int c = pq.top().second.second;
		int w = -pq.top().first;
		pq.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + drow[i];
			int nc = c + dcol[i];
			if (nr < 0 || nc < 0 || nr >=m|| nc >= n) continue;
			int nw = w + adj[nr][nc];
			if (dis[nr][nc] > nw) {
				dis[nr][nc] = nw;
				pq.push({ -nw,{nr,nc} });
			}
		}
	}
	/*for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", dis[i][j]);
		}
		cout << endl;
	}*/
	printf("%d\n", dis[m - 1][n - 1]);

}