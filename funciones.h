#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defines.h"
#include "structs.h"

void poner_prefijo(char * str, char * prefijo);
void copiar_sin_finalizador(char * dest,char * orig); 
void reemplazar(char * cad, char old,char new, int size) ;
char * newStr(char *charBuffer);
char * substring(char * str , int start, int end);
void error_lexico(char * mensaje);


/********************* FUNCIONES INTERMEDIA ************************/

int print_t(t_nodo_arbol *tree);
int _print_t(t_nodo_arbol *tree, int is_left, int offset, int depth, char * s, int max);
t_info_sentencias * crear_info_sentencias(t_nodo_arbol * p_nodo) ;
void reemplazar_etiqueta_por_valor_TS(t_nodo_arbol*);
t_info * crear_info(char *);


#endif
