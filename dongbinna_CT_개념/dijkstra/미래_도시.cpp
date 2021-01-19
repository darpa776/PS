#include <iostream>
#define INF 1e9
using namespace std;
//반드시 거쳐가야할 경로를 제시하므로
//플로이드 워셜 알고리즘
int main()
{
  int n,m,k,x;
  cin>>n>>m;
  //회사 개수 n, 경로 개수 m

  //graph
  int graph[101][101];
  //2차원 배열 초기화
   // 최단 거리 테이블을 모두 무한으로 초기화
    for (int i = 0; i < 101; i++) {
        fill_n(graph[i], 101, INF);
    }
  
  //자기자신에게는 못가요
  for(int i=0;i<n;i++)
  {
    graph[i][i]=0;
  }
  for(int i=0;i<m;i++)
  { 
    int a,b;
    cin>>a>>b;
    graph[a][b]=1;
    graph[b][a]=1;
  }
 //소개팅장소k, 도착할 회사x
  cin>> x>> k;
  //1->k->x
  //방문판매원은 항상 1번 회사에 위치해있다.
  //전처리
    for (int k = 1; k <= n; k++) {
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
            }
        }
    }

  int distance= graph[1][k]+graph[k][x];
  if(distance>=INF)//INF에 거리가 더 더해져 있을 수 있음
  cout<<"unavilable"<<endl;
  else
  cout<<distance;
 
  return 0;
}