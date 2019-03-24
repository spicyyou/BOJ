#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>

using namespace std;
int arr[1005];
int main() {
	int t = 1;
	FILE *fd;
	fd = fopen("input.txt", "r");
	while (t<11) {
		int n;
		//fscanf(fd,"%d", &n);
		scanf("%d", &n);
		for (int i = 0; i < 100; i++) {
			//fscanf(fd,"%d", &arr[i]);
			scanf("%d", &arr[i]);
		}
		sort(arr, arr + 100);
		for (int i=0;i<n;i++) {
			arr[0]++;
			arr[99]--;
			sort(arr, arr + 100);
			//if (arr[99] - arr[0] + 2 == 0 || arr[99] - arr[0] + 2 == 0) break;
		}
		printf("#%d %d\n",t, arr[99] - arr[0]);
		//memset(arr, 0, sizeof(arr));
		t++;
	}
	//fclose(fd);

}