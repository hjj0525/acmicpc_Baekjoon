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

	int N;
	int K;
	int value[10];
	int cnt = 0;

	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> value[i];

	int idx = N - 1;
	while (K != 0) {
		if (K < value[idx])
			idx--;
		else {
			K -= value[idx];
			cnt++;
		}
	}

	cout << cnt << '\n';

	return 0;
}