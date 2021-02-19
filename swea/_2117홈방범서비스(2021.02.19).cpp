#include <iostream>
#include <vector>
#include <algorithm>
#define _crt_secure_no_warnings
#pragma warning(disable:4996)
using namespace std;

int testcase,t=0 ;
int n,m, ans,house=0;
int map[20][20];
int dx[4] = {-1,1,0,0};//상하좌우
int dy[4] = {0,0,-1,1};
int visited[20][20];
//int profit=0;//집이 내는 비용
//
//int dfs(int origin_x,int origin_y,int x, int y,int k,int install_cost) {//마스크의 중앙에서 시작
//	
//	
//	
//
//	if (map[x][y])//만약 집이 있으면
//	{
//		profit += m;
//		house += 1;
//	}
//
//	for (int i = 0; i < 4; i++) {
//		int nx = x + dx[i];
//		int ny = y + dy[i];
//
//		if (nx<0 || ny < 0 || nx >= n || ny>=n) continue;
//		if (abs(nx - origin_x) + abs(ny - origin_y) >= k) continue;
//		if (!visited[nx][ny]) {//방문하지 않은 곳만 dfs 수행
//			visited[nx][ny] = 1;
//			dfs(origin_x,origin_y,nx, ny, k, install_cost);
//		}
//		
//	}
//	return 0;
//}

int distance_check(int x, int y,int k) {
	for (int i = 0; i <n ; i++) {
		for (int j = 0; j < n; j++) {
			if (abs(i - x) + abs(j - y) < k)//k만큼 떨어진 거리에 있으면
			{
				//그자리에 집이 있는지 확인한다.
				if (map[i][j]) {
					house += 1;
				}
			}
		}
	}
	return house;
}

int main() {
	freopen("sample_input.txt", "r", stdin);
	
	cin >> testcase;
	while(t<testcase){
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin>>map[i][j];//집들의 위치를 입력받는다
		}
	}
	//k사이즈에 맞는 마스크는 중앙위치에서 k만큼 이동한 곳이면 마스크에 해당한다.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			//운영비용 계산하기
			int k = 1;
			while (k<= 2*(n-1)) {
				int install_cost = pow(k, 2) + pow(k - 1, 2);
				int profit= m* distance_check(i,j,k);
				int cost =  profit- install_cost;
				if (cost>=0)//손해를 보지 않는다=이익이 없어도 된다.//**
				{//서비스 제공가능한 세대 수를 저장한다.
					ans=max(house, ans);
				}
				k++;

				//손해를 보지 않는 선에서 가장 많은 집들에 서비스를 제공하기
				house = 0;
			}
			
		}
	}
	

	

	cout << "#" << t + 1 << " " << ans << endl;
	////초기화
	//
	ans = 0;
	for(int i=0;i<n;i++){
		fill_n(visited[i], n, 0);
		fill_n(map[i], n, 0);
	}

	t++;
	}
	return 0;
}
