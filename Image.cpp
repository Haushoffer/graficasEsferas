
#include <iostream>
#include <stdio.h>

#include "Image.h"



Image::Image(void)
	:	hres(100),
		vres(100)
{}

							

Image::Image(const Image& image)
	:	hres(image.hres),
		vres(image.vres),
		pixels(image.pixels)
{}		



Image& 										
Image::operator= (const Image& rhs) {
	if (this == &rhs)
		return (*this);
	
	hres 		= rhs.hres;
	vres 		= rhs.vres;
	pixels 		= rhs.pixels;

	return (*this);
}		



Image::~Image(void)	{}
	


void										
Image::read_ppm_file(const char* file_name) {


    
    FILE* file = fopen(file_name, "rb");
    
    if (file == 0){
		cout << "could not open file" << endl;
	}
	else
		cout << "file opened" << endl;


    
    unsigned char ppm_type;
    if (fscanf(file, "P%c\n", &ppm_type) != 1){
		cout << "Invalid PPM signature" << endl;
	}
	

    
    if (ppm_type != '6'){
		cout << "Only binary PPM supported" << endl;
	}


    
    unsigned char dummy;
    while (fscanf(file ,"#%c", &dummy)) 
        while (fgetc(file) != '\n');


    
    if (fscanf(file, "%d %d\n", &hres, &vres) != 2){
		cout << "Invalid image size" << endl;
	}

    if (hres <= 0)
		cout << "Invalid image width" << endl;
	else
		cout << "hres = " << hres << endl;

    
	if (vres <= 0)
		cout << "Invalid image height" << endl;
	else
		cout << "vres = " << vres << endl;


    
    unsigned int max_value;
    if (fscanf(file, "%d\n", &max_value) != 1){
		cout << "Invalid max value" << endl;
	}

	float inv_max_value = 1.0 / (float)max_value;
  
	pixels.reserve(hres * vres);


    
    for (unsigned int y = 0; y < vres; y++) {
        for (unsigned int x = 0; x < hres; x++) {
            unsigned char red;
            unsigned char green;
            unsigned char blue;
            
            if (fscanf(file, "%c%c%c", &red, &green, &blue) != 3) {
				cout << "Invalid image" << endl;
			}

			float r = red   * inv_max_value;
			float g = green * inv_max_value;
			float b = blue  * inv_max_value;
			
			ColorRGB aux;
			aux.r=r;
			aux.g=g;
			aux.b=b;
			pixels.push_back(aux);
        }
    }


    
    fclose(file);
	
	cout << "finished reading PPM file" << endl;
	cout<<"Tamano es "<< pixels.size()<<std::endl; 
}





ColorRGB Image::get_color(int& index){
	int pixels_size = pixels.size();
	ColorRGB red;
	red.r=1;red.g=0;red.b=0;
	
	if (index < pixels_size && index >= 0){
		return (pixels[index]);
	}
	else
		return (red); 
}
