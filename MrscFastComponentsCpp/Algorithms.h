#pragma once
#include "Vertex.h"
#include "Vector2d.h"
#include "Workspace.h"
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <deque>

typedef vector<Edge> Path;

struct PathInfo {
	PathInfo() : cost(0) {}
	Path path;
	double cost;

	vector<Vertex> get_vertex_sequence();
};

struct PathNodeNaive {
	PathNodeNaive* prev_node;
	double total_cost;
	Edge edge;
	bool operator < (const PathNodeNaive& p);
};

struct CmpPathNodeNaivePtr {
	bool operator()(const PathNodeNaive* lhs, const PathNodeNaive* rhs) const;
};

PathInfo extract_path(const PathNodeNaive& path_node);

PathInfo get_path_gbrs(
	Workspace& workspace,
	Vector2d& direction,
	Vertex& start,
	set<Vertex>& ends,
	unordered_map<Edge, double, Edge::HashFunction>& w,
	double rotate_penalty
);

PathInfo get_path_gbrs(
	Workspace& workspace,
	Vector2d& direction,
	Vertex& start,
	set<Edge>& ends,
	unordered_map<Edge, double, Edge::HashFunction>& w,
	double rotate_penalty
);