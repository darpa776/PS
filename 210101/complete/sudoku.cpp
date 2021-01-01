#include <iostream>
using namespace std;
int map[9][9];
int row;
int col;//find_zero함수에서 찾은 위치를 dfs 함수에 넘겨주기 위한 변수
//https://github.com/hotehrud/acmicpc/blob/master/algorithm/graph/2239.java
//소스를 함수를 이용해서 최대한 잘게 쪼개기
int flag;//스도쿠 결과가 한번만 출력되게 한다
bool row_search(int m, int num)
{//가로줄=뒷 인덱스 증가
	for (int x = 0; x < 9; x++)
	{
		if (map[m][x] == num)
		{
			return false;//가로줄에 이미 존재하는 숫자입니다
		}
			
	}
	return true;//가로줄에는 없는 숫자입니다
}
bool col_search(int n, int num)
{
	for (int y = 0; y < 9; y++)
	{
		if (map[y][n] == num)
		{
			return false;//세로줄에 이미 존재하는 숫자입니다
		}

	}
	return true;//세로줄에는 없는 숫자입니다
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
	
	return false;//더이상 0이 없습니다
}


void dfs(int m, int n)
{
	
	
	for (int num = 1; num < 10; ++num)
	{
		//가로줄,세로줄, 박스에 없는 숫자라면
		if (row_search(m, num) && col_search(n, num) && box_search(m, n, num))
		{//채우기 시작
			map[m][n] = num;
			//0인 다음 위치 찾기
			if (find_zero())
			{//찾았으면 재귀
				dfs(row, col);
			}
			else//모두 다 채웠으면 출력한 후 종료
			{//문제는 return한 후 이전dfs함수로 돌아갈 때 출력된다.
				if (flag==0)//한번도 출력한 경우가 없을 때
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
		
				else//한번 출력하고 나서
				{
					return;
				}

			}
			map[m][n] = 0;//backtracking 위한 원위치

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
	}//입력 다 받고 난 다음

	find_zero();//*****처음이 무조건 0일 경우로 생각하고 문제를 풀었다ㅠㅠㅠㅠ
	dfs(row, col);//***
	//다음번에 소스를 수정하게 되면 find_zero함수를 dfs 맨앞으로 넣어보쟈

	return 0;
}
	//0찾아서 조건 1.2.3에 다 해당되는지 검사하기
	//조건 안 맞으면 다음 숫자 넣어보기


