#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;//�����
int chk[20];//��� ������ ���� �迭
int map[20][20];//����� �ִ� 20��
vector<int> start;
vector<int> link;
int s_start;//��ŸƮ ���� �ó��� ��
int s_link;//��ũ ���� �ó��� ��
int ans=1000;//�ּҰ� ������� ����

int cal();
int dfs(int idx, int num)
{
	if(idx==n/2)
	{
		
		//�ó��� ��� �Լ�
		cal();
		//->�� ���̰� �ּҰ� �Ǵ��� Ȯ���ϴ� �Լ�

		////�� ���� ���� �˰��� ����� ­���� �����غ���// �� ���� ����� ����ϱ�
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

		chk[i] = 1;//��������
		dfs(idx + 1,i);//num�� i �ֱ�****
		chk[i] = 0;//������ �����϶�� �ڸ� ���ֱ�
		}
	}
	return 0;
}
//�ó��� ��� �Լ�
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
	// ��ŸƮ���� ��ũ���� �ּ� �ɷ�ġ ���� ���ϱ�
	
	ans = min(ans, abs(s_start - s_link));
	//�ʱ�ȭ
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