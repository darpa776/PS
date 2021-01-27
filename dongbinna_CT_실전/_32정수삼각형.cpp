#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//dp는 내 위치에서 최대값이 되게 하는 것

int map[500][500];//맨 마지막 줄에 n개 숫자 들어감
int arr[500][500];
int main() {
	//정수 삼각형
	int n;//삼각형의 크기
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin>>map[i][j];
		}
	}
	arr[0][0] = map[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				arr[i][j] = map[i][j] + arr[i - 1][j];
				//오른쪽꺼 받기
				continue;
			}
			if (j == i) {
				arr[i][j] = map[i][j] + arr[i - 1][j-1];
				//왼쪽꺼 받기
				continue;
			}
			arr[i][j] = max(map[i][j] + arr[i - 1][j-1], map[i][j] + arr[i-1][j]);
			//왼쪽꺼 받기, 오른쪽꺼 받기
		}
	}
	int ans = 0;
	int i = n - 1;
	for (int j = 0; j < n; j++) {
		//맨 마지막 줄 중에 가장 큰 값 저장하기
		if (ans < arr[i][j]) {
			ans = arr[i][j];
		}
	}
	cout << ans << endl;
	return 0;
}
