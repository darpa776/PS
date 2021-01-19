#include <iostream>
using namespace std;

int v, e;
int parent[100001];

int findroot(int x)
{
	if (x == parent[x]) return x;
	else 
		return parent[x] = findroot(parent[x]);
	
}

int doUnion(int x, int y)
{//x와 y가 같은 집합이다
//부모노드가 같도록 변경해준다
	x = findroot(x);
	y = findroot(y);
	if (x < y) parent[y] = x;
	//더 작은 번호를 부모로 정한다
	else parent[x] = y;

	return 0;
}//루트노트까지 출력해야하고, 루트노트를 찾아 부모노드에 갱신해야한다

int main()
{
	//입력: vertex 개수(v), edge개수(e)
	//edge 정보
	cin >> v >> e;

	//부모 노드 초기화
	for (int i = 1; i <= v; i++)
	{
		parent[i]=i;
		//노드의 부모는 자기자신
	}
	
	//간선 정보 얻기
	//간선 정보가 들어오는대로 union
	for (int i = 0; i < e; i++)
	{
		int x, y;
		cin >> x >> y;
		doUnion(x, y);//x와 y를 합친다
	}

	//출력: 각 원소가 속한 집합
	//부모 테이블

	for (int i = 1; i <=v ; i++)
	{
		//각 원소가 속한 집합
		cout << findroot(i) << " ";

	}
	cout << endl;
	for (int i = 1; i <= v; i++)
	{
		cout<<parent[i]<<" ";
	}
	return 0;
}