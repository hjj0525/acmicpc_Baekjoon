#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N; // 집의 갯수
int C; // 공유기의 갯수
vector <long long> pos; // 집의 위치
int main() {
	cin >> N >> C;
	long long high = 0, low = 0;
	for (int i = 0; i < N; i++) {
		long long position;
		cin >> position;
		pos.push_back(position);
		high = max(high, position);
	}
	sort(pos.begin(), pos.end());
	
	int ans = 0;

	while (low <= high) {
		long long mid = (low + high) / 2;
		long long wifi = pos[0];
		int cnt = 1;
		
		for (int i = 1; i < N; i++) {
			if (pos[i] - wifi >= mid) {
				cnt++;
				wifi = pos[i];
			}
		}

		if (cnt < C) { // 결과가 공유기 갯수보다 아래
			high = mid - 1;
		}
		else {
			if (mid > ans) // 최댓값 찾기
				ans = mid;
			low = mid + 1;
		}
	}

	cout << ans << '\n';

	return 0;
}