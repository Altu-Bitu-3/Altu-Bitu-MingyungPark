#include <iostream>
#include <vector>
#include <algorithm>
#include<cmath>
#include <numeric>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, a, max = 0, tmp;
	cin >> n;
	vector<int>arr(n), cnt(8001);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		cnt[4000+arr[i]]++;
		cnt[4000 + arr[i]] > max ? max = cnt[4000 + arr[i]] : tmp = i;
	}

	sort(arr.begin(), arr.end());

	for (; tmp >= 0; tmp--) {
		if (max == cnt[tmp])
			break;
	}
	int sum = accumulate(arr.begin(), arr.end(), 0);
	
	cout << round(sum / double(n)) << "\n";
	cout << arr[(n + 1) / 2] << "\n";
	cout << tmp-4000 << "\n";
	cout << arr[n - 1] - arr[0];
	return 0;
}