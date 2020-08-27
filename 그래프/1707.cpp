#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

static int RED = 1;
static int BLUE = -1;

vector<int> adj[20001];
int visited[20001];
int colors[20001];
bool isBipartite;

void DFS(int x, int color) {
	colors[x] = color;

	for (int y : adj[x]) {
		// ���� ���� �����ϴٸ� Ż��
		if (colors[y] == color) {
			isBipartite = false;
			return;
		}
		// ���� ���� �������� �ʾҴٸ�, DFS
		if (colors[y] == 0)
			DFS(y, -color);
	}
}
int main() {
	int K;
	cin >> K;
	
	while (K--) {
		int V, E;
		cin >> V >> E;
		isBipartite = true;
		for (int i = 1; i <= V; i++) {
			colors[i] = 0;
			adj[i].clear();
		}
		for (int i = 0; i < E; i++) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		
		// ���� ���� ��Ұ� �ƴ� ���� �ֱ� ������ ��� ���� Ž��
		for (int i = 1; i <= V; i++) {
			// �̺� �׷����� �ƴ϶�� Ż��
			if (!isBipartite)
				break;
			
			if (colors[i] == 0)
				DFS(i, RED);
		}
		isBipartite ? cout << ("YES") << endl : cout << ("NO") << endl;
	}
	
	return 0;
}