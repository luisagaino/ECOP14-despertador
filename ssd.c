// -----------------------------------------------------------------------
//   Copyright (C) Rodrigo Almeida 2010
// -----------------------------------------------------------------------
//   Arquivo: ssd.c
//            Biblioteca de controle dos displays de 7 segmentos
//   Autor:   Rodrigo Maximiano Antunes de Almeida
//            rodrigomax at unifei.edu.br
//   Licen�a: GNU GPL 2
// -----------------------------------------------------------------------
//   This program is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation; version 2 of the License.
//
//   This program is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License for more details.
// -----------------------------------------------------------------------


#include "ssd.h"
#include "pic18f4520.h"

//vetor para armazenar a convers�o do display
static const char valor[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
//armazena qual � o display disponivel
static char display;
//armazena o valor a ser enviado ao display
static char v0, v1, v2, v3;

void ssdDigit(char val, char pos)
{
	if (pos == 0)
	{
		v0 = val;
	}
	if (pos == 1)
	{
		v1 = val;
	}
	if (pos == 2)
	{
		v2 = val;
	}
	if (pos == 3)
	{
		v3 = val;
	}

}

void ssdUpdate(void)
{
	//desliga todos os displays
	PORTA = 0x00;
	//desliga todos os leds
	PORTD = 0x00;

	switch(display) //liga apenas o display da vez
	{
		case 0:
			PORTD = valor[v0];
			BitSet(PORTA,5);
			display = 1;
		break;

		case 1:
			PORTD = valor[v1];
			BitSet(PORTA,4);
			display = 2;
		break;

		case 2:
			PORTD = valor[v2];
			BitSet(PORTA,3);
			display = 3;
		break;

		case 3:
			PORTD = valor[v3];
			BitSet(PORTA,2);
			display = 0;
		break;

		default:
			display = 0;
		break;
	}
}


void ssdInit(void)
{
	//configura��o dos pinos de controle
    TRISA = 0x00;
	ADCON1 = 0x0E; //apenas AN0 � analogico, a referencia � baseada na fonte
	TRISD = 0x00;	//Porta de dados
    BitClr(INTCON2, 7);
}