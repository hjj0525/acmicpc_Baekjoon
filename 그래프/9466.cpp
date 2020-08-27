#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define NUM 100001

vector<int> adj[NUM];
bool visited[NUM];
bool finished[NUM];
int cnt;
void DFS(int x) {
	visited[x] = true;
	int next = adj[x][0];
	// 만약 방문을 하지 않았다면
	if (!visited[next]) {
		DFS(next);
	}
	// 이미 방문을 한 상태라면
	else {
		if (!finished[next]) {
			// 1->2->3->1 의 싸이클이 형성되었다면
			// 3 은 x에 해당하고, 1이 next
			// 
			for (int i = next; i != x; i = adj[i][0])
				cnt++;
			cnt++;
		}
	}
	// 싸이클 형성이라면 else문 돌고, 
	// 형성 실패라면 finished[next]에서 걸러지면서 재귀함수 탈출
	finished[x] = true;
}
int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int num;
			cin >> num;
			adj[i].push_back(num);
		}
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (!visited[i])
				DFS(i);
		}
		cout << n - cnt << endl;

		for (int i = 1; i <= n; i++) {
			adj[i].clear();
			visited[i] = false;
			finished[i] = false;
		}
	}
	return 0;
}