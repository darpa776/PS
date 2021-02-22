#include <iostream>
#include <queue>
#include <algorithm>
#define max 200000

using namespace std;

int n, k, ans;
//일반적으로 bfs는 그래프의 경우 방문했는지 여부를 안남겨도 되지만
//이 문제는 중복되는 수를 다시 방문하는 경우도 있으므로 visited 배열을 사용해주어야한다.

//max값과 visited 배열을 사용하는 것이 이 문제가 다른 일반적인 bfs와 다른 차이점임

//일반적으로 bfs는 visited에 먼저 들어가는 친구가 가장 최소의 비용임
//그래서 visit하기만 하면 그 값이 가장 작은 값임

int visited[200001];

int main() {
	fill_n(visited, 200001, -1);

	cin >> n >> k;
	//수빈이(n)는 걷거나 순간이동
	//걸으면 x+1 또는 x-1
	//순간이동하면 2*x 위치로 이동
	//n->k가 될 수 있는 가장 빠른 시간 구하기

	queue<pair<int,int>> q;
	q.push({ n,0 });//수빈이는 현재 n위치에 있다.

	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();
		visited[x] = cnt;
		

		if (x == k)//수빈이가 동생을 찾았으면 움직인 시간을 출력한다.
		{
			ans = cnt;
			break;
		}

		//cnt++;
		if (x + 1 <= max && visited[x + 1] == -1) {//방문한 적이 없으면
			q.push({ x + 1, cnt + 1 });
		}
		if (x - 1 >= 0 && visited[x - 1] == -1) {
			q.push({ x - 1, cnt + 1 });
		}
		if (x * 2 <= max && visited[x * 2] == -1) {
			q.push({ x * 2, cnt + 1 });
		}
		
		
	}


	cout << ans << endl;
	
	return 0;
}
