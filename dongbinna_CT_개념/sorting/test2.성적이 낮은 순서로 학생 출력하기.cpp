#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Student {
public:
	string name;
	int score;
	Student(string name, int score) {
		this->name = name;
		this->score = score;
	}

	bool operator<(Student& other) {
		return this->score < other.score;
		//성적이 낮은 순으로 출력
	}
};

int main()
{
	int n;
	cin >> n;

	vector<Student> list;
	for (int i = 0; i < n; ++i)
	{
		string name;
		int score;
		cin >> name >> score;
		list.push_back(Student(name, score));
	}//입력완료
	sort(list.begin(), list.end());

	//결과 출력
	for (int i = 0; i < n; i++)
	{
		cout << list[i].name << " ";
	}
	
	return 0;
}




