#include "opcao.h"
#include "lcd.h"
#include "teclado.h"
#include "pic18f4520.h"

int escolha(){
    unsigned char opcao, manual;
    int start;
    lcd_cmd(L_CLR);
    lcd_cmd(L_L3);
    lcd_str("1 - Manual");
    lcd_cmd(L_L4);
    lcd_str("2 - Automatico");
    TRISD = 0x0F;
    opcao = tc_tecla(0) + 0x30;
    TRISD = 0x00;
    switch (opcao) {
        case '1':
            lcd_cmd(L_CLR);
            lcd_cmd(L_L3);
            lcd_str("1 - Manual");
            lcd_cmd(L_L4);
            lcd_str("2 - Ciclos");
            TRISD = 0x0F;
            manual = tc_tecla(0) + 0x30;
            TRISD = 0x00;
            if(manual=='1'){
                start=1;
            }else if(manual=='2'){
                start=2;
            }
            break;
        case '2':
            start = 3;
            break;
    }
    return start;
}
