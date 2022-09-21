#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

//안정된 문자열로 바꾸는데 필요한 연산 수 카운트
int cnt_stable(string s) {
	stack<char>st;//입력 값 저장 할 스텍. 이 스텍에는"{"만 저장할 것
	int cnt = 0;

	for (int i = 0; i < s.length(); i++) {//입력의 길이만큼 반복
		switch (s[i]) {
		//입력이"{" 이었을 때는 스텍에 추가
		case'{': 
			st.push(s[i]);
			break;
		// 입력이"}"일때
		case'}':
			//스텍이 비어있다면 "{"로 바꾸는 연산 후 스텍에 추가
			if (st.empty()) {
				cnt++;//연산 횟수+1
				st.push('{');
				continue;
			} 
			//스텍이 비어있지 않다면 {}쌍 하나 만들 수 있으므로 pop
			st.pop();
			break;
		}
	}
	//남아있는 "{"들의 절반은 "}"로 바꾸어서 안정적으로 바꾼다
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
		i++; //몇번재 줄인지 카운팅
		if (s[0] == '-') //'-'가 나오는 순간 break
			break;
		cout<<i<<". "<<cnt_stable(s)<<"\n";//테스트케이스에 대한 출력
	}
}