#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
//pair�� struct�߿� struct���
struct person {
	int x, y;
	//������ǥ
}typedef person;
person a, b;

struct A {
	//��ġ
	int x, y;
	//����
	int c;
	//������
	int p;
};
struct A BC[9];

int ap[101];//ȭ��ǥ����
int bp[101];
//set<int> max_;
int flag_A[9], flag_B[9];//Ư���ð��� ���Ӱ����� BC�� index�� ����
int power;//power �ִ밪 ����. +=�̿�

void path(int, person);

int main()
{
	freopen("sample_input.txt", "r", stdin);
	int T;
	cin >> T;

	int M, A;
	
	//M:�̵��ð�, A:���������� ����
	
	int n;//�ӽú���
	int test_case = 1;
	while (T--) {
		
		cin >> M >> A;

		for (int i = 0; i < M; i++) {
			cin >> n;
			ap[i]=n;
			//path(n, a);
		}
		for (int i = 0; i < M; i++) {
			cin >> n;
			bp[i] = n;
		}//ȭ��ǥ�� �����ϰ� �ʿ��� �� �ǽð����� ��ΰ����
		//�����̽��� �ϸ� �迭�� �ϳ��� ��***

		for (int i = 1; i <= A; i++) {
			cin >> BC[i].x >> BC[i].y >> BC[i].c >> BC[i].p;
		}//index�� 1���� �����Ѵ�.


		for (int i = 0; i <= M; i++) {
			//i==0�� ��. �ʱ���ġ�� BC��ȿ�������� ����غ�����
			if (i == 0) {
				b.x = 10; b.y = 10;
			}

			//2. BC��ȿ���� ���
			int dist;
			for (int j = 1; j <= A; j++) {
				dist = abs(a.x - BC[j].x) + abs(a.y - BC[j].y);
				if (dist <= BC[j].c) {
					flag_A[j] = j;
				}
				dist = abs(b.x - BC[j].x) + abs(b.y - BC[j].y);
				if (dist <= BC[j].c) {
					flag_B[j] = j;//BC�� index��ü�� �ִ´�
				}

			}
			
			//3. ������ ���
			//int temp_A,temp_B=0;
			int temp = 0;

			for (int j = 1; j <= A; j++) {
				//������ BC�� A�� �ִ� ���
				
					//Ž���ϴ� �ΰ��� ���Ұ� ���� ���� ���
					if (flag_A[j] == flag_B[j]) {
						if (flag_A[j]) {
							if (temp < BC[j].p) {
								temp = BC[j].p;
							}
						}
					}
					//Ž���ϴ� �ΰ��� ���Ұ� ���� ���� �������
					//(0,1)�Ǵ� (1,0)
					else if (flag_A[j] != flag_B[j]) {
						if (flag_A[j] | flag_B[j]) {//(1,0)
							if (temp < BC[j].p) {
								temp = BC[j].p;
							}
						}
					}
					
				/*	if (flag_A[j]) {
						for (int k = j; k <= A; k++) {
							
							if (flag_B[k] & flag_A[j]) {
								if (temp < BC[j].p + BC[k].p) {
									temp = BC[j].p + BC[k].p;

								}
							}

						}
					}*/
					
					power += temp;
					temp = 0;//Ȥ�� ���� �ʱ�ȭ
					//for���� �ϰ� if���� �ϴ°� ������ if���� �ϰ� for���� �ϴ°� ������?
					//�ΰ��� ������?
					//������ BC�� B���� �ִ� ���
					/*if (flag_B[j]) {

					}
					power += temp;
					temp = 0;//Ȥ�� ���� �ʱ�ȭ*/
					
				



			}
			
			//1. ����� �̵�
			path(ap[i], a); path(bp[i], b);

		}

		//4. ������ �ִ밪 ���
		cout << '#' << test_case<<" "<<power<<endl;
			test_case++;
	}
	return 0;

}

void path(int n, person p){
	//ȭ��ǥ->��ǥ
	switch (n)
	{
		case 1:
			p.y--;
			break;
		case 2:
			p.x++;
			break;
		case 3:
			p.y++;
			break;
		case 4:
			p.x--;
			break;
	default:

		//�ƹ��͵� ��������,skip
		break;
	}

}