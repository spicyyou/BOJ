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
	string a, b;
	cin >> a >> b;
	int alen = strlen(a.c_str());
	int blen = strlen(b.c_str());

	int ans = 0;
	int min = INT_MAX;
	for (int j = 0; j <= blen - alen; j++) {
		for (int i = 0; i < alen; i++) {
			if (a[i] != b[i+j]) {
				ans++;
			}
		}
		if (min > ans) {
			min = ans;
		}
		ans = 0;
	}
	cout << min << endl;

}