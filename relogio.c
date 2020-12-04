#include "relogio.h"
#include "lcd.h"

void relogio(int hora, int min, int seg) {
    char valores[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}, h, m, s;
    lcd_cmd(L_L1);
    lcd_str("    ");
    h = valores[(hora / 10) % 10];
    lcd_dat(h);
    h = valores[(hora / 1) % 10];
    lcd_dat(h);
    lcd_dat(':');
    m = valores[(min / 10) % 10];
    lcd_dat(m);
    m = valores[(min / 1) % 10];
    lcd_dat(m);
    lcd_dat(':');
    s = valores[(seg / 10) % 10];
    lcd_dat(s);
    s = valores[(seg / 1) % 10];
    lcd_dat(s);
    
}

void imprimeHorario(int h, int m){
    char valores[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}, hh, mm;
    lcd_cmd(L_L3);
    lcd_str("    ");
    hh = valores[(h / 10) % 10];
    lcd_dat(hh);
    hh = valores[(h / 1) % 10];
    lcd_dat(hh);
    lcd_dat(':');
    mm = valores[(m / 10) % 10];
    lcd_dat(mm);
    mm = valores[(m / 1) % 10];
    lcd_dat(mm);
    lcd_str(":00");
}