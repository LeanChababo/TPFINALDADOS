#include <iostream>
#include "rlutil.h"

using namespace std;

//CREACION DADO
void Dados(int posx,int posy)
{
    rlutil::setColor(rlutil::RED);
    //PINTA CADA COSO A MEDIDA QUE PASA POR EL FOR, RELLENA LOS PIXEES
    for (int x=posx ; x<=posx+6; x++)
    {
        for (int y=posy; y<=posy+2; y++)
        {
            rlutil::locate (x,y);
            cout << (char) 219;
        }
    }
}

//TRAE NUMEROS DE DADO
void NumDado (int numero, int posx, int posy)
{
    int valor;
    Dados(posx,posy);
    rlutil::setColor(rlutil::BLUE);
    rlutil::setBackgroundColor(rlutil::RED);
    switch(numero)
    {
    case 1:
        rlutil::locate(posx+3,posy+1);
        cout << (char)254;
        break;
    case 2:
        rlutil::locate(posx+1,posy);
        cout << (char) 220;
        rlutil::locate(posx+5,posy+2);
        cout << (char) 223;
        break;
    case 3:
        rlutil::locate(posx+1,posy);
        cout << (char) 220;
        rlutil::locate(posx+5,posy+2);
        cout << (char) 223;
        rlutil::locate(posx+3,posy+1);
        cout << (char)254;
        break;
    case 4:
        rlutil::locate(posx+1,posy);
        cout << (char) 220;
        rlutil::locate(posx+5,posy);
        cout << (char) 220;
        rlutil::locate(posx+1,posy+2);
        cout << (char) 223;
        rlutil::locate(posx+5,posy+2);
        cout << (char) 223;
        break;
    case 5:
        rlutil::locate(posx+1,posy);
        cout << (char) 220;
        rlutil::locate(posx+5,posy);
        cout << (char) 220;
        rlutil::locate(posx+3,posy+1);
        cout << (char)254;
        rlutil::locate(posx+1,posy+2);
        cout << (char) 223;
        rlutil::locate(posx+5,posy+2);
        cout << (char) 223;
        break;
    case 6:
        rlutil::locate(posx+1,posy);
        cout << (char) 220;
        rlutil::locate(posx+5,posy);
        cout << (char) 220;
        rlutil::locate(posx+1,posy+2);
        cout << (char) 223;
        rlutil::locate(posx+5,posy+2);
        cout << (char) 223;
        rlutil::locate(posx+3,posy);
        cout << (char) 220;
        rlutil::locate(posx+3,posy+2);
        cout << (char) 223;
        break;
    }
}

// CREAMOS LA FUNCION DE TIRAR QUE LLAMAMOS A LA FUNCION DE NumDado Y LE DAMOS UN VALOR RANDOM PARA QUE VAYAN APARECIENDO DIFERNTES NUMEROS DE DADOPARA QUE SEA UN DADO ALEATORIO

// FOR INTERNO NOS DA LOS NUMEROS Y METEMOS PAUSA PARA EFECTO
int tirar (int posx, int posy)
{
    int dado = rand() %6 +1;

    for (int i=0; i<20; i++)
    {
        NumDado(rand()%6+1,posx,posy);
        rlutil::msleep(5);
    }
    NumDado(dado,posx,posy);
    return dado;
}
//FUNCION PARA TIRAR MANUAL
int tirarAEleccion (int numero, int posx, int posy, int op )/// OP ES PARA USAR EN EL CODIGO DE REGLA PARA QUE NO ME HAGA EFECTO DE TIRAR Y QUE ME QUEDEN FIJAS
{
    if(op == 1) /// SI PONGO UNO AL LLAMAR A LA FUNCION POR EJEMPLO EN MODO SIMULACION ENTONCES SI NOS HACE EL EFECTO
    {
        for (int i=0; i<20; i++)
        {
            NumDado(rand()%6+1,posx,posy);
            rlutil::msleep(5);
        }
    }
    NumDado(numero,posx,posy);
    return numero;
}


