#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
vector<int> Ns;
vector<int> Ms;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		Ns.push_back(tmp);
	}
	sort(Ns.begin(), Ns.end());

	cin >> M;
	for (int i = 0; i < M; i++) {
		int tmp;
		cin >> tmp;
		Ms.push_back(tmp);
	}

	for (int i = 0; i < M; i++) {
		if (binary_search(Ns.begin(), Ns.end(), Ms[i]))
			cout << "1 ";
		else
			cout << "0 ";
	}
	return 0;
}