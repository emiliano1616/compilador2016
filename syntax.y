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
#include "ts.h"
#include "funciones.h"

#define DEBUG 1
extern YYSTYPE yylval;
char temp_variables[MAX_VARIABLES][30];
// char temp_tipo_dato[MAX_VARIABLES][10];
char temp_tipo_dato[10];
int variables_a_agregar= 0;


extern int linecount;

t_pila_de_colas * pila_de_colas;
t_pila * pila_bloques;
t_cola * cola_sentencias;
t_pila * pila_comparaciones;
t_pila * pila_condiciones;
t_pila * pila_expresiones;
t_pila * pila_factores;
t_pila * pila_terminos;
t_pila_asm * pila_whiles;

t_arbol * arbol_ejecucion;
t_nodo_arbol * nodo_between;
t_nodo_arbol * nodo_average;
t_nodo_arbol * nodo_factor;
t_nodo_arbol * nodo_termino;
t_nodo_arbol * nodo_expresion;
t_nodo_arbol * nodo_asignacion;
t_nodo_arbol * nodo_condicion;
t_nodo_arbol * nodo_comparacion;
t_nodo_arbol * nodo_pgm;
t_nodo_arbol * nodo_programa;
t_nodo_arbol * nodo_sentencia;
t_nodo_arbol * nodo_sentencias;
t_nodo_arbol * nodo_comparador;
t_nodo_arbol * nodo_condicional;
t_nodo_arbol * nodo_iteracion;
t_nodo_arbol * nodo_io;
t_nodo_arbol * nodo_entrada;
t_nodo_arbol * nodo_salida;
t_nodo_arbol * nodo_declaracion_variable;
t_nodo_arbol * nodo_sentencias_then;
t_nodo_arbol * nodo_sentencias_else;
t_nodo_arbol * nodo_then;
t_nodo_arbol * nodo_asm_while;


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
%type <str_val> salida
%type <str_val> entrada
// %type <str_val> factor_str

%token PR_MAIN
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
%token PR_AVERAGE
%token PR_DECVAR
%token PR_ENDDEC
%token PR_BETWEEN
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
%token <str_val> PR_FLOAT
%token <str_val> PR_INT
%token <str_val> PR_STRING
%token OP_CONCAT
%token PUNTO_Y_COMA
%token DOS_PUNTOS
%%

pgm : programa 
{
	nodo_pgm = nodo_programa;
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


	nodo_sentencia = crear_nodo_arbol(crear_info(";"),nodo_asignacion,NULL);
	insertar_en_cola(&cola_sentencias,crear_info_sentencias(nodo_sentencia));
	// puts("insertando en cola");
	// recorrer_en_orden(nodo_sentencia,&visitar);


};

sentencia : between PUNTO_Y_COMA
{
	if(DEBUG) {
		puts("sentencia : between PUNTO_Y_COMA\n");
		puts("-------------------\n");		
	}


	nodo_sentencia = crear_nodo_arbol(crear_info(";"),nodo_between,NULL);
	insertar_en_cola(&cola_sentencias,crear_info_sentencias(nodo_sentencia));
	// puts("insertando en cola");
	// recorrer_en_orden(nodo_sentencia,&visitar);


};

sentencia : average PUNTO_Y_COMA
{
	if(DEBUG) {
		puts("sentencia : average PUNTO_Y_COMA\n");
		puts("-------------------\n");		
	}


	nodo_sentencia = crear_nodo_arbol(crear_info(";"),nodo_average,NULL);
	insertar_en_cola(&cola_sentencias,crear_info_sentencias(nodo_sentencia));
	// puts("insertando en cola");
	// recorrer_en_orden(nodo_sentencia,&visitar);


};


