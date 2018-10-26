#include <vector>
#include <iostream>
#include <algorithm> 
#include <math.h>
using namespace std;
#include "Vector3D.h"
#include "Esfera.h"
#include "ViewPlane.h"
#include "Rayo.h"
#include "LuzPuntual.h"
#include "Utilitarios.h"
#include "Plano.h"

double acotar(double n)
{
    if ( n > 1.0)
    {
        return 1.0;
    }
    else
    {
        return n;
    }
}
ColorRGB obtenerColorPixel(const Rayo& r, vector<ObjetoGeometrico*> objetos, LuzPuntual luz){
    
    ColorRGB color;

    color.r = 0.0;
    color.g = 0.0;
    color.b = 0.0;

    double t;
    double tmin = 2000000;    
    Vector3D n;
    Punto3D q;

    Vector3D h;
    for(int i = 0; i < objetos.size(); i++) {
        if( objetos[i]->hayImpacto(r, t, n, q) && t < tmin){
           /*  color.r = luz.color.r * objetos[i]->obtenerColor().r * std::max(0.0, n * (luz.posicion - q).hat()) ;
             color.g = luz.color.g * objetos[i]->obtenerColor().g * std::max(0.0, n * (luz.posicion - q).hat());
             color.b = luz.color.b * objetos[i]->obtenerColor().b * std::max(0.0, n * (luz.posicion - q).hat());
          */  
            // h = ((-1)*r.d).hat();
            // color.r = luz.color.r * objetos[i]->obtenerColor().r * std::max(0.0, n * (luz.posicion - q).hat()) + luz.color.r * objetos[i]->obtenerColor().r * pow(max(0.0, n * h), 1000);
            // color.g = luz.color.g * objetos[i]->obtenerColor().g * std::max(0.0, n * (luz.posicion - q).hat()) + luz.color.r * objetos[i]->obtenerColor().r * pow(max(0.0, n * h), 1000);
            // color.b = luz.color.b * objetos[i]->obtenerColor().b * std::max(0.0, n * (luz.posicion - q).hat()) + luz.color.r * objetos[i]->obtenerColor().r * pow(max(0.0, n * h), 1000);

            h = ((-1)*r.d).hat();
            color.r = acotar( 0.1 + luz.color.r * objetos[i]->obtenerColor().r * std::max(0.0, n * (luz.posicion - q).hat()) + luz.color.r * objetos[i]->obtenerColor().r * pow(max(0.0, n * h), 1000));
            color.g = acotar( 0.1 + luz.color.g * objetos[i]->obtenerColor().g * std::max(0.0, n * (luz.posicion - q).hat()) + luz.color.r * objetos[i]->obtenerColor().r * pow(max(0.0, n * h), 1000));
            color.b = acotar( 0.1 + luz.color.b * objetos[i]->obtenerColor().b * std::max(0.0, n * (luz.posicion - q).hat()) + luz.color.r * objetos[i]->obtenerColor().r * pow(max(0.0, n * h), 1000));

            tmin = t;
        }
    }
    return color;
}

