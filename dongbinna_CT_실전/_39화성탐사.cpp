#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

int map[125][125];
int arr[125][125];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
priority_queue<pair<int, pair<int, int>>> pq;

int main() 
{
	int testcase;
	cin >> testcase;
	int t = 0;
	while (testcase > t) {
		int n;
		cin >> n;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin>>map[i][j];
			}
		}
		//map입력받기 완료
		for (int j = 0; j < n; j++) {
			fill_n(arr[j], 125, INF);
		}
		arr[0][0] = map[0][0];
		//0,0부터 다익스트라 시작
		pq.push({ -map[0][0],{0,0} });

		while (!pq.empty()) {
			int dist = -pq.top().first;
			int y = pq.top().second.first;
			int x = pq.top().second.second;
			pq.pop();
			if (arr[y][x] < dist) continue;
			//다른 큐를 꺼내서 최소비용을 갱신하는 동안( arr가 dist 보다 작아졌을 경우) 이미 방문한 노드임
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny >= 0 && nx >= 0 && ny < n && nx < n)
				{
					// 현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우
					if (dist + map[ny][nx] < arr[ny][nx]) {
						arr[ny][nx] = dist + map[ny][nx];
						pq.push({ -arr[ny][nx], {ny, nx} });
					}
					//위의 코드와 똑같지만 기존 arr값이 아닌 새로운 값으로 갱신되는 경우만 큐에 넣는다
					//arr[ny][nx] = min(dist + map[ny][nx], arr[ny][nx]);
					//pq.push({ -arr[ny][nx],{ny,nx} });
				}
			}
		}
		cout << arr[n - 1][n - 1] << endl;
		t++;
	}
	return 0;
}
