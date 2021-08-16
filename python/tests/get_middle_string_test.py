import pytest
from middle_square import get_middle_string


def test_get_middle_string_one_of_four():
    input = 'ABCD'
    assert get_middle_string(input, 1) == 'C'

def test_get_middle_string_two_of_four():
    input = 'ABCD'
    assert get_middle_string(input, 2) == 'BC'

def test_get_middle_string_three_of_four():
    input = 'ABCD'
    assert get_middle_string(input, 3) == 'BCD'

def test_get_middle_string_four_of_four():
    input = 'ABCD'
    assert get_middle_string(input, 4) == 'ABCD'

def test_get_middle_string_one_of_five():
    input = 'ABCDE'
    assert get_middle_string(input, 1) == 'C'

def test_get_middle_string_two_of_five():
    input = 'ABCDE'
    assert get_middle_string(input, 2) == 'BC'

def test_get_middle_string_three_of_five():
    input = 'ABCDE'
    assert get_middle_string(input, 3) == 'BCD'

def test_get_middle_string_four_of_five():
    input = 'ABCDE'
    assert get_middle_string(input, 4) == 'ABCD'
