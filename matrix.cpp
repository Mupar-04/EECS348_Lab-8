#include "matrix.hpp"
#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;
// implementation of functions declared in matrix.hpp goes here
// function definitions for a class have their names prefixed with
// the class name and "::"

// e.g. for the constructor:

Matrix::Matrix(size_t N) {
    // initialize an empty NxN matrix
    data.resize(N, vector<int>(N, 0));
}

// e.g. for a member function:

void Matrix::print_matrix() const {
    // print out the matrix
    for (const auto& row : data) {
        for (const auto& val : row) {
            cout << setw(4) << val;
        }
        cout << endl;
    }
}

Matrix::Matrix(vector<vector<int>> nums) {
    if (nums.empty() || nums.size() != nums[0].size()) {
        throw invalid_argument("Matrix must be square and non-empty.");
    }
    data = nums;
}

Matrix Matrix::operator+(const Matrix &rhs) const {
    if (get_size() != rhs.get_size()) {
        throw invalid_argument("Matrix sizes do not match for addition.");
    }
    Matrix result(get_size());
    for (size_t i = 0; i < get_size(); ++i) {
        for (size_t j = 0; j < get_size(); ++j) {
            result.data[i][j] = data[i][j] + rhs.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix &rhs) const {
    if (get_size() != rhs.get_size()) {
        throw invalid_argument("Matrix sizes do not match for multiplication.");
    }
    Matrix result(get_size());
    for (size_t i = 0; i < get_size(); ++i) {
        for (size_t j = 0; j < get_size(); ++j) {
            for (size_t k = 0; k < get_size(); ++k) {
                result.data[i][j] += data[i][k] * rhs.data[k][j];
            }
        }
    }
    return result;
}


void Matrix::set_value(size_t i, size_t j, int n) {
    if (i >= get_size() || j >= get_size()) {
        throw out_of_range("Index out of range.");
    }
    data[i][j] = n;
}

int Matrix::get_value(size_t i, size_t j) const {
    if (i >= get_size() || j >= get_size()) {
        throw out_of_range("Index out of range.");
    }
    return data[i][j];
}


size_t Matrix::get_size() const {
    return data.size();
}


int Matrix::sum_diagonal_major() const {
    int sum = 0;
    for (size_t i = 0; i < get_size(); ++i) {
        sum += data[i][i];
    }
    return sum;
}

int Matrix::sum_diagonal_minor() const {
    int sum = 0;
    for (size_t i = 0; i < get_size(); ++i) {
        sum += data[i][get_size() - i - 1];
    }
    return sum;
}

void Matrix::swap_rows(size_t r1, size_t r2) {
    if (r1 >= get_size() || r2 >= get_size()) {
        throw out_of_range("Row index out of range.");
    }
    swap(data[r1], data[r2]);
}

void Matrix::swap_cols(size_t c1, size_t c2) {
    if (c1 >= get_size() || c2 >= get_size()) {
        throw out_of_range("Column index out of range.");
    }
    for (size_t i = 0; i < get_size(); ++i) {
        swap(data[i][c1], data[i][c2]);
    }
}


