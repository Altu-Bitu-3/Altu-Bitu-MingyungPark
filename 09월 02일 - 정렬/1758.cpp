#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long getTip(vector<int> arr, int n) {
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] <= i)
			break;
		sum += arr[i] - i;
	}
	return sum;
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end(), greater<>());
	cout << getTip(arr, n);
	return 0;
}