#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
#pragma warning(disable: 4996);

int maze[101][101];
bool visited[101][101];

int dx[4] = { 0, 0, 1 ,-1 };
int dy[4] = { 1, -1, 0, 0 };

int main() {
	int n, m;
	cin >> n >> m; // n이 세로, m이 가로
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			scanf("%1d", &maze[i][j]);
	}

	queue<pair<int, int>> q;
	q.push(make_pair(1, 1));

	while (!q.empty()) {
		pair<int, int> now = q.front();
		int dist = maze[now.first][now.second];
		q.pop();

		for (int k = 0; k < 4; k++) {
			int newY = now.first + dy[k];
			int newX = now.second + dx[k];

			if (0 < newX && newX <= m && 0 < newY && newY <= n) {
				if (!visited[newY][newX] && maze[newY][newX]) {
					q.push(make_pair(newY, newX));
					visited[newY][newX] = true;
					maze[newY][newX] = dist + 1;
				}
			}
				
		}
	}

	/*
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cout << maze[i][j];
		cout << endl;
	}
	*/
	
	printf("%d\n", maze[n][m]);
	return 0;
}