#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//내림차순이 아니라 오름차순으로 정렬해야 함
//문제가 그룹 수를 최대로 만드는 것임

int main() {
	int n;//모험에 참가하는 모험자 수
	cin >> n;
	vector<int> afraid;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		afraid.push_back(x);
	}
	sort(afraid.begin(), afraid.end());
	int ans = 0;
	int idx = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{//1명이라도 팀을 구성한다.
		cnt++;

		//공포도가 팀 인원수보다 더 크면 인원수를 더 모아야한다.
		//하지만 현재 팀 인원수가 공포도를 넘거나 같으면 팀을 구성하고 다음 팀을 마련해야 한다.
		//팀을 많이 결성하려면 팀 인원수가 공포도를 넘으면 다음 팀을 결성해야한다.
		if (afraid[i] <= cnt)
		{
			ans++;
			cnt = 0;
			//다음 팀을 준비
		}
	}
	cout << ans << endl;
	return 0;
}
