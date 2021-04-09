#include <iostream> 
#include <algorithm>
using namespace std;

int n, m, h;//세로선, 가로선, 세로선마다 가로선을 놓을 수 있는 위치의 개수
int map[32][12];
//추가해야하는 가로선이 3개 이상이면 -1을 출력
int ans = 1e9;

bool play() {
	for (int j = 1; j <= n; j++) {
		int i = 1;
		int start = j;
		while (i<=h) {
			
			if (map[i][j - 1] == 1)
				j--;
			else if(map[i][j] == 1)
				j++;
			i++;
		}
		int end = j;
		if (start != end)
			return false;//가로선 추가 필요
	}
	return true;
}

void dfs(int x, int cnt) {
	if (cnt > 3)
		return;
	if (play()) {
		ans = min(ans, cnt);
		return;
	}
	//가로선을 놓을 수 있는 모든 경우를 탐색하면 시간초과
	//현재위치를 전달해서 현재 위치 이후부터 놓도록 하자
	for (int i = x; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			//y까지 전달하면 다음 행에 넘어갈때 못넘어감

			//그냥 이중 for문 차례대로 탐색
			if (map[i][j] || map[i][j - 1] || map[i][j + 1])
				continue;
			map[i][j] = 1;
			dfs(i, cnt + 1);
			map[i][j] = 0;
		}
	}
	return;
}

int main() {
	cin >> n >> m >> h;
	//m개의 가로선 정보
	for (int i = 0; i < m; i++) {
		int a, b;

		cin >> a >> b;
		map[a][b] = 1;
	}

	if (play() == true)//i선에서 시작해서 i선으로 끝난다면
	{
		cout << 0 << endl;
		return 0;
	}
	//dfs
	//적용하려는 visited 배열의 왼쪽, 오른쪽이 1이면 적용할 수 없다.
	dfs(1,0);
	//사다리를 만들자(최소개수로 추가)
	if (ans == 1e9)
		ans = -1;
	cout << ans << endl;
	return 0;
}
