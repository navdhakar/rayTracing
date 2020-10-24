#include <iostream>
#include "color.h"
#include "ray.h"
bool hitSphere(const point3& center, double radius, const ray& r){
    vec3 oc = r.origin() - center;
    auto a = dot(r.direction(), r.direction());
    auto b = 2.0 * dot(oc, r.direction());
    auto c = dot(oc, oc) - radius*radius;
    auto discriminant = b*b - 4*a*c;
    return (discriminant > 0);
}
color rayColor(const ray& r){
    if(hitSphere(point3(0,0,-1), 0.5, r))
        return color(0,1,0);
    
    vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
}
int main(){
    auto aspectRatio = 16.0/9.0;
    const int imageWidth = 400;
    const int imageHieght = static_cast<int>(imageWidth / aspectRatio);
    //CAMERA
    auto viewport_height = 2.0;
    auto viewport_width = aspectRatio * viewport_height;
    auto focal_length = 1.0;

    auto origin = point3(0, 0, 0);
    auto horizontal = vec3(viewport_width, 0, 0);
    auto vertical = vec3(0, viewport_height, 0);
    auto lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0, 0, focal_length);
       
        std::cout << "P3\n" << imageWidth << " " << imageHieght << "\n255\n";
        for(int i = imageHieght-1; i>=0; --i){
            std::cerr<<"\rrendering:"<<i<<' '<<std::flush;
            for(int j=0; j<imageWidth-1; ++j){

            auto u = double(j) / (imageWidth-1);
            auto v = double(i) / (imageHieght-1);
            ray r(origin, lower_left_corner + u*horizontal + v*vertical - origin);
            color pixel_color = rayColor(r);
            
            writeColor(std::cout, pixel_color);

            }
        }
     std::cerr<<"\nDone"<<std::endl;
}