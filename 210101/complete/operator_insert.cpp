#include <iostream>

using namespace std;
int n;//���� ����
int num[12];//�Է� ���� ������ ���� ����(2~11)
int opr[4];//�������� ������ ��� �ִ� ����(��������)

int maxx=-1000000000;//�ٽ��ѹ� �� Ȯ���ϱ�
int minn=1000000000;

int dfs(int idx,int result)
{
	if (idx == n)
	{
		if (result >= maxx)
		{
			maxx = result;
		}
		if (result <= minn)
		{
			minn = result;

		}
		return 0;
	}


	if (opr[0] > 0)
	{
		opr[0]--;
		dfs(idx + 1, result + num[idx]);
		opr[0]++;

	}
	if (opr[1] > 0)
	{
		opr[1]--;
		dfs(idx + 1, result - num[idx]);
		opr[1]++;
	}
	if (opr[2] > 0)
	{

		opr[2]--;
		dfs(idx + 1, result * num[idx]);
		opr[2]++;
	}
	if (opr[3] > 0)
	{
		opr[3]--;
		dfs(idx + 1, result / num[idx]);
		opr[3]++;
	}
	
	return 0;
}

int main()
{
	
	//���� ���� �Է�(n)
	cin >> n;
	//���� �Է�(n)
	for (int i = 0; i < n; ++i)
	{
		cin >> num[i];
	}
	//4������ ������ ���� �Է�(4���� �����ļ� n-1)
	for (int i= 0; i < 4; ++i)
	{
		cin >> opr[i];
	}
	//���� dfs�� ��������
	dfs(1, num[0]);
	cout << maxx<<endl; 
	cout << minn<<endl;
	//ambigious�϶��� builtin �־ �׷��ϱ� �������� �ٲ�����
	return 0;

}