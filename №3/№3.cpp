#define _CRT_SECURE_NO_WARNINGS 
#include <iostream> 
#include <vector> 
#include <algorithm>  
#include <cmath> 
using namespace std;

struct City {
	int x, y;
};


struct Edge {
	int city1, city2;
	double distance;
};

double find_distance(const City& city1, const City& city2) {
	return(sqrt(pow(city1.x - city2.x, 2) + pow(city1.y - city2.y, 2)));
}

int parent(const vector<int>& parents, int city) {
	if (parents[city] == city) {
		return city;
	}
	return parent(parents, parents[city]);
}

void kruskal(int n, const vector<City>& cities, const vector<pair<int, int>>& highways) {
	vector <Edge> edges;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			edges.push_back({ i,j,  find_distance(cities[i],cities[j]) });
		}
	}
	sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b)
		{
			return(a.distance < b.distance);
		});
	vector<int> parents(n);

	for (int i = 0; i < n; ++i) parents[i] = i;

	for (const auto& highway : highways) {


		int c1 = highway.first - 1;
		int c2 = highway.second - 1;


		parents[parent(parents, c1)] = parent(parents, c2);
	}

	for (const auto& edge : edges) {

		int c1_parent = parent(parents, edge.city1);
		int c2_parent = parent(parents, edge.city2);

		if (c1_parent != c2_parent) {
			cout << edge.city1 + 1 << " " << edge.city2 + 1 << endl;
			parents[c1_parent] = c2_parent;
		}
	}

}




int main() {
	int N, m;
	cin >> N;
	vector<City> cities(N);
	for (int i = 0; i < N; i++)
	{
		cin >> cities[i].x >> cities[i].y;
	}
	cin >> m;
	vector<pair<int, int>>  highways(m);
	for (int i = 0; i < m; i++) {
		cin >> highways[i].first >> highways[i].second;
	}

	kruskal(N, cities, highways);

}