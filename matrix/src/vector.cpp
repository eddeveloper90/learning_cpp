/**
 * @author eddeveloper <ed.developer90@gmail.com>
 * Date :  2021-03-16
 * Time : 6:30 PM
 */

#include <iostream>
#include <string>
#include <math.h>
#include "vector.h"

Vector::Vector(int n) {
    change_size(n);
//    std::cout << "vector initialized." << "\n";
}

void Vector::add_number(int n) {
//    std::cout << "vector add_number " << n << "\n";
//    std::cout << "vector add_number -> size " << size << " len " << len << "\n";
    if(size == len) {
//        std::cout << "size changing...\n";
        change_size(size + 1);
    }

    *(element + size++) = n;
}

int Vector::get_current() const {
    return this->size;
}

void Vector::show_vector() const {
    std::string vecstr = "[";
    for (int i = 0; i < this->size; ++i) {
        vecstr += std::to_string(*(element + i));
        if (vecstr != "[" && i < size - 1) {
            vecstr += ",";
        }
    }
    vecstr += "]";
    std::cout << vecstr << "\n";
}

void Vector::add_number(int i, int n) {
//    std::cout << "vector add_number " << i << " " << n << "\n";
//    std::cout << "vector add_number -> size " << size << " len " << len << "\n";
    if (size == 0 || size < i + 1) {
        int s = size;
        for (int j = 0; j < i - s; ++j) {
            add_number(0);
        }
        add_number(n);
    } else {
        element[i] = n;
    }
}

void Vector::show_line() const {
    std::string vecstr = "";
    for (int i = 0; i < this->size; ++i) {
        vecstr += std::to_string(*(element + i));
        if (vecstr != "" && i < size - 1) {
            vecstr += ",";
        }
    }
    std::cout << vecstr << "";
}

void Vector::change_size(int new_size) {
//    std::cout << "vector new size " << new_size << "\n";
    int * tmp {new int[new_size]{}};
    if (len == 0 ) {
        element = new int[new_size];
        for (int i = 0; i < new_size; ++i) {
            element[i] = 0;
        }
        size = new_size;
    } else {
        for (int i = 0; i < new_size; ++i) {
            tmp[i] = element[i];
        }

        if (element != nullptr)
            free(element);
        element = tmp;
    }

    len = new_size;
}

int *Vector::get_row() {
    return this->element;
}

void Vector::load_vec(Vector vec) {
    for (int i = 0; i < std::min(this->size, vec.size); ++i) {
        element[i] = vec.element[i];
    }
}

int Vector::length() {
    return this->size;
}

int Vector::operator*(Vector vec) {
    if(size != vec.size) {
        return 0;
    }

    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += element[i] * vec.element[i];
    }
    return sum;
}
