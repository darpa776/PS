#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> graph[100000];
int n;
int visited[100000];
vector<int> route;
int ans=1;

void cmp(int parent_idx, int child_idx) {
	int parent = route[parent_idx];
	visited[parent] = 1;
	int sub = 0;
	for (int i = 0; i < graph[parent].size(); i++) {
		if (visited[graph[parent][i]])
			sub++;
	}
	if (graph[parent].size() - sub == 0) return;
	for (int j = 0; j < graph[parent].size() - sub; j++) {
		int child = route[child_idx + j];
		visited[child] = 1;
		if (graph[parent].end() == find(graph[parent].begin(), graph[parent].end(), child))
		{//만약 graph[parent]에 child가 없으면 잘못된 루트
			ans = 0;
		}

	}
	cmp(parent_idx + 1, child_idx + graph[parent].size()-sub);
	return;
}

int main() {

	cin >> n;//정점의 수
	for (int i = 0; i < n-1; i++) {//간선정보
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		route.push_back(tmp);
	}
	if (route[0] != 1) {//처음으로 방문할 정점이 1이 아니면 잘못된 루트이므로 종료
		cout << 0 << endl;
		return 0;
	}
	////이제 비교시작
	//int read_idx = 0;

	cmp(0, 1);//현재 정점은 1, 정점의 route에서의 idx는 0, 정점의 child의 route idx는 1(현재 정점의 size가 1이기 때문)

	//for (int i = 0; i < route.size(); i++) {
	//	if (i == 0) {
	//		
	//	}
	//}

	cout << ans << endl;
	return 0;
}
