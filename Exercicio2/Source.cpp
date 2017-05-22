/*
* Criar um programa que possibilite a pesquisa “binária” em um vetor com 10.000 numeros inteiros.
*/

#include<stdio.h>
#include<stdlib.h>
#include <time.h> //para usar a função time

//apenas para declarar as variáveis que vamos usar
//para testar seu código, você pode usar apenas 3 pessoas.
//depois substitua por 10000
#define COMPRIMENTOVETOR 10000

//protótipos
int pesquisar(int, int, int, int[]);

int main() {
	int vet[COMPRIMENTOVETOR];
	int num = 0, ret = 0, c = 0, temp = 0;
	//precisamos preencher este array com alguma coisa... para testar.
	printf("Gerando os numeros...\n");
	//para preencher o array com números aleatórios
	srand(time(0)); //semente para o gerador de números aleatórios
	//agora podemos preencher o array
	for (int i = 0; i < COMPRIMENTOVETOR; i++) {
		vet[i] = (rand() % 100) + 1;	//gerando números randômicos entre zero e 100
	}

	printf("Ordenando o array...\n");
	//agora precisamos ordenar o vetor gerado 
	//vou usar o bubble sort mesmo 
	for (int i = 0; i < COMPRIMENTOVETOR; i++) {
		for (int j = i + 1; j < COMPRIMENTOVETOR; j++) {
			if (vet[i] > vet[j]) {
				temp = vet[i];
				vet[i] = vet[j];
				vet[j] = temp;
			}
		}
	}

	printf("Informar número que deseja pesquisar: ");
	scanf_s("%d", &num);
	//sempre limpe o buffer de teclado depois de usar o scanf/scanf_s
	while ((c = getchar()) != '\n' && c != EOF) {}

	//agora chamamos a função que vai pesquisar o vetor
	ret = pesquisar(0, 9999, num, vet);
	if (ret > -1)
		printf("O Número se encontra no Vetor, na posicao %d.\n", ret);
	else
		printf("O Número Não foi localizados no Vetor\n");

	system("Pause");
	return 0;
}

/*
* pesquisar, 
* Params: ini, posição inicial;
					fim, Posição final;
					num, Valor a ser procurado;
					vet, Vetor que será procurado. 
	Return: a posição do numero pesquisado no vetor
*/

int pesquisar(int ini, int fim, int num, int vet[]) {
	int pos, ret;

	if (ini > fim)
		return(-1);
	//encontra a posição que fica no meio do vetor
	pos = ini + (int)((fim - ini) / 2);

	//verifica se já não é o número procurado
	if (vet[pos] == num)
		return(pos);
	//agora faz a busca chamando pesquisar recursivamente
	//correndo as posições inicial e final em sentido opostos
	else if (num > vet[pos])
		ret = pesquisar(pos + 1, fim, num, vet);
	else
		ret = pesquisar(ini, pos - 1, num, vet);

	return(ret);
}

