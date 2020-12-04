# Despertador

O objetivo desse projeto é simular um despertador, em que o usuário usa as teclas para definir de que modo o despertador operará e, ao acabar o tempo, as lâmpadas do quarto (relé) serão acendidas. O usuário pode escolher entre 3 opções: digitar o horário manualmente, escolher quantos ciclos de sono ele gostaria de ter ou escolher a opção automática (simulação de um sensor de luminosidade).

Para isso, foi usado a IDE MPLABx e o simulador PICSimLab.

## Periféricos usados

* **Teclas:** Recebem a opção do usuário e o horário para o fim da contagem.
* **LCD HD44780 16x4:** Mostra a opção escolhida e o horário atual. 
  * Manualmente: Mostra o horário definido pelo usuário.
  * Por ciclos: Mostra quantas horas o usuário vai dormir de acordo com a quantidade de ciclos de sono escolhida.
  * Automaticamente: Apenas sinaliza que está aguardando o amanhecer.
* **Potenciômetro:** simula um LDR.
* **Relé:** liga as lâmpadas do quarto quando o despertador tocar (simulação).

## Arquivos

As bibliotecas referentes a periféricos são previamente existentes.

A biblioteca referente ao ADC foi feita por Luis Claudio Gambôa Lopes.
Os arquivos config.h e pic18f4520.h foram feitos pelo professor Rodrigo Almeida.
As bibliotecas referentes ao LCD e ao teclado foram disponibilizadas pelos professores Otávio Gomes e Rodrigo Almeida.

Os seguintes arquivos foram feitas por mim:
* **Relógio** Possui duas funções:
 * Imprime no LCD o horário atual.
 * Imprime no LCD o horário em que se deseja acordar.
* **Opção:** Possui uma função que lê das teclas o modo de operação desejado.
* **Ciclo:** Possui uma função que lê das teclas a quantidade de ciclos de sono desejadas pelo usuário e retorna esse valor.
* **Manual:** Possui duas funções:
 * Lê das teclas as horas de quando se deseja acordar.
 * Lê das teclas os minutos de quando se deseja acordar.
* **Delay:** Define um atraso.
* **itoa:** Transforma o valor lido no ADC em um float.

### Main

Na main temos a chamada das funções mencionadas anteriormente além da contagem de horas para o relógio, e o estabelecimento das condições para que o relé seja acionado.
