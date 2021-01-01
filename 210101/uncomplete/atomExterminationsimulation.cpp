#include <iostream>

using namespace std;

struct atominfo{
	int x, y, dir,k;
};
struct atominfo atom[1001];
int up[1001],down[1001],_left[1001],_right[1001];

int main()
{
	freopen("sample_input_atom.txt", "r", stdin);
	int T,test_case = 1;
	int N;
	cin >> T;
	while (T >= test_case) {
		cin >> N;
		int u = 1, d = 1, l = 1, r = 1;
		//���� �����ϱ� ���� ���⺰�� atom �з�
		for (int i = 1; i <= N; i++) {
			cin >> atom[i].x >> atom[i].y >> atom[i].dir >> atom[i].k;
			switch (atom[i].dir)
			{
			case 0:
				up[u] = i;
				u++;
				break;
			case 1:
				down[d] = i;
				d++;
				break;
			case 2:
				_left[l] = i;
				l++;
				break;
			case 3:
				_right[r] = i;
				r++;
				break;
			default:
				break;
			}
		}
		int flag=0;
		
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				
					if ((_left[i] != 0) && (_left[j] != 0) && (_right[i] != 0) && (_right[j] != 0) && (up[i] != 0) && (up[j] != 0) && (down[i] != 0) && (down[j] != 0)) {

						//1)x�� y�� ������ ���
						//�¿�� ���� ���
						if (atom[_left[i]].y == atom[_right[j]].y) {
							if (atom[_left[i]].x > atom[_right[j]].x) {
								flag += atom[_left[i]].k + atom[_right[j]].k;
							}
						}
						//���Ʒ��� ���� ���
						if (atom[up[i]].x == atom[down[j]].x) {
							if (atom[up[i]].y < atom[down[j]].y) {
								flag += atom[up[i]].k + atom[down[j]].k;
							}
						}

						//2)x�� y�� �������� ���� ���
						//��ǥ�� x����, y���� ���밪 ���� ������ ������ �浹�Ѵ�.
						else if (abs(atom[i].x - atom[j].x) == abs(atom[i].y - atom[j].y)) {
							if (j != j) {
								flag += atom[i].k + atom[j].k;
							}
							////(�Ʒ�,��),(��,��)
							//if (atom[i].x + atom[i].y == atom[j].x + atom[j].y)
							//{
							//	
							//}
							//if ()//(�Ʒ�, ��)
							//{
							//}

						}
					}
				
				
			}
		}

		cout << "#" << test_case << " " << flag << endl;
		test_case++;
	}
	return 0;
}

////(�Ʒ�,��) �Ǵ� (��,��)
//				//(1) �� atom x,y�� ���밪 ���� ���� ��
//if (abs(atom[up[i]].x - atom[down[j]].x) == abs(atom[up[i]].y - atom[down[j]].y)) {
//
//}
////(2) �� atom x,y������ ���� ���� ��
////(��,�Ʒ�) �Ǵ� (��,��)
//if () {
//
//}