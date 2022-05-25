typedef struct
{
    int filaInicial;
    int columnaInicial;
    int filaFinal;
    int columnaFinal;


}mCoordenadas;
void tableroShow(int *tablero[8][8],int turno);
void tableroStart(int *tablero[8][8]);
void tableroLoad(int *tablero[8][8],int *turno);
void reconocerPieza(int pieza,int turno,int *num,int *piezaI);
void cambioTurno(int *turno);
void verificarMovimiento(int *tablero[8][8],int piezaI,int *num2,int *num3,int filaInicial,int filaFinal,int columnaInicial,int columnaFinal,int turno);
void posicion(mCoordenadas *mCoord,int *tablero[8][8],int turno,int coordenada,int AI);
void guardarPartida(int *tablero[8][8],int turno);
void Nuevapartida();
void cargarPartida();




