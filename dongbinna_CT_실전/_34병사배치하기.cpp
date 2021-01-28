#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	//병사 배치하기
	//가장 긴 증가하는 부분 수열
	int n;
	cin >> n;
	//전투력
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	//다이내믹 테이블 초기화
	int dp[2000];
	fill_n(dp, 2000, 1);

	//병사들의 전투력이 내림차순이기 때문에 오름차순 수열로 변경
	reverse(v.begin(), v.end());

	//dp 테이블 만들기
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (v[i] > v[j]) {
				dp[i] = max(dp[i],dp[j]+1);
			}
		}
	}
	//뺄 병사들 수 출력
	//가장 큰 수열의 길이=length
	int length=0;
	for (int i = 0; i < n; i++) {
		if (length < dp[i])
			length = dp[i];
	}
	cout << n - length << endl;
	return 0;
}
