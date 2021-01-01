#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;//멤버수
int chk[20];//멤버 편가르기 위한 배열
int map[20][20];//멤버가 최대 20명
vector<int> start;
vector<int> link;
int s_start;//스타트 팀의 시너지 합
int s_link;//링크 팀의 시너지 합
int ans=1000;//최소값 출력위한 변수

int cal();
int dfs(int idx, int num)
{
	if(idx==n/2)
	{
		
		//시너지 계산 함수
		cal();
		//->값 차이가 최소가 되는지 확인하는 함수

		////그 전에 내가 알고리즘 제대로 짯느지 시험해보기// 한 팀의 멤버들 출력하기
		//for (int i = 0; i < n; ++i)
		//{
		//	cout << chk[i];
		//	
		//}
		//cout<<endl;
		return 0;
	}
	for (int i = num; i < n; ++i)
	{
		if (!chk[i])
		{

		chk[i] = 1;//선택했음
		dfs(idx + 1,i);//num에 i 넣기****
		chk[i] = 0;//다음꺼 선택하라고 자리 내주기
		}
	}
	return 0;
}
//시너지 계산 함수
int cal() {
	for (int i = 0; i < n; ++i)
	{
		if (chk[i])
		{
			start.push_back(i);
		}
		else
		{
			link.push_back(i);
		}
	}
	for (int i = 0; i < start.size(); i++)
	{
		for (int j = i + 1; j < start.size(); j++)
		{
			int start_x = start[i], start_y = start[j];
			int link_x = link[i], link_y = link[j];
			s_start += map[start_x][start_y] + map[start_y][start_x];
			s_link += map[link_x][link_y] + map[link_y][link_x];
		}
	}
	// 스타트팀과 링크팀의 최소 능력치 차이 구하기
	
	ans = min(ans, abs(s_start - s_link));
	//초기화
	s_start = 0, s_link = 0;
	start.clear();
	link.clear();

	return 0;


}





int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin>>map[i][j];
		}
	}
	dfs(0,0);//**
	cout << ans << endl;
	return 0;
}