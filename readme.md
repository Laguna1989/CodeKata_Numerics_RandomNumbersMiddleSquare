# Overview

This is a Code Nummy about psuedo random number generators, specifically the Middle Square algorithm. Please check out
the other [Code Nummies](https://github.com/Laguna1989/CodeNummies_Overview).

The first part of this Code Nummy is to implement the Middle Square algorithm. In a second step we will learn why it is
a bad choice as a random number generator.

# Theory

## Pseudo random number generators

Computers have a hard time with generating random values, as they behave in a deterministic way. However, they can still
create pseudo random numbers, by making use of some clever algebraic rules.

Please note:

* If in doubt about a pseudo random number generator, there are already available test frameworks that can be applied.
  They will detect most common issues. A good example is the BigCrush test
  from [TestU01](http://simul.iro.umontreal.ca/testu01/tu01.html) test suite.
* In almost all cases it is advised to use an existing random number generator. A common recommendation is
  the [Mersenne Twister 19937](https://www.cplusplus.com/reference/random/mt19937/), which is available in most frameworks.

## The Middle Square algorithm

The Middle Square algorithm works as described below:

First we need to determine the seed (initial value of the algorithm) and the number of digits.

* `seed = 1234`
* `number_of_digits = 8`

In each call to the random number generator, the following steps are performed:

* `number = seed * seed`
* Fill up the left side of number with `0` until number contains `number_of_digits` characters.
* Create a substring with length `number_of_digits/2` from the middle of `number`

Let's take a look at an example:

* `seed = 1234`
* `number_of_digits = 8`
* `number = 1234 * 1234 = 1522756`
* Fill with `0`s: `number = 01522756`
* return four digits from the middle of number, in this case `5227`

# Exercise

## Implementation

Let's start out with the actual implementation of the algorithm.

* First, take care of the
  function `get_middle_string(input_string, new_string_length)` in the
  file `src/middle_square`. The unit tests in `tests/get_middle_string_test` will help you through the
  implementation.
* Next, implement the actual random number
  generator, `middle_square(initial, number_of_digits)` in the
  file `src/middle_square`. The unit tests in `tests/middle_square_unit_test` will be helpful here.

## Period of the generator

One major downside of the Middle Square algorithm is the limited period. This means that after a certain amount of calls
the sequence of "random" numbers repeats itself. Implement a test case for this in the
file `tests/middle_square_period_test`.

* Start with a test that calls
    * `std::uint32_t seed = 4;`
    * `seed = middle_square(seed, 2);` repeatedly until the same seed occurs a second time
    * Hint: `std::set<std::uint32_t>` might come in handy
    * Introduce a counter variable, that counts how long the period is
* Now let's do some statistics:
    * Add a for loop around the code that uses initial values 0 to 10000
    * calculate the min, max and average period for this `number_of_digits` for the possible seed values
    * Hint: To speed up calculation, switch to Release build
* Now investigate how this behavior differs for `number_of_digits` in the range 2 to 11
    * For each loop, print out the current `number_of_digits`, min, max and average period.

Question: Will the period be long enough for reasonable statistical sampling?

## Random number Distribution

The limited period leads to problems when it comes to the distribution of random numbers. Implement your tests in the
file `tests/middle_square_distribution_test`.

* Write a test, that records the distribution for  `seed = 1234` and `number_of_digits = 8` for 1000 random numbers.
  What can you observe?
* Write a second test, which creates a histogram of the last decimal digit of the random numbers produced
* Write a third test, which creates a histogram of the last hexadecimal digit of the random numbers produced
* play around with different starting values. Does this make a difference?
* play around with different values for `number_of_digits`. Does this make a (huge) difference?

# References

* [Middle Square Method (wikipedia)](https://en.wikipedia.org/wiki/Middle-square_method)
* [TestU01](http://simul.iro.umontreal.ca/testu01/tu01.html)
* [Mersenn Twister 19937](https://www.cplusplus.com/reference/random/mt19937/)
