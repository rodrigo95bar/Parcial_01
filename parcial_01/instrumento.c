#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "instrumento.h" //cambiar por nombreInstrumento entidad
#define sinfonica 1
#define filarmonica 2
#define camara 3
#define cuerdas 1
#define viento_madera 2
#define viento_metal 3
#define percusion 4


static int generateID(void);

/** \brief  To indicate that all position in the pInstrumento are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the pInstrumento
* \param pInstrumento nombreInstrumento Array of nombreInstrumento
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int instrumento_Inicializar(Instrumento *pInstrumento, int size)                                    //cambiar nombreInstrumento
{
    int retorno=-1;
    if(pInstrumento!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            pInstrumento[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer apellido vacio en un pInstrumento
* \param pInstrumento nombreInstrumento Array de nombreInstrumento
* \param size int Tamaño del pInstrumento
* \param posicion int* Puntero a la posicion del pInstrumento donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un apellido vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int instrumento_buscarEmpty(Instrumento *pInstrumento, int size, int* posicion)                    //cambiar nombreInstrumento
{
    int retorno=-1;
    int i;
    if(pInstrumento!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(pInstrumento[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un pInstrumento y devuelve la posicion en que se encuentra
* \param pInstrumento nombreInstrumento Array de nombreInstrumento
* \param size int Tamaño del pInstrumento
* \param posicion int* Puntero a la posicion del pInstrumento donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int instrumento_buscarID(Instrumento *pInstrumento, int size, int valorBuscado, int* posicion)                    //cambiar nombreInstrumento
{
    int retorno=-1;
    int i;
    if(pInstrumento!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(pInstrumento[i].isEmpty==1)
                continue;
            else if(pInstrumento[i].idInstrumento==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Busca un int en un pInstrumento y devuelve la posicion en que se encuentra
* \param pInstrumento nombreInstrumento Array de nombreInstrumento
* \param size int Tamaño del pInstrumento
* \param posicion int* Puntero a la posicion del pInstrumento donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int instrumento_buscarInt(Instrumento *pInstrumento, int size, int valorBuscado, int* posicion)                    //cambiar nombreInstrumento
{
    int retorno=-1;
    int i;
    if(pInstrumento!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(pInstrumento[i].isEmpty==1)
                continue;
            else if(pInstrumento[i].instrumento==valorBuscado)                                                   //cambiar campo instrumento
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
/** \brief Busca un string en un pInstrumento
* \param pInstrumento nombreInstrumento Array de nombreInstrumento
* \param size int Tamaño del pInstrumento
* \param posicion int* Puntero a la posicion del pInstrumento donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int instrumento_buscarString(Instrumento *pInstrumento, int size, char* valorBuscado, int* indice)                    //cambiar nombreInstrumento
{
    int retorno=-1;
    int i;
    if(pInstrumento!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(pInstrumento[i].isEmpty==1)
                continue;
            else if(strcmp(pInstrumento[i].nombreInstrumento,valorBuscado)==0)                                        //cambiar campo nombreInstrumento
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
/** \brief Solicita los datos para completar la primer posicion vacia de un pInstrumento
* \param pInstrumento nombreInstrumento Array de nombreInstrumento
* \param size int Tamaño del pInstrumento
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int instrumento_alta(Instrumento *pInstrumento, int size, int* contadorID)                          //cambiar nombreInstrumento
{
    int retorno=-1;
    int posicion;
    generateID();
    if(pInstrumento!=NULL && size>0 && contadorID!=NULL)
    {
        if(instrumento_buscarEmpty(pInstrumento,size,&posicion)==-1)                          //cambiar nombreInstrumento
        {
            printf("\nNo hay espacios vacios");
        }
        else
        {
            (*contadorID)++;
            pInstrumento[posicion].idInstrumento=*contadorID;                                                       //campo ID
            pInstrumento[posicion].isEmpty=0;




            utn_getName("Ingrese nombreInstrumento de instrumento\n: ","\nError",1,TEXT_SIZE,1,pInstrumento[posicion].nombreInstrumento);

            utn_getUnsignedInt("Ingrese tipo de Instrumento \n 1) Cuerdas \n 2) Viento-madera \n 3) viento-Metal \n 4) Percusion \n:","\nError",1,sizeof(int),1,4,1,&pInstrumento[posicion].instrumento);



            printf("\n ID: %d\n \n nombreInstrumento: %s\n Su Instrumento es de tipo: %d",
                   pInstrumento[posicion].idInstrumento,pInstrumento[posicion].nombreInstrumento,pInstrumento[posicion].instrumento);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del pInstrumento por ID
* \param pInstrumento nombreInstrumento Array de nombreInstrumento
* \param size int Tamaño del pInstrumento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int instrumento_baja(Instrumento *pInstrumento, int sizeArray)                                      //cambiar nombreInstrumento
{
    int retorno=-1;
    int posicion;
    int id;
    if(pInstrumento!=NULL && sizeArray>0)


    {
        utn_getUnsignedInt("\nID de Instrumento a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(instrumento_buscarID(pInstrumento,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            pInstrumento[posicion].isEmpty=1;
            pInstrumento[posicion].idInstrumento=0;                                                                   //cambiar campo id
            pInstrumento[posicion].instrumento=0;                                                               //cambiar campo instrumento
            //pInstrumento[posicion].varFloat=0;                                                             //cambiar campo varFloat
            strcpy(pInstrumento[posicion].nombreInstrumento,"");                                                   //cambiar campo nombreInstrumento
            //strcpy(pInstrumento[posicion].apellido,"");                                               //cambiar campo apellido
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del pInstrumento que contengan el valor buscado
* \param pInstrumento nombreInstrumento Array de nombreInstrumento
* \param size int Tamaño del pInstrumento
* \param valorBuscado int Valor a buscar en el pInstrumento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int instrumento_bajaValorRepetidoInt(Instrumento *pInstrumento, int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(pInstrumento!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(pInstrumento[i].idInstrumento==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                pInstrumento[i].isEmpty=1;
                pInstrumento[i].idInstrumento=0;                                                                   //cambiar campo id
                pInstrumento[i].instrumento=0;                                                               //cambiar campo instrumento
                //pInstrumento[i].varFloat=0;                                                             //cambiar campo varFloat
                strcpy(pInstrumento[i].nombreInstrumento,"");                                                   //cambiar campo nombreInstrumento
                //strcpy(pInstrumento[i].apellido,"");                                               //cambiar campo apellido
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param pInstrumento nombreInstrumento Array de nombreInstrumento
* \param size int Tamaño del pInstrumento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
/*int instrumento_modificar(Instrumento *pInstrumento, int sizeArray)                                //cambiar nombreInstrumento
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(pInstrumento!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(instrumento_buscarID(pInstrumento,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n instrumento: %d\n nombreInstrumento: %s\n apellido: %s",
                       posicion, pInstrumento[posicion].idInstrumento,pInstrumento[posicion].instrumento,pInstrumento[posicion].nombreInstrumento,pInstrumento[posicion].apellido);
                utn_getChar("\nModificar: A B C D S(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,1,1,&pInstrumento[posicion].instrumento);           //mensaje + cambiar campo instrumento
                        break;
                    case 'B':
                                   //mensaje + cambiar campo varFloat
                        break;
                    case 'C':
                        utn_getName("\n: ","\nError",1,TEXT_SIZE,1,pInstrumento[posicion].nombreInstrumento);                      //mensaje + cambiar campo nombreInstrumento
                        break;
                    case 'D':
                        utn_getTexto("\n: ","\nError",1,TEXT_SIZE,1,pInstrumento[posicion].apellido);             //mensaje + cambiar campo apellido
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
*/
//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un pInstrumento
* \param pInstrumento nombreInstrumento Array de nombreInstrumento
* \param size int Tamaño del pInstrumento
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int instrumento_ordenarPorString(Instrumento *pInstrumento,int size)                              //cambiar nombreInstrumento
{
    int retorno=-1;
    int i, j;
    char bufferString[TEXT_SIZE];                               //cambiar campo nombreInstrumento
    int bufferId;
    int bufferIsEmpty;

    int bufferInt;                                              //cambiar buffer int
    //float bufferFloat;                                          //cambiar buffer varFloat
    //char bufferLongString[TEXT_SIZE];                           //cambiar campo apellido

    if(pInstrumento!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(bufferString,pInstrumento[i].nombreInstrumento);                      //cambiar campo nombreInstrumento
            bufferId=pInstrumento[i].idInstrumento;                                   //cambiar campo id
            bufferIsEmpty=pInstrumento[i].isEmpty;

            bufferInt=pInstrumento[i].instrumento;                                //cambiar campo instrumento
            //bufferFloat=pInstrumento[i].varFloat;                            //cambiar campo varFloat
            //strcpy(bufferLongString,pInstrumento[i].apellido);          //cambiar campo apellido


            j = i - 1;
            while ((j >= 0) && strcmp(bufferString,pInstrumento[j].nombreInstrumento)<0)         //cambiar campo nombreInstrumento                 //Si tiene mas de un criterio se lo agrego, Ej. bufferInt<pInstrumento[j].instrumento
            {                                                                                                               //buffer < campo ascendente   buffer > campo descendente
                strcpy(pInstrumento[j + 1].nombreInstrumento,pInstrumento[j].nombreInstrumento);          //cambiar campo nombreInstrumento
                pInstrumento[j + 1].idInstrumento=pInstrumento[j].idInstrumento;                                //cambiar campo id
                pInstrumento[j + 1].isEmpty=pInstrumento[j].isEmpty;

                pInstrumento[j + 1].instrumento=pInstrumento[j].instrumento;                        //cambiar campo instrumento
                //pInstrumento[j + 1].varFloat=pInstrumento[j].varFloat;                    //cambiar campo varFloat
                //strcpy(pInstrumento[j + 1].apellido,pInstrumento[j].apellido);  //cambiar campo apellido

                j--;
            }
            strcpy(pInstrumento[j + 1].nombreInstrumento,bufferString);                     //cambiar campo nombreInstrumento
            pInstrumento[j + 1].idInstrumento=bufferId;                                        //cambiar campo id
            pInstrumento[j + 1].isEmpty=bufferIsEmpty;

            pInstrumento[j + 1].instrumento=bufferInt;                                                        //cambiar campo instrumento
            //pInstrumento[j + 1].varFloat=bufferFloat;                                                    //cambiar campo varFloat
            //strcpy(pInstrumento[j + 1].apellido,bufferLongString);                                    //cambiar campo apellido
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un pInstrumento
* \param pInstrumento nombreInstrumento Array de nombreInstrumento
* \param size int Tamaño del pInstrumento
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int instrumento_listar(Instrumento *pInstrumento, int CANT_INSTRUMENTO)                      //cambiar  nombreInstrumento
{
    int retorno=-1;
    int i;
    if(pInstrumento!=NULL && CANT_INSTRUMENTO>=0)
    {
        for(i=0;i<CANT_INSTRUMENTO;i++)
        {
            if(pInstrumento[i].isEmpty==1)
                continue;
            else
                printf("\n ID: %d\n nombre Instrumento: %s\n Tipo Instrumento %d",
                       pInstrumento[i].idInstrumento,pInstrumento[i].nombreInstrumento,pInstrumento[i].instrumento);      //cambiar todos
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

