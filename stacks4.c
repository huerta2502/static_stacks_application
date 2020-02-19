/***************************************************************************************
 * static_stacks_menu
 * @author: Carlos Huerta García
 * @description: Displays a menu to execute stacks functions with int and char functions
 * *************************************************************************************/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct intStack{
    int top;
    unsigned capacity;
    int* array;
} intStack;
typedef struct charStack{
    int top;
    unsigned capacity;
    char* array;
} charStack;
intStack* initIntStack(int capacity){
	intStack* stack = (intStack*)malloc(sizeof(intStack));
	if(stack == NULL)
		exit(1);
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int*)calloc(stack->capacity, sizeof(int));
	if(stack->array == NULL)
		exit(1);
	return stack;
}
charStack* initCharStack(int capacity){
	charStack* stack = (charStack*)malloc(sizeof(charStack));
	if(stack == NULL)
		exit(1);
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (char*)calloc(stack->capacity, sizeof(char));
	if(stack->array == NULL)
		exit(1);
	return stack;
}
bool isEmptyIntStack(intStack* stack){
    return stack->top == -1 || stack == NULL;
}
bool isEmptyCharStack(charStack* stack){
    return stack->top == -1 || stack == NULL;
}
bool isFullIntStack(intStack* stack){
	return stack->top == stack->capacity - 1;
}
bool isFullCharStack(charStack* stack){
	return stack->top == stack->capacity - 1;
}
void pushIntStack(intStack* stack, int item){
    if(isFullIntStack(stack)){
		puts("\nLa pila de enteros está llena\n");
    	return;
	} else
    	stack->array[++stack->top] = item; 
}
void pushCharStack(charStack* stack, char item){
    if(isFullCharStack(stack)){
		puts("\nLa pila de caracteres está llena\n");
    	return;
	} else
    	stack->array[++stack->top] = item; 
}
int popIntStack(intStack* stack){
    if(isEmptyIntStack(stack)){
		puts("\nLa pila de enteros está vacía\n");
    	return INT_MIN;
	} else
    	return stack->array[stack->top--];
}
char popCharStack(charStack* stack){
    if(isEmptyCharStack(stack)){
		puts("\nLa pila de caracteres está vacía\n");
    	return CHAR_MIN;
	} else
    	return stack->array[stack->top--];
}
int peekIntStack(intStack* stack){
    if(isEmptyIntStack(stack)){
		puts("\nLa pila de enteros está vacía\n");
    	return INT_MIN;
	} else
    	return stack->array[stack->top];
}
char peekCharStack(charStack* stack){
    if(isEmptyCharStack(stack)){
		puts("\nLa pila de caracteres está vacía\n");
    	return CHAR_MIN;
	} else
    	return stack->array[stack->top];
}
void printIntStack(intStack* stack){
    if(isEmptyIntStack(stack)){
		puts("\nLa pila de enteros está vacía\n[ ]\n");
    	return;
	} else{
    	int i = 0;
    	for(i = 0; i <= stack->top; i++)
    		printf("[%d]->", stack->array[i]);
	}
}
void printCharStack(charStack* stack){
    if(isEmptyCharStack(stack)){
		puts("\nLa pila de caracteres está vacía\n");
    	return;
	} else{
    	int i = 0;
    	for(i = 0; i <= stack->top; i++)
    		printf("[%c]->", stack->array[i]);
	}
}
void clearIntStack(intStack* stack){
	if(isEmptyIntStack(stack)){
		puts("\nLa pila de enteros está vacía\n");
    	return;
	} else{
    	free(stack->array);
    	stack->top = -1;
    }
}
void clearCharStack(charStack* stack){
	if(isEmptyCharStack(stack)){
		puts("\nLa pila de caracteres está vacía\n");
    	return;
	} else{
    	free(stack->array);
    	stack->top = -1;
    }
}

void main() {
	intStack* newIntStack = NULL;
	charStack* newCharStack = NULL;
	char go = 's', newChar;
	int option, charStackCapacity, stackCapacity, floatStackCapacity, newInt;
	float newFloat;
	do{
		puts("0 Salir");
		puts("1 Crear pila de caracteres");
		puts("2 Crear pila de enteros");
		puts("3 Mostrar pila de caracteres");
		puts("4 Mostrar pila de enteros");
		puts("5 Tomar el último caracter");
		puts("6 Tomar el último entero");
		puts("7 Quitar el último caracter");
		puts("8 Quitar el último entero");
		puts("9 Agregar un caracter");
		puts("10 Agregar un entero");
		puts("11 Vaciar la pila de caracteres");
		puts("12 Vaciar la pila de enteros");
		puts("13 Tope pila de caracteres");
		puts("14 Tope de pila de enteros");
		scanf("%d", &option);
		switch(option){
			case 0:
				exit(0);
				clearIntStack(newIntStack);
    			clearCharStack(newCharStack);
				break;
			case 1:
				puts("Introduza la capacidad de la pila de caracteres:");
				scanf("%d", &charStackCapacity);
				newCharStack = initCharStack(charStackCapacity);
				break;
			case 2:
				puts("Introduza la capacidad de la pila de enteros:");
				scanf("%d", &stackCapacity);
				newIntStack = initIntStack(stackCapacity);
				break;
			case 3:
				printCharStack(newCharStack);
				break;
			case 4:
				printIntStack(newIntStack);
				break;
			case 5:
				printf("%c\n", peekCharStack(newCharStack));
				break;
			case 6:
				printf("%d\n", peekIntStack(newIntStack));
				break;
			case 7:
				printf("%c\n", popCharStack(newCharStack));
				break;
			case 8:
				printf("%d\n", popIntStack(newIntStack));
				break;
			case 9:
				if(newCharStack != NULL){
					fflush(stdin);
					printf("Introduzca el caracter: ");
					fflush(stdin);
					scanf("%c", &newChar);
					scanf("%c", &newChar);
					pushCharStack(newCharStack, newChar);
				} else 
					puts("La pila de caracteres no ha sido creada");
				break;
			case 10:
				if(newIntStack != NULL){
					puts("Introduzca el entero");
					scanf("%d", &newInt);
					pushIntStack(newIntStack, newInt);
				} else 
					puts("La pila de enteros no ha sido creada");
				break;
			case 11:
				clearCharStack(newCharStack);
				break;
			case 12:
				clearIntStack(newIntStack);
				break;
			case 13:
				printf("%d\n", newCharStack->top);
				break;
			case 14:
				printf("%d\n", newIntStack->top);
				break;
			default:
				puts("Operación inválida");
				break;
		}
		printf("\n¿Desea realizar más operaciones? (s/n): ");
		fflush(stdin);
		scanf("%c", &go);
		scanf("%c", &go);
	} while(go == 's');
    clearIntStack(newIntStack);
    clearCharStack(newCharStack);
}
