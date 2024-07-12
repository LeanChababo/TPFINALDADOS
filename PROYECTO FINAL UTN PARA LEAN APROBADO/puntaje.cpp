#include <iostream>

using namespace std;

#include "funciones.h"
#include "rlutil.h"
#include "misFunciones.h"


int puntaje (int vNumDados[])
{
    int puntajeAux=0, vContDados[6], contRepetidos=0;
    bool sexTeto=false;

    for (int i = 0; i < 6; i++)
    {
        contRepetidos = contarNumerosRepetidos(vNumDados, i+1, 6);
        if (contRepetidos == 6)
        {
            if (vNumDados[0] != 6) /// SI ESE NUMERO REPETIDO ES DIFERENTE A 6 ENTONCES HACE LA CUENTA CORRESPONDIENTE
            {
                puntajeAux = vNumDados[0] * 10;
            }
            else /// TENEMOS EL SEXTETO DE 6
            {
                puntajeAux = 0;
                sexTeto = true;
                system("cls");
                rlutil::hidecursor();
                rlutil::locate(37,10);
                cout << "-----------------------------------------------------" << endl;
                rlutil::locate(37,11);
                cout << "- HICISTE SEXTETO DE 6, TU PUNTAJE SE REINICIA A 0  -" << endl;
                rlutil::locate(37,12);
                cout << "-----------------------------------------------------" << endl;
            }
            break;
        }
    } ///HACEMOS LA CUENTA SI NO PASA NADA
    if (puntajeAux == 0 && sexTeto == false)
    {
        puntajeAux = sumarVector(vNumDados, 6);
    }
/// VERIFICACION ESCALERA
    ordenarVector(vNumDados, 6);

    bool escalera = true;

    for (int i = 0; i < 6; i++)
    {
        if (vNumDados[i] != i + 1)
        {
            escalera = false;
            break;
        }
    }

    if (escalera == true )
    {
        system("cls");
        rlutil::hidecursor();
        rlutil::locate(42,12);
        cout << "------------------------------------" << endl;
        rlutil::locate(42,13);
        cout << "------- HICISTE UNA ESCALERA -------" << endl;
        rlutil::locate(42,14);
        cout << "------------------------------------" << endl;
        puntajeAux = 100;
    }
    return puntajeAux;
}

