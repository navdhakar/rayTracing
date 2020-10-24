#include <iostream>

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
    
            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);
            std::cout<<ir<<' '<<ig<<' '<<ib<<'\n';

            }
        }
     std::cerr<<"\nDone"<<std::endl;
}