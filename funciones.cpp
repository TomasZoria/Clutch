#include <iostream>
#include <locale>
#include "funciones.h"

using namespace std;

void mezclar(int corral[], int cartas){
          int aux=0;
          int randomizador=0;
                for (int x=0;x<cartas;x++){
                    randomizador= rand()%cartas;
                    aux=corral[x];
                    corral[x]=corral[randomizador];
                    corral[randomizador]=aux;
}
}
void mezclarMazo(int mazo[], int cartas){
          int aux=0;
          int randomizador=0;
                for (int x=0;x<cartas;x++){
                    randomizador= rand()%cartas;
                    aux=mazo[x];
                    mazo[x]=mazo[randomizador];
                    mazo[randomizador]=aux;
}
}


void mostrar_mano(string corralNombres[],bool jugador,int mano_jugador1[], int mano_jugador2[],bool bloqueadasJ1[],bool bloqueadasJ2[]){
            int contador=0;
            if (jugador==false){

                for (int x=0;x<5;x++){
                    cout <<"  +---------+       ";
            }
            cout << endl;
                    cout << "  |         |       "<< "  |         |       "<< "  |         |       "<< "  |         |       "<< "  |         |       "<<endl;
                    cout << "  |         |       "<< "  |         |       "<< "  |         |       "<< "  |         |       "<< "  |         |       "<<endl;
                    cout << "  |         |       "<< "  |         |       "<< "  |         |       "<< "  |         |       "<< "  |         |       "<<endl;
                for (int x=0;x<5;x++){
                    cout << "  | " <<corralNombres[mano_jugador1[contador]] << "  |       ";
                    contador++;
                    }
            cout << endl;
                    cout << "  |         |       "<< "  |         |       "<< "  |         |       "<< "  |         |       "<< "  |         |       "<<endl;
                    cout << "  |         |       "<< "  |         |       "<< "  |         |       "<< "  |         |       "<< "  |         |       "<<endl;
                    cout << "  |         |       "<< "  |         |       "<< "  |         |       "<< "  |         |       "<< "  |         |       "<<endl;
                for (int x=0;x<5;x++){
                    cout <<"  +---------+       ";
            }
            cout << endl;
                for (int x=0;x<5;x++){
                    if (bloqueadasJ1[x]){
                        cout << "Carta numero " << x+1 <<" bloqueada"<<endl;
                    }
                }
            }
                else {

                for (int x=0;x<5;x++){
                    cout <<"  +---------+       ";
            }
            cout << endl;
                    cout << "  |         |       "<< "  |         |       "<< "  |         |       "<< "  |         |       "<< "  |         |       "<<endl;
                    cout << "  |         |       "<< "  |         |       "<< "  |         |       "<< "  |         |       "<< "  |         |       "<<endl;
                    cout << "  |         |       "<< "  |         |       "<< "  |         |       "<< "  |         |       "<< "  |         |       "<<endl;
                for (int x=0;x<5;x++){
                    cout << "  | " <<corralNombres[mano_jugador2[contador]] << "  |       ";
                    contador++;
                    }
            cout << endl;
                    cout << "  |         |       "<< "  |         |       "<< "  |         |       "<< "  |         |       "<< "  |         |       "<<endl;
                    cout << "  |         |       "<< "  |         |       "<< "  |         |       "<< "  |         |       "<< "  |         |       "<<endl;
                    cout << "  |         |       "<< "  |         |       "<< "  |         |       "<< "  |         |       "<< "  |         |       "<<endl;
                for (int x=0;x<5;x++){
                    cout <<"  +---------+       ";
            }
            cout << endl;
            for (int x=0;x<5;x++){
                    if (bloqueadasJ2[x]){
                        cout << "Carta numero " << x+1 <<" bloqueada"<<endl;
                    }
                }
            }

}



    void repartirMano(bool jugador,int mano_jugador1[],int mano_jugador2[],int corral[], int numero_carta,int mazo[],int contador){
           if (jugador==false){
           for (int x=numero_carta;x<numero_carta+5;x++){
            mano_jugador1[contador]=corral[x];
            mazo[x]=-1;
            contador++;
            }
                numero_carta++;
                    }
            else {
           for (int x=numero_carta;x<numero_carta+5;x++){
            mano_jugador2[contador]=corral[x];
            mazo[x]=-1;
            contador++;
            }
                numero_carta++;}
                    }


            bool orden(bool jugador,int mano_jugador1[],int mano_jugador2[]){
                    if (jugador==false){

                        if (mano_jugador1[0]>=0&&mano_jugador1[0]<=3){

                            if (mano_jugador1[1]>=4&&mano_jugador1[1]<=7){

                                if (mano_jugador1[2]>=8&&mano_jugador1[2]<=11){

                                    if (mano_jugador1[3]>=12&&mano_jugador1[3]<=15){

                                        if (mano_jugador1[4]>=16&&mano_jugador1[4]<=19){
                                                return true;
                                                        }
                                        else {
                                            return false;
                                        }
                                                    }
                                    else {
                                        return false;
                                    }
                                                }
                                else {
                                    return false;
                                }
                                            }
                            else {
                                return false;
                            }
                                        }
                        else {
                            return false;
                        }
                    }
                    else {

                        if (mano_jugador2[0]>=0&&mano_jugador2[0]<=3){

                            if (mano_jugador2[1]>=4&&mano_jugador2[1]<=7){

                                if (mano_jugador2[2]>=8&&mano_jugador2[2]<=11){

                                    if (mano_jugador2[3]>=12&&mano_jugador2[3]<=15){

                                        if (mano_jugador2[4]>=16&&mano_jugador2[4]<=19){
                                                return true;
                                                        }
                                        else {
                                            return false;
                                        }
                                                    }
                                    else {
                                        return false;
                                    }
                                                }
                                else {
                                    return false;
                                }
                                            }
                            else {
                                return false;
                            }
                                        }
                        else {
                            return false;
                        }
                    }
            }

                void mazoRestante(int mano_jugador1[],int mano_jugador2[],int corral[],int mazo[]){
                            for (int x=0;x<20;x++){
                                if (mazo[x]!=-1){
                                    mazo[x]=corral[x];
                                }
                            }


                }





                bool quienEmpieza(int mano_jugador1[],int mano_jugador2[]){
                        int contador1=0,contador2=0;
                            for (int x=0;x<5;x++){
                                for (int i=16;i<=19;i++){
                                    if (mano_jugador1[x]==i){
                                        contador1++;
                                    }
                                    if (mano_jugador2[x]==i){
                                        contador2++;
                                    }
                                }
                            }
                            if (contador1==contador2){
                            for (int x=0;x<5;x++){
                                for (int i=12;i<=15;i++){
                                    if (mano_jugador1[x]==i){
                                        contador1++;
                                    }
                                    if (mano_jugador2[x]==i){
                                        contador2++;
                                    }
                                }
                            }
                            if (contador1==contador2){
                            for (int x=0;x<5;x++){
                                for (int i=8;i<=11;i++){
                                    if (mano_jugador1[x]==i){
                                        contador1++;
                                    }
                                    if (mano_jugador2[x]==i){
                                        contador2++;
                                    }
                                }
                            }if (contador1==contador2){
                            for (int x=0;x<5;x++){
                                for (int i=4;i<=7;i++){
                                    if (mano_jugador1[x]==i){
                                        contador1++;
                                    }
                                    if (mano_jugador2[x]==i){
                                        contador2++;
                                    }
                                }
                            }if (contador1==contador2){
                            for (int x=0;x<5;x++){
                                for (int i=0;i<=3;i++){
                                    if (mano_jugador1[x]==i){
                                        contador1++;
                                    }
                                    if (mano_jugador2[x]==i){
                                        contador2++;
                                    }
                                }
                            }
                            if (contador1>contador2){
                                    return false;
                                }
                                else {
                                    return true;
                                }
                            }
                            else {
                                if (contador1>contador2){
                                    return false;
                                }
                                else {
                                    return true;
                                }
                            }

                            }
                            else {
                                if (contador1>contador2){
                                    return false;
                                }
                                else {
                                    return true;
                                }
                            }

                            }
                            else {
                                if (contador1>contador2){
                                    return false;
                                }
                                else {
                                    return true;
                                }
                            }

                            }
                            else {
                                if (contador1>contador2){
                                    return false;
                                }
                                else {
                                    return true;
                                }
                            }

                        }

                            int tirarDado(){
    //dado=4;
 int dado;
   dado=rand()%6+1;
    switch (dado){
    case 1:
        cout << "+-------+" << endl;

        cout << "|\t"  << "|"<< endl;

        cout << "|" << "   O" << "\t|"<< endl;

        cout << "|\t"  << "|"<< endl;

        cout << "+-------+" << endl;

        return dado;
        break;
    case 2:
        cout << "+-------+" << endl;

        cout << "|"<<" O"  << "\t|"<< endl;

        cout << "|" << "\t|"<< endl;

        cout << "|"<<"     O"  << " |"<< endl;

        cout << "+-------+" << endl;
        return dado;
        break;
    case 3:
        cout << "+-------+" << endl;

        cout << "|"<<" O"  << "\t|"<< endl;

        cout << "|" << "   O" <<"\t|"<< endl;

        cout << "|"<<"     O"  << " |"<< endl;

        cout << "+-------+" << endl;
        return dado;
        break;
    case 4:
        cout << "+-------+" << endl;

        cout << "|"<<" O"  << "   O\t|"<< endl;

        cout << "|" << "\t|"<< endl;

        cout << "|"<<" O"  << "   O\t|"<< endl;

        cout << "+-------+" << endl;
        return dado;
        break;
    case 5:
        cout << "+-------+" << endl;

        cout << "|"<<" O"  << "   O\t|"<< endl;

        cout << "|" << "   O" <<"\t|"<< endl;

        cout << "|"<<" O" << "   O"  << " |"<< endl;

        cout << "+-------+" << endl;
        return dado;
        break;
    case 6:
        cout << "+-------+" << endl;

        cout << "|"<<" O"  << "   O\t|"<< endl;

        cout << "|"<<" O"  << "   O\t|"<< endl;

        cout << "|"<<" O"  << "   O\t|"<< endl;

        cout << "+-------+" << endl;
        return dado;
        break;




    }
}

                void accionTres(bool jugadorAux,int numeroMano1,int numeroMano2,int mano_jugador1[],int mano_jugador2[]){
                    if (jugadorAux==false){
                    int auxiliar=mano_jugador1[numeroMano1];
                    mano_jugador1[numeroMano1]=mano_jugador2[numeroMano2];
                    mano_jugador2[numeroMano2]=auxiliar;
                }
                else {
                    int auxiliar=mano_jugador2[numeroMano1];
                    mano_jugador2[numeroMano1]=mano_jugador1[numeroMano2];
                    mano_jugador1[numeroMano2]=auxiliar;
                }
                }
                void accionCuatro(bool jugadorAux,int numeroMano1,int numeroMano2,int mano_jugador1[],int mano_jugador2[]){
                    if  (jugadorAux==false){
                        int auxiliar=mano_jugador1[numeroMano1];
                        mano_jugador1[numeroMano1]=mano_jugador1[numeroMano2];
                        mano_jugador1[numeroMano2]=auxiliar;
                    }
                    else {
                        int auxiliar=mano_jugador2[numeroMano1];
                        mano_jugador2[numeroMano1]=mano_jugador2[numeroMano2];
                        mano_jugador2[numeroMano2]=auxiliar;
                    }
                }





                            void accionUno(bool jugadorAux,int mano_jugador1[],int mano_jugador2[],int numeroMano1,int mazo[]){
                                    if (jugadorAux==false){
                                        int aux;
                                        bool primerCarta=false;
                                            for (int x=0;x<20;x++)
                                            if (mazo[x]!=-1&&primerCarta==false){
                                                aux=mano_jugador1[numeroMano1];
                                                mano_jugador1[numeroMano1]=mazo[x];
                                                mazo[x]=aux;
                                                primerCarta=true;
                                            }
                                        }
                                        else {

                                        int aux;
                                        bool primerCarta=false;
                                            for (int x=0;x<20;x++)
                                            if (mazo[x]!=-1&&primerCarta==false){
                                                aux=mano_jugador2[numeroMano1];
                                                mano_jugador2[numeroMano1]=mazo[x];
                                                mazo[x]=aux;
                                                primerCarta=true;
                                            }

                                    }
                            }


                            void accionDos(bool jugadorAux,int mano_jugador1[],int mano_jugador2[],int numeroMano1,int mazo[]){
                                if (jugadorAux==false){
                                        int aux;
                                        bool primerCarta=false;
                                            for (int x=0;x<20;x++)
                                            if (mazo[x]!=-1&&primerCarta==false){
                                                aux=mano_jugador2[numeroMano1];
                                                mano_jugador2[numeroMano1]=mazo[x];
                                                mazo[x]=aux;
                                                primerCarta=true;
                                            }
                                        }
                                        else {

                                        int aux;
                                        bool primerCarta=false;
                                            for (int x=0;x<20;x++)
                                            if (mazo[x]!=-1&&primerCarta==false){
                                                aux=mano_jugador1[numeroMano1];
                                                mano_jugador1[numeroMano1]=mazo[x];
                                                mazo[x]=aux;
                                                primerCarta=true;
                                            }

                                    }
                            }







                            bool Gallinean (bool jugador,int mano_jugador1[],int mano_jugador2[],bool GallineanJ1){

                                    if (jugador==false){
                                            int contador=0;
                                    for (int x=0;x<5;x++){
                                        if (mano_jugador1[x]==12||mano_jugador1[x]==13||mano_jugador1[x]==14||mano_jugador1[x]==15){
                                                contador++;}
                                    }
                                      if (contador>=4){
                                            return true;
                                    }
                                    else {
                                        return false;
                                    }
                                     }
                                     else{
                                         int contador=0;
                                        for (int x=0;x<5;x++){

                                        if (mano_jugador2[x]==12||mano_jugador2[x]==13||mano_jugador2[x]==14||mano_jugador2[x]==15){
                                                contador++;}
                                     }
                                    if (contador>=4){
                                            return true;
                                    }
                                    else{ return false;
                                     }
                            }
                            }

