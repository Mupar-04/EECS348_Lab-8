#include "matrix.hpp" // Include the Matrix header file
#include <iostream> // For standard input/output
#include <fstream> // For file operations
using namespace std; //Avoid multiple stds


// This is to read tow matrices from the file
vector<vector<int>> read_matrix_from_file(const string &filename, size_t &N) {
    // Take in the file name
    ifstream infile(filename);
    if (!infile) {
        throw runtime_error("Failed to open file: " + filename);
    }

    // This is the matrix size and it is in the first lin.
    infile >> N;
    
    // Here we create 2N by N matirx to hold both matrices
    vector<vector<int>> nums(N * 2, vector<int>(N, 0));
    for (size_t i = 0; i < N * 2; ++i) {
        for (size_t j = 0; j < N; ++j) {
            infile >> nums[i][j];
        }
    }

    // Close the file after using it.
    infile.close();
    
    // return combined raw matrix data.
    return nums;
}

// This is the main function.
int main() {
        try {
        
        // We first prompt the user to type in the file name.
        string filename;
        cout << "Enter the input file name: ";
        cin >> filename;

        // Size of each matrix
        size_t N;
        vector<vector<int>> raw_data = read_matrix_from_file(filename, N);

        // Split into two matrices
        vector<vector<int>> m1_data(raw_data.begin(), raw_data.begin() + N);
        vector<vector<int>> m2_data(raw_data.begin() + N, raw_data.end());

        // Here I am creating 2 matrices using Matrix class I defined.
        Matrix m1(m1_data);
        Matrix m2(m2_data);

        // Here I am printing them out by calling print_matrix function.
        cout << "\nMatrix 1:\n";
        m1.print_matrix();
        cout << "\nMatrix 2:\n";
        m2.print_matrix();

        // Here I perform addition and store it into sum matrix and I print it
        Matrix sum = m1 + m2;
        cout << "\nMatrix 1 + Matrix 2:\n";
        sum.print_matrix();

        // Here I perform multipication and store it into sum matrix and I print it
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

    } 
    
    // If the code above did not work, I return an error and finsih the program.
    catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    // Here I am finishing the program.
    return 0;
}
