#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int getAns(vector<pair<int, int>>& arr, int n) {
	sort(arr.begin(), arr.end());//first ±‚¡ÿsorting
	int ans = 1, rank = arr[0].second;
	for (int i = 1; i < n; i++) {
		if (rank > arr[i].second) {
			ans++;
			rank = arr[i].second;
		}
	}
	return ans;
}

int main() {
	int n, t;
	cin >> t;
	while (t > 0) {
		cin >> n;
		vector<pair<int, int>> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i].first >> arr[i].second;
		}
		cout << getAns(arr, n) << "\n";
		t--;
	}
	return 0;
}