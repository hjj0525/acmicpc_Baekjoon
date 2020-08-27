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
queue<int> Q;
stack<int> S;
void DFS(int x) {
	visited[x] = true;
	printf("%d ", x);
	for (int y : adj[x]) {
		if (!visited[y])
			DFS(y);
	}
}
void DFS_STACK(int x) {
	S.push(x);
	visited[x] = true;
	printf("%d ", x);
	while (!S.empty()) {
		int target = S.top();
		bool allVisit = true;
		for (int i = 0; i < adj[target].size(); i++) {
			if (!visited[adj[target][i]]) {
				allVisit = false;
				visited[adj[target][i]] = true;
				printf("%d ", adj[target][i]);
				S.push(adj[target][i]);
				break;
			}
		}			
		if(allVisit) {
				S.pop();
		}
	}
}
void BFS(int sx) {
	Q.push(sx);
	visited[sx] = true;
	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();
		printf("%d ", x);
		for (int y : adj[x]) {
			if (!visited[y]) {
				Q.push(y);
				visited[y] = true;
			}
		}
	}
}
int main() {
	int n, m; // n은 정점, m은 간선
	int start;
	cin >> n >> m >> start;
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v); // u -> v
		adj[v].push_back(u); // v -> u
	}
	for (int i = 1; i < n; i++)
		sort(adj[i].begin(), adj[i].end());
	DFS_STACK(start);
	printf("\n");
	for (int i = 0; i < MAX; i++)
		visited[i] = false;
	//memset(visited, 0, sizeof(visited)); 
	// 특정 메모리 시작점부터 연속된 범위를 ~으로 지정
	// for문 보다 빠른 속도가 나올 수도 있다.
	BFS(start);
	printf("\n");

	return 0;
}