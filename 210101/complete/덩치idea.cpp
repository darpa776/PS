#include <iostream>
#include <vector>
using namespace std;

int n;//�����
//vector<pair<int, int>> person;//��� ���� ����
int person[100][3];//��� ���� ����+���
int cnt;

int main()
{
	cin >> n;
	int a, b = 0;
	int equal=0;
	person[0][2] = -200;//���߿� shift�� ���� ��(+��ȣ)�� �������� �򰥸��� �ʵ���
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b;

		person[i][0] = a;//������
		person[i][1] = b;//Ű


		for (int j = 0; j < i; ++j)
		{
			if (person[j][0] > a)//�� �Է��� �������� ������ ������� --;
				--cnt;
			else if (person[j][0] < a)
				++cnt;
			else if (person[j][0] < a)
				++equal;
			if (person[j][1] > b)
				--cnt;
			else if (person[j][1] < b)
				++cnt;
			else if (person[j][1] < b)
				++equal;

			if (cnt == 0||equal)
				person[i][2] = person[j][2];
			else if (cnt < 0)
				person[i][2] = person[j][2] + 1;
			else if (cnt > 0)
				person[i][2] = person[j][2] - 1;
			cnt = 0;
			equal = 0;
		}


	}

//	for (int i = 0; i < n; ++i)
//	{
//		cout << person[i][2] << endl;
//	}


	//shift
	signed int min = 5000;//����

	for (int i = 0; i < n; ++i)
	{
		if (min > person[i][2])
		{
			min = person[i][2];
			//������ min ������� ���� ģ������ ���� �� �ִ�.
		}

	}
	//2. �ּҰ��� ģ���� ������� ���Ƹ���
		//1��ο�

	int k = 0;
	int rank = 1;//��� ����
	while (rank <= n)//��� ���� �� ���Ǳ�
	{
		for (int i = 0; i < n; ++i)
		{
			if (min == person[i][2])
			{
				person[i][2] = rank;
				++k;
			}

		}
		++min;
		rank += k;
		k = 0;

	}

	for (int i = 0; i < n; ++i)
	{
		cout << person[i][2] << endl;
	}
	return 0;
}