#ifndef MUSICO_H_INCLUDED
#define MUSICO_H_INCLUDED

#define TEXT_SIZE 50

typedef struct
{
    int idMusico;
    int isEmpty;
    //-----------------
    //char nombre[TEXT_SIZE];
    //char lugar[TEXT_SIZE];
    char nombre[TEXT_SIZE];
    char apellido[TEXT_SIZE];
    //int tipoMusico;
    int edad;
    int suOrquesta;
    int suInstrumento;


}Musico;


#endif // MUSICO_H_INCLUDED

int musico_Inicializar(Musico *pMusico, int size);                                    //cambiar musico
int musico_buscarEmpty(Musico *pMusico, int size, int* posicion);                    //cambiar musico
int musico_buscarID(Musico *pMusico, int size, int valorBuscado, int* posicion);                    //cambiar musico
int musico_buscarInt(Musico *pMusico, int size, int valorBuscado, int* posicion);                    //cambiar musico
int musico_buscarString(Musico *pMusico, int size, char* valorBuscado, int* indice);                    //cambiar musico
int musico_alta(Musico *pMusico, int size, int* contadorID);                          //cambiar musico
int musico_baja(Musico *pMusico, int sizeArray);                                      //cambiar musico
int musico_bajaValorRepetidoInt(Musico *pMusico, int sizeArray, int valorBuscado);
int musico_modificar(Musico *pMusico, int sizeArray);                                //cambiar musico
int musico_ordenarPorString(Musico *pMusico,int size);                              //cambiar musico
int musico_listar(Musico *pMusico, int size);                      //cambiar musico




