#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>
#include<string>
#include<climits>
#include<string.h>

using namespace std;


pair<int, int>  price[1005];
int main() {
	int x, y,n;
	float min= float(INT_MAX);
	int idx = 0;
	scanf("%d%d", &x, &y);
	scanf("%d", &n);
	price[0].first = x;
	price[0].second = y;
	for (int i = 1; i <= n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		price[i].first = a;
		price[i].second = b;
	}
	for (int i = 0; i <= n; i++) {
		float gram = float(price[i].first) / float(price[i].second);
		//cout << gram << endl;
		if (gram < min) {
			idx = i;
			min = gram;
		}
	}
	//cout << min << endl;
	printf("%lf", min*1000);
}