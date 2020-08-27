#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#pragma warning(disable: 4996);
using namespace std;

const int MAX = 300000;

int visited[MAX] = { 0, };
vector<int> adj[MAX];

void DFS(int x, int y) {
	visited[x]++;
	if (visited[x] == 3)
		return;
	int next = 0;

	while (x) {
		next += (int)pow((x % 10), y);
		x /= 10;
	}
	DFS(next, y);
}
int main() {
	int A, P;
	cin >> A >> P;
	DFS(A, P);
	int cnt = 0;
	for (int i = 0; i < MAX;i++) {
		if (visited[i] == 1)
			cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}