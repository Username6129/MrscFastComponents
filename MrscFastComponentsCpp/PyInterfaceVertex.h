#pragma once
#include "pybind11/pybind11.h"
#include <pybind11/operators.h>
#include "Vertex.h"

namespace py = pybind11;
using namespace pybind11::literals;

void bindVertex(py::module& m);