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

	if (depth == 6) {                    //Ż������
		for (int i = 0; i<6; i++) {
			cout << combi[i] << ' ';    //�����ϳ��� ����� �� Ż��
		}
		cout << '\n';
		return;
	}

	for (int i = start; i<n; i++) {    //lotto�迭 0���� k-1���� Ž����     
		combi[depth] = lotto[i];    //depth�� ���� -> 0~5��° ���̱��� ��͸����� ���� Ž���� ���ڸ� ����.    
		dfs(i + 1, depth + 1);            //��� ���� �κ� , �ϳ��� ���̸� Ž�� �� ���������� ���� �Լ�ȣ���Ҷ��� ����+1�� �������.
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