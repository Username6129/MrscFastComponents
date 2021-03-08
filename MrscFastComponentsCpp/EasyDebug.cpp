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
    Vertex v1 = Vertex(1);
    Vertex v2 = Vertex(2);
    Vertex v3 = Vertex(3);
    Vertex v4 = Vertex(4);
    Edge e1 = Edge(v1, v2); // 1, 2
    Edge e2 = Edge(v2, v3); // 2, 3
    Edge e3 = Edge(v3, v4); // 3, 4
    Edge e4 = Edge(v4, v1); // 4, 1
    
    g.insert(e1);
    g.insert(e2);
    g.insert(e3);
    g.insert(e4);

    auto res = g.get_cycle(v1);

    //Workspace w = Workspace(75, 75, 1);
    //set<Vertex> vends;
    //unordered_map<Edge, double, Edge::HashFunction> cost(w.graph.edges.size());

    //for (auto e : w.graph.edges)
    //{
    //    cost[e] = 1;
    //}

    //auto init_direction = Vector2d(0, 1);
    //auto vstart = w[Vector2d(0, 0)];
    //vends.insert(w[Vector2d(0, 0)]);

    //std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    //auto copy_edges = w.graph.get_edges_end_with(w[Vector2d(74, 74)]);
    //
    //for (const auto& e : copy_edges) {
    //    w.graph.remove(e);
    //}

    //for (const auto& e : copy_edges) {
    //    w.graph.insert(e);
    //}

    //w.graph.insert(w[Vector2d(74, 74)]);
    //auto res = get_path_gbrs(w, init_direction, vstart, vends, cost, 1);

    //std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    //if (res.path.size() > 0) {
    //    for (auto v : res.get_vertex_sequence()) {
    //        cout << v.to_string() << endl;
    //    }
    //    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    //}
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
