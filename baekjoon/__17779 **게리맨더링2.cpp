#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int map[21][21];

//최대 n이 20이고, 문제에서처럼 각 행열은 1로 시작하자.

//맨위 꼭짓점부터 시계방향으로
//x,y
//x+d2, y+d2
//x+d1+d2, y-d1+d2
//x+d1, y-d1

int cmp(int mark[21][21]) {
	int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) {
			switch (mark[i][j])
			{
			case 1:
				sum1 += map[i][j];
				break;

			case 2:
				sum2 += map[i][j];
				break;

			case 3:
				sum3 += map[i][j];
				break;

			case 4:
				sum4 += map[i][j];
				break;

			case 5:
				sum5 += map[i][j];
				break;

			}
		}
	}

	//각 선거구의 인구수를 비교한다.
	int max_num = max(max(max(max(sum1, sum2),sum3),sum4),sum5);
	int min_num = min(min(min(min(sum1, sum2), sum3), sum4), sum5);
	//선거구를 나누는 방법 중에서, 인구가 가장 많은 선거구와 가장 적은 선거구의 인구 차이의 최솟값을 구해보자.
	int ans = max_num - min_num;
	return ans;
}

int bound(int x, int y, int d1, int d2) {
	int mark[21][21];
	for (int i = 1; i <= n; i++)
		fill(mark[i] + 1, mark[i] + n+1, 5);

	//1선거구
	int tmp = 0;
	for (int r = 1; r < x + d1; r++){
		if (r >= x)
			tmp++;
		for (int c = 1; c <= y - tmp; c++){
			mark[r][c] = 1;
		}
	}

	//2선거구
	tmp = 0;
	for (int r = 1; r <= x + d2; r++) {
		if (r > x)
			tmp++;
		for (int c = y + 1+tmp; c <= n; c++) {
			mark[r][c] = 2;
		}
	}

	//3선거구
	tmp = d2+1;
	for (int r = x + d1; r <= n; r++) {
		if (r > x + d1 && r<=x+d1+d2)
			tmp--;
		for (int c = 1; c <= y-d1+d2-tmp; c++) {
			mark[r][c] = 3;
		}
	}
	
	//4선거구
	tmp = 0;
	for (int r = x + d2 + 1; r <= n; r++) {
		if (r > x + d2+1 && r<=x+d1+d2+1)
			tmp++;
		for (int c = y+d2- tmp; c <= n; c++) {
			mark[r][c] = 4;
		}
	}
	
	return cmp(mark);
}

bool check(int x, int y, int d1, int d2) {
	for (int i = 0; i <= d1; i++)
		if (x + i <= 0 || y - i <= 0 || x + i > n || y - i > n)
			return false;
	for (int i = 0; i <= d2; i++)
		if (x + i <= 0 || y + i <= 0 || x + i > n || y + i > n)
			return false;
	for (int i = 0; i <= d2; i++)
		if ((x +d1)+ i <= 0 || (y -d1)+ i <= 0 || (x + d1) + i > n || (y - d1) + i > n)
			return false;
	for (int i = 0; i <= d1; i++)
		if ((x + d2) + i <= 0 || (y +d2) - i <= 0 || (x + d2) + i > n || (y +d2) - i > n)
			return false;
	return true;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];
	//map에 인구수를 받음
	
	//선거구를 나누자
	int ans = 1e9;
	for (int x = 1; x <= n; x++) {//(x,y)가 제일 위 꼭짓점
		for (int y = 1; y <= n; y++) {
			for (int d1 = 1; d1 < n; d1++) {
				for (int d2 = 1; d2 < n; d2++) {
					//경계선이 map을 벗어나면 continue;
					if (check(x,y,d1,d2))
					{//적절한 경계선인지 확인
						ans=min(ans,bound(x, y, d1, d2));
						//적절한 경계선이면 지역구마다 인원수 비교
					}
				}
				
			}
			
		}
	}
	
	cout << ans << endl;
	return 0;
}
