#include <iostream>
#include <string>
#include <set>
#include <cstdio>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
string space(string, int);

int main()
{
	freopen("sample_input.txt", "r", stdin);
	int T, test_case;
	test_case = 1;
	
	
	cin >> T;
	
	
	while (T >= test_case)
	{
		int N, K;
		//N은 문자열 길이, K는 몇번째로 큰수를 출력할건지
		cin >> N >> K;
		string s;
		cin >> s;//N 길이의 문자열에 입력받음

		set<int, greater<int>> pw;//내림차순 정렬

		int key_length=s.size()/4;

		//cout << "key_length:" << key_length << '\n';

		
		for(int i=0;i<key_length;i++)
		{
			//cout<< "s:" << s << "\n";
			string s_back;
			//1. 한자씩 돌린다(뒤에껄 앞으로 붙인다)
			s_back=s.back();
			s.pop_back();
			s.insert(0, s_back);
			//cout << "s_back:" << s_back << " " << "s:"<<s << "\n";

			//2. 띄어쓴다
			string s1;
			s1=space(s, key_length);//s+공백->s1
			
			//3. set에 넣는다
			//분할된 문자열들을 double형태로 바꿔서 크기 순으로 자동정렬
			
			//for()
			//{
				//문자열을 문자배열로 변경
				//strtok를 쓰기 위해서 문자열을 문자배열로 변환
				//이럴거면 처음부터 배열로 받는게 나았을지도..
				char cstr[100];//N최대값이 28임
				//부족한지 30으로 했을 때 에러났음
				strcpy(cstr, s1.c_str());

				double number;
					
				//문자열 분할
				char* tok1=strtok(cstr, " ");
				//여기서부터는 string s1이 아니라 char_array cstr임
				while (tok1 != NULL) {
					//cout << tok1 << endl;
					
					number = strtol(tok1, NULL, 16);//16진수로 변환해서
					pw.emplace(number);//set에 넣음

					tok1 = strtok(NULL, " ");
				}
				/*NULL을 넣었을 때는 직전 strtok 함수에서 처리했던 문자열에서 잘린 문자열만큼 
				다음 문자로 이동한 뒤 다음 문자열을 자릅니다 잘린 문자열의 포인터를 다시 넣었을 때는 
				다음 문자로 이동하지 못하고 처음에 나오는 문자열만 계속 자르게 됩니다*/

				
		}
		
		////일단 pw set 전체 출력해보기
		//for (auto x : pw) {
		//	cout << hex <<uppercase<< x <<' ';
		//}
		int i = 1;
		//set에서 K index에 해당하는 값을 출력한다
		for (set<int>::iterator it = pw.begin(); it != pw.end(); ++it)
		{
			if (i == K) {
				cout << "#"<<test_case<<" "<<*it << endl;
			}
			i++;
		}
		
		
		//순회하는 시간을 줄일 수 있을까?
		//원하는 iterator index에 어떻게 바로 접근하지?



		test_case++;//한번 수행하고 나면 test_case증가
	}
	return 0;
}

string space(string s,int key)
{
	string s1 = "";
	int i = 1;
	for (auto x : s) 
	{
		if (i%key == 0)
		{
			s1 += x;
			s1 += " ";
			//cout<<"s2:" << s2 << "\n";
		}
		else
		{
			s1 += x;
			//cout<<"i:"<<i<< " s2:" << s2 << "\n";
		}
		i++;
		//cout << "s1:"<<s1 << "\n"<<"s2:" << s2<<"\n";
	}
	//s1분할 완료
	return s1;
}