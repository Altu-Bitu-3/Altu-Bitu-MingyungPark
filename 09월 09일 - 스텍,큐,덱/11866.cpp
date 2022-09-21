#include <iostream>
#include <queue>
using namespace std;

//요세푸스문제 답을 도출하는 함수
 void josephus_Ans(queue<int> q, int n, int k) {
	int num = 0, cnt=0;
	//큐에 사람이 남아 있을 때
	while (!q.empty()) {
		num++;
		if (num % k == 0) {
			//나머지가 0일때 사람 제거됨
			if (cnt > 0) { //제거되는 사람이 2번재 사람일 때 무터 ", "출력
				cout << ", ";
			}
			cout<<q.front();//제거되는 사람 출력
			cnt++;//제거된 사람+1
		}
		else {
			q.push(q.front()); //앞사람 뒤로 다시 보냄
		}
			q.pop(); ///앞사람 삭제
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