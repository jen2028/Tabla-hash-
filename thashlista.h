#define m 100
typedef struct nodo{
	
	char clave;
	struct nodo *sgte;
	
}Nodo;

Nodo *TablaHash[m];

Nodo *iniciarTabla(){
	int i;
	Nodo *t;
	t = malloc(sizeof(TablaHash));
		for(i=0;i<m;i++){
		TablaHash[i]=NULL;
		printf("tabla hash[%d]-->",i);
		printf("%c -->\n",t->clave);
		}
	return t;	
}

int letraNum(char palabra){
	
	if(palabra=='ñ'){
		
		return 14;
		
	}if(palabra<'O'){
		
		return palabra - 'a';
		
	}
	
	return palabra - 'a'+1;
}

int Hash(char palabra){
	int tam_alfabeto=27;
	long int radix=0;
	int i=0;
	while((palabra!='\0')&&(i<7)){
		
		radix=radix+letraNum(palabra)*pow(tam_alfabeto,i);
		i++;
		
	}
	
	return(radix%m);
}
////

Nodo *InsertaClave(Nodo *t,char palabra){ 
	printf("palabra; %s",palabra);
  	int indice = Hash(palabra);
  	Nodo *nuevo_nodo;
  	nuevo_nodo=TablaHash[indice];
  	
    if(nuevo_nodo==NULL){
    	nuevo_nodo=malloc(sizeof(Nodo));
    	nuevo_nodo->clave=palabra;
    	nuevo_nodo->sgte=NULL;
    	TablaHash[indice]=nuevo_nodo;
    	
	}else{
		
		while(nuevo_nodo!=NULL){
			nuevo_nodo=nuevo_nodo->sgte;
		}
		nuevo_nodo=malloc(sizeof(Nodo));
    	nuevo_nodo->clave=palabra;
    	nuevo_nodo->sgte=NULL;
    	TablaHash[indice]=nuevo_nodo;
		
	}

}


int BuscarClave(Nodo *t,char palabra){ 

    int indice = Hash(palabra); 
    Nodo *nuevo_nodo=TablaHash[indice];
    if(nuevo_nodo == NULL){ 
    
        while (nuevo_nodo != NULL) { 
        
            if (nuevo_nodo->clave == palabra) { 
            
	         return palabra;
	         
            } 
            nuevo_nodo = nuevo_nodo->sgte;
        } 
    }else{
    	
    	return;
	}

}

int AgregarArchivo(char palabra){
    FILE *archivo = fopen("texto.txt", "a");
    fprintf(archivo, "%c\n",palabra);
    fclose(archivo);
    return 1;
}

Nodo *LeerArchivo(){
	FILE *archivo;
	Nodo*t;
	t=NULL;
	char palabra[1024];
	char linea[1024];
	int contador,total;
	archivo=fopen("texto.txt","r");
    while(fgets(palabra, 1024, (FILE*) archivo)) {
        printf("LA PALABBRA ES: %s \n", palabra);
       // t=InsertaClave(t,palabra); 
        
    }	
	fclose(archivo);
	return (t);	
}
void Imprimir(Nodo *t) {
   int i;
   Nodo *aux;
   int posicion=0;
	
   for(i=0;i<m;i++) {
	
      if(TablaHash[i] != NULL){
      		printf(" (%c)",aux->clave);
	  }else{
	  	 printf("NULL \n");
	  }

   }
	
   printf("\n");
}
