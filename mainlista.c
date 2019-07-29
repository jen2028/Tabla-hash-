#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include"thashlista.h"
int main(){	

	Nodo*t;
	char palabra;
	char opcion;
	TablaHash[m]=NULL;

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
                      iniciarTabla();
                     // LeerArchivo();//leer,contador
                      Imprimir(t);
                     // printf( "\n   Palabras procesadas: %d\n",contador);
                     // printf( "\n   Tamano de la tabla: %d\n",tamano);
    				 // printf( "\n   Nunmero de colisiones: %d \n",colisiones);//n maximo y minimo
                      break;

            case '2': printf( "\n  2. Ingrese palabras:\n");
            		  fflush( stdin );
                      scanf( "%c", &palabra);
                      AgregarArchivo(palabra);
                 //   InsertaClave(t,palabra);                
                      break;

            case '3': printf( "\n   3. Buscar palabra ingresada: \n" );
            		  fflush( stdin );
                      scanf( "%c", &palabra);
                      BuscarClave(t,palabra);
                      //TiempoDeBusqueda();
                      printf( "\n  La palabra buscada es: %d \n",palabra);
                      //printf( "\n  El tiempo de busqueda fue: %d \n",tiempo);
                        
         }

    } while ( opcion != '4' );

    return 0;
}
///////////////////
/*int main(){
	Nodo*t;
	char palabra;
	TablaHash[m]=NULL;
	t=iniciarTabla();
//	InsertaClave(t,palabra);
//	BuscarClave(t,palabra);
//	AgregarArchivo(palabra);
	LeerArchivo();
	Imprimir(t);
}*/
