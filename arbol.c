#include "arbol.h"


// void main() {

// 	t_info a[10000];
// 	int i;

// 	for(i=0;i < 10000; i++) {
// 		a[i].a = i;
// 	}

// 	t_arbol * arbol;
// 	crear_arbol(&arbol);


// 	arbol->p_nodo = crear_hoja(&a[2]);

// 	insertar_hijo_izquierdo(arbol->p_nodo,&a[1]);
// 	insertar_hijo_derecho(arbol->p_nodo,&a[6]);

// 	insertar_hijo_izquierdo(arbol->p_nodo->nodo_der,&a[4]);
// 	insertar_hijo_derecho(arbol->p_nodo->nodo_der,&a[7]);

// 	insertar_hijo_izquierdo(arbol->p_nodo->nodo_der->nodo_izq,&a[3]);
// 	insertar_hijo_derecho(arbol->p_nodo->nodo_der->nodo_izq,&a[5]);


// 	vaciar_arbol(&arbol);
// 	recorrer_en_orden(arbol->p_nodo,&visitar);

// }


void crear_arbol(t_arbol ** p_arbol){
	//*p_arbol = NULL;
	if(*p_arbol == NULL) {
		*p_arbol = (t_arbol*) malloc(sizeof(t_arbol));
		(*p_arbol)->p_nodo =NULL;
	}

}

void unir_nodo_arbol(t_nodo_arbol * padre,  t_nodo_arbol * p_nodo_izq, t_nodo_arbol * p_nodo_der)
{
	padre->nodo_der = p_nodo_der;
	padre->nodo_izq = p_nodo_izq;
}

t_nodo_arbol * crear_nodo_arbol(t_info * info, t_nodo_arbol * p_nodo_izq, t_nodo_arbol * p_nodo_der) {

	t_nodo_arbol * p_nodo = (t_nodo_arbol * ) malloc(sizeof(t_nodo_arbol));
	p_nodo->padre = NULL;
	p_nodo->info= info;
	p_nodo->nodo_der = p_nodo_der;
	p_nodo->nodo_izq = p_nodo_izq;
	if(p_nodo_der)
		p_nodo_der->padre = p_nodo;
	if(p_nodo_izq)
		p_nodo_izq->padre = p_nodo;

	return p_nodo;

}

t_nodo_arbol * obtener_raiz(t_nodo_arbol * p_nodo)
{
	if(p_nodo->padre)
		return obtener_raiz(p_nodo->padre);
	return p_nodo;
}


t_nodo_arbol * crear_hoja(t_info * info) {

	return crear_nodo_arbol(info,NULL,NULL);
}

void insertar_hijo_izquierdo(t_nodo_arbol * p_nodo, t_info * info){
	if(p_nodo != NULL) 
		p_nodo->nodo_izq = crear_hoja(info);

}

void insertar_hijo_derecho(t_nodo_arbol * p_nodo, t_info * info){
	if(p_nodo != NULL) 
		p_nodo->nodo_der = crear_hoja(info);
}

void recorrer_en_preorden(t_nodo_arbol * p_nodo,void (*f)(t_nodo_arbol*)) {
	if(p_nodo == NULL) return;

	f(p_nodo);
	recorrer_en_preorden(p_nodo->nodo_izq,f);
	recorrer_en_preorden(p_nodo->nodo_der,f);
}

void recorrer_en_orden(t_nodo_arbol * p_nodo,void (*f)(t_nodo_arbol*)) {
	if(p_nodo == NULL) return;

	recorrer_en_orden(p_nodo->nodo_izq,f);
	f(p_nodo);
	recorrer_en_orden(p_nodo->nodo_der,f);
}
void recorrer_en_postorden(t_nodo_arbol * p_nodo,void (*f)(t_nodo_arbol*)) {
	if(p_nodo == NULL) return;
	recorrer_en_postorden(p_nodo->nodo_izq,f);
	recorrer_en_postorden(p_nodo->nodo_der,f);
	f(p_nodo);
}

