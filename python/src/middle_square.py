def get_middle_string(input_string, new_string_length):
    input_string_length = len(input_string)
    offset = int(input_string_length / 2) - int(new_string_length / 2)
    end = offset + new_string_length

    return input_string[offset:end]


def middle_square(initial, number_of_digits=8):
    num = initial * initial
    num_str = str(num)
    num_str = num_str.rjust(number_of_digits, '0')
    return int(get_middle_string(num_str, int(number_of_digits / 2)))