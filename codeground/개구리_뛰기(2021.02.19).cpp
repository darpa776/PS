#include <iostream>
#include <vector>
#include <algorithm>
//#define _crt_secure_no_warnings
//#pragma warning(disable:4996)
using namespace std;

int testcase,t=0 ;
int n,k, ans = 0;
//int cnt[1000001];
vector<int> stone;
//size=n+1;//0 위치도 포함한다.
//int stone[100001];

int check() {
	//시작점에서 뛸때 k보다 큰 위치에 있는 경우
	if (stone[0] > k) return -1;

	for (int i = 1; i < n; i++) {
		if (abs(stone[i] - stone[i - 1])>k) {
			//중간에 개구리가 뛸 수 없는 지점이 있으면 ans =-1;
			return -1;
		}
	}
	return 0;
}
////greedy로 풀면 되는걸 dp로 착각하게 만드는 문제임....
////dp로 푸는 경우
////아래 경우처럼 풀면 timelimit, stackoverflow..
////문제에서 100만개를 준 경우를 계산해볼때 dp는 무리임을 알았어야했어..
//int frog(int last) {
//	for (int j = 0; j < n; j++) {
//		for (int i = 0; i < n; i++) {
//			if (stone[i] - last <= k) {
//				dp[stone[i]] = min(dp[last] + 1, dp[stone[i]]);//해당 돌의 dp를 갱신
//			}
//			else break;
//
//		}
//		last = stone[j];
//	}
//	return dp[stone[n - 1]];
//}

//이미 ans이 -1인 경우는 걸러냈으니까, greedy로 풀어서 stone위치가 가장 크도록 뛰게 하자
int frog(int current) {
	int cnt = 0;
	for (int i = 1; i < n; i++) {
		
		if (current + k < stone[i]) {//******
			current = stone[i - 1];//*******
			cnt += 1;//******
		}
		//마지막 current가 마지막-1번째 stone 이니까
		//마지막 stone에 도착하도록 cnt 수 더해줘야함
		//마지막 current에서 마지막 stone까지는 무조건 도착함!**
		
	}
	cnt += 1;

//출처: https://hading.tistory.com/46
	return cnt;
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	
	cin >> testcase;
	while(t<testcase){
	cin >> n;//돌들의 개수
	
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		stone.push_back(x);
		
	}
	//개구리가 한번의 점프로 이동가능한 최대거리
	cin >> k;

	ans = check();
	if (ans != -1) {//길을 만들 수 있는 경우에는 frog 함수를 사용한다.
		ans = frog(0);
	}
	
	cout << "Case #" << t + 1 << endl;
	cout<< ans << endl;
	//초기화
	
	ans = 0;
	stone.clear();
	t++;
	}
	return 0;
}
