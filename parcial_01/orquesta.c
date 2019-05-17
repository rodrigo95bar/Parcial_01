#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "orquesta.h"
#include "instrumento.h"
#define sinfonica 1
#define filarmonica 2
#define camara 3
#define cuerdas 1
#define viento_madera 2
#define viento_metal 3
#define percusion 4


static int generateID(void);

/** \brief  To indicate that all position in the pOrquesta are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the pOrquesta
* \param pOrquesta nombre Array of nombre
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int orquesta_Inicializar(Orquesta *pOrquesta, int size)                                    //cambiar nombre
{
    int retorno=-1;
    if(pOrquesta!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            pOrquesta[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un pOrquesta
* \param pOrquesta nombre Array de nombre
* \param size int Tamaño del pOrquesta
* \param posicion int* Puntero a la posicion del pOrquesta donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int orquesta_buscarEmpty(Orquesta *pOrquesta, int size, int* posicion)                    //cambiar nombre
{
    int retorno=-1;
    int i;
    if(pOrquesta!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(pOrquesta[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un pOrquesta y devuelve la posicion en que se encuentra
* \param pOrquesta nombre Array de nombre
* \param size int Tamaño del pOrquesta
* \param posicion int* Puntero a la posicion del pOrquesta donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int orquesta_buscarID(Orquesta *pOrquesta, int size, int valorBuscado, int* posicion)                    //cambiar nombre
{
    int retorno=-1;
    int i;
    if(pOrquesta!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(pOrquesta[i].isEmpty==1)
                continue;
            else if(pOrquesta[i].idOrquesta==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Busca un int en un pOrquesta y devuelve la posicion en que se encuentra
* \param pOrquesta nombre Array de nombre
* \param size int Tamaño del pOrquesta
* \param posicion int* Puntero a la posicion del pOrquesta donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int orquesta_buscarInt(Orquesta *pOrquesta, int size, int valorBuscado, int* posicion)                    //cambiar nombre
{
    int retorno=-1;
    int i;
    if(pOrquesta!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(pOrquesta[i].isEmpty==1)
                continue;
            else if(pOrquesta[i].tipoOrquesta==valorBuscado)                                                   //cambiar campo tipoOrquesta
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

//String
/** \brief Busca un string en un pOrquesta
* \param pOrquesta nombre Array de nombre
* \param size int Tamaño del pOrquesta
* \param posicion int* Puntero a la posicion del pOrquesta donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int orquesta_buscarString(Orquesta *pOrquesta, int size, char* valorBuscado, int* indice)                    //cambiar nombre
{
    int retorno=-1;
    int i;
    if(pOrquesta!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(pOrquesta[i].isEmpty==1)
                continue;
            else if(strcmp(pOrquesta[i].nombre,valorBuscado)==0)                                        //cambiar campo nombre
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un pOrquesta
* \param pOrquesta nombre Array de nombre
* \param size int Tamaño del pOrquesta
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int orquesta_alta(Orquesta *pOrquesta, int size, int* contadorID)                          //cambiar nombre
{
    int retorno=-1;
    int posicion;
    generateID();
    if(pOrquesta!=NULL && size>0 && contadorID!=NULL)
    {
        if(orquesta_buscarEmpty(pOrquesta,size,&posicion)==-1)                          //cambiar nombre
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            pOrquesta[posicion].idOrquesta=*contadorID;                                                       //campo ID
            pOrquesta[posicion].isEmpty=0;




            utn_getName("Ingrese nombre de orquesta\n: ","\nError",1,TEXT_SIZE,1,pOrquesta[posicion].nombre);

            utn_getTexto("Ingrese lugar\n: ","\nError",1,TEXT_SIZE,1,pOrquesta[posicion].lugar);

            utn_getUnsignedInt("Ingrese tipo de Orquesta: \n 1) Sinfonica \n 2) Filarmonica \n 3) Camara","\nError",1,sizeof(int),1,3,1,&pOrquesta[posicion].tipoOrquesta);

            utn_getUnsignedInt("Ingrese tipo de Instrumento: \n 1) Cuerdas \n 2) Viento-madera \n 3) viento-Metal \n 4) Percusion","\nError",1,sizeof(int),1,4,1,&pOrquesta[posicion].tipoInstrumento);

            printf("\n Posicion: %d\n ID: %d\n \n nombre: %s\n lugar: %s \n Tipo de orquesta: %d \n Tipo de Instrumento: %d",
                   posicion, pOrquesta[posicion].idOrquesta,pOrquesta[posicion].nombre,pOrquesta[posicion].lugar,pOrquesta[posicion].tipoOrquesta,pOrquesta[posicion].tipoInstrumento);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del pOrquesta por ID
* \param pOrquesta nombre Array de nombre
* \param size int Tamaño del pOrquesta
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int orquesta_baja(Orquesta *pOrquesta, int sizeArray)                                      //cambiar nombre
{
    int retorno=-1;
    int posicion;
    int id;
    if(pOrquesta!=NULL && sizeArray>0)


    {
        utn_getUnsignedInt("\nID de Orquesta a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(orquesta_buscarID(pOrquesta,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            pOrquesta[posicion].isEmpty=1;
            pOrquesta[posicion].idOrquesta=0;                                                                   //cambiar campo id
            pOrquesta[posicion].tipoOrquesta=0;                                                               //cambiar campo tipoOrquesta
            //pOrquesta[posicion].varFloat=0;                                                             //cambiar campo varFloat
            strcpy(pOrquesta[posicion].nombre,"");                                                   //cambiar campo nombre
            strcpy(pOrquesta[posicion].lugar,"");                                               //cambiar campo lugar
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del pOrquesta que contengan el valor buscado
* \param pOrquesta nombre Array de nombre
* \param size int Tamaño del pOrquesta
* \param valorBuscado int Valor a buscar en el pOrquesta
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int orquesta_bajaValorRepetidoInt(Orquesta *pOrquesta, int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(pOrquesta!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(pOrquesta[i].idOrquesta==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                pOrquesta[i].isEmpty=1;
                pOrquesta[i].idOrquesta=0;                                                                   //cambiar campo id
                pOrquesta[i].tipoOrquesta=0;                                                               //cambiar campo tipoOrquesta
                //pOrquesta[i].varFloat=0;                                                             //cambiar campo varFloat
                strcpy(pOrquesta[i].nombre,"");                                                   //cambiar campo nombre
                strcpy(pOrquesta[i].lugar,"");                                               //cambiar campo lugar
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param pOrquesta nombre Array de nombre
* \param size int Tamaño del pOrquesta
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int orquesta_modificar(Orquesta *pOrquesta, int sizeArray)                                //cambiar nombre
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(pOrquesta!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(orquesta_buscarID(pOrquesta,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n tipoOrquesta: %d\n nombre: %s\n lugar: %s",
                       posicion, pOrquesta[posicion].idOrquesta,pOrquesta[posicion].tipoOrquesta,pOrquesta[posicion].nombre,pOrquesta[posicion].lugar);
                utn_getChar("\nModificar: A B C D S(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,1,1,&pOrquesta[posicion].tipoOrquesta);           //mensaje + cambiar campo tipoOrquesta
                        break;
                    case 'B':
                                   //mensaje + cambiar campo varFloat
                        break;
                    case 'C':
                        utn_getName("\n: ","\nError",1,TEXT_SIZE,1,pOrquesta[posicion].nombre);                      //mensaje + cambiar campo nombre
                        break;
                    case 'D':
                        utn_getTexto("\n: ","\nError",1,TEXT_SIZE,1,pOrquesta[posicion].lugar);             //mensaje + cambiar campo lugar
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un pOrquesta
* \param pOrquesta nombre Array de nombre
* \param size int Tamaño del pOrquesta
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int orquesta_ordenarPorString(Orquesta *pOrquesta,int size)                              //cambiar nombre
{
    int retorno=-1;
    int i, j;
    char bufferString[TEXT_SIZE];                               //cambiar campo nombre
    int bufferId;
    int bufferIsEmpty;

    int bufferInt;                                              //cambiar buffer int
    //float bufferFloat;                                          //cambiar buffer varFloat
    char bufferLongString[TEXT_SIZE];                           //cambiar campo lugar

    if(pOrquesta!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(bufferString,pOrquesta[i].nombre);                      //cambiar campo nombre
            bufferId=pOrquesta[i].idOrquesta;                                   //cambiar campo id
            bufferIsEmpty=pOrquesta[i].isEmpty;

            bufferInt=pOrquesta[i].tipoOrquesta;                                //cambiar campo tipoOrquesta
            //bufferFloat=pOrquesta[i].varFloat;                            //cambiar campo varFloat
            strcpy(bufferLongString,pOrquesta[i].lugar);          //cambiar campo lugar


            j = i - 1;
            while ((j >= 0) && strcmp(bufferString,pOrquesta[j].nombre)<0)         //cambiar campo nombre                 //Si tiene mas de un criterio se lo agrego, Ej. bufferInt<pOrquesta[j].tipoOrquesta
            {                                                                                                               //buffer < campo ascendente   buffer > campo descendente
                strcpy(pOrquesta[j + 1].nombre,pOrquesta[j].nombre);          //cambiar campo nombre
                pOrquesta[j + 1].idOrquesta=pOrquesta[j].idOrquesta;                                //cambiar campo id
                pOrquesta[j + 1].isEmpty=pOrquesta[j].isEmpty;

                pOrquesta[j + 1].tipoOrquesta=pOrquesta[j].tipoOrquesta;                        //cambiar campo tipoOrquesta
                //pOrquesta[j + 1].varFloat=pOrquesta[j].varFloat;                    //cambiar campo varFloat
                strcpy(pOrquesta[j + 1].lugar,pOrquesta[j].lugar);  //cambiar campo lugar

                j--;
            }
            strcpy(pOrquesta[j + 1].nombre,bufferString);                     //cambiar campo nombre
            pOrquesta[j + 1].idOrquesta=bufferId;                                        //cambiar campo id
            pOrquesta[j + 1].isEmpty=bufferIsEmpty;

            pOrquesta[j + 1].tipoOrquesta=bufferInt;                                                        //cambiar campo tipoOrquesta
            //pOrquesta[j + 1].varFloat=bufferFloat;                                                    //cambiar campo varFloat
            strcpy(pOrquesta[j + 1].lugar,bufferLongString);                                    //cambiar campo lugar
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un pOrquesta
* \param pOrquesta nombre Array de nombre
* \param size int Tamaño del pOrquesta
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int orquesta_listar(Orquesta *pOrquesta, int CANT_ORQUESTA)                      //cambiar  nombre
{
    int retorno=-1;
    int i;
    if(pOrquesta!=NULL && CANT_ORQUESTA>=0)
    {
        for(i=0;i<CANT_ORQUESTA;i++)
        {
            if(pOrquesta[i].isEmpty==1)
                continue;
            else
                printf("\n ID: %d\n tipoOrquesta: %d\n nombre: %s\n lugar: %s",
                       pOrquesta[i].idOrquesta,pOrquesta[i].tipoOrquesta,pOrquesta[i].nombre,pOrquesta[i].lugar);      //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}

static int generateID(void)
{
    static int idOrq = 0;
    return idOrq++;
}
