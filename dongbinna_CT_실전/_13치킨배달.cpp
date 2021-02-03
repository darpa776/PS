#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	int map[51][51];
	vector<pair<int, int>> chicken;
	vector<pair<int, int>> house;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x;
			cin >> x;
			map[i][j] = x;
			if (x == 1) {//일반집이면
				house.push_back({ i,j });
			}
			else if (x == 2)//치킨집이면
			{
				chicken.push_back({ i,j });
			}
		}
	}
	//입력 완료
	//치킨 거리 계산
	//최대 임의의 m개 가게를 운영한다.
	vector<int> random(chicken.size());
	fill_n(random.end()-m, m, 1);

	vector<int> answer;
	do{
	int city_chickendist = 0;//도시의 치킨거리
	//주어진 random을 기준으로 도시의 치킨거리를 계산한다.
	for (int x = 0; x < house.size(); x++) {
		int chickendist = 1e9;//한 가정의 치킨거리
		for (int i = 0; i < chicken.size(); i++) {
			if (random[i]) {//현재 i번째 치킨집은 운영할 수 있는 경우

				int dist = abs(chicken[i].first - house[x].first) + abs(chicken[i].second - house[x].second);
				chickendist = min(chickendist, dist);
			}

		}
		city_chickendist += chickendist;
	}
	//한 random 경우의 도시의 치킨거리
	answer.push_back(city_chickendist);
	} while (next_permutation(random.begin(), random.end()));

	int ans = 1e9;//도시의 치킨거리 중에서도 제일 작은 최소값 구하기
	for (int i = 0; i < answer.size(); i++) {
		ans = min(ans, answer[i]);
	}
	cout << ans << endl;
	return 0;
}
