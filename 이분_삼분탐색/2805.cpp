#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

static int MAX = 1000000;

int N; // 나무의 수
long long M; // 나무 길이
vector<long long> H; // 나무의 높이

bool isPossible(long long len) {
	long long total = 0;
	for (auto i = H.begin(); i < H.end(); i++) {
		if (*i > len)
			total += *i - len;
	}
	if (total >= M)
		return true;
	return false;
}
int main() {
	cin >> N >> M;
	long long high = 0, low = 0, res = 0;
	for (int i = 0; i < N; i++) {
		long long treeLen;
		cin >> treeLen;
		H.push_back(treeLen);
		high = max(high, treeLen);
	}

	while (low <= high) {
		long long mid = (high + low) / 2;

		if (isPossible(mid)) {
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