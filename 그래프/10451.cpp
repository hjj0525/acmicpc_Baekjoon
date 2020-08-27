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
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		for (int i = 1; i <= N; i++) {
			int num;
			cin >> num;
			adj[i].push_back(num);
		}
		int perm_cycle = 0;
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				DFS(i);
				perm_cycle++;
			}
		}
		for (int i = 0; i <= N; i++) {
			visited[i] = false;
			adj[i].clear();
		}
		cout << perm_cycle << endl;
	}
	

	return 0;
}