#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int v, e;//마을 수, 길 수
vector<pair<int,pair<int,int>>> edge;
int parent[101];
int result = 0;
int big;

int findparent(int x)
{
	if (parent[x] == x) return x;
	else return parent[x] = findparent(parent[x]);
}


void doUnion(int x, int y)
{
	x=findparent(x);
	y = findparent(y);
	if (x < y) parent[y] = x;
	else parent[x] = y;
	return;
}


void kruskal()
{//최소신장그래프를 찾은 다음에 최소신장트리를 구성하는 간선 중에서 가장 비용이 큰 간선을 제거하자**

	for (int i = 0; i < edge.size(); i++)
	{
		if (findparent(edge[i].second.first) != findparent(edge[i].second.second))
			//같은 부모를 가지면 사이클을 가지므로 무시하고, 다른 부모를 가지면 union을 수행한다
		{
			doUnion(edge[i].second.first, edge[i].second.second);
			result += edge[i].first;
			big = edge[i].first;//***
		}
	}
	return;
}

int main()
{
	cin >> v >> e;
	for (int i = 0; i < e; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		edge.push_back({ z,{x,y} });
	}
	for(int i=1;i<=v;i++)
	parent[i] = i;

	//간선 정렬(오름차순)
	sort(edge.begin(), edge.end());

	kruskal();

	return 0;
}