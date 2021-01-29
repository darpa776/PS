#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define INF 1e9
using namespace std;

int main() {
	int n;
	int m;
	cin>> n >> m;
	int arr[101][101];
	for (int i = 0; i < 101; i++) {
		fill_n(arr[i], 101, INF);
	}
	
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		if (arr[x][y]!=INF) {
			arr[x][y] = min(arr[x][y], z);
			continue;
		}
		arr[x][y] = z;
	}
	for (int i = 1; i <= n; i++) {
		arr[i][i] = 0;
	}//시작도시와 도착도시가 같은 경우는 없다
	//arr 초기화 완료

	//플로이드 워셜 알고리즘 시작
	for (int k = 1; k <= n; k++) {
		//바깥쪽 반복문을 경유점으로 설정해야한다.
		//경유점을 설정하고 정점들을 돌아야하는 이유: https://cloge.tistory.com/28
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}
	//출력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j]>=INF)	arr[i][j] = 0;
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
