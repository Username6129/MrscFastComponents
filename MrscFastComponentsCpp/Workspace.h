#pragma once
#include "Graph.h"
#include <map>
#include <unordered_map>
using namespace std;

typedef pair<double, double> PythonTuple;

struct Workspace {

//private:
	unordered_map<Vertex, Vector2d, Vertex::HashFunction> z;
	map<Vector2d, Vertex> z_inv;

//public:
	Graph graph;
	double grid_length;	

	Workspace(int m, int n, double l);
	Workspace();
	
	void set_mapping(const Vertex& v, const Vector2d& c);
	void set_mapping(const Vector2d& c, const Vertex& v);
	//void set_mapping(const Vector2d& c, const Vertex& );

	Vector2d get_cord(const Vertex& v);
	Vertex get_cord_inv(const Vector2d& c);
	Vertex operator[] (const Vector2d& c);
	Vector2d operator[] (const Vertex& v);

	/*This part is to simplify Python call.*/
	Vertex operator[] (const PythonTuple&);
	void set_mapping(const PythonTuple& c, const Vertex& v);
	void set_mapping(const Vertex& v, const PythonTuple& c);
};