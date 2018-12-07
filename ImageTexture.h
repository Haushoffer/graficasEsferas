
#pragma once

#include "Image.h"


class ImageTexture {	
	public:

	
		ImageTexture(void);									
			
		ImageTexture(Image* _image_ptr);					
	
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

