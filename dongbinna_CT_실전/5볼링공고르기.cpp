#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  int n,m;
  cin>>n>>m;
  //서로 무게가 다른 볼링공 고르기
  //n:볼링공의 개수, m:최대 무게
  vector<int> list;
  for(int i=0;i<n;i++)
  {
    int x;
    cin>>x;
    list.push_back(x);
  }
  
  int count=0;
  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      if(list[i]!=list[j])
        count++;
    }
  }
  cout<<count<<endl;

//이렇게 풀어도 답은 나오는데,
//주어지는 m을 사용하기 위해서는 m을 1부터 m까지 증가시켜가며
//12233의 경우
//A가 1일때(1)* B가 선택할 수 있는 볼링공 개수(4:2233) +
//A가 2일때(2)* B가 선택할 수 있는 볼링공 개수(2:33) +
//A가 3일때(2)* B가 선택할 수 있는 볼링공 개수(0:없음)
  
}