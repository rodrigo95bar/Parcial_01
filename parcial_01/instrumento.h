#ifndef INSTRUMENTO_H_INCLUDED
#define INSTRUMENTO_H_INCLUDED

#define TEXT_SIZE 50

typedef struct
{
    int idInstrumento;
    int isEmpty;
    //-----------------
    //char nombre[TEXT_SIZE];
    //char lugar[TEXT_SIZE];
    char nombreInstrumento[TEXT_SIZE];

    //int tipoInstrumento;
    int instrumento;


}Instrumento;


#endif // INSTRUMENTO_H_INCLUDED

int instrumento_Inicializar(Instrumento *pInstrumento, int size);                                    //cambiar instrumento
int instrumento_buscarEmpty(Instrumento *pInstrumento, int size, int* posicion);                    //cambiar instrumento
int instrumento_buscarID(Instrumento *pInstrumento, int size, int valorBuscado, int* posicion);                    //cambiar instrumento
int instrumento_buscarInt(Instrumento *pInstrumento, int size, int valorBuscado, int* posicion);                    //cambiar instrumento
int instrumento_buscarString(Instrumento *pInstrumento, int size, char* valorBuscado, int* indice);                    //cambiar instrumento
int instrumento_alta(Instrumento *pInstrumento, int size, int* contadorID);                          //cambiar instrumento
int instrumento_baja(Instrumento *pInstrumento, int sizeArray);                                      //cambiar instrumento
int instrumento_bajaValorRepetidoInt(Instrumento *pInstrumento, int sizeArray, int valorBuscado);
int instrumento_modificar(Instrumento *pInstrumento, int sizeArray);                                //cambiar instrumento
int instrumento_ordenarPorString(Instrumento *pInstrumento,int size);                              //cambiar instrumento
int instrumento_listar(Instrumento *pInstrumento, int size);                      //cambiar instrumento





