#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

int parent[501];
int graph[501][501];//인접행렬
priority_queue<pair<int,  int>> pq;

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
		
		for (int i = 1; i <= n; i++) {
			parent[i] = i;//초기화
		}

		for (int i = 1; i <= n; i++) {
			for(int j=1;j<=n;j++){
				int x;
				cin >> x;
				if(x)	doUnion(i,j);
			}
		}
		
		vector<int> plan;
		for (int i = 0;i<m; i++) {//여행계획
			int x;
			cin >> x;
			plan.push_back(x);
		}
		////////////////////////
		
		//여행계획이 가능한지 서로소 판별을 해본다
		//같은 그룹내에있으면 여행이 가능하다
		for (int i = 0; i < plan.size()-1; i++) {
			
			if (findparent(plan[i])!=findparent(plan[i+1])) {
				cout << "NO" << endl;
				return 0;
			}
		}
		cout << "YES" << endl;
	return 0;
}