int main()
{
    double sm=2;
    double alt=200;
    // LUZ ----------------------------------------------------------------------------------------------
    //LuzPuntual luz(1.0, 1.0, 1.0, -200, -400, -300);
    LuzPuntual luz(1.0, 1.0, 1.0, 0.0, 200, 0.0);
    // ESCENA--------------------------------------------------------------------------------------------
    /////OREJAS INICIO
    Punto3D centro1(16.6*sm, (33.3*sm)+alt, -900.0);
    double radio1 = 8.33*sm;
    Esfera esfera1(centro1, radio1);   
    esfera1.establecerColor(0.36, 0.231, 0.17);

    Punto3D centro3(-16.6*sm, (33.3*sm)+alt, -900.0);
    double radio3 = 8.33*sm;
    Esfera esfera3(centro3, radio3);   
    esfera3.establecerColor(0.36, 0.231, 0.17);
    ////OREJAS FIN
    ///OREJAS INTERIOR INICIO
    Punto3D centro4(15.1*sm, (31.6*sm)+alt, -850.0);
    double radio4 = 4.16*sm;
    Esfera esfera4(centro4, radio4);   
    esfera4.establecerColor(1.0, 0.3, 0.3);

    Punto3D centro5(-15.1*sm, (31.6*sm)+alt, -850.0);
    double radio5 = 4.16*sm;
    Esfera esfera5(centro5, radio5);   
    esfera5.establecerColor(1.0, 0.3, 0.3);
    ///OREJAS INTERIOR FIN

    ///ojos
    Punto3D centro6(10*sm, (10.0*sm)+alt, -400.0);
    double radio6 = 3*sm;
    Esfera esfera6(centro6, radio6);   
    esfera6.establecerColor(0, 0, 0);

    Punto3D centro7(-10*sm, (10.0*sm)+alt, -400.0);
    double radio7 = 3*sm;
    Esfera esfera7(centro7, radio7);   
    esfera7.establecerColor(0, 0, 0);

    //iris
    Punto3D centro8(10*sm, (10.0*sm)+ alt, 1);
    double radio8 = 1.6*sm;
    Esfera esfera8(centro8, radio8);   
    esfera8.establecerColor(0,1,0);

    Punto3D centro9(-10*sm, (10.0*sm) + alt, 1);
    double radio9 = 1.6*sm;
    Esfera esfera9(centro9, radio9);   
    esfera9.establecerColor(0,1, 0);
    //iris
    //ojos fin

    //boca ini
    Punto3D centro11(0.0, -20+0.0+alt, -400.0);
    double radio11 = 10*sm;
    Esfera esfera11(centro11, radio11);   
    esfera11.establecerColor(0, 0, 0);

    Punto3D centro12(0.0, -20+0.0+alt, -300.0);
    double radio12 = 5*sm;
    Esfera esfera12(centro12, radio12);   
    esfera12.establecerColor(1, 0, 0);


    //boca fin

    Punto3D centro2(0.0, 0.0+alt, -800.0);
    double radio2 = 33.3*sm;
    Esfera esfera2(centro2, radio2);   
    esfera2.establecerColor(0.36, 0.231, 0.17);

    Punto3D centro10(0.0, -80-(sm*33.3)+alt, -900.0);
    double radio10 = 60*sm;
    Esfera esfera10(centro10, radio10);   
    esfera10.establecerColor(0.36, 0.231, 0.17);
    
    //Plano
    Punto3D p(0, 0.0, -10000.0);
    Vector3D q(0, 1.0, 1.0);
    Plano plano(p, q.hat());
    plano.establecerColor(1.0, 1.0, 0.0);
    
    //fin plano
    /*Punto3D a(0, 150, 0);
    Vector3D b(0, 1.0, 1.0);
    Plano plano1(a, b.hat());
    plano1.establecerColor(0.0, 0.0, 246.0);*/

    vector<ObjetoGeometrico*> escena;
    ///cara
    escena.push_back(&esfera2);
    ////orejas 
    escena.push_back(&esfera1);
    escena.push_back(&esfera3);

    escena.push_back(&esfera4);
    escena.push_back(&esfera5);
    ///fin orejas
    ///inicio ojos
    escena.push_back(&esfera6);
    escena.push_back(&esfera7);
    //iris
    escena.push_back(&esfera8);
    escena.push_back(&esfera9);
    //fin iris
    ///fin ojos

    //curpito
    escena.push_back(&esfera10);

    //boca
    escena.push_back(&esfera11);
    escena.push_back(&esfera12);
   
    ColorRGB color_pixel;
    //plano
    escena.push_back(&plano);
   //escena.push_back(&plano1);

    // VIEWPLANE----------------------------------------------------------------------------------------
    int hres = 800;
    int vres = 600;
    double s = 1.0;
    ViewPlane vp(hres, vres, s);

    // UTILITARIO PARA GUARDAR IMAGEN -------------------------------------------------------------------
    int dpi = 72;
    int width = vp.hres;
    int height = vp.vres;
    int n = width * height;
    ColorRGB* pixeles = new ColorRGB[n];
    


    // --------------------------------------------------------------------------------------------------
    for(int fil = 0; fil < vp.vres; fil++)
    {
        for ( int col = 0; col < vp.hres; col++) 
        {
             // Disparar un rayo
            Vector3D direccion(0.0, 0.0, -1.0);
            double x_o = vp.s * ( col - vp.hres/2 + 0.5 );
            double y_o = vp.s * ( fil - vp.vres/2 + 0.5 );
            double z_o = 100;
            Punto3D origen(x_o, y_o, z_o);
            Rayo rayo(origen, direccion);

            color_pixel = obtenerColorPixel(rayo, escena, luz);

            pixeles[fil*width+col].r = color_pixel.r;
            pixeles[fil*width+col].g = color_pixel.g;
            pixeles[fil*width+col].b = color_pixel.b;
        }
    }    
    savebmp("img.bmp", width, height, dpi, pixeles);
    return 0;
}
