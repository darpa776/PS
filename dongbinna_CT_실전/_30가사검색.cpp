#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//?가 들어간 곳에 a~z까지 찾기
int count(vector<string>& v, string leftv, string rightv) {
	
	//?부분에 a부터 z로 들어온 범위를 조사
	vector<string>::iterator right = upper_bound(v.begin(),v.end(),rightv);//z로 들어온 친구들
	vector<string>::iterator left = lower_bound(v.begin(), v.end(), leftv);//a로 들어온 친구들
	return right-left;
}

//?를 특정 알파벳으로 변경하는 함수
string change(string q, string old, string new_) {
	int pos = 0;
	//find 함수에서 두번째 인자인 pos는 찾기 시작할 위치를 나타낸다.
	while ((pos = q.find(old, pos)) != string::npos)//찾는 문자열이 없는 경우 npos를 반환한다
	{//find 함수에서 탐색은 pos 부터 시작한다.
		q.replace(pos, old.size(), new_);
		//pos위치부터 old.size()크기만큼의 문자들을 _new문자로 바꾼다.
		pos += new_.size();
	}
	return q;
}

vector<int> solution(vector<string> words, vector<string> queries){
	vector<int> answer;//각 keyword가 포함된 개수를 반환

	//?가 끝에 붙은경우
	//?가 앞에 붙은경우(뒤집기)
	//각각 저장하기
	vector<string> arr[10001];//단어의 길이에 따라 나눠서 넣는다
	vector<string> reversed_arr[10001];
	for (int i = 0; i < words.size(); i++) {
		string word = words[i];
		arr[word.size()].push_back(word);
		reverse(word.begin(), word.end());
		reversed_arr[word.size()].push_back(word);//단어를 뒤집어서 삽입

	}

	//정렬
	for (int i = 0; i < 10001; i++) {
		sort(arr[i].begin(), arr[i].end());
		sort(reversed_arr[i].begin(), reversed_arr[i].end());
	}

	//쿼리에 맞는 단어 개수 찾자
	for (int i = 0; i < queries.size(); i++)
	{
		string q = queries[i];
		int cnt;
		if (q[0] == '?') {//접두사에 ?가 붙은 경우 reversed_arr에서 찾는다
			reverse(q.begin(), q.end());
			cnt= count(reversed_arr[q.size()], change(q, "?", "a"), change(q, "?", "z"));
		}

		else {//접미사에 ?가 붙은경우 arr에서 찾는다
			cnt = count(arr[q.size()],change(q,"?","a"), change(q, "?", "z"));
			//?를 특정 알파벳으로 변경하는 함수 사용
			//q의 ?를 a로 바꾼 친구들부터 z로 바꾼 친구들의 개수를 찾기! 
		}
		answer.push_back(cnt);
	}
	return answer;
}
