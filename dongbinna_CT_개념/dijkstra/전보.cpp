#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

vector<pair<int,int>> graph[30001];
int d[30001];
priority_queue<pair<int,int>> q;
int n,m,c;//도시, 통로, start
int x,y,z;//출발도시, 도착도시, time

int dijkstra(int c)
{
  d[c]=0;
  //첫번째 도시 넣어
  q.push({0,c});
  // for(int i=0;i<;i++)
  //   q.push(make_pair(graph[c][i].second,graph[c][i].first));
  //                               //거리              도시
  while(!q.empty())
  {
    //pq 정렬을 정하는 것은 첫번째 원소(?)
    int dist =-q.top().first;
    int now = q.top().second;
    q.pop();
    //이미 방문한 곳이면 continue;
    if(d[now]<dist) continue;
    //주변 노드들을 탐색하면서 d에 넣기
    for(int i=0;i<graph[now].size();i++)
    {
      if(d[graph[now][i].first]>d[now]+graph[now][i].second)
      {  
        d[graph[now][i].first]=d[now]+graph[now][i].second;
        q.push({-(d[graph[now][i].first]),graph[now][i].first});
      }
    }
  }
  return 0;
}

int main()
{
  cin>>n>>m>>c;

//graph 입력받기(m개 branch)
for(int i=0;i<m;i++)
{ 
  cin>>x>>y>>z;
  graph[x].push_back(make_pair(y,z));
}

//d 초기화
fill_n(d,30001,INF);

dijkstra(c);

//정답 출력
int count=0;
int max=0;
for(int i=0;i<n;i++)
{
  if(d[i]<INF)
  {
    count++;
    if(d[i]>max)
       max=d[i];
    //max=max(max,d[i]);
  }
}
cout<<count<<" "<<max<<endl;
  return 0;
}