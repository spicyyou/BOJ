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
vector<int> vec;

int main() {
	int m;
	scanf("%d", &m);
	string str;
	while (m--) {
		char str[100];
		scanf("%s", str);
		int n;
		scanf("%d", &n);
		//getchar();
		if (strcmp(str, "add") == 0) {
			auto idx = find(vec.begin(), vec.end(), n);
			if (idx == vec.end()) {
				vec.push_back(n);
			}
		}
		else if (strcmp(str, "remove") == 0) {
			auto idx = find(vec.begin(), vec.end(), n);
			if (idx == vec.end()) {//n이 없음
			}
			else {
				//int index = idx - vec.begin();
				vec.erase(idx);
			}

		}
		else if (strcmp(str, "check") == 0) {
			auto idx = find(vec.begin(), vec.end(), n);
			if (idx != vec.end()) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}

		}
		else if (strcmp(str, "toggle") == 0) {
			auto idx = find(vec.begin(), vec.end(), n);
			if (idx == vec.end()) {//n이 없음
				vec.push_back(n);
			}
			else {
				//int index = idx - vec.begin();
				vec.erase(idx);
			}

		}
		else if (strcmp(str, "all") == 0) {
			vec.clear();
			for (int i = 1; i <= 20; i++) {
				vec.push_back(i);
			}
		}
		else if (strcmp(str, "empty") == 0) {
			vec.clear();
		}
	}
}