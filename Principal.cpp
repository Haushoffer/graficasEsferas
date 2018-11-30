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
#include "Triangulo.h"

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
    LuzPuntual luz(1.0, 1.0, 1.0, 0.0, 50, 0.0);
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
    esfera10.establecerColor(0.36, 0.231, 0.10);
    //esfera focos
    Punto3D centro13(100*sm, (33.3*sm)+alt, -900.0);
    double radio13 = 15.33*sm;
    Esfera esfera13(centro13, radio13);   
    esfera13.establecerColor(0, 0, 0);

    Punto3D centro14(-100*sm, (33.3*sm)+alt, -900.0);
    double radio14 = 15.33*sm;
    Esfera esfera14(centro14, radio14);   
    esfera14.establecerColor(0, 0, 0);

    Punto3D centro15(100*sm, (33.3*sm)+alt, -850.0);
    double radio15 = 4.33*sm;
    Esfera esfera15(centro15, radio15);   
    esfera15.establecerColor(0.29, 0.99, 0.11);

    Punto3D centro16(-100*sm, (33.3*sm)+alt, -850.0);
    double radio16 = 4.33*sm;
    Esfera esfera16(centro16, radio16);   
    esfera16.establecerColor(0.29, 0.99, 0.11);

    Punto3D centro17(180*sm, (33.3*sm)+alt, -900.0);
    double radio17 = 15.33*sm;
    Esfera esfera17(centro17, radio17);   
    esfera17.establecerColor(0, 0, 0);

    Punto3D centro18(-180*sm, (33.3*sm)+alt, -900.0);
    double radio18 = 15.33*sm;
    Esfera esfera18(centro18, radio18);   
    esfera18.establecerColor(0, 0, 0);

    Punto3D centro19(180*sm, (33.3*sm)+alt, -850.0);
    double radio19 = 4.33*sm;
    Esfera esfera19(centro19, radio19);   
    esfera19.establecerColor(0.65, 0.07, 0.82);

    Punto3D centro20(-180*sm, (33.3*sm)+alt, -850.0);
    double radio20 = 4.33*sm;
    Esfera esfera20(centro20, radio20);   
    esfera20.establecerColor(0.65, 0.07, 0.82);

    //manos
    Punto3D centro21(-70*sm, (-50*sm)+alt, -500.0);
    double radio21 = 15.33*sm;
    Esfera esfera21(centro21, radio21);   
    esfera21.establecerColor(0.36, 0.231, 0.10);

    Punto3D centro22(70*sm, (-50*sm)+alt, -500.0);
    double radio22 = 15.33*sm;
    Esfera esfera22(centro22, radio22);   
    esfera22.establecerColor(0.36, 0.231, 0.10);
    //fin manos


    //dedos izq
    //fondo palma izq
    Punto3D centro31(-70*sm, (-52*sm)+alt, -400);
    double radio31 = 7.99*sm;
    Esfera esfera31(centro31, radio31);   
    esfera31.establecerColor(0, 0, 0);
    // fin fondo palma izq
    Punto3D centro32(-70*sm, (-52*sm)+alt, -300);
    double radio32 = 8*sm;
    Esfera esfera32(centro32, radio32);   
    esfera32.establecerColor(1.0, 0.3, 0.3);
    
    Punto3D centro33(-60*sm, (-45*sm)+alt, -300);
    double radio33 = 2*sm;
    Esfera esfera33(centro33, radio33);   
    esfera33.establecerColor(1.0, 0.3, 0.3);

    Punto3D centro34(-80*sm, (-45*sm)+alt, -300);
    double radio34 = 2*sm;
    Esfera esfera34(centro34, radio34);   
    esfera34.establecerColor(1.0, 0.3, 0.3);

    Punto3D centro35(-74*sm, (-40*sm)+alt, -300);
    double radio35 = 2*sm;
    Esfera esfera35(centro35, radio35);   
    esfera35.establecerColor(1.0, 0.3, 0.3);

    Punto3D centro36(-66*sm, (-40*sm)+alt, -300);
    double radio36 = 2*sm;
    Esfera esfera36(centro36, radio36);   
    esfera36.establecerColor(1.0, 0.3, 0.3);
    //fin dedos izq


    //dedos der
    //fondo palma der
    Punto3D centro30(70*sm, (-52*sm)+alt, -400);
    double radio30 = 7.99*sm;
    Esfera esfera30(centro30, radio30);   
    esfera30.establecerColor(0, 0, 0);
    // fin fondo palma der
    Punto3D centro25(70*sm, (-52*sm)+alt, -300);
    double radio25 = 8*sm;
    Esfera esfera25(centro25, radio25);   
    esfera25.establecerColor(1.0, 0.3, 0.3);
    
    Punto3D centro26(60*sm, (-45*sm)+alt, -300);
    double radio26 = 2*sm;
    Esfera esfera26(centro26, radio26);   
    esfera26.establecerColor(1.0, 0.3, 0.3);

    Punto3D centro27(80*sm, (-45*sm)+alt, -300);
    double radio27 = 2*sm;
    Esfera esfera27(centro27, radio27);   
    esfera27.establecerColor(1.0, 0.3, 0.3);

    Punto3D centro28(74*sm, (-40*sm)+alt, -300);
    double radio28 = 2*sm;
    Esfera esfera28(centro28, radio28);   
    esfera28.establecerColor(1.0, 0.3, 0.3);

    Punto3D centro29(66*sm, (-40*sm)+alt, -300);
    double radio29 = 2*sm;
    Esfera esfera29(centro29, radio29);   
    esfera29.establecerColor(1.0, 0.3, 0.3);
    //fin dedos der

    //pies
    Punto3D centro23(50*sm, (-135*sm)+alt, -300);
    double radio23 = 20.33*sm;
    Esfera esfera23(centro23, radio23);   
    esfera23.establecerColor(0.36, 0.231, 0.10);

    Punto3D centro24(-50*sm, (-135*sm)+alt, -300);
    double radio24 = 20.33*sm;
    Esfera esfera24(centro24, radio24);   
    esfera24.establecerColor(0.36, 0.231, 0.10);

   /* Punto3D centro37(60*sm, (-160*sm)+alt, 110.0);
    double radio37 = 10.33*sm;
    Esfera esfera37(centro37, radio37);   
    esfera37.establecerColor(0.36, 0.231, 0.10);
    
    Punto3D centro38(-60*sm, (-160*sm)+alt, 110.0);
    double radio38 = 10.33*sm;
    Esfera esfera38(centro38, radio38);   
    esfera38.establecerColor(0.36, 0.231, 0.10);*/

    //fin pies
    //esfera focos fin
    //Pared
    Punto3D p1(0, 0.0, -1000.0);
    Vector3D q1(0, 1.0, 1.0);
    Plano plano1(p1, q1.hat());
    plano1.establecerColor(0.02, 0.04, 0.2);
    //fin Pared
    //inicio piso
    Punto3D p2(0,-220,0);
    Vector3D q2(0, 1.0,-1.0 );
    Plano plano2(p2, q2.hat());
    plano2.establecerColor(0.20, 0.29, 0.37);

    Punto3D p3(0,-240,0);
    Vector3D q3(0, 1.0,-1.0 );
    Plano plano3(p3, q3.hat());
    plano3.establecerColor(0.65, 0.07, 0.82);

    Punto3D p4(0,-245,0);
    Vector3D q4(0, 1.0,-1.0 );
    Plano plano4(p4, q4.hat());
    plano4.establecerColor(0.20, 0.29, 0.37);

    Punto3D p5(0,-285,0);
    Vector3D q5(0, 1.0,-1.0 );
    Plano plano5(p5, q5.hat());
    plano5.establecerColor(0.29, 0.99, 0.11);

    Punto3D p6(0,-290,0);
    Vector3D q6(0, 1.0,-1.0 );
    Plano plano6(p6, q6.hat());
    plano6.establecerColor(0.20, 0.29, 0.37);

    Punto3D p7(0,-330,0);
    Vector3D q7(0, 1.0,-1.0 );
    Plano plano7(p7, q7.hat());
    plano7.establecerColor(0.29, 0.99, 0.11);

    Punto3D p8(0,-335,0);
    Vector3D q8(0, 1.0,-1.0 );
    Plano plano8(p8, q8.hat());
    plano8.establecerColor(0.20, 0.29, 0.37);

    Punto3D p9(0,-375,0);
    Vector3D q9(0, 1.0,-1.0 );
    Plano plano9(p9, q9.hat());
    plano9.establecerColor(0.65, 0.07, 0.82);

    Punto3D p10(0,-380,0);
    Vector3D q10(0, 1.0,-1.0 );
    Plano plano10(p10, q10.hat());
    plano10.establecerColor(0.20, 0.29, 0.37);

    //Triangulo
    Punto3D A(50,250,-50);
    Punto3D B(0,300,45);
    Punto3D C(-50, 250, -20);
    Triangulo t(A, B, C);
    t.establecerColor(0.113,0.647,0.529);

    //Calzon
    Punto3D A1(110,10,50);
    Punto3D B1(0,-65,-45);
    Punto3D C1(-110, 10, 20);   
    Triangulo t2(A1,B1,C1);
    t2.establecerColor(0.749,0.882,0.20);

    //Bra
    Punto3D A2(105,100,-50);
    Punto3D B2(110,90,45);
    Punto3D C2(-110, 100, -20);   
    Triangulo t3(A2,B2,C2);
    t3.establecerColor(0.749,0.882,0.20);

    Punto3D A3(105,90,-50);
    Punto3D B3(-112,90,45);
    Punto3D C3(-110, 100, -20);   
    Triangulo t4(A3,B3,C3);
    t4.establecerColor(0.749,0.882,0.20);

    //Estrellas de disco
    Punto3D A4(-180,190,-50);
    Punto3D B4(-200,230,45);
    Punto3D C4(-220, 190, -20);   
    Triangulo t5(A4,B4,C4);
    t5.establecerColor(1.0,1.0,0);

    Punto3D A5(-180,190,-50);
    Punto3D B5(-140,170,45);
    Punto3D C5(-180, 150, -20);   
    Triangulo t6(A5,B5,C5);
    t6.establecerColor(1.0,1.0,0);

    Punto3D A6(-220,150,-50);
    Punto3D B6(-180,150,45);
    Punto3D C6(-200, 110, -20);   
    Triangulo t7(A6,B6,C6);
    t7.establecerColor(1.0,1.0,0);

    Punto3D A7(-220,190,-50);
    Punto3D B7(-260,170,45);
    Punto3D C7(-220, 150, -20);   
    Triangulo t8(A7,B7,C7);
    t8.establecerColor(1.0,1.0,0);

    Punto3D A8(-180,190,-50);
    Punto3D B8(-220,190,45);
    Punto3D C8(-180, 150, -20);   
    Triangulo t9(A8,B8,C8);
    t9.establecerColor(1.0,1.0,0);

    Punto3D A9(-180,150,-50);
    Punto3D B9(-220,190,45);
    Punto3D C9(-220, 150, -20);   
    Triangulo t10(A9,B9,C9);
    t10.establecerColor(1.0,1.0,0);




    //Esferas calzon
    
    Punto3D centro37(18*sm, (-100*sm)+alt, 55);
    double radio37 = 3*sm;
    Esfera esfera37(centro37, radio37);   
    esfera37.establecerColor(1.0, 0, 0);

    Punto3D centro38(-22*sm, (-110*sm)+alt, 60);
    Esfera esfera38(centro38, radio37);   
    esfera38.establecerColor(1.0, 0, 0);
    
    Punto3D centro40(28*sm, (-110*sm)+alt, 60);
    Esfera esfera40(centro40, radio37);   
    esfera40.establecerColor(1.0, 0, 0);
    

    Punto3D centro39(0*sm, (-113*sm)+alt, 60);
    Esfera esfera39(centro39, radio37);   
    esfera39.establecerColor(1.0, 0, 0);

    Punto3D centro42(-5*sm, (-125*sm)+alt, 60);
    Esfera esfera42(centro42, radio37);   
    esfera39.establecerColor(1.0, 0, 0);


    Punto3D centro41(-14*sm, (-100*sm)+alt, 60);
    Esfera esfera41(centro41, radio37);   
    esfera41.establecerColor(1.0, 0, 0);

    Punto3D centro44(-50*sm, (-100*sm)+alt, 60);
    Esfera esfera44(centro44, radio37);   
    esfera44.establecerColor(1.0, 0, 0);
    Punto3D centro43(50*sm, (-100*sm)+alt, 60);
    Esfera esfera43(centro43, radio37);   
    esfera43.establecerColor(1.0, 0, 0);

    Punto3D centro45(-30*sm, (-102*sm)+alt, 60);
    Esfera esfera45(centro45, radio37);   
    esfera45.establecerColor(1.0, 0, 0);
    Punto3D centro46(30*sm, (-102*sm)+alt, 60);
    Esfera esfera46(centro46, radio37);   
    esfera46.establecerColor(1.0, 0, 0);


    Punto3D centro47(0*sm, (-103*sm)+alt, 60);
    Esfera esfera47(centro47, radio37);   
    esfera47.establecerColor(1.0, 0, 0);


    Punto3D centro48(10*sm, (-113*sm)+alt, 60);
    Esfera esfera48(centro48, radio37);   
    esfera48.establecerColor(1.0, 0, 0);

    //fin piso


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
   
   //focos
   escena.push_back(&esfera13);
   escena.push_back(&esfera14);
   escena.push_back(&esfera15);
   escena.push_back(&esfera16);
   escena.push_back(&esfera17);
   escena.push_back(&esfera18);
   escena.push_back(&esfera19);
   escena.push_back(&esfera20);

   //manos
    escena.push_back(&esfera21);
    escena.push_back(&esfera22);

    //dedos der
    escena.push_back(&esfera25);
    escena.push_back(&esfera26);
    escena.push_back(&esfera27);
    escena.push_back(&esfera28);
    escena.push_back(&esfera29);
    escena.push_back(&esfera30);
    
    //dedos izq
    escena.push_back(&esfera36);
    escena.push_back(&esfera31);
    escena.push_back(&esfera32);
    escena.push_back(&esfera33);
    escena.push_back(&esfera34);
    escena.push_back(&esfera35);
    
    //piernas
    escena.push_back(&esfera23);
    escena.push_back(&esfera24);

    //pared
    escena.push_back(&plano1);

    //piso
     //plano
    escena.push_back(&plano2);
    escena.push_back(&plano3);
    escena.push_back(&plano4);
    escena.push_back(&plano5);
    escena.push_back(&plano6);
    escena.push_back(&plano7);
    escena.push_back(&plano8);
    escena.push_back(&plano9);
    escena.push_back(&plano10);
    
    //escena.push_back(&esfera37);
   // escena.push_back(&esfera38);
   //triangulo
   escena.push_back(&t);

   //calzon
   escena.push_back(&t2);

   //bra
   escena.push_back(&t3);
   escena.push_back(&t4);

   //estrellas
    escena.push_back(&t5);
    escena.push_back(&t6);
    escena.push_back(&t7);
    escena.push_back(&t8);
    escena.push_back(&t9);
    escena.push_back(&t10);

   //esferas calzon
    escena.push_back(&esfera37);
    escena.push_back(&esfera38);
    escena.push_back(&esfera39);
    escena.push_back(&esfera40);
    escena.push_back(&esfera41);
    escena.push_back(&esfera42);
    escena.push_back(&esfera44);
    escena.push_back(&esfera43);
    escena.push_back(&esfera45);
    escena.push_back(&esfera46);
    escena.push_back(&esfera47);
    escena.push_back(&esfera48);

    ColorRGB color_pixel;



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
