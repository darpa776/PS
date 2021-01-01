#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int n, k, m;
int T, test_case;
int ans;
int chem[100][100];
//int visit[100][100];//n*n*k(�ִ� ����)//int�� 2�����迭���ٰ� vector�� �־��
vector<int> visit[100][100];//???***???


typedef struct microbial {//�̻��� ����
	//pair<int, int> pos;
	int x; int y;//���� ��ġ
	int num;//�̻��� ��
	int dir;//����
	int alive=1;//����ִ���
}microbial;

//queue<microbial> q;
vector<microbial> dic;
void direction(microbial* now, int dir)
{//now�� �� ������ ��ȿ�Ϸ��� �����͸� �����**
	if(dir==1) //�� 
		now->x -= 1;
	else if(dir==2)//��
		now->x += 1;
	else if(dir==3)//��
		now->y -= 1;
	else if(dir==4)//��
		now->y += 1;
}
//******dic�� �ʱ�ȭ0�� �򰥸��� �ʱ����� 1���� �����Ѵ�(1~k)
int main() {
	freopen("sample_input.txt", "r", stdin);
	cin >> T;
	while (test_case < T)
	{
		cin>>n>>m>>k;
		//1. ��ǰ �߸��� ����
		for (int i = 0; i < n; ++i)
		{
			chem[0][i] = 1;//�� �׵θ�
			chem[n - 1][i] = 1;//�Ʒ� �׵θ�
			chem[i][0] = 1;//���� �׵θ�
			chem[i][n - 1] = 1;//������ �׵θ�
		}
		microbial trash;
		trash.alive = 0;
		dic.push_back(trash);
		//2.q�� �⺻ setting
		for(int i=1;i<=k;++i)
		{
			microbial input;
			cin >> input.x>>input.y>>input.num>>input.dir;//���� �Է�
			
			dic.push_back(input);
		}
		//�Է¿Ϸ�
 		while (m > 0)
		{
			for (int i = 1; i <=k; ++i)
			{
				/*microbial now = q.front();
				q.pop();*/
				
				//1) ������ ����ؼ� ���� �� ���� ����
				if (dic[i].alive) {
					direction(&dic[i], dic[i].dir);//�� x,y�� �����
					visit[dic[i].x][dic[i].y].push_back(i);//���� �� ���� �湮���� ǥ��
				}
			}
			//2) ������ġ�� �ߺ��Ǵ� ��� ó��
			//�� ���� ���� �� 2�̻��� ���� �浹�Ѵ�
			//2 �̻��� ��� ���⸦ �湮�ϰڴٰ� �� ���� ã�Ƽ� 
			//(queue ��ſ� ���ͷ�? ��ǥ���� �����س��� ���� �� �����ϱ�)
			//�̻������� ������ ���ϰ� ���ľ��Ѵ�
				//chem�ΰ��� ����ó�� ���ֱ�

			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					if (visit[i][j].size() > 1)
					{
						int max_bio = 0;
						int sum_bio = 0;
						//�̻������� ������ ���ϰ� ���ľ��Ѵ�

						for (int l = 0; l < visit[i][j].size(); ++l)//����ִ� �͵鸸 visit�� �������� ����
						{
							max_bio=max(max_bio,dic[visit[i][j][l]].num);//��ݽ�ȭ �̷��� ���� �ִٴ�**
							//���� �ڷ��� https://hibee.tistory.com/273 ����
							sum_bio += dic[visit[i][j][l]].num;
						}
						for (int l = 0; l < visit[i][j].size(); ++l)
						{
							if (max_bio == dic[visit[i][j][l]].num)
								//**alive ���� �̿��ϱ� (���� ����Ʈ ������)
								//ť�� �ƴ϶� ���� ������ pop�ϱ� ��ٷο�
								//dir �ٲ� �ʿ���� �׳� �� ������ ���� �̻������� �־��ָ��
								dic[visit[i][j][l]].num=sum_bio;
							else
								dic[visit[i][j][l]].alive = 0;//�� �ְŵ�
						}

						
					}
				}
			}
			//chem�ΰ��� ����ó�� ���ֱ�*************
			for (int i = 1; i <= k; ++i)
			{
				if (dic[i].alive&&chem[dic[i].x][dic[i].y])//����ְ� nx ny�� chem�ΰ��̸�
				{//����ٲٰ�
					if (dic[i].dir % 2)//Ȧ����
						dic[i].dir++;
					else//¦����
						dic[i].dir--;
					//1�̸� 2��,2�̸� 1����, 3�� 4��,4�̸� 3��
					//1�Ǵ� 3�̸� --,2�Ǵ� 0�̸�++

				//��ƴ ���̱�
					if (dic[i].num % 2)//Ȧ����
						dic[i].num = (dic[i].num - 1) / 2;
					else//¦����
						dic[i].num /= 2;
				}
			}
			--m;//1�ð� ���
			//visit �ʱ�ȭ***
			for (int i = 0; i < 100; ++i)
				for (int j = 0; j < 100; ++j)
				
					visit[i][j].clear();//???***???


			
		}

		//����ִ� �̻����� ����
		
		for (int i = 1; i <=k; ++i)
		{
			if (dic[i].alive)
				ans+=dic[i].num;

		}
		++test_case;
		cout << "#" << test_case << " " << ans << endl;
		ans = 0;//�ʱ�ȭ
		dic.clear();
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)

				chem[i][j] = 0;
		}
	}
	return 0;
}