void visitar(t_nodo_arbol * p_nodo){
	if(p_nodo != NULL) {
		printf("Visitando el nodo: %s \n", p_nodo->info->a );
	}
}

void borrar_nodo_arbol(t_nodo_arbol * p_nodo){

	if(p_nodo != NULL) {
		puts(p_nodo->info->a);
		if(p_nodo->info != NULL)
			free(p_nodo->info);	
		free(p_nodo);

	}

}

void vaciar_arbol(t_arbol ** p_arbol) {
	recorrer_en_postorden((*p_arbol)->p_nodo,&borrar_nodo_arbol);
	(*p_arbol)->p_nodo = NULL;
}

int comparar_etiquetas(t_info * e1,t_info * e2)
{
	if(e1 == NULL)
		return 0;

	if(e2 == NULL)
		return 0;

	return strcmp(e1->a,e2->a) == 0;
}

int comparar_nodos(t_nodo_arbol * e1,t_nodo_arbol * e2)
{
	if(e1 == e2)
		return 1;

	return comparar_etiquetas(e1->info,e2->info);
}

t_nodo_arbol * buscar_etiqueta(t_nodo_arbol * p_nodo,t_info * p_info)
{
	buscar_etiqueta_comparador(p_nodo,p_info,&comparar_nodos);
}


t_nodo_arbol * buscar_etiqueta_comparador(t_nodo_arbol * p_nodo,t_info * p_info,int (*f)(t_nodo_arbol*,t_nodo_arbol*))
{
	if(p_nodo == NULL || p_info == NULL)
		return NULL;

	t_nodo_arbol * temp = buscar_etiqueta_comparador(p_nodo->nodo_izq,p_info,&comparar_nodos);
	if(temp != NULL)
		return temp;

	if(comparar_etiquetas(p_nodo->info,p_info))
		return p_nodo;

	temp = buscar_etiqueta_comparador(p_nodo->nodo_der,p_info,&comparar_nodos);
	if(temp != NULL)
		return temp;

	return NULL;
}


t_nodo_arbol * clonar_arbol(t_nodo_arbol * p_nodo)
{
   if (p_nodo == NULL ) 
    return p_nodo;
   //create new node and make it a copy of node pointed by root
   t_nodo_arbol * temp = (t_nodo_arbol *)malloc(sizeof(t_nodo_arbol)) ;
 temp->info = copiar_etiqueta(p_nodo->info);

   temp->nodo_der = clonar_arbol(p_nodo->nodo_der);    //cloning left child
   temp->nodo_izq = clonar_arbol(p_nodo->nodo_izq);  //cloning right child

   if(temp->nodo_der)
   	temp->nodo_der->padre = temp;
   if(temp->nodo_izq)
   	temp->nodo_izq->padre = temp;
   return temp;
}

t_info * copiar_etiqueta(t_info * p_info)
{
	t_info * p_nueva_info = (t_info *) malloc (sizeof(t_info));
	strcpy(p_nueva_info->a,p_info->a);
	return p_nueva_info;
}



void refactorizar_nodo(t_nodo_arbol ** p_nodo)
{
	if(!p_nodo || !*p_nodo)
		return ;

	while((*p_nodo)->nodo_izq != NULL && (*p_nodo)->nodo_der == NULL)
	{
		t_nodo_arbol * aux = *p_nodo;
		*p_nodo = (*p_nodo)->nodo_izq;
		(*p_nodo)->padre = aux->padre;
		puts((*p_nodo)->info->a);

		free(aux->info);
		free(aux);
	}

	while((*p_nodo)->nodo_izq == NULL && (*p_nodo)->nodo_der != NULL)
	{

		t_nodo_arbol * aux = *p_nodo;
		*p_nodo = (*p_nodo)->nodo_der;
		(*p_nodo)->padre = aux->padre;
		puts((*p_nodo)->info->a);

		free(aux->info);
		free(aux);
	}

	refactorizar_nodo(&(*p_nodo)->nodo_izq);
	refactorizar_nodo(&(*p_nodo)->nodo_der);
}

