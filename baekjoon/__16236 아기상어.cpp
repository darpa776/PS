#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n;//map 크기
int map[20][20];
int no_path[20][20];//상어의 size를 고려해 갈지말지
int visited[20][20];
vector<pair<int,pair<int,int>>> fish;//먹을 수 있는 물고기의 거리, 위치
//정렬순: first 오름차순, second.first 오름차순, second.second 오름차순
//매번 물고기를 먹고나서 크기를 고려해주고
//그다음에 fish 벡터를 초기화해준 후 다시 채워주고 sort해준다.
pair< pair<int, int>, pair<int, int>> shark;//크기, 먹은 물고기 수, 위치(x,y)
int ans_time = 0;

int eat(int x, int y) {
	shark.second.first = x;
	shark.second.second = y;
	shark.first.second++;
	if (shark.first.first == shark.first.second) {
		//상어가 먹은 물고기 수가 상어크기와 같으면 레벨업(사이즈업)해주고 먹은 물고기수 초기화
		shark.first.first++;
		shark.first.second = 0;
	}
	map[x][y] = 0;//해당 위치의 물고기는 사라짐
	return 0;
}
int bfs(int orgx, int orgy) {
	int dx[4] = {-1,1,0,0};
	int dy[4] = {0,0,-1,1};
	//상하좌우
	queue<pair<int,int>> q;
	q.push({ orgx, orgy });
	visited[orgx][orgy] = 0;
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n)
				continue;
			if (map[nx][ny] != 0 && map[nx][ny] < shark.first.first)//상어크기보다 작으면 fish 벡터에 넣는다.
			{
				visited[nx][ny] = visited[x][y] + 1;
				fish.push_back({ visited[nx][ny] ,{nx,ny} });
			}

			if (no_path[nx][ny] == 0 && visited[nx][ny] == -1) {
				q.push({ nx,ny });
				visited[nx][ny] =visited[x][y]+ 1;
			}
				
		}
	}
	if (fish.size() == 0) {
		cout << ans_time << endl;
		exit(0);
	}
	sort(fish.begin(),fish.end());//오름차순 정렬
	return 0;
}

void renew() {
	for (int i = 0; i < n; i++) {
		fill_n(no_path[i], n, 0);
	}//전부초기화해준후
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//상어의 크기보다 큰 물고기가 있는 곳만 지나갈 수 없다
			if (map[i][j] > shark.first.first)
				no_path[i][j] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		fill_n(visited[i], n, -1);
	}
	fish.clear();
	return;
}

int main(){
	cin >> n;
	shark.first.first = 2;
	int tmp = 0;//임시로 크기가 1인 물고기들을 세아림
	//만약 크기가 1인 물고기가 없으면 0출력, 종료
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				tmp++;
			}
			if (map[i][j] == 9) {
				shark.second.first = i;
				shark.second.second = j;
				map[i][j] = 0;
			}
		}
	}
	
	if (tmp == 0) {
		cout << 0 << endl;
		exit(0);
	}
	
	while (1)//먹은 물고기 수가 size를 만족할 때
	{
		//no_path 갱신, visited 초기화, fish 벡터 clear
		renew();
		//현재 위치에서 다음 물고기까지 갈 거리를 조사한다.
		bfs(shark.second.first, shark.second.second);
		//fish 벡터에 들어있는 물고기중 가장 가까운 물고기를 먹는다
		ans_time += fish.front().first;//물고기 잡아먹으러가는데 걸리는 시간
		eat(fish.front().second.first, fish.front().second.second);
	}
	
	return 0;
}
