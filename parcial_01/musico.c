#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "musico.h"
#include "instrumento.h"   //cambiar por nombre entidad
#define sinfonica 1
#define filarmonica 2
#define camara 3
#define cuerdas 1
#define viento_madera 2
#define viento_metal 3
#define percusion 4


static int generateID(void);

/** \brief  To indicate that all position in the pMusico are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the pMusico
* \param pMusico nombre Array of nombre
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int musico_Inicializar(Musico *pMusico, int size)                                    //cambiar nombre
{
    int retorno=-1;
    if(pMusico!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            pMusico[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer apellido vacio en un pMusico
* \param pMusico nombre Array de nombre
* \param size int Tamaño del pMusico
* \param posicion int* Puntero a la posicion del pMusico donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un apellido vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int musico_buscarEmpty(Musico *pMusico, int size, int* posicion)                    //cambiar nombre
{
    int retorno=-1;
    int i;
    if(pMusico!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(pMusico[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un pMusico y devuelve la posicion en que se encuentra
* \param pMusico nombre Array de nombre
* \param size int Tamaño del pMusico
* \param posicion int* Puntero a la posicion del pMusico donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarID(Musico *pMusico, int size, int valorBuscado, int* posicion)                    //cambiar nombre
{
    int retorno=-1;
    int i;
    if(pMusico!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(pMusico[i].isEmpty==1)
                continue;
            else if(pMusico[i].idMusico==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Busca un int en un pMusico y devuelve la posicion en que se encuentra
* \param pMusico nombre Array de nombre
* \param size int Tamaño del pMusico
* \param posicion int* Puntero a la posicion del pMusico donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarInt(Musico *pMusico, int size, int valorBuscado, int* posicion)                    //cambiar nombre
{
    int retorno=-1;
    int i;
    if(pMusico!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(pMusico[i].isEmpty==1)
                continue;
            else if(pMusico[i].suInstrumento==valorBuscado)                                                   //cambiar campo suInstrumento
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
/** \brief Busca un string en un pMusico
* \param pMusico nombre Array de nombre
* \param size int Tamaño del pMusico
* \param posicion int* Puntero a la posicion del pMusico donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarString(Musico *pMusico, int size, char* valorBuscado, int* indice)                    //cambiar nombre
{
    int retorno=-1;
    int i;
    if(pMusico!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(pMusico[i].isEmpty==1)
                continue;
            else if(strcmp(pMusico[i].nombre,valorBuscado)==0)                                        //cambiar campo nombre
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
/** \brief Solicita los datos para completar la primer posicion vacia de un pMusico
* \param pMusico nombre Array de nombre
* \param size int Tamaño del pMusico
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int musico_alta(Musico *pMusico, int size, int* contadorID)                          //cambiar nombre
{
    int retorno=-1;
    int posicion;
    generateID();
    if(pMusico!=NULL && size>0 && contadorID!=NULL)
    {
        if(musico_buscarEmpty(pMusico,size,&posicion)==-1)                          //cambiar nombre
        {
            printf("\nNo hay espacios vacios");
        }
        else
        {
            (*contadorID)++;
            pMusico[posicion].idMusico=*contadorID;                                                       //campo ID
            pMusico[posicion].isEmpty=0;




            utn_getName("Ingrese nombre de musico\n: ","\nError",1,TEXT_SIZE,1,pMusico[posicion].nombre);

            utn_getTexto("Ingrese apellido\n: ","\nError",1,TEXT_SIZE,1,pMusico[posicion].apellido);

            utn_getUnsignedInt("Ingrese edad \n:","\nError",1,sizeof(int),1,99,1,&pMusico[posicion].edad);



            printf("\n ID: %d\n \n nombre: %s\n apellido: %s \n Su orquesta es: %d \n Su Instrumento es: %d",
                   pMusico[posicion].idMusico,pMusico[posicion].nombre,pMusico[posicion].apellido,pMusico[posicion].suOrquesta,pMusico[posicion].suInstrumento);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del pMusico por ID
* \param pMusico nombre Array de nombre
* \param size int Tamaño del pMusico
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musico_baja(Musico *pMusico, int sizeArray)                                      //cambiar nombre
{
    int retorno=-1;
    int posicion;
    int id;
    if(pMusico!=NULL && sizeArray>0)


    {
        utn_getUnsignedInt("\nID de Musico a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(musico_buscarID(pMusico,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            pMusico[posicion].isEmpty=1;
            pMusico[posicion].idMusico=0;                                                                   //cambiar campo id
            pMusico[posicion].suInstrumento=0;                                                               //cambiar campo suInstrumento
            //pMusico[posicion].varFloat=0;                                                             //cambiar campo varFloat
            strcpy(pMusico[posicion].nombre,"");                                                   //cambiar campo nombre
            strcpy(pMusico[posicion].apellido,"");                                               //cambiar campo apellido
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del pMusico que contengan el valor buscado
* \param pMusico nombre Array de nombre
* \param size int Tamaño del pMusico
* \param valorBuscado int Valor a buscar en el pMusico
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musico_bajaValorRepetidoInt(Musico *pMusico, int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(pMusico!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(pMusico[i].idMusico==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                pMusico[i].isEmpty=1;
                pMusico[i].idMusico=0;                                                                   //cambiar campo id
                pMusico[i].suInstrumento=0;                                                               //cambiar campo suInstrumento
                //pMusico[i].varFloat=0;                                                             //cambiar campo varFloat
                strcpy(pMusico[i].nombre,"");                                                   //cambiar campo nombre
                strcpy(pMusico[i].apellido,"");                                               //cambiar campo apellido
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param pMusico nombre Array de nombre
* \param size int Tamaño del pMusico
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int musico_modificar(Musico *pMusico, int sizeArray)                                //cambiar nombre
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(pMusico!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(musico_buscarID(pMusico,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n suInstrumento: %d\n nombre: %s\n apellido: %s",
                       posicion, pMusico[posicion].idMusico,pMusico[posicion].suInstrumento,pMusico[posicion].nombre,pMusico[posicion].apellido);
                utn_getChar("\nModificar: A B C D S(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,1,1,&pMusico[posicion].suInstrumento);           //mensaje + cambiar campo suInstrumento
                        break;
                    case 'B':
                                   //mensaje + cambiar campo varFloat
                        break;
                    case 'C':
                        utn_getName("\n: ","\nError",1,TEXT_SIZE,1,pMusico[posicion].nombre);                      //mensaje + cambiar campo nombre
                        break;
                    case 'D':
                        utn_getTexto("\n: ","\nError",1,TEXT_SIZE,1,pMusico[posicion].apellido);             //mensaje + cambiar campo apellido
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
/** \brief Ordena por campo XXXXX los elementos de un pMusico
* \param pMusico nombre Array de nombre
* \param size int Tamaño del pMusico
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int musico_ordenarPorString(Musico *pMusico,int size)                              //cambiar nombre
{
    int retorno=-1;
    int i, j;
    char bufferString[TEXT_SIZE];                               //cambiar campo nombre
    int bufferId;
    int bufferIsEmpty;

    int bufferInt;                                              //cambiar buffer int
    //float bufferFloat;                                          //cambiar buffer varFloat
    char bufferLongString[TEXT_SIZE];                           //cambiar campo apellido

    if(pMusico!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(bufferString,pMusico[i].nombre);                      //cambiar campo nombre
            bufferId=pMusico[i].idMusico;                                   //cambiar campo id
            bufferIsEmpty=pMusico[i].isEmpty;

            bufferInt=pMusico[i].suInstrumento;                                //cambiar campo suInstrumento
            //bufferFloat=pMusico[i].varFloat;                            //cambiar campo varFloat
            strcpy(bufferLongString,pMusico[i].apellido);          //cambiar campo apellido


            j = i - 1;
            while ((j >= 0) && strcmp(bufferString,pMusico[j].nombre)<0)         //cambiar campo nombre                 //Si tiene mas de un criterio se lo agrego, Ej. bufferInt<pMusico[j].suInstrumento
            {                                                                                                               //buffer < campo ascendente   buffer > campo descendente
                strcpy(pMusico[j + 1].nombre,pMusico[j].nombre);          //cambiar campo nombre
                pMusico[j + 1].idMusico=pMusico[j].idMusico;                                //cambiar campo id
                pMusico[j + 1].isEmpty=pMusico[j].isEmpty;

                pMusico[j + 1].suInstrumento=pMusico[j].suInstrumento;                        //cambiar campo suInstrumento
                //pMusico[j + 1].varFloat=pMusico[j].varFloat;                    //cambiar campo varFloat
                strcpy(pMusico[j + 1].apellido,pMusico[j].apellido);  //cambiar campo apellido

                j--;
            }
            strcpy(pMusico[j + 1].nombre,bufferString);                     //cambiar campo nombre
            pMusico[j + 1].idMusico=bufferId;                                        //cambiar campo id
            pMusico[j + 1].isEmpty=bufferIsEmpty;

            pMusico[j + 1].suInstrumento=bufferInt;                                                        //cambiar campo suInstrumento
            //pMusico[j + 1].varFloat=bufferFloat;                                                    //cambiar campo varFloat
            strcpy(pMusico[j + 1].apellido,bufferLongString);                                    //cambiar campo apellido
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un pMusico
* \param pMusico nombre Array de nombre
* \param size int Tamaño del pMusico
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int musico_listar(Musico *pMusico, int CANT_MUSICO)                      //cambiar  nombre
{
    int retorno=-1;
    int i;
    if(pMusico!=NULL && CANT_MUSICO>=0)
    {
        for(i=0;i<CANT_MUSICO;i++)
        {
            if(pMusico[i].isEmpty==1)
                continue;
            else
                printf("\n ID: %d\n suInstrumento: %d\n nombre: %s\n apellido: %s\n ",
                       pMusico[i].idMusico,pMusico[i].suInstrumento,pMusico[i].nombre,pMusico[i].apellido);      //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}

static int generateID(void)
{
    static int idMus = 0;
    return idMus++;
}

