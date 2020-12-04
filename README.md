# Despertador

O objetivo desse projeto é simular um despertador, em que o usuário usa as teclas para definir de que modo o despertador operará e, ao acabar o tempo, as lâmpadas do quarto (relé) serão acendidas. O usuário pode escolher entre 3 opções: digitar o horário manualmente, escolher quantos ciclos de sono ele gostaria de ter ou escolher a opção automática (simulação de um sensor de luminosidade).
Para isso, foi usado a IDE MPLABx e o simulador PICSimLab. As bibliotecas referentes aos periféricos são previamente existentes.

## Periféricos usados

* **Teclas:** Recebem a opção do usuário e o horário para o fim da contagem.
* **LCD HD44780 16x4:** Mostra a opção escolhida e o horário atual. 
  * Manualmente: mostra o horário definido pelo usuário.
  * Por ciclos: mostra quantas horas o usuário vai dormir de acordo com a quantidade de ciclos de sono escolhida.
  * Automaticamente: apenas dirá que está aguardando o amanhecer.
* **Potenciômetro:** simula um LDR.
* **Relé:** liga as lâmpadas do quarto quando o despertador tocar (simulação).
