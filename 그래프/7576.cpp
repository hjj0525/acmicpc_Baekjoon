#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1001
using namespace std;


bool visited[MAX][MAX];
int m, n; // m�� ����, n�� ���� 2~1000
// �� �� �� ��
int dx[4] = { 0, 0, 1 ,-1 };
int dy[4] = { 1, -1, 0, 0 };
int map[MAX][MAX];

int main() {
	bool isRipe = true;
	int tomatoNum = 0;
	queue<pair<int, int>> q;
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j]; // i�� ����, j�� ����
			// 1�� ���� ����, 0�� ��������, -1�� �丶�䰡 ������� ����
			if (map[i][j] == 0)
				isRipe = false;
			if (map[i][j] == 1) {
				q.push(make_pair(i, j));
				tomatoNum++;
			}
		}
	}
	// ��� ���� 1 or -1�̶�� ��� �;��ִ� ����
	if (isRipe) {
		cout << 0 << '\n';
		return 0;
	}
	if (tomatoNum == 0) {
		cout << -1 << endl;
		return 0;
	}
	
	int cnt = 0;
	bool traverse; // ������, Ȥ�� �� �; ���� ������ Ȯ��
	int days = 0;
	while (!q.empty()) {
		cnt = 0;
		traverse = false;
		for (int i = 0; i < tomatoNum; i++) {
			pair<int, int> newc = q.front(); // �� ���� �丶�� ��ġ (BFSȰ��)
			q.pop();

			visited[newc.first][newc.second] = true;

			for (int k = 0; k < 4; k++) {
				int newY = newc.first + dy[k];
				int newX = newc.second + dx[k];

				if (0 < newX && newX <= m && 0 < newY && newY <= n && !visited[newY][newX] && map[newY][newX] == 0) {
					traverse = true;
					map[newY][newX] = 1;
					q.push(make_pair(newY, newX));
					cnt++;
				}
			}
		}
		tomatoNum = cnt;
		if (traverse)
			days++;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!visited[i][j] && map[i][j] == 0) {
				printf("-1\n");
				return 0;
			}
		}
	}

	cout << days << endl;

	return 0;
}