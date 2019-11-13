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
long long int arr[5005];



int main() {
	string s;
	cin >> s;
	int len = strlen(s.c_str());
	int a = int(s[0])-48;
	int b = 1;
	//cout << a << endl;
	if (len == 1) {
		printf("NO\n");
		return 0;
	}
	for (int i = 1; i < len; i++) {
		b *= (int(s[i])-48);
	}
	int idx = 1;
	while (1) {
		//cout << "a: " << a << " b " << b << endl;
		if (a == b) {
			printf("YES\n"); return 0;
		}
		if (idx == len - 1) break;
		a *= (int(s[idx])-48);
		if (b == 0 && int(s[idx]) - 48 != 0) {
			b = 0;
		}
		else if (b == 0 && int(s[idx] - 48 == 0)) {
			b = 1;
			for (int i = idx + 1; i < len; i++) {
	
				b *= int(s[i]) - 48;
			}
		}
		else {
			b /=(int(s[idx]) - 48);
		}
		idx++;
	}
	printf("NO\n");
}