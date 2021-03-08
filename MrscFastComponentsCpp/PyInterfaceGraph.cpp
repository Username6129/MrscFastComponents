#include "PyInterfaceGraph.h"
#include "pybind11/stl_bind.h"
#include <set>


void bindGraph(py::module& m) {

    py::class_<Graph>(m, "Graph", R"delimiter(

        Directed graph with edges and vertices.

        :var vertices: A readonly-set of vertices.
        :var edges: A readonly-set of edges.

    )delimiter")
        .def(py::init<>())
        .def("insert", py::overload_cast<const Edge&>(&Graph::insert),
            R"delimiter(
            This function receives Vertex or Edge as input. The provided input will be added to the corresponding set.
            
            :param item: An instance of Vertex or Edge.
            :type item: Union[Edge, Vertex]

            :Example:
            
            >>> v1 = Vertex(1)
            >>> v2 = Vertex(2)
            >>> v3 = Vertex(3)
            >>> e = Edge(v1, v2)

            >>> g = Graph()
            >>> g.insert(v3)
            >>> g.vertices
            {<Vertex: 3>}

            >>> g.insert(e)
            >>> v1 in g.vertices and v2 in g.vertices and v3 in g.vertices
            True

            >>> g.edges
            {<Edge: 1, 2>}

        )delimiter", "item"_a)

        .def("insert", py::overload_cast<const Vertex&>(&Graph::insert))
        .def("remove", py::overload_cast<const Edge&>(&Graph::remove),
            R"delimiter(
            This function receives Vertex or Edge as input. The provided input will be removed from the corresponding set.
            Please note that removing a vertex will also remove the edges containing the vertex.
            However, removing an edge does not delete the vertices of the edge.
            
            :param item: An instance of Vertex or Edge.
            :type item: Union[Edge, Vertex]

            :Example:
            
            >>> v1 = Vertex(1)
            >>> v2 = Vertex(2)
            >>> v3 = Vertex(3)
            >>> e = Edge(v1, v2)

            >>> g = Graph()
            >>> g.insert(v3)
            >>> g.insert(e)
            >>> v1 in g.vertices and v2 in g.vertices and v3 in g.vertices and e in g.edges
            True

            >>> g.remove(e)
            >>> e not in g.edges and e.endPointX in g.vertices and e.endPointY in g.vertices 
            True

            >>> g.remove(v3)
            >>> v3 in g.vertices
            False

            >>> g.edges
            set()

        )delimiter", "item"_a)

        .def("remove", py::overload_cast<const Vertex&>(&Graph::remove))
        .def("exists", py::overload_cast<const Edge&>(&Graph::exists),
            R"delimiter(
            This function receives Vertex or Edge as input. 
            Check if a given input in the graph instance.
            
            :param item: An instance of Vertex or Edge.
            :type item: Union[Edge, Vertex]
            :return: true if the provided input in the graph instance, false otherwise.
            :rtype: bool

            :Example:
            
            >>> from mrscfastcom.workspace import *
            >>> v1 = Vertex(1)
            >>> v2 = Vertex(2)
            >>> v3 = Vertex(3)
            >>> e = Edge(v1, v2)

            >>> g = Graph()
            >>> g.insert(v1)
            >>> g.exists(v1)
            True

            >>> g.exists(v2)
            False

            >>> g.insert(e)
            >>> g.exists(e)
            True
            
            >>> e2 = Edge(v2, v1)
            >>> g.exists(e2)
            False

        )delimiter")

        .def("exists", py::overload_cast<const Vertex&>(&Graph::exists))
        .def_property_readonly("vertices", &Graph::get_vertices)
        .def_property_readonly("edges", &Graph::get_edges)
        .def("get_dt_predecessors", &Graph::get_dt_predecessors, R"delimiter(
            This function is to get the direct predecessors of the input vertex.
            
            :param v: An instance of Vertex.
            :type v: Union[Edge, Vertex]
            :return: A set of predecessors.
            :rtype: Set[Vertex]

            :Example:
            
            >>> v1 = Vertex(1)
            >>> v2 = Vertex(2)
            >>> v3 = Vertex(3)
            >>> e1 = Edge(v1, v2)
            >>> e2 = Edge(v1, v3)
            >>> e3 = Edge(v3, v2)

            >>> g = Graph()
            >>> g.insert(e1)
            >>> g.insert(e2)
            >>> g.insert(e3)

            >>> g.get_dt_predecessors(v1)
            set()
            
            >>> {v1, v3} == g.get_dt_predecessors(v2)
            True

            >>> g.get_dt_predecessors(v3)
            {<Vertex: 1>}

        )delimiter")

        .def("get_edges_start_with", &Graph::get_edges_start_with, R"delimiter(

            This function return all the edges start with vertex v.
            
            :param v: An instance of Vertex.
            :type v: Vertex
            :return: A set of edges that start with vertex v.
            :rtype: Set[Vertex]

            :Example:
            
            >>> v1 = Vertex(1)
            >>> v2 = Vertex(2)
            >>> v3 = Vertex(3)
            >>> e1 = Edge(v1, v2)
            >>> e2 = Edge(v1, v3)
            >>> e3 = Edge(v3, v2)

            >>> g = Graph()
            >>> g.insert(e1)
            >>> g.insert(e2)
            >>> g.insert(e3)

            >>> {e3} == g.get_edges_start_with(v3)
            True

        )delimiter")

        .def("get_edges_end_with", &Graph::get_edges_end_with, R"delimiter(

            This function return all the edges end with vertex v.
            
            :param v: An instance of Vertex.
            :type v: Vertex
            :return: A set of edges that end with vertex v.
            :rtype: Set[Vertex]

            :Example:
            
            >>> v1 = Vertex(1)
            >>> v2 = Vertex(2)
            >>> v3 = Vertex(3)
            >>> e1 = Edge(v1, v2)
            >>> e2 = Edge(v1, v3)
            >>> e3 = Edge(v3, v2)

            >>> g = Graph()
            >>> g.insert(e1)
            >>> g.insert(e2)
            >>> g.insert(e3)

            >>> {e2} == g.get_edges_end_with(v3)
            True

        )delimiter")

        .def("get_edges_with", &Graph::get_edges_with, R"delimiter(

            This function return all the edges that contain vertex v.
            
            :param v: An instance of Vertex.
            :type v: Vertex
            :return: A set of edges that contain vertex v.
            :rtype: Set[Vertex]

            :Example:
            
            >>> v1 = Vertex(1)
            >>> v2 = Vertex(2)
            >>> v3 = Vertex(3)
            >>> e1 = Edge(v1, v2)
            >>> e2 = Edge(v1, v3)
            >>> e3 = Edge(v3, v2)

            >>> g = Graph()
            >>> g.insert(e1)
            >>> g.insert(e2)
            >>> g.insert(e3)

            >>> {e1, e3} == g.get_edges_with(v2)
            True

            >>> {e2, e3} == g.get_edges_with(v3)
            True

        )delimiter")

        .def("get_cycle", &Graph::get_cycle)
        .def("get_cycle_length", &Graph::get_cycle_length, R"delimiter(

            Check if any cycle exists in the graph.
            
            :param root: The algorithm only searches the subgraph that connected to root.
            :type root: Vertex
            :return: Return the number of edges involved in the cycle.
            :rtype: int

            :Example:
            
            >>> v1 = Vertex(1)
            >>> v2 = Vertex(2)
            >>> v3 = Vertex(3)
            >>> e1 = Edge(v1, v2)
            >>> e2 = Edge(v2, v3)
            >>> e3 = Edge(v3, v1)

            >>> g = Graph()
            >>> g.insert(e1)
            >>> g.get_cycle_length(v1)
            0

            >>> g.insert(e2)
            >>> g.get_cycle_length(v1)
            0

            >>> g.insert(e3)
            >>> g.get_cycle_length(v1)
            3

        )delimiter", "root"_a)

        .def("is_cycle_exist", &Graph::is_cycle_exist, R"delimiter(

            Check if any cycle exists in the graph.
            
            :param root: The algorithm only searches the subgraph that connected to root.
            :type root: Vertex
            :return: True if at least one cycle exists, false otherwise.
            :rtype: bool

            :Example:
            
            >>> v1 = Vertex(1)
            >>> v2 = Vertex(2)
            >>> v3 = Vertex(3)
            >>> e1 = Edge(v1, v2)
            >>> e2 = Edge(v2, v3)
            >>> e3 = Edge(v3, v1)

            >>> g = Graph()
            >>> g.insert(e1)
            >>> g.is_cycle_exist(v1)
            False

            >>> g.insert(e2)
            >>> g.is_cycle_exist(v1)
            False

            >>> g.insert(e3)
            >>> g.is_cycle_exist(v1)
            True

        )delimiter", "root"_a)
    
        .def("get_dt_successors", &Graph::get_dt_successors, R"delimiter(

            This function is to get the direct successors of the input vertex.
            
            :param v: An instance of Vertex.
            :type v: Vertex
            :return: A set of successors.
            :rtype: Set[Vertex]

            :Example:
            
            >>> v1 = Vertex(1)
            >>> v2 = Vertex(2)
            >>> v3 = Vertex(3)
            >>> e1 = Edge(v1, v2)
            >>> e2 = Edge(v1, v3)
            >>> e3 = Edge(v3, v2)

            >>> g = Graph()
            >>> g.insert(e1)
            >>> g.insert(e2)
            >>> g.insert(e3)

            >>> {v2, v3} == g.get_dt_successors(v1)
            True
            
            >>> g.get_dt_successors(v2)
            set()

            >>> g.get_dt_successors(v3)
            {<Vertex: 2>}

        )delimiter")

        .def("get_in_degree", &Graph::get_in_degree, R"delimiter(

            This function is to get the in degree of vertex v.
            
            :param v: An instance of Vertex.
            :type v: Vertex
            :return: In degree of vertex v.
            :rtype: int

            :Example:
            
            >>> v1 = Vertex(1)
            >>> v2 = Vertex(2)
            >>> v3 = Vertex(3)

            >>> e1 = Edge(v1, v2)
            >>> e2 = Edge(v1, v3)
            >>> e3 = Edge(v3, v2)

            >>> g = Graph()
            >>> g.insert(e1)
            >>> g.insert(e2)
            >>> g.insert(e3)

            >>> g.get_in_degree(v2)
            2
            
            >>> g.remove(e3)
            >>> g.get_in_degree(v2)
            1

            >>> g.remove(e1)
            >>> g.get_in_degree(v1)
            0

        )delimiter")

        .def("get_out_degree", &Graph::get_out_degree, R"delimiter(

            This function is to get the out degree of vertex v.
            
            :param v: An instance of Vertex.
            :type v: Vertex
            :return: Out degree of the vertex v.
            :rtype: int

            :Example:
            
            >>> v1 = Vertex(1)
            >>> v2 = Vertex(2)
            >>> v3 = Vertex(3)

            >>> e1 = Edge(v1, v2)
            >>> e2 = Edge(v1, v3)
            >>> e3 = Edge(v3, v2)

            >>> g = Graph()
            >>> g.insert(e1)
            >>> g.insert(e2)
            >>> g.insert(e3)

            >>> g.get_out_degree(v1)
            2
            
            >>> g.remove(e1)
            >>> g.get_out_degree(v1)
            1

            >>> g.remove(e2)
            >>> g.get_out_degree(v1)
            0

        )delimiter");
}