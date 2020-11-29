// EasyDebug.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Workspace.h"
#include "Algorithms.h"
#include <cmath>
#include <chrono>

int main()
{

    auto g = Graph();
    g.insert(Edge(Vertex(1), Vertex(2)));
    cout << g.is_cycle_exist(Vertex(1)) << endl;
    g.insert(Edge(Vertex(2), Vertex(1)));
    g.insert(Vertex(3));
    cout << g.is_cycle_exist(Vertex(1)) << endl;
    cout << g.is_cycle_exist(Vertex(3)) << endl;
    cout << g.get_edges_end_with(Vertex(1)).size() << endl;
    g.remove(Edge(Vertex(2), Vertex(1)));
    cout << g.get_edges_end_with(Vertex(1)).size() << endl;
    //Workspace w = Workspace(75, 75, 1);
    //set<Vertex> vends;
    //unordered_map<Edge, double, Edge::HashFunction> cost(w.graph.edges.size());

    //for (auto e : w.graph.edges)
    //{
    //    cost[e] = 1;
    //}

    //auto init_direction = Vector2d(0, 1);
    //auto vstart = w[Vector2d(0, 0)];
    //vends.insert(w[Vector2d(74, 74)]);

    //std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    //auto res = get_path_gbrs(w, init_direction, vstart, vends, cost, 1);

    //std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    //for (auto v : res.path) {
    //    cout << w[v.endPointX].to_string() << endl;
    //}
    //cout << w[res.path.back().endPointY].to_string() << endl;

    //std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    //
    //auto g = Graph();
    //auto v1 = Vertex(1);
    //auto v2 = Vertex(2);
    //auto v3 = Vertex(3);

    //g.insert(Edge(v1, v2));
    //for (auto e : g.get_edges_with(v1)) {
    //    cout << e.to_string();
    //};
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
