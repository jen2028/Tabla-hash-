#define m 80383
char *TablaHash[m];

void IniciarTablaHash(){
	int i;
	TablaHash[m]=malloc(sizeof(char));
	for(i=0;i<m;i++){
		TablaHash[i]=NULL;
	}
}

//////////////////////

int letraNum(char clave[],int i ){

	if(clave[i]=='á'&&clave[i]=='é'&&clave[i]=='í'&&clave[i]=='ó'&&clave[i]=='ú'){
		
		return 100;
		
	}
		if(clave[i]=='Á'&&clave[i]=='É'&&clave[i]=='Í'&&clave[i]=='Ó'&&clave[i]=='Ú'){
		
		return 120;
		
	}
		if(clave[i]=='a'&&clave[i]=='e'&&clave[i]=='i'&&clave[i]=='o'&&clave[i]=='u'){
		
		return 101;
		
	}
		if(clave[i]=='A'&&clave[i]=='E'&&clave[i]=='I'&&clave[i]=='O'&&clave[i]=='U'){
		
		return 121;
		
	}
	if(clave[i]=='ñ'){
		
		return 14;
		
	}if(clave[i]<'O'){
		
		return clave[i] - 'a';
		
	}
	
	return clave[i] - 'a'+1;
}

///////////////////////////////////

int FuncionHash(char clave[]){

	int tam_alfabeto=27;
	if(clave == NULL)return -1;
	long int radix=0;
	int i = 0;
	while((clave[i]!='\0')&&(i<5)){

		radix=radix+letraNum(clave,i)*pow(tam_alfabeto,i);
		i++;
		
	}
	return radix%m;
}

/////////////////////////////////

int InsertarClave(char *clave){
	int i;
	int posicion;
	posicion=FuncionHash(clave);
	posicion=abs(posicion);
	printf("Posicion en la tabla: %i\n",posicion);
	
	if(TablaHash[posicion]!=NULL){
		int intento=1;
	
		while(TablaHash[posicion]!=NULL){
			
		posicion=(FuncionHash(clave)+intento*intento)%m;
		intento++;
		return ;
		}
		
		if(TablaHash[posicion]==NULL){	
				TablaHash[posicion]=(char*)malloc(sizeof(char));
				TablaHash[posicion]=clave;		
		}

	}else{
			TablaHash[posicion]=clave;	
			printf("LA CLAVE ES: %s \n",TablaHash[posicion]);
	}

}
////////////////////

int BuscarClave(char *clave){
	int i,posicion,comparar;
	posicion=FuncionHash(clave);
		//printf("VALOR DE LA TABLA HASH ES %s --- VALOR DE LA CLAVE A BUSCAR ES % s",TablaHash[posicion],clave);
	for(i=0;i<m;i++){	
		if(TablaHash[posicion]==NULL){
	//		printf("la tabla esta vacia");
			return 0;
		}else{
		    comparar=strcmp(TablaHash[posicion],clave);
		    if(comparar==0){
	//	    	printf("palabra encontrada");
				return posicion;
			}
		}
		printf("%i \n",i);
		posicion=(FuncionHash(clave)+i*i)%m;
	}
	//printf("palabra no encontrada");
}
/////////////////
int ImprimirTablaHash() {
	
	int i;
	for (i=0;i<m;i++) {
	//	printf("%d- \n", i);
		if (TablaHash[i]!= NULL) {
			printf("Palabra insertada: %s \n",TablaHash[i]);
		} else {
			
		}
	}
}

//////////////

int AgregarArchivo(char *palabra){
    FILE *archivo = fopen("texto.txt", "a");
    fprintf(archivo, "%s\n",palabra);
    fclose(archivo);
    return 1;
}

///////////////

void LeerArchivo(char clave[]) {
	char c;
	int i, j;
	FILE *archivo;
	archivo = fopen("texto.txt", "r");
	
	while(fgets(clave, 18, (FILE*) archivo)) {
		InsertarClave(clave);
    }
	fclose(archivo);
}

