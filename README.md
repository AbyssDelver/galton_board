# Galton Board


-----
to build in release mode:

```
cmake -S ./ -B build/release -DBUILD_TESTING=True -DCMAKE_BUILD_TYPE=Release
```
and then 

```
cmake --build build/release
```
to run the program:
```
./build/release/galton
```
to run the gradient descent version of the program:
```
./build/release/galton_descent
```
to run the test for the program:
```
./build/release/galton.t
```
-----
-----
To build in debug mode use instead:
```
cmake -S ./ -B build/debug -DBUILD_TESTING=True -DCMAKE_BUILD_TYPE=Debug
```

and then 

```
cmake --build build/debug
```
to run the program:
```
./build/debug/galton
```
to run the gradient descent version of the program:
```
./build/debug/galton_descent
```
to run the test for the program:
```
./build/debug/galton.t
```
-----
one can also set 
```
-DBUILD_TESTING=False
```
to not build the tests
## How to use
To change the size and shape of the board one must edit the pegs.txt file. This file contains '.', '\*' and '\n' characters (the rest of the character, like whitespaces, are irrelevant).
The '.' represents the absence of a peg: if the balls falls on the '.' it will drop down, skipping a column. The '\*' represents a peg. The shape of the board must abide to the following requirements:
1. the first row must **not** have an even number of elements
2. the rows must alternate between having the same numbers of elements as the first, and and having one element less than the first row
3. the number of rows must be even

The program has two versions: the normal one and the gradient descent one. The normal version simulates a galton board defined by the pegs.txt file, with the probability of going to the left or to the right of a peg that varies row by row. To change the probability one has to change the relevant vector in the constants.hpp file.
 
The gradient descent version solves the opposite problem: you give the program a probability distribution (by specifing it in the constants.hpp file) and you are given the probability for every row. This is achieved through gradient descent, and the relevant parameters, like the step of the descent, can be again found in the constants.hpp file in the src directory.

## How to read the result
The result gest printed in two different ways: first a visual representation of the lower part of the Galton board is drawn on the screen. The number of elements in each column is
relative to the column with the maximum number of entries, which is always drawn full. Then a full breakdown of the numbers in each bin gets drawn on the screen.

In the gradient descent version of the program the updated probabilites are printed after each iteration.

## Epistemic status
Not very certain of the correctness of the program. The program has not been tested very thoroughly, and there might be bugs. What has been tested is the the throwing of errors when the
conditions on the rows are not satisified. At first glance the example board i have provided in pegs.txt files seems to be giving resonable answers, the result is a normal distribution with center positioned at the middle of the board, as expected. No further testing has been done.
