%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
#include "structs.h"
#include "defines.h"
#include "arbol.h"
#include "pila.h"
#include "cola.h"

#define DEBUG 1
extern YYSTYPE yylval;
char prefijo_id[10] = PREFIJO_ID;
char prefijo_int[10] = PREFIJO_INT;
char prefijo_float[10] = PREFIJO_FLOAT;
char prefijo_string[10] = PREFIJO_STRING;
char temp_variables[MAX_VARIABLES][30];
char temp_tipo_dato[MAX_VARIABLES][10];
int variables_a_agregar= 0;
char aux[30];
char aux2[30];
int cantidad_cte_string = 0;
int buscar_en_TS_sin_prefijo(char * nombre, char * mjs_error , int lineNumber );
int buscar_en_TS(char * nombre, char * mjs_error, int lineNumber);
void agregar_simbolo(char * nombre, int tipo, char * valor,char * alias,int lineNumber,int esConstante);
void agregar_variable_a_TS(char * nombre, char * tipo,int lineNumber);
void agregar_cte_a_TS(int tipo, char * valor_str, int valor_int,float valor_float,int lineNumber);
void agregar_cte_a_TS_sin_prefijo(int tipo, char * valor_str, int valor_int,float valor_float,int lineNumber);
void error_lexico(char * mensaje);
int tipos_iguales(char * nombre1, char * nombre2, char * mjs_error, int lineNumber);
int traer_tipo(char * nombre);
void poner_prefijo(char * str, char * prefijo);
void copiar_sin_finalizador(char * dest,char * orig); 
void reemplazar(char * cad, char old,char new, int size) ;
char *newStr (char *charBuffer);
char * substring(char * str , int start, int end);
char * get_nombre_sin_prefijo(t_simbolo *);
int traer_tipo_con_prefijo(char * nombre);

extern int linecount;
static t_info_sentencias * p_info_iguales;
static FILE *a;
static char asig_final[80];
static char asig_iguales[80];
static char sent_final[80];
static char string_saltos[1];
static char string_cond[5];



int yylex();

FILE  *yyin; //Archivo de Entrada
%}

/* PARA OBTENER LOS VALORES Y PASAR A TS*/
%union {
int intval;
float val;
char *str_val;
}
%start pgm

%token <str_val>TOKEN_ID
%token <intval>CONST_INT
%token <str_val>CONST_STR
%token <val>CONST_FLOAT

%type <str_val>tipo_dato
%type <str_val> expresion
%type <str_val> termino
%type <str_val> factor
%type <str_val> comparador
%type <str_val> sentencia
%type <str_val> iguales
%type <str_val> filter
%type <str_val> salida
%type <str_val> entrada
// %type <str_val> factor_str

%token PR_MAIN
%token PR_IGUALES
%token PR_FILTER
%token PR_WRITE
%token PR_READ
%token PR_IF
%token PR_THEN
%token PR_ENDIF
%token PR_ELSE
%token PR_NOT
%token PR_WHILE
%token PR_DO
%token PR_ENDWHILE
%token PAR_ABRE
%token PAR_CIERRA
%token COR_ABRE
%token COR_CIERRA
%token <str_val>COMA
%token OP_LOG_AND
%token OP_LOG_OR
%token OP_SUMA
%token OP_RESTA
%token OP_MUL
%token OP_DIV
%token<str_val> OP_MAYOR
%token<str_val> OP_MAYOR_IGUAL
%token<str_val> OP_MENOR
%token<str_val> OP_MENOR_IGUAL
%token<str_val> OP_DISTINTO
%token<str_val> OP_IGUAL_IGUAL
%token OP_IGUAL
%token PR_AS
%token PR_DIM
%token OP_FILTER
%token <str_val> PR_FLOAT
%token <str_val> PR_INT
%token <str_val> PR_STRING
%token OP_CONCAT
%token PUNTO_Y_COMA
%%

pgm : programa 
{
	puts("COMPILACION EXITOSA\n");
	puts("-------------------\n");
};

programa : PR_MAIN declaracion_variables lista_sentencias
{

	// nodo_declaracion_variable = nodo_sentencias;

	if(DEBUG){
		puts("Codigo con variables\n");
		puts("-------------------\n");
	}

};

programa : PR_MAIN lista_sentencias
{
	if(DEBUG){
		puts("Codigo sin variables\n");
		puts("-------------------\n");
	}
};

