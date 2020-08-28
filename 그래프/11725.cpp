#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
#pragma warning(disable: 4996);
#define MAX 100001

vector<vector<int>> v;
int visited[MAX];
int parent[MAX];
int main() {
	int N;
	scanf("%d", &N);
	v.resize(N + 1);

	// 입력
	for (int i = 0; i < N-1; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	//BFS
	queue<int> Q;
	Q.push(1);
	visited[1] = true;

	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();

		for (int i = 0; i < v[x].size(); i++) {
			if (!visited[v[x][i]]) {
				parent[v[x][i]] = x;
				visited[v[x][i]] = true;
				Q.push(v[x][i]);
			}
		}
	}

	// 출력
	for (int i = 2; i <= N; i++) {
		cout << parent[i] << "\n";
	}
	return 0;
}