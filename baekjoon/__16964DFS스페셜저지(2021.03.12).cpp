#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> graph[100001];
int n;
int visited[100001];
vector<int> route;
int ans = 1;
int index = 0;
void cmp() {
	int parent = route[index];
	visited[parent] = 1;
	//만약 parent가 visited한 자식 외에 자식이 있으면
	//그 child를 방문하고
	//자식이 없으면 종료하고 parent의 다음 child로 이동한다.
	int sub = 0;
	for (int i = 0; i < graph[parent].size(); i++) {
		if (visited[graph[parent][i]])
			sub++;
	}
	if (graph[parent].size() - sub == 0) return;
	int child_num = graph[parent].size() - sub;
	for (int i = 0; i < child_num; i++) {
		if (graph[parent].end() != find(graph[parent].begin(), graph[parent].end(), route[index+1]))
		{//만약 graph[parent]에 child가 있으면 
		//그 친구로 이동
			index++;
			cmp();
		}
		else//없으면 잘못된 루트
		{
			ans = 0;
			return;
		}
	}
}

int main() {

	cin >> n;//정점의 수
	for (int i = 0; i < n - 1; i++) {//간선정보
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

	cmp();
	//parent
	//parent_idx
	cout << ans << endl;
	return 0;
}