sentencia : asignacion PUNTO_Y_COMA
{
	if(DEBUG) {
		puts("sentencia : asignacion PUNTO_Y_COMA\n");
		puts("-------------------\n");		
	}
};


lista_sentencias : sentencia
{
	if(DEBUG){
		puts("Una sola sentencia\n");
		puts("-------------------\n");
	}
};

lista_sentencias : sentencia lista_sentencias
{
	if(DEBUG) {
		puts("Varias sentencias\n");
		puts("-------------------\n");
	}
};

sentencia : condicional 
{

	// nodo_sentencia = nodo_condicional;
	if(DEBUG) {
		puts("sentencia : condicional \n");
		puts("-------------------\n");		
	}
};


sentencia : iteracion
{
	if(DEBUG) {
		puts("sentencia : iteracion\n");
		puts("-------------------\n");		
	}
};

sentencia : io PUNTO_Y_COMA
{
	if(DEBUG) {
		puts("Operacion de entrada salidas\n");
		puts("-------------------\n");		
	}
};

sentencia : iguales PUNTO_Y_COMA
{
	if(DEBUG) {
		puts("Operacion de iguales\n");
		puts("-------------------\n");	
	}
}

sentencia : filter PUNTO_Y_COMA
{
	if(DEBUG) {
		puts("Operacioon de filters\n");
		puts("-------------------\n");
	}
}

iguales : PR_IGUALES PAR_ABRE expresion COMA COR_ABRE lista_expresiones COR_CIERRA PAR_CIERRA 
{
	if(DEBUG) {
		puts("iguales : PR_IGUALES PAR_ABRE expresion COMA COR_ABRE lista_expresiones COR_CIERRA PAR_CIERRA\n");
		puts("-------------------\n");
	}
	$$ = "IGUALES";
}

lista_expresiones : expresion COMA lista_expresiones
{
	if(DEBUG) {
		puts("Lista de expresiones\n");
		puts("-------------------\n");		
	}
}

lista_expresiones : expresion
{
	if(DEBUG) {
		puts("Última expresion\n");
		puts("-------------------\n");		
	}
}

filter : PR_FILTER PAR_ABRE condicion_filter COMA COR_ABRE lista_variables COR_CIERRA PAR_CIERRA
{
	if(DEBUG) {
		puts("filter : PR_FILTER PAR_ABRE condicion COMA COR_ABRE lista_variables COR_CIERRA PAR_CIERRA\n");
		puts("-------------------\n");
	}
	$$ = "FILTER";
}

condicion_filter : comparacion_filter
{
	puts("condicion_filter : comparacion_filter\n");
	puts("-------------------\n");
}

condicion_filter : comparacion_filter OP_LOG_AND comparacion_filter
{
	puts("condicion_filter : comparacion_filter and comparacion_filter\n");
	puts("-------------------\n");
}

condicion_filter : comparacion_filter OP_LOG_OR comparacion_filter
{
	puts("condicion_filter : comparacion_filter or comparacion_filter\n");
	puts("-------------------\n");
}

comparacion_filter : OP_FILTER comparador expresion
{
	puts("comparacion_filter : OP_FILTER comparador expresion\n");
	puts("-------------------\n");
}

// comparacion_filter : PR_NOT OP_FILTER comparador expresion
// {
// 	puts("comparacion_filter : PR_NOT OP_FILTER comparador expresion\n");
// 	puts("-------------------\n");
// }

lista_variables : TOKEN_ID COMA lista_variables
{
	if(DEBUG) {
		puts("Lista de variables\n");
		puts("-------------------\n");		
	}
}

lista_variables : TOKEN_ID
{
	if(DEBUG) {
		puts("Ultima variable\n");
		puts("-------------------\n");
	}
}

io : entrada
{
	if(DEBUG) {
		puts("io : entrada\n");
		puts("-------------------\n");
	}
}

io : salida
{
	if(DEBUG) {
		puts("io : salida\n");
		puts("-------------------\n");		
	}
}

entrada : PR_READ TOKEN_ID
{
	if(DEBUG) {
		puts("entrada : READ id\n");
		puts("-------------------\n");		
	}
	char mjs[50];
	if(buscar_en_TS_sin_prefijo($2,mjs,linecount) == -1)
	{
		puts(mjs);
		exit(1);
	}
}

