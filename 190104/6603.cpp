#include<iostream>
#include<stdio.h>
#include<utility>
#include<vector>
#include<algorithm>
#include<stack>
#include<string.h>
#include<queue>
using namespace std;
int lotto[20];
int combi[20];
int n;

void dfs(int start, int depth) {

	if (depth == 6) {                    //탈출조건
		for (int i = 0; i<6; i++) {
			cout << combi[i] << ' ';    //조합하나를 출력한 뒤 탈출
		}
		cout << '\n';
		return;
	}

	for (int i = start; i<n; i++) {    //lotto배열 0부터 k-1까지 탐색함     
		combi[depth] = lotto[i];    //depth는 깊이 -> 0~5번째 깊이까지 재귀를통해 새로 탐색한 숫자를 넣음.    
		dfs(i + 1, depth + 1);            //재귀 들어가는 부분 , 하나의 깊이를 탐색 후 저장했으니 다음 함수호출할때는 깊이+1을 해줘야함.
	}

}


int main() {
	while (1) {
		scanf("%d", &n);
		if (n == 0) { break; }
		for (int i = 0; i < n; i++) {
			scanf("%d", lotto + i);
		}

		dfs(0, 0);
		printf("\n");
	}




}