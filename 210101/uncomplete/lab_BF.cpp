#include <iostream>
#include <vector>

using namespace std;
int N, M;
int arr[][8];
//�����¿�
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int main()
{
	cin >> N >> M;
	int arr[][8] = { 0, };
	for (int i = 0; i < N; ++i)//����index
		for (int j = 0; j < M; ++j)//���� index
			cin >> arr[i][j];
	lab();
	//0���� ����
}

void lab()
{//�����ҹ� ����ó�����ֱ�
	for (int i = 0; i < N; ++i)//����index
	{
		for (int j = 0; j < M; ++j)//���� index
		{
			if (arr[i][j] == 2)
			{
				for (int direction = 0; direction < 4; ++direction)
				{
					if (arr[i + dx[direction]])
						int val = arr[i + dx[direction]][i + dy[direction]];
					
				}
			}
		}
}
	