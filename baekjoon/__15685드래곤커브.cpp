#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
//드래곤 커브의 개수
int n;
int x, y, d, g;//드래곤 커브의 시작점(y,x), 시작방향, 세대
int map[100][100];
//우상좌하=0,1,2,3
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
int dragon_curv[11][1024];
//0세대가 2의 0승인 1개, 3세대가 2의 3승인 8개 이므로 10세대는 2의 10승인 1024개일 것임
vector<pair<int, int>> real;
int ans = 0;

int make_gen(int gen) {
	for (int i = 0;i<pow(2,gen-1); i++) {
		dragon_curv[gen][i]=dragon_curv[gen-1][i];
	}
	int i = pow(2, gen - 1);
	for (int j = 1; j <= pow(2, gen - 1); j++) {
		//거꾸로 확인하면서 반시계방향으로 돌리기
		if (dragon_curv[gen - 1][i - j] == 3)
			dragon_curv[gen][i +j - 1] = 0;
		else {
			dragon_curv[gen][i +j -1] = dragon_curv[gen - 1][i - j] + 1;//반시계방향회전
		}
	}
	return 0;
}



int main()
{	//10까지의 드래곤 커브를 미리 만들자
	for(int i=0;i<=10;i++){
		fill_n(dragon_curv[i],1024, -1);//-1로 초기화
	}
	dragon_curv[0][0] = 0;
	for (int i = 1; i <= 10; i++) {
		make_gen(i);
	}
	
	/*for (int i = 0; i < 11; i++) {
		for (int j = 0; j < pow(2, i); j++) {
			cout << dragon_curv[i][j];
		}
		cout << endl;
	}*/

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin>> x>>y >> d >> g;
		//1. 방향만 넣은 벡터 만들기
		vector<int> dragon_dir;
		for (int j = 0; j < pow(2, g); j++) {
			int tmp = (dragon_curv[g][j] + d) % 4;
			dragon_dir.push_back(tmp);
		}
		
		//2. 실제 가야할 좌표를 넣은 벡터
		
		real.push_back({x,y});
		for (int i = 0; i < dragon_dir.size(); i++) {
			int nx = real.back().first + dx[dragon_dir[i]];
			int ny = real.back().second + dy[dragon_dir[i]];
			real.push_back({nx,ny});
		}
	}
	/*for (int i = 0; i < real.size(); i++) {
			cout << real[i].first << " " << real[i].second << endl;
		}*/
	//3. 벡터에서 중복되는 원소 제거
	sort(real.begin(), real.end());
	real.erase(unique(real.begin(), real.end()), real.end());
	/*for (int i = 0; i < real.size(); i++) {
		cout << real[i].first << " " << real[i].second << endl;
	}*/

	//4. 좌표의 주변칸을 모두 ++
	for (int i = 0; i < real.size(); i++) {
		int a= real[i].first; 
		int b = real[i].second;

		map[a][b]++;
		map[a][b - 1]++;
		map[a - 1][b - 1]++;
		map[a - 1][b]++;
	}
	//5. 모든 좌표를 탐색하는데, 그 값이 4이면 ans++
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] == 4)
				ans++;

		}
	}
	cout << ans;
	return 0;
}
