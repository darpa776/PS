#include <iostream>
#include <vector>

using namespace std;
int N, M;
int arr[][8];
//상하좌우
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int main()
{
	cin >> N >> M;
	int arr[][8] = { 0, };
	for (int i = 0; i < N; ++i)//세로index
		for (int j = 0; j < M; ++j)//가로 index
			cin >> arr[i][j];
	lab();
	//0개수 세기
}

void lab()
{//연구소밖 예외처리해주기
	for (int i = 0; i < N; ++i)//세로index
	{
		for (int j = 0; j < M; ++j)//가로 index
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
	