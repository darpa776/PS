#include <iostream>
#include <vector>
using namespace std;

int n;//�����
//vector<pair<int, int>> person;//��� ���� ����
int person[100][3];//��� ���� ����+���
int cnt;
int k;
int main()
{
	cin >> n;
	int a, b = 0;

	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b;

		person[i][0] = a;//������
		person[i][1] = b;//Ű

	}
	//�Է� �ٹ���
	//�񱳽���
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)//i�� ���� j�� �񱳴��
		{
			if (i == j)
				continue;

			if ((person[i][0] < person[j][0]) && person[i][1] < person[j][1])//��ġū ���(k) ���Ƹ���
				++k;

		}
		person[i][2] = k + 1;
		k = 0;
	}

	for (int i = 0; i < n; ++i)
	{
		cout << person[i][2] << endl;
	}

	return 0;
}