lista_sentencias : sentencia
{
	if(DEBUG){
		puts("Una sola sentencia\n");
		puts("-------------------\n");
		// printf("la pila esta vacia? %d\n",pila_vacia(&cola_sentencias) );
	}
		t_info_sentencias * sentencia_apilada = sacar_de_cola(&cola_sentencias);
		nodo_sentencias = sentencia_apilada->a;
		// puts("sacando de cola");
		// recorrer_en_orden(sentencia_apilada->a,&visitar);
};

lista_sentencias : sentencia lista_sentencias
{
	// if(DEBUG) {
		puts("Varias sentencias\n");
		puts("-------------------\n");
	// }
	// nodo_sentencias = nodo_sentencia;
	// nodo_sentencias->nodo_der = nodo_sentencia;
	t_info_sentencias * sentencia_apilada = sacar_de_cola(&cola_sentencias);
	nodo_sentencias->nodo_der = sentencia_apilada->a;
	nodo_sentencias->nodo_der->padre = nodo_sentencias;
	nodo_sentencias = sentencia_apilada->a;
		// puts("sacando de cola");
		// recorrer_en_orden(sentencia_apilada->a,&visitar);



	// nodo_sentencias = crear_nodo_arbol(crear_info("NUEVA"),nodo_sentencias,sentencia_apilada->a);
};

sentencia : condicional 
{

	// nodo_sentencia = nodo_condicional;
	if(DEBUG) {
		puts("sentencia : condicional \n");
		puts("-------------------\n");		
	}
	
	//para esta altura todas las sentencias del bloque deberian haber sido desencoladas
	printf("La cola de sentencias esta vacia? %d\n",cola_vacia(&cola_sentencias));
	cola_sentencias = sacar_de_pila_de_colas(&pila_de_colas);

	nodo_sentencia = crear_nodo_arbol(crear_info(";"),nodo_condicional,NULL);
	insertar_en_cola(&cola_sentencias,crear_info_sentencias(nodo_sentencia));
	// puts("insertando en cola");
	// recorrer_en_orden(nodo_sentencia,&visitar);

};


sentencia : iteracion
{
	if(DEBUG) {
		puts("sentencia : iteracion\n");
		puts("-------------------\n");		
	}

	//para esta altura todas las sentencias del bloque deberian haber sido desencoladas
	printf("La cola de sentencias esta vacia? %d\n",cola_vacia(&cola_sentencias));
	cola_sentencias = sacar_de_pila_de_colas(&pila_de_colas);

	nodo_sentencia = crear_nodo_arbol(crear_info(";"),nodo_iteracion,NULL);
	insertar_en_cola(&cola_sentencias,crear_info_sentencias(nodo_sentencia));
		// puts("insertando en cola");
	// recorrer_en_orden(nodo_sentencia,&visitar);
	// print_t(nodo_sentencia);
	// nodo_sentencia = nodo_iteracion;
};

sentencia : io PUNTO_Y_COMA
{
	if(DEBUG) {
		puts("Operacion de entrada salidas\n");
		puts("-------------------\n");		
	}
	nodo_sentencia = crear_nodo_arbol(crear_info(";"),nodo_io,NULL);
	insertar_en_cola(&cola_sentencias,crear_info_sentencias(nodo_sentencia));
		// puts("insertando en cola");
	// recorrer_en_orden(nodo_sentencia,&visitar);
};


between : PR_BETWEEN  PAR_ABRE TOKEN_ID COMA COR_ABRE expresion PUNTO_Y_COMA expresion COR_CIERRA PAR_CIERRA
{
	if(DEBUG) {
		puts("between : PR_BETWEEN  PAR_ABRE TOKEN_ID COMA COR_ABRE expresion PUNTO_Y_COMA expresion COR_CIERRA PAR_CIERRA\n");
		puts("-------------------\n");		
	}

	t_info_sentencias * p_info1 = sacar_de_pila(&pila_expresiones);
	t_info_sentencias * p_info2 = sacar_de_pila(&pila_expresiones);


	t_nodo_arbol * p_if_cond1 = crear_nodo_arbol(crear_info("<"),crear_hoja(crear_info($3)),p_info1->a);
	t_nodo_arbol * p_if_cond2 = crear_nodo_arbol(crear_info(">"),crear_hoja(crear_info($3)),p_info2->a);

	t_nodo_arbol * p_if = crear_nodo_arbol(crear_info("AND"),p_if_cond1,p_if_cond2);



	t_nodo_arbol * p_if_then = crear_nodo_arbol(crear_info("<V.F>"),crear_hoja(crear_info("1")),crear_hoja(crear_info("0")));



	nodo_between = crear_nodo_arbol(crear_info("BETWEEN"),p_if,p_if_then);



}

