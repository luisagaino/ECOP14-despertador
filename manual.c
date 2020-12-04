#include "manual.h"
#include "lcd.h"
#include "teclado.h"
#include "pic18f4520.h"

int horas() {
    int hora;
    unsigned char h1, h2;
    lcd_cmd(L_CLR);
    lcd_cmd(L_L1);
    lcd_str("Digite as horas");
    lcd_cmd(L_L2);
    lcd_str("(dois digitos):");
    lcd_cmd(L_L3);
    TRISD = 0x0F;
    h1 = tc_tecla(0) + 0x30;
    TRISD = 0x00;
    lcd_dat(h1);
    TRISD = 0x0F;
    h2 = tc_tecla(0) + 0x30;
    TRISD = 0x00;
    lcd_dat(h2);
    lcd_str(" horas");
    if(h1=='0'){
        switch(h2){
            case '0': 
                hora=0;
                break;
            case '1':
                hora=1;
                break;
            case '2':
                hora=2;
                break;
            case '3':
                hora=3;
                break;
            case '4':
                hora=4;
                break;
            case '5':
                hora=5;
                break;
            case '6':
                hora=6;
                break;
            case '7':
                hora=7;
                break;
            case '8':
                hora=8;
                break;
            case '9':
                hora=9;
                break;
        }
    }else if(h1=='1'){
        switch(h2){
            case '0': 
                hora=10;
                break;
            case '1':
                hora=11;
                break;
            case '2':
                hora=12;
                break;
            case '3':
                hora=13;
                break;
            case '4':
                hora=14;
                break;
            case '5':
                hora=15;
                break;
            case '6':
                hora=16;
                break;
            case '7':
                hora=17;
                break;
            case '8':
                hora=18;
                break;
            case '9':
                hora=19;
                break;
        }
    }else if(h1=='2'){
        switch(h2){
            case '0': 
                hora=20;
                break;
            case '1':
                hora=21;
                break;
            case '2':
                hora=22;
                break;
            case '3':
                hora=23;
                break;
        }
    }
    return hora;
}

int minutos() {
    int min;
    unsigned char m1, m2;
    lcd_cmd(L_L1);
    lcd_str("Digite minutos ");
    lcd_cmd(L_L2);
    lcd_str("(dois digitos):");
    lcd_cmd(L_L4);
    TRISD = 0x0F;
    m1 = tc_tecla(0) + 0x30;
    TRISD = 0x00;
    lcd_dat(m1);
    TRISD = 0x0F;
    m2 = tc_tecla(0) + 0x30;
    TRISD = 0x00;
    lcd_dat(m2);
    lcd_str(" minutos");
    if(m1=='0'){
        switch(m2){
            case '0': 
                min=0;
                break;
            case '1':
                min=1;
                break;
            case '2':
                min=2;
                break;
            case '3':
                min=3;
                break;
            case '4':
                min=4;
                break;
            case '5':
                min=5;
                break;
            case '6':
                min=6;
                break;
            case '7':
                min=7;
                break;
            case '8':
                min=8;
                break;
            case '9':
                min=9;
                break;
        }
    }else if(m1=='1'){
        switch(m2){
            case '0': 
                min=10;
                break;
            case '1':
                min=11;
                break;
            case '2':
                min=12;
                break;
            case '3':
                min=13;
                break;
            case '4':
                min=14;
                break;
            case '5':
                min=15;
                break;
            case '6':
                min=16;
                break;
            case '7':
                min=17;
                break;
            case '8':
                min=18;
                break;
            case '9':
                min=19;
                break;
        }
    }else if(m1=='2'){
        switch(m2){
            case '0': 
                min=20;
                break;
            case '1':
                min=21;
                break;
            case '2':
                min=22;
                break;
            case '3':
                min=23;
                break;
            case '4':
                min=24;
                break;
            case '5':
                min=25;
                break;
            case '6':
                min=26;
                break;
            case '7':
                min=27;
                break;
            case '8':
                min=28;
                break;
            case '9':
                min=29;
                break;
        }
    }else if(m1=='3'){
        switch(m2){
            case '0': 
                min=30;
                break;
            case '1':
                min=31;
                break;
            case '2':
                min=32;
                break;
            case '3':
                min=33;
                break;
            case '4':
                min=34;
                break;
            case '5':
                min=35;
                break;
            case '6':
                min=36;
                break;
            case '7':
                min=37;
                break;
            case '8':
                min=38;
                break;
            case '9':
                min=39;
                break;
        }
    }else if(m1=='4'){
        switch(m2){
            case '0': 
                min=40;
                break;
            case '1':
                min=41;
                break;
            case '2':
                min=42;
                break;
            case '3':
                min=43;
                break;
            case '4':
                min=44;
                break;
            case '5':
                min=45;
                break;
            case '6':
                min=46;
                break;
            case '7':
                min=47;
                break;
            case '8':
                min=48;
                break;
            case '9':
                min=49;
                break;
        }
    }else if(m1=='5'){
        switch(m2){
            case '0': 
                min=50;
                break;
            case '1':
                min=51;
                break;
            case '2':
                min=52;
                break;
            case '3':
                min=53;
                break;
            case '4':
                min=54;
                break;
            case '5':
                min=55;
                break;
            case '6':
                min=56;
                break;
            case '7':
                min=57;
                break;
            case '8':
                min=58;
                break;
            case '9':
                min=59;
                break;
        }
    }
    return min;
}
