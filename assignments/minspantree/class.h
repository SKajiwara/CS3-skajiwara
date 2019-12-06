#include <vector>
#include <queue>
using namespace std;

class ParPtrTree {
  private:
    vector<int> parents; // parent pointer vector
    vector<int> weights; // weights for weighted union
  public:
    // constructor
    ParPtrTree(size_t size) {
        parents.resize(size); //create parents vector
        fill(parents.begin(), parents.end(), -1); // each node is its own root to start
        weights.resize(size);
        fill(weights.begin(), weights.end(), 1);// set all base weights to 1
    }

    // Return the root of a given node with path compression
    // recursive algorithm that makes all ancestors of the current node
    // point to the root
    int FIND(int node) {
        if (parents[node] == -1) return node;
        parents[node] = FIND(parents[node]);
        return parents[node];
    }

    // Merge two subtrees if they are different
    void UNION(int node1, int node2) {
        int root1 = FIND(node1);
        int root2 = FIND(node2);
        // MERGE two trees
        if (root1 != root2) {
            if (weights[root1] < weights[root2]) {
                parents[root1] = root2;
                weights[root2] += weights[root1];
            }
            else {
                parents[root2] = root1;
                weights[root1] += weights[root2];
            }
        }
    }

    string toString() {
        string nodes = "nodes:\t";
        string prts = "parents:\t";
        for (int i=0; i < this->parents.size(); i++) {
            prts += to_string(this->parents[i]) + '\t';
            nodes += " \t " + to_string(i);
        }
        return prts + "\n" + nodes;
    }
};
struct Edge
{
    int src, dest, weight;
    // for min priority queue
     bool operator<(const Edge &other) const {
        return this->weight > other.weight;
    }
};
struct Graph
{
    // V -> Number of vertices, E -> Number of edges
    int V, E;
    // graph is stored in a min heap priority_queue
    // Kruskal algo requires working with edges with smallest to highest weight
    priority_queue<Edge, vector<Edge> > edges;
    // constructor
    Graph(int v, int e) {
        V = v;
        E = e;
    }
    void addEdge(int u, int v, int w) {
        edges.push({u, v, w});
    }
};
