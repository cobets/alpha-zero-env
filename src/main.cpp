#include <pybind11/pybind11.h>
#include "env.h"
#include "mcts.h"
#include "gomoku.h"

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

class PyBoardGame: public BoardGame {
public:
    using BoardGame::BoardGame;
    bool has_legal_moves() override {
        PYBIND11_OVERRIDE_PURE(
            bool,
            BoardGame,
            has_legal_moves,
        );
    }
    std::vector<int> get_legal_moves() override {
        PYBIND11_OVERRIDE_PURE(
            std::vector<int>,
            BoardGame,
            get_legal_moves,
        );
    }
    void execute_move(int move) override {
        PYBIND11_OVERRIDE_PURE(
            void,
            BoardGame,
            execute_move,
            move
        );
    }
    std::vector<int> get_game_status() override {
        PYBIND11_OVERRIDE_PURE(
            std::vector<int>,
            BoardGame,
            get_game_status,
        );
    }
    void display() override {
        PYBIND11_OVERRIDE_PURE(
            void,
            BoardGame,
            display,
        );
    }
    unsigned int get_action_size() override {
        PYBIND11_OVERRIDE_PURE(
            unsigned int,
            BoardGame,
            get_action_size,
        );
    }
    std::vector<std::vector<int>> get_board() override {
        PYBIND11_OVERRIDE_PURE(
            std::vector<std::vector<int>>,
            BoardGame,
            get_board,
        );
    }
    int get_last_move() override {
        PYBIND11_OVERRIDE_PURE(
            int,
            BoardGame,
            get_last_move,
        );
    }
    int get_current_color() override {
        PYBIND11_OVERRIDE_PURE(
            int,
            BoardGame,
            get_current_color,
        );
    }
    unsigned int get_n() override {
        PYBIND11_OVERRIDE_PURE(
            unsigned int,
            BoardGame,
            get_n,
        );
    }
};

namespace py = pybind11;

PYBIND11_MODULE(alpha_zero_env, m) {
    m.def("add", &add);
    m.def("v", &v);
    py::class_<BoardGame, PyBoardGame>(m, "BoardGame")
        .def(py::init<>())
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
