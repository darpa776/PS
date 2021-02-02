#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
//위상정렬
int graph[501][501];
int indegree[501];//각 팀들의 진입차수

int main()
{
	int testcase;
	cin >> testcase;
	int t = 0;
	while (testcase > t) {
		int n;
		cin >> n;
		//n개의 팀이 참가

		//작년 순위 저장
		vector<int> lasty;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			lasty.push_back(x);
		}

		//**바로 옆팀과의 순위만을 저장하는 것이 아니라 전체적으로 상대적이게 연결시켜준다.
		for (int i = 0; i < n-1; i++) {
			for (int j = i + 1; j<n; j++) {
				graph[lasty[i]][lasty[j]] = 1;
				indegree[lasty[j]] += 1;//다음 팀의 진입차수 증가시켜주기
			}
		}

		//올해 순위가 바뀐 그룹 입력받기
		int num;
		cin >> num;
		for (int i = 0; i < num; i++) {
			int x, y;
			cin >> x >> y;
			//x가 더 작은 수이므로 기존 연결은 y->x일 수도 있다.
			//graph[y][x] = graph[x][y];
			if (graph[x][y]) {//만약 x->y방향이면
				graph[y][x] = 1;
				indegree[x]++;
				graph[x][y] = 0;
				indegree[y]--;
			}
			else {//만약 y->x방향이면
				graph[x][y] = 1;
				indegree[y]++;
				graph[y][x] = 0;
				indegree[x]--;
			}
		}
		queue<int> q;
		vector<int> answer;
		//위상정렬 시작
		for (int i = 1; i <= n; i++) {
			//진입차수가 0인곳부터 시작
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		int cycle = 0;
		int ambiguous =0;
		//노드 수 만큼 돌아가기전에 q.size()가 0이면 사이클이 발생한 것
		for (int node_cnt = 0; node_cnt < n;node_cnt++) {
			if (q.size() > 1) {
				//진입차수가 0인 노드가 2개 이상이면 배열가능한 순위가 2개 이상이다.
				cout << "?" << endl;
				ambiguous =1;
				break;
			}
			else if (!q.size()) {//q.size가 0일 경우 사이클이 발생한 것=불가능한 순위
				cout << "IMPOSSIBLE" << endl;
				cycle = 1;
				break;
			}
			int now = q.front();
			answer.push_back(now);
			q.pop();
		
			for (int j = 1; j <= n; j++) {
				if (graph[now][j]) {//now의 순위 < j의 순위
					indegree[j]--;
					if (indegree[j] == 0) {
						q.push(j);
					}
				}
			}
		}
		if (cycle==0 && ambiguous==0){

			for (int i = 0; i < answer.size(); i++)
			{
				cout << answer[i] << " ";
			}
			cout << endl;
		}

		//초기화
		t++;

		//answer.clear();
		//lasty.clear();

		//전역으로 설정한 것들만 초기화 해주면 된다.
		for (int i = 0; i < 501; i++) {
			fill_n(graph[i], 501, 0);
		}
		fill_n(indegree,501,0);//각 팀들의 진입차수
	}

	return 0;
}
