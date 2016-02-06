#include <iostream>
#include <queue>
#include "Matrix.h"
 
using std::endl;
using std::queue;
 
Matrix::Matrix(int p1, int p2) {
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            num[r][c] = 0;
    num[p1/cols][p1%cols] = 2;
    num[p2/cols][p2%cols] = 2;
}
 
bool Matrix::moveLeft() {
    int tmp[rows][cols];  //  tmp stores a copy of current matrix
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            tmp[r][c] = num[r][c];
    for (int r = 0; r < rows; r++) {  //  moving left affect the rows seperately.
        queue<int> q;
        for (int c = 0; c < cols; c++) {
            if (num[r][c])
                q.push(num[r][c]);  //  Ignore those 0s.
            num[r][c] = 0;
        }
        int pos = 0;
        while (!q.empty()) {
            int k = q.front();
            q.pop();
            if (q.empty() || k != q.front()) {  //  If the neighbour two numbers are different, then just move their position.
                num[r][pos++] = k;
            } else {  //  If the neighbour two numbers are same, then merge them.
                num[r][pos++] = 2*k; 
                q.pop();
            }
        }
    }
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            if (tmp[r][c] != num[r][c])  //  Only if the two matrix are different, there will be a new number 2 added in.
                return true;
    return false;
}
 
bool Matrix::moveRight() {
    int tmp[rows][cols];
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            tmp[r][c] = num[r][c];
    for (int r = 0; r < rows; r++) {
        queue<int> q;
        for (int c = cols-1; c >= 0; c--) {
            if (num[r][c])
                q.push(num[r][c]);
            num[r][c] = 0;
        }
        int pos = cols-1;
        while (!q.empty()) {
            int k = q.front();
            q.pop();
            if (q.empty() || k != q.front()) {
                num[r][pos--] = k;
            } else {
                num[r][pos--] = 2*k;
                q.pop();
            }
        }
    }
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            if (tmp[r][c] != num[r][c])
                return true;
    return false;
}
 
bool Matrix::moveUp() {
    int tmp[rows][cols];
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            tmp[r][c] = num[r][c];
    for (int c = 0; c < cols; c++) {
        queue<int> q;
        for (int r = 0; r < rows; r++) {
            if (num[r][c])
                q.push(num[r][c]);
            num[r][c] = 0;
        }
        int pos = 0;
        while (!q.empty()) {
            int k = q.front();
            q.pop();
            if (q.empty() || k != q.front()) {
                num[pos++][c] = k;
            } else {
                num[pos++][c] = 2*k;
                q.pop();
            }
        }
    }
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            if (tmp[r][c] != num[r][c])
                return true;
    return false;
}
 
bool Matrix::moveDown() {
    int tmp[rows][cols];
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            tmp[r][c] = num[r][c];
    for (int c = 0; c < cols; c++) {
        queue<int> q;
        for (int r = rows-1; r >= 0; r--) {
            if (num[r][c])
                q.push(num[r][c]);
            num[r][c] = 0;
        }
        int pos = rows-1;
        while (!q.empty()) {
            int k = q.front();
            q.pop();
            if (q.empty() || k != q.front()) {
                num[pos--][c] = k;
            } else {
                num[pos--][c] = 2*k;
                q.pop();
            }
        }
    }
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            if (tmp[r][c] != num[r][c])
                return true;
    return false;
}
 
bool Matrix::add(int p) {
    int r = p/cols;
    int c = p%cols;
    if (num[r][c])
        return false;
    num[r][c] = 2;
    return true;
}

// Overwrite output stream operation to ouput the matrix in standard format.
ostream& operator<<(ostream& out, const Matrix& matrix) {
    for (int i = 0; i <= (L+1)*cols; i++)
        out << "-";
    out << endl;
    for (int r = 0; r < rows; r++) {
        out << "|";
        for (int c = 0; c < cols; c++) {
            int k = matrix.num[r][c];
            out.width(L);
            if (k)
                out << matrix.num[r][c];
            else
                out << "";
            out << "|";
        }
        out << endl;
    }
    for (int i = 0; i <= (L+1)*cols; i++)
        out << "-";
    out << endl;
 
    return out;
}
