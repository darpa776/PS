#include <iostream>
#include <string>
using namespace std;

int main()
{
  int n;
  cin>>n;
  cin.ignore();

  int x=1,y=1;
  char list[4]={'L','R','U','D'};
  int dx[4]={-1,1,0,0};
  int dy[4]={0,0,-1,1};

  string plans;
  getline(cin, plans);
  for(int i=0;i<plans.size();i++)
  {
    for(int j=0;j<4;j++)
    {
      if(plans[i]==list[j])
      {
        if((x+dx[j]<1)||(x+dx[j]>n)||(y+dy[j]<1)||(y+dy[j]>n))
        break;
        else
        {
          x+=dx[j];
          y+=dy[j];
        }
      }
    }
  }
  cout<<y<<" "<<x<<endl;
  return 0;
}