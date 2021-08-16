import pytest

from middle_square import middle_square


@pytest.mark.parametrize("initial, result", [(0, 0),
                                             (1, 0),
                                             (1234, 5227),
                                             (5227, 3215)])
def test_middle_square_correct_result_for_size_eight(initial, result):
    assert middle_square(initial) == result


@pytest.mark.parametrize("initial, result", [(4, 1),
                                             (9, 8),
                                             (11, 2),
                                             (12, 4),
                                             (13, 6),
                                             (14, 9)])
def test_middle_square_correct_result_for_size_three(initial, result):
    assert middle_square(initial, 3) == result
