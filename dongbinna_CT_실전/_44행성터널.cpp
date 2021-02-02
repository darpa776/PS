#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int parent[200000];
vector<pair<int, int>> x;
//좌표, 행성번호
vector<pair<int, int>> y;
vector<pair<int, int>> z;
vector<pair<int,pair<int,int>>> planet;
//행성의 비용,번호

int findparent(int x) {
	if (parent[x] == x) return x;
	else
		return parent[x]=findparent(parent[x]);
}

void doUnion(int x, int y) {
	x = findparent(x);
	y = findparent(y);
	if (x < y)
		parent[y] = x;
	else
		parent[x] = y;
	return;
}

int main() 
{
	int n;
	cin >> n;//행성의 개수

	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}
	
	for (int i = 1; i <= n; i++) {//행성들의 위치
		int a, b, c;
		cin >> a >> b >> c;
		x.push_back({ a,i });
		y.push_back({ b,i });
		z.push_back({ c,i });
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	sort(z.begin(), z.end());
	//정렬했으니 서로 값들이 차이가 적도록 근접한 것들끼리 비교한다.
	
	for (int i = 0; i < n-1; i++) {
		//행성의 번호가 작은 것부터 큰 쪽으로 연결된 도로라 가정한다.
		//하지만 이 가정이 필요없는 이유는 두 노드 모두에 대해 findparent 함수를 수행할 것이기 때문임
		planet.push_back({ x[i + 1].first - x[i].first, { x[i].second,x[i + 1].second } });
		planet.push_back({ y[i + 1].first - y[i].first, { y[i].second,y[i + 1].second } });
		planet.push_back({ z[i + 1].first - z[i].first, { z[i].second,z[i + 1].second } });
	}
//(1) 행성들 사이의 비용을 정한다.
	//x,y,z중에서도 최소의 값을 두행성 사이의 비용으로 정한다.
	//두 행성 사이의 값이 여러개가 존재하는 경우, 최소의 비용으로 먼저 union을 시행한다.
	//그래서 만약 동일한 행성들을 연결할 비용이 최소의 비용이 아니라면 union이 불가하게 된다.
	sort(planet.begin(), planet.end());

//(2) kruskal 알고리즘을 수행한다.
	int answer = 0;
	for (int i = 0; i < planet.size(); i++) {
		if (findparent(planet[i].second.first) != findparent(planet[i].second.second)) {
			doUnion(planet[i].second.first, planet[i].second.second);
			answer += planet[i].first;
		}
	}
	
	cout << answer << endl;
	return 0;
}
