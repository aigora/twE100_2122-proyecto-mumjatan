
typedef struct
{
    int filaInicial;
    int columnaInicial;
    int filaFinal;
    int columnaFinal;


}mCoordenadas;
void tableroShow(int tablero[][8],int turno,int *filaM);
void tableroStart(int tablero[][8]);
void tableroLoad(int tablero[8][8],int *turno);
void reconocerPieza(int pieza,int turno,int *num,int *piezaI);
void reconocerJaque(int tablero[][8],int turno);
void cambioTurno(int *turno);
void verificarMovimiento(int tablero[8][8],int piezaI,int *num2,int *num3,int filaInicial,int filaFinal,int columnaInicial,int columnaFinal,int turno,int *filaM);
void posicion(mCoordenadas *mCoord,int tablero[8][8],int turno,int coordenada,int AI,int *fila);
void guardarPartida(int tablero[8][8],int turno);
void Nuevapartida();
void cargarPartida();
void movimientoAI(int tablero[][8]);
void delay (int secs);
void animacion_bienvenida();
void animacion_ganador0();
void animacion_ganador1();
void animacion_despedida();

