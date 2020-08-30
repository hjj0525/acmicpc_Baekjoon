#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

/*
1. �Է� ���� ������ ���� �� �ִ� ���̸� high�� ����ϴ�.
2. �ڸ��� ������ ���̰� �����ؾ��ϹǷ� low�� 1�� ����ϴ�.
3. �̺� Ž���� �����ϸ鼭 mid�� ���� ������ �����ϴ��� Ȯ���մϴ�.
	i) ������ �����ȴٸ� �ڸ��� ������ ���̸� �ø��ϴ�.
	ii) ������ �������� �ʴ´ٸ� �ڸ��� ������ ���̸� ���Դϴ�.
4. ������ �����Ǵ� �ִ� ���̸� ����մϴ�.
*/

const int MAX = 10000;
int K, N;
long long wire[MAX];

bool isRight(long long len) {
	int cnt = 0;
	for (int i = 0; i < K; i++) {
		cnt += wire[i] / len;
	}
	// Ư�� ���� len�� ������ N������ ���ٸ�
	if (cnt >= N)
		return true;
	return false;
}
int main() {
	cin >> K >> N;

	long long high = 0; // ���� �� ���� ����
	long long low = 1;
	long long res = 0; // ��� ��

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