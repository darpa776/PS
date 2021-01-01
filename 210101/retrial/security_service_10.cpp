#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
int n, m, ans;
bool map[21][21];
bool visited[21][21];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
//�����¿�
int home;
//int profit;
void simul(int x, int y)
{
	queue<pair<int, int>> q;
	int tmp = 0;
	int k = 1;

	q.push(make_pair(x, y));
	visited[x][y] = 1;
	if (map[x][y])//���� �ִٸ�
		++home;
	tmp = m * home - (pow(k, 2) + pow(k - 1, 2));//���Ͱ��
	if (tmp >= 0)//���� ����Ѱ� �� ũ��
		ans = max(home, ans);//�� ����
	int q_size = 1;
	while (!q.empty())
	{
		++k;// k++��������
		while (q_size--)
		{
			int now_x = q.front().first;
			int now_y = q.front().second;
			q.pop();
			//if (visited[now_x][now_y] >= n + 1) return;
			for (int i = 0; i < 4; ++i)
			{	//nx,ny ����
				int nx = now_x + dx[i];
				int ny = now_y + dy[i];
				//����ó��
				if (nx < 0 || ny < 0 || nx >= n || ny >= n)//nx,ny�� map�� �����
					continue;
				if (!visited[nx][ny])//�湮���� ���� ���̰�
				{
					if (map[nx][ny])//���� �ִٸ�
						++home;
					visited[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
			}
		}q_size = q.size();

		if (k <= n + 1)
		{
			tmp = m * home - (pow(k, 2) + pow(k - 1, 2));//���Ͱ��
			if (tmp >= 0)
				ans = max(home, ans);//�� ����
		}
		//or�������� �� ��� �����ȿ� �ִ��� �˾Ƴ���
		//mask Ű�� �� ���� ����ȸ���� ���Ͱ� �ִ밪�� ��/����
		else
			return;
		
			
	}
	return;

}
int main()
{
	freopen("sample_input.txt", "r", stdin);
	int test_case = 0;
	int T;
	cin >> T;

	//�Է����� n,m,map
	while (test_case < T)
	{
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				simul(i, j);
				//�ʱ�ȭ
				home = 0;
				
				for (int i = 0; i < n; ++i) 
					memset(visited[i], 0, sizeof(int)* n);
			}
		}
		cout << "#" << ++test_case << " " << ans << endl;

		//�ʱ�ȭ
		ans = 0;
		for (int i = 0; i < n; ++i) {

			memset(map[i], 0, sizeof(int)* n);
		}

	}
	return 0;
}
