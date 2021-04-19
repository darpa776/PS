#include <iostream>
#include <queue>
using namespace std;
//https://sangdo913.tistory.com/162
//빨간 구슬이 먼저 떨어져야한다.
//더이상 구슬이 움직이지 않을때까지 기울이기
//최소 몇번 만에 빨간 구슬을 구멍을 통해 빼낼수 있는가?
//10번 이내에 못 빼내면 -1 출력
//파란구슬과 빨간구슬이 동시에 구멍으로 빠져나와도 -1

int n, m;
char map[20][20];
int visited[20][20][20][20];//red & blue
pair<int, int> red;
pair<int, int> blue;
pair<int, int> hole;
int dx[4] = {-1,1,0,0};//상하좌우
int dy[4] = {0,0,-1,1};
int ans=0;

int main() {

	//빨간공과 파란공의 i나 j가 같으면 굴릴때 주의: 멀리 굴러간 공의 위치를 반대로 1
	//bfs와 while을 이용해서 해당방향으로 계속 전진
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'O')//구멍이면
			{
				hole.first = i;
				hole.second = j;
			}
			else if (map[i][j] == 'R')
			{
				red.first = i;
				red.second = j;
				map[i][j] = '.';

			}
			else if (map[i][j] == 'B') {
				blue.first = i;
				blue.second = j;
				map[i][j] = '.';
			}
		}
	}

	//bfs
	int t = 1;
	queue < pair<pair<int, int>, pair<int, int>>> q;
	q.push({ red, blue });
	visited[red.first][red.second][blue.first][blue.second] = 1;

	while (!q.empty()) {
		int cnt = q.size();
		while (cnt--) {//bfs에서 시간 세는 법**
			//굴리기 시작
			int Rx = q.front().first.first;
			int Ry = q.front().first.second;
			int Bx = q.front().second.first;
			int By = q.front().second.second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int R_flag = 0;
				int B_flag = 0;

				int nRx = Rx + dx[i];
				int nRy = Ry + dy[i];
				int nBx = Bx + dx[i];
				int nBy = By + dy[i];
				
				//if (visited[nRx][nRy][nBx][nBy] != 0)//방문했다면 pass
				//	continue;

				int R_cnt = 0;//빨간공의 이동거리
				while (1) {
					if (map[nRx][nRy] == '#') break;
					if (map[nRx][nRy] == 'O')
					{//파란공도 같이 빠질 수 있으니까 flag 걸어놓자.
						R_flag = 1;
						break;
					}
					nRx += dx[i];
					nRy += dy[i];
					//해당방향으로 계속 이동해준다.
					R_cnt++;
				}
				nRx -= dx[i];
				nRy -= dy[i];

				int  B_cnt = 0;//파란공의 이동거리
				while (1) {
					if (map[nBx][nBy] == '#') break;
					if (map[nBx][nBy] == 'O') {
						B_flag = 1;
						break;
					}
					nBx += dx[i];
					nBy += dy[i];
					B_cnt++;
				}
				nBx -= dx[i];
				nBy -= dy[i];
				//만약 벽이면 이동하지 않는다

				
				//같은 곳에 도착했다면
				if (nRx == nBx && nRy == nBy) {
					if (R_cnt < B_cnt) {
						//멀리 굴러간 공의 위치를 반대방향으로 1 옮기기
						nBx -= dx[i];
						nBy -= dy[i];
					}
					else if (R_cnt > B_cnt) {
						nRx -= dx[i];
						nRy -= dy[i];
					}
				}

				if (R_flag && B_flag) {
					//B도 나왔기 때문에 -1 출력해야함
					ans = -1;
					continue;
				}
				else if (R_flag==0 && B_flag==1) {
					ans = -1;
					continue;
				}
				else if (R_flag==1 && B_flag==0) {
					//빨간공만 나왔다면
					cout << t;
					return 0;
				}
				if (visited[nRx][nRy][nBx][nBy]) continue;
				visited[nRx][nRy][nBx][nBy] = 1;
				q.push({ {nRx,nRy},{nBx,nBy} });//벽까지 이동한 위치
					
			}
		}
		t++;
		if (t >10) {
			cout << -1 ;
			return 0;
		}
		
	}
	if (ans == -1)
		cout << ans;
	return 0;
}
