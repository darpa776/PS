#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int r, c, n;
string input;
vector<int> stick;
char map[100][100];
int visited[100][100];
int dx[4] = {-1,1,0,0};//상하좌우
int dy[4] = {0,0,-1,1};
int group_num = 0;
vector<pair<int,int>> group;
int below[100];
int height = 1e9;
//int height[100];

bool key(pair<int,int> a, pair<int,int> b) {
		return a.first > b.first;
}
void dfs(int x,int y) {//클러스터가 묶여있는지 확인

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;//범위에 해당하지 않으면 pass
		if (map[nx][ny] == 'x' && visited[nx][ny]==0) {
			visited[nx][ny]= 1;
			group.push_back({ nx,ny });
			dfs(nx, ny);
		}
	}
	return;
}

void solve(int x, int y) {
	
	for (int i = 0; i < 100; i++) {
		fill_n(visited[i], 100, 0);
	}
	group.clear();
	
	for (int idx = 0; idx < 4; idx++) {

		int nx = x + dx[idx];
		int ny = y + dy[idx];
		if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;//범위에 해당하지 않으면 pass
		if (map[nx][ny] == 'x' && visited[nx][ny] == 0) {
			visited[nx][ny] = 1;
			group.push_back({ nx,ny });
			dfs(nx, ny);
		}
		else continue;

		//땅에 붙어있거나 밑에 미네랄이 존재하면 따로 하강시켜주지 않아도 된다.
		//below 벡터에는 각 열의 가장 아래 있는 좌표를 넣어야한다.
		fill_n(below, 100, -1);
		height = 1e9;
		for (int i = 0; i < group.size(); i++) {
			if (below[group[i].second] < group[i].first)
				below[group[i].second] = group[i].first;
		}

		int flag = 0;
		for (int j = 0; j < 100; j++) {
			if (below[j] == r - 1) {//땅에 붙어있는 경우
				flag = 1;
			}
		}
		if (flag) {//하강작업 안해줘도 됨
			for (int i = 0; i < 100; i++) {
				fill_n(visited[i], 100, 0);
			}
			group.clear();
			continue;
		}
		
		else if (flag == 0) {
			//맨밑행이 또다른 미네랄 또는 바닥을 만날때까지 하강할 길이 구하기
			//for (int j = 0; j < 100; j++) {//가장 적은 height만큼 이동하기
			//	if (below[j] >= 0) {
			//		for (int i = below[j]+1; i < r; i++) {
			//			if (map[i][j] == 'x') {//또다른 미네랄을 만날때까지 하강
			//				height = min(height, i - below[j]-1);
			//			}
			//			else if (i == r - 1) {//땅바닥을 만날때까지 하강
			//				height = min(height, i - below[j]);
			//			}
			//		}
			//	}
			//}
			//ㄷ자 모양의 클러스터일 경우 맨밑만 고려할게 아니라 다른 클러스터 위에 걸쳐질 수 있으므로 모두 조사해야함
			for (int idx = 0; idx < group.size(); idx++) {
				int x = group[idx].first;
				int y = group[idx].second;
				for (int i = x + 1; i < r; i++) {
					if (map[i][y] == 'x' && visited[i][y] == 0) {//다른 클러스터이고 x인 경우
						height = min(height, i - x - 1);
					}
					else if (i == r - 1) {//땅바닥을 만날때까지 하강
						height = min(height, i - x);
					}
				}

			}
			sort(group.begin(), group.end(), key);
			//그룹전체를 height만큼 이동
			for (int i = 0; i < group.size(); i++) {
				int x = group[i].first;
				int y = group[i].second;
				//if (x + height < r) {//**//
				map[x][y] = '.';
				map[x + height][y] = 'x';
				//}
			}
		}
		for (int i = 0; i < 100; i++) {
			fill_n(visited[i], 100, 0);
		}
		group.clear();
	}
	return;
}



int main()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin>>map[i][j];
		}
	}
	
	//막대를 던진횟수
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		stick.push_back(tmp);
	}//입력 끝
	
	//1. 왼쪽부터 창을 던진다
	for (int throw_idx = 0; throw_idx < n; throw_idx++) {
		int a = stick[throw_idx];
		if (throw_idx % 2 == 0) {//왼쪽에서 던짐
		//맨 아래 부터 1임: b(실제 idx)= r-a(던지는 행)
			for (int j = 0; j < c; j++) {
				if (map[r - a][j] == 'x') {
					//만약 가장 왼쪽에 미네랄이 있으면
					//해당 미네랄을 일단 제거한다.
					map[r - a][j] = '.';
					solve(r - a, j);
					break;
				}
			}
		}
		else {//오른쪽에서 창을 던진다.
			for (int j = c - 1; j >= 0; j--) {
				if (map[r - a][j] == 'x') {
					//만약 가장 오른쪽에 미네랄이 있으면
					//해당 미네랄을 일단 제거한다.
					map[r - a][j] = '.';
					solve(r - a, j);
					break;
				}

			}

		}
	}

	//전체 map 출력
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
	return 0;
}
