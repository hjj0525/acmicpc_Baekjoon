#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#pragma warning(disable: 4996);

int n;
int map[100][100];
bool visited[100][100];

int dx[4] = { 0, 0, 1 ,-1 };
int dy[4] = { 1, -1, 0, 0 };

vector<pair<int, int>> landList;

void MakeLandLable(int a, int b, int L) {
	queue<pair<int, int>> Q;
	Q.push(make_pair(a, b));
	visited[a][b] = true;
	map[a][b] = L;

	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;

		Q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (!visited[nx][ny] && map[nx][ny] == -1) {
					visited[nx][ny] = true;
					map[nx][ny] = L;
					Q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int BFS(int landLabel) {
	int res = 0;
	queue<pair<int, int>> Q;

	// ���� ���� ��ǥ�� queue�� ����ְ� BFS
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == landLabel) {
				visited[i][j] = true;
				Q.push(make_pair(i, j));
			}
		}
	}

	while (!Q.empty()) {
		int S = Q.size(); // Q�� ���������� pop�ϱ� ������ �ʱ� ũ�⸦ �������
		for (int i = 0; i < S; i++) {
			int x = Q.front().first;
			int y = Q.front().second;

			Q.pop();

			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (0 <= nx && nx < n && 0 <= ny && ny < n) {
					if (map[nx][ny] != 0 && map[nx][ny] != landLabel)
						return res; // �ڱ� �ڽŵ� �ƴϰ�, �� ���� �ƴ� => �ٸ� �� ����
					else if (map[nx][ny] == 0 && !visited[nx][ny]) {
						visited[nx][ny] = true;
						Q.push(make_pair(nx, ny));
					}
				}
			}
		}
		res++;
	}
}


int main() {
	int ans = 987654321;
	// �Է� �κ�
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
			if (map[i][j] == 1) {
				map[i][j] = -1;
				landList.push_back(make_pair(i, j));
			}
		}
	}
	// ������ ��ȣ ���̱�
	int landLabel = 1;
	for (int i = 0; i < landList.size(); i++) {
		int x = landList[i].first; // ����
		int y = landList[i].second; // ����

		if (visited[x][y] == false) {
			MakeLandLable(x, y, landLabel);
			landLabel++;
		}
	}
	memset(visited, false, sizeof(visited));
	for (int i = 1; i < landLabel; i++)
	{
		ans = min(ans, BFS(i));
		memset(visited, false, sizeof(visited));
	}
	cout << ans << endl;


	/* �׽�Ʈ ��º�
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << map[i][j] << " ";
		cout << endl;
	}
	�׽�Ʈ ��º� */ 

	return 0;
}