average : PR_AVERAGE PAR_ABRE COR_ABRE lista_expresiones COR_CIERRA PAR_CIERRA 
{
	if(DEBUG) {
		puts("average : PR_AVERAGE PAR_ABRE COR_ABRE lista_expresiones COR_CIERRA PAR_CIERRA \n");
		puts("-------------------\n");
	}

	while(!pila_vacia(&pila_expresiones) )
	{
		t_info_sentencias * p_info = sacar_de_pila(&pila_expresiones);
		// printf("asdasd\n");
	}

}

lista_expresiones : expresion
{
	if(DEBUG) {
		puts("lista_expresiones : expresion \n");
		puts("-------------------\n");
	}
}

lista_expresiones : expresion COMA lista_expresiones
{
	if(DEBUG) {
		puts("lista_expresiones : expresion COMA lista_expresiones \n");
		puts("-------------------\n");
	}
}


io : entrada
{
	if(DEBUG) {
		puts("io : entrada\n");
		puts("-------------------\n");
	}

	nodo_io = nodo_entrada;

}

io : salida
{
	if(DEBUG) {
		puts("io : salida\n");
		puts("-------------------\n");		
	}
	nodo_io = nodo_salida;
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
	nodo_entrada = crear_nodo_arbol(crear_info("READ"),crear_hoja(crear_info($2)),crear_hoja(crear_info("READ")));
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
	nodo_salida = crear_nodo_arbol(crear_info("WRITE"),crear_hoja(crear_info($2)),crear_hoja(crear_info("WRITE")));

}

salida : PR_WRITE CONST_STR
{
	if(DEBUG) {
		puts("salida : PR_WRITE cte\n");
		puts("-------------------\n");	
	}
	nodo_salida = crear_nodo_arbol(crear_info("WRITE"),crear_hoja(crear_info($2)),crear_hoja(crear_info("WRITE")));

}

condicional : PR_IF PAR_ABRE condicion PAR_CIERRA then PR_ENDIF
{
	if(DEBUG) {
		puts("Condicional sin ELSE\n");
		puts("-------------------\n");
	}

	t_info_sentencias * p_info = sacar_de_pila(&pila_condiciones);
	//le pongo null porque ahi iria el ELSE y no hay
	nodo_then = crear_nodo_arbol(crear_info("THEN"),nodo_sentencias_then,NULL);
	nodo_condicional = crear_nodo_arbol(crear_info("IF"),p_info->a,nodo_then);
}

condicional : PR_IF PAR_ABRE condicion PAR_CIERRA then else PR_ENDIF
{


	if(DEBUG) {
		puts("Condicional con ELSE\n");
		puts("-------------------\n");	
	}

	t_info_sentencias * p_info = sacar_de_pila(&pila_condiciones);
	nodo_then = crear_nodo_arbol(crear_info("<V.F>"),nodo_sentencias_then,nodo_sentencias_else);
	nodo_condicional = crear_nodo_arbol(crear_info("IF"),p_info->a,nodo_then);

}

then : PR_THEN lista_sentencias
{
	if(DEBUG) {
		puts("PR_THEN lista_sentencias\n");
		puts("-------------------\n");	
	}
	nodo_sentencias_then = obtener_raiz(nodo_sentencias);

}

