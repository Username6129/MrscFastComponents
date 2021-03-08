#include "Graph.h"
#include <queue>
bool Graph::exists(const Edge& e)
{
	return this->edges.find(e) != this->edges.end();
}

bool Graph::exists(const Vertex& v)
{
	return this->vertices.find(v) != this->vertices.end();
}

void Graph::insert(const Edge& e)
{
	this->edges.insert(e);
	this->vertices.insert(e.endPointX);
	this->vertices.insert(e.endPointY);

	this->edges_in_map[e.endPointX].insert(e.endPointY);
	this->inv_edges_in_map[e.endPointY].insert(e.endPointX);
	this->edges_start_with[e.endPointX].insert(e);
	this->edges_end_with[e.endPointY].insert(e);
}

void Graph::insert(Edge&& e)
{
	this->edges.insert(e);
	this->vertices.insert(e.endPointX);
	this->vertices.insert(e.endPointY);

	this->edges_in_map[e.endPointX].insert(e.endPointY);
	this->inv_edges_in_map[e.endPointY].insert(e.endPointX);
	this->edges_start_with[e.endPointX].insert(e);
	this->edges_end_with[e.endPointY].insert(e);
}

void Graph::insert(const Vertex& v)
{
	this->vertices.insert(v);
}

void Graph::insert(Vertex&& v)
{
	this->vertices.insert(v);
}

void Graph::remove(Vertex&& v)
{
	for (auto e : this->get_edges_end_with(v))
	{
		this->remove(e);
	}

	for (auto e : this->get_edges_start_with(v)) {
		this->remove(e);
	}

	this->vertices.erase(v);
}

void Graph::remove(const Vertex& v)
{
	for (auto e : this->get_edges_end_with(v))
	{
		this->remove(e);
	}

	for (auto e : this->get_edges_start_with(v)) {
		this->remove(e);
	}

	this->vertices.erase(v);
}

void Graph::remove(const Edge& e)
{
	auto it = this->edges_in_map.find(e.endPointX);

	if (it != this->edges_in_map.end())
		(*it).second.erase(e.endPointY);

	it = this->inv_edges_in_map.find(e.endPointY);

	if (it != this->inv_edges_in_map.end())
		(*it).second.erase(e.endPointX);

	this->edges.erase(e);
	this->edges_start_with[e.endPointX].erase(e);
	this->edges_end_with[e.endPointY].erase(e);
}

void Graph::remove(Edge&& e)
{
	auto it = this->edges_in_map.find(e.endPointX);

	if (it != this->edges_in_map.end())
		(*it).second.erase(e.endPointY);

	it = this->inv_edges_in_map.find(e.endPointY);

	if (it != this->inv_edges_in_map.end())
		(*it).second.erase(e.endPointX);

	this->edges.erase(e);
	this->edges_start_with[e.endPointX].erase(e);
	this->edges_end_with[e.endPointY].erase(e);
}

set<Vertex> Graph::get_dt_successors(const Vertex& v) const
{
	auto it = this->edges_in_map.find(v);

	if (it == this->edges_in_map.end())
		return set<Vertex>();
	else
		return (*it).second;
}

set<Vertex> Graph::get_dt_predecessors(const Vertex& v) const 
{

	auto it = this->inv_edges_in_map.find(v);

	if (it == this->inv_edges_in_map.end())
		return set<Vertex>();
	else
		return (*it).second;
}

set<Edge> Graph::get_edges_with(const Vertex& v) const
{
	set<Edge> res;
	if (edges_in_map.find(v) != edges_in_map.end()) {
		for (auto& v1 : edges_in_map.find(v)->second) {
			res.insert(Edge(v, v1));
		}
	}

	if (inv_edges_in_map.find(v) != inv_edges_in_map.end()) {
		for (auto& v1 : inv_edges_in_map.find(v)->second) {
			res.insert(Edge(v1, v));
		}
	}

	return res;
}

set<Edge> Graph::get_edges_start_with(const Vertex& v) const
{
	auto it = this->edges_start_with.find(v);
	if (it != this->edges_start_with.end()) {
		return it->second;
	}
	return set<Edge>();
}

