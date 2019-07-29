#define m 100
char *TablaHash[m];

void IniciarTablaHash(){
	int i;
	TablaHash[m]=malloc(sizeof(char));
	for(i=0;i<m;i++){
		TablaHash[i]=NULL;
	}
}

int letraNum(char clave[],int i ){
	
	if(clave[i]=='ñ'){
		
		return 14;
		
	}if(clave[i]<'O'){
		
		return clave[i] - 'a';
		
	}
	
	return clave[i] - 'a'+1;
}
int FuncionHash(char clave[]){

	int tam_alfabeto=27;
	if(clave == NULL)return -1;
	long int radix=0;
	int i = 0;
	while((clave[i]!='\0')&&(i<7)){

		radix=radix+letraNum(clave,i)*pow(tam_alfabeto,i);
		i++;
		
	}
	return radix%m;
}

int InsertarClave(char *clave){
	int i;
	int posicion;
	posicion=FuncionHash(clave);
	posicion=abs(posicion);
	printf("Posicion en la tabla: %i\n",posicion);
	
	if(TablaHash[posicion]!=NULL){
		int intento=0;
	
		while(TablaHash[posicion]!=NULL){
			
		posicion=(FuncionHash(clave)+intento*intento)%m;
		intento++;
		return;
		}
		
		if(TablaHash[posicion]==NULL){	
				//TablaHash[posicion]=(char*)malloc(sizeof(char));
				TablaHash[posicion]=clave;		
		}

	}else{
		
			TablaHash[posicion]=clave;	
			printf("LA CLAVE ES: %s \n",TablaHash[posicion]);
	}

}
int BuscarClave(char clave[]){
	int i,posicion;
	for(i=0;i<m;i++){
		posicion=FuncionHash(clave);
		if(TablaHash[posicion]==NULL){
			return -1;
		}else if(TablaHash[posicion]==clave){
				return posicion;
		}
	}
}

int ImprimirTablaHash() {
	int i;
	for (i=0;i<m;i++) {
		printf("%d- \n", i);
		if (TablaHash[i]!= NULL) {
			printf("Palabra insertada: %s \n",TablaHash[i]);
		} else {
			
		}
	}
}
int AgregarArchivo(char *palabra){
    FILE *archivo = fopen("texto.txt", "a");
    fprintf(archivo, "%c\n",palabra);
    fclose(archivo);
    return 1;
}

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

