#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int sumNumber(const string& a) {
	int sum = 0;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] <= '9')
			sum += a[i] - '0';
	}
	return sum;
}

bool cmp(const string& a, const string& b) {
	int sum_a = sumNumber(a);
	int sum_b = sumNumber(b);

	if (a.length() != b.length())
		return a.length() < b.length();
	else if (sum_a != sum_b)
		return sum_a < sum_b;
	else
		return a < b;
}

int main() {
	int n;
	cin >> n;
	vector<string> serial(n);
	for (int i = 0; i < n; i++) {
		cin >> serial[i];
	}
	sort(serial.begin(), serial.end(), cmp);
	for (int i = 0; i < n; i++) {
		cout << serial[i] << "\n";
	}
	return 0;
}