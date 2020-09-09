#pragma warning (disable: 4996)
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
int A[500000]; // 정리 전 수열
int B[500000]; // 정리 후 수열
long long cnt = 0;


void merge(int l, int mid, int r) {
	int i = l; // 시작점 1
	int j = mid + 1; // 시작점 2
	int idx = 0;

	while (i <= mid || j <= r) {
		// 우측 전부 전진, 좌측 남아있음
		// 또는 우측이 더 큰 경우 (위치가 변하지 않음 => no swap)
		if (i <= mid && (j > r || A[i] <= A[j])) 
			B[idx++] = A[i++];
		// 좌측 전부 전진, 우측 남아있음
		// 또는 좌측이 더 큰 경우 (위치가 옮겨짐 => swap)
		else {
			B[idx++] = A[j++]; 
			cnt += (long long)mid - i + 1;
		}
	}

	for (int i = l; i <= r; i++)
		A[i] = B[i - l];
}

void mergesort(int l, int r) {
	if (l < r) {
		int mid = (l + r) / 2;
		mergesort(l, mid);
		mergesort(mid + 1, r);
		merge(l, mid, r);
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	mergesort(0, N - 1);

	cout << cnt;
	return 0;
}