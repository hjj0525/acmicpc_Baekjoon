#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#pragma warning(disable: 4996);
#define MAX 100001


// �׸��� �˰����� ���·� Ǯ���Ͽ���
// ���� cost�� ū node�� ã�� �Ŀ�
// �� node���� ����Ͽ� �ִ밪�� ���Ͽ���.

int n; // ����� ����	
vector<pair<int, int>> tree[MAX];
// first�� ���, second�� weight
int cost[MAX] = { 0, }; // ���� ���κ��� i�������� ���µ� �ʿ��� ���
bool visited[MAX];

int maxNum = 0; // ����(diameter)�� ����
int idx; // �ִ밪�� ���� �� �ִ� �����

void DFS(int start) {
	visited[start] = true;

	for (int i = 0; i < tree[start].size();i++) {
		int next = tree[start][i].first;
		int weight = tree[start][i].second;
		if (!visited[next]) {
			visited[next] = true;
			cost[next] = cost[start] + weight;
			if (maxNum < cost[next]) {
				maxNum = cost[next];
				idx = next;
			}
			DFS(next);
		}
	}
}
int main() {
	scanf("%d", &n);
	tree->resize(n);
	for (int i = 1; i <= n; i++) {
		int a, weight;
		int	b = 0;
		cin >> a;
		while (1) {
			cin >> b;
			if (b == -1)
				break;
			cin >> weight;
			tree[a].push_back(make_pair(b, weight));
			tree[b].push_back(make_pair(a, weight));
		}
	}
	DFS(1);
	memset(visited, 0, sizeof(visited));
	memset(cost, 0, sizeof(cost));
	maxNum = 0;
	DFS(idx);

	cout << maxNum  << endl;
	return 0;
}