#include <iostream>

using namespace std;
int m, n;
bool visited[20];

void dfs(int idx, int cnt)//m�� �� �����غ���
{
		if (cnt == n)
		{
			//print();
			//visited==true�ΰ� ����ϱ�
			for (int k = 0; k < 20; ++k)
				if (visited[k]) cout << k+1;
			cout << endl;
			return;
		}
		for (int i = idx; i < m; ++i)
		{
			if (visited[i] == true) continue;
			visited[i] = true;
			dfs(i, cnt + 1);
			visited[i] = false;
		}
	
	return;
}

int main()
{
	cout << "m n" << endl;
	cin >> m>>n;
	cout << endl;
	dfs(0, 0);






}