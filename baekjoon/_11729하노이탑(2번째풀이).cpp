#include <iostream>
using namespace std;
//문제상 시간초과 때문에 endl을 '\n'로 고쳐서 제출
int n;//1~20
//최종적으로 1번째 장대에 있는 원판들이 3번째 장대로 옮겨가야한다.
int cnt[21];

void hanoi(int n, int A, int B, int C) {
	if (n == 1) {
		cout << A <<" "<< B<< '\n';
		return;
	}
	hanoi(n - 1, A, C, B);
	cout << A << " " << B<< '\n';
	hanoi(n - 1, C, B, A);
	
}


int main() {
	//첫번째 장대에 쌓인 원판 개수
	cin >> n;

	//A에서 n-1개의 블럭을 C로 옮기는 횟수+A에서 n번째 블럭을 B로 옮기는 횟수(1)+ C에서 n-1개의 블럭을 C로 옮기는 횟수
	//hanoi(n)= hanoi(n-1)*2 + 1
	cnt[1] = 1;
	for (int i = 2; i <= n; i++) {
		cnt[i] = cnt[i - 1] * 2 + 1;
	}
	cout << cnt[n] << '\n';

	hanoi(n, 1,3,2);//개수, A(출발), B(도착), C(휴게소)
	//옮긴 횟수 k 출력
	//옮기는 과정 출력
	//A 가장 위 원판을 B로 옮겼음을 의미
	return 0;
}
