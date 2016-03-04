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
	int num1;
	int operacao;
	int num2;
}Op;

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

#endif /* UTIL_H_ */
