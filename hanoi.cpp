#include <iostream>
#include <cmath>
using namespace std;

int n;//���� �ٸ� n���� ������ �����ִ�.
void hanoi(int num, int from, int tmp, int to)
{
	
	if (num == 2)
	{
		cout << from << " " << tmp<< "\n";
		cout << from << " " << to << "\n";
		cout << tmp << " " << to << "\n";
		return;
	}

	hanoi(num - 1, from,to,tmp);//�����⸦ 1->2�� �׾Ƴ���
	cout << from << " " << to << "\n";//�Ǹ����� ģ���� �״´�
	hanoi(num - 1, tmp,from,to);//2�� �ִ� �����⸦ 3���� �ű��
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	//��տ� ���� �ֱ�, data �Է�
	cout << (int)pow(2, n) - 1 << endl;
	hanoi(n, 1,2,3);
	return 0;
	//(1 << n) - 1
}