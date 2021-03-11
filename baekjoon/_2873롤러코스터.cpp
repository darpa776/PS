#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int r, c;
int map[1000][1000];
string ans; 
int minv = 1e9;
pair<int, int> no;

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin>>map[i][j];
			if ((i + j) % 2 == 1 && minv > map[i][j]) {//홀짝 또는 짝홀인 좌표(=더해서 홀수)이고 최소값을 가지면
				minv = map[i][j];//최소값 갱신해주고
				no = {i,j};//건드리면 안되는 곳도 갱신해주기
			}
		}
	}

	//case분류, 짝홀, 홀짝, 홀홀
	if (r % 2 == 0 && c % 2 == 1) {//짝홀
		//아래 위로

			//맨마지막 지점까지 접근하면 안됨
		for (int j = 0; j < c; j++) {
			for (int i = 0; i < r - 1; i++) {
				if (j % 2 == 0)
					ans += 'D';
				else if (j % 2 == 1)
					ans += 'U';
			}
			if (j != c - 1)
				ans += 'R';
		}
	}
	else if (r % 2 == 1) {//홀짝과 홀홀
		//좌우로
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c - 1; j++) {
				if (i % 2 == 0) {
					ans += 'R';
				}
				else if (i % 2 == 1) {
					ans += 'L';
				}
			}
			if (i != r - 1)//마지막행빼고 D써준다
				ans += 'D';
		}
	}
	else if (r % 2 == 0 && c % 2 == 0) {//짝짝
		int no_x = no.first;
		int no_y = no.second;
		
		for (int i = 0; i < r-1; i++) {
			for (int j = 0; j < c - 1; j++) {
				if (no_x == r - 1)//접근하지 않은 좌표가 맨 마지막 행에 있다면
				//마지막행까지 다 접근해줘야한다.
				{
					if (no_x-1 == i) {
						if (j < no_y)//no 좌표만나기 전에는 
							if (j % 2 == 1)
								ans += "UR";
							else
								ans += "DR";

						if (j >= no_y)//no 좌표만나고 난후 에는
							if (j % 2 == 0)
								ans += "RD";
							else
								ans += "RU";
							
					}

					else {
						if (i % 2 == 0) {
							ans += 'R';
						}
						else if (i % 2 == 1) {
							ans += 'L';
						}
					}
				}
				else {//no가 마지막행이 아니면
					if (no_x % 2 == 0) {//접근하지 말아야할 좌표가 짝수행에 있을때
						if (no_x == i) {
							if (j < no_y)
								if (j % 2 == 1)
									ans += "UR";
								else
									ans += "DR";

							if (j >= no_y)
								if (j % 2 == 1)
									ans += "RU";
								else
									ans += "RD";
						}

						else {
							if (i % 2 == 0) {
								ans += 'R';
							}
							else if (i % 2 == 1) {
								ans += 'L';
							}
						}
					}
					if (no_x % 2 == 1) {//접근하지 말아야할 행이 홀수인 경우
						if (no_x == i) {
							if (j < c - no_y - 1)
							{
								if (j % 2 == 1)
									ans += "UL";
								else
									ans += "DL";
							}
							if (j >= c - no_y - 1)
							{
								if (j % 2 == 1)
									ans += "LU";
								else
									ans += "LD";
							}
						}
						else {
							if (i % 2 == 0) {
								ans += 'R';
							}
							else if (i % 2 == 1) {
								ans += 'L';
							}
						}
					}
				}
			}
			if (i != r - 2)//마지막행빼고 D써준다
			{
				ans += 'D';
			}
		}
	}
	cout << ans << endl;
	return 0;
}
