#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	//편집거리
	//A를 편집해서 B로 만들어야 함
	string A;
	string B;

	//cin >> A >> B;
	//또는
	getline(cin, A);
	getline(cin, B);

	//dp테이블을 만들자

	//int dp[5001][5001];//이거 쓰면 오류(stack영역 overflow)남
	vector<vector<int> > dp(A.size() + 1, vector<int>(B.size() + 1));

	//dp 테이블 초기설정
	for (int i = 0; i <= A.size(); i++) {
		dp[i][0] = i;
	}

	for (int j = 0; j <= B.size(); j++) {
		dp[0][j] = j;
	}


	for (int i = 1; i <= A.size(); i++) {
		for (int j = 1; j <= B.size(); j++) {
			if (A[i - 1] == B[i - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				//삽입insert
				int _insert = dp[i][j - 1] + 1;
				//삭제erase
				int _erase = dp[i - 1][j] + 1;
				//교체replace
				int _replace = dp[i - 1][j - 1] + 1;

				dp[i][j] = min(_insert, min(_erase, _replace));
			}
		}
	}

	//최소 편집거리 출력
	cout << dp[A.size()][B.size()] << endl;
	return 0;
}
