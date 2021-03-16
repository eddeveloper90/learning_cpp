#include <iostream>
#include "matrix.h"

int main(int argc, char *argv[]) {
    Vector v{2};
    for (int i = 0; i < 2; ++i) {
        v.add_number(i * 5);
    }
    v.add_number(1);
    v.add_number(10);
    v.add_number(20);
    v.add_number(30);
    v.add_number(40);
    v.add_number(50);
    v.add_number(20,50);
//    v.add_number(2);
//    v.add_number(3);
//    v.add_number(2, 10);
//    v.add_number(1, 16);
    v.show_vector();

    std::cout << "------------------------------------------------" << "\n";
    Matrix matrix;
    matrix.add_element(0, 0, 1);
    matrix.add_element(0, 1, 2);
    matrix.add_element(1, 0, 3);
    matrix.add_element(1, 1, 4);
    matrix.show_matrix();

    Matrix matrix2;
    matrix2.add_element(0, 0, 1);
    matrix2.add_element(0, 1, 2);
    matrix2.add_element(1, 0, 5);
    matrix2.add_element(1, 1, 2);
    matrix2.show_matrix();

    Matrix mat3 = matrix + matrix2;
    mat3.show_matrix();

    Matrix mat4 = matrix - matrix2;
    mat4.show_matrix();

    mat4.get_col(0).show_vector();

    std::cout << "------------------------------------------------" << "\n";

    Vector v1{2};
    v1.add_number(0,1);
    v1.add_number(1,2);
    v1.show_vector();

    Vector v2{2};
    v2.add_number(0,3);
    v2.add_number(1,4);
    v2.show_vector();

    std::cout << v1 * v2 << "\n";
    std::cout << "------------------------------------------------" << "\n";
    Matrix mat5 = matrix * matrix2;
    matrix.show_matrix();
    matrix2.show_matrix();
    mat5.show_matrix();
    return EXIT_SUCCESS;
}