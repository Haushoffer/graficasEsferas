#include "Esfera.h"
#include<iostream>
#include <cmath>

using namespace std;
Esfera::Esfera(Punto3D v_c, double v_r):c( v_c), r( v_r)
{ 
    color.r = 1.0;
    color.g = 1.0;
    color.b = 0.0;
}
Esfera::~Esfera(){}
bool Esfera::hayImpacto(const Rayo& rayo, double& tmin) const
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
        discriminante = sqrt(discriminante);
        double t0 = -b-discriminante;
        if(t0 > 0){
            tmin = t0;
            return true;
        }
        double t1 = -b+discriminante;
        if(t1 > 0){
            tmin = t1;
            return true;
        }
        return false;
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