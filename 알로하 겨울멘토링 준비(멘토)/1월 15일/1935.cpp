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
int cost[100];
stack<double> st;
int main(){
	int n;
	cin >> n;
	cin >> temp;
	for (int i = 0; i < n; i++) {
		scanf("%d", cost + i);
	}
	double sum = 0;
	for (int i = 0; i < temp.length(); i++) {
		if (temp[i] <= 'Z'&&temp[i] >= 'A') {
			st.push(cost[temp[i] - 65]);
		}
		else {
			double b = st.top();
			st.pop();
			double a = st.top();
			st.pop();
			if (temp[i] == '+') {
				st.push(a + b);
			}
			else if (temp[i] == '*') {
				st.push(a*b);
			}
			else if (temp[i] == '/') {
				st.push(a/b);
			}
			else if (temp[i] == '-') {
				st.push(a - b);
			}
		}
	}

	printf("%.2lf", st.top());
}