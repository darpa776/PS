#include <iostream>
#include <vector>
#include <algorithm>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
using namespace std;

int n, m, c;
int map [10][10];
int testcase,t=0 ;

int honey(int x, int y) {
	int num=0;
	int sum=0;
	for (int i = 0; i < m; i++) {
		num += map[x][y + i];
		sum += pow(map[x][y + i], 2);
	}
	if (num <= c) return sum;


	sum = 0;
	for (int i = 1; i <= m; i++) {
		vector<int> binary(m);
		fill(binary.end() - i, binary.end(),1);
		do {
			int tmp = 0, num = 0;
			for (int i = 0; i < m; i++) {
				if (binary[i]) {
					num += map[x][y + i];
					tmp += pow(map[x][y + i], 2);
				}
			}
			if (num <= c) sum = max(sum, tmp);
		} while (next_permutation(binary.begin(), binary.end()));
		
	}
	return sum;
}

int main() {
	freopen("sample_input.txt", "r", stdin);
	
	cin >> testcase;
	while(t<testcase){
	cin >> n>>m>>c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	//벌꿀채취
	int arr[10][10];
	//-1로 fill?
	for (int i = 0; i < n; i++){
		for (int j = 0; j <= n - m; j++) {
			arr[i][j] = honey(i, j);
		}
	}
	//각 위치에서 m개의 벌통을 채취했을 때의 최대값을 arr에 저장
	//선택한 위치가 서로 겹치지 않게 고른다.
	vector<int> choice(n*(n-m+1));
	//vector<vector<int>> choice(m-n,vector<int>(n));
	fill(choice.end() - 2, choice.end(), 1);//채굴위치를 두개 선정한다.
	int ans = 0;
	do {
		
		vector<pair<int, int>> coordinate;

		for(int i=0;i<n*(n-m+1);i++){
			if(choice[i]){
				coordinate.push_back({ i / (n - m+1),i % (n - m+1) });
				
			}
		}
		int cal = 0;
		if (coordinate[0].first != coordinate[1].first) {
			cal += arr[coordinate[0].first][coordinate[0].second];
			cal += arr[coordinate[1].first][coordinate[1].second];
		}
		else {
			//같은 행이 m칸 거리내에 있는가?
			if (abs(coordinate[0].second - coordinate[1].second) > m) {
				//m칸 보다 더 멀리 떨어져있으면
				cal += arr[coordinate[0].first][coordinate[0].second];
				cal += arr[coordinate[1].first][coordinate[1].second];
			}
			else {
			//같은 행에서 m칸 거리내에 있으면
				continue;
			}
		}
		ans = max(ans, cal);
	} while (next_permutation(choice.begin(), choice.end()));
	


	cout<<"#"<<t+1<<" " << ans << endl;
	//초기화
	for (int i = 0; i < n; i++) {
		fill_n(map[i], n, 0);
		fill_n(arr[i], n, 0);
	}
	


	t++;
	}
	return 0;
}
