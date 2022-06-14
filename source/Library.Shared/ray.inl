#include "ray.h"

namespace Renderer 
{
	inline Ray::Ray(const point4& origin, const Vec4& direction) :
		_origin(origin), _dir(direction)
	{

	}

	inline point4 Ray::origin() const
	{
		return _origin;
	}

	inline Vec4 Ray::direction() const
	{
		return _dir;
	}

	inline point4 Ray::at(float t) const
	{
		return _origin + t*_dir;
	}


}