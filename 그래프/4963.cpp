#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 51
using namespace std;



bool visited[MAX][MAX];
int w, h;
// 상 하 좌 우
int dx[8] = { 0, 0, 1 ,-1 ,1,1,-1,-1};
int dy[8] = { 1, -1, 0, 0,1,-1,1,-1 };
int map[MAX][MAX];

void DFS(int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i < 8; i++) {
		int newX = x + dx[i];
		int newY = y + dy[i];

		if (1 <= newX && newX <= h && 1 <= newY && newY <= w) {
			if (map[newX][newY] == 1 && !visited[newX][newY])
				DFS(newX, newY);
		}
	}
}
// i가 height, j가 width임을 주의하자
int main() {
	int islands;
	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;

		// 초기화
		islands = 0;
		for(int i=1; i<=h;i++)
			for (int j = 1; j <= w; j++) {
				map[i][j] = 0;
				visited[i][j] = false;
			}


		// map 그리기
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (map[i][j]==1 && !visited[i][j]) {
					DFS(i, j);
					islands++;
				}
			}
		}
		cout << islands << '\n';
	}
	return 0;
}