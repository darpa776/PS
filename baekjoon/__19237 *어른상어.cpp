#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, m;//n*n 크기 격자, m개 칸에 상어가 있다.
int k;//냄새는 k초후 사라진다.
int map[20][20][2];//0에는 상어번호, 1에는 상어향기 시간
int dx[5] = {0,-1,1,0,0};//위, 아래, 왼, 오
int dy[5] = {0,0,0,-1,1};//상하좌우
vector<pair<pair<int,int>, pair<int,int>>> shark;//상어의 (idx 번호,방향), (위치)
int dir_prior[401][5][4];//m번째 상어, 현재 방향, 우선순위 방향

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j][0];//map에는 상어의 번호가 들어간다.
			if (map[i][j][0]) {
				map[i][j][1] = k;//상어 냄새 유효기간 설정
				shark.push_back({ {map[i][j][0],0 }, { i,j }});
			}
		}
	}
	//idx==0인 상어는 임의로 초기화해준다.
	shark.push_back({ {-1,-1}, {-1,-1} });
	sort(shark.begin(), shark.end());

	//각 상어의 현재 방향
	for (int i = 1; i <= m; i++) {
		int tmp;
		cin >> tmp;
		shark[i].first.second = tmp;
	}
	//각 상어의 방향 우선순위
	for (int i = 1; i <= m; i++) {
		//상하좌우
		for (int j = 1; j <= 4; j++) {
			for (int k = 0; k < 4; k++) {
				cin >> dir_prior[i][j][k];
				//i번째 상어의 j 방향에서의 방향 우선순위를 저장
			}
		}
	}
	int tmp_map[20][20][2];
	int t = 1;
	while (t) {
		//상어 냄새 --
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j][1])
					map[i][j][1]--;
				else//연산을 다 끝내고 0이 된 칸에는 상어번호도 초기화
					map[i][j][0] = 0;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int l = 0; l < 2; l++) {
					tmp_map[i][j][l] = map[i][j][l];
				}
			}
		}

		//1. 상어의 idx 순서대로 이동을 시작하자
		for (int i = 1; i <= m; i++) {
			//shark[i].first.first==i 인지 확인
			//이때 죽은 상어는 shark[i].first.first가 -1일 것임
			if (shark[i].first.first != i) continue;
			int x = shark[i].second.first;
			int y = shark[i].second.second;
			int dir_origin = shark[i].first.second;//상어방향

			for (int l = 0; l < 8; l++) {
				int dir = dir_prior[i][dir_origin][l % 4];//i번째 상어가 현재 dir 방향일때의 이동 우선순위
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				//방향 우선순위에 따라 방향변경 중 아무 냄새가 없는 칸으로 이동
				if (l < 4 && map[nx][ny][0] == 0) {
					//아무도 건드리지 않은 칸이라면
					//이동을 시작했을 때는 아무도 건드리지 않았던 칸이라도 이동중에 다른 상어가 먼저 쨈쳤을수도 있다.

					if (tmp_map[nx][ny][0]) {//이전에 온 상어가 있다면
						//번호가 더 작은 상어가 살아남는다
						//2. 같은 상어에 도착하는 상어중 번호가 작은 상어가 살아남는다
						if (tmp_map[nx][ny][0] > i) {//이전에 있던 상어와 현재 상어의 idx 번호 비교
							//현재 상어의 idx(i)가 더 작다면
							tmp_map[nx][ny][0] = i;//상어가 찜꽁
							tmp_map[nx][ny][1] = k;//냄새 유효기간 설정
							shark[i].first.second = dir;
							shark[i].second.first = nx;
							shark[i].second.second = ny;
							break;
						}
						else {
							//같은 칸에 모인 상어들끼리의 전쟁에서 패배함
							shark[i].first.first = -1;//죽음
							break;
						}
					}
					else {//만약 이전에 온 상어가 없다면
						tmp_map[nx][ny][0] = i;//상어가 찜꽁
						tmp_map[nx][ny][1] = k;//냄새 유효기간 설정
						shark[i].first.second = dir;
						shark[i].second.first = nx;
						shark[i].second.second = ny;
						break;
					}
				}
				//아무 상어도 건드리지 않은 칸이 없고
				//map[nx][ny][0]==i;(내번호)이면 진입한다.
				//내 냄새라면
				if (l >= 4 && map[nx][ny][0] == i) {
					tmp_map[nx][ny][0] = i;
					tmp_map[nx][ny][1] = k;
					shark[i].first.second = dir;
					shark[i].second.first = nx;
					shark[i].second.second = ny;
					break;
				}
				//다른 상어의 칸이면 pass;			
			}

		}


		//임시 map에서 정해진 사항을 진짜 map 에 넘겨주기
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int l = 0; l < 2; l++) {
					map[i][j][l] = tmp_map[i][j][l];
				}
			}
		}


		
		//1번 상어가 격자에 남아있는지 확인
		//1번 상어만 살아있는지 확인
		vector<int> check;
		for (int i = 0; i <= m; i++) {
			if(shark[i].first.first==i)
				check.push_back(i);//살아있는 상어의 idx를 저장
		}
		if (check.size() == 1){
			check[0] == 1;
			cout << t << endl;
			return 0;
		}
		
		check.clear();
		t++;
		if (t > 1000) {
			cout << -1 << endl;
			return 0;
		}
	}

	//1000초가 넘어도 다른 상어가 격자에 남아 있으면 -1 출력하기
	return 0;
}
//1번 상어만 격자에 남기까지 걸리는 시간?
