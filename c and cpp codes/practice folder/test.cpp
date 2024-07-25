#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;

int main()
{
    unordered_map<char, vector<char>> graph = {
        {'A', {'B', 'C'}},
        {'B', {'A', 'D', 'E'}},
        {'C', {'A', 'F'}},
        {'D', {'B'}},
        {'E', {'B', 'F'}},
        {'F', {'C', 'E'}}};

    auto dfs = [&](auto& self, char node, unordered_set<char> &visited) -> void
    {
        visited.insert(node);
        // cout << node << " ";

        for (char neighbor : graph[node])
        {
            if (visited.find(neighbor) == visited.end())
            {
                self(self, neighbor, visited);
            }
        }
    };
    auto start = high_resolution_clock::now();
    for (int i = 0; i < 100000; i++)
    {

        unordered_set<char> visited;
        dfs(dfs, 'A', visited);
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    cout << duration.count() << endl;
    return 0;
}
