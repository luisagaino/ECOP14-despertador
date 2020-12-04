#include "pic18f4520.h"
#include "config.h"
#include "lcd.h"
#include "opcao.h"
#include "relogio.h"
#include "manual.h"
#include "ciclo.h"
#include "delay.h"
#include "adc.h"
#include "itoa.h"

void main(void) {
    int hora = 0, min = 0, seg = 0, hdsp, mdsp, start, c;
    unsigned char tmp;
    float adc;
    lcd_init();
    TRISB = 0x00;
    TRISE = 0x00;
    PORTB = 0x00;
    PORTE = 0x00;
    start = escolha();
    if (start == 1) {
        hdsp = horas();
        mdsp = minutos();
        atraso_ms(1000);
        lcd_cmd(L_CLR);
        imprimeHorario(hdsp, mdsp);
        for (;;) {
            relogio(hora, min, seg);

            if (hora == hdsp && min == mdsp) {
                PORTE = 0xFF;
                atraso_ms(2000);
                break;
            }

            //ajusta as horas do relogio
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
            //fim ajuste de horas
            atraso_ms(1000);
        }
    } else if (start == 2) {
        c = ciclo();
        atraso_ms(1000);
        lcd_cmd(L_CLR);
        mdsp = c * 45 - 15 * (c - 1);
        hdsp = c;
        if (c == 0) {
            hdsp = 0;
            mdsp = 25;
        }
        while (mdsp > 59) {
            mdsp = mdsp - 60;
            hdsp++;
        }
        imprimeHorario(hdsp, mdsp);
        hdsp = hora + hdsp;
        mdsp = min + mdsp;
        while (mdsp > 59) {
            mdsp = mdsp - 60;
            hdsp++;
        }
        for (;;) {
            relogio(hora, min, seg);

            if (hora == hdsp && min == mdsp) {
                PORTE = 0xFF;
                atraso_ms(2000);
                break;
            }

            //ajusta as horas do relogio
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
            //fim ajuste de horas
            atraso_ms(1000);
        }
    } else if (start == 3) {
        lcd_cmd(L_CLR);
        lcd_cmd(L_L2);
        lcd_str("  Aguardando o");
        lcd_cmd(L_L3);
        lcd_str("   amanhecer");
        adc_init();
        for (;;) {
            tmp = (adc_amostra(0)*10) / 204;
            adc = itoa(tmp);
            if (adc >= 4) {
                PORTE = 0xFF;
            } else if (PORTE == 0xFF) {
                PORTE = 0x00;
            }
        }
    }
}