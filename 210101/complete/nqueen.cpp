#include <iostream>
#include <math.h>
int n;
int ans;
int check[16];//n이 최대 15
using namespace std;
int flag=1;
int dfs(int row,  int cnt)//행,열,몇번째 queen을 두었다
{
	if (cnt == n)
	{
		ans++;
		return 0;
	}

	for (int i = row; i <= n; ++i)//i가 현재 행
	{
		for (int j = 1; j <= n; ++j)//j는 열
		{
			
			if (i == 1)//첫행을 정하는 것은 무조건 허락
			{
				check[i] = j;

				dfs(i + 1, cnt + 1);//j는 어차피 처음부터 세니까 필요없을수도 있음
				check[i] = 0;//**찾느라 한참걸렸다ㅜㅜ**
				continue;//**찾느라 한참걸렸다ㅜㅜ**
				//가로 겹치지 않게 다음 행으로 넘기기
			}
			flag = 1;
			for (int k = 1; k < i; ++k)
			{
				if (j == check[k] || abs(j - check[k]) == abs(k - i))//수직, 대각선이면 넘어가기
				{
					flag = 0;
					break;
				}
			}
			if(flag)
			{
				check[i] = j;
				dfs(i + 1, cnt + 1);//j는 어차피 처음부터 세니까 필요없을수도 있음
					//가로 겹치지 않게 다음 행으로 넘기기
				check[i] = 0;
			}
			
		}
		return 0; //**찾느라 한참걸렸다ㅜㅜ**
	}
	return 0;
}

int main()
{
	cin >> n;
	dfs(1,  0);//queen을 놓지 않았다고 간주하기 때문에 check배열 값으로 0을 쓰지 않도록 한다.
	cout << ans;
	return 0;
}