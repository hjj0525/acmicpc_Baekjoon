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
	// ���� �湮�� ���� �ʾҴٸ�
	if (!visited[next]) {
		DFS(next);
	}
	// �̹� �湮�� �� ���¶��
	else {
		if (!finished[next]) {
			// 1->2->3->1 �� ����Ŭ�� �����Ǿ��ٸ�
			// 3 �� x�� �ش��ϰ�, 1�� next
			// 
			for (int i = next; i != x; i = adj[i][0])
				cnt++;
			cnt++;
		}
	}
	// ����Ŭ �����̶�� else�� ����, 
	// ���� ���ж�� finished[next]���� �ɷ����鼭 ����Լ� Ż��
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