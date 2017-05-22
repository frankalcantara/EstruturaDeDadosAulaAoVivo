/*
* Criar uma Lista que armazene os dados cadastrais das pessoas que compraram em uma determinada loja de um shopping.
* Usando uma lista encadeada
* Dados cadastrais:
Nome (30 caracteres);
cpf (12 caracteres);
email (50 Caracteres);
telefone (12 Caracteres).
* O programa deverá ter a possibilidade de pesquisar de forma sequencial um determinado cliente que a loja deseje.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHONOME 30
#define TAMANHOCPF 12
#define TAMANHOEMAIL 50
#define TAMANHOTELEFONE 12

//Vamos começar definindo uma estrutura de dados capaz de armazenar 
// os nós desta lista e o ponteiro para o próximo nó. 

struct Lista {
	char nome[TAMANHONOME];
	char cpf[TAMANHOCPF];
	char email[TAMANHOEMAIL];
	struct Lista *prox;			//contém uma estrura do mesmo tipo que armazena os dados da 
													//posição da lista
};

//Agora vamos instanciar esta struc, para o primeiro elemento da lista, o último e
//um elemento temporário
struct Lista *prim, *ulti, *ptr;

//protótipos
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
	//lembre-se que a structs são globais
	//igualando a temporária com a primeira colocamos o cursor da lista
	//na primeira posição
	ptr = prim;

	if (prim == NULL)	//não foi incluído nenhum registro
		printf("Não há registros de clientes.\n");
	else {
		printf("Digite o nome do cliente que deseja pesquisar:");
		//recolher toda a linha digitada
		gets_s(cliente);

		//vamos percorrer toda a lista
		while (ptr != NULL) {
			if (strcmp(cliente, ptr->nome) == 0) {
				//achamos o cliente então vamos mostrar
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
			//agora apontamos o cursor para a próxima posição da lista
			ptr = ptr->prox;
		}
	}
}


void incluir() {
	//primeiro vamos definir um nó temporário, ptr e alocar memória para ele
	//usamos o malloc para alocar um fragmento contínuo de memória que seja 
	//do tamanho da estrutura que vamos usar 
	ptr = (struct Lista *) malloc(sizeof(struct Lista));

	//puts escreve um string no dispositivo padrão seguido de uma
	//quebra de linha o printf escreve um string no dispositivo 
	//padrão segundo uma regra de formatação
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
		// a lista está vazia, 
		// a primeira posição é igula a última
		ulti = ptr;
		prim = ptr;
	}
	else {
		//a lista não está vazia
		// a struct prox do últim nó aponta para a 
		// o nó temporário
		ulti->prox = ptr;
		//o último nó vira o nó temporário
		ulti = ptr;
	}
}
