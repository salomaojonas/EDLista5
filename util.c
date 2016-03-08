/*
 * util.c
 *
 *  Created on: 03/03/2016
 *      Author: salomao
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "util.h"

void calculaOperacao(Operacao *operacao, int qtdOperacoes, Operacao *vetorOriginal){
	int resultado = 0, j, x, y, aux=0;
	int *operacoesRealizadas;
	operacoesRealizadas = malloc(qtdOperacoes*sizeof(int));
	int conta = 0;
	printf("\n***** CALCULANDO OPERAÇÕES SEGUNDO AS ORDENS DE PRIORIDADE*****\n");
	for(j=0;conta<qtdOperacoes;j++){
		char operador = operacao[j].op;

		printf("\n%d %c %d = ", operacao[j].num1, operacao[j].op, operacao[j].num2);

		switch (operador) {
			case '+':
				aux = operacao[j].num1 + operacao[j].num2;
				conta+=1;
				break;
			case '-':
				aux = operacao[j].num1 - operacao[j].num2;
				conta+=1;
				break;
			case '*':
				aux = operacao[j].num1 * operacao[j].num2;
				conta+=1;
				break;
			case '/':
				aux = operacao[j].num1 / operacao[j].num2;
				conta+=1;

				break;
			default:
				break;
		}
		printf(" %d ", aux);
		resultado+= aux;
	}
	printf("\n***** RESPOSTA : %d ", resultado);
}

void prioridades(Operacao *vetor, int qtdOperacoes){
	Operacao *vetorPrioridade, *vAuxiliar;
	int aux = qtdOperacoes-1, x;
	int iPrioridade = 0, contVAuxiliar = 0;

	vAuxiliar = malloc(qtdOperacoes*sizeof(Operacao));
	vetorPrioridade = malloc(qtdOperacoes*sizeof(Operacao));

	for(x=aux;x>=0;x--){
		if(vetor[x].parentese==1){
			vetorPrioridade[iPrioridade] = vetor[x];
			iPrioridade+=1;
		}else{
			vAuxiliar[contVAuxiliar] = vetor[x];
			contVAuxiliar+=1;
		}
	}

	int j;
	for(j=0;j<contVAuxiliar;j++){
		vetorPrioridade[iPrioridade] = vAuxiliar[j];
		iPrioridade+=1;
	}

	int k;
	printf("\n***** ORDEM DE PRIORIDADE DAS OPERAÇÕES*****\n");
	for(k=0;k<iPrioridade;k++){
		printf("\n%d %c %d", vetorPrioridade[k].num1, vetorPrioridade[k].op, vetorPrioridade[k].num2);
	}
	calculaOperacao(vetorPrioridade, qtdOperacoes, vetor);

}

Operacao preencheOperacao(int tipoOperacao){
	Operacao op;
	op.num1 = 1+(rand() % 20);
	op.num2 = 1+(rand() % 20);
	switch (tipoOperacao) {
		case 43:
			op.op = '+';
			break;
		case 45:
			op.op = '-';
			break;
		case 42:
			op.op = 'x';
			break;
		case 47:
			op.op = '/';
			break;
		default:
			break;
	}

	op.op = tipoOperacao;

	return op;
}

void insereParentese(Operacao *vetor,int qtdOperacoes ){
	int x, z, conParentese = 0 ;
		for(x=0;x<qtdOperacoes; x++){
			z = (rand() % 2);
			if(z>0){
				vetor[x].parentese = 1; // coloca o parêntese na operação em questão.
				conParentese+=1;
			}
		}
		printf("\nQuantidade de parentese adicionados %d:", conParentese);
}

void geraOperacoes(QTDOperacoes operacoes, int qtdOperacoes, char parentese[]){
	Operacao *vetor;
	int aux, contador=0;
	printf("%c ???? ", parentese);
	printf("\nTem parêntese ? ");
	parentese == 's' ? printf("SIM\n") : printf("NÃO\n");

	vetor = malloc(qtdOperacoes*sizeof(Operacao));
	if(operacoes.soma>0){
		for(aux=0;aux<operacoes.soma;aux++){
			Operacao operacao = preencheOperacao(43);
			vetor[contador] = operacao;
			contador+=1;
		}
	}

	if(operacoes.sub>0){
		for(aux=0;aux<operacoes.sub;aux++){
			Operacao operacao = preencheOperacao(45);
			vetor[contador] = operacao;
			contador+=1;
		}
	}

	if(operacoes.mult>0){
		for(aux=0;aux<operacoes.mult;aux++){
			Operacao operacao = preencheOperacao(42);
			vetor[contador] = operacao;
			contador+=1;
		}
	}

	if(operacoes.div>0){
		for(aux=0;aux<operacoes.div;aux++){
			Operacao operacao = preencheOperacao(47);
			vetor[contador] = operacao;
			contador+=1;
		}
	}

	if(parentese == 's'){
		insereParentese(vetor , qtdOperacoes);
	}


	int x;
	printf("\n***** OPERAÇÃO A SER CALCULADA *****\n");
	for(x=0;x<qtdOperacoes;x++){
		if(vetor[x].parentese==1)
			printf("(%d %c %d)", vetor[x].num1, vetor[x].op, vetor[x].num2);
		else
			printf("%d %c %d", vetor[x].num1, vetor[x].op, vetor[x].num2);
		if(x<qtdOperacoes-1)
			printf(" + ");
	}

	prioridades(vetor, qtdOperacoes);

}

void questao(){
	srand(time(NULL));
	char parentese;
	QTDOperacoes operacoes;
	int qtdOperacoes = 0;

	printf("Informe a quantidade de somas:");
	scanf("%d", &operacoes.soma);
    __fpurge(stdin);
	qtdOperacoes+=operacoes.soma;

	printf("Informe a quantidade de subtrações:");
	scanf("%d", &operacoes.sub);
    __fpurge(stdin);
	qtdOperacoes+=operacoes.sub;

	printf("Informe a quantidade de multiplicações:");
	scanf("%d", &operacoes.mult);
    __fpurge(stdin);
	qtdOperacoes+=operacoes.mult;

	printf("Informe a quantidade de divisões:");
	scanf("%d", &operacoes.div);
    __fpurge(stdin);
	qtdOperacoes+=operacoes.div;
    __fpurge(stdin);

	printf("Vai ter parêntese ?");
	scanf("%c", &parentese);
    __fpurge(stdin);

	geraOperacoes(operacoes, qtdOperacoes, parentese);

}
