#pragma once
#include "Edge.h"
#include "Vector2d.h"
#include <set>
#include <unordered_map>
#include <vector>

struct Graph
{
	bool exists(const Edge& e);
	bool exists(const Vertex& v);
	void insert(const Edge& e);
	void insert(const Vertex& v);
	void insert(Edge&& e);
	void insert(Vertex&& v);
	void remove(Vertex&& v);
	void remove(const Vertex& v);
	void remove(const Edge& e);
	void remove(Edge&& e);
	set<Vertex> get_dt_successors(const Vertex& v) const;
	set<Vertex> get_dt_predecessors(const Vertex& v) const;
	set<Edge> get_edges_with(const Vertex& v) const;
	set<Edge> get_edges_start_with(const Vertex& v) const;
	set<Edge> get_edges_end_with(const Vertex& v) const;
	vector<Edge> get_cycle(const Vertex& root) const;
	bool is_cycle_exist(const Vertex& root) const;
	int get_cycle_length(const Vertex& root) const;
	int get_in_degree(const Vertex& v) const;
	int get_out_degree(const Vertex& v) const;
	set<Edge> get_edges();
	set<Vertex> get_vertices();
	//set<Edge> get_edges() const;
	//set<Vertex> get_vertices() const;

//private:
	set<Edge> edges;
	set<Vertex> vertices;
	unordered_map<Vertex, set<Vertex>, Vertex::HashFunction> edges_in_map;
	unordered_map<Vertex, set<Vertex>, Vertex::HashFunction> inv_edges_in_map;
	unordered_map<Vertex, set<Edge>, Vertex::HashFunction> edges_start_with;
	unordered_map<Vertex, set<Edge>, Vertex::HashFunction> edges_end_with;
};