#include <pybind11/pybind11.h>
#include "env.h"
#include "mcts.h"
#include "gomoku.h"

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

namespace py = pybind11;

PYBIND11_MODULE(alpha_zero_env, m) {
    m.def("add", &add);
    m.def("v", &v);
    py::class_<BoardGame>(m, "BoardGame")
        .def(py::init<unsigned int, unsigned int, int>())
        .def("has_legal_moves", &BoardGame::has_legal_moves)
        .def("get_legal_moves", &BoardGame::get_legal_moves)
        .def("execute_move", &BoardGame::execute_move)
        .def("get_game_status", &BoardGame::get_game_status)
        .def("display", &BoardGame::display)
        .def("get_action_size", &BoardGame::get_action_size)
        .def("get_board", &BoardGame::get_board)
        .def("get_last_move", &BoardGame::get_last_move)
        .def("get_current_color", &BoardGame::get_current_color)
        .def("get_n", &BoardGame::get_n)
        .def("clone", &BoardGame::clone)
        ;
    py::class_<NeuralNetwork>(m, "NeuralNetwork")
        .def(py::init<std::string, bool, unsigned int>())
        ;
    py::class_<MCTS>(m, "MCTS")
        .def(py::init<NeuralNetwork*, unsigned int, double, unsigned int, double, unsigned int>())
        ;

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
