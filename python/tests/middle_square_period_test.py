from middle_square import middle_square
import matplotlib.pyplot as plt


def test_middle_square_period():
    for number_of_digits in range(2, 14):
        counter_sum = 0
        min_value = 9999999
        max_value = 0

        max_start_seed = 1000
        for start_seed in range(1, max_start_seed):
            seed = start_seed
            value_set = set()
            counter = 0
            while not seed in value_set:
                value_set.add(seed)
                seed = middle_square(seed, number_of_digits)
                counter += 1
                if counter > max_value:
                    max_value = counter
                if counter < min_value:
                    min_value = counter
                counter_sum += counter

        print(f"{number_of_digits} {counter_sum/max_start_seed} {max_value} {min_value} ")