salida : PR_WRITE TOKEN_ID
{
	if(DEBUG) {
		puts("salida : PR_WRITE id\n");
		puts("-------------------\n");
	}

	char mjs[50];
	if(buscar_en_TS_sin_prefijo($2,mjs,linecount) == -1)
	{
		puts(mjs);
		exit(1);
	}

}

salida : PR_WRITE CONST_STR
{
	if(DEBUG) {
		puts("salida : PR_WRITE cte\n");
		puts("-------------------\n");	
	}

}

condicional : PR_IF PAR_ABRE condicion PAR_CIERRA then PR_ENDIF
{
	if(DEBUG) {
		puts("Condicional sin ELSE\n");
		puts("-------------------\n");
	}
}

condicional : PR_IF PAR_ABRE condicion PAR_CIERRA then else PR_ENDIF
{


	if(DEBUG) {
		puts("Condicional con ELSE\n");
		puts("-------------------\n");	
	}
}

then : PR_THEN lista_sentencias
{
	if(DEBUG) {
		puts("PR_THEN lista_sentencias\n");
		puts("-------------------\n");	
	}

}

else : PR_ELSE lista_sentencias
{
	if(DEBUG) {
		puts("PR_ELSE lista_sentencias\n");
		puts("-------------------\n");	
	}
}

condicion : comparacion
{
	if(DEBUG) {
		puts("condicion : comparacion\n");
		puts("-------------------\n");
	}
}

condicion : comparacion OP_LOG_AND comparacion
{
	if(DEBUG) {
		puts("condicion : comparacion and comparacion\n");
		puts("-------------------\n");		
	}
}

condicion : comparacion OP_LOG_OR comparacion
{
	if(DEBUG) {
		puts("condicion : comparacion or comparacion\n");
		puts("-------------------\n");		
	}
}

comparacion : expresion comparador expresion
{
	if(DEBUG) {
		puts("comparacion : expresion comparador expresion\n");
		puts("-------------------\n");
	}
	char mjs_error[60];
	/* comparo que para operar entre terminos, ambos tengan el mismo tipo de datos*/ 
	if(!tipos_iguales($1,$3,mjs_error,linecount)) 
	{
		puts(mjs_error);
		exit(1);
	}
}

comparacion : PR_NOT expresion
{
	if(DEBUG) {
		puts("comparacion : PR_NOT expresion comparador expresion\n");
		puts("-------------------\n");
	}
}

iteracion : PR_WHILE PAR_ABRE condicion PAR_CIERRA PR_DO lista_sentencias PR_ENDWHILE
{
	if(DEBUG) {
		puts("iteracion : PR_WHILE PAR_ABRE condicion PAR_CIERRA PR_DO lista_sentencias PR_ENDWHILE\n");
		puts("-------------------\n");
	}

}

asignacion : TOKEN_ID OP_IGUAL expresion 
{
	if(DEBUG) {
		puts($1);
		puts("Asignacion -> Token_ID := expresion\n");
		puts("-------------------\n");
	}

	/* comparo que para operar entre terminos, ambos tengan el mismo tipo de datos*/ 
	// puts("asignacion comprobacion tipos iguales");
	char mjs_error[60];
	if(!tipos_iguales($1,$3,mjs_error, linecount)) {
		puts(mjs_error);
		exit(1);
	}
}

expresion :factor OP_CONCAT factor 
{
	if(DEBUG) {
		printf("expresion %s %s\n",$1,$3 );
		puts("expresion : factor OP_CONCAT factor ");
		puts("-------------------\n");
	}

	/* comparo que para operar entre terminos, ambos tengan el mismo tipo de datos*/ 
	char mjs_error[60];
	if(!tipos_iguales($1,$3,mjs_error, linecount)) {
		puts(mjs_error);
		exit(1);
	}

	/* Verifico que no este concatenando flotantes*/
	int tipo = traer_tipo($3);
	if(tipo == TIPO_FLOAT) {
		char aux_float[10];
		char aux_float2[10];
		sprintf(aux_float,"%s",$1);
		sprintf(aux_float2,"%s",$3);
		sprintf(mjs_error,OPERACION_INVALIDA_TIPOS,"CONCATENACION",aux_float,aux_float2,"FLOAT",linecount);
		puts(mjs_error);
		exit(1);
	}

	/* Verifico que no este concatenando enteros*/
	if(tipo == TIPO_INT) {
		char aux_int[10];
		char aux_int2[10];
		sprintf(aux_int,"%s",$1);
		sprintf(aux_int2,"%s",$3);
		sprintf(mjs_error,OPERACION_INVALIDA_TIPOS,"CONCATENACION",aux_int,aux_int2,"INT",linecount);
		puts(mjs_error);
		exit(1);
	}

}

