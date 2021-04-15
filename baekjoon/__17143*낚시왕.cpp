#include <iostream>
#include <vector>
using namespace std;
//낚시왕이 오른쪽으로 한 칸 이동한다.
int dx[5] = {0,-1,1,0,0};//상,하,우,좌
int dy[5] = {0,0,0,1,-1};
int r, c, m;
int map[102][102];
vector<struct shark> shark;//생사여부와 크기, 속력과 이동방향

struct shark {
	int live=1;
	int size;
	int vel;
	int dir;
	int x;
	int y;
};

int main() {
	cin >> r >> c >> m;
	for (int i = 1; i <= r; i++) {
		fill(map[i] + 1, map[i] + 1 + c, -1);
	}
	for (int i = 0; i < m; i++) {
		//상어의 수:m
		int x, y, s, d, z;
		cin >> x >> y >> s >> d >> z;
		map[x][y] = i;//i번째 상어
		struct shark tmp = {1,z,s,d, x, y };
		shark.push_back(tmp);
	}

	int t = 1;//낚시왕의 위치
	int sum = 0;//낚시왕이 잡은 상어 크기의 합
	while(t<=c){

		//낚시왕이 있는 열에 있는 상어 중에서 땅과 제일 가까운 상어를 잡는다. 상어를 잡으면 격자판에서 잡은 상어가 사라진다.
		for (int i = 1; i <= r; i++) {
			if (map[i][t]>=0) {
				sum += shark[map[i][t]].size;//상어 크기 저장
				shark[map[i][t]].live = 0;//죽음
				map[i][t] = -1;
				break;//더이상 상어를 잡지 않는다.
			}
		}

		//상어가 이동한다.
		int tmp_map[102][102];//상어들이 이동할 동안 쓸 임시 map
		for (int i = 1; i <= r; i++) {
			fill(tmp_map[i] + 1, tmp_map[i] + 1 + c, -1);
		}

		for (int i = 0; i < m; i++) {
			if (shark[i].live)//살아 있는 상어라면
			{
				//이동방향으로 속도만큼 이동
				int tmp = shark[i].vel;

				//시간초과가 발생하기 때문에 상어가 이동할 칸(tmp)을 줄여주자
				if (shark[i].dir <= 2) {//상하로 움직이는 경우
					tmp = tmp % ((r - 1) * 2);//제자리로 돌아온다
				}
				else {//좌우로 움직이는 경우
					tmp = tmp % ((c - 1) * 2);
				}
				int nx, ny;
				if (tmp == 0)
				{
					nx = shark[i].x;
					ny = shark[i].y;
				}
				else
				{//**여기서 자꾸 뭐가 굉장히 안맞음
					//상어의 현재 위치가 테두리칸이라면 방향을 바꿔서 전진시켜준다
					if((shark[i].x == 1 && shark[i].dir ==1) || (shark[i].y == 1 && shark[i].dir ==4) || (shark[i].x == r && shark[i].dir == 2) || (shark[i].y == c && shark[i].dir ==3)){
						//방향바꿔주기
						if (shark[i].dir % 2 == 0) {
							shark[i].dir--;
						}
						else {
							shark[i].dir++;
						}
					}
					nx = shark[i].x + dx[shark[i].dir];
					ny = shark[i].y + dy[shark[i].dir];
					tmp--;
					
					while (tmp--) {

						//테두리칸에 도착하면 방향을 반대로 바꿔서 속력을 유지한채로 이동한다.
						if ((nx == 1 && shark[i].dir==1)|| (ny == 1 && shark[i].dir ==4 ) || (nx == r && shark[i].dir == 2) || (ny ==c && shark[i].dir==3)) {
							//방향바꿔주기
							if (shark[i].dir % 2 == 0) {
								shark[i].dir--;
							}
							else {
								shark[i].dir++;
							}
							
						}
					
						nx += dx[shark[i].dir];
						ny += dy[shark[i].dir];
						
					}
					
				}
				//이동완료

				if (tmp_map[nx][ny] >= 0) {//만약 이동한 곳에 상어가 있다면 크기가 큰 상어가 이미 있던 상어를 잡아 먹는다
					if (shark[tmp_map[nx][ny]].size > shark[i].size) {//새로 이동한 상어가 더 작고, 원래 있었던 상어가 더 크면
						shark[i].live = 0;//새로 도착한 상어는 죽음
					}
					else {//새로 도착한 상어가 더 크면
						shark[tmp_map[nx][ny]].live = 0;//원래 있던 상어는 죽음
						tmp_map[nx][ny] = i;//크기가 큰 상어 idx로 덮어쓰기
						shark[i].x = nx;
						shark[i].y = ny;
					}
						
				}
				else {//도착한 곳에 상어가 아무도 없는 경우
					tmp_map[nx][ny] = i;
					shark[i].x = nx;
					shark[i].y = ny;
				}
				
			}
		}

		//임시 map으로 map을 변경
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				map[i][j] = tmp_map[i][j];
			}
		}


		t++;//낚시왕 이동
	}
	cout << sum << endl;//낚시왕이 잡은 상어크기의 합
	
	return 0;
}
