#pragma once
#include "vec4.h"

//Think of the ray as a function : P(t) = A+tb
//P = a 3d position along a line in 3D
//A = the ray origin
//b = the ray direction
//t = a float in the code
//(only positive t wavlues will only give you parts in front of Ray (known as half ray))

namespace Renderer
{
	class Ray final
	{
	public:

		Ray() = default;

		~Ray() = default;

		Ray(const point4& origin, const Vec4& direction);

		point4 origin() const;

		Vec4 direction() const;

		//computes the funtion P(t)
		point4 at(float t) const;

	public:
		point4 _origin;
		Vec4 _dir;

	};
}

#include "ray.inl"