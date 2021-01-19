#include <string>
#include <vector>
#include <algorithm>
#include <queue>
//#include <iostream>
using namespace std;

//int main()
//{
//	vector<int> food_times = { 3,1,2 };
//	long long k = 5;

int solution(vector<int> food_times, long long k) {

	// 전체 음식을 먹는 시간보다 k가 크거나 같다면 -1
	long long time = 0;
	for (int i = 0; i < food_times.size(); i++) {
		time += food_times[i];
	}
	if (time <= k) return -1;
	//시간이 가기전에 이미 다먹으면 -1을 리턴

	//min을 편리하게 찾기 위한 밑작업
	priority_queue<pair<int, int>> pq;
	for (int i = 0; i < food_times.size(); i++)
	{
		pq.push({ -food_times[i],i + 1 });//시간,번호를 minheap으로 입력
	}


	long long previous = 0;
	long long now = -pq.top().first;
	//먹는데 제일 적게 걸리는 시간
	long long length = pq.size();
	long long rotate = (now - previous) * length;//먹는데 걸리는 시간


	while (k > rotate)
	{//모든 원소의 시간을 줄이지 않고 (지금 pop하는 시간- 전에 pop한 시간)이 중요
	//항상 다음 원소-현재 원소의 시간차이 만큼을 가지고 있고
	//base가 현재시간만큼 쌓여있는 것이기 때문

		//주요동작
		k -= rotate;//먹고 남은 시간

		//부동작
		pq.pop();
		previous = now;
		now = -pq.top().first;
		length = pq.size();
		rotate = (now - previous) * length;
		
	}

	//남은 음식 중에서 몇 번째 음식인지 확인하여 출력
	//k번째 음식번호가 재방시 먹어야하는 음식의 번호임**
	//pq는 이터레이터가 없어서 인덱스로 접근이 불가하다.
	vector<pair<int, int>> result;
	while (!pq.empty())
	{
		//남은 음식들을 result vector에 저장한다.
		//음식번호, 시간
		result.push_back({ pq.top().second,-pq.top().first });
		pq.pop();

	}
	sort(result.begin(), result.end());
	//음식번호가 오름차순으로 정렬됨

	//남은 k번째 음식번호를 반환한다.
	//이때 k가 남은 음식 종류보다 클 수 있으므로 나머지로 출력한다.
	return result[k % result.size()].first;
	//cout<<result[k%result.size()].first;
}
