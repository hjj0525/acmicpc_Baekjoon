#pragma warning (disable: 4996)
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 1000000

int main() {
	ios::sync_with_stdio();
	cin.tie();
	int N, M;
	cin >> N >> M;
	int A[MAX+1];
	int B[MAX+1];
	int C[2 * MAX];
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	for (int j = 0; j < M; j++) {
		scanf("%d", &B[j]);
	}
	A[N] = 1000000000;
	B[M] = 1000000000;
	int j=0, k=0;
	for (int i = 0; i < N+M; i++) {
		if (A[j] >= B[k] || A[j] == 1000000000) {
			C[i] = B[k];
			k++;
		}
		else if(A[j] < B[k] || B[k] == 1000000000){
			C[i] = A[j];
			j++;
		}
	}

	for (int i = 0; i < N + M; i++)
		cout << C[i] << " ";


	return 0;
}