expresion : termino
{
	if(DEBUG) {
	printf("%s\n",$1 );
		puts("Expresion -> termino\n");
		puts("-------------------\n");
	}

	$$=$1;
}

expresion : expresion OP_SUMA termino  
{
	if(DEBUG) {
		printf("%s %s\n", $1, $3);
		puts("expresion : expresion OP_SUMA termino\n");
		puts("-------------------\n");
	}
	/* comparo que para operar entre terminos, ambos tengan el mismo tipo de datos*/ 
	char mjs_error[60];
	if(!tipos_iguales($1,$3,mjs_error, linecount)) {
		puts(mjs_error);
		exit(1);
	}
	/* Verifico que no este sumando strings*/
	int tipo = traer_tipo($3);
	if(tipo == TIPO_STRING) {
		sprintf(mjs_error,OPERACION_INVALIDA_TIPOS,"SUMA",$1,$3,"STRING",linecount);
		puts(mjs_error);
		exit(1);
	}
} 

expresion : expresion OP_RESTA termino 
{
	if(DEBUG) {
		printf("%s %s\n", $1, $3);
		puts("Resta\n");
		puts("-------------------\n");
	}

	/* comparo que para operar entre terminos, ambos tengan el mismo tipo de datos*/ 
	char mjs_error[60];
	if(!tipos_iguales($1,$3,mjs_error, linecount)) {
		puts(mjs_error);
		exit(1);
	}
	/* Verifico que no este restando strings*/
	int tipo = traer_tipo($3);
	if(tipo == TIPO_STRING) {
		sprintf(mjs_error,OPERACION_INVALIDA_TIPOS,"RESTA",$1,$3,"STRING",linecount);
		puts(mjs_error);
		exit(1);
	}
}

termino : factor
{
	if(DEBUG) {
	printf("%s\n",$1 );
		puts("termino : factor\n");
		puts("-------------------\n");
	}
}

termino : termino OP_DIV factor
{
	if(DEBUG) {
	printf("%s %s\n", $1,$3);
		puts("termino : termino OP_DIV factor\n");
		puts("-------------------\n");
	}
	/* comparo que para operar entre terminos, ambos tengan el mismo tipo de datos*/ 
	char mjs_error[60];
	if(!tipos_iguales($1,$3,mjs_error, linecount)) {
		puts(mjs_error);
		exit(1);
	}

	/* Verifico que no este dividiendo strings*/
	int tipo = traer_tipo($3);
	if(tipo == TIPO_STRING) {
		sprintf(mjs_error,OPERACION_INVALIDA_TIPOS,"DIVISION",$1,$3,"STRING",linecount);
		puts(mjs_error);
		exit(1);
	}
}

termino : termino OP_MUL factor
{
	if(DEBUG) {
	printf("%s %s\n", $1,$3);
		puts("termino : termino OP_MUL factor\n");
		puts("-------------------\n");
	}

	/* comparo que para operar entre terminos, ambos tengan el mismo tipo de datos*/ 
	char mjs_error[60];
	if(!tipos_iguales($1,$3,mjs_error, linecount)) {
		puts(mjs_error);
		exit(1);
	}

	/* Verifico que no este multiplicando strings*/
	int tipo = traer_tipo($3);
	if(tipo == TIPO_STRING) {
		sprintf(mjs_error,OPERACION_INVALIDA_TIPOS,"MULTIPLICACION",$1,$3,"STRING",linecount);
		puts(mjs_error);
		exit(1);
	}
}

factor : CONST_STR
{
	if(DEBUG) {
		puts("factor : cte\n");
		puts("-------------------\n");		
	}

	/* agrego la constante a la tabla de simbolos */
	agregar_cte_a_TS(TIPO_STRING,$1, 0,0.0,linecount);
	$$=$1;

	puts($1);

}

factor : CONST_INT
{
	if(DEBUG) {
		printf("%d\n",$1);
		puts("factor : cte\n");
		puts("-------------------\n");		
	}
	/* agrego la constante a la tabla de simbolos, pero para hacerlo, primero
	tengo que castearla a string */
	char temp[10];
	sprintf(temp,"%d",$1);
	$$ = temp;
	agregar_cte_a_TS(TIPO_INT,NULL, $1,0.0,linecount);
}

