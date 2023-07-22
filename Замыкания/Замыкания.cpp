#include <iostream>
#include <iomanip>
using namespace std;

// Number of vertices in the graph
#define N 5

// Function to print the transitive closure of a graph
void runWarshallAlgorithm(bool graph[N][N])
{
	// `cost[][]` stores transitive closure of the graph
	bool cost[N][N];

	// initialize `cost[][]` matrix
	for (int v = 0; v < N; v++)
	{
		for (int u = 0; u < N; u++)
		{
			// initially, the cost would be the same as the edge weight
			cost[v][u] = graph[v][u];
		}
	}

	// run Warshall algorithm
	for (int k = 0; k < N; k++)
	{
		for (int v = 0; v < N; v++)
		{
			for (int u = 0; u < N; u++)
			{
				// if vertex `k` is on the shortest path from `v` to `u`,
				// then update the value of `cost[v][u]`
				if (!cost[v][u]) {
					cost[v][u] = (cost[v][k] && cost[k][u]);
				}
			}
		}
	}

	// print the transitive closure of a graph
	for (int v = 0; v < N; v++)
	{
		for (int u = 0; u < N; u++) {
			cout << setw(3) << cost[v][u];
		}
		cout << endl;
	}
}

int main()
{
	bool graph[N][N] =
	{
		{ 0, 0, 0, 1, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 1 },
		{ 0, 0, 0, 0, 1 },
		{ 0, 1, 1, 1, 0 }
	};

	runWarshallAlgorithm(graph);

	return 0;
}