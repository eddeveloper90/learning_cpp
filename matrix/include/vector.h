/**
 * @author eddeveloper <ed.developer90@gmail.com>
 * Date :  2021-03-16
 * Time : 6:58 PM
 */

#ifndef MATRIX_VECTOR_H
#define MATRIX_VECTOR_H

#endif //MATRIX_VECTOR_H

class Vector {
private:
    int *element{new int};
    int size{0};
    int len{0};

    void change_size(int new_size);

public:
    Vector(int n);

    int *get_row();

    void add_number(int i, int n);

    void add_number(int n);

    int get_current() const;

    void show_vector() const;

    void show_line() const;

    void load_vec(Vector vec);

    int length();

    int operator*(Vector vec);
};