factor : CONST_FLOAT
{
	if(DEBUG) {
		printf("%.4f\n",$1);
		puts("factor : cte\n");
		puts("-------------------\n");
	}
	/* agrego la constante a la tabla de simbolos, pero para hacerlo, primero
	tengo que castearla a string */
	char temp[10];
	sprintf(temp,"%.4f",$1);
	$$ = temp;
	agregar_cte_a_TS(TIPO_FLOAT,NULL, 0,$1,linecount);
}

factor : TOKEN_ID
{
	if(DEBUG) {
		puts("factor : TOKEN_ID\n");
		puts("-------------------\n");
	}
} 
     
     
factor : iguales 
{
	if(DEBUG) {
		puts($1);
		puts("factor : iguales \n");
		puts("-------------------\n");	
	}
}

factor : filter
{
	if(DEBUG) {
		puts($1);
		puts("factor : filter\n");
		puts("-------------------\n");	
	}	
}

// factor : expresion
// {
// 	puts("factor : expresion\n");
// 	puts("-------------------\n");
// }

declaracion_variables : PR_DIM COR_ABRE declaracion_variables_interna COR_CIERRA PUNTO_Y_COMA 

{
	if(DEBUG) {
		puts("declaracion_variables : PR_DIM COR_ABRE declaracion_variables_interna COR_CIERRA\n");
		puts("-------------------\n");
	}
	int i;
	/*agrego las variables a la tabla de simbolos, recorro en forma de cola y pila
	los vectores que cree anteriormente para invertir el orden de los tipos de datos*/
	for (i = 0; i < variables_a_agregar; ++i)
	{
		// printf("agregando %s %s\n", temp_variables[i],temp_tipo_dato[variables_a_agregar -1 - i]);
		agregar_variable_a_TS(temp_variables[i],temp_tipo_dato[variables_a_agregar - 1- i], linecount);
	}
	variables_a_agregar = 0;
} 

declaracion_variables : PR_DIM COR_ABRE declaracion_variables_interna COR_CIERRA PUNTO_Y_COMA declaracion_variables 
{
	puts("declaracion_variables : PR_DIM COR_ABRE declaracion_variables_interna COR_CIERRA\n");
	puts("-------------------\n");
}


declaracion_variables_interna : TOKEN_ID COMA declaracion_variables_interna COMA tipo_dato
{
	if(DEBUG) {
		puts("declaracion_variables_interna : TOKEN_ID COMA declaracion_variables_interna COMA tipo_dato\n");
		puts("-------------------\n");
	}
	/* Agrego de forma temporal los datos leidos, para luego procesarlos */
	strcpy(temp_variables[variables_a_agregar],$1);
	strcpy(temp_tipo_dato[variables_a_agregar],$5);
	variables_a_agregar++;
} 

declaracion_variables_interna : TOKEN_ID COR_CIERRA PR_AS COR_ABRE tipo_dato
{
	if(DEBUG) {
		puts("declaracion_variables_interna : TOKEN_ID COR_CIERRA PR_AS COR_ABRE tipo_dato\n");
		puts("-------------------\n");
	}
	int i;
	/*agrego las variables a la tabla de simbolos, recorro en forma de cola y pila
	los vectores que cree anteriormente para invertir el orden de los tipos de datos*/
	for (i = 0; i < variables_a_agregar; ++i)
	{
		printf("agregando %s %s\n", temp_variables[i],temp_tipo_dato[variables_a_agregar -1 - i]);
		agregar_variable_a_TS(temp_variables[i],temp_tipo_dato[variables_a_agregar - 1 - i], linecount);
	}
	variables_a_agregar = 0;

	/* Agrego de forma temporal los datos leidos, para luego procesarlos */
	strcpy(temp_variables[variables_a_agregar],$1);
	strcpy(temp_tipo_dato[variables_a_agregar],$5);
	variables_a_agregar++;
}

tipo_dato : PR_INT 
{
	$$=$1;
	if(DEBUG) {
		puts("PR_INT\n");
		puts("-------------------\n");	
	}
}   

tipo_dato : PR_FLOAT 
{
	$$=$1;
	if(DEBUG) { 
		puts("PR_FLOAT\n");
		puts("-------------------\n");
	}
}            