else : PR_ELSE lista_sentencias
{
	if(DEBUG) {
		puts("PR_ELSE lista_sentencias\n");
		puts("-------------------\n");	
	}
	nodo_sentencias_else = obtener_raiz(nodo_sentencias);
}

condicion : comparacion
{
	// if(DEBUG) {
		puts("condicion : comparacion\n");
		puts("-------------------\n");
	// }

	insertar_en_pila_de_colas(&pila_de_colas,cola_sentencias);
	crear_cola(&cola_sentencias);

	t_info_sentencias * p_info = sacar_de_pila(&pila_comparaciones);
	nodo_condicion = p_info->a;
	insertar_en_pila(&pila_condiciones,crear_info_sentencias(nodo_condicion));

}

condicion : comparacion OP_LOG_AND comparacion
{
	// if(DEBUG) {
		puts("condicion : comparacion and comparacion\n");
		puts("-------------------\n");		
	// }

	insertar_en_pila_de_colas(&pila_de_colas,cola_sentencias);
	crear_cola(&cola_sentencias);

	t_info_sentencias * p_info1 = sacar_de_pila(&pila_comparaciones);
	t_info_sentencias * p_info2 = sacar_de_pila(&pila_comparaciones);

	nodo_condicion = crear_nodo_arbol(crear_info("AND"),p_info1->a,p_info2->a);
	insertar_en_pila(&pila_condiciones,crear_info_sentencias(nodo_condicion));


}

condicion : comparacion OP_LOG_OR comparacion
{
	// if(DEBUG) {
		puts("condicion : comparacion or comparacion\n");
		puts("-------------------\n");		
	// }

	insertar_en_pila_de_colas(&pila_de_colas,cola_sentencias);
	crear_cola(&cola_sentencias);

	t_info_sentencias * p_info1 = sacar_de_pila(&pila_comparaciones);
	t_info_sentencias * p_info2 = sacar_de_pila(&pila_comparaciones);

	nodo_condicion = crear_nodo_arbol(crear_info("OR"),p_info1->a,p_info2->a);
	insertar_en_pila(&pila_condiciones,crear_info_sentencias(nodo_condicion));

}

comparacion : expresion comparador expresion
{
	// if(DEBUG) {
	// puts($2);
		puts("comparacion : expresion comparador expresion\n");
		puts("-------------------\n");
	// }
	char mjs_error[60];
	/* comparo que para operar entre terminos, ambos tengan el mismo tipo de datos*/ 
	if(!tipos_iguales($1,$3,mjs_error,linecount)) 
	{
		puts(mjs_error);
		exit(1);
	}

	t_info_sentencias * p_info1 = sacar_de_pila(&pila_expresiones);
	t_info_sentencias * p_info2 = sacar_de_pila(&pila_expresiones);
	nodo_comparacion = crear_nodo_arbol(crear_info($2),p_info1->a,p_info2->a);

	// puts("a ver esto ahora");
	// nodo_comparacion = crear_nodo_arbol(crear_info($2),nodo_expresion,nodo_termino);
	insertar_en_pila(&pila_comparaciones,crear_info_sentencias(nodo_comparacion));
}

comparacion : PR_NOT expresion
{
	if(DEBUG) {
		puts("comparacion : PR_NOT expresion comparador expresion\n");
		puts("-------------------\n");
	}

	t_info_sentencias * p_info = sacar_de_pila(&pila_expresiones);

	nodo_comparacion = crear_nodo_arbol(crear_info("NOT"),p_info->a,NULL);
	insertar_en_pila(&pila_comparaciones,crear_info_sentencias(nodo_comparacion));

}

