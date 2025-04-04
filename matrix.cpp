#include "matrix.hpp" //Include header file.
#include <iostream> //To be able to have input and output.
#include <iomanip> //For formatted printing.
#include <stdexcept> //For throwong exceptions.

using namespace std; //By typing this, we do not need to type out std:: everytime.


// This is a constructor which is responsible for creating a new matrix, 
// Its size depends on the first line of the input file. 
Matrix::Matrix(size_t N) {
    // initialize an empty NxN matrix
    data.resize(N, vector<int>(N, 0));
}


// This prints the matrix in a formatted grid.
void Matrix::print_matrix() const {
    // print out the matrix

    // Loop through each row
    for (const auto& row : data) {

        // Loop through each element
        for (const auto& val : row) {
            
            // print the value with gaps in between.
            cout << setw(4) << val;
        }
        // start a new line once one row is done pritning.
        cout << endl;
    }
}

// This is a constructor which takes in nested vector as input
Matrix::Matrix(vector<vector<int>> nums) {
    // Here I am checking if it is a non-empty square matrix
    if (nums.empty() || nums.size() != nums[0].size()) {
        // I throw an error if it is either of them.
        throw invalid_argument("Matrix must be square and non-empty.");
    }

    // Here I store them as data.
    data = nums;
}

// This is responsible for adding 2 matrices.
Matrix Matrix::operator+(const Matrix &rhs) const {
    
    // Before adding them together, I will need to make sure both matrices have the same size.
    if (get_size() != rhs.get_size()) {
        
        // I will throw an error if they don't
        throw invalid_argument("Matrix sizes do not match for addition.");
    }

    // Here I need to create a new matrix to store the resulting matrix.
    Matrix result(get_size());
    for (size_t i = 0; i < get_size(); ++i) {
        for (size_t j = 0; j < get_size(); ++j) {
            
            // I add each corresponding element in both matrices and store it in our new matrix we just created.
            result.data[i][j] = data[i][j] + rhs.data[i][j];
        }
    }

    // I return the resulting matrix.
    return result;
}

// This function is respnsible for multipication of 2 matrices.
Matrix Matrix::operator*(const Matrix &rhs) const {
   
   // Before multiplying them together, I will need to make sure both matrices have the same size.
    if (get_size() != rhs.get_size()) {
        // I will throw an error if they don't
        throw invalid_argument("Matrix sizes do not match for multiplication.");
    }

    // Create result matrix
    Matrix result(get_size());
    for (size_t i = 0; i < get_size(); ++i) {
        for (size_t j = 0; j < get_size(); ++j) {
            for (size_t k = 0; k < get_size(); ++k) {
                // Here I do multipication, in matrices, multipication is implemented using row * column.
                result.data[i][j] += data[i][k] * rhs.data[k][j];
            }
        }
    }

    // I return resulring matrix.
    return result;
}

// This function is to set a specific value at a specific spot. 
void Matrix::set_value(size_t i, size_t j, int n) {
    
    // If user tries to set a value out of index, I throw an error
    if (i >= get_size() || j >= get_size()) {
        throw out_of_range("Index out of range.");
    }

    // Otherwise, I set the value
    data[i][j] = n;
}

// This function id to get the value of specific index.
int Matrix::get_value(size_t i, size_t j) const {
    // I first check the it is in range or no.
    if (i >= get_size() || j >= get_size()) {
        throw out_of_range("Index out of range.");
    }

    // I return the value at the index.
    return data[i][j];
}

// This returns the size of the matrix
size_t Matrix::get_size() const {
    return data.size();
}


// This function is responsible for summing the values in diagonal line. 
int Matrix::sum_diagonal_major() const {
    
    // This is the resulting value we are going to return.
    int sum = 0;
    for (size_t i = 0; i < get_size(); ++i) {
        // This is how we get the diagonal values and sum it
        sum += data[i][i];
    }

    // We return the resulting sum.
    return sum;
}

// This calculates the other diagonal line(from top-right to bottom-left)
int Matrix::sum_diagonal_minor() const {
    // This is the resulting value we are gonna return
    int sum = 0;

    for (size_t i = 0; i < get_size(); ++i) {
        
        // The value of row index is the same as major one, but the column starts from the end.
        sum += data[i][get_size() - i - 1];
    }

    // Return the final value.
    return sum;
}

// This is to swap 2 rows
void Matrix::swap_rows(size_t r1, size_t r2) {
    
    // Check if the rows user wants to swap is in the range or no.
    if (r1 >= get_size() || r2 >= get_size()) {
        throw out_of_range("Row index out of range.");
    }

    // I use built-in swap function to swap.
    swap(data[r1], data[r2]);
}

// This is to swap the columns
void Matrix::swap_cols(size_t c1, size_t c2) {
    
    // Check if the column user wants to swap is in the range.
    if (c1 >= get_size() || c2 >= get_size()) {
        throw out_of_range("Column index out of range.");
    }

    for (size_t i = 0; i < get_size(); ++i) {

        // I use built-in swap function to swap.
        swap(data[i][c1], data[i][c2]);
    }
}


