#include <stdlib.h> 
#include <math.h> 
#include <stdio.h> 

//vamos definir tudo com inteiros, para ficar mais simples, 
//mas voc� deve lembrar que n�o poderemos calcular o fatorial de
//n�meros muito grandes. Ent�o, para testar use n�meros menores que 20
//de prefer�ncia que voc� saiba o resultado. 10 fatorial 3628800

//prot�tipo
int factorial(int);

int  main() {
	//sempre inicialize suas vari�veis
	int i = 0, c = 0;
	printf("Digite o n�mero desejado:");					  
	scanf_s("%d", &i);
	//sempre limpe o buffer de teclado depois de usar o scanf/scanf_s
	while ((c = getchar()) != '\n' && c != EOF) {}
	
	//agora � s� imprimir o retorno da fun��o
	printf("Fatorial de %d: %d\n", i, factorial(i));	  

	system("Pause");
	return 0;
}

//fazendo a fun��o recursiva
int factorial(int i) {
	//condi��o de parada, para evitar o loop infinito
	if (i <= 1) {
		return 1;
	}
	//multiplica o valor inicial pelo valor devolvido pela 
	//fun��o chamada com com o valor inicial menos 1
	return i * factorial(i - 1);							
}
