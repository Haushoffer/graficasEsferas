
#pragma once

#include "Image.h"


class ImageTexture {	
	public:

	
		ImageTexture(void);									
			
		ImageTexture(Image* _image_ptr);					
				
		ImageTexture(const ImageTexture& it);				

		ImageTexture& 										
		operator= (const ImageTexture& rhs);		
			

		virtual
		~ImageTexture(void) ;								
		
		virtual ColorRGB																				
		get_color();
						
		void
		set_image(Image* _image_ptr);

		void setU(int ru);

		void setV(int rv);
	public:	
	    int index;
		int 		hres;		
		int			vres;		
		Image*		image_ptr;		
};



inline void
ImageTexture::set_image(Image* _image_ptr) {
	image_ptr = _image_ptr;
	hres = image_ptr->get_hres();
	vres = image_ptr->get_vres();
}


