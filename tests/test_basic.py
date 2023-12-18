import alpha_zero_env as m


class DotsGame(m.BoardGame):
    pass


def test_main():
    assert m.__version__ == "0.0.3"
    assert m.add(1, 2) == 3
    print(m.v())
    game = DotsGame()
    print(game.has_legal_moves())
