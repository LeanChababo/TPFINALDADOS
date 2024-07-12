#include <iostream>
#include <ctime>

using namespace std;

#include "rlutil.h"
#include "funciones.h"
#include "misFunciones.h"


void modoDosJugadores(int puntajeMayor[], string nombreDelMayorPuntaje[])
{
    string nombre1, nombre2,opcionRondas;
    int  puntajeTotalJ1 = 0,puntajeTotalJ2 =0,Dados[6], ronda=0,maximoDeLaRondaJ1 =0,maximoDeLaRondaJ2=0,opcion,  tiradasJ1=0,tiradasJ2=0,limRondas, tirada =0;
    bool finaliza=false;
    ponerCero(Dados, 3);

    rlutil::locate (41,7);
    cout << "  MODO DUO! " << endl;
    rlutil::locate (41,10);
    cout << " INGRESE EL NOMBRE DEL PRIMER JUGADOR" << endl;
    rlutil::locate (55,12);
    cout << "- ";
    cin.ignore();
    getline(cin,nombre1);
    rlutil::locate (41,14);
    cout << " INGRESE EL NOMBRE DEL SEGUNDO JUGADOR" << endl;
    rlutil::locate (55,16);
    cout << "- ";
    getline(cin,nombre2);
    if(nombre1=="" || nombre2 == "") /// EL USUARIO DEBE DE INGRESAR SI O SI AMBOS NOMBRES
    {
        system("cls");
        rlutil::locate(38, 10);
        cout << "INGRESA NOMBRES!!! O AFUERA!" << endl;
        rlutil::locate(43, 12);
        cout << "INGRESE EL NOMBRE DEL PRIMER JUGADOR: ";
        rlutil::locate(58, 14);
        getline(cin,nombre1);
        rlutil::locate(43, 16);
        cout << "INGRESE EL NOMBRE DEL SEGUNDO JUGADOR: " << endl;
        rlutil::locate(58, 18);
        getline(cin,nombre2);
        if(nombre1=="" || nombre2 == "" )
        {
            system("cls");
            menu (puntajeMayor,nombreDelMayorPuntaje);
        }
    }
    system("cls");
    cout << endl;
    rlutil::locate (42,10);
    cout << " QUIERE INGRESAR UN LIMITE DE RONDAS? " <<endl;
    cout << endl;
    rlutil::locate (54,12);
    cout << " [ S / N ]" <<endl;
    rlutil::locate (59,14);
    cin >> opcionRondas;

    if (opcionRondas == "n" || opcionRondas == "N")
    {
        finaliza = false;
    }
    else if (opcionRondas == "s" || opcionRondas == "S")
    {
        system("cls");
        rlutil::locate (6,10);
        cout<< " INGRESE EL LIMITE DE RONDAS QUE DESEA JUGAR "<<endl;
        rlutil::locate (6,12);
        cin>>limRondas;
    }

    while(finaliza == false)
    {
        int puntajeTiradas[3];
        bool  sexteto = false;
        tiradasJ1=0;
        tiradasJ2=0;
        ronda++;
        ponerCero(puntajeTiradas, 3);
        system("cls");
        srand(time (0));
        rlutil::saveDefaultColor();

        if (puntajeTotalJ1 >0)
        {
            rlutil::locate (6,9);
            cout << "RONDA " << ronda << endl;
            rlutil::locate (6,10);
            cout << "TURNO DE " << nombre1<<endl;
            rlutil::locate (6,12);
            cout << "PUNTAJE "<< nombre1 << " " << puntajeTotalJ1 <<endl;
            rlutil::locate (6,13);
            cout << "PUNTAJE "<< nombre2 << " " << puntajeTotalJ2 <<endl;
            rlutil::anykey();
        }
        while(tiradasJ1 <= 2)
        {
            system("cls");
            rlutil::locate(6, 3);
            cout << "JUGADOR: " << nombre1 ;
            rlutil::locate(6, 4);
            cout << "RONDA: " << ronda ;
            rlutil::locate(6, 5);
            cout << "PUNTAJE TOTAL: " << puntajeTotalJ1 << endl;
            rlutil::locate(6, 7);
            cout << "MAXIMO PUNTAJE DE LA RONDA " << maximoDeLaRondaJ1 << endl;
            rlutil::locate(6, 8);
            cout << "LANZAMIENTO NUMERO " << tiradasJ1 +1 << endl;
            rlutil::locate(6, 9);
            cout << "TIRADA 1: " << puntajeTiradas[0] << " TIRADA 2: " << puntajeTiradas[1] << " TIRADA 3: " <<  puntajeTiradas[2] << endl;
            rlutil::locate(6, 12);
            cout << "Presiona cualquier tecla para tirar los dados! (menos apagar) " << endl;

            rlutil::anykey();

            for (int j=0; j<6; j++)
            {
                Dados[j] = tirar((j + 3) *10,16);
            }

            puntajeTiradas[tiradasJ1] = puntaje(Dados);

            if(puntajeTiradas[tiradasJ1]==0 || puntajeTiradas[tiradasJ1]==100)
            {
                tiradasJ1 = 2;
            }
            if(puntajeTiradas[tiradasJ1] == 0)
            {
                sexteto = true;
            }

            rlutil::resetColor();
            rlutil::anykey();
            ponerCero(Dados, 3);
            tiradasJ1 ++;
        }
        int ubi=maximoVector(puntajeTiradas, 3);
        if (puntajeTiradas[ubi] == 100)
        {
            puntajeTotalJ1 += 100;
        }
        else if (sexteto == true )
        {
            puntajeTotalJ1 = 0;
            maximoDeLaRondaJ1 = 0;
        }
        else
        {
            maximoDeLaRondaJ1 = puntajeTiradas[ubi];
            puntajeTotalJ1 += puntajeTiradas[ubi];
        }
        sexteto = false;
        ponerCero(puntajeTiradas, 3);
        system("cls");
        rlutil::locate (55,9);
        cout << "RONDA " << ronda << endl;
        rlutil::locate (51,10);
        cout << "TURNO DE " << nombre2<<endl;
        rlutil::locate (46,12);
        cout << "PUNTAJE "<< nombre1 << " " << puntajeTotalJ1 <<endl;
        rlutil::locate (46,13);
        cout << "PUNTAJE "<< nombre2 << " " << puntajeTotalJ2 <<endl;

        rlutil::anykey();
/// MISMAS CONDICIONES PARA LAS 3 TIRADAS
        while(tiradasJ2 <= 2)
        {
            system("cls");
            rlutil::locate(6, 3);
            cout << "JUGADOR: " << nombre2;
            rlutil::locate(6, 4);
            cout << "RONDA: " << ronda;
            rlutil::locate(6, 5);
            cout << "PUNTAJE TOTAL: " << puntajeTotalJ2 << endl;
            rlutil::locate(6, 7);
            cout << "MAXIMO PUNTAJE DE LA RONDA " << maximoDeLaRondaJ2 << endl;
            rlutil::locate(6, 8);
            cout << "LANZAMIENTO NUMERO " << tiradasJ2 +1 << endl;
            rlutil::locate(6, 9);
            cout << "TIRADA 1: " << puntajeTiradas[0] << " TIRADA 2: " << puntajeTiradas[1] << " TIRADA 3: " <<  puntajeTiradas[2] << endl;
            rlutil::locate(6, 12);
            cout << "Presiona cualquier tecla para tirar los dados! (menos apagar) " << endl;

            rlutil::anykey();
            for (int j=0; j<6; j++)
            {
                Dados[j] = tirar((j + 3) *10,16);
            }

            puntajeTiradas[tiradasJ2] = puntaje(Dados);

            if(puntajeTiradas[tiradasJ2]==0 || puntajeTiradas[tiradasJ2]==100)
            {
                tiradasJ2 = 2;
            }
            if(puntajeTiradas[tiradasJ2] == 0)
            {
                sexteto = true;
            }

            rlutil::resetColor();
            rlutil::anykey();
            ponerCero(Dados, 3);
            tiradasJ2++;
        }
        ubi=maximoVector(puntajeTiradas, 3);
        if (puntajeTiradas[ubi] == 100)
        {
            puntajeTotalJ2 += puntajeTiradas[ubi];
        }
        else if (sexteto == true )
        {
            puntajeTotalJ2 = 0;
            maximoDeLaRondaJ2 = 0;
        }
        else
        {
            maximoDeLaRondaJ2 = puntajeTiradas[ubi];
            puntajeTotalJ2 += puntajeTiradas[ubi];
        }
        if (puntajeTotalJ1>=100)
        {
            finaliza=true;
        }
        else if (puntajeTotalJ2>=100)
        {
            finaliza=true;
        }
        else if (ronda == limRondas)
        {
            finaliza=true;
        }

    }/// VEMOS QUIEN HIZO MAS PUNTOS ENTRE LOS DOS Y O QUIEN HIZO MENOS TIRADAS Y LE DECIMOS QUIEN GANO
    if (puntajeTotalJ1>=puntajeTotalJ2 &&  tiradasJ1 <= tiradasJ2)
    {
        actualizarRanking(puntajeTotalJ1, nombre1,puntajeMayor, nombreDelMayorPuntaje);
        system("cls");
        rlutil::locate(6,12);
        cout << "  FELICIDADES " << nombre1 << " GANASTE EL JUEGO!!!" <<endl;
        rlutil::anykey();
        system("cls");
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::setColor(rlutil::WHITE);

        rlutil::locate(6, 4);
        cout << nombre1 << " LLEGASTE A " << puntajeTotalJ1 << " PUNTOS EN LA RONDA " << ronda << endl ;
    }
    else if (puntajeTotalJ2>=puntajeTotalJ1 && tiradasJ1 >= tiradasJ2)
    {
        actualizarRanking(puntajeTotalJ2, nombre2,puntajeMayor, nombreDelMayorPuntaje);
        system("cls");
        rlutil::locate(6,12);
        cout << "  FELICIDADES " << nombre2 << " GANASTE EL JUEGO!!!" <<endl;
        rlutil::anykey();
        rlutil::resetColor();
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::setColor(rlutil::WHITE);
        system("cls");
        rlutil::locate(6, 4);
        cout << nombre2 << " LLEGASTE A " << puntajeTotalJ2 << " PUNTOS EN LA RONDA " << ronda <<endl ;
    }
    rlutil::locate(6, 9);
    cout << " 1- EMPEZAR EL JUEGO DE NUEVO  " << endl;
    rlutil::locate(6, 10);
    cout << " 2- RANKING                    " << endl;
    rlutil::locate(6, 11);
    cout << " 3- MENU                       " << endl;
    rlutil::locate(6, 12);
    cout << " 0- FINALIZAR JUEGO            " << endl;
    rlutil::locate(6, 15);
    cout << "INGRESE SU OPCION: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        system ("cls");
        modoDosJugadores(puntajeMayor,nombreDelMayorPuntaje);
        break;
    case 2:
        system ("cls");
        ranking(puntajeMayor,nombreDelMayorPuntaje);
        break;
    case 3:
        system("cls");
        menu(puntajeMayor,nombreDelMayorPuntaje);
        break;
    case 0:
        return;
    }
    rlutil::resetColor();
}






