#include <iostream>
using namespace std;
//������[]���� ����� []+1�� ��������.
int n[10][1001];
//�����
int m[10][1001];
int N, M, K, A, B;
//����â���� ������ �����ϴµ� �ɸ��� �ð�
int ai[10];
//����â���� ������ �����ϴµ� �ɸ��� �ð�
int bj[10];
int tk[1001];
int nj, mj;//������ ����� index
int waitinglist1[1001];
struct person {
	int num;
	int time;
};

int main()
{
	int T;
	cin >> T;
	int test_case = 1;
	struct person person[1001];
	while (T >= test_case) {
		cin >> N >> M >> K >> A >> B;
		for (int i = 1; i <= N; i++)
			cin >> ai[i];
		for (int i = 1; i <= M; i++)
			cin >> bj[i];
		for (int i = 1; i <= K; i++)
			cin >> tk[i];

		for (int t = 0; ; t++)//�ð� ����
		{
			cout << t << "�� ��Ȳ" << endl;
			for (int j = 0; ;)
			{
				for (int i = 1; i <= K;)//i�� ����ȣ
				{
						if (tk[i] == t)//�մ��� ���� �����ϸ�
						{
							waitinglist1[j] = i;//��⸮��Ʈ�� �θ���
							j++; i++;
						}
						else
						{
							break;
						}
						i++;
					
				}
			}
		}
	}
}