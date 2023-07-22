#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <queue> 

using namespace std;

int main() {
    int n, m;

    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<int> distance(n + 1, -1);
    queue<int> q;


    int x, y;
    for (int i = 0; i < m; i++) {

        cin >> x >> y;
        graph[x].push_back(y);
    }

    q.push(1);
    distance[1] = 0;

    while (!q.empty()) {
        int ind = q.front();
        q.pop();

        for (int item : graph[ind])
            if (distance[item] == -1) {
                distance[item] = distance[ind] + 1;
                q.push(item);
            }
    }

    for (int i = 1; i <= n; i++)
        printf("%d\n", distance[i]);
}