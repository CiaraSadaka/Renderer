#pragma once

#include <stdio.h>
#include <cmath>
#include <iomanip>
#include <iostream>




namespace Renderer
{
	class Vec4 final
	{
	private:
		float _values[4]; //{x, y, z, alpha}

	public:

		
		/// <summary>
		/// The constructor for Vec4.
		/// </summary>
		Vec4(float e0, float e1, float e2, float e3);

		/// <summary>
		/// Deconstructor for Vec4.
		/// </summary>
		~Vec4() = default;

		/// <summary>
		/// copy constructor
		/// </summary>
		/// <param name="other">the Vec4 to copy</param>
		Vec4(const Vec4& other)= default;

		/// <summary>
		/// assignment operator
		/// </summary>
		Vec4& operator =(const Vec4& other) = default;

		/// <summary>
		/// move constructor
		/// </summary>
		Vec4(Vec4&& other) = default;

		/// <summary>
		/// move assignment operator
		/// </summary>
		Vec4& operator =(Vec4&& other) = default;

		/// <summary>
		/// returns the X value of the vec4
		/// </summary>
		/// <returns>the first item in the Vec4</returns>
		float x() const;

		/// <summary>
		/// returns the y value of the vec4
		/// </summary>
		/// <returns>the second item in the Vec4</returns>
		float y() const;

		/// <summary>
		/// returns the Z value of the vec4
		/// </summary>
		/// <returns>the third item in the Vec4</returns>
		float z() const;

		/// <summary>
		/// returns the alpha value of the vec4
		/// </summary>
		/// <returns>the last item in the Vec4</returns>
		float a() const;

		/// <summary>
		/// negates all values
		/// </summary>
		/// <returns></returns>
		Vec4 operator-() const;

		/// <summary>
		/// takes an index and returns the item there in the Vec4
		/// </summary>
		/// <param name="i"> integer (0-3)</param>
		/// <returns>a float</returns>
		float operator[](int i) const;

		/// <summary>
		/// takes an index and returns the item there in the vec4
		/// </summary>
		/// <param name="i"> integer (0-3)</param>
		/// <returns>a refernec to the item</returns>
		float& operator[](int i);

		/// <summary>
		/// Adds two vec4 item by item. 
		/// </summary>
		/// <param name="v">the constant second vec4 to add</param>
		/// <returns>a reference to the result vec4</returns>
		Vec4& operator+=(const Vec4& v);

		/// <summary>
		/// Multiplies a Vec4 by a scaler
		/// </summary>
		/// <param name="t"> the constant scalar</param>
		/// <returns>a reference to the result vec4</returns>
		Vec4& operator*=(const float t);

		/// <summary>
		/// divides the Vec4 by a scalar
		/// </summary>
		/// <param name="t"> the constant scalar</param>
		/// <returns>a reference to the result vec4 </returns>
		Vec4& operator/=(const float t);

		/// <summary>
		/// squares each element in the vec4 with itself and then adds them
		/// </summary>
		/// <returns>the legth</returns>
		float length() const;

		/// <summary>
		/// squares each element in the vec4 with itself
		/// </summary>
		/// <returns>the length of the Vec4 squared</returns>
		float length_squared() const;



	};

	
	using point4 = Vec4;
	using color = Vec4;

	std::ostream& operator<<(std::ostream& out, const Vec4& v);

	Vec4 operator+(const Vec4& u, const Vec4& v);

	Vec4 operator-(const Vec4& u, const Vec4& v);

	Vec4 operator*(const Vec4& u, const Vec4& v);

	Vec4 operator*(float t, const Vec4& v);

	Vec4 operator*(const Vec4& v, float t);

	Vec4 operator/(Vec4 v, float t);

	float dot(const Vec4& u, const Vec4& v);

	Vec4 cross(const Vec4& u, const Vec4& v);

	Vec4 unit_vector(Vec4 v);

	//void write(std::ofstream& imageFile, Vec4);

}

#include "vec4.inl"



