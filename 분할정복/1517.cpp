#pragma warning (disable: 4996)
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
int A[500000]; // ���� �� ����
int B[500000]; // ���� �� ����
long long cnt = 0;


void merge(int l, int mid, int r) {
	int i = l; // ������ 1
	int j = mid + 1; // ������ 2
	int idx = 0;

	while (i <= mid || j <= r) {
		// ���� ���� ����, ���� ��������
		// �Ǵ� ������ �� ū ��� (��ġ�� ������ ���� => no swap)
		if (i <= mid && (j > r || A[i] <= A[j])) 
			B[idx++] = A[i++];
		// ���� ���� ����, ���� ��������
		// �Ǵ� ������ �� ū ��� (��ġ�� �Ű��� => swap)
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