#include <iostream>
#include <vector>
#include <algorithm>
#define _crt_secure_no_warnings
#pragma warning(disable:4996)
using namespace std;

int testcase,t=0 ;
int n,m, ans;
int map[20][20];
int dp[13];

int coin[4];
int plan[12];

int main() {
	freopen("sample_input.txt", "r", stdin);
	
	cin >> testcase;
	while(t<testcase){
		for (int i = 0; i < 4; i++) {
			cin >> coin[i];//1일권, 1달권, 3달권, 1년권
			//이용권의 가격들
		}
		
		int useday = 0;
		for (int i = 0; i < 12; i++) {
			//12달 동안의 수영장 이용계획
			cin>>plan[i];
			useday += plan[i];//총 이용날짜 계산
		}

		dp[12] = 0;
		//dp 쌓기
		for (int i = 11; i >= 0; i--) {
			
			dp[i] = coin[0] * plan[i] +dp[i+1];//1일권
			dp[i] = min(dp[i], coin[1] + dp[i + 1]);//1달권
			if (i < 11) {
				dp[i] = min(dp[i], coin[2] + dp[i + 3]);//3달권
			}
			
		}
		ans = min(coin[3], dp[0]);//1년권
			//1년권은 비교할 대상이 1년단위이기 때문에 따로 계산
		cout << "#" << t + 1 << " " << ans << endl;
	

	t++;
	}
	return 0;
}
