/*
 * util.h
 *
 *  Created on: 03/03/2016
 *      Author: salomao
 */

#ifndef UTIL_H_
#define UTIL_H_

typedef struct{
	int num1;
	int op;
	int num2;
	int parentese;
}Operacao;

typedef struct{
	int soma;
	int sub;
	int mult;
	int div;
}QTDOperacoes;

typedef struct{
	int op;
	int qtd;
}QTDParentese;

void questao ();

void geraOperacoes (QTDOperacoes, int, char);

Operacao preencheOperacao (int);

void insereParentese (Operacao *,int);

void prioridades (Operacao *, int);

void calculaOperacao (Operacao *, int, Operacao *);

#endif /* UTIL_H_ */
