#include <pybind11/pybind11.h>
#include "env.h"
#include "board_game.h"

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
};

namespace py = pybind11;

PYBIND11_MODULE(alpha_zero_env, m) {
    m.def("add", &add);
    m.def("v", &v);
    py::class_<BoardGame, PyBoardGame>(m, "BoardGame")
        .def(py::init<>())
        .def("has_legal_moves", &BoardGame::has_legal_moves)
        .def("get_legal_moves", &BoardGame::get_legal_moves);

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
