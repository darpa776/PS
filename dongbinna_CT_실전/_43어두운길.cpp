#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int,pair<int,int>>> map;
//비용, 도로의 위치(x,y)
int parent[200000];
int cost = 0;

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
	int n,m;
	cin >> n>>m;
	
	//최소 spanning tree
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}

	
	for (int i = 0; i < m; i++) {
		//도로 위치와 길이 입력받기
		int x, y, z;
		cin >> x >> y >> z;
		map.push_back({ z,{ x,y } });
		
	}
	//사이클이 일어나지 않으면 union하기
	//비용이 최소이면 union하기
	//***간선의 비용을 정렬하고 사이클이 아닐때만 union연산을 수행한다.

	sort(map.begin(), map.end());
	int total = 0;
	for (int i = 0; i < m; i++) {//도로의 개수만큼
	
		int x = map[i].second.first;
		int y = map[i].second.second;
		int z = map[i].first;;
		total += z;
		if (findparent(x) != findparent(y)) {
			doUnion(x, y);
			cost += map[i].first;
		}
	}
	cout << total-cost << endl;
	//문제가 '절약할 수 있는 최대금액'이므로 
	//전체 union했을 경우 드는 비용(절약안했을 때 드는 비용) - 있어야하는 도로의 비용(union한 도로비용)= 절약할 수 있는 비용
	return 0;
}
