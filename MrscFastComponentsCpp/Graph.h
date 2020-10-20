#pragma once
#include "Edge.h"
#include "Vector2d.h"
#include <set>
#include <unordered_map>

struct Graph
{
	bool exists(Edge& e);
	bool exists(Vertex& v);
	void insert(Edge& e);
	void insert(Vertex& v);
	void insert(Edge&& e);
	void insert(Vertex&& v);
	void remove(Vertex& v);
	void remove(Edge& e);
	set<Vertex> get_dt_successors(const Vertex& v) const;
	set<Vertex> get_dt_predecessors(const Vertex& v) const;
	//set<Edge> get_edges() const;
	//set<Vertex> get_vertices() const;

//private:
	set<Edge> edges;
	set<Vertex> vertices;
	unordered_map<Vertex, set<Vertex>, Vertex::HashFunction> edges_in_map;
	unordered_map<Vertex, set<Vertex>, Vertex::HashFunction> inv_edges_in_map;
	unordered_map<Vertex, set<Edge>, Vertex::HashFunction> left_vertex_incident_edges;
	unordered_map<Vertex, set<Edge>, Vertex::HashFunction> right_vertex_incident_edges;
};