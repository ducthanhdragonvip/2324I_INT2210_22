#include <iostream>
#include <vector>
#include <algorithm>

class Graph {
public:
    Graph(int vertices) : V(vertices) {}

    void addEdge(int u, int v, int weight) {
        edges.push_back({u, v, weight});
    }

    int findParent(std::vector<int>& parent, int i) {
        if (parent[i] == -1) {
            return i;
        }
        return findParent(parent, parent[i]);
    }

    void unionSets(std::vector<int>& parent, int x, int y) {
        int xset = findParent(parent, x);
        int yset = findParent(parent, y);
        parent[xset] = yset;
    }

    std::vector<std::pair<int, int>> kruskalMST() {
        std::vector<std::pair<int, int>> result; // Lưu kết quả

        // Sắp xếp các cạnh theo trọng số tăng dần
        std::sort(edges.begin(), edges.end(), [](const auto& a, const auto& b) {
            return a.weight < b.weight;
        });

        std::vector<int> parent(V, -1);

        for (const auto& edge : edges) {
            int x = findParent(parent, edge.src);
            int y = findParent(parent, edge.dest);

            // Nếu thêm cạnh này không tạo chu trình, thêm vào kết quả
            if (x != y) {
                result.emplace_back(edge.src, edge.dest);
                unionSets(parent, x, y);
            } else {
                // Nếu tạo chu trình, loại bỏ cạnh có trọng số lớn nhất trong chu trình
                result.pop_back();
                result.emplace_back(edge.src, edge.dest);
            }
        }

        return result;
    }

private:
    struct Edge {
        int src, dest, weight;
    };

    int V;
    std::vector<Edge> edges;
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

    std::vector<std::pair<int, int>> result = g.kruskalMST();

    std::cout << "Cac canh trong Cau Bao Trum Nho Nhat:\n";
    for (const auto& edge : result) {
        std::cout << edge.first << " - " << edge.second << "\n";
    }

    return 0;
}
