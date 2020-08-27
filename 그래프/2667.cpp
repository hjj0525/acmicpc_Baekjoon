#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int visited[25][25] = { 0, };
// 상 하 좌 우
int dx[4] = { 0, 0, 1 ,-1 };
int dy[4] = { 1, -1, 0, 0 };
string map[25];
int N;
int aptSize;
vector<int> apts;

void DFS(int x, int y) {
	// 방문했으면 체크
	visited[x][y] = 1;
	aptSize++; // 방문했으므로 카운트 증가
	
	// 상하좌우 한 칸씩 비교
	for (int i = 0; i < 4; i++) {
		int newX = x + dx[i];
		int newY = y + dy[i];
		// 범위 확인 (이상한 범위로 나가지 않도록)
		if (0 <= newX && newX < N && 0 <= newY && newY < N) {
			if (map[newX][newY] == '1' && !visited[newX][newY])
				DFS(newX, newY);
		}
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> map[i];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == '1' && !visited[i][j]) {
				aptSize = 0;
				DFS(i, j);
				apts.push_back(aptSize);
			}
		}
	}
	sort(apts.begin(), apts.end());
	cout << apts.size() << endl;
	for (int i = 0; i < apts.size(); i++)
		cout << apts[i] << endl;

	return 0;
}