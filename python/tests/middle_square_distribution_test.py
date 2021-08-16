import pytest
import matplotlib.pyplot as plt
from middle_square import middle_square


def test_middle_square_full_distribution():
    seed = 1234
    values = []
    for i in range(0, 1001):
        seed = middle_square(seed, 8)
        values.append(seed)

    plt.hist(values, 20)
    #plt.show()

def test_middle_square_last_decimal_digit():
    seed = 1234
    values = []
    for i in range(0, 1001):
        seed = middle_square(seed, 8)
        values.append(seed % 10)

    plt.hist(values, 20)
    #plt.show()