iteracion : PR_WHILE PAR_ABRE condicion PAR_CIERRA PR_DO lista_sentencias PR_ENDWHILE
{
	if(DEBUG) {
		puts("iteracion : PR_WHILE PAR_ABRE condicion PAR_CIERRA PR_DO lista_sentencias PR_ENDWHILE\n");
		puts("-------------------\n");
	}

	t_info_sentencias * p_info = sacar_de_pila(&pila_condiciones);
	t_nodo_arbol * sentencias_del_do = obtener_raiz(nodo_sentencias);
	// nodo_do = crear_nodo_arbol(crear_info("DO"),sentencias_del_do,NULL);
	nodo_iteracion = crear_nodo_arbol(crear_info("WHILE"),p_info->a,sentencias_del_do);
	sentencias_del_do->padre = nodo_iteracion;

}

asignacion : TOKEN_ID OP_IGUAL expresion 
{
	if(DEBUG) {
		puts($1);
		puts("Asignacion -> Token_ID := expresion\n");
		puts("-------------------\n");
	}

	// printf("asignacion %s %s\n",$1,$3 );
	/* comparo que para operar entre terminos, ambos tengan el mismo tipo de datos*/ 
	puts("asignacion comprobacion tipos iguales");
	char mjs_error[60];
	if(!tipos_iguales($1,$3,mjs_error, linecount)) {
		puts(mjs_error);
		exit(1);
	}
	t_info_sentencias * p_info = sacar_de_pila(&pila_expresiones);
	/* guardo la asignacion en el arbol de ejecucion */
	nodo_asignacion = crear_nodo_arbol(crear_info(":="),crear_hoja(crear_info($1)),p_info->a);

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


	/* guardo la expresion en el arbol de ejecucion */

	t_info_sentencias * p_nodo_factor1 = sacar_de_pila(&pila_factores);

	t_info_sentencias * p_nodo_factor2 = sacar_de_pila(&pila_factores);

	nodo_expresion = crear_nodo_arbol(crear_info("++"),p_nodo_factor1->a,p_nodo_factor2->a);

	insertar_en_pila(&pila_expresiones,crear_info_sentencias(nodo_expresion));

}

expresion : termino
{
	if(DEBUG) {
	printf("%s\n",$1 );
		puts("Expresion -> termino\n");
		puts("-------------------\n");
	}

	$$=$1;
	
	/* guardo la expresion en el arbol de ejecucion */
	t_info_sentencias * p_nodo_termino = sacar_de_pila(&pila_terminos);
	nodo_expresion = p_nodo_termino->a;
	insertar_en_pila(&pila_expresiones,p_nodo_termino);

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

	/* guardo la expresion en el arbol de ejecucion */
	t_info_sentencias * p_nodo_expresion = sacar_de_pila(&pila_expresiones);
	t_info_sentencias * p_nodo_termino =  sacar_de_pila(&pila_terminos);
	nodo_expresion = crear_nodo_arbol(crear_info("+"),p_nodo_expresion->a,p_nodo_termino->a);
	insertar_en_pila(&pila_expresiones,crear_info_sentencias(nodo_expresion));

	free(p_nodo_expresion);
	free(p_nodo_termino);

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

	/* guardo la expresion en el arbol de ejecucion */
	t_info_sentencias * p_nodo_expresion = sacar_de_pila(&pila_expresiones);
	t_info_sentencias * p_nodo_termino =  sacar_de_pila(&pila_terminos);
	nodo_expresion = crear_nodo_arbol(crear_info("-"),p_nodo_expresion->a,p_nodo_termino->a);
	insertar_en_pila(&pila_expresiones,crear_info_sentencias(nodo_expresion));

	free(p_nodo_expresion);
	free(p_nodo_termino);

}

