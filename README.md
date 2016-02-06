# Simple-2048-game
A simple implementation version of 2048 for 4*4 matrix

In this game, there is a 4*4 matrix, whose positions can be numbered from 0 to 15 as follows.

|  0  |  1  |  2  |  3  |
|  4  |  5  |  6  |  7  |
|  8  |  9  |  10 |  11 |
|  12 |  13 |  14 |  15 |

At each position, there may be empty position or a number that is an exponent of 2.
For example , 2, 4, 8 16, 32, etc.
A possible matrix may then be like this:
|  128|   32|     |     |
|    2|    4|     |     |
|    2|     |     |     |
|     |     |     |     |

So there will be a class named Matrix, who has a data member called num (a 4*4 array) to save the matrix described as above.

Here are more details about this class.
(1) A constructor named Matrix(int p1, int p2) initializes the original positions of number 2, 
and p1 and p2 will be a position from 0 to 15.
Then the corresponding positions will be set to 2, and others will be set to 0.
As an example, if calling Matrix(13, 14), the matrix will be like this:
|     |     |     |     |
|     |     |     |     |
|     |     |     |     |
|     |    2|    2|     |

(2) There are four kinds of movements that you can make at each step, as moveLeft, moveRight, moveUp and moveDown.
The function of moveLeft means to push the number to the left,
and if the adjacent two numbers are the same, add them together(left first).
The other movements are similar with moveLeft, but moveRight is right first, and moveUp is top first, moveDown is bottom first.
Note that if the matrix is changed after this operation, you should return true, or you should return false.

Here is an example.

Original Matrix =
|    4|     |    4|    4|
|     |     |     |    4|
|    4|     |    4|     |
|    4|     |    4|     |

Take a moveLeft at original matrix:
|    8|    4|     |     |
|    4|     |     |     |
|    8|     |     |     |
|    8|     |     |     |

Take a moveRight at original matrix:
|     |     |    4|    8|
|     |     |     |    4|
|     |     |     |    8|
|     |     |     |    8|

Take a moveUp at original matrix:
|    8|     |    8|    8|
|    4|     |    4|     |
|     |     |     |     |
|     |     |     |     |

Take a moveDown at original matrix:
|     |     |     |     |
|     |     |     |     |
|    4|     |    4|     |
|    8|     |    8|    8|

(3) A function called add(int p) means that if the number in position p is 0,
you should set the number to 2(to simplify the problem, we will not add a 4 like the original game) and return true.
Or you do not need to set it to 2 and just return false.

(4)A friend function named operator<<(ostream& out, const Matrix& matrix) will output the matrix in a specific format.
The output takes six lines, and every line has 29 characters, which may be a character of a number, a ‘-‘, a ‘|’ or a space.
Note that the width of a number of a data is 6.
