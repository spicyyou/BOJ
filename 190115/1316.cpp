#include<iostream>
#include<stdio.h>
#include<utility>
#include<vector>
#include<algorithm>
#include<stack>
#include<string.h>
#include<queue>
#include<set>
#include<ostream>
#include<map>
#include<string>
#include<deque>

using namespace std;

string temp;
int check[105];
int main() {
	int n;
	cin >> n;
	int res = 0;
	for (int i = 0; i < n; i++) {
		memset(check, -1, sizeof(check));
		int flag = 0;
		cin >> temp;
		for (int j = 0; j < temp.length(); j++) {
			if (check[temp[j]-97] == -1) {
				check[temp[j]-97] = j;
			}
			else {
				if(temp[j]!=temp[j-1]){
					flag = 1;
					break;
				}
			}
		}
		if (flag == 0) {
			res++;
		}
	}
	cout << res << endl;

}