tipo_dato : PR_STRING 
{
	$$=$1;
	if(DEBUG) {
		puts("PR_STRING\n");
		puts("-------------------\n");
	}
} 

comparador : OP_MAYOR
{
	// strcpy(nodo_comparador->info->a, ">");
	if(DEBUG) {
		puts("OP_MAYOR\n");
		puts("-------------------\n");
	}
}   

comparador : OP_MENOR
{
	// strcpy(nodo_comparador->info->a, "<");
	if(DEBUG) {
		puts("OP_MENOR\n");
		puts("-------------------\n");
	}
}   

comparador : OP_MENOR_IGUAL
{
	// strcpy(nodo_comparador->info->a, "<=");

	$$=$1;
	if(DEBUG) {
		puts("OP_MENOR_IGUAL\n");
		puts("-------------------\n");
	}
}      

comparador : OP_MAYOR_IGUAL
{
	// strcpy(nodo_comparador->info->a, ">=");
	if(DEBUG) {
		puts("OP_MAYOR_IGUAL\n");
		puts("-------------------\n");
	}
}    

comparador : OP_IGUAL_IGUAL
{
	// strcpy(nodo_comparador->info->a, "==");
	if(DEBUG) {
		puts("OP_IGUAL_IGUAL\n");
		puts("-------------------\n");
	}
}

comparador : OP_DISTINTO
{
	// strcpy(nodo_comparador->info->a, "!=");
	if(DEBUG) {
		puts("OP_DISTINTO\n");
		puts("-------------------\n");
	}
}     

%%


t_simbolo tabla_simbolos[2000];
int cantidad_simbolos = 0;	
void imprimir_tabla_simbolos();
void vaciar_tabla_simbolos();
char * tipo_simbolo_to_string(int tipo);



//funcion para realizar todo lo que haga falta previo a terminar
void finally(FILE *yyin){
	vaciar_tabla_simbolos();
	fclose(a);
	// vaciar_arbol(&arbol_ejecucion);
	fclose(yyin);
}



int main(int argc, char **argv ) {
	// puts("Corriendo el compilador...");
	++argv, --argc; 
	puts("a");
	if ( argc > 0 ) {
	    yyin = fopen( argv[0], "r" );
    }	else {
	    yyin = stdin;

    }
	puts("b");

    agregar_variable_a_TS("IGUALES","INT", 0);

	yyparse();
	puts("c");

	imprimir_tabla_simbolos();

	finally(yyin); 
	puts("\nFinalizando compilacion...");
	return EXIT_SUCCESS;
}

int yyerror(void)
{
	printf("Syntax Error\n");
	system ("Pause");
	exit (1);
}

