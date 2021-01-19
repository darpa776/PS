#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int v, e;
int parent[101];
vector<pair<int, pair<int, int>>> edge;
int ans=0;

int findroot(int x)
{
	if (x == parent[x]) return x;
	else return parent[x] = findroot(parent[x]);
}

int doUnion(int x,int y)
{
	x=findroot(x);
	y = findroot(y);

	if (x < y) parent[y] = x;
	else parent[x] = y;
	
	return 0;
}

int main()
{
	cin >> v >> e;

	//parent 배열 초기화
	for (int i = 1; i <= v; i++)
	{
		parent[i] = i;
	}

	//간선 입력받기
	for (int i = 0; i < e; i++)
	{
		int x, y, cost;
		cin >> x >> y>>cost;
		edge.push_back({ cost, {x,y} });
	}

	sort(edge.begin(), edge.end());//오름차순 정렬

	for (int i = 0; i < edge.size(); i++)
	{
		int x, y;
		x=edge[i].second.first;
		y = edge[i].second.second;
		if (findroot(x) != findroot(y))
		{
			doUnion(x, y);
			ans += edge[i].first;
		}
	}
	cout << ans;
	return 0;
}