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
#include<climits>
#include<stdlib.h>

using namespace std;

int main() {
	int n, a, b;
	cin >> n;
	cin >> a >> b;
	int cnt = 0;
	while (n) {
		n = n / 2;
		//cout << a <<" "<< b << endl;
		if (a % 2 != 0) {
			a = (a / 2) + 1;
		}
		else {
			a = a / 2;
		}

		if (b % 2 != 0) {
			b = (b / 2) + 1;
		}
		else {
			b = b / 2;
		}
		cnt++;
		if (a == b) {
			cout << cnt << endl;
			return 0;
		}
	}
	printf("-1\n");
}