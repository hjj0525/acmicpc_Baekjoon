#include <iostream>
#include <queue>
using namespace std;

/* Radix Sort �� �̿��� ��� O(n*d)�� �ð� ���⵵�� ������! */

int main() {
	// radix sort������ ��� ������ ���� ����ؾ��Ѵ�. 
	vector<long> arrPos; 
	vector<long> arrNeg;

	long n;
	long posCnt=0;
	long negCnt=0;

	long tmp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp >= 0) {
			arrPos.push_back(tmp);
			posCnt++;
		}
		else {
			arrNeg.push_back(tmp);
			negCnt++;
		}
	}

	queue<long> posRadix[10]; // �ڸ��� �뵵
	queue<long> negRadix[10];
	
	if (posCnt > 0) {
		int maxPos = arrPos[0];
		int d = 1; // �ִ� �ڸ���

		// �ִ� �ּҰ� ���ϱ�
		for (int i = 1; i < posCnt; i++)
			if (maxPos < arrPos[i])
				maxPos = arrPos[i];

		while (maxPos / 10) {
			d *= 10;
			maxPos /= 10;
		}

		int mod = 10;
		int dMin = 1;

		while (dMin <= d) {
			// �ڸ����� �°� ť�� ����ֱ� (0~9) ���� �ش��ϴ� �ڸ�
			for (int i = 0; i < posCnt; i++) {
				posRadix[(arrPos[i] % mod) / dMin].push(arrPos[i]);
			}

			for (int i = 0, j = 0; i < 10;) {
				if (posRadix[i].size()) { // radix�� ������ ��� 
					arrPos[j++] = posRadix[i].front(); // arrPos�� ���Ӱ� ���鼭 radix������ �����Ѵ�
					posRadix[i].pop();
				}
				else
					i++;
			}

			dMin *= 10;
			mod *= 10;
		}
	}

	if (negCnt > 0) {
	
		int minNeg = arrNeg[0];
		int d = 1;

		for (int i = 1; i < negCnt; i++)
			if (minNeg > arrNeg[i])
				minNeg = arrNeg[i];

		while (minNeg / 10) {
			d *= 10;
			minNeg /= 10;
		}
		int mod = 10;
		int dMin = 1;

		while (dMin <= d) {
			// �ڸ����� �°� ť�� ����ֱ� (0~9) ���� �ش��ϴ� �ڸ�
			for (int i = 0; i < negCnt; i++) {
				negRadix[-(arrNeg[i] % mod) / dMin].push(arrNeg[i]);
			}

			for (int i = 0, j = 0; i < 10;) {
				if (negRadix[i].size()) { // radix�� ������ ��� 
					arrNeg[j++] = negRadix[i].front(); // arrNeg�� ���Ӱ� ���鼭 radix������ �����Ѵ�
					negRadix[i].pop();
				}
				else
					i++;
			}

			dMin *= 10;
			mod *= 10;
		}
	}

	for (int i = negCnt-1; i >= 0; i--)
		cout << arrNeg[i] << "\n";

	for (int i = 0; i < posCnt; i++)
		cout << arrPos[i] << "\n";

	return 0;
}