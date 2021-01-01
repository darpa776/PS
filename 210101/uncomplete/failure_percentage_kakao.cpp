
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(pair<int, float> a, pair<int, float> b)//���� �� �ƴ�. �ڷ����� ������ ��
{
	if (a.second == b.second)//�������� ������
		return a.first < b.first;//stage�� ������ �տ� ��

	return a.second > b.second;//�Ϲ������� �������� ū�� �տ���
}

vector<int> solution(int N, vector<int> stages) {
	//sort(stages.begin(), stages.end());
	int arr[501] = { 0, };
	vector<pair<int, float>> fail;
	for (auto iter = stages.begin(); iter != stages.end(); ++iter) {
		arr[*iter-1]++;//arr������ 0����,iter ������ 1���� end+1����
		//*iter stage�� �� ������� ��� �����ϴ���
		//�̷��� �ϸ� �����ؼ� �ο� ����� �ʿ� ����
	}
	int num = stages.size();
	for (int i = 0; i < N; i++)//�Ѱ������� num�� �ƴ϶� N��
	{//N:��ü �������� ����
	 //num:��ü ����� ��
	 //���� N<num
		if (arr[i] == 0)
		{//i�� �������� �ѹ��� �Ǿ����
			fail.push_back(make_pair( i+1 , 0));
			//push_back���ٶ� �� make_pair�� ����� ��
			num -=arr[i];
		}

		else {
			fail.push_back(make_pair(i + 1, (float)arr[i] / num));
			//push_back���ٶ� �� make_pair�� ����� ��
			num -= arr[i];
		}
	}

	sort(fail.begin(),fail.end(),cmp);
	vector<int> answer;
	for (auto iter = fail.begin(); iter != fail.end(); ++iter) {
		answer.push_back(iter->first);
		
	}
	for (auto iter = answer.begin(); iter != answer.end(); ++iter) {
		cout << *iter;
	}
	return answer;
}

int main()
{
	vector<int> stage = { 2,1,2,6,2,4,3,3 };
	solution(5, stage);
	
	
}