#include <iostream>
#include <queue>
using namespace std;

//�似Ǫ������ ���� �����ϴ� �Լ�
 void josephus_Ans(queue<int> q, int n, int k) {
	int num = 0, cnt=0;
	//ť�� ����� ���� ���� ��
	while (!q.empty()) {
		num++;
		if (num % k == 0) {
			//�������� 0�϶� ��� ���ŵ�
			if (cnt > 0) { //���ŵǴ� ����� 2���� ����� �� ���� ", "���
				cout << ", ";
			}
			cout<<q.front();//���ŵǴ� ��� ���
			cnt++;//���ŵ� ���+1
		}
		else {
			q.push(q.front()); //�ջ�� �ڷ� �ٽ� ����
		}
			q.pop(); ///�ջ�� ����
	}
	return;
}

int main() {
	int n, k;
	cin >> n >> k;
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	cout << "<";
	josephus_Ans(q, n, k);
	cout<< ">";
	return 0;
}