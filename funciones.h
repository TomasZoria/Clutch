#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


void mezclar(int corral[], int cartas );
void mezclarMazo(int mazo[], int cartas );
void mostrar_mano(std::string corralNombres[],bool jugador,int mano_jugador1[], int mano_jugador2[],bool bloqueadasJ1[],bool bloqueadasJ2[]);
void repartirMano(bool jugador,int mano_jugador1[],int mano_jugador2[],int corral[], int numero_carta,int mazo[],int contador);
bool orden(bool jugador,int mano_jugador1[],int mano_jugador2[]);
void mazoRestante(int mano_jugador1[],int mano_jugador2[],int corral[],int mazo[]);
bool quienEmpieza(int mano_jugador1[],int mano_jugador2[]);
int tirarDado();
void accionUno(bool jugadorAux,int mano_jugador1[],int mano_jugador2[],int numeroMano1,int mazo[]);
void accionDos(bool jugadorAux,int mano_jugador1[],int mano_jugador2[],int numeroMano1,int mazo[]);
void accionTres(bool jugadorAux,int numeroMano1,int numeroMano2,int mano_jugador1[],int mano_jugador2[]);
void accionCuatro(bool jugadorAux,int numeroMano1,int numeroMano2,int mano_jugador1[],int mano_jugador2[]);
bool Gallinean (bool jugador,int mano_jugador1[],int mano_jugador2[],bool GallineanJ1);





#endif // FUNCIONES_H_INCLUDED
