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
#include<stdlib.h>

using namespace std;
long long int arr[10000005];
vector<long long > vec;
long long a, b;
void sosu() {
	for (long long int i = 2; i*i <= b; i++) {
		if (arr[i] == 0) // 이미 체크된 수의 배수는 확인하지 않는다
			continue;

		for (long long int j = i + i; j <= b; j += i) { // i를 제외한 i의 배수들은 0으로 체크
			arr[j] = 0;
		}
	}
}

int palin(long long v) {
	string temp=to_string(v);
	long long int left = 0, right = strlen(temp.c_str()) - 1;
	while (left < right) {
		if (temp[left] == temp[right]) {
			left++;
			right--;
		}
		else {
			return -1;
		}
	}
	return 1;
}


int main() {
	scanf("%lld%lld", &a, &b);
	if (b > 10000000) {
		b = 10000000;
	}
	for (long long int i = 2; i <= b; i++) {
		arr[i] = i;
	}
	sosu();
	/*for (long long int i = a; i <= b; i++) {
		if (arr[i] != 0) {
			cout <<i<<" "<< arr[i] << endl;
		}
	}*/
	for (long long int i = a; i <= b; i++) {
		if (arr[i] != 0) {
			if (palin(i) == 1) {
				printf("%lld\n", i);
			}
		}
	}
	printf("-1\n");
}