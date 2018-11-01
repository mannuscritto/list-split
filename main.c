/* Program Name: List-Split
 * Description: There is a function that splits an original linked list into two different ones.
 * Latest Modification Date: Thu 11/01/2018
 * Author: GitHub @mannuscritto
 * Version: 0.1.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct node {
	int value;
	struct node *next;
};

typedef struct node snode;
snode *newNode, *pointer, *back, *temp;
snode *front = NULL, *rear = NULL;

snode* createNode(int val) {
	newNode = (snode *)malloc(sizeof(snode));
	if (newNode == NULL) {
		printf("\nO nó não foi alocado!\n");
	} else {
		newNode->value = val;
		newNode->next = NULL;
		return newNode;
	}
}

void insertion(int val, int pos) {
	int count = 0, i;
	newNode = createNode(val);
	pointer = front;
	while (pointer != NULL) {
		pointer = pointer->next;
		count++;
	}
	if (pos == 1) {
		if (front == NULL) {
			front = rear = newNode;
			front->next = NULL;
			rear->next = NULL;
		} else {
			temp = front;
			front = newNode;
			front->next = temp;
		}
		printf("\nValor %d inserido com sucesso!\n", val);
	} else if (pos > 1 && pos <= count) {
		pointer = front;
		for (i = 1; i < pos; i++) {
			back = pointer;
			pointer = pointer->next;
		}
		back->next = newNode;
		newNode->next = pointer;
		printf("\nValor %d inserido com sucesso!\n", val);
	} else if (pos == count+1) {
		if (front == NULL) {
			front = rear = newNode;
			front->next = NULL;
			rear->next = NULL;
		} else {
			rear->next = newNode;
			rear = newNode;
			rear->next = NULL;
		}
		printf("\nValor %d inserido com sucesso!\n", val);
	} else {
		printf("\nA posição escolhida não existe!\n");
	}
}

//Remover
void deletion(int pos) {
	int count = 0, i, vlr;
	if (front == NULL) {
		printf("\nNão existem elementos para deletar!\n");
	} else {
		pointer = front;
		if (pos == 1) {
			vlr = front->value;
			front = pointer->next;
			printf("\nValor %d deletado com sucesso!\n", vlr);
		} else {
			while (pointer != NULL) {
				pointer = pointer->next;
				count++;
			}
			if (pos > 0 && pos <= count) {
				pointer = front;
				for (i = 1; i < pos; i++) {
					back = pointer;
					pointer = pointer->next;
				}
				back->next = pointer->next;
			} else {
				printf("\nA posição escolhida não existe!\n");	
			}
			free(pointer);
			printf("\nElemento deleteado com sucesso!\n");
		}
	}
}

//Teste função mostrar
void display() {
	if (front == NULL) {
		printf("\nImpossível imprimir valores! A lista está vazia!\n");
		return;
	} else {
		printf("|");
		for (pointer = front; pointer != NULL; pointer = pointer->next) {
			printf(" %d |", pointer->value);
		}
		printf("\n");
	}
}

void displayItem(int pos) {
	if (front == NULL) {
		printf("\nImpossível imprimir valores! A lista está vazia!\n");
		return;
	} else {
		int count = 0, i;
		pointer = front;
		while (pointer != NULL) {
			pointer = pointer->next;
			count++;
		}
		pointer = front;
		if (pos > 0 && pos <= count) {
			for (i = 1; i < pos; i++) {
				pointer = pointer->next;
			}
			printf("\n| %d |\n", pointer->value);
		} else {
			printf("\nA posição escolhida não existe!\n");	
		}
	}
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	int opt, vlr, pos;
	while (1) {
		system("cls");
		printf("MENU\n\n");
		printf("\tInserir     [1]\n");
		printf("\tDeletar     [2]\n");
		printf("\tImprimir    [3]\n");
		printf("\tExibir item [4]\n");
		printf("\tSair        [0]\n");
		printf("Digite a opção: ");
		scanf("%d", &opt);
		switch (opt) {
			case 1: 
				printf("\nDigite o valor do item: ");
				do {
					scanf("%d", &vlr);
				} while(vlr < 0);
				printf("\nDigite a posição para inserir %d: ", vlr);
				do {
					scanf("%d", &pos);
				} while(pos < 0);
				insertion(vlr, pos);
				break;
			case 2:
				printf("\nDigite a posição para remover %d: ", vlr);
				do {
					scanf("%d", &pos);
				} while(pos < 0);
				deletion(pos);
				break;
			case 3:
				display();
				break;
			case 4:
				printf("\nDigite a posição para exibir: ");
				do {
					scanf("%d", &pos);
				} while(pos < 0);
				displayItem(pos);
				break;
			case 0:
				exit(0);
				break;
			default:
				printf("\nOpção Inválida!\n");
		}
		system("pause");
	}
	return 0;
}
