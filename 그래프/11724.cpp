#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#pragma warning(disable: 4996);
using namespace std;

const int MAX = 1001;

bool visited[MAX];
vector<int> adj[MAX];

void DFS(int x) {
	visited[x] = true;
	for (int y : adj[x]) {
		if (!visited[y])
			DFS(y);
	}
}

int main() {
	int n, m; // n은 정점, m은 간선
	int start;
	cin >> n >> m ;
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v); // u -> v
		adj[v].push_back(u); // v -> u
	}
	int components = 0; // 연결 요소
	for (int i = 1; i <= n; i++) { // 1번~n번 정점을 순회
		if (!visited[i]) {
			DFS(i);
			components++;
		}
	}
	printf("%d\n", components);

	return 0;
}