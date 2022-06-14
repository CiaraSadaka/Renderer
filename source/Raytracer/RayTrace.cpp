#include "pch.h"
#include "Raytrace.h"

using namespace std; 

namespace Renderer
{
    //write pixel data to a file
    void write_color(std::ostream& out, color pixel_color)
    {
        // Write the translated [0,255] value of each color component.
        out << static_cast<int>(255.999 * pixel_color.x()) << ' '
            << static_cast<int>(255.999 * pixel_color.y()) << ' '
            << static_cast<int>(255.999 * pixel_color.z()) << '\n';
    }



    void HelloWorldGradient()
    {

        //render "hello world image"
             // Image

        const int image_width = 256;
        const int image_height = 256;

        // Render

        ofstream imageFile;
        imageFile.open("HelloWorld.ppm");
        imageFile << "P3\n" << image_width << ' ' << image_height << "\n255\n";


        std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

        for (int j = image_height - 1; j >= 0; --j) {
            std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
            for (int i = 0; i < image_width; ++i) {
                color pixel_color(float(i) / (image_width - 1), float(j) / (image_height - 1), 0.25, 1);
                write_color(imageFile, pixel_color);
            }
        }

        imageFile.close();

        std::cerr << "\nDone.\n";
    }

    /*bool hit_sphere(const point4& center, float radius, const Ray& r) {
        Vec4 oc = r.origin() - center;
        auto a = dot(r.direction(), r.direction());
        auto b = 2.0 * dot(oc, r.direction());
        auto c = dot(oc, oc) - radius * radius;
        auto discriminant = b * b - 4 * a * c;
        return (discriminant > 0);
    }*/
    float hit_sphere(const point4& center, float radius, const Ray& r) {
        Vec4 oc = r.origin() - center;
        float a = dot(r.direction(), r.direction());
        float b = (float)2.0 *(float) dot(oc, r.direction());
        float c = dot(oc, oc) - radius * radius;
        auto discriminant = b * b - 4 * a * c;
        if (discriminant < 0) 
        {
            return -1.0;
        }
        else 
        {
            return (-b - sqrt(discriminant)) / (float)(2.0 * a);
        }

    }

   /* color ray_color(const Ray& r)
   {
        if (hit_sphere(point4(0, 0, -1, 1), 0.5, r))
            return color(1, 0, 0, 0);
        Vec4 unit_direction = unit_vector(r.direction());
        float t = (float)(0.5 * (unit_direction.y() + 1.0));
        return ((float)1.0 - t) * color(1.0, 1.0, 1.0, 1.0) + t * color(0.5, (float)0.7, 1.0, 1.0);

    }*/

    color ray_color(const Ray& r)
    {
        auto t = hit_sphere(point4(0, 0, -1, 1), 0.5, r);
        if (t > 0.0) {
            Vec4 N = unit_vector(r.at(t) - Vec4(0, 0, -1, 1));
            return 0.5 * color(N.x() + 1, N.y() + 1, N.z() + 1, 1);
        }
        Vec4 unit_direction = unit_vector(r.direction());
        t = (float)0.5 * (float)(unit_direction.y() + 1.0);
        return ((float)1.0 - t) * color(1.0, 1.0, 1.0, 1.0) + t * color(0.5, (float)0.7, 1.0, 1.0);
    }

    void BlueGrayGradient()
    {
        // render blue white gradient

        // Image
        const float aspect_ratio = (float)(16.0 / 9.0);
        const int image_width = 400;
        const int image_height = static_cast<int>(image_width / aspect_ratio);


        // Camera
        //cam center at (0,0,0) and y go in to the right

        float viewport_height = 2.0;
        float viewport_width = aspect_ratio * viewport_height;
        float focal_length = 1.0;

        auto origin = point4(0, 0, 0, 0);
        auto horizontal = Vec4(viewport_width, 0, 0, 0);
        auto vertical = Vec4(0, viewport_height, 0, 0);
        auto lower_left_corner = origin - horizontal / 2 - vertical / 2 - Vec4(0, 0, focal_length, 0);

        // Render
        ofstream imageFile;
        imageFile.open("Sphere2.ppm");
        imageFile << "P3\n" << image_width << ' ' << image_height << "\n255\n";

        std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

        for (int j = image_height - 1; j >= 0; --j) {
            std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
            for (int i = 0; i < image_width; ++i) {
                auto u = float(i) / (image_width - 1);
                auto v = float(j) / (image_height - 1);
                Ray r(origin, lower_left_corner + u * horizontal + v * vertical - origin);
                color pixel_color = ray_color(r);
                write_color(imageFile, pixel_color);
            }
        }

        imageFile.close();
        std::cerr << "\nDone.\n";
    }


}