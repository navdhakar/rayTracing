#include <iostream>
#include "color.h"

int main(){
    auto aspectRatio = 16.0/9.0;
    auto imageWidth = 400;
    auto imageHieght = imageWidth/aspectRatio;
        std::cout << "P3\n" << imageWidth << " " << imageHieght << "\n255\n";
        for(int i = imageHieght-1; i>=0; --i){
            std::cerr<<"\rrendering:"<<i<<' '<<std::flush;
            for(int j=0; j<=imageWidth-1; ++j){

            auto r = double(i) / (imageWidth-1);
            auto g = double(j) / (imageHieght-1);
            auto b = 0.25;
            color pixel_color(double(i)/(imageWidth-1), double(j)/(imageHieght-1), 0.25);
            writeColor(std::cout, pixel_color);

            }
        }
     std::cerr<<"\nDone"<<std::endl;
}