/**
 * @author eddeveloper <ed.developer90@gmail.com>
 * Date :  2021-03-16
 * Time : 6:22 PM
 */

#include <iostream>
#include "matrix.h"

Matrix::Matrix() {
    n = 2;
    change_size(2);
//    std::cout << "Matrix initialized.\n";
}

void Matrix::show_matrix() {
    std::cout << "[";
    for (int i = 0; i < m; ++i) {
        if (i != 0) {
            std::cout << " ";
        }
        rows[i]->show_line();
        if (i < m - 1) {
            std::cout << "\n";
        }
    }
    std::cout << "]\n";
}

void Matrix::add_row(Vector *row) {
    *(rows + m++) = row;
}

void Matrix::add_element(int r, int c, int a) {
//    std::cout << r << " " << c << " " << a << "\n";
    if (c >= n) {
        n = c + 1;
    }

    if (r >= m) {
        change_size(r + 1);
    }

    rows[r]->add_number(c, a);
}

void Matrix::change_size(int new_size) {
//    std::cout << "matrix new size " << new_size << "\n";
    if (m == 0) {
        rows = new Vector *[new_size];
        for (int i = 0; i < new_size; ++i) {
            rows[i] = new Vector(n);
        }
    } else {
        Vector **tmp = new Vector *[new_size];
        for (int i = 0; i < new_size; ++i) {
            tmp[i] = new Vector(n);
            if (i < m) {
                tmp[i]->load_vec(rows[i]);
            }
        }
        if (rows != nullptr)
            free(rows);
        rows = tmp;
    }
    m = new_size;
}

int Matrix::rows_len() {
    return this->m;
}

int Matrix::cols_len() {
    return this->n;
}

Matrix Matrix::operator+(Matrix mat) {
    if (this->m != mat.rows_len()) {
        return Matrix{};
    }

    if (this->n != mat.cols_len()) {
        return Matrix{};
    }

    Matrix tmp;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            tmp.add_element(i, j, this->rows[i]->get_row()[j] + mat.rows[i]->get_row()[j]);
        }
    }
    return tmp;
}

Matrix Matrix::operator-(Matrix mat) {
    if (this->m != mat.rows_len()) {
        return Matrix{};
    }

    if (this->n != mat.cols_len()) {
        return Matrix{};
    }

    Matrix tmp;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            tmp.add_element(i, j, this->rows[i]->get_row()[j] - mat.rows[i]->get_row()[j]);
        }
    }
    return tmp;
}

Matrix Matrix::operator*(Matrix mat) {
    if(n != mat.rows_len()) {
        return mat;
    }

    Matrix tmp;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
               tmp.add_element(i, j, rows[0][i] * mat.get_col(j));
        }
    }

    return tmp;
}

Vector Matrix::get_col(int col) {
    Vector column{m};
    for (int i = 0; i < m; ++i) {
        column.add_number(i, rows[i]->get_row()[col]);
    }
    return column;
}


