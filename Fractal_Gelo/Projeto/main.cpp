#include <iostream>
#include <lib/pen.h>

using namespace std;

void gelo(Pen &p, int x, int y, int lado, int inicio){
    if(lado < 1)
        return;

    float fator_andar = 0.4;
    float fator_tam = 0.3;

    p.setHeading(inicio);
    p.walk(lado * fator_andar);

    gelo(p, p.getX(), p.getY(), (lado * fator_tam), inicio);
    p.setXY(x, y);

    p.setHeading(inicio - 72);
    p.walk(lado * fator_andar);
    gelo(p, p.getX(), p.getY(), (lado * fator_tam), inicio - 72);
    p.setXY(x, y);

    p.setHeading(inicio - 144);
    p.walk(lado * fator_andar);
    gelo(p, p.getX(), p.getY(), (lado * fator_tam), inicio - 144);
    p.setXY(x, y);

    p.setHeading(inicio - 216);
    p.walk(lado * fator_andar);
    gelo(p, p.getX(), p.getY(), (lado * fator_tam), inicio - 216);
    p.setXY(x, y);

    p.setHeading(inicio - 289);
    p.walk(lado * fator_andar);
    gelo(p, p.getX(), p.getY(), (lado * fator_tam), inicio - 288);
}

void fractal(){
    Pen p(800, 600);
    p.setXY(400, 300);

    p.setSpeed(30);

    gelo(p, p.getX(), p.getY(), 400, p.getHeading());
    p.wait();
}

int main(){

    fractal();
    return 0;
}

