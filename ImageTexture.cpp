
#include "ImageTexture.h"
#include <iostream>


ImageTexture::ImageTexture(void){
		hres=100;
		vres=100;
		image_ptr=nullptr;
		index=0;
}

ImageTexture::ImageTexture(Image* _image_ptr)
{
	hres=_image_ptr->get_hres();
	vres=_image_ptr->get_vres();
	image_ptr=_image_ptr;
	index=0;
}

ImageTexture& 
ImageTexture::operator= (const ImageTexture& rhs) {
	hres = rhs.hres;
	vres = rhs.vres;
	std::cout<<"Pasa h y v\n";
	image_ptr=rhs.image_ptr;
	std::cout<<"Pasa igual: "<< image_ptr <<" y "<<rhs.image_ptr<<"\n";
	
	
}

ImageTexture::~ImageTexture(){
	
}

ColorRGB														
ImageTexture::get_color() {	
	index++;
	return (image_ptr->get_color(index));
}