set<Edge> Graph::get_edges_end_with(const Vertex& v) const
{
	auto it = this->edges_end_with.find(v);
	if (it != this->edges_end_with.end()) {
		return it->second;
	}
	return set<Edge>();
}

bool Graph::is_cycle_exist(const Vertex& root) const
{
	unordered_set<int> closed;
	queue<Vertex> queue;
	queue.push(root);
	closed.insert(root.id);

	while (!queue.empty()) {
		auto& v = queue.front();
		queue.pop();
		for (auto& v1: this->get_dt_successors(v)) {
			if (closed.find(v1.id) != closed.end()) {
				return true;
			}
			closed.insert(v.id);
			queue.push(v1);
		}
	}

	return false;
}

//vector<Vertex> Graph::get_cycle(const Vertex& v) const {
//}
//
//vector<Vertex> Graph::_get_cycle_helper(const Vertex& cur, const Vertex& t) const
//{
//	if (cur == t) { 
//		auto res = vector<Vertex>();
//		res.push_back(t);
//		return res;
//	}
//
//	vector<Vertex> tmp;
//	vector<Vertex> tmp2;
//
//	for (auto& e : this->get_edges_start_with(cur)) {
//		tmp = this->_get_cycle_helper(e.endPointY, t);
//		if (tmp.size() > 0 && tmp.size() <= tmp2.size()) {
//			tmp2 = tmp;
//		}
//	}
//
//	vector<Vertex> res;
//
//	if (tmp2.size() > 0) {
//		res.push_back(cur);
//		res.insert(res.end(), tmp2.begin(), tmp2.end());
//		return res;
//	}
//
//	return res;
//}

int Graph::get_cycle_length(const Vertex& root) const
{
	unordered_map<Vertex, int, Vertex::HashFunction> depth;
	unordered_set<int> closed;
	queue<Vertex> queue;
	
	depth[root] = 0;
	queue.push(root);
	closed.insert(root.id);

	while (!queue.empty()) {
		auto& v = queue.front();
		queue.pop();
		for (auto& v1 : this->get_dt_successors(v)) {
			depth[v1] = depth[v] + 1;
			if (closed.find(v1.id) != closed.end()) {
				return depth[v1];
			}
			closed.insert(v.id);
			queue.push(v1);
		}
	}

	return 0;
}

vector<Edge> Graph::get_cycle(const Vertex& root) const
{
	unordered_map<Vertex, Vertex, Vertex::HashFunction> parent;
	unordered_set<int> closed;
	queue<Vertex> queue;
	vector<Edge> res;

	auto special_node = Vertex(-1);
	parent[root] = special_node;
	queue.push(root);
	closed.insert(root.id);

	while (!queue.empty()) {
		auto v = queue.front();
		queue.pop();
		for (auto& v1 : this->get_dt_successors(v)) {
			if (closed.find(v1.id) != closed.end()) {
				res.push_back(Edge(v, v1));
				auto& vn = parent[v];
				Vertex tmp = v;
				while (!(vn == special_node)) {
					res.push_back(Edge(vn, tmp));
					tmp = vn;
					vn = parent[vn];
				}
				reverse(res.begin(), res.end());
				return res;
			}
			parent[v1] = v;
			closed.insert(v.id);
			queue.push(v1);
		}
	}

	return res;
}

int Graph::get_in_degree(const Vertex& v) const
{
	if (this->inv_edges_in_map.find(v) == this->inv_edges_in_map.end()) {
		return 0;
	}
	return this->inv_edges_in_map.find(v)->second.size();
}

int Graph::get_out_degree(const Vertex& v) const
{
	if (this->edges_in_map.find(v) == this->edges_in_map.end()) {
		return 0;
	}
	return this->edges_in_map.find(v)->second.size();
}

set<Edge> Graph::get_edges()
{
	set<Edge> es;
	for (auto& e : edges) {
		es.insert(e);
	}
	return es;
}

set<Vertex> Graph::get_vertices()
{
	set<Vertex> vs;
	for (auto& v : vertices) {
		vs.insert(v);
	}
	return vs;
}

//set<Edge> Graph::get_edges() const 
//{
//	return this->edges;
//}
//
//set<Vertex> Graph::get_vertices() const 
//{
//	return this->vertices;
//}
