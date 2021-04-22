#include <iostream>
#include <deque>
#include <vector>
using namespace std;
deque<pair<int, pair<int, int>>> dq;//가장 먼저 올라온 로봇인가, 로봇이 올라가 있는가(1이면 로봇 o), 내구도
vector<pair<int, pair<int, int>>> conv;//임시 컨베이어
int n, k;

//가장 먼저 올라온 로봇인지 여부, 로봇이 올라가 있는지, 내구도
int robot_move(int idx) {
	for (int j = 0; idx - j >= 0; j++) {
		if (j == 0) {
			if (conv[idx - j + 1].second.second){
			conv[idx - j + 1].first = 1;
			conv[idx - j].first = 0;
			}
		}
		if (conv[(idx - j)].second.first) {// 로봇이 올라와 있다면
			//그다음 벨트의 내구도를 판단한다.
			if (conv[idx - j + 1].second.first) continue;
			if (conv[idx - j + 1].second.second) {//내구도가 아직 있으면
				conv[idx - j + 1].second.second--;//내구도 체크
				conv[idx - j + 1].second.first = 1;//로봇 옮겨줌
				conv[idx - j].second.first = 0;
			}
			
		}

	}
	return 0;
}

int main() {
	//벨트를 어떻게 회전시킬 것인가
	//로봇이 올라와있는지 어떻게 확인할 것인가
	cin >> n >> k;//칸의 개수와 내구도가 0인칸 개수
	for (int i = 0; i < 2 * n; i++) {
		int strong;
		cin >> strong;
		dq.push_back({ 0,{ 0, strong} });
	}
	int turn = 1;
	while (1) {
		//1. 벨트 회전
		pair<int, pair<int, int>> tmp;
		tmp = dq.back();
		dq.pop_back();
		dq.push_front(tmp);

		//2. 로봇 이동
		
		while (!dq.empty()) {
			pair<int, pair<int, int>> tmp;//가장 먼저 올라온 로봇인지 여부, 로봇이 올라가 있는지, 내구도
			tmp = dq.front();
			dq.pop_front();
			conv.push_back(tmp);
		}
		//인덱스 접근 불가능한 dq형에서 값 변경이 가능한 vector형으로 변환 완료

		for (int i = 0; i < conv.size(); i++) {
			if (conv[i].first == 0) continue;
			//가장 먼저 벨트에 올라간 로봇이라면
			//로봇이 이동한다.
			//가장 먼저 벨트에 올라간 로봇부터 벨트가 회전하는 방향으로 한칸 이동할 수 있다면 이동한다.

			//idx의 로봇이 가장 먼저 벨트에 올라온 로봇이다.
			if (i == n - 1) {//n위치에 온 로봇은 내려준다.
				//idx가 현재 내려야할 위치에 있다면 내리고 
				conv[i].first = 0;
				conv[i].second.first = 0;
				//내구도는 유지됨

				//그담 로봇에게 가장 먼저 올라온 로봇 상을 수여한다.
				for (int j = 1; i - j >= 0; j++) {
					if (conv[(i - j)].second.first) {//다음 칸에 로봇이 올라와 있다면
						conv[(i - j)].first = 1;
						i = i - j;
						break;
					}
				}
			}

			robot_move(i);//로봇을 움직이자
			break;
		}
		for (int i = 0; i < conv.size(); i++) {
			if (conv[i].first == 0) continue;
			if (i == n - 1) {//n위치에 온 로봇은 내려준다.
			//idx가 현재 내려야할 위치에 있다면 내리고 
				conv[i].first = 0;
				conv[i].second.first = 0;
				//내구도는 유지됨

				//그담 로봇에게 가장 먼저 올라온 로봇 상을 수여한다.
				for (int j = 1; i - j >= 0; j++) {
					if (conv[(i - j)].second.first) {//다음 칸에 로봇이 올라와 있다면
						conv[(i - j)].first = 1;
						break;
					}
				}
			}
			

		}

		//3. 로봇 올리기
		if(conv[0].second.second){
		int flag = 0;
		for (int i = 0; i < n; i++) {
			if (conv[i].second.first)
				flag = 1;
		}
		if (flag == 0) {
			conv[0].first = 1;
		}
		//만약 처음올리는 로봇이 아니라면 그냥 로봇 올리기
		conv[0].second.first = 1;//로봇있음
		conv[0].second.second--;//내구성 감소시켜주기
		}

		//4. 내구도 0인칸이 k개 이상인지 확인하고, k개 이상이면 종료
		int cnt = 0;
		for (int i = 0; i < conv.size(); i++) {
			if (conv[i].second.second <= 0)
				cnt++;
		}
		if (cnt >= k) {
			cout << turn << endl;//몇번째 turn이 수행되고 있었는지 출력
			return 0;
		}
		//vector의 값들을 다 dq에 넣어주기
		for (int i = 0; i < conv.size(); i++) {
			dq.push_back(conv[i]);
		}
		conv.clear();
		turn++;
	}

	return 0;
}
