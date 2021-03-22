#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define _crt_secure_no_warnings
#pragma warning(disable:4996)
using namespace std;

int testcase, t = 0;
int n;
int map[50][50];
int visited[50];
int num = 0;//사람수
vector<pair<int, int>> person_pos;//사람 위치
vector<pair<int, int>> stair_pos;
int ans = 1e9;
int arrive = 0;//도착한 사람 수
int stair1 = 0;//1번 계단에 있는 사람 수
int stair2 = 0;//2번 계딴에 있는 사람 수


void simulation(vector<int> binary, vector<int> person) {//cnt 반복문으로 돌리기
	int cnt = 0;
	while (1) {
		for (int i = 0; i < num; i++) {
			if (person[i] == -1) {//도착
			//도착했으면 arrive++, person[i]=1e9
				if (visited[i])
					continue;
				arrive++;
				visited[i] = 1;
				//도착한 애는 건드리지 말기

				if (binary[i] == 0) {
					stair1--;
				}
				else if (binary[i] == 1) {
					stair2--;
				}
			}
			//도착한 사람들 먼저 계단에서 빼줘야 기다리던 사람들이 들어갈 수 있다.
			//이렇게 미리 안해주면 도착한 사람의 바로 다음 idx사람이 들어가게 된다.
		}

		for (int i = 0; i < num; i++) {
			if (person[i] > 0 && person[i] != -1)
				person[i]--;//만약 stair에 아직 도달하지 못했다면 stair 와의 거리 좁히기
			else if (person[i] == 0) {
				//만약 stair 앞에 도착했다면 해당 stair에 몇명이 있는지 확인
				if (binary[i] == 0) {//1번 계단에 몇명이 있는지 확인
					if (stair1 == 3) {
						//wait
					}
					else {
						int x = stair_pos[0].first;
						int y = stair_pos[0].second;
						person[i] = -map[x][y];
						stair1++;
					}
				}
				else if (binary[i] == 1) {
					if (stair2 == 3) {

					}
					else {
						int x= stair_pos[1].first;
						int y = stair_pos[1].second;
						person[i] = -map[x][y];
						stair2++;
					}
				}
			}
			else if (person[i] < -1)
				person[i]++;
			

		}//모두 다같이 이동
		cnt++;//다 이동 했으면 cnt++
		if (arrive == num) {//모두 도착함
			ans = min(cnt, ans);
			return;
		}

	}
	return;
}



int main() {
	freopen("sample_input.txt", "r", stdin);

	cin >> testcase;
	while (t < testcase) {

		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j] == 1)//사람이면
				{
					num++;//사람수세기
					person_pos.push_back({ i,j });
				}
				else if (map[i][j] >= 2)//계단이면
					stair_pos.push_back({ i,j });//계단의 위치를 저장
			}
		}
		
		vector<int> binary(num, 0);
		
		//모든 사람이 0번째 계단을 사용한다~모두 1번째 계단을 사용한다.
		//사람크기의 binary 벡터 선언
		for (int i = 0; i <= num; i++) {
			fill(binary.end() - i, binary.end(), 1);
			do {
				//사람 마다 계단과의 거리 계산해주기
				vector<int> person(num, 0);
				for (int j = 0; j < num; j++)
				{
					if (binary[j] == 0)//1번 계단을 사용해야한다면
					{
						person[j] = abs(person_pos[j].first - stair_pos[0].first) + abs(person_pos[j].second - stair_pos[0].second);
						//1번 계단까지 가는 거리
					}

					else if (binary[j] == 1)//2번 계단을 사용해야한다면
					{
						person[j] = abs(person_pos[j].first - stair_pos[1].first) + abs(person_pos[j].second - stair_pos[1].second);
					}//2번 계단까지 가는 거리
				}
				
				simulation(binary,person);
				fill(visited, visited+50, 0);
				arrive = 0;
			} while (next_permutation(binary.begin(), binary.end()));
		}
		cout << "#" << t + 1 << " " << ans << endl;
		t++;

		//초기화
		num = 0;//사람수
		person_pos.clear();//사람 위치
		stair_pos.clear();
		ans = 1e9;
		arrive = 0;//도착한 사람 수
		stair1 = 0;//1번 계단에 있는 사람 수
		stair2 = 0;//2번 계단에 있는 사람 수
		fill(binary.begin(), binary.end(), 0);
	}
	return 0;
}
