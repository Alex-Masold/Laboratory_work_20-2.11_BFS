#include <iostream> 
#include <vector> 
#include <queue> 


using namespace std;

int main() {
    int M, N;
    cin >> M >> N;

    vector<string> a(M);
    for (int i = 0; i < M; ++i)
        cin >> a[i];

    pair<int, int> start, finish;

    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j) {
            if (a[i][j] == 'S')
                start = { i, j };

            if (a[i][j] == 'F')
                finish = { i, j };
        }


    vector<vector<int>> dist(M, vector<int>(N, -1));
    dist[start.first][start.second] = 0;

    queue<pair<int, int>> q;
    q.push(start);

    vector<pair<int, int>> neighbours = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

    while (!q.empty()) {
        pair<int, int> position = q.front();
        q.pop();

        for (const auto& d : neighbours) {
            int new_i = position.first + d.first;
            int new_j = position.second + d.second;

            if (new_i >= 0 && new_i < M && new_j >= 0 && new_j < N && a[new_i][new_j] != 'X' && dist[new_i][new_j] == -1)
            {
                dist[new_i][new_j] = dist[position.first][position.second] + 1;
                q.push({ new_i, new_j });
            }
        }
    }
    cout << dist[finish.first][finish.second] << endl;
    return 0;
}