
#pragma once

#include <vector>		
#include "ColorRGB.h"
using namespace std;



class Image {	
	public:
	
		Image(void);								

		Image(const Image& image);					

		Image& 										
		operator= (const Image& image);		

		~Image(void) ;								
		
		void										
		read_ppm_file(const char* file_name);
		
		int
		get_hres(void);	
		
		int
		get_vres(void);	
				
		ColorRGB									
		get_color(int& index);		
		
	private:
		int 				hres;	
		int					vres;		
		vector<ColorRGB> 	pixels;
};

inline int
Image::get_hres(void) {
	return (hres);
}




inline int
Image::get_vres(void) {
	return (vres);
}
