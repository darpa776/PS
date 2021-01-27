#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//dp는 내 위치에서 최대값이 되게 하는 것
int map[20][20];
int arr[20][20];
//위, 동, 아래
int di[3] = { -1,0,1 };
int testcase = 0, T;
int n, m;

void dp(int i,int j) {
	for (int z = 0; z < 3; z++) {
		
		if (i + di[z]<0|| i + di[z]>=n) continue;
		arr[i][j] = max(arr[i][j], map[i][j] + arr[i+di[z]][j - 1]);
	}
	
	return;
}




int main()
{
	//금광
	
	cin >> T;
	
	while (testcase < T) {
		cin >> n >> m;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin>>map[i][j];
			}
		}

		
		for (int i = 0; i < n; i++) {
			arr[i][0] = map[i][0];
		}//첫째열은 그냥 넣기
		//둘째열부터 해당위치에 최대값 넣기
		for (int j = 1; j < m; j++) {
			for (int i = 0; i < n; i++) {
				dp(i,j);
			}
		}
		int gold = 0;
		for (int i = 0; i < n; i++) {
			gold=max(arr[i][m - 1],gold);
		}
		cout << gold << endl;
		//채굴자가 채굴한 금의 최대크기
		testcase++;

		//초기화
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <m ; j++) {
				map[i][j]=0;
				arr[i][j]=0;
			}
		}
		


	}
	return 0;
}
