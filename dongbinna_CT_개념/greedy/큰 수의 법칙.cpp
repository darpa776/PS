#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  //2<=n<=1000
  //1<=m<=10000//총 몇번 더해라
  //1<=k<=10000//반복해서 몇 번 더해라
  int n,m,k;
  cin>>n>>m>>k;

  int ans=0;
  //vector<int> list;
  vector<int> list;

  for(int i=0;i<n;i++)
  { 
    //****//
    int x;//입력변수
    cin>>x;
    list.push_back(x);
  }

  sort(list.begin(),list.end());
  //오름차순 정렬
  int max1=list[n-1];
  int max2=list[n-2];

  int count=0;//몇 번 더했는지 세아릴 변수
  int same_number_count=0;//같은 숫자를 몇 번 더했는지 세아릴 변수

  while(1)
  {
    if(count>=m)
    break;

    if(same_number_count<k)
    {
      ans+=max1;
      same_number_count++;
      count++;
    }
    else
    {
      ans+=max2;
      same_number_count=0;
      count++;
    }
  }
  cout<<ans<<endl;
  return 0;
}
