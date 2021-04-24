#include <iostream>
using namespace std;
//마법사 상어와 토네이도

int map[500][500];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
//좌하우상
int out = 0;

int tor[4][5][5] = {//왜 -1인가
{{0,0,2,0,0},
{0,10,7,1,0},
{5,-1,0,0,0},
{0,10,7,1,0},
{0,0,2,0,0}}//좌
,

{{0,0,0,0,0},
{0,1,0,1,0},
{2,7,0,7,2},
{0,10,-1,10,0},
{0,0,5,0,0}}//하
,

{{0,0,2,0,0},
{0,1,7,10,0},
{0,0,0,-1,5},
{0,1,7,10,0},
{0,0,2,0,0}}//우
,

{{0,0,5,0,0},
{0,10,-1,10,0},
{2,7,0,7,2},
{0,1,0,1,0},
{0,0,0,0,0}}//상

};
// 0.001 곱해준 후 int 처리(소수점 버리기)

int main() {
	
	int n;//격자 크기
	//격자에 있는 모래의 양을 의미
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	//격자의 중간부분 알아내기
	int x = n % 2 + 1;
	int y = n % 2 + 1;
	//좌하우상
	//1,1,2,2,3,3,4,4,5,5,6,6,7

	//dd방향마다 알파자리에 해당하는 인덱스 정하기
	pair<int, int> alpha[4] = { {0,-1},{1,0},{0,1},{-1,0} };


	//방향전환

	//중간부분에서부터 좌로 이동.
	int nx = x; int ny = y;
	int M = 0;//이동해야하는 횟수
	while (1) {
		if (nx == 0 && ny == 0) break;
		int m = 0;
		int k = 1;
		for (int dd = 0; dd <= 4; dd++) {//좌하우상
		//두번에 한번씩 M++;
			if (dd == 4)
				dd = 0;

			if (k == 1) {
				k++;//첫번째
				M++;
				m = 0;
			}
			else if (k == 2) {//두번째

				k = 1;
				m = 0;
			}
			while (M > m) {

				nx = x + dx[dd];
				ny = y + dy[dd];
				//모래양 계산 시작
				if (nx == 0 && ny == 0) {
					cout << out << endl; 
					exit(0);
				}

 				if (map[nx][ny]) {//현재 위치에 모래가 있는 경우에만 해준다.
					int amount = map[nx][ny];
					int spent = 0;
					for (int i = 2; i >= -2; i--) {
						for (int j = 2; j >= -2; j--) {
							if (nx - i < 0 || ny - j < 0 || nx - i >= n || ny - j >= n){
								int tmp = amount * tor[dd][-i + 2][-j + 2] / 100;
								if (tmp == 0) continue;
								out += tmp;
								spent += tmp;
							}
							else if (tor[dd][-i + 2][-j + 2] > 0){
								int tmp = amount * tor[dd][-i + 2][-j + 2] / 100;
								if (tmp == 0) continue;
								map[nx - i][ny - j] += tmp;
								spent += tmp;
							}
							
						}
					}
					
					int i = alpha[dd].first;
					int j = alpha[dd].second;
					map[nx +i][ny + j] += amount - spent;

					map[nx][ny] = 0;
				}
				x=nx ; y=ny;

				m++;

			}


		}
		
	}
	//중간 위치에서부터 시작, 왼쪽방향에서 먼저 시작(반시계방향 회전)
	//기준 위치로부터 한칸 더 전진하고 기준 위치를 변경해주기

	cout << out << endl;
	return 0;
}
