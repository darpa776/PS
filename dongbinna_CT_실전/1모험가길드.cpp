#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  cin>>n;

  vector <int> fear;
  for(int i=0;i<n;i++)
  {
    int x;
    cin>>x;
    fear.push_back(x);
  }

  sort(fear.begin(),fear.end());//오름차순 정렬

  
  int team=0;//팀 수
  int i=0;
  while(1)
  {
    i+=fear[i];
    if(i<n)
    { 
      team++;
    }
    else
      break;
  }

  cout<<team;
}