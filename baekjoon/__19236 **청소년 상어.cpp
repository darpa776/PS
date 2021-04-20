#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//상어가 먹을 수 있는 물고기 합의 최댓값
//16마리 밖에 되지 않으니 따로 fish 벡터를 만들어 주지는 않아도 됨
//pair<int, pair<int, int>> shark;//방향, 위치(x,y)
int dx[9] = { 0,-1,-1,0,1,1,1,0,-1 };//12시방향부터 반시계방향으로
int dy[9] = { 0,0,-1,-1,-1,0,1,1,1 };
int map[4][4][2];//물고기 번호, 방향
int ans=0;

void move_fish(int idx,int shark_x,int shark_y) {
	//만약 해당 물고기가 살아 있으면 자리를 옮긴다.
	//만약 옮기는 곳에 물고기가 죽어있어도 자리를 옮긴다.
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (map[i][j][0] == idx)//원하는 물고기를 찾았으면
			{
				int dir = map[i][j][1];//이동하려는 물고기의 이동방향
				int cnt = 8;
				while (cnt--) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];
					if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) {//없는 공간이라면 회전해본다.
						dir++;
						if (dir == 9)
							dir = 1; 
						continue;
					}
					if (nx == shark_x && ny == shark_y) {//이동하려는 곳에 상어가 있으면 회전한다.
						dir++;
						if (dir == 9)
							dir = 1;
						continue;
					}
					if (map[nx][ny][0]) {//만약 이동하려는 곳에 물고기가 있다면
						//서로의 위치를 교환한다
						map[i][j][0] = map[nx][ny][0];//이동해올 물고기의 번호
						map[i][j][1] = map[nx][ny][1];//이동해올 물고기의 방향정보
						map[nx][ny][0] = idx;
						map[nx][ny][1] = dir;
						break;
					}
					else if (map[nx][ny][0] == 0) {//이동하려는 곳에 물고기가 없다면
						map[i][j][1] = map[nx][ny][1];
						map[i][j][0] = 0;
						map[nx][ny][0] = idx;
						map[nx][ny][1] = dir;
						break;
					}

				}
				return;
			}
		}
	}
	return;
}

void check_shark(int x, int y) {
	////상어의 방향대로 이동
	////물고기가 없으면 이동하지 않는다
	//while (1) {
	//	int nx = x + dx[shark.first];
	//	int ny = y + dy[shark.first];
	//	if (map[nx][ny] == 0) continue;
	//	else if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) return;
	//	else
	//		go(map, nx, ny);
	//}
	//
}

void copy(int a[4][4][2], int b[4][4][2]) {//a배열을 b배열로 복사함
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 2; k++)
				b[i][j][k] = a[i][j][k];
	return;
}
void go(int shark_x, int shark_y,int sum) {

	//1. shark_x, shark_y에 도착해서 해당 위치의 물고기를 잡아먹는다
	sum += map[shark_x][shark_y][0];
	map[shark_x][shark_y][0] = 0;
	int dir = map[shark_x][shark_y][1];
	
	//2. 물고기를 번호순대로 이동시킨다.
	for(int i=1;i<=16;i++)
		move_fish(i,shark_x,shark_y);
	//3. 상어가 이동가능한 위치를 확인해보자
	//check_shark(shark_x, shark_y);
	//상어의 방향대로 이동
	//물고기가 없으면 이동하지 않는다
	int nx = shark_x + dx[dir];
	int ny = shark_y + dy[dir];
	while (1) {
		if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) { 
			ans = max(ans, sum);
			return; 
		}
		if (map[nx][ny][0]){
			int tmp[4][4][2];
			copy(map, tmp);
			go(nx, ny,sum);
			copy(tmp, map);
		}
		nx += dx[dir];
		ny += dy[dir];
	}
	return;
}

int main() {

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int num, dir;
			cin >> num >> dir;
			map[i][j][0] = num;
			map[i][j][1] = dir;
		}
	}
	//상어가 0,0에서부터 시작한다.
	go( 0, 0,0);
	//상어가 먹을 수 있는 물고기 번호의 최댓값은?
	cout << ans << endl;
	return 0;
}
