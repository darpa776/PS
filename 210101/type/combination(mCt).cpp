#include <iostream>

using namespace std;
int m;
bool visited[20];

void dfs(int idx, int cnt, int t)//m�� �� �����غ���
{
	if (cnt == t)
	{
		//print();
		//visited==true�ΰ� ����ϱ�
		for (int k = 0; k < 20; ++k)
			if (visited[k]) cout << k + 1;
		cout << endl;
		return;
	}
	for (int i = idx; i < m; ++i)
	{
		if (visited[i] == true) continue;
		visited[i] = true;
		dfs(i, cnt + 1, t);
		visited[i] = false;
	}

	return;
}

int main()
{
	cout << "m" << endl;
	cin >> m;
	for (int i = 1; i <= m; ++i)
		dfs(0, 0, i);






}