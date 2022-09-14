#include <iostream>
#include <stack>
#include <deque>
using namespace std;

// dq덱에 초기카드상태 저장하는 함수
void card(deque<int>& dq, stack<int>& s, int n) {
	int tmp;
	
	//1번카드부터 n번 카드까지 순서대로 dq에 삽입
	for (int i = 1; i <= n; i++) {
		//i번 카드를 놓을 때 쓴 기술이 s.top()
		switch (s.top()) {
			//1번기술 : 제일 위의 카드를 내려놓음 >> 제일위로 카드 이동(push_front)
		case 1:
			dq.push_front(i);
			break;
			
			//2번 기술 :위에서 두번째 자리로 카드 이동
		case 2:
			tmp = dq.front();
			dq.pop_front();
			dq.push_front(i);
			dq.push_front(tmp);
			break;

			//3번 기술 : 맨 아래로 카드 이동
		case 3:
			dq.push_back(i);
			break;
		}
		//사용한 기술 pop
		s.pop();
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, input;
	stack<int>s; //input으로 받을 카드기술
	deque<int>dq;//초기카드상태 저장할 덱

	//카드개수n, 카드기술을 input받는다.
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		s.push(input);
	}

	//초기상태 dq에 저장
	card(dq, s, n);

	//앞에서부터dq cout
	while (n--) {
		cout << dq.front() << " ";
		dq.pop_front();
	}

	return 0;
}