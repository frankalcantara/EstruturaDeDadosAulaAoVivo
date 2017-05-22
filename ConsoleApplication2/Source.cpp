/*
* Um colecionador de vinhos guarda seus vinhos em uma adega para envelhecimento,
* a cada ocasi�o especial abre sempre sua �ltima aquisi��o, para poupar os mais antigos.
* Sabendo do se que as informa��es b�sicas que o registro do vinho deve conter s�o
*		Vinho (30 caracteres);
*		Data (8 caracteres);
*		Safra (um �nteiro).
*		Construa um programa que :
*			a.Permita incluir novos vinhos na adega;
*			b.Informe qual vinho deve ser aberto em uma ocasi�o especial;
*/

#include <stdio.h>
#include <stdlib.h>

#define VINHONOME 30
#define DATACOMPRIMENTO 10

//vamos montar uma pilha usando uma lista encadeada como estrutura de armazenamento
//sendo assim, vamos precisar de uma estrutura para armazenar os dados e o ponteiro
//do pr�ximo item
struct Dados {
	char vinho[VINHONOME], data[DATACOMPRIMENTO];
	int safra;
	struct Dados *prox;
};

struct Dados *prim, *ptr;

//prot�tipos 
int menu();
void armazenar_vinho();
void retirar_vinho();


int main() {
	int op = 1;
	prim = NULL;

	while (op != 3) {
		op = menu();
		switch (op) {
		case 1:
			armazenar_vinho();
			break;
		case 2:
			retirar_vinho();
			break;
		}
	}

	system("Pause");
	return 0;
}


int menu() {
	int op = 0, c = 0;
	printf("Informe 1 para incluir vinhos na Pilha: \n");
	printf("Informe 2 para retirar vinhas da Pilha: \n");
	printf("Informe 3 para sair: \n");

	scanf_s("%d", &op);
	//sempre limpe o buffer do teclado.
	while ((c = getchar()) != '\n' && c != EOF) {}

	return(op);
}

void armazenar_vinho() {
	int c = 0;
	//Alocando a mem�ria necess�ria ao armazenamento da pilha
	ptr = (struct Dados *) malloc(sizeof(struct Dados));
	//armazenado os dados digitados diretamente na struc tempor�ria local
	puts("Informe o vinho: ");
	gets_s(ptr->vinho);
	puts("Informe a data : ");
	gets_s(ptr->data);
	puts("Informe a safra : ");
	scanf_s("%d", &ptr->safra);
	//sempre limpe o buffer do teclado.
	while ((c = getchar()) != '\n' && c != EOF) {}

	//armazenando a struc local no topo da pilha.
	if (prim == NULL) {
		ptr->prox = NULL;
		prim = ptr;
	}
	else {
		prim->prox = ptr;
		prim = ptr;
	}
}


void retirar_vinho() {
	if (prim == NULL)
		printf("N�o h� vinhos armazenados.");
	else {
		printf("O pr�ximo vinho a ser consumido ser�: ");
		printf("Vinho: %s.\nData : %s.\nSafra : %d.\n", prim->vinho, prim->data, prim->safra);
		ptr = prim;
		prim = prim->prox;
		free(ptr);
	}
}


