#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n, cnt = 0;
	cin >> n;
	vector<int>a(n), b(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<>());

	for (int i = 0; i < n; i++)
		cnt += a[i] * b[i];
	cout << cnt;
	return 0;
}