//============================================================================
// Name        : Lab8-1-1.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Operators: iostream and operators
//============================================================================

#include <iostream>
using namespace std;

class Matrix {
private:
	// Matrix dimensions
	int numRows;	// number of rows
	int numCols;	// number of columns

	// Matrix contents
	int **A;

public:
	// Constructor
	Matrix (int numRows, int numCols) throw (string) {
		if (numRows <= 0 || numCols <= 0) {
			throw string("Invalid dimension supplied to Matrix constructor.");
		}
		this->numRows = numRows;
		this->numCols = numCols;

		A = new int*[this->numRows];	// pointer to an array of pointers to integers.
		for (int i = 0; i < this->numRows; i++){
			A[i] = new int[this->numCols];	// pointer to an array of integers.
		}
	}


	// Getters
	int get_NumRows() const {return numRows;}
	int get_NumCols() const {return numCols;}
	int get_Value(int r, int c) const throw (string) {
		if (r < 0 || r >= numRows || c < 0 || c >= numCols) throw string("Invalid row and/or column coordinate supplied to getter.");
		return A[r][c];
	}


	// Overloaded << operator to print matrix values to the console.
	friend ostream& operator<<(ostream& os, Matrix m)
	{
		m.print();
		return os;
	}


	// Overloaded >> operator to get the values of this matrix.
	friend istream& operator>>(istream& is, Matrix& m)
	{
		for (int j = 0; j < m.get_NumRows(); j++)	// loop over rows
		{
			//cout << "Enter values for row " << j+1 << ": ";
			for (int k = 0; k < m.get_NumCols(); k++)	// loop over columns
			{
				int val;
				is >> val;
				try{
					m.set_Value(j, k, val);
				}
				catch (string &s){
					cout << "Exception in setting matrix values: " << s << endl;
					cout << "Attempted row, column coordinates: (" << j << ", " << k << ").  "
							<< "Valid limits: 0 <= r <= " << m.get_NumRows() - 1 << ",  0 <= c <= " << m.get_NumCols() - 1 << "." << endl;
					cout << "Not setting this matrix element value.";
				}
			}
		}

		return is;
	}



	// Matrix addition
	void MatrixAdd(Matrix *B, Matrix *C) throw (string) {
		// Performs this->A = B->A + C->A.
		// B and/or C may equal this

		if (B == nullptr || C == nullptr) throw string("Null addend pointer supplied to MatrixAdd.");

		if (C->get_NumRows() != numRows || C->get_NumCols() != numCols) throw string("Addend matrix dimensions do not match.");

		if (B->get_NumRows() != numRows || B->get_NumCols() != numCols) throw string("Addend matrix dimensions do not match.");

		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j < numCols; j++)
			{
				this->A[i][j] = B->A[i][j] + C->A[i][j];
			}
		}
	}




	// Setter
	void set_Value(int r, int c, int val) throw (string) {
		if (r < 0 || r >= numRows || c < 0 || c >= numCols) throw string("Invalid row and/or column coordinate supplied to setter.");
		A[r][c] = val;
	}



	// Display values
	void print() {
		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j < numCols; j++)
			{
				cout << A[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}



	// Destructor
	~Matrix(){
		for (int i = 0; i < this->numRows; i++){
			if (A != nullptr) delete [] A;
		}
		if (*A != nullptr) delete [] *A;
	}
};



int main() {
	int numRows, numCols;	// number of rows and columns in a matrix.
	Matrix *M[1];			// Pointers to matrices.



	// Create Matrix objects.
	cout << "Constructing one matrix of integers." << endl;
	for (int i = 0; i < 1; i++)	// loop over matrices
	{
		bool matrixOK = true;	// control re-input of dimensions until they are valid.

		do {
			cout << "Matrix #" << i+1 << ": enter number of rows and number of columns: ";
			cin >> numRows >> numCols;
			try{
				M[i] = new Matrix(numRows, numCols);
			}
			catch(string &s){
				cout << "Exception in Matrix construction: " << s << endl;
				matrixOK = false;	// force re-input of dimensions for this matrix.
			}
		}while (!matrixOK);
	}



	// Fill matrices with values.
	cout << "\n\nInputting values for matrix." << endl;
	for (int i = 0; i < 1; i++) // loop over matrices
	{
		cout << "Matrix " << i+1 << ":" << endl;
//		for (int j = 0; j < M[i]->get_NumRows(); j++)	// loop over rows
//		{
//			cout << "Enter values for row " << j+1 << ": ";
//			for (int k = 0; k < M[i]->get_NumCols(); k++)	// loop over columns
//			{
//				int val;
//				cin >> val;
//				try{
//					M[i]->set_Value(j, k, val);
//				}
//				catch (string &s){
//					cout << "Exception in setting matrix values: " << s << endl;
//					cout << "Attempted row, column coordinates: (" << j << ", " << k << ").  "
//							<< "Valid limits: 0 <= r <= " << M[i]->get_NumRows() - 1 << ",  0 <= c <= " << M[i]->get_NumCols() - 1 << "." << endl;
//					cout << "Not setting this matrix element value.";
//				}
//			}
//		}
		cin >> *M[i];	// use the overloaded extraction operator
	}




	// Displaying the matrix.
	cout << endl;
	cout << *M[0];	// use the overloaded insertion operator.











	// Free memory
	for (int i = 0; i < 1; i++)
	{
		if (M[i] != nullptr){
			delete M[i]; M[i] = nullptr;
		}
	}

	return 0;
}
