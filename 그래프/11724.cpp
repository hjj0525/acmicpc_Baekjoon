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
	int n, m; // n�� ����, m�� ����
	int start;
	cin >> n >> m ;
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v); // u -> v
		adj[v].push_back(u); // v -> u
	}
	int components = 0; // ���� ���
	for (int i = 1; i <= n; i++) { // 1��~n�� ������ ��ȸ
		if (!visited[i]) {
			DFS(i);
			components++;
		}
	}
	printf("%d\n", components);

	return 0;
}