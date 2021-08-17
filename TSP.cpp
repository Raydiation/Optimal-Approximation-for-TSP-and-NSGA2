#include<bits/stdc++.h>
#include"SA.cpp"
#include"Brute_Force.cpp"
#include"ACO.cpp"
using namespace std;
class TSP_solution
{
public:
    TSP_solution(vector<vector<int>> graph) :Graph(graph) {}
    vector<int> TSP()
    {
        /*Brute_Force Brute_Force_solver(Graph);
        Brute_Force_solver.Force_solution();
        return Brute_Force_solver.goodOrder;
        int max_round=1000;
        SA SA_solver(Graph,max_round);
        SA_solver.main_algorithm(max_round);
        return SA_solver.goodOrder;*/
        ACO ACOsolver(Graph, 50);
        ACOsolver.init();
        ACOsolver.Round(0);
        return ACOsolver.goodPath;
    }
    vector<vector<int>> Graph;
};
int main()
{
    default_random_engine generator = default_random_engine(time(NULL));
    uniform_int_distribution<int> distribution_int(0, 100);
    auto rand_int = bind(distribution_int, generator);

    const int node_num = 18;
    vector<vector<int>> graph(node_num, vector<int>(node_num));
    for (int i = 0; i < node_num; i++)
    {
        for (int j = 0; j < node_num; j++)
        {
            if (i == j) graph[i][j] = 0;
            else if (i > j)graph[i][j] = graph[j][i];
            else graph[i][j] = rand_int();
        }
    }

    for (int i = 0; i < node_num; i++)
    {
        for (int j = 0; j < node_num; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    TSP_solution solve(graph);
    solve.TSP();
}