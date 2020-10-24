#define COLOR_H

#include "vec3.h"

void writeColor(std::ostream &out, color pixel_color){
    
    
        out << static_cast<int>(255.999 * pixel_color.x()) << ' '
        << static_cast<int>(255.999 * pixel_color.y()) << ' '
        << static_cast<int>(255.999 * pixel_color.z()) << '\n';
    
}