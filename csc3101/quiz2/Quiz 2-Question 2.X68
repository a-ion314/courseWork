*-----------------------------------------------------------
* Title      :Quiz 2 Question 2
* Written by :Adrian Ionascu
* Date       :12/4/16
* Description:
*-----------------------------------------------------------
    ORG    $1000
START:                  ; first instruction of program
    LEA ARRAY1,A2       ;move array into A2 to keep A1 for comma output
    LEA COMMA,A1        ;move comma into A1
    
    MOVE.B #7,D7          ;size of array
    MOVE.B #0,D5          ;counter
    MOVE.B #4,D0
    TRAP #15            ;grab input
    
    CMP #0,D1
    BLT ODD             ;if input is negative output odds
    
EVEN
    MOVE.B #0,D6        ;used to check remainder of DIVU
    JMP LOOP
ODD
    MOVE.B #1,D6

LOOP
    CMP D5,D7           ;check if out of array
    BEQ END
    
    MOVE.L (A2),D4
    DIVU #2,D4
    CLR.W D4
    SWAP D4
    
    CMP D6,D4
    BEQ PRINT
    JMP COUNT
    
PRINT
    MOVE.L (A2),D1      ;prints number and comma
    MOVE.B #3,D0
    TRAP #15
    
    MOVE.B #14,D0
    TRAP #15

COUNT
    ADD.B #1,D5         ;increases counter to ensure program is within the array
    ADDA.L #4,A2
    JMP LOOP

END    SIMHALT             ; halt simulator

* Put variables and constants here
COMMA DC.B ', ',0
ARRAY1 DC.L 1,7,13,0,11,24,8
    END    START        ; last line of source


*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~4~
