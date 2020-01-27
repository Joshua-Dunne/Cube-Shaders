#ifndef VECTOR3_H
#define VECTOR3_H

#include <iostream>
#include <math.h>
#include <string>
#include "Matrix3.h"

class Matrix3;

class Vector3
{
public:
	// default constructor
	Vector3() :
		  m_x(0.0f)
		, m_y(0.0f)
		, m_z(0.0f)
	{

	}

	// To allow other values for X, Y and Z to be declared
	Vector3(float x1, float y1, float z1) :
		  m_x(x1)
		, m_y(y1)
		, m_z(z1)
	{
	}

	//// To allow other values for X, Y and Z to be declared
	//Vector3(const Vector3& t_v) :
	//	m_x(t_v.m_x)
	//	, m_y(t_v.m_y)
	//	, m_z(t_v.m_z)
	//{
	//}


private:
	// The class has three variables x, y and z 
	float m_x;
	float m_y;
	float m_z;

public:

	float getX() const { return m_x; };
	void setX(float t_x) { m_x = t_x; };

	float getY() const { return m_y; };
	void setY(float t_y) { m_y = t_y; };

	float getZ() const { return m_z; };
	void setZ(float t_z) { m_z = t_z; };

	/// <summary>
	/// A method to return the length of the vector 
	/// </summary>
	/// <returns>Length of vector</returns>
	inline float length() const
	{
		return sqrt(lengthSquared());
	}

	/// <summary>
	/// A method to return the length squared of the vector
	/// </summary>
	/// <returns>Squared length of vector</returns>
	inline float lengthSquared() const
	{
		return (m_x * m_x + m_y * m_y + m_z * m_z);
	}

	/// <summary>
	/// A method to reduce the length of the vector to 1.0 
	/// keeping the direction the same 
	/// </summary>
	/// <returns>Normalised Vector3</returns>
	Vector3 normalise();

	std::string toString();

	Vector3 operator+(const Vector3 t_addVector) const;
	Vector3 operator-(const Vector3 t_subVector) const;
	void operator-();
	float operator *(Vector3 m_scalarVector) const;
	Vector3 operator *(float k) const;
	Vector3 operator ^(Vector3 t_vector) const;

	Vector3 operator *(Matrix3 M1);
};

#endif