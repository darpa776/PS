#include <iostream>
using namespace std;
int map[9][9];
int row;
int col;//find_zero�Լ����� ã�� ��ġ�� dfs �Լ��� �Ѱ��ֱ� ���� ����
//https://github.com/hotehrud/acmicpc/blob/master/algorithm/graph/2239.java
//�ҽ��� �Լ��� �̿��ؼ� �ִ��� �߰� �ɰ���
int flag;//������ ����� �ѹ��� ��µǰ� �Ѵ�
bool row_search(int m, int num)
{//������=�� �ε��� ����
	for (int x = 0; x < 9; x++)
	{
		if (map[m][x] == num)
		{
			return false;//�����ٿ� �̹� �����ϴ� �����Դϴ�
		}
			
	}
	return true;//�����ٿ��� ���� �����Դϴ�
}
bool col_search(int n, int num)
{
	for (int y = 0; y < 9; y++)
	{
		if (map[y][n] == num)
		{
			return false;//�����ٿ� �̹� �����ϴ� �����Դϴ�
		}

	}
	return true;//�����ٿ��� ���� �����Դϴ�
}

bool box_search(int m, int n, int num)
{
	for (int i = 0; i < 3; ++i)//0,1,2
	{
		for (int j = 0; j < 3; ++j)
		{
		
			if (map[(m / 3)*3 + i][(n / 3)*3 + j] == num)
			{
				return false;
			}
		}
	}

	return true;
}

bool find_zero()
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (map[i][j] == 0)
			{
				row = i;
				col = j;
				return true;
			}
		}
	}
	
	return false;//���̻� 0�� �����ϴ�
}


void dfs(int m, int n)
{
	
	
	for (int num = 1; num < 10; ++num)
	{
		//������,������, �ڽ��� ���� ���ڶ��
		if (row_search(m, num) && col_search(n, num) && box_search(m, n, num))
		{//ä��� ����
			map[m][n] = num;
			//0�� ���� ��ġ ã��
			if (find_zero())
			{//ã������ ���
				dfs(row, col);
			}
			else//��� �� ä������ ����� �� ����
			{//������ return�� �� ����dfs�Լ��� ���ư� �� ��µȴ�.
				if (flag==0)//�ѹ��� ����� ��찡 ���� ��
				{
					for (int i = 0; i < 9; ++i)
					{
						for (int j = 0; j < 9; ++j)
						{
							cout << map[i][j] << " ";
						}
						cout << endl;
					}
					flag++;
					return;
				}
		
				else//�ѹ� ����ϰ� ����
				{
					return;
				}

			}
			map[m][n] = 0;//backtracking ���� ����ġ

		}
		
	}
	
	return;
}

int main()
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cin >> map[i][j];
		}
	}//�Է� �� �ް� �� ����

	find_zero();//*****ó���� ������ 0�� ���� �����ϰ� ������ Ǯ���٤ФФФ�
	dfs(row, col);//***
	//�������� �ҽ��� �����ϰ� �Ǹ� find_zero�Լ��� dfs �Ǿ����� �־��

	return 0;
}
	//0ã�Ƽ� ���� 1.2.3�� �� �ش�Ǵ��� �˻��ϱ�
	//���� �� ������ ���� ���� �־��


