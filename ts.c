#include "ts.h"

t_simbolo tabla_simbolos[2000];
int cantidad_simbolos = 0;	
char aux[30];
char aux2[30];

char prefijo_id[10] = PREFIJO_ID;
char prefijo_int[10] = PREFIJO_INT;
char prefijo_float[10] = PREFIJO_FLOAT;
char prefijo_string[10] = PREFIJO_STRING;
int cantidad_cte_string = 0;


/* borra todo el contenido de la tabla de simbolos, generalmente para ser borrado */
void vaciar_tabla_simbolos(){
	int i;
	for (i = 0; i < cantidad_simbolos; ++i)
	{
		free(tabla_simbolos[i].nombre);
		if(tabla_simbolos[i].valor_string != NULL)
			free(tabla_simbolos[i].valor_string);
	}
	cantidad_simbolos = 0;
}

/* le envias una de las constantes definidas en define.h y te devuelve un equivalente en string
seria como hacerle un toString al tipo de dato entero */
char * tipo_simbolo_to_string(int tipo){
	// printf("\n\n\n%d\n\n\n", tipo);
	switch(tipo) {
		case TIPO_STRING:
			return "STRING";
		case TIPO_FLOAT:
			return "FLOAT";
		case TIPO_INT:
			return "INT";
		case TIPO_PR:
			return "PR";
		default:
			return "DESCONOCIDO";
	}
}

/* imprime la tabla de simbolos a un archivo txt*/
void imprimir_tabla_simbolos() {
	FILE *f = fopen(PATH_TABLA_SIMBOLOS, "w");
	if (f == NULL)
	{
	    puts(ERROR_ABRIR_TABLA_SIMBOLOS);
	    exit(1);
	}
	int i;
	fprintf(f, "NOMBRE \t\t\t\t TIPO \t\t\t\t CONST\t\t\t\t LINEA\n\n");
	for (i = 0; i < cantidad_simbolos; ++i)
	{
		if(tabla_simbolos[i].tipo == TIPO_STRING)
		{
			fprintf(f, "%s\t\t\t\t%s\t\t\t\t%d\t\t\t\t%d \n",tabla_simbolos[i].nombre,tipo_simbolo_to_string(tabla_simbolos[i].tipo),tabla_simbolos[i].esConstante,tabla_simbolos[i].lineNumber);
			// if(tabla_simbolos[i].nombre[0] == '_')
			// {
			// 	fprintf(a, "\n");
			// 	fprintf(a, tabla_simbolos[i].nombre);			
			// 	fprintf(a, " db ?");
			// }
		}
	
		if(tabla_simbolos[i].tipo == TIPO_INT)
		{
			fprintf(f, "%s\t\t\t\t%s\t\t\t\t%d\t\t\t\t%d\n",tabla_simbolos[i].nombre,tipo_simbolo_to_string(tabla_simbolos[i].tipo),tabla_simbolos[i].esConstante,tabla_simbolos[i].lineNumber);
			// fprintf(a, "\n");
			// if(tabla_simbolos[i].nombre[1] == 'c' && tabla_simbolos[i].nombre[2] == 't' && tabla_simbolos[i].nombre[3] == 'e')
			// {
			// 	char *aux = newStr(tabla_simbolos[i].nombre);
			// 	fprintf(a, "_");
			// 	fprintf(a, aux);		
			// 	fprintf(a, " dd ");
			// 	char subbuff[5];
			// 	memcpy( subbuff, &aux[4], 1 );
			// 	subbuff[1] = '\0';
			// 	fprintf(a, subbuff);
			// 	fprintf(a, ".000000");
			// } else
			// {
			// 	fprintf(a, "\n");
			// 	fprintf(a, tabla_simbolos[i].nombre);			
			// 	fprintf(a, " dd 0");
			// }
		}
		
		if(tabla_simbolos[i].tipo == TIPO_FLOAT)
		{
			fprintf(f, "%s\t\t\t\t%s\t\t\t\t%d\t\t\t\t%d\n",tabla_simbolos[i].nombre,tipo_simbolo_to_string(tabla_simbolos[i].tipo),tabla_simbolos[i].esConstante,tabla_simbolos[i].lineNumber);
			// fprintf(a, "\n");
			// if(tabla_simbolos[i].nombre[1] == 'c' && tabla_simbolos[i].nombre[2] == 't' && tabla_simbolos[i].nombre[3] == 'e')
			// {
			// 	char *aux = newStr(tabla_simbolos[i].nombre);
			// 	fprintf(a, "_");
			// 	fprintf(a, aux);		
			// 	fprintf(a, " dd ");
			// 	char subbuff[5];
			// 	memcpy( subbuff, &aux[4], 6 );
			// 	subbuff[6] = '\0';
			// 	fprintf(a, subbuff);
			// } else
			// {
			// 	fprintf(a, "\n");
			// 	fprintf(a, tabla_simbolos[i].nombre);			
			// 	fprintf(a, " dd ?");
			// } 
		}
		
		// if(tabla_simbolos[i].tipo == TIPO_PR)
		// 	fprintf(f, "%s\t\t\t\t%s\t\t\t\t\n",tabla_simbolos[i].nombre,tipo_simbolo_to_string(tabla_simbolos[i].tipo));
				

	}
	fclose(f);
}

/** Esta funcion te permite agregar un simbolo a la tabla de simbolos.
	La idea es que se le envie el nombre del simbolo (Si es un id, el nombre
	de la variable con el  prefijo "_", el tipo de dato es un int definido
	 en las macro y el valor, en caso de que sea una constante)*/
void agregar_simbolo(char * nombre, int tipo, char * valor, int lineNumber,int esConstante) {
	int n;
	tabla_simbolos[cantidad_simbolos].nombre = malloc(sizeof(char) * strlen(nombre));
	strcpy(tabla_simbolos[cantidad_simbolos].nombre,nombre);


	tabla_simbolos[cantidad_simbolos].tipo = tipo;
	tabla_simbolos[cantidad_simbolos].esConstante = esConstante;
	tabla_simbolos[cantidad_simbolos].lineNumber = lineNumber;
	switch(tipo) {
		case TIPO_FLOAT:
			valor="0";
			tabla_simbolos[cantidad_simbolos].valor_float = atof(valor);
		break;
		case TIPO_STRING:
			if(valor != NULL) {
				tabla_simbolos[cantidad_simbolos].valor_string = malloc(sizeof(char) * strlen(valor));
				strcpy(tabla_simbolos[cantidad_simbolos].valor_string,valor);	
			} else {
				tabla_simbolos[cantidad_simbolos].valor_string = NULL;
			}
		break;
		case TIPO_INT:
			valor="0";
			tabla_simbolos[cantidad_simbolos].valor_int = atoi(valor);
		break;
		case TIPO_PR:
		break;
		default:
		puts("Tipo dato erroneo"); exit(1);
	}
	cantidad_simbolos++;


}


char * get_nombre_sin_prefijo(t_simbolo * p_simbolo)
{
	// printf("Prefijo int : %d\n",);
	if(!p_simbolo->esConstante)
		return p_simbolo->nombre + strlen(PREFIJO_ID);

	if(p_simbolo->tipo == TIPO_INT)
		return p_simbolo->nombre + strlen(PREFIJO_INT);

	if(p_simbolo->tipo == TIPO_STRING)
		return p_simbolo->nombre + strlen(PREFIJO_STRING);
	
	if(p_simbolo->tipo == TIPO_FLOAT)
		return p_simbolo->nombre + strlen(PREFIJO_FLOAT);
}

/* Busca una variable en la TS sin tener en cuenta sus prefijos y devuelve
el indice. si no lo encuentra, devuelve -1;*/
int buscar_en_TS_sin_prefijo(char * nombre, char * mjs_error, int lineNumber) {
	char * temp;
	int i;
	for (i = 0; i < cantidad_simbolos; ++i)
	{
		temp = get_nombre_sin_prefijo(&tabla_simbolos[i]	);
		// strcpy(temp,tabla_simbolos[i].nombre + 1);
		if(strcmp(temp,nombre) == 0) 
			return i;
	}
	if(mjs_error != NULL) 
		sprintf(mjs_error,VARIABLE_INEXISTENTE,nombre, lineNumber);
	return -1;
}

/* devuelve el indice del simbolo en la tabla. si no lo encuentra
devuelve -1
*/
int buscar_en_TS(char * nombre, char * mjs_error, int lineNumber) {
	int i;
	for (i = 0; i < cantidad_simbolos; ++i)
	{
		if(strcmp(tabla_simbolos[i].nombre,nombre) == 0) 
			return i;
	}
	if(mjs_error != NULL) 
		sprintf(mjs_error,VARIABLE_INEXISTENTE,nombre, lineNumber);
	return -1;
}


