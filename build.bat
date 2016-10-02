flex lex.l

bison -dyv syntax.y

gcc.exe lex.yy.c y.tab.c arbol.c pila.c cola.c ts.c funciones.c -o final.exe