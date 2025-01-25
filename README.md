# lcdscreenp-X-16F628A's library guide
## Information 
This library is provided for XC8 Compiler and more precisely for 16F627A/16F628A/16F647A/16F648A.
It's only work for parralel 16x2 LCD display. 
## Install
In order to install this library, just put the source files into your MPLABX project.
Put the lcdscreenp16x2.c into the "Source files" folder and the lcdscreenp16x2.h into the "Header files" folder.

## Use 
As for use this library, you should import it by put `#include "lcdscreenp.h"` at the begining of your main.c file  
You can edit pin-attribution by editing the attribution in "lcdscreenp16x2.h". Below, you can see the code to edit in order to change the pin-attribution.  

```
#define RS PORTBbits.RB5
#define E PORTBbits.RB4
#define D4 PORTBbits.RB6
#define D5 PORTBbits.RB7
#define D6 PORTAbits.RA6
#define D7 PORTAbits.RA7
```
/!\ Warning : Mind to not put any of these pin on : RA5 or RA4 ( without pull up resistor )  
/!\ Warning : Don't forget to disable periphericals associated with the pin that you want to use

### Documentation
The provided library is very easy to use. You have to first Create a `LCDScreen` object then initialize it by using `LCDScreen_init(&lcd_object_name)`  
Here is an example :  
```
LCDScreen lcd;

void main(void) {
    
    //Mise de tous les port en sortie 
    TRISA &= 0x00;
    TRISB &= 0x00;

    CMCON = 0x07; //Désactivation des comparateurs

    PORTA = 0b00000000;
    PORTB = 0x00;
    
    __delay_ms(50);
    LCDScreen_init(&lcd);
    lcd.cursor_blink();
    
    while(1){
        //Do your stuff
    }
    return;
}
```
Here is some information about library's functions  
`lcd.cursor_blink()` : Enable / Disable cursor blinking  
`lcd.write(char c)` : Write a character  at the cursor position  
`lcd.print(int x, int y, char *str)` : Write a message at column x and line y   
`lcd.clear()` : Clear the LCD display  

## Changelog

19/12/2024 : lcdscreenp-X-16F628A  v1.0 release

Please, if you have any suggest/question contact me on contact@ingeno.fr
