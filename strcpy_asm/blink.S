//#define __SFR_OFFSET 0 //initialize special function register for linker, offsets IO address used by avr-libc's register definitions 
//.thumb  //Tell assembler to recognize THUMB FORMAT
.syntax unified // UNIFIES SYNTAX DIFFERENCES AMOUNG ARM AND THUMB DIVISION


  .global copy                    //linker 

copy:                           
    STMFD sp!, {v1-v6, lr}      //push onto stack
    MOV R7, R0                  // pointer to the original string in R7
    BL length_check              //go to check length function,branch with link
    MOV R0, R4                  //   move length to register
    BL malloc                   //Allocate space base on length
    MOV R9, R0                  //move the first memory location to r9, R0 is in beginning of NEW string now

loop1:                           //Loop to copy
    LDRB R8, [R7], #1           //load first character,move pointer
    STRB R8, [R0], #1           //store character, move character
    SUBS R4, R4, #1             //subtract 1 from the size
    BNE loop1                    //check if loop is done
    MOV R0, R9                  //Move back to beginning of the NEW string
    B end                   //go to end


length_check:                         //checks the length
    MOV R4, #0                  //set counter to 0
    
counter: 
    LDRB R5, [R0], #1           //load the first char
    CMP R5, #0                  //check for end, null char
    ADD R4, R4, #1              //increment length value
    BNE counter              // branch for loop
    MOV PC, LR                 // return,link register
    
end:
    LDMFD sp!, {v1-v6, pc}      //pop items off stack


BX LR 