termino : factor
{
	if(DEBUG) {
	printf("%s\n",$1 );
		puts("termino : factor\n");
		puts("-------------------\n");
	}
	/*guardo el termino en el arbol de ejecucion*/
	t_info_sentencias * p_nodo_factor = sacar_de_pila(&pila_factores);
	nodo_termino = p_nodo_factor->a;
	insertar_en_pila(&pila_terminos,p_nodo_factor);

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

	/*guardo el termino en el arbol de ejecucion*/
	t_info_sentencias * p_nodo_factor = sacar_de_pila(&pila_factores);
	t_info_sentencias * p_nodo_termino = sacar_de_pila(&pila_terminos);

	nodo_termino = crear_nodo_arbol(crear_info("/"),p_nodo_termino->a,p_nodo_factor->a);
	insertar_en_pila(&pila_terminos,crear_info_sentencias(nodo_termino));

	free(p_nodo_factor);
	free(p_nodo_termino);

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

	/*guardo el termino en el arbol de ejecucion*/
	t_info_sentencias * p_nodo_factor = sacar_de_pila(&pila_factores);
	t_info_sentencias * p_nodo_termino = sacar_de_pila(&pila_terminos);

	nodo_termino = crear_nodo_arbol(crear_info("*"),p_nodo_termino->a,p_nodo_factor->a);
	insertar_en_pila(&pila_terminos,crear_info_sentencias(nodo_termino));

	free(p_nodo_factor);
	free(p_nodo_termino);

}

factor : between 
{
	if(DEBUG) {
		// puts($1);
		puts("factor : between \n");
		puts("-------------------\n");	
	}
	insertar_en_pila(&pila_factores,crear_info_sentencias(crear_nodo_arbol(crear_info("BETWEEN"),nodo_between,NULL)));
	// nodo_factor = crear_nodo_arbol(crear_info("IGUALES"),nodo_iguales,NULL);
	//nodo_sentencia = crear_nodo_arbol(crear_info(";"),nodo_iguales,NULL);
	//insertar_en_pila(&cola_sentencias,crear_info_sentencias(nodo_sentencia));
}

factor : CONST_STR
{
	if(DEBUG) {
		// printf("%s\n",$1);
		puts("factor : cte\n");
		puts("-------------------\n");		
	}

	/* agrego la constante a la tabla de simbolos */
	agregar_cte_a_TS(TIPO_STRING,$1, 0,0.0,linecount);
	$$=$1;

	/*guardo el termino en el arbol de ejecucion*/
	nodo_factor =  crear_hoja(crear_info($1));
	insertar_en_pila(&pila_factores,crear_info_sentencias(nodo_factor));
	// nodo_factor = crear_hoja(crear_info($1));

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

	// puts("agregando a factooooor intttttttttttttttttttttttttttttt");
	// puts(temp);
	/*guardo el termino en el arbol de ejecucion*/
	nodo_factor =  crear_hoja(crear_info(temp));
	insertar_en_pila(&pila_factores,crear_info_sentencias(nodo_factor));
	// nodo_factor = crear_hoja(crear_info(temp));
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

	/*guardo el termino en el arbol de ejecucion*/
	nodo_factor =  crear_hoja(crear_info(temp));
	insertar_en_pila(&pila_factores,crear_info_sentencias( nodo_factor));
	// nodo_factor = crear_hoja(crear_info(temp));
}

factor : TOKEN_ID
{
	if(DEBUG) {
		puts("factor : TOKEN_ID\n");
		puts("-------------------\n");
	}
	/*guardo el termino en el arbol de ejecucion*/
	nodo_factor =  crear_hoja(crear_info($1));
	insertar_en_pila(&pila_factores,crear_info_sentencias(nodo_factor ));
	// nodo_factor = crear_hoja(crear_info(temp));
} 
     

// factor : expresion
// {
// 	puts("factor : expresion\n");
// 	puts("-------------------\n");
// }

declaracion_variables : PR_DECVAR linea_de_declaracion_de_tipos PR_ENDDEC PUNTO_Y_COMA 
{
	// if(DEBUG) {
		puts("declaracion_variables : PR_DECVAR linea_de_declaracion_de_tipos PR_ENDDEC PUNTO_Y_COMA\n");
		puts("-------------------\n");
	// }

} 

