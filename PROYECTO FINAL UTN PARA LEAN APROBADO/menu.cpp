#include <iostream>

using namespace std;

#include "rlutil.h"
#include "misFunciones.h"


void menu (int puntajeMayor[], string nombreDelMayorPuntaje[])
{
    int opcion;
    rlutil::locate (0,6);
        cout << "------------------------------------------------------------------------------------------------------------------------";
        cout << "                                                 BIENVENIDO A" <<endl;
        cout << "                                                CIEN O ESCALERA" << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    rlutil::locate (0,10);
    cout << " 1- EMPEZAR NUEVO JUEGO DE UN JUGADOR" << endl;
    rlutil::locate (0,11);
    cout << " 2- EMPEZAR NUEVO JUEGO DE DOS JUGADORES" << endl;
    rlutil::locate (0,12);
    cout << " 3- RANKING " << endl;
    rlutil::locate (0,13);
    cout << " 4- REGLAS " << endl;
    rlutil::locate (0,14);
    cout << " 5- MODO PRUEBA" << endl;
    rlutil::locate (0,15);
    cout << " 0- FINALIZAR JUEGO" << endl;
    rlutil::locate (20,17);
    cout << "ELIJA UN NUMERO: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        system ("cls");
        modoUnJugador(puntajeMayor, nombreDelMayorPuntaje);
        break;
    case 2:
        system ("cls");
        modoDosJugadores(puntajeMayor,nombreDelMayorPuntaje);
        break;
    case 3:
        system ("cls");
        ranking(puntajeMayor, nombreDelMayorPuntaje);
        break;
        case 4:
        system ("cls");
        reglas(puntajeMayor, nombreDelMayorPuntaje);
        break;
    case 5:
        system ("cls");
        Simulacion(puntajeMayor, nombreDelMayorPuntaje);
        break;
    case 0:
        return ;
    }
}

