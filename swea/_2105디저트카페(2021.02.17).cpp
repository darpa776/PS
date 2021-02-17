#include <iostream>
#include <vector>
#include <algorithm>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
using namespace std;

int n,ans=0;
int map [20][20];
int visited[20][20];
int testcase,t=0 ;
int dx[4] = {1,1,-1,-1};//시계방향
int dy[4] = {1,-1,-1,1};
int cnt = 0;
pair<int, int> start;
int check[101];

void trip(int x, int y,int dir,int cnt) {
	
	for (int i = dir; i <= dir + 1; i++) {
		int nx = x + dx[i % 4];
		int ny = y + dy[i % 4];
		//visited를 쓰면 find 함수를 안써도 되서 빨라진다.
		if (nx < 0 || ny < 0 || nx >= n || ny >= n ) {
			//연산 가능범위가 아닌 곳이라면
			continue;
		}

		if (start.first == nx && start.second == ny && dir == 3 ) {//처음시작한 곳으로 돌아왔다면
			//하트방향을 그리지 않도록 출발지점에 도착할 때의 방향을 정한다.
			ans = max(cnt, ans);
			return;
		}
		else if ( check[map[nx][ny]]==0) {
			//먹어본적 없는 디저트라면
			check[map[nx][ny]]=1;
			cnt++;
			visited[nx][ny]=1;
			trip(nx, ny, i, cnt);
			check[map[nx][ny]] = 0;
			cnt--;
			visited[nx][ny] = 0;
		}
		else {
			//먹어봤던 디저트라면 방향을 전환시킨다.
			continue;
		}

	}
	
}


int main() {
	freopen("sample_input.txt", "r", stdin);
	
	cin >> testcase;
	while(t<testcase){
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cnt = 0;
			start.first = i;
			start.second = j;
			visited[i][j] = 1;
			check[map[i][j]] = 1; 
			trip(i, j,0,1);
			visited[i][j] = 0;
			check[map[i][j]] = 0;
			//오른쪽 하단부터 돌아야 하트모양으로 이상하게 돌지 않는다
			fill_n(check, 101, 0);
		}
	}

	if (ans == 0) ans = -1;
	cout<<"#"<<t+1<<" " << ans << endl;
	//초기화
	for (int i = 0; i < n; i++) {
		fill_n(map[i], n, 0);
		fill_n(visited[i], n, 0);
	}
	ans = 0, cnt = 0;
	t++;
	}
	return 0;
}
