#include <iostream>

using namespace std;

//typedef struct desks
//{
//	int person, time;
//}desks;
//������, //�����
int n[10][1001], m[10][1001];

int N, M, K, A, B;
//����â���� ������ �����ϴµ� �ɸ��� �ð�
int ai[10];
//����â���� ������ �����ϴµ� �ɸ��� �ð�
int bj[10];
int tk[1001];
//int person = 0;//�մ�
int flag;
int  ttt = 1;//�ּҽð� ��ŭ�� ����
int nj,mj;
struct person {
	int num;
	int time;
}; 
int desk(int mn[10][1001], struct person*);
int desk_time(int nm[10][1001], int, int);

int main()
{
	int T;

	cin >> T;
	int test_case = 1;

	struct person person[1001];
	while ( T>=test_case) {
		cin >> N >> M >> K >> A >> B;

		for (int i = 1; i <= N; i++)
			cin >> ai[i];

		for (int i = 1; i <= M; i++) 
			cin >> bj[i];
		
		for (int i = 1; i <= K; i++)
			cin >> tk[i];

		//---------------�Է�
		//1. setting
		
		
		//�ð� ���� ���� ����� ��� �о�� �� �ִ°�?
		//tk�� ��� ������ ���ΰ�?
		for (int t = 0; ;t++)//�ð� ����
		{
			cout << t << "�� ��Ȳ"<<endl;
			for (int i = ttt;i<=ttt;)//end���� �����س���
			{
				cout << i << "��° ������� scan �մϴ�"<<endl;
				if (tk[i] == t)//�ش��ϴ� �ð��� ����� �ҷ�����
				{//i++����� ��
					person[i].num = i;
					//person[i].time = 1;
					cout << i<<"��° �մ��� �����߽��ϴ�." <<endl;
					for (int j = 0;; j++)
					{
						int time_n = desk(n, &person[j]);
					}

					/////////////
					//���� ����ũ�� �������� ��ٸ���
					flag = desk_time(n, p->time, i);
					if (flag) { i++; }
				}

				else
				{
					break;
				}
				int out=0;
			//����ó�� �ִ� ����� ��������
			//struct�� �ص� �Žð� ���� �������� �˻��ؾ��Ѵ�.
				for(int i=1;out=0;i++)
				{
					out=desk_time (n, person[i].time+i, i);
				if (!out)
				{
					cout << i << "��° ����� �������ϴ�." << endl;
					
					
				}
				}
				//������ ���

				//ndesk A�� mdeskB�� ������ ���ؼ� ���
				
			}
			
		}
		test_case++;
	}

}

int desk(desks mn[10],struct person* p)//����ȣ�� ����.
{
	//int flag=0;
	//�غκк��ʹ� �Լ��� �ۼ��ص� ������ ��
	//N_desk�� ����� ���ٸ� ����� ����
	for (int i = 1; i <= N; )
	{
		flag = desk_time(n, p->time, i);
		//i�� ����ũ�� nj��°�� person.num�� ����
			if (!mn[i][nj]) {//�ƹ��� �� �ɾ��� ��
				


				cout << i << "�� ";
				if (mn == n)
				{
					cout << "����ó�� " ;
					//�ð������Լ����
					//flag = desk_time(n, p->time, i);
					if (flag)
					{
						mn[i] = p->num;//������ ����
					}
					ttt++;
				}
				else if (mn == m)
				{
					cout << "����ҿ�" ;
					//flag = desk_time(m, p->time, i);
					if (flag)
					{
						mn[i][0] = p->num;
					}
					ttt++;
				}
				//cout <<p->time<< "�� ° �ɾ��ֽ��ϴ�" << endl;

				p->time++;
				//flag = i;
				break;
			}
			else//desk�� ����� �ִٸ�
			{
				i++;//index �������Ѽ� �� Ȯ��
				flag = 0;
			}
		
	}
	//for�� �� ���� ����� �� ���ִٸ�
	return flag;
}

int desk_time(int nm[10],int ptime,int desk_number)
{
	if (nm == n)
	{
		if (ptime == ai[desk_number])
		{
			cout << "�� �̻� �ɾ� ���� �� �����ϴ�.\n" << endl;
			desk_number++;
			nj++;
			return 0;
		}
		else
		{
			cout << "��� �ɾ� ���� �� �ֽ��ϴ�.\n" << endl;
			return 1;
		}


	}

	else if (nm == m)
	{
		if (ptime == bj[desk_number])
		{
			cout << "�� �̻� �ɾ� ���� �� �����ϴ�.\n" << endl;
			desk_number++;
			mj++;
			return 0;
		}
		else
		{
			cout << "��� �ɾ� ���� �� �ֽ��ϴ�.\n" << endl;
			return 1;
		}
	}
}