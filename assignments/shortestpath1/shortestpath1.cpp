#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

const int MAX = 1e4 + 5;
const int oo = 1e9 + 5;

int n, m, q, s;
int u, v, w, e, t;
vector<pair<int, int>> a[MAX];
priority_queue<pair<int, int>> pq;
int dis[MAX];

void answer(){
  pq.push({0, s});
  fill(dis, dis + n, oo);
  dis[s] = 0;
  while((int) pq.size() > 0) {
    auto p = pq.top();
    pq.pop();
    if(abs(p.first) == dis[p.second]) {
      for(auto v : a[p.second]) {
        if(dis[p.second] + v.second < dis[v.first]) {
          dis[v.first] = dis[p.second] + abs(v.second);
          pq.push({-dis[v.first], v.first});
        }
      }
    }
  }
}

void kattis(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  while(cin >> n >> m >> q >> s, n || m || q || s) {
    if(t++) {
      cout << "\n";
    }
    fill(a, a + n, vector<pair<int, int>>());
    for(int i = 0; i < m; i++) {
      cin >> u >> v >> w;
      a[u].push_back({v, w});
    }
    answer();
    for(int i = 0; i < q; i++) {
      cin >> e;
      cout << (dis[e] == oo ? "Impossible" : to_string(dis[e])) << "\n";
    }
  }
}
void test(){
  int a =1;
}

int main(int argc, char* argv[]) {

  if (argc > 1 && strncmp(argv[1], "test", 4) == 0)
    test();

  else
    kattis();

  return 0;
}