/* Agrega una variable a la TS*/
void agregar_variable_a_TS(char * nombre, char * tipo_str, int lineNumber) {
	// printf("agrego %s en linea %d\n",nombre,linecount );
	strcpy(aux2,nombre);
	poner_prefijo(aux2,prefijo_id);
	int index;
	//si ya existe en TS, tiro error y cierro programa
	if((index = buscar_en_TS(aux2, NULL,0)) >= 0) {
		printf(VARIABLE_REPETIDA,nombre,tabla_simbolos[index].lineNumber);
		exit(1);
	}

	int tipo = strcmp(tipo_str, "FLOAT") == 0 ? TIPO_FLOAT : strcmp(tipo_str, "INT") == 0 ? TIPO_INT : TIPO_STRING;
	agregar_simbolo(aux2,tipo,NULL,lineNumber,0);
}

/*Agrega una constante a la TS*/
void agregar_cte_a_TS(int tipo, char * valor_str, int valor_int,float valor_float, int lineNumber) {


	if(tipo == TIPO_STRING) {
		strcpy(aux2,prefijo_string);
		strcat(aux2, valor_str);
		if(buscar_en_TS_sin_prefijo(valor_str,NULL,0) != -1)
		return;

		cantidad_cte_string++;
		agregar_simbolo(aux2,tipo,NULL,lineNumber,1);


	}else if(tipo == TIPO_INT) {
		strcpy(aux2,prefijo_int);
		sprintf(aux,"%d",valor_int);
		strcat(aux2,aux);
		if(buscar_en_TS_sin_prefijo(aux,NULL,0) != -1)
		return;

		agregar_simbolo(aux2,tipo,aux,lineNumber,1);
		
	}else if(tipo == TIPO_FLOAT) {
		strcpy(aux2,prefijo_float);
		snprintf(aux,30,"%.4f",valor_float);
		strcat(aux2,aux);
		if(buscar_en_TS_sin_prefijo(aux,NULL,0) != -1)
		return;
		agregar_simbolo(aux2,tipo,aux,lineNumber,1);
		
	}
}

int traer_tipo_con_prefijo(char * nombre) {
	int index = buscar_en_TS(nombre, NULL,0);
	return tabla_simbolos[index].tipo;
}

/*Busca un simbolo en la TS por su nombre, y te devuelve su tipo */
int traer_tipo(char * nombre) {
	int index = buscar_en_TS_sin_prefijo(nombre, NULL,0);
	return tabla_simbolos[index].tipo;
}

/* 
Busca en la tabla de simbolos por nombre. Si los encuentra, devuelve 1 si son iguales,
o 0 si son distintos. Se le puede enviar un buffer de forma opcional para devolver
un mensaje de error
*/
int tipos_iguales(char * nombre1, char * nombre2, char * msj_error,int lineNumber) {

	int index1 = buscar_en_TS_sin_prefijo(nombre1,msj_error,lineNumber);
	int index2 = buscar_en_TS_sin_prefijo(nombre2,msj_error,lineNumber);

// printf("%s %s %d %d\n",nombre1,nombre2,index1,index2 );
	if(index1 == -1 || index2 == -1) {
		return 0;
	}

	int return_value = tabla_simbolos[index1].tipo == tabla_simbolos[index2].tipo;


	/* Si me pedian un mensaje de error, lo guardo en la variable*/
	if(!return_value && msj_error != NULL) {
		char tipo1[10];
		tabla_simbolos[index1].tipo == TIPO_STRING ? strcpy(tipo1,"STRING") : tabla_simbolos[index1].tipo == TIPO_FLOAT ? strcpy(tipo1,"FLOAT") : strcpy(tipo1,"INT");		
		char tipo2[10]; 
		tabla_simbolos[index2].tipo == TIPO_STRING ? strcpy(tipo2,"STRING") : tabla_simbolos[index2].tipo == TIPO_FLOAT ? strcpy(tipo2,"FLOAT") : strcpy(tipo2,"INT");		

		sprintf(msj_error,VARIABLE_ERROR_TIPOS,tipo1,tipo2, lineNumber);
	}
	// return 1;
	return tabla_simbolos[index1].tipo == tabla_simbolos[index2].tipo; 
}
