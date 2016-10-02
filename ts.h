#ifndef TS_H
#define TS_H
#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "defines.h"
#include <string.h>

int buscar_en_TS_sin_prefijo(char * nombre, char * mjs_error , int lineNumber );
int buscar_en_TS(char * nombre, char * mjs_error, int lineNumber);
void agregar_simbolo(char * nombre, int tipo, char * valor,int lineNumber,int esConstante);
void agregar_variable_a_TS(char * nombre, char * tipo,int lineNumber);
void agregar_cte_a_TS(int tipo, char * valor_str, int valor_int,float valor_float,int lineNumber);
int traer_tipo_con_prefijo(char * nombre);
void imprimir_tabla_simbolos();
void vaciar_tabla_simbolos();
char * tipo_simbolo_to_string(int tipo);
char * get_nombre_sin_prefijo(t_simbolo *);
int traer_tipo(char * nombre);
int tipos_iguales(char * nombre1, char * nombre2, char * mjs_error, int lineNumber);


#endif
