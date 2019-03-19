#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>

int dx[5] = { -1,-2,1,2 };
using namespace std;
int arr[1005];
int ans;

int main() {
	int t = 1;
	//FILE *fd;
	//fd = fopen("input.txt", "r");
	while (t<11) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		for (int i = 2; i <= n-3; i++) {
			int min = 9999999;
			for (int j = 0; j < 4; j++) {
				int temp = arr[i] - arr[i+dx[j]];
				if (min > temp) {
					if (temp < 0) {
						min = 0;
						continue;
					}
					min = temp;
				}
			}
			ans+= min;
		}
		printf("#%d %d\n", t, ans);
		ans = 0;
		memset(arr, 0, sizeof(arr));
		t++;
	}
	//fclose(fd);

}