#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M, K; // 여자, 남자, 제외인원
	cin >> N >> M >> K;

	int maxTeam;

	if (N / M >= 2) {
		maxTeam = M;
	}
	else {
		maxTeam = N / 2;
	}

	float remain = K - (N + M - maxTeam * 3);
	if (remain <= 0) {
		cout << maxTeam << '\n';
		return 0;
	}
	
	int minus = ceil(remain / 3);
	
	maxTeam -= minus;
	cout << maxTeam << '\n';

	return 0;
}