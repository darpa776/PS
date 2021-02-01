#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int gate[100001];
int parent[100001];

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
	int g, p;
	cin >> g >> p;

	for (int i = 0; i <= g; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < p; i++) {
		//비행기가 도킹할수 있는 최대 탑승구 번호
		int x;
		cin >> x;
		//최대한 탑승구번호가 큰쪽으로 도킹한다
		if (findparent(x) == 0) {
			//도킹이 이미 다 되어 있으면 현재 도킹된 비행기 수를 출력하고 운행을 종료한다.
			cout << i << endl;
			return 0;
		}
		else
		{
			x = findparent(x);
			//루트에 도킹한다.
			doUnion(x, x - 1);
		}
			
	}
		
		
	return 0;
}
