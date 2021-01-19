#include <iostream>
using namespace std;

bool check(int h, int m, int s)
{
  if(h%10==3||h/10==3||m%10==3||m/10==3||s%10==3||s/10==3)
    return true;
  else
    return false;
}
int main()
{
  int time;
  cin>>time;

  int count=0;
  for(int h=0;h<=time;++h)
  {
    for(int m=0;m<60;++m)
    {
      for(int s=0;s<60;s++)
      {
        if(check(h,m,s))
        {
          count+=1;
        }

      }
    }
  }
  cout<<count<<endl;
  return 0;
}