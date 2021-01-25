#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class info {
public:
	string name;
	int korean;
	int english;
	int math;

	info(string name, int korean, int english, int math) {
		this->name = name;
		this->korean = korean;
		this->english = english;
		this->math = math;
	}
	bool operator<(info& other) {
		if (this->korean != other.korean) {
			return this->korean > other.korean;
		}
		if (this->korean == other.korean && this->english == other.english && this->math == other.math) {
			return this->name < other.name;
		}
		if (this->korean == other.korean && this->english == other.english) {
			return this->math > other.math;
		}

		if (this->korean == other.korean) {
			return this->english < other.english;
		}

	}
};
vector<info> list;
int main()
{
	int n, korean, english, math;
	string name;
	cin >> n;
	//이름, 국영수 성적 입력
	for (int i = 0; i < n; i++)
	{
		cin >> name >> korean >> english >> math;
		list.push_back(info(name, korean, english, math));
	}

	sort(list.begin(), list.end());
	//결과 출력
	for (int i = 0; i < n; i++)
	{
		cout << list[i].name << '\n';
	}//endl 때문에 자꾸 시간초과가 났었음
	return 0;

}
