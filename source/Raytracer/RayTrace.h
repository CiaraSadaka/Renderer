#pragma once
#include "pch.h"
#include "vec4.h"
#include "ray.h"
#include <cmath>
namespace Renderer
{
	void write_color(std::ostream& out, color pixel_color);

	//makes a file hello world with simple gradient
	void HelloWorldGradient();

	//returns true if that ray hits the sphere
	float hit_sphere(const point4& center, float radius, const Ray& r);

	//returns the rolor of a ray at a point
	color ray_color(const Ray& r);

	//makes a file called Sphere with a blue-grey gradient background and a Sphere.
	void BlueGrayGradient();
}
