#include <iostream>
#include <stack>
#include <deque>

using namespace std;

// dq���� �ʱ�ī����� �����ϴ� �Լ�
deque<int> card(stack<int>& s, int n) {
	int tmp;
	deque<int>ans;
	//1��ī����� n�� ī����� ������� dq�� ����
	for (int i = 1; i <= n; i++) {
		//i�� ī�带 ���� �� �� ����� s.top()
		switch (s.top()) {
			//1����� : ���� ���� ī�带 �������� >> �������� ī�� �̵�(push_front)
		case 1:
			ans.push_front(i);
			break;
			
			//2�� ��� :������ �ι�° �ڸ��� ī�� �̵�
		case 2:
			tmp = ans.front();
			ans.pop_front();
			ans.push_front(i);
			ans.push_front(tmp);
			break;

			//3�� ��� : �� �Ʒ��� ī�� �̵�
		case 3:
			ans.push_back(i);
			break;
		}
		//����� ��� pop
		s.pop();
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, input;
	stack<int>s; //input���� ���� ī����
	deque<int>dq;//�ʱ�ī����� ������ ��

	//ī�尳��n, ī������ input�޴´�.
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		s.push(input);
	}

	//�ʱ���� dq�� ����
	dq=card( s, n);

	//�տ�������dq cout
	while (n--) {
		cout << dq.front() << " ";
		dq.pop_front();
	}

	return 0;
}