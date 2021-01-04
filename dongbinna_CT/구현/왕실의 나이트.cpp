#include <iostream>
#include <string>
using namespace std;

//입력 : 나이트의 위치(a1)
//출력 : 나이트가 이동할 수 있는 경우의 수
int main()
{
//1. 입력문자 분리
  string st;
  cin>>st;
  //2. 위치 알아내기
  int x,y;
  //**문자열을 문자로 변환
  y = st[1] - '0';
  //현재 문자열로 입력받았기 때문에 숫자도 지금은 정수형이 아니라 문자형이다. 아스키코드값을 이용해서 정수로 바꾼다.
  x = st[0] - 'a' + 1;
  //a가 1, b는 2가 되도록 a만큼의 알파벳 아스키코드값을 뺀 후 1을 더해 원점의 위치를 1,1에 맞게 조정

  //3. 경우의 수 알아내기
  int dx[8]={-1,1,2,2,1,-1,-2,-2};
  int dy[8]={-2,-2,-1,1,2,2,1,-1};
  int count;//answer
  for(int i=0;i<8;i++)
  {
    if(x+dx[i]<1||x+dx[i]>8||y+dy[i]<1||y+dy[i]>8)
    {
      continue;
    }
    else
    {
      count+=1;
    }
  }

  cout<<count<<endl;
  return 0;
}