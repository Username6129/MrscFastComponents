#pragma once
#include "Vertex.h"

using namespace std;

struct Edge {

	Vertex endPointX;
	Vertex endPointY;

	Edge();
	Edge(const Vertex& v1, const Vertex& v2);
	string to_string();
	size_t get_hash();
	bool operator == (const Edge& e) const;
	bool operator < (const Edge& e) const;
	struct HashFunction
	{
		std::size_t operator()(const Edge& k) const;
	};
};
