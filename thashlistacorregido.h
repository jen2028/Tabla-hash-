#define m 27
typedef struct nodo{
	
	char *clave;
	struct nodo *sgte;
	
}Nodo;

Nodo *TablaHash[m];

/////////////////////////

Nodo *iniciarTabla(){
	int i;
	Nodo *t;
	t = malloc(sizeof(Nodo));
		for(i=0;i<m;i++){
		TablaHash[i]=NULL;

		}
	return t;	
}

/////////////////////////

int letraNum(char *palabra,int i){
	
	if(palabra[i]=='ñ'){
		
		return 14;
		
	}if(palabra[i]<'O'){
		
		return palabra[i] - 'a';
		
	}
	
	return palabra[i] - 'a'+1;
}

///////////////////////

int Hash(char *palabra){
	int tam_alfabeto=27;
	long int radix=0;
	int i=0;
	while((palabra!='\0')&&(i<5)){
		
		radix=radix+letraNum(palabra,i)*pow(tam_alfabeto,i);
		printf("radix ; %i\n",radix);
		i++;
		
	}
	
	return(radix%m);
}
///////////////////////////
Nodo *CrearNodo(char *palabra){
	
	int longitud = strlen(palabra);
	Nodo *aux;
	aux = (Nodo *)malloc(sizeof(Nodo));
	aux->clave = (char *)malloc(sizeof(char)*(longitud+1));
	strcpy(aux->clave,palabra);
	aux->sgte = NULL;

    return aux;
}
///////////////////////

Nodo *InsertaClave(Nodo *t,char *palabra){
	
	int indice,colision,posicion;
	Nodo *aux1,*aux2;	
	posicion=Hash(palabra);
//	posicion=abs(posicion);
	printf("la posicion es : %i \n\n",posicion);
	
	if(TablaHash[posicion]==NULL){
		
		t=CrearNodo(palabra);
		TablaHash[posicion]=t;
		return t;
		
	}else{

		for(aux2=TablaHash[posicion];aux2->sgte!=NULL;aux2=aux2->sgte){
			
			aux2->sgte=t;
			colision++;

		}
		printf("Numero de colisiones %i\n",colision);	
		t=CrearNodo(palabra);
		TablaHash[posicion]=t;
		return t;
	}
	
}

///////////////////////////////////


int BuscarClave(char *palabra){ 

    int indice = Hash(palabra); 
    Nodo *aux1=TablaHash[indice];
    
	for(aux1=TablaHash[indice];aux1->sgte!=NULL;aux1=aux1->sgte){
		
		if(strcmp(aux1->clave,palabra)==0){
			
			printf("Palabra encontrada");
			return indice;
			
		}
		
	}
	return -1;

}
////////////////////////////////////////////

int AgregarArchivo(char palabra){
    FILE *archivo = fopen("texto.txt", "a");
    fprintf(archivo, "%c\n",palabra);
    fclose(archivo);
    return 1;
}

//////////////////////////////////////////////

Nodo *LeerArchivo(){
	FILE *archivo;
	Nodo*t;
	t=NULL;
	char palabra[1024];
	char linea[1024];
	int contador=1,total;
	archivo=fopen("texto.txt","r");
    while(fgets(palabra, 1024, (FILE*) archivo)) {
        InsertaClave(t,palabra); 
        printf("Palabras procesadas: %i \n",contador);
        contador++;
    }	
	fclose(archivo);
	return (t);	
}

///////////////////////////////////////////

void Imprimir(Nodo *t) {
	
	Nodo *aux2;
	for(aux2=t;aux2!=NULL;aux2=aux2->sgte){
		
		
		printf("EL TEXTO ES = %s \n",aux2->clave);
		
	}
	
////////////////////////////////////	
	
	
/*  int i,j;
   Nodo *aux;
   int posicion=0;
	
	for(i=0;i<m;i++){
		aux=TablaHash[i];
		if(aux==NULL){
			printf("No hay elementos");
			
		}else{
			printf("Arreglo [%i] = ");
			while(aux!=NULL){
				
				printf(" %s ",aux->clave);
				aux=aux->sgte;
			}
			printf("\n");
		}	
		
	}

   printf("\n");*/
}
