#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//1~49���� k�� ���� �߿��� 6�� ����
//S�� k�� �־����� �� �� ����
//S�� �־����Ƿ� permutation �Լ��� ���� ���� ���� ��

bool cmp(vector<int> a,vector<int> b)
{
	return a < b;
}

//������ �������� ������ ��:greater<int>() �� sort�� ������ ���ڷ� ���ָ� �ȴ�

int main()
{
	//0�� �ƴϸ� ��� �Է� �ޱ�
	vector<int> k;
	vector<vector<int>> s(10, vector<int>(20));
	
	int var;
	vector<int> trick;
	int test_case = 0;

	cin >> var;
	
	while (var != 0)
	{
		k.push_back(var);
		for (int i = 0; i < k[test_case]; ++i){
			cin >> var;
			s[test_case][i]=var;
		}

		++test_case;//���� test_case 1
		cin >> var;
	}
	int T = test_case;
	test_case = 0;
	while (T>test_case) {
		//���� ����� 0111111->1011111->... 
		//��� ����� 1111110->1111101->... �Ǿ����
		for (int i = 0; i < 6; ++i)
			trick.push_back(1);
		for (int i = 0; i < k[test_case] - 6; ++i)
			trick.push_back(0);

		//sort(trick.begin(), trick.end(), greater<int>());

		//������������ sorting�ϸ� 1111110, greater<int>()
		//�������� �� do,while(prev_per)�ϸ� �ȹٷ�, ���� ��µ�
		//�������� �� do,while(next_per)�ϸ� �ȹٷ�, �ϳ��� ��µ�

		//������������ sorting�ϸ� 0111111
		//�������� �� do,while(prev_per)�ϸ� �Ųٷ�, �ϳ��� ��µ�
		//�������� �� do, while(next_per)�ϸ� �Ųٷ�, ���� ��µ�

		//for (int i = 0; i < trick.size(); ++i)
		//	cout << trick[i];
		//cout << endl;
		do{
			for (int i = 0; i < k[test_case]; ++i)
			{
				if (trick[i])
					cout << s[test_case][i] << " ";
			}
			cout << endl;
		} while (prev_permutation(trick.begin(), trick.end()));
		//next_permutation ��ſ� prev_permutation ���

		cout << endl;
		trick.clear();
		//s.clear();
		++test_case;
	}
	return 0;
}