#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

//������ ���ڿ��� �ٲٴµ� �ʿ��� ���� �� ī��Ʈ
int cnt_stable(string s) {
	stack<char>st;//�Է� �� ���� �� ����. �� ���ؿ���"{"�� ������ ��
	int cnt = 0;

	for (int i = 0; i < s.length(); i++) {//�Է��� ���̸�ŭ �ݺ�
		switch (s[i]) {
		//�Է���"{" �̾��� ���� ���ؿ� �߰�
		case'{': 
			st.push(s[i]);
			break;
		// �Է���"}"�϶�
		case'}':
			//������ ����ִٸ� "{"�� �ٲٴ� ���� �� ���ؿ� �߰�
			if (st.empty()) {
				cnt++;//���� Ƚ��+1
				st.push('{');
				continue;
			} 
			//������ ������� �ʴٸ� {}�� �ϳ� ���� �� �����Ƿ� pop
			st.pop();
			break;
		}
	}
	//�����ִ� "{"���� ������ "}"�� �ٲپ ���������� �ٲ۴�
	if (!st.empty()) {
		cnt += st.size() / 2;
	}
	return cnt;
}
int main() {
	string s;
	int i = 0;
	while (true) {
		getline(cin, s);
		i++; //����� ������ ī����
		if (s[0] == '-') //'-'�� ������ ���� break
			break;
		cout<<i<<". "<<cnt_stable(s)<<"\n";//�׽�Ʈ���̽��� ���� ���
	}
}