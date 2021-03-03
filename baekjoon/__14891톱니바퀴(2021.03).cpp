#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
using namespace std;
deque<int> chain[4];
//deque는
//맨 뒤를 삭제해 맨 앞에 넣을 수 있음
//맨 앞을 삭제해 맨 뒤에 넣을 수 있음

string chain_s[4];//톱니바퀴의 정보를 저장
vector<pair<int, int>> rotation;//돌릴바퀴 번호와 방향
int k;

int dfs(int num, int dir, char padodir)//톱니번호, 톱니회전방향, 파도타기방향
{
	if (padodir == 'L')//왼쪽으로 파도타는 방향이면
	{//더 왼쪽에 톱니가 있는지 확인
		if (num == 0)//자기가 왼쪽의 마지막 톱니이면
		{
			return 0;//dfs 종료
		}
		//a톱니의 왼쪽 톱니를 확인
		//만약 이가 서로 다르다면 반대방향으로 회전
		if (chain[num][6] != chain[num - 1][2]) {
			rotation.push_back({ num - 1,-dir });
			dfs(num - 1, -dir, 'L');//왼쪽 톱니를 지금방향과 반대로 돌리고 왼쪽으로 파도타라
		}
		
	}
	else if (padodir == 'R')//오른쪽으로 파도타는 방향이면
	{//더 오른쪽에 톱니가 있는지 확인
		if (num == 3)//자기가 오른쪽의 마지막 톱니이면
		{
			return 0;//dfs 종료
		}
		//a톱니의 오른쪽 톱니를 확인
		if (chain[num][2] != chain[num + 1][6]) {
			rotation.push_back({ num + 1, -dir });
			dfs(num + 1, -dir, 'R');
		}
	}
	return 0;
}


int main()
{

	for (int i = 0; i < 4; i++) {
		getline(cin, chain_s[i]);
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			char tmp = chain_s[i][j];
			chain[i].push_back(tmp - '0');

		}
	}//문자열로 입력된 톱니 극을 deque에 저장

	//명령의 개수
	cin >> k;
	//int top = 8;
	for (int i = 0; i < k; i++) {

		//a번째 톱니바퀴를 b방향으로 회전
		int la; int b;
		cin >> la >> b;
		int a = la - 1;//실제 톱니바퀴 번호
		rotation.push_back({ a,b });
		//a톱니의 좌우만 확인한다.
		dfs(a, b, 'L');//톱니번호, 방향, 파도타기 방향
		dfs(a, b, 'R');

		//한꺼번에 돌리기
		for (int j = 0; j < rotation.size(); j++) {
			int rtnum = rotation[j].first;//돌릴바퀴번호
			int rtdir = rotation[j].second;//돌릴방향
			if (rtdir == -1)//시계반대방향이면
			{//top이 0에서 1이 된다.
			 //맨 앞을 삭제해 맨 뒤에 넣는다
				int tmp = chain[rtnum].front();
				chain[rtnum].pop_front();
				chain[rtnum].push_back(tmp);
			}
			else if (rtdir == 1)//시계방향으로 돌리면
			{//top이 0에서 7이 된다.
			//맨 뒤를 삭제해 맨 앞에 넣는다
				int tmp = chain[rtnum].back();
				chain[rtnum].pop_back();
				chain[rtnum].push_front(tmp);
			}
			
		}
		rotation.clear();
	}


	//다 돌고 난 다음 top이 S면 1,2,4,8 점수부여
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		if (chain[i][0] == 1)
			ans += pow(2, i);

	}
	cout << ans << endl;
	return 0;
}
