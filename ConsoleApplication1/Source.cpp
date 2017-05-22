/*
* Criar uma Lista que armazene os dados cadastrais das pessoas que compraram em uma determinada loja de um shopping.
* Usando uma lista encadeada
* Dados cadastrais:
Nome (30 caracteres);
cpf (12 caracteres);
email (50 Caracteres);
telefone (12 Caracteres).
* O programa dever� ter a possibilidade de pesquisar de forma sequencial um determinado cliente que a loja deseje.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHONOME 30
#define TAMANHOCPF 12
#define TAMANHOEMAIL 50
#define TAMANHOTELEFONE 12

//Vamos come�ar definindo uma estrutura de dados capaz de armazenar 
// os n�s desta lista e o ponteiro para o pr�ximo n�. 

struct Lista {
	char nome[TAMANHONOME];
	char cpf[TAMANHOCPF];
	char email[TAMANHOEMAIL];
	struct Lista *prox;			//cont�m uma estrura do mesmo tipo que armazena os dados da 
													//posi��o da lista
};

//Agora vamos instanciar esta struc, para o primeiro elemento da lista, o �ltimo e
//um elemento tempor�rio
struct Lista *prim, *ulti, *ptr;

//prot�tipos
int menu();
void pesquisar();
void incluir();


int main() {
	int op = 1;
	prim = NULL;
	ulti = NULL;

	while (op != 3) {
		op = menu();
		switch (op) {
		case 1:
			incluir();
			break;
		case 2:
			pesquisar();
			break;
		}	//fim switch
	}	//fim while
	system("Pause");
	return 0;
}

int menu()
{
	int op = 0, c = 0;
	//vamos limpar a tela todas as vezes que o menu aparecer
	system("cls");
	printf("Digite 1 para Incluir:\n");
	printf("Digite 2 para Pesquisar:\n");
	printf("Digite 3 para sair:\n");

	scanf_s("%d", &op);
	//sempre limpe o buffer de teclado se usar o scanf/scanf_s
	while ((c = getchar()) != '\n' && c != EOF) {}

	return(op);
}

void pesquisar() {
	char cliente[TAMANHONOME];
	//lembre-se que a structs s�o globais
	//igualando a tempor�ria com a primeira colocamos o cursor da lista
	//na primeira posi��o
	ptr = prim;

	if (prim == NULL)	//n�o foi inclu�do nenhum registro
		printf("N�o h� registros de clientes.\n");
	else {
		printf("Digite o nome do cliente que deseja pesquisar:");
		//recolher toda a linha digitada
		gets_s(cliente);

		//vamos percorrer toda a lista
		while (ptr != NULL) {
			if (strcmp(cliente, ptr->nome) == 0) {
				//achamos o cliente ent�o vamos mostrar
				printf("Foi encontrado o seguinte cliente:\n");
				printf("Nome: %s\n", ptr->nome);
				printf("CPF: %s\n", ptr->cpf);
				printf("Email: %s\n", ptr->email);
				printf("\n\n");
				//e vamos dar uma parada para ler... 
				system("Pause");
				break;
			}
			//corremos a lista toda
			//agora apontamos o cursor para a pr�xima posi��o da lista
			ptr = ptr->prox;
		}
	}
}


void incluir() {
	//primeiro vamos definir um n� tempor�rio, ptr e alocar mem�ria para ele
	//usamos o malloc para alocar um fragmento cont�nuo de mem�ria que seja 
	//do tamanho da estrutura que vamos usar 
	ptr = (struct Lista *) malloc(sizeof(struct Lista));

	//puts escreve um string no dispositivo padr�o seguido de uma
	//quebra de linha o printf escreve um string no dispositivo 
	//padr�o segundo uma regra de formata��o
	puts("Digite os dados do Cliente:");
	puts("Informe Nome: ");
	gets_s(ptr->nome);
	puts("Informe CPF: ");
	gets_s(ptr->cpf);
	puts("Informe Email: ");
	gets_s(ptr->email);
	ptr->prox = NULL;
	// para incluri na lista
	if (prim == NULL) {
		// a lista est� vazia, 
		// a primeira posi��o � igula a �ltima
		ulti = ptr;
		prim = ptr;
	}
	else {
		//a lista n�o est� vazia
		// a struct prox do �ltim n� aponta para a 
		// o n� tempor�rio
		ulti->prox = ptr;
		//o �ltimo n� vira o n� tempor�rio
		ulti = ptr;
	}
}
