#include "despertador.h"
#include "ssd.h"

void relogio7seg(int hora, int min, int seg) {
    float tempo;
    seg++;
    if (seg == 60) {
        seg = 0;
        min++;
        if (min == 60) {
            min = 0;
            hora++;
            if (hora == 24) {
                hora = 0;
            }
        }
    }
    ssdDigit(((min / 1) % 10), 0);
    ssdDigit(((min / 10) % 10), 1);
    ssdDigit(((hora / 1) % 10), 2);
    ssdDigit(((hora / 10) % 10), 3);
    ssdUpdate();
    for (tempo = 0; tempo < 100; tempo++); // +- 10ms  
    //fim funcao relogio
}