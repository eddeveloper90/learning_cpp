/**
 * @author eddeveloper <ed.developer90@gmail.com>
 * Date :  2021-03-16
 * Time : 6:22 PM
 */

#ifndef LEARNING_CPP_MATRIX_H
#define LEARNING_CPP_MATRIX_H

#include "vector.h"
//#include "string"

class Matrix {
private:
    int m{0}, n{0};
//    Vector *rows = (Vector*)malloc(sizeof(Vector) * 15); ;
    Vector *rows = (Vector *) malloc(sizeof(Vector) * 2);

    void change_size(int new_size);

public:
    Matrix();

    void add_row(Vector *row);

    void add_element(int m, int n, int a);

    void show_matrix();

    int rows_len();

    int cols_len();

    Vector get_col(int c);

    Matrix operator+(Matrix m);

    Matrix operator*(Matrix m);

    Matrix operator-(Matrix m);
};


#endif //LEARNING_CPP_MATRIX_H
