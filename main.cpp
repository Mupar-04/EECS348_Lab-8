#include "matrix.hpp"
#include <iostream>
#include <fstream>
using namespace std;


vector<vector<int>> read_matrix_from_file(const string &filename, size_t &N) {
    ifstream infile(filename);
    if (!infile) {
        throw runtime_error("Failed to open file: " + filename);
    }

    infile >> N;
    vector<vector<int>> nums(N * 2, vector<int>(N, 0));
    for (size_t i = 0; i < N * 2; ++i) {
        for (size_t j = 0; j < N; ++j) {
            infile >> nums[i][j];
        }
    }
    infile.close();
    return nums;
}

int main() {
        try {
        string filename;
        cout << "Enter the input file name: ";
        cin >> filename;

        size_t N;
        vector<vector<int>> raw_data = read_matrix_from_file(filename, N);

        // Split into two matrices
        vector<vector<int>> m1_data(raw_data.begin(), raw_data.begin() + N);
        vector<vector<int>> m2_data(raw_data.begin() + N, raw_data.end());

        Matrix m1(m1_data);
        Matrix m2(m2_data);

        cout << "\nMatrix 1:\n";
        m1.print_matrix();
        cout << "\nMatrix 2:\n";
        m2.print_matrix();

        // Addition
        Matrix sum = m1 + m2;
        cout << "\nMatrix 1 + Matrix 2:\n";
        sum.print_matrix();

        // Multiplication
        Matrix product = m1 * m2;
        cout << "\nMatrix 1 * Matrix 2:\n";
        product.print_matrix();

        // Diagonal sums
        cout << "\nSum of major diagonal of Matrix 1: " << m1.sum_diagonal_major() << endl;
        cout << "Sum of minor diagonal of Matrix 1: " << m1.sum_diagonal_minor() << endl;

        // Row swap
        size_t r1, r2;
        cout << "\nEnter two row indices to swap in Matrix 1 (0-based): ";
        cin >> r1 >> r2;
        m1.swap_rows(r1, r2);
        cout << "Matrix 1 after swapping rows:\n";
        m1.print_matrix();

        // Column swap
        size_t c1, c2;
        cout << "\nEnter two column indices to swap in Matrix 1 (0-based): ";
        cin >> c1 >> c2;
        m1.swap_cols(c1, c2);
        cout << "Matrix 1 after swapping columns:\n";
        m1.print_matrix();

        // Update element
        size_t row, col;
        int value;
        cout << "\nEnter row index, column index, and new value to update in Matrix 1: ";
        cin >> row >> col >> value;
        m1.set_value(row, col, value);
        cout << "Matrix 1 after update:\n";
        m1.print_matrix();

    } catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }


    return 0;
}
