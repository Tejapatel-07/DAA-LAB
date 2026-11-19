#include <iostream>
using namespace std;

#define V 4
#define INF 99999

int graph[V][V] = {
    {0,  10, 15, 20},
    {10, 0,  35, 25},
    {15, 35, 0,  30},
    {20, 25, 30, 0}
};

int visited[V];
int minCost = INF;

void tsp(int city, int count, int cost)
{
    // If all cities are visited
    if (count == V)
    {
        if (graph[city][0] != 0)
        {
            int totalCost = cost + graph[city][0];

            if (totalCost < minCost)
                minCost = totalCost;
        }
        return;
    }

    // Visit unvisited cities
    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && graph[city][i] != 0)
        {
            visited[i] = 1;

            tsp(i, count + 1,
                cost + graph[city][i]);

            visited[i] = 0;
        }
    }
}

int main()
{
    // Start from city 0
    visited[0] = 1;

    tsp(0, 1, 0);

    cout << "Minimum travelling cost = "
         << minCost << endl;

    return 0;
}
