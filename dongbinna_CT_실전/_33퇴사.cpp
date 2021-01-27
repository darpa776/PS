#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;//최대 15
vector < pair<int,int>> work;
int ans[20];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int period;
		int money;
		cin >> period >> money;
		work.push_back({period,money});
	}
	//뒤에서부터 거꾸로 프로그래밍

	int answer = 0;
	for (int i = n-1; i >= 0; i--) {
		int t=work[i].first;
		if (t + i > n) {
			ans[i] = answer;
			continue;
		}
		//할일이 퇴사 다음날까지 이어지면
		//이때까지 최대값을 지금날짜까지 얻을 수 있는 최대값으로 넣기
		ans[i] = max(work[i].second + ans[i + work[i].first],answer);
		answer = ans[i];
	}
	

	cout << answer << endl;
	return 0;
}
