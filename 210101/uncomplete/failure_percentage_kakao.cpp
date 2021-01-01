
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(pair<int, float> a, pair<int, float> b)//벡터 페어가 아님. 자료형에 주의할 것
{
	if (a.second == b.second)//실패율이 같으면
		return a.first < b.first;//stage가 작은게 앞에 옴

	return a.second > b.second;//일반적으로 실패율이 큰게 앞에옴
}

vector<int> solution(int N, vector<int> stages) {
	//sort(stages.begin(), stages.end());
	int arr[501] = { 0, };
	vector<pair<int, float>> fail;
	for (auto iter = stages.begin(); iter != stages.end(); ++iter) {
		arr[*iter-1]++;//arr시작은 0부터,iter 시작은 1부터 end+1까지
		//*iter stage를 깬 사람들이 몇명 존재하는지
		//이렇게 하면 정렬해서 인원 고려할 필요 없다
	}
	int num = stages.size();
	for (int i = 0; i < N; i++)//한계조건이 num이 아니라 N임
	{//N:전체 스테이지 개수
	 //num:전체 사용자 수
	 //보통 N<num
		if (arr[i] == 0)
		{//i가 스테이지 넘버가 되어야함
			fail.push_back(make_pair( i+1 , 0));
			//push_back해줄때 꼭 make_pair로 해줘야 함
			num -=arr[i];
		}

		else {
			fail.push_back(make_pair(i + 1, (float)arr[i] / num));
			//push_back해줄때 꼭 make_pair로 해줘야 함
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