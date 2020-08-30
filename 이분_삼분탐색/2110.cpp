#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N; // ���� ����
int C; // �������� ����
vector <long long> pos; // ���� ��ġ
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

		if (cnt < C) { // ����� ������ �������� �Ʒ�
			high = mid - 1;
		}
		else {
			if (mid > ans) // �ִ� ã��
				ans = mid;
			low = mid + 1;
		}
	}

	cout << ans << '\n';

	return 0;
}