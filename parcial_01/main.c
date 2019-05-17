#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "orquesta.h"
#include "instrumento.h"
#include "musico.h"
#define CANT_ORQUESTA 50
#define SORT_UP 1
#define SORT_DOWN 0
#define CANT_MUSICO 1000
#define CANT_INSTRUMENTO 20
int main()
{
    int opcion;
    int contadorId=0;                   //cambiar

    Orquesta pOrquesta[CANT_ORQUESTA];
    Musico pMusico[CANT_MUSICO];
    Instrumento pInstrumento [CANT_INSTRUMENTO];               //cambiar
    orquesta_Inicializar(pOrquesta,CANT_ORQUESTA);                   //cambiar


    do
    {
        utn_getUnsignedInt("\n\n1) Agregar Orquesta\n2) Eliminar Orquesta \n3) Imprimir orquesta \n4) Agregar Musico \n5) Modificar musico(no esta) \n6) Eliminar Musico\n 7)Imprimir musicos(falta modificar)\n 8)Agregar instrumentos\n 9)Imprimir instrumentos\n",                   //cambiar
                      "\nError",1,sizeof(int),1,10,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta
                orquesta_alta(pOrquesta,CANT_ORQUESTA,&contadorId);                   //cambiar
                break;

            case 2: //Modificar
                orquesta_baja(pOrquesta,CANT_ORQUESTA);
                //orquesta_modificar(pOrquesta,CANT_ORQUESTA);                   //cambiar
                break;

            case 3: //Baja
                orquesta_listar(pOrquesta,CANT_ORQUESTA);                   //cambiar
                break;

            case 4://Listar
               musico_Inicializar(pMusico,CANT_MUSICO);
               musico_alta(pMusico,CANT_MUSICO,&contadorId);                  //cambiar
                break;

            case 5://Ordenar
                                  //cambiar
                break;

            case 6:
                 musico_baja(pMusico,CANT_MUSICO);
                break;

             case 7:
                musico_listar(pMusico,CANT_MUSICO);
                    break;

             case 8:
                 instrumento_Inicializar(pInstrumento,CANT_INSTRUMENTO);
                 instrumento_alta(pInstrumento,CANT_INSTRUMENTO,&contadorId);
                    break;


             case 9:
                 instrumento_listar(pInstrumento,CANT_INSTRUMENTO);
                    break;

             case 10:
                    break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=10);
    return 0;
}
