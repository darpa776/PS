#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int T,test_case;
int ans;
int charge[4];
int plan[12];
int d[12];
vector<int> one;//1�ϱ�,1�ޱ����� ����

void dp()
{

	//1�ޱ�,1�ϱ� ��
	for (int i = 0; i < 12; ++i)
	{
		if (plan[i] == 0)
			one.push_back(0);
		else if (charge[0] * plan[i] < charge[1])//1�ޱǺ��� 1�ϱ��� �� �Ҷ�
			one.push_back(plan[i] * charge[0]);//one vector�� 1�ϱ����� �ִ´�
		else
			one.push_back(charge[1]);//one vector�� 1�ޱ����� �ִ´�

		if (i == 0)
			d[i] = one[i];
		else if (i != 0)//i�� 0�� �ƴҶ���, i�� 0�̸� -1�� ������ �� �����Ƿ�.
			d[i] = d[i - 1] + one[i];//�̶������� �ּҿ��
		//3�ޱ��̶� ���� �ּҿ���� ����ؾ��Ѵ�
	//------1�ϱ�,1�ޱ� ����Ϸ�

	//3�޸𿴴��� Ȯ���ϱ�
		if (i >= 2)//3������
		{
			if (i == 2)
				d[i] = min(d[i], charge[2]);
				//3������ 1�ޱ�/1�ϱ��� ���� ���� 3���� �� �ּҰ��� �ּҿ������ �ִ´�
			else
				//�⺻ ��ȭ��
				d[i] = min(d[i - 1] + one[i], d[i - 3] + charge[2]);
				//5������ �ּҿ���� min(4������ �ּҿ��+5�� 1�ϱ�/1�ޱ�,2������ �ּҿ��+3�ޱ�)

		}


	}
	//1��ǰ� ���ϱ�
	ans = min(d[11], charge[3]);

}
int main() {
	freopen("sample_input.txt", "r", stdin);
	cin >> T;//test_case ����� �Է¹ޱ�
	while (test_case < T)
	{
		for(int i=0;i<4;++i)
			cin>> charge[i];//�̿�� ���ݵ�
		for (int i = 0; i < 12; ++i)
			cin >> plan[i];//�̿��ȹ
		
		dp();
	
	
	++test_case;
	cout<<"#"<< test_case<<" "<< ans<<endl;
	//�ʱ�ȭ
	ans = 0;
	one.clear();
	}
	return 0;
}
