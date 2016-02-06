
#include <iostream>
#include <time.h>
#include "Matrix.h"

using std::endl;
using std::cout;
using std::cin;
int main() {
    Matrix m(0, 13);
    cout << "The initial matrix is: " << endl;
    cout << m;
 
    char c;
    cout << "Please input next step (w,a,s,d): ";
    while (cin >> c) {
        bool flag = false;
        switch (c) {  // a, d, w, s stand for left, right, up and down
            case 'a':
                flag = m.moveLeft();
            break;
            case 'd':
                flag = m.moveRight();
            break;
            case 'w':
                flag = m.moveUp();
            break;
            case 's':
                flag = m.moveDown();
            break;
            default:
            break;
        }
        if (flag)  // if the matrix changes, add a 2 to the matrix; else do nothing
            m.update1();
        cout << m;
        cout << "Please input next step (w,a,s,d): ";
    }
    return 0;
}
 
