#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define _crt_secure_no_warnings
#pragma warning(disable:4996)
using namespace std;

int testcase,t=0 ;
int n, m, r, c, L,ans;
int map[50][50];
int visited[50][50];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int main() {
	freopen("sample_input.txt", "r", stdin);
	
	cin >> testcase;
	while (t < testcase) {
		
		cin >> n >> m >> r >> c >> L;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> map[i][j];
			}
		}//0이면 터널이 없음

		//뚜껑이 위치한 곳부터 탐색시작
		queue<pair<int, int>> q;
		q.push({ r,c });
		visited[r][c] = 1;
	
		int position = 0;//절도범이 있을 수 있는 위치

		while (!q.empty()) {
			
				int x = q.front().first;
				int y = q.front().second;
				int what = map[x][y];
				if (visited[x][y] > L) break;
				q.pop();
				position++;

				vector<int> dir;
				if (what == 1) {
					dir.push_back(0);
					dir.push_back(1);
					dir.push_back(2);
					dir.push_back(3);
				}
				else if (what == 2) {
					dir.push_back(0);
					dir.push_back(1);
				}
				else if (what == 3) {
					dir.push_back(2);
					dir.push_back(3);
				}
				else if (what == 4) {
					dir.push_back(0);
					dir.push_back(3);
				}
				else if (what == 5) {
					dir.push_back(1);
					dir.push_back(3);
				}
				else if (what == 6) {
					dir.push_back(1);
					dir.push_back(2);
				}
				else if (what == 7) {
					dir.push_back(0);
					dir.push_back(2);
				}

				
				for (int i = 0; i < dir.size(); i++) {
					int nx = x + dx[dir[i]];
					int ny = y + dy[dir[i]];
					
					if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;//갈수 없는 곳은 가지 않는다.
					if (visited[nx][ny]) continue;//이미 방문한 곳이면 가지 않는다.
					if (map[nx][ny] == 0) continue;//다음 곳에 터널이 없으면 가지 않는다.
					//if (abs(r - nx) + abs(c - ny) >= L) continue;//정해진 시간까지 이동가능
					//이거 고치기 visited+1로!!
					//지금 터널과 다음 터널이 이어진 곳만 간다.
					if (dir[i] == 0) {
						if (map[nx][ny] == 1 || map[nx][ny] ==  2 || map[nx][ny] == 5 || map[nx][ny] == 6)
						{
							q.push({ nx,ny });
							visited[nx][ny] = 1+visited[x][y];
							//position++;
						}
					}
					if (dir[i] == 1) {
						if (map[nx][ny] == 1 || map[nx][ny] == 2 || map[nx][ny] ==4 || map[nx][ny] == 7)
						{
							q.push({ nx,ny });
							visited[nx][ny] = 1+visited[x][y];
							//position++;
						}
					}
					if (dir[i] == 2) {
						if (map[nx][ny] == 1 || map[nx][ny] ==3 || map[nx][ny] == 4 || map[nx][ny] == 5)
						{
							q.push({ nx,ny });
							visited[nx][ny] = 1 + visited[x][y];
							//position++;
						}
					}
					if (dir[i] == 3) {
						if (map[nx][ny] == 1 || map[nx][ny] == 3 || map[nx][ny] ==6 || map[nx][ny] == 7)
						{
							q.push({ nx,ny });
							visited[nx][ny] = 1 + visited[x][y];
							//position++;
						}
					}
					//push한 수만큼 돌아서 l++해주는것->visited를 사용해서 길이가 L이면 break;
				}
				dir.clear();
				
			
		}
		
		//초기화
		for (int i = 0; i < n; i++) {
			fill_n(map[i], m, 0);
			fill_n(visited[i], m, 0);
		}


		//cout << ans << endl;
		cout << "#" << t + 1 << " " << position << endl;
		t++;
	}
	return 0;
}
