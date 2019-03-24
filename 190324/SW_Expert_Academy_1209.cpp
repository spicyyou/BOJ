#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>

using namespace std;

int arr[105][105];
int row[105];
int col[105];
int cross[3];
int main() {
	//FILE * fd;
	//fd = fopen("input.txt", "r");
	for (int t = 1; t <= 10; t++) {
		int n;
		//fscanf(fd,"%d", &n);
		scanf("%d", &n);
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				//fscanf(fd,"%d", &arr[i][j]);

				scanf("%d", &arr[i][j]);
			}
		}
		int max_ = 0;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				row[i] += arr[i][j];
				if (row[i] > max_) {
					max_ = row[i];
				}
			}
		}
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				col[i] += arr[j][i];
				if (col[i] > max_) {
					max_ = col[i];
				}
			}
		}
		for (int i = 0; i < 100; i++) {
			cross[0] += arr[i][i];
		}
		for (int i = 99; i >= 0; i--) {
			cross[1] += arr[i][i];
		}
		int temp = max(cross[0], cross[1]);
		max_ = max(temp, max_);
		printf("#%d %d\n",t, max_);
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		memset(cross, 0, sizeof(cross));

	}



}