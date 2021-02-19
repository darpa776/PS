#include <iostream>
#include <vector>
#include <algorithm>
#define _crt_secure_no_warnings
#pragma warning(disable:4996)
using namespace std;

int testcase,t=0 ;
int n,k,k_use=0, ans = 0;
int map[8][8];
int dx[4] = {-1,1,0,0};//상하좌우
int dy[4] = {0,0,-1,1};
vector<pair<int, int>> top;
int visited[8][8];
int longest = 0;

int dfs(int x, int y) {

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx<0 || ny < 0 || nx >= n || ny>=n) continue;
		if (visited[nx][ny]) continue;//방문했던 곳은 가지 않는다.
		for (int j = 0; j < 2; j++) {
			//안깎기
			if (j == 0) {
				if (map[x][y] > map[nx][ny]) {
					visited[nx][ny] = visited[x][y] + 1;
					longest = max(longest, visited[nx][ny]);
					dfs(nx, ny);
					visited[nx][ny] = 0;
				}
				
			}
			//깎기
			if (j == 1 && k_use == 0)//깎은 적이 없으면
			{
				k_use = 1;
				for (int h = 1; h <= k; h++) {
					map[nx][ny] -= h;
					if (map[x][y] > map[nx][ny]) {
						visited[nx][ny] = visited[x][y] + 1;
						longest = max(longest, visited[nx][ny]);
						dfs(nx, ny);
						visited[nx][ny] = 0;
					}
					map[nx][ny] += h;
					//원상복귀
				}
				k_use = 0;
			}
		}

	}
	return 0;
}



int main() {
	freopen("sample_input.txt", "r", stdin);
	
	cin >> testcase;
	while(t<testcase){
	cin >> n>>k;
	int highest = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin>>map[i][j];
			highest = max(highest,map[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (highest == map[i][j]) {
				top.push_back({ i,j });
				
			}
		}
	}
	
	for (int i = 0; i < top.size(); i++) {
		visited[top[i].first][top[i].second] = 1;
		dfs(top[i].first, top[i].second);
			//가장 긴 등산로 찾기 시작
		for (int i = 0; i < n; i++) {
			fill_n(visited[i], n, 0);
			//fill_n(map[i], n, 0);
		}
	}

	cout << "#" << t + 1 << " " << longest << endl;
	//초기화
	
	longest = 0;
	k_use = 0;
	top.clear();
	for(int i=0;i<n;i++){
		fill_n(visited[i], n, 0);
		fill_n(map[i], n, 0);
	}

	t++;
	}
	return 0;
}
