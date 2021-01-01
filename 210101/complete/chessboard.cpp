#include <iostream>
#include<string>
#include<string.h>
using namespace std;
int m, n;//자르기전 판 크기
char orgin_map[50][51];
//*****2차원 배열 board의 크기는 null문자까지 입력받아야 하므로 [50][51]이 되어야 합니다.
string orgin_WB;
int W_map[50][50];
int B_map[50][50];

int main()
{


	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{

		cin >> orgin_WB;
		strcpy(orgin_map[i], orgin_WB.c_str());

	}
	//입력완료
	//짝수행,홀수열 또는 홀수행 짝수열일때 해당 map이 B인경우 Wmap
	//홀수행,홀수열 또는 짝수행 짝수열일때 해당 map이 B인경우 Bmap
for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			//Wmap,Bmap 조건 검사
			if (i % 2 ^ j % 2)
			{
				if (orgin_map[i][j] == 'B')
					B_map[i][j] = 1;
				else if (orgin_map[i][j] == 'W')
					W_map[i][j] = 1;
			}
			else
			{
				if (orgin_map[i][j] == 'B')
					W_map[i][j] = 1;
				else if (orgin_map[i][j] == 'W')
					B_map[i][j] = 1;
			}
		}
	}

	
	
	int Wcnt=0, Bcnt = 0;
	int min = 5000;//최대 50*50보다 크게 잡았음
	//자른 범위바꿔가며 탐색
	for (int x = 0; x <= n-8 ; ++x)
	{
		for (int y = 0; y <= m-8 ; ++y)
		{//자른 범위안에서 if문
			for (int i = x; i < x + 8; ++i)
			{
				for (int j = y; j < y + 8; ++j)
				{
					if (W_map[i][j])
						Wcnt++;
					if (B_map[i][j])
						Bcnt++;
				}
			}

			if (Wcnt < min)
				min = Wcnt;
			if (Bcnt < min)
				min = Bcnt;
			Wcnt=0, Bcnt = 0;

		}
	}
	cout << min;
	return 0;
}