#pragma once
#include "pybind11/pybind11.h"
#include <pybind11/operators.h>
#include "Edge.h"
#include "Vector2d.h"

namespace py = pybind11;
using namespace pybind11::literals;

void bindEdge(py::module& m);