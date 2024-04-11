#include <iostream>
#include <locale>
#include <ctime>
#include <cstdlib>
#include "funciones.h"
using namespace std;


int main ()
{

    setlocale(LC_ALL, "Spanish");
        string nombre1,nombre2,ganador;
    string corralNombres[20]={  "10 Cor","10 Pic", "10 Tre", "10 Dia",
                                " J Cor"," J Pic", " J Tre", " J Dia",
                                " Q Cor"," Q Pic", " Q Tre", " Q Dia",
                                " K Cor"," K Pic", " K Tre", " K Dia",
                                " A Cor"," A Pic", " A Tre", " A Dia"};



    int corral[20]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
    int numero_carta=0,mazo[20]={},contador=0;
    bool jugador=false,jugadorAux,primerTurno=false;
    bool bloqueadasJ1[5]={},bloqueadasJ2[5]={},bloqueo=true,dado6=false;
    int mano_jugador1[5]={},mano_jugador2[5]={};
    int turnos=1;
    int dado,numeroMano1,numeroMano2,resultadoDado;
    char confirmacion,MP='S',entrada;
    bool RoboCartaJ1,RoboCartaJ2,PasarTurnoJ1,PasarTurnoJ2, estadisticas=false;
    int hitoTres,maxHito,puntosHitos[5],maxPuntos[5]={};
    bool GallineanJ1,GallineanJ2;




    while(MP=='S'||MP=='s'){
    system("cls");
        cout<<"                                                CLUTCH"<<endl;
        cout << " -------------------------------------------------------------------------------------------------------" <<endl;
        cout <<"\t1- JUGAR"<<endl;
        cout <<"\t2- ESTADISTICAS"<<endl;
        cout <<"\t3- CREDITOS"<<endl;
        cout <<"\t4- COMO JUGAR"<<endl;
        cout << " -------------------------------------------------------------------------------------------------------"<<endl;
        cout << "0-SALIR"<<endl;
        cin>>entrada;





    switch(entrada){


    case'0':
        cout <<"¿Cerrar el juego?(S/N)" << endl;
        cin >> confirmacion;
        if (confirmacion=='n'||confirmacion=='N'){
            break;
        }
        else{
        return 0;
        }
            break;

    case'1':
        system("cls");
        cout<<"                                                CLUTCH"<<endl;
        cout << " -------------------------------------------------------------------------------------------------------" <<endl;
        cout << " Antes de comenzar a jugar debe registar los nombres de los jugadores: "<< endl<<endl;
        cout<<" Ingrese el nombre del jugador 1:    ";
        cin.ignore();
        getline(cin,nombre1);
        cout<<" Ingrese el nombre del jugador 2:    ";
        getline(cin,nombre2);
        cout<<"¿Empezar la partida(S/N)?"<<endl;
        cin>>confirmacion;
            if(confirmacion=='S'||confirmacion=='s'){

       //INICIO RANDOM
        srand(time(NULL));
        mezclar(corral, 20);
            RoboCartaJ1=false;
            RoboCartaJ2=false;
            PasarTurnoJ1=false;
            PasarTurnoJ2=false;

            GallineanJ1=false;
            GallineanJ2=false;

            hitoTres=0;
            primerTurno=false;
            for (int x=0;x<5;x++){
                bloqueadasJ1[x]=0;
                bloqueadasJ2[x]=0;
            }
            for (int x=0;x<5;x++){
                puntosHitos[x]=0;
            }

        //JUGADOR 1
        repartirMano(jugador,mano_jugador1,mano_jugador2,corral,numero_carta,mazo,contador);


                if (orden(jugador,mano_jugador1,mano_jugador2)){
                        mezclar(corral,20);
                        repartirMano(jugador,mano_jugador1,mano_jugador2,corral,numero_carta,mazo,contador);
        }
        else {
        }

    numero_carta+=5;

    jugador=true;




        //JUGADOR 2
        repartirMano(jugador,mano_jugador1,mano_jugador2,corral,numero_carta,mazo,contador);


    if (orden(jugador,mano_jugador1,mano_jugador2)){
                        mezclar(corral,20);
                        repartirMano(jugador,mano_jugador1,mano_jugador2,corral,numero_carta,mazo,contador);
                        }
                        else {
                        }
                         mazoRestante(mano_jugador1,mano_jugador2,corral,mazo);
    numero_carta+=5;
    jugador=false;

   //TURNO 1
   while(orden(jugador,mano_jugador1,mano_jugador2)==false){
    system("cls");
        cout<<"                                                CLUTCH"<<endl;
        cout << " -------------------------------------------------------------------------------------------------------" <<endl;
    cout << "TURNO " << turnos << endl;
        cout << "Mano de "<< nombre1 << endl;
                mostrar_mano(corralNombres,jugador=false,mano_jugador1,mano_jugador2,bloqueadasJ1,bloqueadasJ2);
   cout << endl << "____________________________________________________________________________________________________________________" <<endl<< endl ;
        cout << "Mano de " << nombre2 << endl;
                mostrar_mano(corralNombres,jugador=true,mano_jugador1,mano_jugador2,bloqueadasJ1,bloqueadasJ2);
   cout<< endl <<" -------------------------------------------------------------------------------------------------------"<< endl;

/*

    for (int x=0;x<20;x++){
        cout << corral[x] << "    ";
    }
    cout << endl;
      cout << "-------"<<endl;
      for (int x=0;x<20;x++){
        cout << mazo[x] << "    ";
    }
*/



   if (primerTurno==true){
        if (jugadorAux==false){
            cout <<"Turno de " << nombre1 << endl;
        }
        else {
            cout << "Turno de " << nombre2 << endl;
        }
    }

   if (primerTurno==false){
        jugador=quienEmpieza(mano_jugador1,mano_jugador2);
        jugadorAux=jugador;
        if (jugador==false){
            cout <<"Turno de " << nombre1 << endl;
            primerTurno=true;
        }
        else {
            cout << "Turno de " << nombre2 << endl;
            primerTurno=true;
        }
        }
       cout << endl;



       //HITO EXTRA
       Gallinean(jugador,mano_jugador1,mano_jugador2,GallineanJ1);




        cout << "Presionar cualquier tecla para lanzar el dado"<< endl;
         system("pause>nul");
               resultadoDado=tirarDado();
        dado6=false;



    /*    //CODIGO DE PRUEBA
        cout << "numero dado";
        cin >> resultadoDado;
*/



        switch(resultadoDado){
        case 1:
            cout << "Devolver una carta de la mano propia al mazo y robar una carta" <<endl;
            cout << "Ingresar carta a devolver: ";
            cin >> numeroMano1;
             while (numeroMano1>5){
                cout << "Esa carta no existe, por favor elija otra carta: ";
                cin >> numeroMano1;
            }
                accionUno(jugadorAux,mano_jugador1,mano_jugador2,numeroMano1-1,mazo);
            break;
        case 2:
            cout << "Devolver una carta de la mano rival al mazo y robar una carta" << endl;
            cout << "Ingrese la carta a devolver: ";
            cin >> numeroMano1;
             while (numeroMano1>5){
                cout << "Esa carta no existe, por favor elija otra carta: ";
                cin >> numeroMano1;
            }
            bloqueo=true;
                while (bloqueo==true){
             bloqueo=false;
            if (jugadorAux==false){
                    if (bloqueadasJ2[numeroMano1-1]==true){
                        bloqueo=true;
                        cout << "La carta seleccionada esta bloqueada, selecciones otra: ";
                        cin >> numeroMano1;
                    }
            }
            else {
                if (bloqueadasJ1[numeroMano1-1]==true){
                    bloqueo=true;
                    cout << "La carta seleccionada esta bloqueada, selecciones otra: ";
                        cin >> numeroMano1;
                }
            }
            }

            accionDos(jugadorAux,mano_jugador1,mano_jugador2,numeroMano1-1,mazo);
            break;
        case 3:
            cout << "Elegir una carta e intercambiarla con una del rival" << endl;
            cout << "Carta propia: ";
            cin >> numeroMano1;
             while (numeroMano1>5){
                cout << "Esa carta no existe, por favor elija otra carta: ";
                cin >> numeroMano1;
            }
            cout << "Carta rival: ";
            cin >> numeroMano2;
             while (numeroMano2>5){
                cout << "Esa carta no existe, por favor elija otra carta: ";
                cin >> numeroMano2;
            }
            bloqueo=true;
                while (bloqueo==true){
             bloqueo=false;
            if (jugadorAux==false){
                    if (bloqueadasJ2[numeroMano2-1]==true){
                        bloqueo=true;
                        cout << "La carta seleccionada esta bloqueada, selecciones otra: ";
                        cin >> numeroMano2;
                    }
                    RoboCartaJ2=true;
            }
            else {
                if (bloqueadasJ1[numeroMano2-1]==true){
                    bloqueo=true;
                    cout << "La carta seleccionada esta bloqueada, selecciones otra: ";
                        cin >> numeroMano2;
                }
                RoboCartaJ1=true;
            }
            }

            accionTres(jugadorAux,numeroMano1-1,numeroMano2-1,mano_jugador1,mano_jugador2);
            break;
        case 4:
            cout << "Elegir una carta e intercambiarla con una de la misma mano" << endl;
            cout << "Primer carta: ";
            cin >> numeroMano1;
             while (numeroMano1>5){
                cout << "Esa carta no existe, por favor elija otra carta: ";
                cin >> numeroMano1;
            }
            cout << "Segunda carta: ";
            cin >> numeroMano2;
             while (numeroMano2>5){
                cout << "Esa carta no existe, por favor elija otra carta: ";
                cin >> numeroMano2;
            }
            accionCuatro(jugadorAux,numeroMano1-1,numeroMano2-1,mano_jugador1,mano_jugador2);
            break;
        case 5:
            cout << "Bloquea una carta del corral (una carta bloqueada no puede ser intercambiada)"<<endl;
            cout << "¿Bloquear una carta?(S/N)";
            cin >> confirmacion;
                if (confirmacion=='s'||confirmacion=='S'){
            cout << "Ingresar la carta a bloquear: ";
            cin >> numeroMano1;
            while (numeroMano1>5){
                cout << "Esa carta no existe, por favor elija otra carta: ";
                cin >> numeroMano1;
            }



            if (jugadorAux==false){
                bloqueadasJ1[numeroMano1-1]=true;

            }
            else {
                bloqueadasJ2[numeroMano1-1]=true;
            }
                }
            break;
        case 6:
            cout << "Elegir cualquiera de las acciones o pasar el turno"<<endl;
            cout << "¿Pasar turno?(S/N)";
            cin >> confirmacion;
                if (confirmacion=='s'||confirmacion=='S'){
                        if (jugadorAux==false){
                            PasarTurnoJ1=true;
                        }
                        else {
                            PasarTurnoJ2=true;
                        }
                    break;
                }
                else {
                    cout << "Elegir una accion: ";
                    cin >> resultadoDado;
                    while (resultadoDado==6){
                        cout << "Numero invalido, ingrese otro numero: ";
                        cin >> resultadoDado;
                    }
                                    switch(resultadoDado){
                                            case 1:
                                            cout << "Devolver una carta de la mano propio al mazo y robar una carta" <<endl;
                                            cout << "Ingresar carta a devolver: ";
                                            cin >> numeroMano1;
                                             while (numeroMano1>5){
                                                cout << "Esa carta no existe, por favor elija otra carta: ";
                                                cin >> numeroMano1;
                                            }
                                                accionUno(jugadorAux,mano_jugador1,mano_jugador2,numeroMano1-1,mazo);
                                            break;
                                        case 2:
                                            cout << "Devolver una carta de la mano rival al mazo y robar una carta" << endl;
                                            cout << "Ingrese la carta a devolver: ";
                                            cin >> numeroMano1;
                                             while (numeroMano1>5){
                                                cout << "Esa carta no existe, por favor elija otra carta: ";
                                                cin >> numeroMano1;
                                            }
                                            bloqueo=true;
                                                while (bloqueo==true){
                                             bloqueo=false;
                                            if (jugadorAux==false){
                                                    if (bloqueadasJ2[numeroMano1-1]==true){
                                                        bloqueo=true;
                                                        cout << "La carta seleccionada esta bloqueada, selecciones otra: ";
                                                        cin >> numeroMano1;
                                                    }
                                            }
                                            else {
                                                if (bloqueadasJ1[numeroMano1-1]==true){
                                                    bloqueo=true;
                                                    cout << "La carta seleccionada esta bloqueada, selecciones otra: ";
                                                        cin >> numeroMano1;
                                                }
                                            }
                                            }

                                            accionDos(jugadorAux,mano_jugador1,mano_jugador2,numeroMano1-1,mazo);
                                            break;
                                        case 3:
                                            cout << "Elegir una carta e intercambiarla con una del rival" << endl;
                                            cout << "Carta propia: ";
                                            cin >> numeroMano1;
                                             while (numeroMano1>5){
                                                cout << "Esa carta no existe, por favor elija otra carta: ";
                                                cin >> numeroMano1;
                                            }
                                            cout << "Carta rival: ";
                                            cin >> numeroMano2;
                                             while (numeroMano2>5){
                                                cout << "Esa carta no existe, por favor elija otra carta: ";
                                                cin >> numeroMano2;
                                            }
                                            bloqueo=true;
                                                while (bloqueo==true){
                                             bloqueo=false;
                                            if (jugadorAux==false){
                                                    if (bloqueadasJ2[numeroMano2-1]==true){
                                                        bloqueo=true;
                                                        cout << "La carta seleccionada esta bloqueada, selecciones otra: ";
                                                        cin >> numeroMano2;
                                                    }
                                            }
                                            else {
                                                if (bloqueadasJ1[numeroMano2-1]==true){
                                                    bloqueo=true;
                                                    cout << "La carta seleccionada esta bloqueada, selecciones otra: ";
                                                        cin >> numeroMano2;
                                                }
                                            }
                                            }

                                            accionTres(jugadorAux,numeroMano1-1,numeroMano2-1,mano_jugador1,mano_jugador2);
                                            break;
                                        case 4:
                                            cout << "Elegir una carta e intercambiarla con una del mismo corral" << endl;
                                            cout << "Primer carta: ";
                                            cin >> numeroMano1;
                                             while (numeroMano1>5){
                                                cout << "Esa carta no existe, por favor elija otra carta: ";
                                                cin >> numeroMano1;
                                            }
                                            cout << "Segunda carta: ";
                                            cin >> numeroMano2;
                                             while (numeroMano2>5){
                                                cout << "Esa carta no existe, por favor elija otra carta: ";
                                                cin >> numeroMano2;
                                            }
                                            accionCuatro(jugadorAux,numeroMano1-1,numeroMano2-1,mano_jugador1,mano_jugador2);
                                            break;
                                        case 5:
                                            cout << "Bloquea una carta del corral (una carta bloqueada no puede ser intercambiada)"<<endl;
                                            cout << "¿Pasar turno?(S/N)";
                                            cin >> confirmacion;
                                                if (confirmacion=='s'||confirmacion=='S'){
                                            cout << "Ingresar la carta a bloquear: ";
                                            cin >> numeroMano1;

                                            while (numeroMano1>5){
                                                cout << "Esa carta no existe, por favor elija otra carta: ";
                                                cin >> numeroMano1;
                                            }
                                            if (jugadorAux==false){
                                                bloqueadasJ1[numeroMano1-1]=true;
                                            }
                                            else {
                                                bloqueadasJ2[numeroMano1-1]=true;
                                            }
                                            }
                                            break;
        }

                }

            break;
        }
        jugadorAux=!jugadorAux;
    if (jugador==jugadorAux){
        jugador=!jugador;
        }
        turnos++;
        mezclarMazo(mazo,20);
        cout << "Presionar cualquier tecla para seguir el juego";
        system("pause>nul");


/*

            //CODIGO DE PRUEBA
        cout << "jugador";
        cin >> jugador;
        cout << "cartas seleccionadas" << endl;
        if (jugador==false){
        cin >> mano_jugador1[0];
        cin >> mano_jugador1[1];
        cin >> mano_jugador1[2];
        cin >> mano_jugador1[3];
        cin >> mano_jugador1[4];
        }
        else {
        cin >> mano_jugador2[0];
        cin >> mano_jugador2[1];
        cin >> mano_jugador2[2];
        cin >> mano_jugador2[3];
        cin >> mano_jugador2[4];
        }

*/
        }

        //jugadorAux!=jugadorAux;

        if(jugador==false){
            ganador=nombre1;
        }
        else {
            ganador=nombre2;
        }
            //HITOS

            if (resultadoDado==3){
                puntosHitos[0]=10;
            }
            if (jugador==false){

                    if (GallineanJ1==true){
                        puntosHitos[4]=50;
                    }

                if (mano_jugador2[0]>=0&&mano_jugador2[0]<=3){
                }
                else {
                    hitoTres++;
                }
                if (mano_jugador2[1]>=4&&mano_jugador2[1]<=7){
                }
                else {
                    hitoTres++;
                }
                if (mano_jugador2[2]>=8&&mano_jugador2[2]<=11){
                }
                else {
                    hitoTres++;
                }
                if (mano_jugador2[3]>=12&&mano_jugador2[3]<=15){
                }
                else {
                    hitoTres++;
                }
                if (mano_jugador2[4]>=16&&mano_jugador2[4]<=19){
                }
                else {
                    hitoTres++;
                }
                puntosHitos[1]=5*hitoTres;

                    if (PasarTurnoJ1==false){
                        puntosHitos[2]=10;
                    }

                    if(RoboCartaJ1==false){
                        puntosHitos[3]=5;
                    }
            }
            else {
                    if (GallineanJ1==true){
                        puntosHitos[4]=50;
                    }


                if (mano_jugador1[0]>=0&&mano_jugador1[0]<=3){
                }
                else {
                    hitoTres++;
                }
                if (mano_jugador1[1]>=4&&mano_jugador1[1]<=7){
                }
                else {
                    hitoTres++;
                }
                if (mano_jugador1[2]>=8&&mano_jugador1[2]<=11){
                }
                else {
                    hitoTres++;
                }
                if (mano_jugador1[3]>=12&&mano_jugador1[3]<=15){
                }
                else {
                    hitoTres++;
                }
                if (mano_jugador1[4]>=16&&mano_jugador1[4]<=19){
                }
                else {
                    hitoTres++;
                }
                puntosHitos[1]=5*hitoTres;

                    if (PasarTurnoJ2==false){
                        puntosHitos[2]=10;
                    }

                    if(RoboCartaJ2==false){
                        puntosHitos[3]=5;
                    }
            }
            estadisticas=true;


        system("cls");
        cout<<"                                                CLUTCH"<<endl;
        cout << " -------------------------------------------------------------------------------------------------------" <<endl;
        cout << "                                         PARTIDA TERMINADA                                              " << endl;
                cout << ganador << "        Gano la partida!"<<endl;
        cout << "HITO                               " << ganador << endl;
        cout << " -------------------------------------------------------------------------------------------------------" <<endl;
        cout << " Ganar la partida\t" << "\t         +15" << "\tPuntos" << endl;
        cout << " Ganar robando la ultima carta\t" << "\t +" << puntosHitos[0] << "\tPuntos" << endl;
        cout << " " << hitoTres << " Cartas mal ubicadas del rival" << "\t +" << puntosHitos[1] << "\tPuntos" << endl;
        cout << " Ganar sin pasar de turno\t" << "\t +" << puntosHitos[2] << "\tPuntos" << endl;
        cout << " Ganar sin que te roben cartas\t" << "\t +"<< puntosHitos[3] << "\tPuntos" << endl;
        cout << " Tener las 4 reinas en la mano \t" << "\t +"<< puntosHitos[4]<< "\tPuntos" << endl;
        cout << " -------------------------------------------------------------------------------------------------------" <<endl;
        cout << ganador << " fue el ganador con un total de \t\t " << 15+puntosHitos[0]+puntosHitos[1]+puntosHitos[2]+puntosHitos[3]+puntosHitos[4] << " puntos " << endl;

        for (int x=0;x<5;x++){
            if (puntosHitos[x]>maxPuntos[x]){
                maxPuntos[x]=puntosHitos[x];
            }
        }
        if (hitoTres>maxHito){
            maxHito=hitoTres;
        }


        cout << "Presione cualquier tecla para volver al menu..";
                system("pause>nul");
        break;

}
        else{

                    }

    break;

        case'2':
            if (estadisticas==false){
                system("cls");
                cout<<"                                                CLUTCH"<<endl;
                cout << " -------------------------------------------------------------------------------------------------------" <<endl;
                cout << "Todavia no se ha jugado ninguna partida " << endl;
                cout << "Presione cualquier tecla para volver al menu..";
                system("pause>nul");
                break;
            }
            else {
            system("cls");
            cout<<"                                                CLUTCH"<<endl;
            cout << " -------------------------------------------------------------------------------------------------------" <<endl;
            cout << "                                           ESTADISTICAS                                                 " << endl;
            cout << "HITO                               " << ganador << endl;
            cout << " -------------------------------------------------------------------------------------------------------" <<endl;
            cout << " Ganar la partida\t" << "\t         +15" << "\tPuntos" << endl;
            cout << " Ganar robando la ultima carta\t" << "\t +" << maxPuntos[0] << "\tPuntos" << endl;
            cout << " " << maxHito << " Cartas mal ubicadas del rival" << "\t +" << maxPuntos[1] << "\tPuntos" << endl;
            cout << " Ganar sin pasar de turno\t" << "\t +" << maxPuntos[2] << "\tPuntos" << endl;
            cout << " Ganar sin que te roben cartas\t" << "\t +"<< maxPuntos[3] << "\tPuntos" << endl;
            cout << " Tener las 4 reinas en la mano \t" << "\t +"<< maxPuntos[4]<< "\tPuntos" << endl;
            cout << " -------------------------------------------------------------------------------------------------------" <<endl;
            cout << ganador << " es la persona con mayor puntaje con \t\t " << 15+maxPuntos[0]+maxPuntos[1]+maxPuntos[2]+maxPuntos[3] << " puntos " << endl;
            cout << "Presione cualquier tecla para volver al menu..";
            system("pause>nul");
            break;
        }

            break;

    case'3':
            cout<<"INTEGRANTES DEL GRUPO 12:"<<endl;
            cout<<"LEONARDO TOARA - Legajo: 22245"<<endl
            <<"TOMAS ZORIA - Legajo: 29944"<<endl
            <<"LISANDRO PEROSA CROSES - Legajo: 29859"<<endl;
            cout << "Presione cualquier tecla para volver al menu..";
            system("pause>nul");

                break;

    case'4':
        system("cls");
        cout<<"                                                CLUTCH"<<endl;
        cout << " -------------------------------------------------------------------------------------------------------" <<endl;
        cout << "                                          ACCIONES DE DADO                                              " << endl;
        cout << "Accion de dado 1: Elegir una carta de su propio corral (1-5) y robar una carta del mazo. Se intercambian las dos. La carta robada pasa a formar parte del corral y la carta seleccionada se incorpora al mazo." << endl;
        cout << "Accion de dado 2: Elegir una carta del corral del contrario (1-5) y robar una carta del mazo. Se intercambian las dos. La carta robada pasa a formar parte del corral del contrario y la carta seleccionada se incorpora al mazo." << endl;
        cout << "Accion de dado 3: Elegir una carta del corral propio (1-5) e intercambiarla por una carta del corral del contrario (1-5). Las cartas seleccionadas se intercambian." << endl;
        cout << "Accion de dado 4: Intercambiar dos cartas del propio corral. Se eligen dos cartas del propio corral (1-5) y se intercambian entre sí." << endl;
        cout << "Accion de dado 5: Bloquear una carta del corral. La carta bloqueada no puede ser elegida por el contrario para intercambio (acciones 2 y 3) pero sí puede ser elegida por uno mismo." << endl;
        cout << "Accion de dado 6: Elegir cualquiera de las acciones anteriores o bien pasar el turno."<< endl;
        cout << " -------------------------------------------------------------------------------------------------------" <<endl;
        cout << "Cada figura representa una etapa en el proceso de crecimiento de una gallina" << endl;
        cout << endl;
        cout<<"NAIPE:10 = Huevo----";
        cout<<"Un huevo listo para ser empollado. Depende de vos que no termine en la sartén con sal y pimienta."<<endl<<endl;
        cout<<"NAIPE:J = Grieta----";
        cout<<"El huevo fue empollado y se visualiza una pequeña grieta."<<endl<<endl;
        cout<<"NAIPE:Q = Picoteo----";
        cout<<"El huevo fue empollado aún más y de la grieta se asoma un pequeño pico."<<endl<<endl;
        cout<<"NAIPE:K = Pollito----";
        cout<<"Del huevo salió un pequeño pollito. Es muy raro, sus primeras palabras fueron: ¡Hola mundo!"<<endl<<endl;
        cout<<"NAIPE:A = Gallina----";
        cout<<"El pollito creció y se convirtió en una gallina senior. No para de hablar de ganar en dólares."<<endl<<endl;
        cout << "Presione cualquier tecla para volver al menu..";
        system("pause>nul");

 }


}
return 0;}
