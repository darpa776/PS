#include iostream
#include stack
#include vector
#include algorithm
#include queue

using namespace std;

int T, h, test_case, k, n;
int map[8][8];
vectorpairint, int max_pos;

int dx[4] = { -1, 1,0,0 }; �����¿�
int dy[4] = { 0,0,-1,1 };
int visited[8][8];
int ans;
int dfs(int x, int y, int len, int cut)
{
	ans = max(ans, len);
	visited[x][y] = true;

	a, b �̿��ؼ� ��� Ž��
		for (int i = 0; i 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			�� ���� ����ٸ�
				if (nx  0  ny  0  nx = n  ny = n) continue;
			cut�� ������� �ش���ǥ�� �ֺ��� ���츮���� ���� �湮�� ���� ������
				if (!visited[nx][ny])
				{
					if (map[x][y]  map[nx][ny])
					{
						visited[nx][ny] = true;
						dfs(nx, ny, len + 1, cut); ���� �ձ�, ���� ����
							visited[nx][ny] = false;
					}
					else if (!cut && (map[x][y]  map[nx][ny] - k))�ִ� k��ŭ ��Ҵµ��� ���츮���� ������ pass.
						����� �� ���츮���� ���� ���&& �ȱ��� ��
					{
						visited[nx][ny] = true;
					int t = map[nx][ny]; ������ ��ġ�� ���� ����
						map[nx][ny] = map[x][y] - 1; ���� ���̸� �ִ���� ���� ���� ����
						dfs(nx, ny, len + 1, 1); ���� �� 1, �ȱ��� �� 0
						map[nx][ny] = t; ���󺹱�
						visited[nx][ny] = false;
					}
				}

		}
	visited[x][y] = false;
	return len;
}
int main() {
	freopen(sample_input.txt, r, stdin);
	cin  T;
	while (test_case  T)
	{
		cin  n  k;
		int max_ = -1;
		for (int i = 0; i n; ++i)
		{
			for (int j = 0; j n; ++j)
			{
				cin map[i][j];
				if (max_  map[i][j])
					max_ = map[i][j]; ���츮���� �ִ��� ����
			}
		}

		���̰� �ִ��� �� �˾Ƴ���
			for (int i = 0; i n; ++i)
			{
				for (int j = 0; j n; ++j)
				{
					if (max_ == map[i][j])
						max_pos.push_back(make_pair(i, j)); ���̰� �ִ��� �� ��ġ ����
				}
			}
		int cnt = max_pos.size();
		max_pos���� ��ġ �ҷ�����
			for (int i = 0; i cnt; ++i)
			{
				���� ���� ���� ������� �ҷ�����
					int x = max_pos[i].first;
				int y = max_pos[i].second;
				dfs(x, y, 1, 0);
			}
		max_pos.clear(); ���� ����

			++test_case;
		cout# test_case  ansendl;
		ans = 0; �ʱ�ȭ

	}
	return 0;
}