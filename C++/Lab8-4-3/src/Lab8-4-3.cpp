//============================================================================
// Name        : Lab8-4-3.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Operators: arithmetic operators
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
				cout << A[i][j] << " ";
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


	Matrix operator+(int a)
	{
		// add a constant (a) to each element of this matrix.
		Matrix M(numRows, numCols);	// output matrix

		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j < numCols; j++)
			{
				M.set_Value(i,j,A[i][j] + a);
			}
		}
		return M;
	}

	Matrix operator+(const Matrix& B)
	{
		// add a Matrix B to this matrix.

		// The number of columns in this Matrix must equal the number of columns in B.	Same for the rows.
		if (numCols != B.get_NumCols()) throw string ("One of the matrix sizes is not valid.");
		if (numRows != B.get_NumRows()) throw string ("One of the matrix sizes is not valid.");

		Matrix M(numRows, numCols);	// output matrix

		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j < numCols; j++)
			{
				M.set_Value(i,j,A[i][j] + B.get_Value(i, j));
			}
		}
		return M;
	}

	Matrix operator-(int a)
	{
		// subtract a constant (a) to each element of this matrix.
		Matrix M(numRows, numCols);	// output matrix

		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j < numCols; j++)
			{
				M.set_Value(i,j,A[i][j] - a);
			}
		}
		return M;
	}

	Matrix operator-(const Matrix& B)
	{
		// subtract a Matrix B from this matrix.

		// The number of columns in this Matrix must equal the number of columns in B.	Same for the rows.
		if (numCols != B.get_NumCols()) throw string ("One of the matrix sizes is not valid.");
		if (numRows != B.get_NumRows()) throw string ("One of the matrix sizes is not valid.");

		Matrix M(numRows, numCols);	// output matrix

		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j < numCols; j++)
			{
				M.set_Value(i,j,A[i][j] - B.get_Value(i, j));
			}
		}
		return M;
	}

	Matrix operator*(int a)
	{
		// multiply a constant (a) to each element of this matrix.
		Matrix M(numRows, numCols);	// output matrix

		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j < numCols; j++)
			{
				M.set_Value(i,j,A[i][j] * a);
			}
		}
		return M;
	}

	Matrix operator*(const Matrix& B)
	{
		// multiply this matrix by Matrix B.

		// The number of columns in this Matrix must equal the number of rows in B.
		if (numCols != B.get_NumRows()) throw string ("One of the matrix sizes is not valid.");

		Matrix M(numRows, B.get_NumCols());	// output matrix

		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j < B.get_NumCols(); j++)
			{
				int value = 0;
				for (int k = 0; k < numCols; k++)
				{
					value += A[i][k] * B.get_Value(k, j);
				}
				M.set_Value(i,j,value);
			}
		}
		return M;
	}

	Matrix& operator=(const Matrix& M)
	{

		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j < numCols; j++)
			{
				A[i][j] = M.get_Value(i,j);
			}
		}
		return *this;
	}

	Matrix(const Matrix& M){
		// copy constructor
		numRows = M.get_NumRows();
		numCols = M.get_NumCols();

		A = new int*[this->numRows];	// pointer to an array of pointers to integers.
		for (int i = 0; i < this->numRows; i++){
			A[i] = new int[this->numCols];	// pointer to an array of integers.
		}

		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j < numCols; j++)
			{
				A[i][j] = M.get_Value(i, j);
			}
		}
	}



};



