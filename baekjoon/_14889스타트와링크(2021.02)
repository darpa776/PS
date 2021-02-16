#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	//무조건 짝수인 n을 입력받는다.
	int n;
	cin >> n;

	int score[20][20];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			score[i][j]=x;
		}
	}
	vector<int> member(n,0);//n만큼 0으로 초기화
	fill(member.begin()+n/2, member.end(), 1);

	int ans=1e9;
	do {
	
		int sum0 = 0;
		int sum1 = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (member[i] == member[j]) {//같은 팀이면 시너지 합에 더하기
					if (member[i] == 0) {
						sum0 += score[i][j];
					}
					else if (member[i] == 1) {
						sum1 += score[i][j];
					}
				}
			}
		}

		int minus=abs(sum0-sum1);
		ans = min(ans, minus);
	
	} while (next_permutation(member.begin(),member.end()));

	cout << ans << endl;
	return 0;
	
}
