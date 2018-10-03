#include "Esfera.h"
#include<iostream>
using namespace std;
Esfera::Esfera(Punto3D v_c, double v_r):c( v_c), r( v_r)
{ 
    color.r = 1.0;
    color.g = 1.0;
    color.b = 0.0;
}
Esfera::~Esfera(){}
bool Esfera::hayImpacto(const Rayo& rayo) const
{
    Vector3D temp = rayo.o - c;
    double a = rayo.d * rayo.d;
    double b = 2 * rayo.d * temp;
    double c = temp * temp  -  r * r ;
    double discriminante = b * b - 4.0 * a * c;
    if ( discriminante < 0.0 )
    {
        return false;
    } 
    else
    {
        return true;
    }
}
void Esfera::setColor(double r, double g, double b){
    color.r=r;
    color.g=g;
    color.b=b;
}

ColorRGB Esfera::obtenerColor()
{
    ColorRGB c;
    c.r = color.r;
    c.g = color.g;
    c.b = color.b;
    return  c;
}