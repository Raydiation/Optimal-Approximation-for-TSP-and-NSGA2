#include<bits/stdc++.h>
#include"GA.cpp"
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
        return Brute_Force_solver.goodOrder;*/
        int max_round=5000;
        SA SA_solver(Graph,max_round);
        SA_solver.main_algorithm(max_round);

        //return SA_solver.goodOrder;
        ACO ACO_solver(Graph, 20);
        ACO_solver.init();
        ACO_solver.Round(0);

        //return ACOsolver.goodPath;
        GA GA_solver(Graph,20);
        GA_solver.Init();
        GA_solver.update_candidate(0);
        cout<<"SA result : "<<SA_solver.goodOrderScore<<"\n";
        for(int num:SA_solver.goodOrder)
            cout<<num<<" ";
        cout<<endl;
        cout<<"ACO result : "<<ACO_solver.goodPathLength<<"\n";
        for(int num:ACO_solver.goodPath)
            cout<<num<<" ";
        cout<<endl;
        cout<<"GA result : "<<GA_solver.route_length(GA_solver.candidate_route[0].first)<<"\n";
        for(int num:GA_solver.candidate_route[0].first)
            cout<<num<<" ";
        cout<<endl;
        return GA_solver.candidate_route[0].first;
    }
    vector<vector<int>> Graph;
};
int main()
{
    const int node_num = 10;

    default_random_engine generator = default_random_engine(time(NULL));
    uniform_int_distribution<int> distribution_int(0,2*node_num-1);
    auto rand_int=bind(distribution_int,generator);

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
