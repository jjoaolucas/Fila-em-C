#include <stdio.h>
#define MAX 10

int menu(){
	int opc;
	
	printf ("\n1 - Inserir Elemento");
	printf ("\n2 - remover");
	printf ("\n3 - maior, menor e media");
	printf ("\n4 - maiores q 10 e multiplos de 5");
	printf ("\n5 - pares");
	printf ("\n6 - Maior elemento\n");
	scanf ("%d" , &opc);
	
	return opc;
}

int inicio=0, fim=-1, fila[MAX];

int filavazia(){
	if(inicio > fim)
		return 1;
	else
		return 0;
}

int filacheia(){
	if(fim==MAX-1)
		return 1;
	else
		return 0;
}

void inserir(){
	int valor;
	if(!filacheia()){
		printf ("\nElemento para inserir na pilha: ");
		scanf ("%d" , &valor);
		fim++;
		fila[fim]=valor;
		printf ("\nElemento %d inserido com sucesso!\n", fila[fim]);
	}else 
		printf ("Fila cheia");
}

void remover(){
	int valor;
	if(!filavazia()){
		valor = fila[inicio];
		inicio++;
		printf ("\nElemento %d removido com sucesso!\n", valor);
	}else 
		printf ("Fila vazia");
}

void calculo(){
	int maior=0, menor=9999, soma=0, i;
	float media;
	
	if(!filavazia()){
		for(i=inicio;i<=fim;i++){
			if(fila[i] > maior)
				maior=fila[i];
			if(fila[i] < menor)
				menor = fila[i];
			soma += fila[i];	
		}
		media = (float)soma / ((fim+1) - inicio);
		
		printf ("\nMaior elemento da fila %d" , maior);
		printf ("\nMenor elemento da fila %d" ,  menor);
		printf ("\nMedia aritmetica da fila: %.2f" , media);
	}else
		printf ("Fila vazia");
}

int maiormulti(){
	int cont=0, i;
	
	if (!filavazia()){
		for (i=inicio;i<=fim;i++){
			if(fila[i] > 10 && fila[i] % 5 == 0)
				cont++;
		}
		return cont;
	}else
		printf ("fila vazia");
}

void pares(){
	int i;
	if (!filavazia()){
		for (i=inicio;i<=fim;i++){
			if(fila[i] % 2 == 0)
				printf ("%d\n" , fila[i]);
		}
			
	}else
		printf ("Fila vazia");
}

int impares(){
	int i, cont=0;
	if(!filavazia()){
		for (i=inicio;i<=fim;i++){
			if(fila[i] % 2 == 1)
				cont++;
		}
		return cont;
	}else
		printf ("fila vazia");
}

main()
{
	int opc, valor;
	
	opc = menu();
	while(opc != 0 ){
			switch(opc){
				case 1: inserir();
						system("pause");
				break;
				case 2: remover();
						system("pause");
				break;
				case 3: calculo();
						system("pause");
				break;
				case 4: printf ("A quantidade de elementos maiores que 10 e multiplos de 5: %d" , maiormulti());
						system("pause");
				break;
				case 5: pares();
						system("pause");
				break;
				case 6: printf ("A quantidade de elementos impares: %d" , impares());
						system("pause");
				
			}
		opc =menu();
	}
}










