#include "ciclo.h"
#include "lcd.h"
#include "pic18f4520.h"
#include "teclado.h"

int ciclo(){
    unsigned char c;
    int qtd;
    lcd_cmd(L_CLR);
    lcd_cmd(L_L1);
    lcd_str("Cada ciclo tem");
    lcd_cmd(L_L2);
    lcd_str("aproximadamente");
    lcd_cmd(L_L3);
    lcd_str("1h45m. Quantos?");
    TRISD = 0x0F;
    c = tc_tecla(0) + 0x30;
    TRISD = 0x00;
    lcd_cmd(L_L4);
    lcd_dat(c);
    lcd_str(" ciclos");
    switch(c){
        case '0':
            qtd=0;
            break;
        case '1':
            qtd = 1;
            break;
        case '2':
            qtd = 2;
            break;
        case '3':
            qtd = 3;
            break;
        case '4':
            qtd = 4;
            break;
        case '5':
            qtd = 5;
            break;
        case'6':
            qtd = 6;
            break;
        case '7':
            qtd = 7;
            break;
        case '8':
            qtd = 8;
            break;
        case '9':
            qtd = 9;
            break;
    }
    return qtd;
}