/* borra todo el contenido de la tabla de simbolos, generalmente para ser borrado */
void vaciar_tabla_simbolos(){
	int i;
	for (i = 0; i < cantidad_simbolos; ++i)
	{
		free(tabla_simbolos[i].nombre);
		if(tabla_simbolos[i].valor_string != NULL)
			free(tabla_simbolos[i].valor_string);
		if(tabla_simbolos[i].alias != NULL)
			free(tabla_simbolos[i].alias);
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
			if(tabla_simbolos[i].nombre[0] == '_')
			{
				fprintf(a, "\n");
				fprintf(a, tabla_simbolos[i].nombre);			
				fprintf(a, " db ?");
			}
		}
	
		if(tabla_simbolos[i].tipo == TIPO_INT)
		{
			fprintf(f, "%s\t\t\t\t%s\t\t\t\t%d\t\t\t\t%d\n",tabla_simbolos[i].nombre,tipo_simbolo_to_string(tabla_simbolos[i].tipo),tabla_simbolos[i].esConstante,tabla_simbolos[i].lineNumber);
			fprintf(a, "\n");
			if(tabla_simbolos[i].nombre[1] == 'c' && tabla_simbolos[i].nombre[2] == 't' && tabla_simbolos[i].nombre[3] == 'e')
			{
				char *aux = newStr(tabla_simbolos[i].nombre);
				fprintf(a, "_");
				fprintf(a, aux);		
				fprintf(a, " dd ");
				char subbuff[5];
				memcpy( subbuff, &aux[4], 1 );
				subbuff[1] = '\0';
				fprintf(a, subbuff);
				fprintf(a, ".000000");
			} else
			{
				fprintf(a, "\n");
				fprintf(a, tabla_simbolos[i].nombre);			
				fprintf(a, " dd 0");
			}
		}
		
		if(tabla_simbolos[i].tipo == TIPO_FLOAT)
		{
			fprintf(f, "%s\t\t\t\t%s\t\t\t\t%d\t\t\t\t%d\n",tabla_simbolos[i].nombre,tipo_simbolo_to_string(tabla_simbolos[i].tipo),tabla_simbolos[i].esConstante,tabla_simbolos[i].lineNumber);
			fprintf(a, "\n");
			if(tabla_simbolos[i].nombre[1] == 'c' && tabla_simbolos[i].nombre[2] == 't' && tabla_simbolos[i].nombre[3] == 'e')
			{
				char *aux = newStr(tabla_simbolos[i].nombre);
				fprintf(a, "_");
				fprintf(a, aux);		
				fprintf(a, " dd ");
				char subbuff[5];
				memcpy( subbuff, &aux[4], 6 );
				subbuff[6] = '\0';
				fprintf(a, subbuff);
			} else
			{
				fprintf(a, "\n");
				fprintf(a, tabla_simbolos[i].nombre);			
				fprintf(a, " dd ?");
			} 
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
void agregar_simbolo(char * nombre, int tipo, char * valor,char * alias, int lineNumber,int esConstante) {
int n;
	tabla_simbolos[cantidad_simbolos].nombre = malloc(sizeof(char) * strlen(nombre));
	strcpy(tabla_simbolos[cantidad_simbolos].nombre,nombre);


	if(alias != NULL) {
		tabla_simbolos[cantidad_simbolos].alias = malloc(sizeof(char) * strlen(alias));
		strcpy(tabla_simbolos[cantidad_simbolos].alias,alias);	
	}
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

char * substring(char * str , int start, int end)
{
	char * ret = (char*) malloc(sizeof(char) * (end - start + 1));
	memcpy( ret, str + start, end - start +1);
	*(ret + (end - start+1)) = '\0';
	return ret;
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
	agregar_simbolo(aux2,tipo,NULL,NULL,lineNumber,0);
}

/*Agrega una constante a la TS*/
void agregar_cte_a_TS(int tipo, char * valor_str, int valor_int,float valor_float, int lineNumber) {


	if(tipo == TIPO_STRING) {
		strcpy(aux2,prefijo_string);
		strcat(aux2, valor_str);
		if(buscar_en_TS_sin_prefijo(valor_str,NULL,0) != -1)
		return;

		cantidad_cte_string++;
		agregar_simbolo(aux2,tipo,NULL,NULL,lineNumber,1);


	}else if(tipo == TIPO_INT) {
		strcpy(aux2,prefijo_int);
		sprintf(aux,"%d",valor_int);
		strcat(aux2,aux);
		if(buscar_en_TS_sin_prefijo(aux,NULL,0) != -1)
		return;

		agregar_simbolo(aux2,tipo,aux,NULL,lineNumber,1);
		
	}else if(tipo == TIPO_FLOAT) {
		strcpy(aux2,prefijo_float);
		snprintf(aux,30,"%.4f",valor_float);
		strcat(aux2,aux);
		if(buscar_en_TS_sin_prefijo(aux,NULL,0) != -1)
		return;
		agregar_simbolo(aux2,tipo,aux,NULL,lineNumber,1);
		
	}
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

/* Esta funcion le pone un prefijo a una string base*/
void poner_prefijo(char * str, char * prefijo) {
	char pref[32];

	strcpy(pref, prefijo);
	strcat(pref,str);
	strcpy(str,pref);
}


void reemplazar(char * cad, char old,char new, int size) 
{
	int i;
	for(i = 0; i < size; i++)
	{
		if(*(cad + i) == old)
			*(cad + i) = new;
	}
}


void copiar_sin_finalizador(char * dest,char * orig) 
{
	
	while(*orig && *dest)
	{
		*dest = *orig;
		orig++;
		dest++;		
	}
}
char *newStr (char *charBuffer) {
  int length = strlen(charBuffer);
  char *str;
  if (length <= 1) {
    str = (char *) malloc(1);
    str[0] = '\0';
  } else {
    str = (char *) malloc(length);
    strcpy(str, &charBuffer[1]);
  }
  return str;
}

int traer_tipo_con_prefijo(char * nombre) {
	int index = buscar_en_TS(nombre, NULL,0);
	return tabla_simbolos[index].tipo;
}