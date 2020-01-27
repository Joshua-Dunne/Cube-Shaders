#ifndef MATRIX3_H
#define MATRIX3_H
#include <math.h>
#include "Vector3.h"

class Vector3;

class Matrix3
	{// The class has nine variables, 3 rows and 3 columns
		double A11;
		double A12;
		double A13;
		double A21;
		double A22;
		double A23;
		double A31;
		double A32;
		double A33;

	public:
		// Constructor 1 - Create a zero matrix
	Matrix3();

		// Constructor 2 - To allow 3 rows of vectors to be declared as a matrix
	Matrix3(Vector3 Row1, Vector3 Row2, Vector3 Row3);
		
		// Constructor 3 - to allow nine double values
	Matrix3(double _A11, double _A12, double _A13,
		double _A21, double _A22, double _A23,
		double _A31, double _A32, double _A33);

	Matrix3 Transpose(Matrix3 M1);

	Matrix3 operator +(Matrix3 M1);
		
	Matrix3 operator -(Matrix3 M1);

	Matrix3 operator *(double x);

	Matrix3 operator *(Matrix3 M1);

	double Determinant(Matrix3 M1);
		
	Vector3 Row(int i);

	Vector3 Column(int i);

	Matrix3 Inverse(Matrix3 M1);

	Matrix3 Rotation(double _angle);
		
	Matrix3 Translate(double dx, double dy);

	Matrix3 Scale(double dx, double dy);

	Matrix3 operator -();

	static Matrix3 RotationX(double _angle);
		
	static Matrix3 RotationY(double _angle);
		
	static Matrix3 RotationZ(double _angle);

	Matrix3 Scale3D(double dx);

	Vector3 operator *(Vector3 V1);

	std::string toString();

	double PI{ 3.1415926535897};
};
#endif