#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#pragma warning(disable: 4996);
#define MAX 10001


// 그리디 알고리즘의 형태로 풀이하였음
// 제일 cost가 큰 node를 찾은 후에
// 그 node에서 출발하여 최대값을 구하였다.

int n; // 노드의 갯수	
vector<pair<int, int>> tree[MAX];
// first는 노드, second는 weight
int cost[MAX] = { 0, }; // 시작 노드로부터 i번노드까지 가는데 필요한 비용
bool visited[MAX];

int maxNum = 0; // 지름(diameter)와 동일
int idx; // 최대값을 가질 수 있는 출발점

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
	for (int i = 1; i < n; i++) {
		int a, b, weight;
		cin >> a >> b >> weight;
		tree[a].push_back(make_pair(b, weight));
		tree[b].push_back(make_pair(a, weight));
	}
	DFS(1);
	memset(visited, 0, sizeof(visited));
	memset(cost, 0, sizeof(cost));
	maxNum = 0;
	DFS(idx);

	cout << maxNum  << endl;
	return 0;
}