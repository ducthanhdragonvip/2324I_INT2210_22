#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
class Graph {
public:
    Graph(int vertices) : V(vertices), adj(vertices, vector<pair<int, int>>()) {}

    void addEdge(int u, int v, int weight) {
        adj[u].emplace_back(v, weight);
        adj[v].emplace_back(u, weight);
    }

    vector<pair<int, int>> primMST() {
        vector<pair<int, int>> result; // Lưu kết quả

        vector<bool> inMST(V, false);
        vector<int> key(V, INT_MAX);
        vector<int> parent(V, -1);

        // Chọn một đỉnh ngẫu nhiên làm nguồn
        int src = 0;
        key[src] = 0;

        // Tạo hàng đợi ưu tiên để chọn đỉnh có key nhỏ nhất
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, src});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            inMST[u] = true;

            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (!inMST[v] && key[v] > weight) {
                    key[v] = weight;
                    pq.push({key[v], v});
                    parent[v] = u;
                }
            }
        }

        // Lưu kết quả vào vector
        for (int i = 1; i < V; ++i) {
            result.emplace_back(parent[i], i);
        }

        return result;
    }

private:
    int V;
    vector<vector<pair<int, int>>> adj;
};

int main() {
    Graph g(6);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 2, 5);
    g.addEdge(1, 3, 10);
    g.addEdge(2, 3, 3);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 1);
    g.addEdge(3, 5, 8);
    g.addEdge(4, 5, 6);

    vector<pair<int, int>> result = g.primMST();

    cout << "Cac canh trong Rung Bao Trum Nho Nhat:\n";
    for (const auto& edge : result) {
        cout << edge.first << " - " << edge.second << "\n";
    }

    return 0;
}
