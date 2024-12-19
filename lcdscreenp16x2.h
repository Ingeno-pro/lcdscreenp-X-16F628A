 /*
 * File:   lcdscreenp.h
 * Author: Ign555
 * Version: 1.0
 * Created on 11 décembre 2024, 7:59
 */
#ifndef _XTAL_FREQ
#define _XTAL_FREQ 4000000
#endif

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef __LCD_PIN__
#define __LCD_PIN__
#define RS PORTBbits.RB5
#define E PORTBbits.RB4
#define D4 PORTBbits.RB6
#define D5 PORTBbits.RB7
#define D6 PORTAbits.RA6
#define D7 PORTAbits.RA7
#endif

#ifndef __LCD_SCREEN_P_H__
#define __LCD_SCREEN_P_H__

#define COLUMNS 16
#define LINES 2
typedef struct LCDScreen
{
    void (*cursor_blink)();
    void (*write)(char c);
    void (*print)(int x, int y, char *str);
    void (*clear)();
    
}LCDScreen;

void LCDScreen_init(LCDScreen *lcd);
void _LCDScreen_send_command(char cmd);
void _LCDScreen_send_data(char data);
void _LCDScreen_send_nibble(char nibble);
void _LCDScreen_push_enable(void);

void LCDScreen_clear(void);
void LCDScreen_cursor_blink(void);
void LCDScreen_print(int x, int y, char *str);

#endif