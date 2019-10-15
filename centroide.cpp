#include <math.h>
enum Signo{
    positivo = 1,
    negativo = -1
};

class Centroide{
private:
    float x,y;
public:
    Centroide(float x, float y) : x(x), y(y) {};
    float getX() const {
        return x;
    }
    void setX(float x) {
        Centroide::x = x;
    }
    float getY() const {
        return y;
    }
    void setY(float y) {
        Centroide::y = y;
    }
};
class Figura{
protected:
    Signo signo;
    Centroide *centroide;
public:
    Figura(float x,float y, Signo signo):signo(signo){
        centroide = new Centroide(x,y);
    }
    virtual float calcularArea()=0;
    Signo getSigno() const {
        return signo;
    }
    void setSigno(Signo signo) {
        Figura::signo = signo;
    }
    Centroide *getCentroide() const {
        return centroide;
    }
    virtual ~Figura() {
        delete centroide;
    }
};

class Circulo: public Figura{
private:
    float r;
public:
    Circulo(float x, float y, Signo signo, float r) : Figura(x, y, signo), r(r) {}

    float calcularArea() override {
        return  M_PI*pow(r,2);
    }
};
class triangulo: public Figura{
protected:
    float b,h;
public:
    triangulo(float x, float y, Signo signo, float b, float h) : Figura(x, y, signo), b(b), h(h) {}

    float calcularArea() override {
        return b*h/2;
    }
};
class rectangulo:public triangulo{
public:
    rectangulo(float x, float y, Signo signo, float b, float h) : triangulo(x, y, signo, b, h) {}

    float calcularArea() override {
        return b*h;
    }
};

