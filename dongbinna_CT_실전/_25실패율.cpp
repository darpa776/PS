#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<float, int>> result;
vector<int> answer;//solution 함수의 리턴형
bool cmp(pair<float, int> a, pair<float, int> b) {

	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first > b.first;
	
}


	vector<int> solution(int n, vector<int> stages) {
	int length = stages.size();
	
	for (int i = 1; i <= n; i++)
	{
		int person = count(stages.begin(), stages.end(),i);
		//cnt= i단계에 해당하는 사람들 수
		//실패율, stage num 입력
		//실패율= 스테이지에 도달했으나 아직 클리어하지 못한 유저 수/스테이지에 도달한 유저 수
        
        // 실패율 계산
        float fail = 0;
        if (length >= 1) {
          fail = (float) person / length;
          }
        
		result.push_back({ fail,i });
        length-=person;
	//마지막 단계를 통과한 사람은 분모인 length에 다 포함되어 있음!!
	}
        
     
        
        
        
	sort(result.begin(), result.end(), cmp);
	//정렬다하고 나면 실패율 순서대로 stage 출력하기
	for (int i = 0; i < result.size(); i++)
	{
		answer.push_back(result[i].second);
	}
	return answer;
}
