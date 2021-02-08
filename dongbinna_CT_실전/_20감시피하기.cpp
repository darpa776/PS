#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int map[7][7];
vector<pair<int, int>> obst;
vector<pair<int, int>> teacher;
int na[4] = {-1,1,0,0};
int nb[4] = {0,0,-1,1};


bool check() {
	//상하좌우 탐색
	for (int i = 0; i < teacher.size(); i++) {
		for (int j = 0; j < 4; j++) {
			int a = teacher[i].first;
			int b = teacher[i].second;
			while (1) {

				a += na[j];
				b += nb[j];
				if (a < 0 || b < 0 || a >= n || b >= n || map[a][b] == 3) {
					break;
				}
				else if (map[a][b] == 1)
					return false;//there's student
			}
		}
	}
	return true;
}

int main()
{
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char x;
			cin >> x;
			if (x == 'X')
			{
				map[i][j] = 0;
				obst.push_back({ i,j });
			}
			else if (x == 'S')
				map[i][j] = 1;
			else if (x == 'T')
			{
				map[i][j] = 2;
				teacher.push_back({ i,j });
			}
		}
	}

	//우선 빈공간에 장애물 넣을 공간을 무작위로 뽑기
	vector<int> binary(obst.size(),0);
	fill(binary.end()-3, binary.end(), 1);
	do {
		for(int i=0;i<binary.size();i++){
			if (binary[i])//장애물을 넣을 공간이라면
			{
				map[obst[i].first][obst[i].second] = 3;//장애물설치
			}

		}
		//장애물을 설치했을 때도 학생들이 선생님들에게 걸리는지 확인해보기
		if (check())
		{
			cout << "YES" << endl;//학생들이 안걸릴 수 있으면 yes 출력
			return 0;
		}
		else//원상복귀
		{
			for (int i = 0; i < binary.size(); i++) {
				if (binary[i])//장애물을 넣었던 공간이라면
				{
					map[obst[i].first][obst[i].second] = 0;//장애물 삭제
				}

			}
		}

	} while (next_permutation(binary.begin(),binary.end()));

	cout << "NO" << endl;//학생들이 걸릴수밖에 없으면 NO 출력
	return 0;
	
	
}