linea_de_declaracion_de_tipos : lista_variables DOS_PUNTOS tipo_dato PUNTO_Y_COMA
{
	printf("El tipo de dato a agregar es %s \n", $3);
	puts("linea_de_declaracion_de_tipos : lista_variables DOS_PUNTOS tipo_dato\n");
	puts("-------------------\n");


}

linea_de_declaracion_de_tipos : lista_variables DOS_PUNTOS tipo_dato PUNTO_Y_COMA linea_de_declaracion_de_tipos
{
	printf("El tipo de dato a agregar es %s \n", $3);
	puts("linea_de_declaracion_de_tipos : linea_de_declaracion_de_tipos linea_de_declaracion_de_tipos\n");
	puts("-------------------\n");

	int i;
	for (i = 0; i < variables_a_agregar; ++i)
	{
		agregar_variable_a_TS(temp_variables[i], $3,linecount);
	}
	variables_a_agregar = 0;
}



lista_variables : TOKEN_ID
{
	printf("la variable es: %s \n",$1);
	if(DEBUG) {
		puts("lista_variables : TOKEN_ID \n");
		puts("-------------------\n");
	}

	strcpy(temp_variables[variables_a_agregar],$1);
	variables_a_agregar++;

} 

lista_variables : TOKEN_ID COMA lista_variables
{
	printf("la variable es: %s \n",$1);
	// if(DEBUG) {
		puts("lista_variables : TOKEN_ID COMA lista_variables \n");
		puts("-------------------\n");
	// }


	strcpy(temp_variables[variables_a_agregar],$1);
	variables_a_agregar++;

} 

// declaracion_variables : PR_DIM COR_ABRE declaracion_variables_interna COR_CIERRA PUNTO_Y_COMA 

// {
// 	if(DEBUG) {
// 		puts("declaracion_variables : PR_DIM COR_ABRE declaracion_variables_interna COR_CIERRA\n");
// 		puts("-------------------\n");
// 	}
// 	int i;
// 	/*agrego las variables a la tabla de simbolos, recorro en forma de cola y pila
// 	los vectores que cree anteriormente para invertir el orden de los tipos de datos*/
// 	for (i = 0; i < variables_a_agregar; ++i)
// 	{
// 		// printf("agregando %s %s\n", temp_variables[i],temp_tipo_dato[variables_a_agregar -1 - i]);
// 		agregar_variable_a_TS(temp_variables[i],temp_tipo_dato[variables_a_agregar - 1- i], linecount);
// 	}
// 	variables_a_agregar = 0;
// } 

// declaracion_variables : PR_DIM COR_ABRE declaracion_variables_interna COR_CIERRA PUNTO_Y_COMA declaracion_variables 
// {
// 	puts("declaracion_variables : PR_DIM COR_ABRE declaracion_variables_interna COR_CIERRA\n");
// 	puts("-------------------\n");
// }


// declaracion_variables_interna : TOKEN_ID COMA declaracion_variables_interna COMA tipo_dato
// {
// 	if(DEBUG) {
// 		puts("declaracion_variables_interna : TOKEN_ID COMA declaracion_variables_interna COMA tipo_dato\n");
// 		puts("-------------------\n");
// 	}
// 	/* Agrego de forma temporal los datos leidos, para luego procesarlos */
// 	strcpy(temp_variables[variables_a_agregar],$1);
// 	strcpy(temp_tipo_dato[variables_a_agregar],$5);
// 	variables_a_agregar++;
// } 

