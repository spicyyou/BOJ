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

vector<int> adj[500];

void pre(char a) {
	printf("%c", a);
	if(adj[a][0]!='.')
		pre(adj[a][0]);
	if(adj[a][1]!='.')
		pre(adj[a][1]);
}
void mid(char a) {

	if (adj[a][0] != '.')
		mid(adj[a][0]);
	printf("%c", a);
	if (adj[a][1] != '.')
		mid(adj[a][1]);
}
void last(char a) {

	if (adj[a][0] != '.')
		last(adj[a][0]);
	if (adj[a][1] != '.')
		last(adj[a][1]);
	printf("%c", a);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char a, b, c;
		cin >> a >> b >> c;
			adj[a].push_back(b);
			adj[a].push_back(c);
		
	}
	pre('A');
	printf("\n");
	mid('A');
	printf("\n");
	last('A');
	printf("\n");
}