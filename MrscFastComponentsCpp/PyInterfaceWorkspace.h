#pragma once
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/operators.h>
#include "Workspace.h"

namespace py = pybind11;
using namespace pybind11::literals;

void bindWorkspace(py::module& m);