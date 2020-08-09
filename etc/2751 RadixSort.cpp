#include <iostream>
#include <queue>
using namespace std;

/* Radix Sort 를 이용한 방식 O(n*d)의 시간 복잡도를 가진다! */

int main() {
	// radix sort에서는 양수 음수를 따로 고려해야한다. 
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

	queue<long> posRadix[10]; // 자릿수 용도
	queue<long> negRadix[10];
	
	if (posCnt > 0) {
		int maxPos = arrPos[0];
		int d = 1; // 최대 자릿수

		// 최대 최소값 구하기
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
			// 자릿수에 맞게 큐에 집어넣기 (0~9) 현재 해당하는 자리
			for (int i = 0; i < posCnt; i++) {
				posRadix[(arrPos[i] % mod) / dMin].push(arrPos[i]);
			}

			for (int i = 0, j = 0; i < 10;) {
				if (posRadix[i].size()) { // radix가 존재할 경우 
					arrPos[j++] = posRadix[i].front(); // arrPos을 새롭게 쓰면서 radix순으로 정렬한다
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
			// 자릿수에 맞게 큐에 집어넣기 (0~9) 현재 해당하는 자리
			for (int i = 0; i < negCnt; i++) {
				negRadix[-(arrNeg[i] % mod) / dMin].push(arrNeg[i]);
			}

			for (int i = 0, j = 0; i < 10;) {
				if (negRadix[i].size()) { // radix가 존재할 경우 
					arrNeg[j++] = negRadix[i].front(); // arrNeg을 새롭게 쓰면서 radix순으로 정렬한다
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