// declaracion_variables_interna : TOKEN_ID COR_CIERRA PR_AS COR_ABRE tipo_dato
// {
// 	if(DEBUG) {
// 		puts("declaracion_variables_interna : TOKEN_ID COR_CIERRA PR_AS COR_ABRE tipo_dato\n");
// 		puts("-------------------\n");
// 	}
// 	int i;
// 	/*agrego las variables a la tabla de simbolos, recorro en forma de cola y pila
// 	los vectores que cree anteriormente para invertir el orden de los tipos de datos*/
// 	for (i = 0; i < variables_a_agregar; ++i)
// 	{
// 		printf("agregando %s %s\n", temp_variables[i],temp_tipo_dato[variables_a_agregar -1 - i]);
// 		agregar_variable_a_TS(temp_variables[i],temp_tipo_dato[variables_a_agregar - 1 - i], linecount);
// 	}
// 	variables_a_agregar = 0;

// 	/* Agrego de forma temporal los datos leidos, para luego procesarlos */
// 	strcpy(temp_variables[variables_a_agregar],$1);
// 	strcpy(temp_tipo_dato[variables_a_agregar],$5);
// 	variables_a_agregar++;
// }

tipo_dato : PR_INT 
{
	$$=$1;
	if(DEBUG) {
		puts("PR_INT\n");
		puts("-------------------\n");	
	}

	int i;
	for (i = 0; i < variables_a_agregar; ++i)
	{
		agregar_variable_a_TS(temp_variables[i], $1,linecount);
	}
	variables_a_agregar = 0;
}   

tipo_dato : PR_FLOAT 
{
	$$=$1;
	if(DEBUG) { 
		puts("PR_FLOAT\n");
		puts("-------------------\n");
	}
	int i;
	for (i = 0; i < variables_a_agregar; ++i)
	{
		agregar_variable_a_TS(temp_variables[i], $1,linecount);
	}
	variables_a_agregar = 0;
}            

tipo_dato : PR_STRING 
{
	$$=$1;
	if(DEBUG) {
		puts("PR_STRING\n");
		puts("-------------------\n");
	}
	int i;
	for (i = 0; i < variables_a_agregar; ++i)
	{
		agregar_variable_a_TS(temp_variables[i], $1,linecount);
	}
	variables_a_agregar = 0;
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


extern t_simbolo tabla_simbolos[2000];

//funcion para realizar todo lo que haga falta previo a terminar
void finally(FILE *yyin){
	vaciar_tabla_simbolos();
	// vaciar_arbol(&arbol_ejecucion);
	fclose(yyin);
}



int main(int argc, char **argv ) {
	// puts("Corriendo el compilador...");
	// crear_inicio_assembler();

	++argv, --argc; 

	if ( argc > 0 ) {
	    yyin = fopen( argv[0], "r" );
    }	else {
	    yyin = stdin;

    }



    crear_pila_de_colas(&pila_de_colas);
    // crear_pila(&cola_sentencias);
    crear_cola(&cola_sentencias);
    crear_pila(&pila_bloques);
    crear_pila(&pila_comparaciones);
    crear_pila(&pila_condiciones);
    crear_pila(&pila_factores);
    crear_pila(&pila_terminos);
    crear_pila(&pila_expresiones);
    crear_arbol(&arbol_ejecucion);

	yyparse();
	imprimir_tabla_simbolos();
	arbol_ejecucion->p_nodo = obtener_raiz(nodo_sentencia);

	refactorizar_nodo(&arbol_ejecucion->p_nodo);
	// recorrer_en_orden(arbol_ejecucion->p_nodo,&reemplazar_etiqueta_por_valor_TS);

	// crear_codigo_assembler(arbol_ejecucion->p_nodo);
	// arbol_ejecucion->p_nodo = obtener_raiz(nodo_iguales);

	// recorrer_en_orden(arbol_ejecucion->p_nodo,&visitar);
	// puts("hola");
	print_t(arbol_ejecucion->p_nodo);
	
	// imprimir_arbol(arbol_ejecucion->p_nodo);

	// printf("la pila esta vacia? %d\n", pila_vacia(&cola_sentencias) );
	// if(!pila_vacia)
	// {
	// 	t_nodo_arbol
	// }
	
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
