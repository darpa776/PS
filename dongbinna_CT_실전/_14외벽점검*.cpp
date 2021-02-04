#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//왜 permutation을 써야하는가?

int solution(int n, vector<int> weak, vector<int> dist) {
	int answer=dist.size()+1;

	int m = weak.size();
	
	for (int i = 0; i <m; i++) {
		weak.push_back(weak[i]+n);
	}
	for (int i = 0; i < m; i++) {//weak의 점검 시작 위치
		do {
			int cnt = 1;
			//해당친구가 점검할 수 있는 마지막 위치
			int position = weak[i] + dist[cnt - 1];
			for (int l = i; l < i + m; l++) {//취약위치에 도착했는지 검사
				if (position < weak[l])//마지막 도착위치가 취약위치를 다 지나가지 못하면
				{
					cnt++;//다른 친구들을 더 부르는데,
					if (cnt > dist.size()) { // 더 부를 수 없으면 종료
						break;
					}
					position = weak[l] + dist[cnt - 1];
					//부를 친구의 도착위치를 새로 설정해준다.
					//전에 있던 친구가 l번째 취약지점위치에 도달하지 못했기 때문에 l번째 취약지점위치부터 시작하도록 설정해주는 것임

				}
			}
			answer = min(answer, cnt);
		} while (next_permutation(dist.begin(), dist.end()));
	}
		if (answer > dist.size()) {
			return -1;
		}//친구들이 다 돌아도 cover가 안되면 
		//이 경우가 있는가??

	return answer;
}
