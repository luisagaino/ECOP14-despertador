#include "i2f.h"

float i2f(unsigned int valor) {
    char a, b;
    int c, d;
    float adc;
    a = ((valor % 100) / 10) + 0x30;
    b = (valor % 10) + 0x30;
    switch(a){
        case '0':
            c=0;
            break;
        case '1':
            c=1;
            break;
        case '2':
            c=2;
            break;
        case '3':
            c=3;
            break;
        case '4':
            c=4;
            break;
        case '5':
            c=5;
            break;
    }
    switch(b){
        case '0':
            d=0;
            break;
        case '1':
            d=1;
            break;
        case '2':
            d=2;
            break;
        case '3':
            d=3;
            break;
        case '4':
            d=4;
            break;
        case '5':
            d=5;
            break;
        case '6':
            d=6;
            break;
        case '7':
            d=7;
            break;
        case '8':
            d=8;
            break;
        case '9':
            d=9;
            break;
    }
    adc = c + d*0.1;
    return adc;
}
