#ifndef ORQUESTA_H_INCLUDED
#define ORQUESTA_H_INCLUDED

#define TEXT_SIZE 50

typedef struct
{
    int idOrquesta;
    int isEmpty;
    //-----------------
    //char nombre[TEXT_SIZE];
    //char lugar[TEXT_SIZE];
    char nombre[TEXT_SIZE];
    char lugar[TEXT_SIZE];
    //int tipoOrquesta;
    int tipoOrquesta;
    int tipoInstrumento;



}Orquesta;


#endif // ORQUESTA_H_INCLUDED

int orquesta_Inicializar(Orquesta *pOrquesta, int size);                                    //cambiar orquesta
int orquesta_buscarEmpty(Orquesta *pOrquesta, int size, int* posicion);                    //cambiar orquesta
int orquesta_buscarID(Orquesta *pOrquesta, int size, int valorBuscado, int* posicion);                    //cambiar orquesta
int orquesta_buscarInt(Orquesta *pOrquesta, int size, int valorBuscado, int* posicion);                    //cambiar orquesta
int orquesta_buscarString(Orquesta *pOrquesta, int size, char* valorBuscado, int* indice);                    //cambiar orquesta
int orquesta_alta(Orquesta *pOrquesta, int size, int* contadorID);                          //cambiar orquesta
int orquesta_baja(Orquesta *pOrquesta, int sizeArray);                                      //cambiar orquesta
int orquesta_bajaValorRepetidoInt(Orquesta *pOrquesta, int sizeArray, int valorBuscado);
int orquesta_modificar(Orquesta *pOrquesta, int sizeArray);                                //cambiar orquesta
int orquesta_ordenarPorString(Orquesta *pOrquesta,int size);                              //cambiar orquesta
int orquesta_listar(Orquesta *pOrquesta, int size);                      //cambiar orquesta



