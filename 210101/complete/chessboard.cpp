#include <iostream>
#include<string>
#include<string.h>
using namespace std;
int m, n;//�ڸ����� �� ũ��
char orgin_map[50][51];
//*****2���� �迭 board�� ũ��� null���ڱ��� �Է¹޾ƾ� �ϹǷ� [50][51]�� �Ǿ�� �մϴ�.
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
	//�Է¿Ϸ�
	//¦����,Ȧ���� �Ǵ� Ȧ���� ¦�����϶� �ش� map�� B�ΰ�� Wmap
	//Ȧ����,Ȧ���� �Ǵ� ¦���� ¦�����϶� �ش� map�� B�ΰ�� Bmap
for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			//Wmap,Bmap ���� �˻�
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
	int min = 5000;//�ִ� 50*50���� ũ�� �����
	//�ڸ� �����ٲ㰡�� Ž��
	for (int x = 0; x <= n-8 ; ++x)
	{
		for (int y = 0; y <= m-8 ; ++y)
		{//�ڸ� �����ȿ��� if��
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