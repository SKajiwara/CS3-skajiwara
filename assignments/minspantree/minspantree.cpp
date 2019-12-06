#include <iostream>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <string>
#include "class.h"
using namespace std;
using iPair = pair<int, int>;

int KruskalMST(Graph& graph, vector<iPair> & MST)
{
  std::ios::sync_with_stdio(false);
  if (graph.E == 0)
      return 0;

  int numMST = graph.V;  // initially V disjoint classes
  ParPtrTree unionfind(graph.V);
  int weight = 0;

  while (numMST > 1 && !graph.edges.empty())
  {
      // pick the smallest edge
      Edge edge = graph.edges.top();
      graph.edges.pop();
      int x = unionfind.FIND(edge.src); // root of src
      int y = unionfind.FIND(edge.dest); // root of dest
      // if src and dest nodes are in different sets
      if (x != y)
      {
          int u = edge.src;
          int v = edge.dest;
          // add weight
          weight += edge.weight;
          // the ordering is not required, but...
          if (u > v) swap(u, v);
          // add u->v edge to MST
          MST.push_back({u, v});
          // combine equiv classes
          unionfind.UNION(u, v);
          numMST--; // one less MST
      }
  }
  return weight;
}

vector<string> answer(Graph& graph){
  vector<string> ans;
  vector<iPair> MST;
  ans.push_back( to_string(KruskalMST(graph, MST)));
  sort(MST.begin(), MST.end());
  for(auto &p:MST)
    ans.push_back( to_string(p.first) + ' ' + to_string(p.second));
  return ans;
}

void test() {
  Graph test1( 5, 5 ), test2( 3, 5 ), test3( 4, 4 );
  test1.addEdge(0,1,4); test1.addEdge(1,3,4); test1.addEdge(1,2,4);
  test1.addEdge(2,3,4); test1.addEdge(3,4,4);
  vector<string> assert{ "16", "0 1",  "1 3", "2 3", "3 4"};
  assert( answer(test1) == assert );

}

void kattis() {
  int n, m, u, v, w, wt;
  while( cin >> n >> m && n>0 ) {
    Graph graph(n, m);
    for ( int i = 0; i < m && cin >> u >> v >> w; i++ )
      graph.addEdge(u, v, w);
    if ( m != 0 ) {
      vector<string> ans = answer(graph);
      for (auto i = ans.begin(); i != ans.end(); ++i) cout << *i << endl;
    }
  }
  cout << "Impossible" << endl;
}

int main( int argc, char* argv[] ) {

  if( argc > 1 && strncmp(argv[1], "test", 4) == 0 )
    test();

  else
    kattis();

  return 0;
}
//cat minspantree.in | ./a.out | diff - minspantree.ans
