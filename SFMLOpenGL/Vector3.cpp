#include "Vector3.h"

/// <summary>
/// A method to reduce the length of the vector to 1.0 
/// keeping the direction the same 
/// </summary>
/// <returns>Normalised Vector3</returns>
Vector3 Vector3::normalise()
{
	Vector3 normalised = *this;

	if (normalised.length() > 0.0)
	{  // Check for divide by zero
		double magnit = normalised.length();
		normalised.m_x /= static_cast<float>(magnit);
		normalised.m_y /= static_cast<float>(magnit);
		normalised.m_z /= static_cast<float>(magnit);
	}
	else
	{
		std::cout << "length <= 0.0" << std::endl;
		normalised = Vector3{ 0,0,0 }; // return empty vector3 if length is 0 or less
	}

	return normalised;
}

std::string Vector3::toString()
{
	return "(" + std::to_string(m_x) + "," 
			   + std::to_string(m_y) + "," 
			   + std::to_string(m_z) + ")";
}

/// <summary>
/// An overloaded operator + to return the sum of 2 vectors
/// </summary>
/// <param name="t_addVector">Vector to add to</param>
/// <returns>sum of 2 vectors</returns>
Vector3 Vector3::operator+(const Vector3 t_addVector) const
{
	return { m_x + t_addVector.getX(), m_y + t_addVector.getY(), m_z + t_addVector.getZ() };
}

/// <summary>
/// An overloaded operator - to return the difference of 2 vectors
/// </summary>
/// <param name="t_subVector">Vector 1</param>
/// <param name="V2">Vector 2</param>
/// <returns>difference of 2 vectors</returns>
Vector3 Vector3::operator-(const Vector3 t_subVector) const
{
	return { m_x - t_subVector.getX(), m_y - t_subVector.getY(), m_z - t_subVector.getZ() };
}



/// <summary>
/// An overloaded operator - to return the negation of a single vector
/// </summary>
/// <param name="V">Vector 1</param>
/// <returns>negation of a single vector</returns>
void Vector3::operator -()
{
	this->setX(this->getX() * -1);
	this->setY(this->getY() * -1);
	this->setZ(this->getZ() * -1);
}

/// <summary>
/// An overloaded operator * to return the scalar product of 2 vectors
/// </summary>
/// <param name="m_scalarVector">Vector 1</param>
/// <returns>scalar product of 2 vectors</returns>
float Vector3::operator *(Vector3 m_scalarVector) const
{
	return (m_x * m_scalarVector.getX() + m_y * m_scalarVector.getY() + m_z * m_scalarVector.getZ());
}

/// <summary>
/// An overloaded operator * to return the product of a scalar by a vector (using float)
/// </summary>
/// <param name="k">Scalar</param>
/// <param name="V1">Vector 1</param>
/// <returns>product of a scalar by a vector</returns>
Vector3 Vector3::operator *(float k) const
{
	return { m_x * k, m_y * k, m_z * k };
}

/// <summary>
/// An overloaded operator ^ to return the vector product of 2 vectors
/// </summary>
/// <param name="t_vector">Vector 2</param>
/// <returns>Vector product of 2 vectors</returns>
Vector3 Vector3::operator ^(Vector3 t_vector) const
{
	return {  m_y * t_vector.getZ() - m_z * t_vector.getY(),
			  m_z* t_vector.getX() - m_x * t_vector.getZ(),
			  m_x * t_vector.getY() - m_y * t_vector.getX() 
		   };
}

Vector3 Vector3::operator*(Matrix3 M1)
{// An overloaded operator * to return the  product of the matrix by a vector
	return Vector3(M1.Row(0).m_x * m_x + M1.Row(0).m_y * m_y + M1.Row(0).m_z * m_z,
				   M1.Row(1).m_x * m_x + M1.Row(1).m_y * m_y + M1.Row(0).m_z * m_z,
				   M1.Row(2).m_x * m_x + M1.Row(2).m_y * m_y + M1.Row(0).m_z * m_z);
}
