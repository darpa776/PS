#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//상어가 먹을 수 있는 물고기 합의 최댓값
pair<int,pair<int, int>> shark;//방향, 위치(x,y)
vector< pair<pair<int,int>,  pair<int, int>>> fish;//물고기 번호, 위치(x,y)
//int fish_life[17];
int dx[9] = {0,-1,-1,0,1,1,1,0,-1};//12시방향부터 반시계방향으로
int dy[9] = {0,0,-1,-1,-1,0,1,1,1};
int map[4][4];//물고기 번호, 방향

void fish_move() {

	for (int i = 1; i < fish.size(); i++) {
		//물고기가 있는 칸이라면 해당 칸에 있는 물고기와 위치를 바꾼다.
		int x = fish[i].second.first;
		int y = fish[i].second.second;
		int dir = fish[map[x][y]].first.second;

		if (map[x][y] == 0) continue;//죽은 물고기라면 다음 물고기로 넘어간다.
		int cnt = 8;
		while (cnt--) {
			
			int nx = x + dx[dir]; int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) {//존재하지 않는 칸이라면 반시계방향으로 회전해본다.
				dir = (dir + 1) % 8;
				continue;
			}
			if (shark.second.first == nx && shark.second.second == ny) {//상어가 있는 칸이라면 반시계방향으로 회전해본다.
				dir = (dir + 1) % 8;
				continue;
			}

			//회전한 곳에 있는 물고기와 변경한다.
			if (map[nx][ny]) {
				int tmp;
				//현재 위치에 새로운 위치의 물고기 정보를 기록
				tmp = fish[map[x][y]].first.first;
				fish[map[x][y]].first.first = fish[map[nx][ny]].first.first;//물고기 번호
				fish[map[nx][ny]].first.first = tmp;
				tmp = fish[map[x][y]].first.second;
				fish[map[x][y]].first.second = fish[map[nx][ny]].first.second;//물고기 방향
				fish[map[nx][ny]].first.second = tmp;
				
				fish[map[x][y]].second.first = nx;//물고기 위치
				fish[map[x][y]].second.second = ny;
				fish[map[nx][ny]].second.first = x;
				fish[map[nx][ny]].second.second = y;

				tmp = map[x][y];
				map[x][y] = map[nx][ny];
				map[nx][ny] = tmp;
				sort(fish.begin(), fish.end());
			}
		}

	}

	return;
}
//물고기의 번호는 map에 저장되어 있고
//물고기의 정보는 fish에 저장되어 있다.
//map이 0이면 해당 물고기에 접근하지 않는다.

int main() {
	//물고기 번호와 방향이 순서대로 주어진다.
	fish.push_back({{ 0, 0}, {0, 0}});//물고기 번호, 방향, 위치(x,y)
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int num, dir;
			cin >> num >> dir;
			map[i][j] = num;
			//물고기 번호를 map에 입력한다.

			fish.push_back({ {num,dir}, {i,j} });
			//물고기를 번호순대로 접근하기 위해 벡터에 번호를 저장
		}
	}
	sort(fish.begin(), fish.end());
	//상어가 0,0에 들어온다.
	shark.second.first = 0;
	shark.second.second = 0;
	shark.first = fish[map[0][0]].first.second;//물고기 방향을 상어가 흡수한다.
	map[0][0] = 0; //물고기가 잡아먹힌다.
	
	//물고기가 이동한다.
	//물고기 번호가 작은 순서대로 이동한다.
	fish_move();
	

	return 0;
}
