#include "Matrix3.h"

Matrix3::Matrix3()
{
	A11 = 0.0;
	A12 = 0.0;
	A13 = 0.0;
	A21 = 0.0;
	A22 = 0.0;
	A23 = 0.0;
	A31 = 0.0;
	A32 = 0.0;
	A33 = 0.0;
}

Matrix3::Matrix3(Vector3 Row1, Vector3 Row2, Vector3 Row3)
{
	A11 = Row1.getX();
	A12 = Row1.getY();
	A13 = Row1.getZ();
	A21 = Row2.getX();
	A22 = Row2.getY();
	A23 = Row2.getZ();
	A31 = Row3.getX();
	A32 = Row3.getY();
	A33 = Row3.getZ();
}

Matrix3::Matrix3(double _A11, double _A12, double _A13, double _A21, double _A22, double _A23, double _A31, double _A32, double _A33)
{
	A11 = _A11;
	A12 = _A12;
	A13 = _A13;
	A21 = _A21;
	A22 = _A22;
	A23 = _A23;
	A31 = _A31;
	A32 = _A32;
	A33 = _A33;
}

Matrix3 Matrix3::Transpose(Matrix3 M1)
{// a method to transpose a given matrix
	return Matrix3(M1.A11, M1.A21, M1.A31,
		M1.A12, M1.A22, M1.A32,
		M1.A13, M1.A23, M1.A33);
}

Matrix3 Matrix3::operator+(Matrix3 M1)
{// An overloaded operator + to return the  sum of two matrix 
	return Matrix3(M1.A11 + A11, M1.A12 + A12, M1.A13 + A13,
		M1.A21 + A21, M1.A22 + A22, M1.A23 + A23,
		M1.A31 + A31, M1.A32 + A32, M1.A33 + A33);
}

// An overloaded operator - to return the difference of two matrix
Matrix3 Matrix3::operator-(Matrix3 M1)
{
	return Matrix3(M1.A11 - A11, M1.A12 - A12, M1.A13 - A13,
		M1.A21 - A21, M1.A22 - A22, M1.A23 - A23,
		M1.A31 - A31, M1.A32 - A32, M1.A33 - A33);
}

// An overloaded operator * to return the  product of the matrix by a scalar
Matrix3 Matrix3::operator*(double x)
{
	Matrix3 answer;
	answer.A11 = A11 * x;
	answer.A12 = A12 * x;
	answer.A13 = A13 * x;

	answer.A21 = A21 * x;
	answer.A22 = A22 * x;
	answer.A23 = A23 * x;

	answer.A31 = A31 * x;
	answer.A32 = A32 * x;
	answer.A33 = A33 * x; ;

	return answer;
}

// An overloaded operator * to return the  product of two matrix
Matrix3 Matrix3::operator*(Matrix3 M1)
{
	Matrix3 answer;

	answer.A11 = M1.Row(0) * Column(0);
	answer.A12 = M1.Row(0) * Column(1);
	answer.A13 = M1.Row(0) * Column(2);

	answer.A21 = M1.Row(1) * Column(0);
	answer.A22 = M1.Row(1) * Column(1);
	answer.A23 = M1.Row(1) * Column(2);

	answer.A31 = M1.Row(2) * Column(0);
	answer.A32 = M1.Row(2) * Column(1);
	answer.A33 = M1.Row(2) * Column(2);

	return answer;
}

// method to return the determinant of a 3x3 matrix
double Matrix3::Determinant(Matrix3 M1)
{
			//                     aei      -     ahf                  + dhc                     - gec                      +    gbh                    -     dbi   
	return M1.A11 * M1.A22 * M1.A33 - M1.A11 * M1.A32 * M1.A23 + M1.A21 * M1.A32 * M1.A13 - M1.A31 * M1.A22 * M1.A13 + M1.A31 * M1.A12 * M1.A23 - M1.A21 * M1.A12 * M1.A33;
}

// a method to return as Row as vector3 0 == first row, default == last row
Vector3 Matrix3::Row(int i)
{
	Vector3 answer;
	switch (i)
	{
	case 0:
		answer = Vector3(static_cast<float>(A11), static_cast<float>(A12), static_cast<float>(A13));
		break;
	case 1:
		answer = Vector3(static_cast<float>(A21), static_cast<float>(A22), static_cast<float>(A23));
		break;
	case 2:
	default:
		answer = Vector3(static_cast<float>(A31), static_cast<float>(A32), static_cast<float>(A33));
		break;
	}

	return answer;
}

// a method to return as column as vector3 0 == first column, default == last column
Vector3 Matrix3::Column(int i)
{
	switch (i)
	{
	case 0:
		return{ static_cast<float>(A11), static_cast<float>(A21), static_cast<float>(A31) };
	case 1:
		return{ static_cast<float>(A12), static_cast<float>(A22), static_cast<float>(A32) };
	case 2:
	default:
		return{ static_cast<float>(A13), static_cast<float>(A23), static_cast<float>(A33) };
	}
}

