#include <vector>
#include <iostream>
using namespace std;

struct fireball {
	int mass;//질량
	int speed;//속력
	int dir;//방향
};
vector<struct fireball> map[50][50];
//vector<struct fireball> fireball;//질량 속력 방향
int n, m;//파이어볼 m개 발사
int k;//이동명령 횟수
int dx[8] = {-1,-1,0,1,1,1,0,-1};//12시방향으로부터 시계방향으로
int dy[8] = {0,1,1,1,0,-1,-1,-1};
//game_map과 map이 따로 논다
vector<struct fireball> game_map[50][50];

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int r, c, m, s, d;
		struct fireball tmp;
		cin >> r >> c >> m >> s >> d;
		tmp.mass = m;
		tmp.speed = s;
		tmp.dir = d;
		map[r][c].push_back(tmp);
	}

	int t = 1;
	while (1) {

		//1. 모든 파이어볼이 자신의 dir으로 speed만큼 이동한다.
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int l = 0; l < map[i][j].size(); l++) {
					struct fireball now = map[i][j][l];
					int direction = map[i][j][l].dir;
					int move = map[i][j][l].speed % n;

					int nx = i + dx[direction];
					int ny = j + dy[direction];
					move--;

					if (nx == 0)
						nx = n;
					if (ny == 0)
						ny = n;
					if (nx == n + 1)
						nx = 1;
					if (ny == n + 1)
						ny = 1;//테두리를 연결시켜주고 이동시키기

					while (move>0) {
						nx += dx[direction];
						ny += dy[direction];
						if (nx == 0)
							nx = n;
						if (ny == 0)
							ny = n;
						if (nx == n + 1)
							nx = 1;
						if (ny == n + 1)
							ny = 1;
						//테두리를 연결시켜주고 이동시키기
						
						move--;
					}
					game_map[nx][ny].push_back(now);
				}
			}
		}

		//2. 2개이상의 파이어볼이 있으면
		//4개의 파이어볼로 나누어
		//질량 속력 방향을 지정해준다.
		//질량=질량 합/5, 속력= 속력합/파이어볼 개수
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (game_map[i][j].size() <2) continue;
				int mass_sum = 0;
				int speed_sum = 0;
				int odd_even;//짝수인지 홀수인지 판단할 변수
				int flag = 0;//만약 flag가 0이면 dir가 0246, 1이면 1357
				for (int l = 0; l < game_map[i][j].size(); l++) {
					mass_sum+=game_map[i][j][l].mass;
					speed_sum+= game_map[i][j][l].speed;
					if (l == 0)
						odd_even = game_map[i][j][l].dir % 2;
					else if (odd_even != game_map[i][j][l].dir % 2)
						flag = 1;
				}

				int mem_cnt = game_map[i][j].size();
				game_map[i][j].clear();
				for (int l = 0; l < 4; l++) {//파이어볼 4개 생성
					struct fireball tmp;
					if (flag == 0)//0246
						tmp = { mass_sum / 5, speed_sum / mem_cnt, l * 2 };

					if (flag == 1)//1357
						tmp = { mass_sum / 5, speed_sum / mem_cnt, (l * 2) + 1 };

					game_map[i][j].push_back(tmp);
				}
			}
		}
		//파이어볼 방향: 모두 홀수나 짝수이면 1246, or not, 1357
		//질량 0인 파이어볼은 소멸된다.
		

		//초기화
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				map[i][j].clear();
			}
		}
		//map<-game_map
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int l = 0; l < game_map[i][j].size(); l++)
					map[i][j].push_back(game_map[i][j][l]);
			}
		}
		//game_map 초기화
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				game_map[i][j].clear();
			}
		}

		//마법사 상어가 이동을 k번 명령한 후, 남아있는 파이어볼 질량의 합?
		if (t == k) {
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					for (int l = 0; l < map[i][j].size(); l++) {
						ans+=map[i][j][l].mass;
					}
				}
			}
			cout << ans << endl;
			return 0;
		}
		t++;
	}
	return 0;
}
