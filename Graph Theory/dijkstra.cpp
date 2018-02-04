# include<bits/stdc++.h>
using namespace std;

# define V 9


void shortest_distance(int distance[], bool spt_set[]) {
	int min = INT_MAX, min_index;
	for(int i = 0; i < V; i++) {
		if(!spt_set[i] && distance[i] <= min) {
			min = distance[i];
			min_index = i;
		}
	}
	return min_index;
}


void dijkstra(int graph[V][V], int source) {
	int distance[V];
	bool spt_set[V];

	for(int i = 0; i < V; i++) {
		distance[i] = INT_MAX;
		spt_set[i] = false;
	}

	distance[source] = 0;

	for(int i = 0; i < V-1; i++) {
		int v = shortest_distance(distance, spt_set);
		spt_set[v] = true;
		for(int j = 0; j < V; j++) {
			if(!spt_set[j] && graph[v][j] && distance[v] != INT_MAX && distance[v]+graph[v][j] < distance[j])
				distance[j] = distance[v] + graph[v][j];
		}
	}
}

int main() {
	int graph[V][V] = {
		{0, 4, 0, 0, 0, 0, 0, 8, 0},
		{4, 0, 8, 0, 0, 0, 0, 11, 0},
		{0, 8, 0, 7, 0, 4, 0, 0, 2},
		{0, 0, 7, 0, 9, 14, 0, 0, 0},
		{0, 0, 0, 9, 0, 10, 0, 0, 0},
		{0, 0, 4, 14, 10, 0, 2, 0, 0},
		{0, 0, 0, 0, 0, 2, 0, 1, 6},
		{8, 11, 0, 0, 0, 0, 1, 0, 7},
		{0, 0, 2, 0, 0, 0, 6, 7, 0}
	};

	dijkstra(graph, 0);

	return 0;
}
