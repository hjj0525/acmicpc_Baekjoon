#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

/*
1. 입력 받은 전선의 길이 중 최대 길이를 high로 잡습니다.
2. 자르는 전선의 길이가 존재해야하므로 low는 1로 잡습니다.
3. 이분 탐색을 진행하면서 mid에 대해 조건을 충족하는지 확인합니다.
	i) 조건이 충족된다면 자르는 전선의 길이를 늘립니다.
	ii) 조건이 충족되지 않는다면 자른는 전선의 길이를 줄입니다.
4. 조건이 충족되는 최대 길이를 출력합니다.
*/

const int MAX = 10000;
int K, N;
long long wire[MAX];

bool isRight(long long len) {
	int cnt = 0;
	for (int i = 0; i < K; i++) {
		cnt += wire[i] / len;
	}
	// 특정 길이 len의 갯수가 N개보다 많다면
	if (cnt >= N)
		return true;
	return false;
}
int main() {
	cin >> K >> N;

	long long high = 0; // 가장 긴 전선 길이
	long long low = 1;
	long long res = 0; // 결과 값

	for (int i = 0; i < K; i++) {
		cin >> wire[i];
		high = max(high, wire[i]);
	}

	while (low <= high) {
		long long mid = (low + high) / 2;
		//cout << "low: " << low << " mid: " << mid << " high: " << high << endl;
		if (isRight(mid)) {
			if (res < mid)
				res = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}

	cout << res << '\n';
		
	return 0;
}