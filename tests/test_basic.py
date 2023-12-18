import alpha_zero_env as m


def test_main():
    assert m.__version__ == "0.0.2"
    assert m.add(1, 2) == 3
    print(m.v())
