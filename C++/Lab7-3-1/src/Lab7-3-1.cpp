//============================================================================
// Name        : Lab7-3-1.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Exceptions: file checks
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
using namespace std;

class Matrix {
private:
	int A[2][2];
	string inFilename;
	string outFilename;
public:
	void setInFilename(const string &s) {inFilename = s;}
	void setOutFilename(const string &s) {outFilename = s;}

	void loadMatrix(){
		ifstream fin;
		try {
			fin.open(inFilename);
			if (fin.is_open() == false)
			{
				// file was not open
				throw runtime_error("File not open.");
			}
		}
		catch (runtime_error &r)
		{
			cout << "Error in opening file for input: " << inFilename << ".";
			throw;
		}

		fin >> A[0][0] >> A[0][1] >> A[1][0] >> A[1][1];
		fin.close();
	}

	void saveMatrix(){
		ofstream fout;
		try {
			fout.open(outFilename);
			if (fout.is_open() == false)
			{
				// file was not open
				throw runtime_error("File not open.");
			}
		}
		catch (runtime_error &r)
		{
			cout << "Error in opening file for output: " << outFilename << ".";
			throw;
		}

		fout << A[0][0] << " " << A[0][1] << " " << A[1][0] << " " << A[1][1];
		fout.close();
	}

	int* getMatrix() {return &A[0][0];}

	void setMatrix(const int *M) {
		A[0][0] = *M;
		A[0][1] = *(M+1);
		A[1][0] = *(M+2);
		A[1][1] = *(M+3);
	}

};

int main() {
	Matrix mat;
	//string infn = "G:\\Technology\\General Software Development\\C++\\in.txt";
	string infn = "G:\\Technology\\General Software Development\\C++\\missing.txt";	// file does not exist
	//string outfn = "G:\\Technology\\General Software Development\\C++\\out.txt";
	string outfn = "Q:\\out.txt";	// no write access rights

	mat.setInFilename(infn);

	mat.setOutFilename(outfn);

	int M[2][2] = {0, 1, 2, 3};

	mat.setMatrix(&M[0][0]);



	try {
		mat.saveMatrix();
	}
	catch (runtime_error &r) {
		cout << "Exception while writing data to file: " << r.what() << endl;
	}



	try {
		mat.loadMatrix();
	}
	catch (runtime_error &r) {
		cout << "Exception while getting data from file: " << r.what() << endl;
	}
	catch (...) {
		cout << "some other kind of exception." << endl;
	}



	int *p = mat.getMatrix();
	M[0][0] = *p;
	M[0][1] = *(p+1);
	M[1][0] = *(p+2);
	M[1][1] = *(p+3);


	cout << M[0][0] << " " << M[0][1] << endl;
	cout << M[1][0] << " " << M[1][1] << endl;

	return 0;
}
