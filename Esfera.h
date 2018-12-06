// #include "Punto3D.h"
#include "Rayo.h"
#include "ColorRGB.h"
#include "ObjetoGeometrico.h"
#include "Vector3D.h"
#include "ImageTexture.h"

class Esfera : public ObjetoGeometrico
{
    public:
    Esfera(Punto3D, double);
    ~Esfera();
    bool hayImpacto(const Rayo& r, double& t, Vector3D& n, Punto3D& q) const;
    void establecerColor(double, double, double);
    ColorRGB obtenerColor();
    double* getTexture(ImageTexture img);

    Punto3D c;
    double r;
    vector<Vector3D> axiss;
    ColorRGB color;
};