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

