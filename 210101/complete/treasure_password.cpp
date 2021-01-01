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
		//N�� ���ڿ� ����, K�� ���°�� ū���� ����Ұ���
		cin >> N >> K;
		string s;
		cin >> s;//N ������ ���ڿ��� �Է¹���

		set<int, greater<int>> pw;//�������� ����

		int key_length=s.size()/4;

		//cout << "key_length:" << key_length << '\n';

		
		for(int i=0;i<key_length;i++)
		{
			//cout<< "s:" << s << "\n";
			string s_back;
			//1. ���ھ� ������(�ڿ��� ������ ���δ�)
			s_back=s.back();
			s.pop_back();
			s.insert(0, s_back);
			//cout << "s_back:" << s_back << " " << "s:"<<s << "\n";

			//2. ����
			string s1;
			s1=space(s, key_length);//s+����->s1
			
			//3. set�� �ִ´�
			//���ҵ� ���ڿ����� double���·� �ٲ㼭 ũ�� ������ �ڵ�����
			
			//for()
			//{
				//���ڿ��� ���ڹ迭�� ����
				//strtok�� ���� ���ؼ� ���ڿ��� ���ڹ迭�� ��ȯ
				//�̷��Ÿ� ó������ �迭�� �޴°� ����������..
				char cstr[100];//N�ִ밪�� 28��
				//�������� 30���� ���� �� ��������
				strcpy(cstr, s1.c_str());

				double number;
					
				//���ڿ� ����
				char* tok1=strtok(cstr, " ");
				//���⼭���ʹ� string s1�� �ƴ϶� char_array cstr��
				while (tok1 != NULL) {
					//cout << tok1 << endl;
					
					number = strtol(tok1, NULL, 16);//16������ ��ȯ�ؼ�
					pw.emplace(number);//set�� ����

					tok1 = strtok(NULL, " ");
				}
				/*NULL�� �־��� ���� ���� strtok �Լ����� ó���ߴ� ���ڿ����� �߸� ���ڿ���ŭ 
				���� ���ڷ� �̵��� �� ���� ���ڿ��� �ڸ��ϴ� �߸� ���ڿ��� �����͸� �ٽ� �־��� ���� 
				���� ���ڷ� �̵����� ���ϰ� ó���� ������ ���ڿ��� ��� �ڸ��� �˴ϴ�*/

				
		}
		
		////�ϴ� pw set ��ü ����غ���
		//for (auto x : pw) {
		//	cout << hex <<uppercase<< x <<' ';
		//}
		int i = 1;
		//set���� K index�� �ش��ϴ� ���� ����Ѵ�
		for (set<int>::iterator it = pw.begin(); it != pw.end(); ++it)
		{
			if (i == K) {
				cout << "#"<<test_case<<" "<<*it << endl;
			}
			i++;
		}
		
		
		//��ȸ�ϴ� �ð��� ���� �� ������?
		//���ϴ� iterator index�� ��� �ٷ� ��������?



		test_case++;//�ѹ� �����ϰ� ���� test_case����
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
	//s1���� �Ϸ�
	return s1;
}