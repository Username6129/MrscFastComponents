#include "PyInterfaceAlgorithms.h"

void bindAlgorithms(py::module& m) {

    py::class_<PathInfo>(m, "PathInfo", R"delimiter(

        A class with two attributes: path, cost. 
        This class is used to return the result of path planning algorithms.

        :var path: A list of edges. 
        :type path: List[Edge]
        :var cost: The total cost of the path.
        :type cost: double 

    )delimiter")
        .def(py::init<>())
        .def_readonly("path", &PathInfo::path)
        .def_readonly("cost", &PathInfo::cost);

    m.def("get_path_gbrs", py::overload_cast<Workspace&, Vector2d&, Vertex&, set<Vertex>&,
        unordered_map<Edge, double, Edge::HashFunction>&, double>(&get_path_gbrs), py::return_value_policy::move,
        R"delimiter(

            This function returns the shortest cost path, which also considers the rotation penalty.
            
            :param workspace: An abstract Graph-based layout.
            :type workspace: Workspace
            :param init_direction: Initial heading direction of a robot.
            :type init_direction: Vector2d
            :param vs: Initiate vertex.
            :type vs: Vertex
            :param ends: A set of available goal vertices or edges.
            :type ends: Set[Vertex, Edges]
            :param cost: Cost function for each edges.
            :type cost: Dict[Edge]
            :param rotation_penalty: Rotation penalty.
            :type rotation_penalty: float

        )delimiter", "workspace"_a, "init_direction"_a, "vs"_a, "ends"_a, "cost"_a, "rotation_penalty"_a);

    m.def("get_path_gbrs", py::overload_cast<Workspace&, Vector2d&, Vertex&, set<Edge>&,
        unordered_map<Edge, double, Edge::HashFunction>&, double>(&get_path_gbrs), py::return_value_policy::move,
        "workspace"_a, "init_direction"_a, "vs"_a, "ends"_a, "cost"_a, "rotation_penalty"_a);
}