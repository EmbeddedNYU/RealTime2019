This is the assembly code reference for blink

Keep in mind the GPIOC_DDR names are simply names/macros, they are not the ones in kinetis.h, you can name them 

.equ pumpkin, 0x400FF094
LDR R0,=pumpkin

And it will be fine, do not get confused just because I chose the same names to represent them.