int main() {
	int numRows, numCols;	// number of rows and columns in a matrix.
	Matrix *M[3];			// Pointers to matrices.



	// Create Matrix objects.
	cout << "Constructing three matrices of integers." << endl;
	for (int i = 0; i < 3; i++)	// loop over matrices
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
	cout << "\n\nInputting values for matrices." << endl;
	for (int i = 0; i < 3; i++) // loop over matrices
	{
		cout << "Matrix " << i+1 << ":" << endl;
		for (int j = 0; j < M[i]->get_NumRows(); j++)	// loop over rows
		{
			cout << "Enter values for row " << j+1 << ": ";
			for (int k = 0; k < M[i]->get_NumCols(); k++)	// loop over columns
			{
				int val;
				cin >> val;
				try{
					M[i]->set_Value(j, k, val);
				}
				catch (string &s){
					cout << "Exception in setting matrix values: " << s << endl;
					cout << "Attempted row, column coordinates: (" << j << ", " << k << ").  "
							<< "Valid limits: 0 <= r <= " << M[i]->get_NumRows() - 1 << ",  0 <= c <= " << M[i]->get_NumCols() - 1 << "." << endl;
					cout << "Not setting this matrix element value.";
				}
			}
		}
	}



	cout << "Matrix A + 1:" << endl;
	Matrix A = *M[0] + 1;
	A.print();

	cout << "Matrix A * 2:" << endl;
	A = A * 2;
	A.print();

	cout << "Matrix A - 1:" << endl;
	A = A - 1;
	A.print();

	Matrix B = *M[1];

	cout << "Matrix A + Matrix B:" << endl;
	try {
		Matrix sum = A + B;
		sum.print();
	} catch (string &s) {
		cout << "Exception: " << s << endl << endl;
	}

	cout << "Matrix A - Matrix B:" << endl;
	try {
		Matrix diff = A - B;
		diff.print();
	} catch (string &s) {
		cout << "Exception: " << s << endl << endl;
	}

	cout << "Matrix A * Matrix B:" << endl;
	try {
		Matrix prod = A * B;
		prod.print();
	} catch (string &s) {
		cout << "Exception: " << s << endl << endl;
	}

	Matrix C = *M[2];
	try {
		cout << "Matrix A + Matrix C:" << endl;
		Matrix sum2 = A + C;
		sum2.print();
	} catch (string &s) {
		cout << "Exception: " << s << endl << endl;
	}

	try {
		cout << "Matrix A - Matrix C:" << endl;
		Matrix diff2 = A - C;
		diff2.print();
	} catch (string &s) {
		cout << "Exception: " << s << endl << endl;
	}

	try {
		cout << "Matrix A * Matrix C:" << endl;
		Matrix prod2 = A * C;
		prod2.print();
	} catch (string &s) {
		cout << "Exception: " << s << endl << endl;
	}




	//	// Add the created matrices in all combinations.
	//	Matrix *sum11, *sum12, *sum13, *sum22, *sum23, *sum33;
	//
	//	try{
	//		sum11 = new Matrix(M[0]->get_NumRows(), M[0]->get_NumRows());	// generate sum11, having same dimensions as M[0].
	//
	//		try {
	//			sum11->MatrixAdd(M[0], M[0]);
	//
	//			cout << "\nM1 + M1:" << endl;
	//			sum11->print();
	//
	//			delete sum11;
	//		}
	//		catch (string &s){
	//			cout << "Exception in addition into sum11: " << s << endl;
	//		}
	//	}
	//	catch (string &s) {
	//		cout << "Exception in sum11 Matrix construction: " << s << endl;
	//	}
	//
	//
	//
	//	try{
	//		sum12 = new Matrix(M[0]->get_NumRows(), M[0]->get_NumRows());	// generate sum12, having same dimensions as M[0].
	//
	//		try {
	//			sum12->MatrixAdd(M[0], M[1]);
	//
	//			cout << "\nM1 + M2:" << endl;
	//			sum12->print();
	//
	//			delete sum12;
	//		}
	//		catch (string &s){
	//			cout << "Exception in addition into sum12: " << s << endl;
	//		}
	//	}
	//	catch (string &s) {
	//		cout << "Exception in sum12 Matrix construction: " << s << endl;
	//	}
	//
	//
	//
	//	try{
	//		sum13 = new Matrix(M[0]->get_NumRows(), M[0]->get_NumRows());	// generate sum13, having same dimensions as M[0].
	//
	//		try {
	//			sum13->MatrixAdd(M[0], M[2]);
	//
	//			cout << "\nM1 + M3:" << endl;
	//			sum13->print();
	//
	//			delete sum13;
	//		}
	//		catch (string &s){
	//			cout << "Exception in addition into sum13: " << s << endl;
	//		}
	//	}
	//	catch (string &s) {
	//		cout << "Exception in sum13 Matrix construction: " << s << endl;
	//	}
	//
	//
	//
	//	try{
	//		sum22 = new Matrix(M[1]->get_NumRows(), M[1]->get_NumRows());	// generate sum22, having same dimensions as M[1].
	//
	//		try {
	//			sum22->MatrixAdd(M[1], M[1]);
	//
	//			cout << "\nM2 + M2:" << endl;
	//			sum22->print();
	//
	//			delete sum22;
	//		}
	//		catch (string &s){
	//			cout << "Exception in addition into sum22: " << s << endl;
	//		}
	//	}
	//	catch (string &s) {
	//		cout << "Exception in sum22 Matrix construction: " << s << endl;
	//	}
	//
	//
	//
	//	try{
	//		sum23 = new Matrix(M[1]->get_NumRows(), M[1]->get_NumRows());	// generate sum23, having same dimensions as M[1].
	//
	//		try {
	//			sum23->MatrixAdd(M[1], M[2]);
	//
	//			cout << "\nM2 + M3:" << endl;
	//			sum23->print();
	//
	//			delete sum23;
	//		}
	//		catch (string &s){
	//			cout << "Exception in addition into sum23: " << s << endl;
	//		}
	//	}
	//	catch (string &s) {
	//		cout << "Exception in sum23 Matrix construction: " << s << endl;
	//	}
	//
	//
	//
	//	try{
	//		sum33 = new Matrix(M[2]->get_NumRows(), M[2]->get_NumRows());	// generate sum33, having same dimensions as M[2].
	//
	//		try {
	//			sum33->MatrixAdd(M[2], M[2]);
	//
	//			cout << "\nM3 + M3:" << endl;
	//			sum33->print();
	//
	//			delete sum33;
	//		}
	//		catch (string &s){
	//			cout << "Exception in addition into sum33: " << s << endl;
	//		}
	//	}
	//	catch (string &s) {
	//		cout << "Exception in sum33 Matrix construction: " << s << endl;
	//	}
	//








	// Free memory
	for (int i = 0; i < 3; i++)
	{
		if (M[i] != nullptr){
			delete M[i]; M[i] = nullptr;
		}
	}

	return 0;
}
