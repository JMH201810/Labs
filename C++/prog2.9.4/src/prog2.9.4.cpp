//============================================================================
// Name        : prog2.9.4.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <math.h>	// note this header
using namespace std;

int main() {
	double vector[] = { 1., 2., 3., 4., 5. };
	int n = sizeof(vector) / sizeof(vector[0]);
	double ArithmeticMean=0;
	double HarmonicMean=0;
	double GeometricMean=1;	// note this initialization
	double RootMeanSquare=0;

	// Insert your code here

	for (int i = 0; i < n; i++)
	{
		ArithmeticMean += vector[i];
		HarmonicMean+=1.0/vector[i];
		GeometricMean *= vector[i];
		RootMeanSquare += pow(vector[i],2);
	}

	ArithmeticMean /= n;
	HarmonicMean = n / HarmonicMean;
	GeometricMean = pow(GeometricMean,1.0/n);
	RootMeanSquare = sqrt(RootMeanSquare/n);


	cout << "Arithmetic Mean = " << ArithmeticMean << endl;
	cout << "Harmonic Mean = " << HarmonicMean << endl;
	cout << "Geometric Mean = " << GeometricMean << endl;
	cout << "RootMean Square = " << RootMeanSquare << endl;
	cout << endl;
	return 0;
}
