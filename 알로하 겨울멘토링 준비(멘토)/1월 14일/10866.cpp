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

//char temp[105];
string temp;
deque<int> deq;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		//scanf("%s", temp);
		cin >> temp;
		if (temp == "push_back") {
			int n;
			scanf("%d", &n);
			deq.push_back(n);
		}
		else if (temp == "push_front") {
			int n;
			scanf("%d", &n);
			deq.push_front(n);
		}
		else if (temp == "pop_front") {
			if (!deq.empty()) {
				cout << deq.front() << endl;
				deq.pop_front();
			}
			else {
				cout << "-1" << endl;
			}
		}
		else if (temp == "pop_back") {
			if (!deq.empty()) {
				cout << deq.back() << endl;
				deq.pop_back();
			}
			else {
				cout << "-1" << endl;
			}

		}
		else if (temp == "size") {
			cout << deq.size()<<endl;
		}
		else if (temp == "empty") {
			cout << deq.empty() << endl;
		}
		else if (temp == "front") {
			if (!deq.empty()) {
				cout << deq.front() << endl;
			}
			else {
				cout << "-1" << endl;
			}
		}
		else if (temp == "back") {
			if (!deq.empty()) {
				cout << deq.back() << endl;
			}
			else {
				cout << "-1" << endl;
			}
		}
	}



}