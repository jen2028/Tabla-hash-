#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include <ctype.h>
#include"thashdircorregido.h"
int main(){	
	char clave[18];
    char opcion;
    char palabra[18];

    do
    {
    	printf("\n Menu de opciones de Tabla hash\n");
        printf( "\n   1. Mostrar tabla hash :");
        printf( "\n   2. Introducir palabra :");
        printf( "\n   3. Buscar palaba ingresada :");
        printf( "\n   4. Salir." );

        do
        {
            printf( "\n   Introduzca opcion (1-4): ");
            fflush( stdin );
            scanf( "%c", &opcion );
            system("cls");

        } while ( opcion < '1' || opcion > '4' );

        switch ( opcion )
        {
            case '1': printf( "\n   1. Mostrar Tabla hash:\n");
            		 //IniciarTablaHash();
                     LeerArchivo(clave);
                     ImprimirTablaHash();
            
                     
                     // printf( "\n   Palabras procesadas: %d\n",contador);
                      printf( "\n   Tamano de la tabla: %d\n",m);
    				 // printf( "\n   Nunmero de colisiones: %d \n",colisiones);//n maximo y minimo
                      break;

            case '2': printf( "\n  2. Ingrese palabras:\n");
            		  fflush( stdin );
                      scanf( "%s", &palabra);
                      AgregarArchivo(palabra);            
                      break;

            case '3': printf( "\n   3. Buscar palabra ingresada: \n" );
            		  fflush( stdin );
                      scanf( "%s", &clave);
                      BuscarClave(clave);
                      //TiempoDeBusqueda();
                      //printf( "\n  El tiempo de busqueda fue: %d \n",tiempo);
                        
         }

    } while ( opcion != '4' );

    return 0;
}
/*
int main(){
	char clave[18];
	IniciarTablaHash();
    LeerArchivo(clave);
    ImprimirTablaHash();
}*/
