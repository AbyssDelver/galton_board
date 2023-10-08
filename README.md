# Galton Board


-----
to build in release mode, as is advised for better performance:

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
to run the test for the program:
```
./build/release/galton.t
```
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
The '.' rapresents the absence of a peg: if the balls falls on the '.' it will drop down, skipping a column. The '\*' rapresents a peg. The shape of the board must abide to the following requirements:
1. the first row must **not** have an even number of elements
2. the rows must alternate between having the same numbers of elements as the first, and and having one element less than the first row
3. the number of rows must be even

## How to read the result
the result gest printed in two different ways: first a visual rapresentation of the lower part of the Galton board is drawn on the screen. The number of elements in each column is
relative to the column with the maximum number of entries, which is always drawn full. Then a full breakdown of the numbers in each bin gets drawn on the screen

## Epistemic status
Not very certain of the correctness of the program. The program has not been tested very thoroughly, and there might be bugs. What has been tested is the the throwing of errors when the
conditions on the rows are not satisified. At first glance the example board i have provided in pegs.txt files seems to be giving resonable answers, the result is a normal distribution with center positioned at the middle of the board, as expected. No further testing has been done.
