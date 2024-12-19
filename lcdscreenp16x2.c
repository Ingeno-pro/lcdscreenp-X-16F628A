#include "lcdscreenp.h"

void LCDScreen_init(LCDScreen *lcd){
    
    lcd->write = _LCDScreen_send_data;
    lcd->print = LCDScreen_print;
    lcd->clear = LCDScreen_clear;
    lcd->cursor_blink = LCDScreen_cursor_blink;
    
    _LCDScreen_send_command(0x33);
    _LCDScreen_send_command(0x32);
    _LCDScreen_send_command(0x28);
    _LCDScreen_send_command(0x0C);
    _LCDScreen_send_command(0x06);
    _LCDScreen_send_command(0x01);
    
}
void _LCDScreen_send_command(char cmd){
    RS = 0;
    _LCDScreen_send_nibble(cmd >> 4);
    _LCDScreen_send_nibble(cmd);
    __delay_ms(2);
}
void _LCDScreen_send_data(char data){
    RS = 1;
    _LCDScreen_send_nibble(data >> 4);
    _LCDScreen_send_nibble(data);
    __delay_ms(2); 
}
void _LCDScreen_send_nibble(char nibble){
    D4 = (nibble) & 0x01;
    D5 = (nibble >> 1) & 0x01;
    D6 = (nibble >> 2) & 0x01;
    D7 = (nibble >> 3) & 0x01;
    _LCDScreen_push_enable();
}
void _LCDScreen_push_enable(){
    E = 1;
    __delay_us(1);
    E = 0;
    __delay_us(50);
}
void LCDScreen_clear(void){
    _LCDScreen_send_command(0x01);
}
void LCDScreen_cursor_blink(void){
   _LCDScreen_send_command(0x0E); //Return the cursor to 0,0
}
void LCDScreen_move_cursor(int x, int y){
    
    int i;
    _LCDScreen_send_command(0x80); //Return the cursor to 0,0
    if(y) _LCDScreen_send_command(0xC0); //Move to the second line
    for(i = 0 ; i < x ; i++)_LCDScreen_send_data(' '); //Increment cursor position to right
   
}
void LCDScreen_print(int x, int y, char *str){
    
    LCDScreen_move_cursor(x, y);
    while(*str != '\0'){
        _LCDScreen_send_data(*str);
        str++;
    }
}