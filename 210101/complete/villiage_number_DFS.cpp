#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool map[25][25];
bool visited[25][25];
int n;
vector<int> vil;
int home;

void dfs(int x, int y)
{
	if ((x >= 0 && y >= 0 && x < n&&y < n) && map[x][y] && !visited[x][y])
		//map�����̰� ���� �ְ� �湮�� ���� ������
	{
		visited[x][y] = true;
		home++;
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			dfs(nx, ny);
		}
	}
	return;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			//cin >> map[i][j];
			scanf("%1d", &map[i][j]);//*******�ѱ��ھ� ���� ���� scanf
		}
	}
	//map�Է� �Ϸ�
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (map[i][j]&&!visited[i][j])//�湮�� ���� ���� ���� ������
			{
				dfs(i,j);
				vil.push_back(home);
				home = 0;
			}
		}
	}
	//�� ������ ���(vector�� size�� �������)
	cout << vil.size() << endl;
	//�� ������ ���� ���� ������������ ���
	sort(vil.begin(), vil.end());
	for (int i = 0; i < vil.size(); ++i)
	{
		cout << vil[i] << endl;
	}
	return 0;
}