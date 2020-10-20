#include "Vertex.h"
#include "Vector2d.h"
#include "Workspace.h"
#include <set>
#include <vector>
#include <map>
#include <algorithm>

typedef vector<Edge> Path;

struct PathNodeNaive {
	PathNodeNaive* prev_node;
	double total_cost;
	Edge edge;
	PathNodeNaive();
	PathNodeNaive(const Vertex& v, PathNodeNaive* prev_node, double total_cost);
	bool operator < (const PathNodeNaive& p);
};

struct CmpPathNodeNaivePtr {
	bool operator()(const PathNodeNaive* lhs, const PathNodeNaive* rhs) const;
};

Path extract_path(const PathNodeNaive& path_node);

Path get_path_GBRS_naive(
	Workspace& workspace,
	Vector2d& direction,
	Vertex& vstart,
	set<Vertex>& vends,
	unordered_map<Edge, double, Edge::HashFunction>& w,
	double rotate_penalty
);