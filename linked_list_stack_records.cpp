#include <stdio.h>
#include <stdlib.h>
 
typedef struct nodo{
	int dato;
	char nombre[30];
	int edad;
	char tel [10];
	struct nodo *sig;
}nodo;   

nodo *pila;

void push();	
int pop();	
void imprimir(nodo *);	
 
main(){
	
	int op;
  
	do{
		printf("\n1. Insertar\n");
		printf("2. Eliminar\n");
		printf("3. Mostrar\n");
		printf("4. Salir\n");
		scanf("%d",&op);
	
	switch(op){
		
		case 1:
		push();
		break;
		
		case 2:
		printf("\nSe elimino el  %d\n",pop());
		break;
		
		case 3:
		imprimir(pila);
		break;
		
		case 4:printf("\nADIOS !!");
		break;
	}
	
	}while(op<4);	
  }
  
void push(){

	nodo *nuevo=(nodo*)malloc(sizeof(nodo));
	nuevo->sig = pila;
	
	printf("\ningresa el nuevo el id: ");  
	scanf("%d",&nuevo->dato);
	
	printf("Ingresa el nombre : ");
	fflush(stdin);
	gets(nuevo->nombre);
	
	printf("Ingresa la edad : ");
	scanf("%d",&nuevo->edad);
	
	printf("Ingresa el telefono : ");
	fflush(stdin);
	gets(nuevo->tel);
	
	pila=nuevo;
}

int pop(){ 
 
	nodo *elim; 
	int x;
	if (pila==NULL) { 
	printf("\nLista vacia"); 
	return EOF; 
}

  else{
	
	x = pila->dato;
	  
	elim = pila;
	pila=pila->sig; //se sustituye el valor de pila con el siguiente valor
	free(elim);//libero elim
 
	return x;
}

}

void imprimir(nodo* ){ 
	
	nodo *indice=pila;
 
 while(indice!=NULL){
 	
 	printf("\n");
	printf("%d) ", indice->dato);
	printf("Nombre: %s\n", indice->nombre);
	printf("   Edad: %d\n", indice->edad);
	printf("   Telefono: %s\n", indice->tel);
	indice = indice->sig;
	printf("\n");
}

printf("\n");
 
}
