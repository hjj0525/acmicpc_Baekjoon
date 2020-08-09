#include <iostream>
#include <vector>
using namespace std;

/* Merge Sort 를 이용한 방식 O(N*log N)의 시간 복잡도를 가진다! */
void Merge(vector<int> &vec, int start, int mid, int end) {
	int i = start;
	int j = mid + 1; // 중간 다음 index

	vector<int> tmp(end - start + 1);
	int base = 0;
	while (i <= mid && j <= end) {
		if (vec[i] <= vec[j]) {
			tmp[base++] = vec[i++];
		}
		else {
			tmp[base++] = vec[j++];
		}
	}
	if (i == mid + 1){
		copy(vec.begin() + j, vec.begin() + (end + 1), tmp.begin() + base);
	}
	else if(j == end + 1){
		copy(vec.begin() + i, vec.begin() + (mid + 1), tmp.begin() + base);
	}
	copy(tmp.begin(), tmp.end(), vec.begin() + start);
}
void MergeSort(vector<int> &vec, int start, int end) {
	if (start < end) {
		int mid = (start + end)/2;
		MergeSort(vec, start, mid);
		MergeSort(vec, mid+1, end);
		Merge(vec, start, mid, end);
	}
}

int main() {
	int n;
	vector<int> arr;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}
	MergeSort(arr, 0, n-1);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\n";
	}
	return 0;
}