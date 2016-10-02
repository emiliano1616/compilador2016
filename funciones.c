#include "funciones.h"

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
char * newStr (char *charBuffer) {
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



char * substring(char * str , int start, int end)
{
	char * ret = (char*) malloc(sizeof(char) * (end - start + 1));
	memcpy( ret, str + start, end - start +1);
	*(ret + (end - start+1)) = '\0';
	return ret;
}



/********************* FUNCIONES INTERMEDIA ************************/


extern t_simbolo tabla_simbolos[2000];


void reemplazar_etiqueta_por_valor_TS(t_nodo_arbol * p_nodo)
{
	if(!p_nodo) return;

	int indice = buscar_en_TS_sin_prefijo(p_nodo->info->a,NULL,0);
	if(indice >= 0 && *tabla_simbolos[indice].nombre == '_')
		strcpy(p_nodo->info->a,tabla_simbolos[indice].nombre);
}


/* Esta funcion crea un t_info a partir de una string, para agregarla
directamente a un nodo de arbol */
t_info * crear_info(char * str) 
{
	t_info * p_info = (t_info *) malloc(sizeof(t_info));
	strcpy(p_info->a,str);
	return p_info;
}

t_info_sentencias * crear_info_sentencias(t_nodo_arbol * p_nodo) 
{
	t_info_sentencias * p_info = (t_info_sentencias *) malloc(sizeof(t_info_sentencias));
	p_info->a = p_nodo;
	return p_info;
}


int _print_t(t_nodo_arbol *tree, int is_left, int offset, int depth, char * s, int max)
{
    int i;
    char b[20];
    int width = 5;

    if (!tree) return 0;

    sprintf(b, "(%s)", tree->info->a);

    int left  = _print_t(tree->nodo_izq,  1, offset,                depth + 1, s,max);
    int right = _print_t(tree->nodo_der, 0, offset + left + width, depth + 1, s,max);


    // printf("%s is_left %d offset %d depth %d width %d b %s \n ", tree->info->a,
    //  is_left,offset,depth,width,b);

    	copiar_sin_finalizador(s + (2 * depth)*max + offset + left,b);

    if (depth && is_left) {

        for (i = 0; i < width + right; i++)
        	copiar_sin_finalizador(s + (2 * depth - 1)*max  + offset + left + width/2 + i,"-"); 
    	copiar_sin_finalizador(s + (2 * depth - 1)*max  + offset + left + width/2 ,"+"); 
    	copiar_sin_finalizador(s + (2 * depth - 1)*max  + offset + left + width + right + width/2 ,"+"); 

    } else if (depth && !is_left) {
        for (i = 0; i < left + width; i++)
    		copiar_sin_finalizador(s + (2 * depth - 1)*max  + offset - width/2 + i ,"-"); 
		copiar_sin_finalizador(s + (2 * depth - 1)*max  + offset + left + width/2 ,"+"); 
		// copiar_sin_finalizador(s + (2 * depth - 1)*max  + offset - width/2 ,"+"); 
    }

    return left + width + right;
}

int print_t(t_nodo_arbol *tree)
{
	FILE *f = fopen("intermedia.txt", "w+");
	if (f == NULL)
	{
	    puts("Error abriendo archivo de notaci�n intermedia");
	    exit(1);
	}
	int i;
    char * s = (char *) malloc(sizeof(char) * RENGLONES_IMPRESION_ARBOL * CARACTERES_RENGLON_ARBOL);

    for (i = 0; i < RENGLONES_IMPRESION_ARBOL * CARACTERES_RENGLON_ARBOL; i++)
    {
    	if(i == 0 || i % (CARACTERES_RENGLON_ARBOL - 1))
    		sprintf(s + i, "%c", ' ');
    	else
    		sprintf(s + i, "%c", '\0');
    }


    _print_t(tree, 0, 0, 0, s,CARACTERES_RENGLON_ARBOL);


    for (i = 0; i < RENGLONES_IMPRESION_ARBOL; i++)
    {
       //printf("%s\n", s + i*CARACTERES_RENGLON_ARBOL);
        fprintf(f, "%s\n", s + i*CARACTERES_RENGLON_ARBOL);
    	
    }

   // for (i = 0; i < RENGLONES_IMPRESION_ARBOL; i++)
   //     printf("%s\n", s + i*CARACTERES_RENGLON_ARBOL);
    
    fclose(f);
}



