#include <string>
#include <vector>
#include <iostream>
#define INF 1e9
using namespace std;
//idea: 비교할 문자열을 따로 저장하고
//비교할 문자열과 다른 새로운 문자열이 나오면
//문자열이 끝날 때까지 비교할 문자열을 갱신한다.
//결과 : (비교할 문자열 길이+1), 여러 문자열이면 문자열 개수만큼.
//여러 문자열일 경우=set가 2개 이상일 경우: result+= 하기
//min함수 써가며 비교할 문자열의 길이를 증가시키기

int count(int x)//자릿수 세는 함수
{
    int cnt = 0;
    while (x > 9)
    {
        x /= 10;
        cnt++;
    }
    return cnt+1;
}

//int main()
//{
//    string s;
//    cin >> s;

int solution(string s) {
    int set = 1;
    string compare_s = s.substr(0, 1);//비교할 문자열
    string new_s;
    int length = INF;
    int new_length = 0;
    int last_idx;
    if (s.size() == 1)
        return 1;
    //cout<<1;
    
    for (int i = 1; i < s.size(); i++)//비교할 문자열의 크기
    {
        compare_s = s.substr(0, i);
        set = 1;
        for (int j = i; j < s.size(); j += i)//비교할 문자열의 시작 위치
        {
            new_s = s.substr(j, i);

            if (compare_s == new_s)
                set++;
            else if (compare_s != new_s)
                //  문자열 끝날때까지 계속 갱신
            {
                compare_s = new_s;
                if (set >= 2)
                {
                    if (set >= 10)
                        new_length += (count(set)+i);
                    else
                    new_length += (1 + i);
                }
                else
                {
                    new_length += i;
                }
                set = 1;
            }
            last_idx = j;
        }
        if (set >= 2)
        {
            if (set >= 10)
                new_length += (count(set) + i);
            else
                new_length += (1 + i);
        }
        else
            new_length += (s.size() - last_idx);
        length = min(length, new_length);
        new_length = 0;
    }
    //cout << length << endl;
    return length;
}
//예외: 반복되는 횟수가 10이 넘는 경우, 글자수는 2자리이므로 1을 더하는것이 아니라
//반복되는 횟수의 자리수만큼 더해주어야 한다.

//예외2: a를 입력하면 1이 나와야한다.
