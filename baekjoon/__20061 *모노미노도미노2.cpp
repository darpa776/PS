#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;//블록을 놓은 횟수
vector<pair<int, pair<int, int>>> plan;
int green_map[6][6];
int blue_map[6][6];
//내가 푸는대로 풀면 시간초과 날수도 있겠다..
//out of bound 에러: 배열의 위치가 벗어난 곳에 접근
int score = 0;

void green(int t, int x, int y) {
	//빨간색칸들과 열의 숫자가 같다.
	//해당 열에서 가장 위칸은 어디인지 파악한다.
	int ans = 0;
	int ans2 = 0;
	if (t == 1) {
		ans = 0;
		while (1) {
			if (green_map[ans][y] || ans == 6)
				break;
			ans++;
		}
		green_map[ans-1][y] = 1;
	}

	else if (t==2) {
		ans = 0;
		while (1) {
			if (green_map[ans][y]||ans==6)//왼쪽
				break;
			ans++;
		}
		ans2 = 0;
		while (1) {
			if (green_map[ans2][y + 1] || ans2 == 6)//오른쪽
				break;
			ans2++;
		}
		ans = min(ans2, ans);//더 위에 있는 칸에 놓는다.
		green_map[ans - 1][y] = 1;
		green_map[ans - 1][y + 1] = 1;
	}
	
	else if (t == 3) {//(x,y),(x,y+1): 위아래
		ans = 0;
		while (1) {
			if (green_map[ans][y]||ans==6)
				break;
			ans++;
		}
		green_map[ans - 1][y] = 1;
		green_map[ans - 2][y] = 1;
	}
	//색을 칠해준다.


	if (ans - 1 > 1) {
		//놓여진 칸들이 모두 채워져있으면 그 행을 삭제
		//점수추가
		//위의 행을 아래로 밀기
		int push[3] = { 0, 1,1 };
		for (int j = 0; j < 4; j++) {
			if (green_map[ans - 1][j] == 0)
				push[1] = 0;
			if (green_map[ans - 2][j] == 0)
				push[2] = 0;
			//한줄이라도 칠해지지 않은 곳이 있으면 삭제해주지 않는다.
		}
		if (push[1]) {
			for (int i = ans-2; i >= 0; i--) {
				for (int j = 0; j < 4; j++) {
					green_map[i+1][j] = green_map[i][j];
				}
			}
			fill_n(green_map[0], 4, 0);

			score++;
		}
		if (push[2]) {
			for (int i = ans-3; i >= 0; i--) {
				for (int j = 0; j < 4; j++) {
					green_map[i+1][j] = green_map[i][j];
				}
			}
			fill_n(green_map[0], 4, 0);

			score++;
		}
	}


	else if (ans - 1 <= 1) {
		//만약 0행,1행에 놓였으면 맨아래 행을 없애 주고 한칸씩 밀어준다
		//0행에 놓였으면 2칸 밀어주고, 1행에 놓였으면 1칸을 밀어야한다
		//점수없음
		int flag;
		if (t== 3)//ans-2: 최소 0행, 가장 높은 곳
			flag = 2;
		else
			flag = 1;
		while (flag--) {
			for (int i = 4; i >= 0; i--) {
				for (int j = 0; j < 4; j++) {
					green_map[i + 1][j] = green_map[i][j];
				}
			}
			fill_n(green_map[0], 4, 0);
		}


	}
	
	return;
}

void blue(int t, int x, int y) {
	//빨간색칸들과 행의 숫자가 같다.
	//해당 열에서 가장 위칸은 어디인지 파악한다.
	int ans = 0;
	int ans2 = 0;
	if (t == 1) {
		ans = 0;
		while (1) {
			if (blue_map[x][ans] || ans == 6)
				break;
			ans++;
		}
		blue_map[x][ans - 1] = 1;
	}
	else if (t == 2) {
		ans = 0;
		while (1) {
			if (blue_map[x][ans] || ans == 6)
				break;
			ans++;
		}
		blue_map[x][ans - 1] = 1;
		blue_map[x][ans - 2] = 1;
	}

	else if (t == 3) {
		ans = 0;
		while (1) {
			if (blue_map[x][ans] || ans == 6)
				break;
			ans++;
		}
		ans2 = 0;
		while (1) {
			if (blue_map[x+1][ans2]|| ans2 == 6)
				break;
			ans2++;
		}
		ans = min(ans2, ans);//더 위에 있는 칸에 놓는다.
		blue_map[x][ans - 1]= 1;
		blue_map[x+1][ans - 1] = 1;
	}

	
	//색을 칠해준다.
	if (ans - 1 > 1) {
		//놓여진 칸들이 모두 채워져있으면 그 행을 삭제
		//점수추가
		//왼쪽의 행을 오른쪽으로 밀기
		int push[3] = { 0, 1,1 };
		for (int i = 0; i < 6; i++) {
			if (blue_map[i][ans - 1] == 0)
				push[1] = 0;
			if (blue_map[i][ans - 2] == 0)
				push[2] = 0;
			//한줄이라도 칠해지지 않은 곳이 있으면 삭제해주지 않는다.
		}
		if (push[1]) {
			for (int j = ans - 2; j >= 0; j--) {
				for (int i = 0; i < 4; i++) {
					blue_map[i][j+1] = blue_map[i][j];
				}
			}
			for (int i = 0; i < 4; i++) {
				blue_map[i][0] = 0;
			}

			score++;
		}
		if (push[2]) {
			for (int i = ans - 3; i >= 0; i--) {
				for (int j = 0; j < 4; j++) {
					blue_map[i][j+1] = blue_map[i][j];
				}
			}
			for (int i = 0; i < 4; i++) {
				blue_map[i][0] = 0;
			}

			score++;
		}
	}


	else if (ans - 1 <= 1) {
		//만약 0행,1행에 놓였으면 맨아래 행을 없애 주고 한칸씩 밀어준다
		//0행에 놓였으면 2칸 밀어주고, 1행에 놓였으면 1칸을 밀어야한다
		//점수없음
		int flag;

		if (t==2)
			flag = 2;
		else
			flag = 1;
		while (flag--) {
			for (int j = 4; j >= 0; j--) {
				for (int i = 0; i < 4; i++) {
					blue_map[i][j + 1] = blue_map[i][j];
				}
			}
			for (int i = 0; i < 4; i++) {
				blue_map[i][0] = 0;
			}
		}


	}
	return;
}

int main() {
	cin >> n;
	for (int p = 0; p < n; p++) {
		//블록을 놓은 정보
		int t, x, y;
		cin >> t >> x >> y;//t블록을 x,y 위치에 둚
		//초록색 블록에 놓는다

		green(t, x, y);


		//파란색 블록에 놓는다

		blue(t, x, y);
	}
	cout << score << endl;
	//얻은 점수와 초록색 보드와 파란색 보드에 타일이 있는 칸의 개수 세아리기
	int cnt = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (green_map[i][j])
				cnt++;
			if (blue_map[i][j])
				cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
