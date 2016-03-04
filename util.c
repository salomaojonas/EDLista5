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

Operacao preencheOperacao(int tipoOperacao){
	Operacao op;
	op.num1 = 1+(rand() % 100);
	op.num2 = 1+(rand() % 100);
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

void geraOperacoes(QTDOperacoes operacoes, int qtdOperacoes){
	Operacao *vetor;
	int aux, contador=0;

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

	int x;
	printf("\n*** OPERAÇÃO A SER CALCULADA ***\n");
	for(x=0;x<qtdOperacoes;x++){
		printf("%d %c %d", vetor[x].num1, vetor[x].op, vetor[x].num2);
		if(x<qtdOperacoes-1)
			printf(" + ");
	}
}

void questao(){
	srand(time(NULL));

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

	geraOperacoes(operacoes, qtdOperacoes);

}