// method to return the inverse of a matrix if exists else zero vector
Matrix3 Matrix3::Inverse(Matrix3 M1)
{
	
	double det = Determinant(M1);
	if (det == 0)
		return Matrix3();
	else
	{
		double scale = 1 / det;
		Matrix3 answer;
		answer.A11 = scale * (M1.A22 * M1.A33 - M1.A23 * M1.A32); // ei-fh
		answer.A12 = scale * (M1.A13 * M1.A32 - M1.A12 * M1.A33); // ch-bi
		answer.A13 = scale * (M1.A12 * M1.A23 - M1.A13 * M1.A22); // ch-bi

		answer.A21 = scale * (M1.A23 * M1.A31 - M1.A21 * M1.A33); // fg-di
		answer.A22 = scale * (M1.A11 * M1.A33 - M1.A13 * M1.A31); // ai-cg
		answer.A23 = scale * (M1.A13 * M1.A21 - M1.A11 * M1.A23); // cd-af


		answer.A31 = scale * (M1.A21 * M1.A32 - M1.A22 * M1.A31); // dh-eg
		answer.A32 = scale * (M1.A12 * M1.A31 - M1.A11 * M1.A32); // bg-ah
		answer.A33 = scale * (M1.A11 * M1.A22 - M1.A12 * M1.A21); // ae-bd

		return answer;
	}

}

Matrix3 Matrix3::Rotation(double _angle)
{
	double radians = PI / 180 * _angle;
	Matrix3 answer;
	answer.A11 = cos(radians);
	answer.A12 = sin(radians);
	answer.A13 = 0;
	answer.A21 = -sin(radians);
	answer.A22 = cos(radians);
	answer.A23 = 0;
	answer.A31 = 0;
	answer.A32 = 0;
	answer.A33 = 1;

	return answer;
}

Matrix3 Matrix3::Translate(double dx, double dy)
{
	Matrix3 answer;
	answer.A11 = 1;
	answer.A12 = 0;
	answer.A13 = dx;
	answer.A21 = 0;
	answer.A22 = 1;
	answer.A23 = dy;
	answer.A31 = 0;
	answer.A32 = 0;
	answer.A33 = 1;

	return answer;
}

Matrix3 Matrix3::Scale(double dx, double dy)
{
	Matrix3 answer;
	answer.A11 = (double)dx / 100;
	answer.A12 = 0;
	answer.A13 = 0;
	answer.A21 = 0;
	answer.A22 = (double)dy / 100;
	answer.A23 = 0;
	answer.A31 = 0;
	answer.A32 = 0;
	answer.A33 = 1;

	return answer;
}

Matrix3 Matrix3::operator-()
{
	return{ A11 * -1, A12 * -1, A13 * -1, 
			A21 * -1, A22 * -1, A23 * -1, 
			A31 * -1, A32 * -1, A33 * -1 };
}

Matrix3 Matrix3::RotationX(double _angle)
{
	double radians = 3.14159 / 180 * _angle;
	Matrix3 answer;
	answer.A11 = 1;
	answer.A12 = 0;
	answer.A13 = 0;
	answer.A21 = 0;
	answer.A22 = cos(radians);
	answer.A23 = -sin(radians);
	answer.A31 = 0;
	answer.A32 = sin(radians);
	answer.A33 = cos(radians);

	return answer;
}

Matrix3 Matrix3::RotationY(double _angle)
{
	double radians = 3.14159 / 180 * _angle;
	Matrix3 answer;
	answer.A11 = cos(radians);
	answer.A12 = 0;
	answer.A13 = sin(radians);
	answer.A21 = 0;
	answer.A22 = 1;
	answer.A23 = 0;
	answer.A31 = -sin(radians);
	answer.A32 = 0;
	answer.A33 = cos(radians);

	return answer;
}

Matrix3 Matrix3::RotationZ(double _angle)
{
	double radians = 3.14159 / 180 * _angle;
	Matrix3 answer;
	answer.A11 = cos(radians);
	answer.A12 = -sin(radians);
	answer.A13 = 0;
	answer.A21 = sin(radians);
	answer.A22 = cos(radians);
	answer.A23 = 0;
	answer.A31 = 0;
	answer.A32 = 0;
	answer.A33 = 1;

	return answer;
}

Matrix3 Matrix3::Scale3D(double dx)
{
	Matrix3 answer;
	answer.A11 = (double)dx / 100;
	answer.A12 = 0;
	answer.A13 = 0;
	answer.A21 = 0;
	answer.A22 = (double)dx / 100;
	answer.A23 = 0;
	answer.A31 = 0;
	answer.A32 = 0;
	answer.A33 = (double)dx / 100;

	return answer;
}

Vector3 Matrix3::operator*(Vector3 V1)
{// An overloaded operator * to return the  product of the matrix by a vector
	return { static_cast<float>(A11) * V1.getX() + static_cast<float>(A12) * V1.getY() + static_cast<float>(A13) * V1.getZ(),
			 static_cast<float>(A21) * V1.getX() + static_cast<float>(A22) * V1.getY() + static_cast<float>(A23) * V1.getZ(),
			 static_cast<float>(A31) * V1.getX() + static_cast<float>(A32) * V1.getY() + static_cast<float>(A33) * V1.getZ() };
}

std::string Matrix3::toString()
{
	return ("\n" + this->Row(0).toString() + "\n" + this->Row(1).toString() + "\n" + this->Row(2).toString());
}
