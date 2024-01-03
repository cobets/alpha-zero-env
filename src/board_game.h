#include <vector>

class BoardGame {
public:
  BoardGame(unsigned int n, unsigned int n_in_row, int first_color) {};
  virtual bool has_legal_moves() { return false; }
  virtual std::vector<int> get_legal_moves() {
    return {};
  }
  virtual void execute_move(int move) {};
  virtual std::vector<int> get_game_status() {
    return {};
  }
  virtual void display() {}
  virtual unsigned int get_action_size() { return 0; }
  virtual std::vector<std::vector<int>> get_board() {
    return {{}};
  }
  virtual int get_last_move() { return -1; }
  virtual int get_current_color() { return -1; };
  virtual unsigned int get_n() { return 0; }
  virtual BoardGame* clone() { return new BoardGame(*this); }
};
