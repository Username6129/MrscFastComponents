#pragma once
#include <string>
#include <unordered_set>

using namespace std;

struct Vertex{

	Vertex();
	Vertex(int id);

	bool operator == (const Vertex& v) const;
	void operator = (const Vertex& v);
	bool operator < (const Vertex& v) const;

	int get_id() const;
	string to_string() const;

	std::size_t get_hash();

	struct HashFunction
	{
		std::size_t operator()(const Vertex& k) const;
	};

//private:
	unordered_set<int> used_id;
	int id;
};