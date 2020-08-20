#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <algorithm>
#pragma warning(disable: 4996);
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	queue<int> Q;
	for (int i = 1; i <= n; i++)
		Q.push(i);

	cout << '<';
	while (Q.size()) {
		if (Q.size() == 1) {
			cout << Q.front() << ">";
			Q.pop();
			break;
		}
		// front가 dequeue 되는 쪽, rear가 queue 되는 쪽
		for (int i = 1; i < k; i++) {
			Q.push(Q.front());
			Q.pop();
		}
		cout << Q.front() << ", ";
		Q.pop();
	}
	cout << "\n";
	return 0;
}