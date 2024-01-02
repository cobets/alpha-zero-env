#include <vector>

class BoardGame {
public:
  virtual bool has_legal_moves() = 0;
  virtual std::vector<int> get_legal_moves() = 0;
  virtual void execute_move(int move) = 0;
  virtual std::vector<int> get_game_status() = 0;
  virtual void display() = 0;
  virtual unsigned int get_action_size() = 0;
  virtual std::vector<std::vector<int>> get_board() = 0;
  virtual int get_last_move() = 0;
  virtual int get_current_color() = 0;
  virtual unsigned int get_n() = 0;
  virtual BoardGame clone() = 0;
};
