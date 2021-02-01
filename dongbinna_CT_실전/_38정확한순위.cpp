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
	int arr[501][501];
	for (int i = 0; i < 501; i++) {
		fill_n(arr[i], 501, INF);
	}
	
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		arr[x][y] = 1;
	}
	for (int i = 1; i <= n; i++) {
		arr[i][i] = 0;
	}
	//arr 초기화 완료

	//플로이드 워셜 알고리즘 시작
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}
	//출력
	int person = 0;
	
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			//**특정노드로 들어오거나 나가는 것이 있으면 비교가 가능하다
			//A노드로 들어오는 B: B<A
			//A노드에서 나가서 B에 도착: A<B
			//따라서 두 경우 중 하나라도 만족하면 비교가능한것이 됨
			if (arr[i][j] < INF || arr[j][i] < INF) cnt++;
			
		}
		if (cnt==n)//모든 노드에 대해 비교가능하면
			//자기자신도 비교가능하다 가정했을 때 자기노드는 제외한 모든 노드는 비교가능해야하므로 cnt가 node수 일때
			person++;
	}//모든 사람에 대해 비교가능한(순위를 알 수 있는) 사람 수를 출력
	cout << person << " ";
	return 0;
}
