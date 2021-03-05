#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
int n,m,x,y,k;
int map[20][20];
//동서북남: 1,2,3,4
int dx[5] = {0,0,0,-1,1};
int dy[5] = {0,1,-1,0,0};
deque<int> dice1;//남북으로 이동하는 주사위
deque<int> dice_;//동서로 이동하는 주사위

int main()
{//지도의 가로세로길이, 주사위를 놓은 곳의 좌표, 명령의 개수
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	//처음 주사위는 다 0
	for (int i = 0; i < 4; i++) {
		dice1.push_back(0);
		dice_.push_back(0);
	}
	for (int i = 0; i < k; i++) {
		int command;
		cin >> command;
		
		int nx = x + dx[command];
		int ny = y + dy[command];

		if (nx<0||ny<0||nx>=n||ny>=m) continue;
		if (command == 1) {//동
			int tmp=dice_.back();
			dice_.push_front(tmp);
			dice_.pop_back();
			dice1[3] = dice_[3];
			dice1[1] = dice_[1];
		}
		else if (command == 2) {//서
			int tmp = dice_.front();
			dice_.push_back(tmp);
			dice_.pop_front();
			dice1[3] = dice_[3];
			dice1[1] = dice_[1];
		}
		else if (command == 3) {//북
			int tmp = dice1.front();
			dice1.push_back(tmp);
			dice1.pop_front();
			dice_[3] = dice1[3];
			dice_[1] = dice1[1];
		}
		else if (command == 4) {//남
			int tmp = dice1.back();
			dice1.push_front(tmp);
			dice1.pop_back();
			dice_[3] = dice1[3];
			dice_[1] = dice1[1];
		}
		
		//만약 지도의 값이 0이면 주사위의 바닥면을 흡수한다
		//만약 지도의 값(가로방향[3]==세로방향[3])이 0이 아니면 지도의 값을 흡수하고 지도는 0이 됨
		if (map[nx][ny] == 0) {
			map[nx][ny] = dice1[3];
		}
		else if (map[nx][ny] != 0) {
			dice1[3] = map[nx][ny];
			dice_[3] = map[nx][ny];
			map[nx][ny] = 0;
		}

		cout << dice1[1]<<endl;
		x = nx;
		y = ny;
	}
	
	return 0;
}
