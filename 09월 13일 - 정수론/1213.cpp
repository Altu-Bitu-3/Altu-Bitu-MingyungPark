#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

bool isPalindrome(int* alphabet) {//�縰��� ���� �� �ִ� ���ڿ����� �˻�
	int cnt = 0;
	alphabet[26] = -1;//�ε��� 26���� Ȧ������ ������ �ε��� ����

	for (int i = 0; i < 26; i++) {
		if (alphabet[i] % 2) { //���ĺ� ������ Ȧ�����̸� cnt+1
			cnt++;
			alphabet[26] = i;
		}
		alphabet[i] /= 2;
	}
	if (cnt > 1) { //Ȧ������ ���ĺ��� 1�� �̻��̸� �縰��� ���� �� ����
		return false;
	}
	return true;
}

string getPalindrome(int* alphabet) {
	stack<char> s;
	string ans;
	for (int i = 0; i < 26; i++) {
		while (alphabet[i]--) {
			s.push(i + 'A');
			ans.push_back(i + 'A');
		}
	}
	if (alphabet[26] > -1) {
		ans.push_back(alphabet[26] + 'A');
	}
	while (!s.empty()) {
		ans.push_back(s.top());
		s.pop();
	}
	return ans;
}

int main() {
	int alphabet[27] = {};
	char c;
	string name;
	cin >> name;
	for (int i = 0; i < name.size();i++) {
		alphabet[name[i] - 'A']++;
	}

	if (isPalindrome(alphabet)) {//if we can get palindrome
		cout << getPalindrome(alphabet);//print palindrome string
		return 0;
	}
	cout << "I'm Sorry Hansoo";//print if we cannot get palindrome

	return 0;
}