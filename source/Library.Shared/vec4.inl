#include "Vec4.h" 


namespace Renderer
{
	inline Vec4::Vec4(float e0, float e1, float e2, float e3) :
		_values{ e0, e1, e2, e3 }
	{

	}

	inline float Vec4::x() const
	{
		return _values[0];
	}

	inline float Vec4::y() const
	{
		return _values[1];
	}

	inline float Vec4::z() const
	{
		return _values[2];
	}

	inline float Vec4::a() const
	{
		return _values[3];
	}

	inline Vec4 Vec4::operator-() const
	{
		return Vec4(-_values[0], -_values[1], -_values[2], -_values[3]);
	}

	inline float Vec4::operator[](int i) const
	{
		return _values[i];
	}

	inline float& Vec4::operator[](int i)
	{
		return _values[i];
	}

	inline Vec4& Vec4::operator+=(const Vec4& v)
	{
		_values[0] += v._values[0];
		_values[1] += v._values[1];
		_values[2] += v._values[2];
		_values[3] += v._values[3];
		return *this;
	}

	inline Vec4& Vec4::operator*=(const float t)
	{
		_values[0] *= t;
		_values[1] *= t;
		_values[2] *= t;
		_values[3] *= t;
		return *this;
	}

	inline Vec4& Vec4::operator/=(const float t)
	{
		return *this *= 1 / t;
	}

	inline float Vec4::length() const
	{
		return sqrtf(length_squared());
	}

	inline float Vec4::length_squared() const
	{
		return _values[0] * _values[0] + _values[1] * _values[1] + _values[2] * _values[2] + _values[3] * _values[3];
	}


	//Vector Utility functions

	inline std::ostream& operator<<(std::ostream& cout, const Vec4& v)
	{
		return cout << v[0] << ' ' << v[1] << ' ' << v[2] << ' ' << v[3];
	}

	inline Vec4 operator+(const Vec4& u, const Vec4& v)
	{
		return Vec4(u[0] + v[0], u[1] + v[1], u[2] + v[2], u[3] + v[3]);
	}

	inline Vec4 operator-(const Vec4& u, const Vec4& v) 
	{
		return Vec4(u[0] - v[0], u[1] - v[1], u[2] - v[2], u[3] - v[3]);
	}

	inline Vec4 operator*(const Vec4& u, const Vec4& v) 
	{
		return Vec4(u[0] * v[0], u[1] * v[1], u[2] * v[2], u[3] * v[3]);
	}

	inline Vec4 operator*(float t, const Vec4& v) 
	{
		return Vec4(t * v[0], t * v[1], t * v[2], t * v[3]);
	}

	inline Vec4 operator*(const Vec4& v, float t) 
	{
		return t * v;
	}

	inline Vec4 operator/(Vec4 v, float t) {
		return (1 / t) * v;
	}

	inline float dot(const Vec4& u, const Vec4& v)
	{
		return u[0] * v[0]
			+ u[1] * v[1]
			+ u[2] * v[2];
		//	+ u[3] * v[3];
	}

	inline Vec4 cross(const Vec4& u, const Vec4& v) 
	{
		return Vec4(u[1] * v[2] - u[2] * v[1],
					u[2] * v[0] - u[0] * v[2],
					u[0] * v[1] - u[1] * v[0], 
					(u[3] + v[3])/2);
	}

	inline Vec4 unit_vector(Vec4 v)
	{
		return v / v.length();
	}


}